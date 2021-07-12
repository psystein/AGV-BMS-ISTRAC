/* Nextion Update Parameters */
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
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE // 0xED is for 1st & 0xEE is 2nd
};
IPAddress ip(192, 168, 1, 130); // 120 is 1st & 130 is 2nd

EthernetServer ethServer(502);

ModbusTCPServer modbusTCPServer;


#include "EasyNextionLibrary.h"  // Include EasyNextionLibrary

EasyNex myNex(Serial3); // Create an object of EasyNex class with the name < myNex >
// Set as parameter the Hardware Serial you are going to use


uint16_t VPositive[40] = {0}, VNegative[40] = {0}, PFuse[40] = {0}, OFuse[40] = {0}, NFuse[40] = {0}, CPositive[40] = {0}, CNegative[40] = {0}, Temperature[40] = {0}, Switch[40] = {0}, Life[40] = {0}, DOD[40] = {0}, AH[40] = {0}, Cycles[40] = {0};
int16_t TemperatureTemp[40] = {0}, CurrentPosTemp[40] = {0}, CurrentNegTemp[40] = {0};

bool FusePAlm[40], FuseOAlm[40], FuseNAlm[40], SwitchAlm[40], ShelfAlarm[40], CabinetAlarm[40];

int OtherAlm[40];
int poller_Flag = 0;

void EthClient() {
  // Serial.println("check point 1"); Serial.flush();  /////////////////////////////////////////////////////////////////////
  //ethServer.begin();
  EthernetClient client = ethServer.available();

  if (client) {
    // a new client connected
    // Serial.println("new client");
    // let the Modbus TCP accept the connection
    modbusTCPServer.accept(client);

    while (client.connected()) {
      //modbusTCPServer.begin();
      Serial.println("TCP connected"); Serial.flush();
      // poll for Modbus TCP requests, while client connected
//      switch (poller_Flag) {
//        case 0:
//          poller_Flag = 1;
//          modbusTCPServer.writeInputRegisters(0, VPositive, 36);     delay (2); // modbusTCPServer.poll();        delay (100);
//          modbusTCPServer.writeInputRegisters(40, VNegative, 36);    delay (2); // modbusTCPServer.poll();        delay (100);
//          modbusTCPServer.writeInputRegisters(80, PFuse, 36);        delay (2); // modbusTCPServer.poll();        delay (100);
//          modbusTCPServer.writeInputRegisters(120, OFuse, 36);       delay (2); // modbusTCPServer.poll();        delay (100);
//          modbusTCPServer.writeInputRegisters(160, NFuse, 36);       delay (2);  //modbusTCPServer.poll();        delay (100);
//          break;
//        case 1:
//          poller_Flag = 2;
//          modbusTCPServer.writeInputRegisters(200, CPositive, 36);   delay (2); // modbusTCPServer.poll();        delay (100);
//          modbusTCPServer.writeInputRegisters(240, CNegative, 36);   delay (2); // modbusTCPServer.poll();        delay (100);
//          modbusTCPServer.writeInputRegisters(280, Temperature, 36); delay (2); // modbusTCPServer.poll();        delay (100);
//          modbusTCPServer.writeInputRegisters(320, Switch, 36);      delay (2); // modbusTCPServer.poll();        delay (100);
//          break;
//        case 2:
//          poller_Flag = 0;
//          modbusTCPServer.writeInputRegisters(360, Life, 36);        delay (2);//  modbusTCPServer.poll();        delay (100);
//          modbusTCPServer.writeInputRegisters(400, DOD, 36);         delay (2);//  modbusTCPServer.poll();        delay (100);
//          modbusTCPServer.writeInputRegisters(480, Cycles, 36);      delay (2);//  modbusTCPServer.poll();        delay (100);
//          modbusTCPServer.writeInputRegisters(520, AH, 36);          delay (2);
//          //modbusTCPServer.writeInputRegisters(560, AH, 36);    delay (2); // modbusTCPServer.poll();
//          break;
//      }
    //  delay (50);
      modbusTCPServer.poll();
   //   delay (100);
    }
    // client.stop(); // CLOSE the connection
    // Serial.println("client disconnected");

  }
  //modbusTCPServer.end();

}


void setup() {
  myNex.begin(9600);
  Ethernet.init(53);
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  Serial.println("Setup Initialized"); Serial.flush();
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
  modbusTCPServer.configureInputRegisters(0, 520);
  //modbusTCPServer.configureHoldingRegisters(0, 50);
  //  for (int i = 0; i < 36; i++) {
  //    VPositive[i] = 0;   VNegative[i] = 0;
  //    PFuse[i] = 0;  OFuse[i] = 0;  NFuse[i] = 0;
  //    CPositive[i] = 0;  CNegative[i] = 0;
  //    Temperature[i] = 0;
  //    Switch[i] = 0;
  //    Life[i] = 0;
  //    DOD[i] = 0;
  //    AH[i] = 0;
  //    Cycles[i] = 0;
  //    ShelfAlarm[i] = 0;
  //  }
  //  modbusTCPServer.writeInputRegisters(0, VPositive, 36);     delay (2);
  //  modbusTCPServer.writeInputRegisters(40, VNegative, 36);    delay (2);
  //  modbusTCPServer.writeInputRegisters(80, PFuse, 36);        delay (2);
  //  modbusTCPServer.writeInputRegisters(120, OFuse, 36);       delay (2);
  //  modbusTCPServer.writeInputRegisters(160, NFuse, 36);       delay (2);
  //  modbusTCPServer.writeInputRegisters(200, CPositive, 36);   delay (2);
  //  modbusTCPServer.writeInputRegisters(240, CNegative, 36);   delay (2);
  //  modbusTCPServer.writeInputRegisters(280, Temperature, 36); delay (2);
  //  modbusTCPServer.writeInputRegisters(320, Switch, 36);      delay (2);
  //  modbusTCPServer.writeInputRegisters(360, Life, 36);        delay (2);
  //  modbusTCPServer.writeInputRegisters(400, DOD, 36);         delay (2);
  //  modbusTCPServer.writeInputRegisters(480, Cycles, 36);      delay (2);
  //  modbusTCPServer.writeInputRegisters(520, AH, 36);          delay (2);


  //Serial2.begin(9600);

  while (!ModbusRTUClient.begin(9600)) {
    Serial.println("Failed to start Modbus RTU Client!");
    while (1) {
      delay(2000);
      resetFunc(); // reset the mcu to try again
    }
  }

  digitalWrite(13, LOW);
  Serial.println("Setup Done"); Serial.flush();
  delay(1000);
}

unsigned long lastMS, TCPdt = 0;
int Steps = 0;
uint32_t  pagePtr = 0;
int MasterSteps = 0;
int dispdt = 2;

void loop() {
  myNex.NextionListen();

  EthClient();

  if (millis() - lastMS >= 100) {
    lastMS = millis();
    for (int i = 0; i < 10; i++)
    {
      pagePtr = myNex.readNumber("PagePtr.val");
      delay (3);
    }
    Serial.print ("P = "); Serial.println(pagePtr); Serial.flush();
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
        EthClient();
        MasterSteps = 0;
        break;
    }
  }


  // modbusTCPServer.poll();
  //delay(100);
}
