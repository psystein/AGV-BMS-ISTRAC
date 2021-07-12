

void readPositiveVoltage() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 00, 18)) {
   // Serial.print("Failed! readPositiveVoltage 0 ");
  //  Serial.println(ModbusRTUClient.lastError());
  }
  else {
  //  Serial.println("success readPositiveVoltage 0");
  //  Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      VPositive[i] = ModbusRTUClient.read();
      if (VPositive[i] <= 260 || VPositive[i] >= 352) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 1;
        }
      }
      else {
        if (OtherAlm[i] == 1) {
          OtherAlm[i] = 0;
        }
      }
    }
  }
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 18, 18)) {
    //Serial.print("Failed! readPositiveVoltage 1");
    //Serial.println(ModbusRTUClient.lastError());
  }
  else {
    //Serial.println("success readPositiveVoltage 1");
    //Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      VPositive[i] = ModbusRTUClient.read();
      if (VPositive[i] <= 260 || VPositive[i] >= 352) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 1;
        }
      }
      else {
        if (OtherAlm[i] == 1) {
          OtherAlm[i] = 0;
        }
      }
    }
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(0, VPositive, 36));
  modbusTCPServer.writeInputRegisters(0, VPositive, 36);
  delay (100);
}

void readNegativeVoltage() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 40, 18)) {
    //Serial.print("Failed! readNegativeVoltage 2");
    //Serial.println(ModbusRTUClient.lastError());
  }
  else {
    //Serial.println("success readNegativeVoltage 2");
    //Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      VNegative[i] = ModbusRTUClient.read();
      if (VNegative[i] <= 260 || VNegative[i] >= 352) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 2;
        }
      }
      else {
        if (OtherAlm[i] == 2) {
          OtherAlm[i] = 0;
        }
      }
    }
    // Serial.println();
  }


  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 58, 18)) {
    //Serial.print("Failed! readNegativeVoltage 3");
    //Serial.println(ModbusRTUClient.lastError());
  }
  else {
    //Serial.println("success readNegativeVoltage 3");
    //Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      VNegative[i] = ModbusRTUClient.read();
      if (VNegative[i] <= 260 || VNegative[i] >= 352) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 2;
        }
      }
      else {
        if (OtherAlm[i] == 2) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(40, VNegative, 36));
  modbusTCPServer.writeInputRegisters(40, VNegative, 36);
}


void readPFuse() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 80, 18)) {
    //Serial.print("Failed! readPFuse 4");
    //Serial.println(ModbusRTUClient.lastError());
  }
  else {
   // Serial.println("success readPFuse 4");
    //Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      PFuse[i] = ModbusRTUClient.read();
      if (PFuse[i] != 1) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 3;
          FusePAlm[i] = 1;
        }
      }
      else {
        if (OtherAlm[i] == 3) {
          OtherAlm[i] = 0;
          FusePAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }

  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 98, 18)) {
   // Serial.print("Failed! readPFuse 5");
   // Serial.println(ModbusRTUClient.lastError());
  }
  else {
   // Serial.println("success readPFuse 5");
   // Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      PFuse[i] = ModbusRTUClient.read();
      if (PFuse[i] != 1) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 3;
          FusePAlm[i] = 1;
        }
      }
      else {
        if (OtherAlm[i] == 3) {
          OtherAlm[i] = 0;
          FusePAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(80, PFuse, 36));
  modbusTCPServer.writeInputRegisters(80, PFuse, 36);
  delay (100);
}


void readOFuse() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 120, 18)) {
    //Serial.print("Failed! readOFuse 6");
    //Serial.println(ModbusRTUClient.lastError());
  }
  else {
   // Serial.println("success readOFuse 6");
    //Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      OFuse[i] = ModbusRTUClient.read();
      if (OFuse[i] != 1) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 4;
          FuseOAlm[i] = 1;
        }
      }
      else {
        if (OtherAlm[i] == 4) {
          OtherAlm[i] = 0;
          FuseOAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }


  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 138, 18)) {
   // Serial.print("Failed! readOFuse 7");
    //Serial.println(ModbusRTUClient.lastError());
  }
  else {
    //Serial.println("success readOFuse 7");
    //Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      OFuse[i] = ModbusRTUClient.read();
      if (OFuse[i] != 1) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 4;
          FuseOAlm[i] = 1;
        }
      }
      else {
        if (OtherAlm[i] == 4) {
          OtherAlm[i] = 0;
          FuseOAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(120, OFuse, 36));
  modbusTCPServer.writeInputRegisters(120, OFuse, 36);
  delay (100);
}

void readNFuse() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 160, 18)) {
    //Serial.print("Failed! readNFuse 8");
   // Serial.println(ModbusRTUClient.lastError());
  }
  else {
    //Serial.println("success readNFuse 8");
    //Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      NFuse[i] = ModbusRTUClient.read();
      if (NFuse[i] != 1) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 5;
          FuseNAlm[i] = 1;
        }
      }
      else {
        if (OtherAlm[i] == 5) {
          OtherAlm[i] = 0;
          FuseNAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }


  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 178, 18)) {
    //Serial.print("Failed! readNFuse 9");
    //Serial.println(ModbusRTUClient.lastError());
  }
  else {
    //Serial.println("success readNFuse 9");
    //Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      NFuse[i] = ModbusRTUClient.read();
      if (NFuse[i] != 1) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 5;
          FuseNAlm[i] = 1;
        }
      }
      else {
        if (OtherAlm[i] == 5) {
          OtherAlm[i] = 0;
          FuseNAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(160, NFuse, 36));
  modbusTCPServer.writeInputRegisters(160, NFuse, 36);
  delay (100);
}

void readCPositive() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 200, 18)) {
    //Serial.print("Failed! readCPositive 10");
   // Serial.println(ModbusRTUClient.lastError());
  }
  else {
   // Serial.println("success readCPositive 10");
   // Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      CPositive[i] = ModbusRTUClient.read();
      CurrentPosTemp[i] = (int16_t)CPositive[i];
      if (CurrentPosTemp[i] >= 12 || CurrentPosTemp[i] <= -12) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 6;
        }
      }
      else {
        if (OtherAlm[i] == 6) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }

  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 218, 18)) {
   // Serial.print("Failed! readCPositive 11");
   // Serial.println(ModbusRTUClient.lastError());
  }
  else {
   // Serial.println("success readCPositive 11");
   // Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      CPositive[i] = ModbusRTUClient.read();
      CurrentPosTemp[i] = (int16_t)CPositive[i];
      if (CurrentPosTemp[i] >= 12 || CurrentPosTemp[i] <= -12) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 6;
        }
      }
      else {
        if (OtherAlm[i] == 6) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(200, CPositive, 36));
  modbusTCPServer.writeInputRegisters(200, CPositive, 36);
  delay (100);
}

void readCNegative() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 240, 18)) {
  //  Serial.print("Failed! readCNegative 12");
  //  Serial.println(ModbusRTUClient.lastError());
  }
  else {
  //  Serial.println("success readCNegative 12");
   // Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      CNegative[i] = ModbusRTUClient.read();
      //Serial.print(CNegative[i]);
      CurrentNegTemp[i] = (int16_t)CNegative[i];
      //Serial.print("  ");
      if (CurrentNegTemp[i] >= 12 || CurrentNegTemp[i] <= -12) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 7;
        }
      }
      else {
        if (OtherAlm[i] == 7) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }

  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 258, 18)) {
  //  Serial.print("Failed! readCNegative 13");
  //  Serial.println(ModbusRTUClient.lastError());
  }
  else {
 //   Serial.println("success readCNegative 13");
 ///   Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      CNegative[i] = ModbusRTUClient.read();
      //Serial.print(CNegative[i]);
      CurrentNegTemp[i] = (int16_t)CNegative[i];
      //Serial.print("  ");
      if (CurrentNegTemp[i] >= 12 || CurrentNegTemp[i] <= -12) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 7;
        }
      }
      else {
        if (OtherAlm[i] == 7) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(240, CNegative, 36));
  modbusTCPServer.writeInputRegisters(240, CNegative, 36);
  delay (100);
}


void readTemp() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 280, 18)) {
  //  Serial.print("Failed! readTemp 14");
  //  Serial.println(ModbusRTUClient.lastError());
  }
  else {
   // Serial.println("success readTemp 14");
  //  Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      Temperature[i] = ModbusRTUClient.read();
      TemperatureTemp[i] = (int16_t)Temperature[i];
      if (TemperatureTemp[i] >= 45 || TemperatureTemp[i] <= -10) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 8;
        }
      }
      else {
        if (OtherAlm[i] == 8) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }


  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 298, 18)) {
   // Serial.print("Failed! readTemp 15");
   // Serial.println(ModbusRTUClient.lastError());
  }
  else {
  //  Serial.println("success readTemp 15");
  //  Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      Temperature[i] = ModbusRTUClient.read();
      TemperatureTemp[i] = (int16_t)Temperature[i];
      if (TemperatureTemp[i] >= 45 || TemperatureTemp[i] <= -10) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 8;
        }
      }
      else {
        if (OtherAlm[i] == 8) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(280, Temperature, 36));
  modbusTCPServer.writeInputRegisters(280, Temperature, 36);
  delay (100);
}

void readSwitch() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 320, 18)) {
  //  Serial.print("Failed! readSwitch 16");
  //  Serial.println(ModbusRTUClient.lastError());
  }
  else {
   // Serial.println("success readSwitch 16");
   // Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      Switch[i] = ModbusRTUClient.read();
      if (Switch[i] != 1) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 9;
          SwitchAlm[i] = 1;
        }
      }
      else {
        if (OtherAlm[i] == 9) {
          OtherAlm[i] = 0;
          SwitchAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }


  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 338, 18)) {
  //  Serial.print("Failed! readSwitch 17");
  //  Serial.println(ModbusRTUClient.lastError());
  }
  else {
  //  Serial.println("success readSwitch 17");
  //  Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      Switch[i] = ModbusRTUClient.read();
      if (Switch[i] != 1) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 9;
          SwitchAlm[i] = 1;
        }
      }
      else {
        if (OtherAlm[i] == 9) {
          OtherAlm[i] = 0;
          SwitchAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(320, Switch, 36));
  modbusTCPServer.writeInputRegisters(320, Switch, 36);
  delay (100);
}


void readLife() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 360, 18)) {
  //  Serial.print("Failed! readLife 18");
  //  Serial.println(ModbusRTUClient.lastError());
  }
  else {
    //Serial.println("success readLife 18");
   // Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      Life[i] = ModbusRTUClient.read();
      if (Life[i] <= 50) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 10;
        }
      }
      else {
        if (OtherAlm[i] == 10) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }


  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 378, 18)) {
    //Serial.print("Failed! readLife 19");
   // Serial.println(ModbusRTUClient.lastError());
  }
  else {
    //Serial.println("success readLife 19");
   // Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      Life[i] = ModbusRTUClient.read();
      if (Life[i] <= 50) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 10;
        }
      }
      else {
        if (OtherAlm[i] == 10) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(360, Life, 36));
  modbusTCPServer.writeInputRegisters(360, Life, 36);
  delay (100);
}

void readDOD() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 400, 18)) {
  //  Serial.print("Failed! readDOD 20");
  //  Serial.println(ModbusRTUClient.lastError());
  }
  else {
   // Serial.println("success readDOD 20");
   // Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      DOD[i] = ModbusRTUClient.read();
      if (DOD[i] >= 75) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 11;
        }
      }
      else {
        if (OtherAlm[i] == 11) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }


  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 418, 18)) {
   // Serial.print("Failed! readDOD 21");
   // Serial.println(ModbusRTUClient.lastError());
  }
  else {
  //  Serial.println("success readDOD 21");
   // Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      DOD[i] = ModbusRTUClient.read();
      if (DOD[i] >= 75) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 11;
        }
      }
      else {
        if (OtherAlm[i] == 11) {
          OtherAlm[i] = 0;
        }
      }
    }
    // Serial.println();
  }
  // Serial.print("Input Registers write Result :- ");
  // Serial.println(modbusTCPServer.writeInputRegisters(400, DOD, 36));
  modbusTCPServer.writeInputRegisters(400, DOD, 36);
  delay (100);
}


void readCycles() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 480, 18)) {
    //Serial.print("Failed! readCycles 24");
   // Serial.println(ModbusRTUClient.lastError());
  }
  else {
  //  Serial.println("success readCycles 24");
  //  Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      Cycles[i] = ModbusRTUClient.read();
      if (Cycles[i] >= 1200) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 13;
        }
      }
      else {
        if (OtherAlm[i] == 13) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }


  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 498, 18)) {
  ////  Serial.print("Failed! readCycles 25");
  //  Serial.println(ModbusRTUClient.lastError());
  }
  else {
//erial.println("success readCycles 25");
  //  Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      Cycles[i] = ModbusRTUClient.read();
      if (Cycles[i] >= 1200) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 13;
        }
      }
      else {
        if (OtherAlm[i] == 13) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(480, Cycles, 36));
  modbusTCPServer.writeInputRegisters(480, Cycles, 36);
  delay (100);
}



void readAH() {
  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 520, 18)) {
   // Serial.print("Failed! readAH 22");
   // Serial.println(ModbusRTUClient.lastError());
  }
  else {
  //  Serial.println("success readAH 22");
  //  Serial.println(ModbusRTUClient.available());
    for (int i = 0; i < 18; i++) {
      AH[i] = ModbusRTUClient.read();
      if (AH[i] <= 35) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 12;
        }
      }
      else {
        if (OtherAlm[i] == 12) {
          OtherAlm[i] = 0;
        }
      }
    }
    //Serial.println();
  }


  if (!ModbusRTUClient.requestFrom(1, INPUT_REGISTERS, 538, 18)) {
   // Serial.print("Failed! readAH 23");
 //   Serial.println(ModbusRTUClient.lastError());
  }
  else {
 //   Serial.println("success readAH 23");
 //   Serial.println(ModbusRTUClient.available());
    for (int i = 18; i < 36; i++) {
      AH[i] = ModbusRTUClient.read();
      if (AH[i] <= 35) {
        if (!OtherAlm[i]) {
          OtherAlm[i] = 12;
        }
      }
      else {
        if (OtherAlm[i] == 12) {
          OtherAlm[i] = 0;
        }
      }
    }
   // Serial.println();
  }
  //Serial.print("Input Registers write Result :- ");
  //Serial.println(modbusTCPServer.writeInputRegisters(520, AH, 36));
  modbusTCPServer.writeInputRegisters(520, AH, 36);
  delay (100);
}
