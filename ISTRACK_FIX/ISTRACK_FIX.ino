int16_t TemperatureTemp[36], CurrentPosTemp[36], CurrentNegTemp[36];
const String Parameters[7][13] = {{"bt3.val", "n48.val", "n49.val", "bt9.val", "bt10.val", "bt11.val", "n6.val", "n12.val", "n13.val", "n24.val", "x0.val", "n36.val", "n37.val"},
  {"bt4.val", "n50.val", "n51.val", "bt14.val", "bt13.val", "bt12.val", "n7.val", "n14.val", "n15.val", "n26.val", "x1.val", "n38.val", "n39.val"},
  {"bt5.val", "n52.val", "n53.val", "bt17.val", "bt16.val", "bt15.val", "n8.val", "n16.val", "n17.val", "n28.val", "x2.val", "n40.val", "n41.val"},
  {"bt8.val", "n54.val", "n55.val", "bt18.val", "bt19.val", "bt20.val", "n9.val", "n18.val", "n19.val", "n30.val", "x3.val", "n42.val", "n43.val"},
  {"bt7.val", "n56.val", "n57.val", "bt21.val", "bt22.val", "bt23.val", "n10.val", "n20.val", "n21.val", "n32.val", "x4.val", "n44.val", "n45.val"},
  {"bt6.val", "n58.val", "n59.val", "bt24.val", "bt25.val", "bt26.val", "n11.val", "n22.val", "n23.val", "n34.val", "x5.val", "n46.val", "n47.val"},
};

#include <SPI.h>
#include <ArduinoRS485.h>
#include <ArduinoModbus.h>
#include <Ethernet.h>

void(* resetFunc) (void) = 0; // for programmatically reset of controller

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 120);

EthernetServer ethServer(502);

ModbusTCPServer modbusTCPServer;

int OtherAlm[36];
bool FusePAlm[36], FuseOAlm[36], FuseNAlm[36], SwitchAlm[36], ShelfAlarm[36], CabinetAlarm[36];

#include "EasyNextionLibrary.h"  // Include EasyNextionLibrary

EasyNex myNex(Serial3); // Create an object of EasyNex class with the name < myNex >
// Set as parameter the Hardware Serial you are going to use



int MasterSteps = 0;

uint16_t VPositive[36], VNegative[36], PFuse[36], OFuse[36], NFuse[36], CPositive[36], CNegative[36], Temperature[36], Switch[36], Life[36], DOD[36], AH[36], Cycles[36];

void setup() {
  myNex.begin(9600);
  Ethernet.init(53);
  Ethernet.begin(mac, ip);
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(2000); 
      resetFunc(); // reset the mcu to try again
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }
  ethServer.begin();

  if (!modbusTCPServer.begin(ip)) {
    Serial.println("Failed to start Modbus TCP Server!");
    while (1);
  }
  modbusTCPServer.configureInputRegisters(0x00, 600);
  for (int i = 0; i < 36; i++) {
    VPositive[i] = 0;
    VNegative[i] = 0;
    PFuse[i] = 0;
    OFuse[i] = 0;
    NFuse[i] = 0;
    CPositive[i] = 0;
    CNegative[i] = 0;
    Temperature[i] = 0;
    Switch[i] = 0;

    Life[i] = 0;
    DOD[i] = 0;
    AH[i] = 0;
    Cycles[i] = 0;
    ShelfAlarm[i] = 0;
  }
  //Serial2.begin(9600);
  
  while (!ModbusRTUClient.begin(9600)) {
    Serial.println("Failed to start Modbus RTU Client!");
    while (1){
      delay(2000); 
      resetFunc(); // reset the mcu to try again
    }
    }
  delay(1000);
  Serial.println("Setup Done"); Serial.flush();
  delay(1000);
  digitalWrite(13, LOW);
}

unsigned long lastMS = 0;
int Steps = 0;
uint32_t  pagePtr = 0;

void loop() {
  myNex.NextionListen();
  EthernetClient client = ethServer.available();
 //////   Serial.println("check point");   /////////////////////////////////////////////////////////////////////
  if (client) {
    // a new client connected
    //Serial.println("new client");

    // let the Modbus TCP accept the connection
    modbusTCPServer.accept(client);

    if (client.connected()) {
      Serial.println("client connected");
      // poll for Modbus TCP requests, while client connected
      modbusTCPServer.poll();
    
      // update the LED
      // updateLED();
    }

   // Serial.println("client disconnected");
  }
  //modbusTCPServer.poll();
  if (millis() - lastMS >= 1000) {
    lastMS = millis();
    for (int i = 0; i < 5; i++){ pagePtr = myNex.readNumber("PagePtr.val"); delay (5);}
    Serial.print("Page = "); Serial.println(pagePtr);
    switch (MasterSteps) {
      case 0:
        switch (Steps) {
          case 0:
            readPositiveVoltage();
            Steps++;
            break;
          case 1:
            readNegativeVoltage();
            Steps++;
            break;
          case 2:
            readPFuse();
            Steps++;
            break;
          case 3:
            readOFuse();
            Steps++;
            break;
          case 4:
            readNFuse();
            Steps++;
            break;
          case 5:
            readCPositive();
            Steps++;
            break;
          case 6:
            readCNegative();
            Steps++;
            break;
          case 7:
            readTemp();
            Steps++;
            break;
          case 8:
            readSwitch();
            Steps++;
            break;
          case 9:
            readLife();
            Steps++;
            break;
          case 10:
            readDOD();
            Steps++;
            break;
          case 11:
            readAH();
            Steps++;
            break;
          case 12:
            readCycles();
            Steps = 0;
            MasterSteps++;
            break;
        }
        break;
      case 1:
        Alarms();
        MasterSteps++;
        break;
      case 2:
        displayParams(pagePtr);
        MasterSteps = 0;
        break;
    }
  }
  //delay(100);
}
