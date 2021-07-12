String VarName[36] {"va0.val", "va1.val", "va2.val", "va3.val", "va4.val", "va5.val", "va6.val", "va7.val", "va8.val", "va9.val", "va10.val", "va11.val", "va12.val", "va13.val", "va14.val", "va15.val", "va16.val", "va17.val", "va18.val", "va19.val", "va20.val", "va21.val", "va22.val", "va23.val", "va24.val", "va25.val", "va26.val", "va27.val", "va28.val", "va29.val", "va30.val", "va31.val", "va32.val", "va33.val", "va34.val", "va35.val"};
int CabinetAlarms[3];

void Alarms() {
  for (int i = 0; i < 36; i++) {

    //Serial.print("Alarm Active ");
    //Serial.print(i);
    //Serial.print(" :- ");
    //Serial.println(OtherAlm[i]);
    if (OtherAlm[i]) {
      myNex.writeNum(VarName[i], 1); delay (2); 
      if (i < 12) {
        CabinetAlarms[0] = i;
        //Serial.print("Cabinet alarm set ");
        //Serial.println(CabinetAlarms[0]);
      }
      else if (i > 11 && i < 24) {
        CabinetAlarms[1] = i;
        //Serial.print("Cabinet alarm set ");
        //Serial.println(CabinetAlarms[1]);
      }
      else if (i > 23 && i < 36) {
        CabinetAlarms[2] = i;
        //Serial.print("Cabinet alarm set ");
        //Serial.println(CabinetAlarms[2]);
      }
    }
    else {
      myNex.writeNum(VarName[i], 0); delay (2); 
      if (i < 12) {
        if (CabinetAlarms[0] == i) {
          //Serial.print("Cabinet alarm reset ");
         // Serial.println(CabinetAlarms[0]);
          CabinetAlarms[0] = 0;
        }
      }
      else if (i > 11 && i < 24) {
        if (CabinetAlarms[1] == i) {
         // Serial.print("Cabinet alarm reset ");
         // Serial.println(CabinetAlarms[1]);
          CabinetAlarms[1] = 0;
        }
      }
      else if (i > 23 && i < 36) {
        if (CabinetAlarms[2] == i) {
          //Serial.print("Cabinet alarm reset ");
          //Serial.println(CabinetAlarms[2]);
          CabinetAlarms[2] = 0;
        }
      }
    }
  }
//  Serial.print("Cabinet Alarms Active ");
//  Serial.print(CabinetAlarms[0]);
//  Serial.print(" ");
//  Serial.print(CabinetAlarms[1]);
//  Serial.print(" ");
//  Serial.print(CabinetAlarms[2]);
//  Serial.println(" ");

  if ( CabinetAlarms[0]) {
    myNex.writeNum("Alarm1.val", 1);
  }
  else {
    myNex.writeNum("Alarm1.val", 0);
  } 
  delay (2); 
  if ( CabinetAlarms[1]) {
    myNex.writeNum("Alarm2.val", 1);
  }
  else {
    myNex.writeNum("Alarm2.val", 0);
  } 
  delay (2); 
  if ( CabinetAlarms[2]) {
    myNex.writeNum("Alarm3.val", 1);
  }
  else {
    myNex.writeNum("Alarm3.val", 0);
  }
  delay (2); 
}




void displayParams(uint32_t  Ptr) {

  if (Switch[(Ptr * 6) - 6] == 1) {
    myNex.writeNum(Parameters[0][0], 1);
  }
  else {
    myNex.writeNum(Parameters[0][0], 0);
  }
  delay (2);
  if (PFuse[(Ptr * 6) - 6] == 1) {
    myNex.writeNum(Parameters[0][3], 1);
  }
  else {
    myNex.writeNum(Parameters[0][3], 0);
  }
  delay (2);
  if (OFuse[(Ptr * 6) - 6] == 1) {
    myNex.writeNum(Parameters[0][4], 1);
  }
  else {
    myNex.writeNum(Parameters[0][4], 0);
  }
  delay (2);
  if (NFuse[(Ptr * 6) - 6] == 1) {
    myNex.writeNum(Parameters[0][5], 1);
  }
  else {
    myNex.writeNum(Parameters[0][5], 0);
  }
  delay (2);
  myNex.writeNum(Parameters[0][1],  VPositive[(Ptr * 6) - 6]); delay (2);
  myNex.writeNum(Parameters[0][2],  VNegative[(Ptr * 6) - 6]); delay (2);
  myNex.writeNum(Parameters[0][6],  DOD[(Ptr * 6) - 6]); delay (2);
  myNex.writeNum(Parameters[0][7],  CurrentPosTemp[(Ptr * 6) - 6]); delay (2);
  myNex.writeNum(Parameters[0][8],  CurrentNegTemp[(Ptr * 6) - 6]); delay (2);
  myNex.writeNum(Parameters[0][9],  TemperatureTemp[(Ptr * 6) - 6]); delay (2);
  myNex.writeNum(Parameters[0][10],  AH[(Ptr * 6) - 6]); delay (2);
  myNex.writeNum(Parameters[0][11],  Cycles[(Ptr * 6) - 6]); delay (2);
  myNex.writeNum(Parameters[0][12],  Life[(Ptr * 6) - 6]); delay (2);



  if (Switch[(Ptr * 6) - 5] == 1) {
    myNex.writeNum(Parameters[1][0], 1);
  }
  else {
    myNex.writeNum(Parameters[1][0], 0);
  }
  delay (2);
  if (PFuse[(Ptr * 6) - 5] == 1) {
    myNex.writeNum(Parameters[1][3], 1);
  }
  else {
    myNex.writeNum(Parameters[1][3], 0);
  }
  delay (2);
  if (OFuse[(Ptr * 6) - 5] == 1) {
    myNex.writeNum(Parameters[1][4], 1);
  }
  else {
    myNex.writeNum(Parameters[1][4], 0);
  }
  delay (2);
  if (NFuse[(Ptr * 6) - 5] == 1) {
    myNex.writeNum(Parameters[1][5], 1);
  }
  else {
    myNex.writeNum(Parameters[1][5], 0);
  }
  delay (2);
  myNex.writeNum(Parameters[1][1],  VPositive[(Ptr * 6) - 5]); delay (2);
  myNex.writeNum(Parameters[1][2],  VNegative[(Ptr * 6) - 5]); delay (2);
  myNex.writeNum(Parameters[1][6],  DOD[(Ptr * 6) - 5]); delay (2);
  myNex.writeNum(Parameters[1][7],  CurrentPosTemp[(Ptr * 6) - 5]); delay (2);
  myNex.writeNum(Parameters[1][8],  CurrentNegTemp[(Ptr * 6) - 5]); delay (2);
  myNex.writeNum(Parameters[1][9],  TemperatureTemp[(Ptr * 6) - 5]); delay (2);
  myNex.writeNum(Parameters[1][10],  AH[(Ptr * 6) - 5]); delay (2);
  myNex.writeNum(Parameters[1][11],  Cycles[(Ptr * 6) - 5]); delay (2);
  myNex.writeNum(Parameters[1][12],  Life[(Ptr * 6) - 5]); delay (2);



  if (Switch[(Ptr * 6) - 4] == 1) {
    myNex.writeNum(Parameters[2][0], 1); delay(2);
  }
  else {
    myNex.writeNum(Parameters[2][0], 0); delay(2);
  }
  delay (2);
  if (PFuse[(Ptr * 6) - 4] == 1) {
    myNex.writeNum(Parameters[2][3], 1); delay(2);
  }
  else {
    myNex.writeNum(Parameters[2][3], 0); delay(2);
  }
  delay (2);
  if (OFuse[(Ptr * 6) - 4] == 1) {
    myNex.writeNum(Parameters[2][4], 1); delay(2);
  }
  else {
    myNex.writeNum(Parameters[2][4], 0); delay(2);
  }
  delay (2);
  if (NFuse[(Ptr * 6) - 4] == 1) {
    myNex.writeNum(Parameters[2][5], 1); delay(2);
  }
  else {
    myNex.writeNum(Parameters[2][5], 0); delay(2);
  }
  delay (2);
  myNex.writeNum(Parameters[2][1],  VPositive[(Ptr * 6) - 4]); delay(2);
  myNex.writeNum(Parameters[2][2],  VNegative[(Ptr * 6) - 4]); delay(2);
  myNex.writeNum(Parameters[2][6],  DOD[(Ptr * 6) - 4]); delay(2);
  myNex.writeNum(Parameters[2][7],  CurrentPosTemp[(Ptr * 6) - 4]); delay(2);
  myNex.writeNum(Parameters[2][8],  CurrentNegTemp[(Ptr * 6) - 4]); delay(2);
  myNex.writeNum(Parameters[2][9],  TemperatureTemp[(Ptr * 6) - 4]); delay(2);
  myNex.writeNum(Parameters[2][10],  AH[(Ptr * 6) - 4]); delay(2);
  myNex.writeNum(Parameters[2][11],  Cycles[(Ptr * 6) - 4]); delay(2);
  myNex.writeNum(Parameters[2][12],  Life[(Ptr * 6) - 4]); delay(2);


  if (Switch[(Ptr * 6) - 3] == 1) {
    myNex.writeNum(Parameters[3][0], 1); 
  }
  else {
    myNex.writeNum(Parameters[3][0], 0); 
  }
  delay (2);
  if (PFuse[(Ptr * 6) - 3] == 1) {
    myNex.writeNum(Parameters[3][3], 1); 
  }
  else {
    myNex.writeNum(Parameters[3][3], 0); 
  }
  delay (2);
  if (OFuse[(Ptr * 6) - 3] == 1) {
    myNex.writeNum(Parameters[3][4], 1); 
  }
  else {
    myNex.writeNum(Parameters[3][4], 0); 
  }
  delay (2);
  if (NFuse[(Ptr * 6) - 3] == 1) {
    myNex.writeNum(Parameters[3][5], 1); 
  }
  else {
    myNex.writeNum(Parameters[3][5], 0); 
  }
  delay (2);
  myNex.writeNum(Parameters[3][1],  VPositive[(Ptr * 6) - 3]); delay(2);
  myNex.writeNum(Parameters[3][2],  VNegative[(Ptr * 6) - 3]); delay(2);
  myNex.writeNum(Parameters[3][6],  DOD[(Ptr * 6) - 3]); delay(2);
  myNex.writeNum(Parameters[3][7],  CurrentPosTemp[(Ptr * 6) - 3]); delay(2);
  myNex.writeNum(Parameters[3][8],  CurrentNegTemp[(Ptr * 6) - 3]); delay(2);
  myNex.writeNum(Parameters[3][9],  TemperatureTemp[(Ptr * 6) - 3]); delay(2);
  myNex.writeNum(Parameters[3][10],  AH[(Ptr * 6) - 3]); delay(2);
  myNex.writeNum(Parameters[3][11],  Cycles[(Ptr * 6) - 3]); delay(2);
  myNex.writeNum(Parameters[3][12],  Life[(Ptr * 6) - 3]); delay(2);



  if (Switch[(Ptr * 6) - 2] == 1) {
    myNex.writeNum(Parameters[4][0], 1); 
  }
  else {
    myNex.writeNum(Parameters[4][0], 0); 
  }
  delay (2);
  if (PFuse[(Ptr * 6) - 2] == 1) {
    myNex.writeNum(Parameters[4][3], 1); 
  }
  else {
    myNex.writeNum(Parameters[4][3], 0); 
  }
  delay (2);
  if (OFuse[(Ptr * 6) - 2] == 1) {
    myNex.writeNum(Parameters[4][4], 1); 
  }
  else {
    myNex.writeNum(Parameters[4][4], 0);
  }
  delay (2);
  if (NFuse[(Ptr * 6) - 2] == 1) {
    myNex.writeNum(Parameters[4][5], 1); ;
  }
  else {
    myNex.writeNum(Parameters[4][5], 0); 
  }
  delay (2);
  myNex.writeNum(Parameters[4][1],  VPositive[(Ptr * 6) - 2]); delay(2);
  myNex.writeNum(Parameters[4][2],  VNegative[(Ptr * 6) - 2]); delay(2);
  myNex.writeNum(Parameters[4][6],  DOD[(Ptr * 6) - 2]); delay(2);
  myNex.writeNum(Parameters[4][7],  CurrentPosTemp[(Ptr * 6) - 2]); delay(2);
  myNex.writeNum(Parameters[4][8],  CurrentNegTemp[(Ptr * 6) - 2]); delay(2);
  myNex.writeNum(Parameters[4][9],  TemperatureTemp[(Ptr * 6) - 2]); delay(2);
  myNex.writeNum(Parameters[4][10],  AH[(Ptr * 6) - 2]); delay(2);
  myNex.writeNum(Parameters[4][11],  Cycles[(Ptr * 6) - 2]); delay(2);
  myNex.writeNum(Parameters[4][12],  Life[(Ptr * 6) - 2]); delay(2);


  if (Switch[(Ptr * 6) - 1] == 1) {
    myNex.writeNum(Parameters[5][0], 1);
  }
  else {
    myNex.writeNum(Parameters[5][0], 0);
  }
  delay (2);
  if (PFuse[(Ptr * 6) - 1] == 1) {
    myNex.writeNum(Parameters[5][3], 1);
  }
  else {
    myNex.writeNum(Parameters[5][3], 0);
  }
  delay (2);
  if (OFuse[(Ptr * 6) - 1] == 1) {
    myNex.writeNum(Parameters[5][4], 1);
  }
  else {
    myNex.writeNum(Parameters[5][4], 0);
  }
  delay (2);
  if (NFuse[(Ptr * 6) - 1] == 1) {
    myNex.writeNum(Parameters[5][5], 1);
  }
  else {
    myNex.writeNum(Parameters[5][5], 0); 
  }
  delay (2);

  myNex.writeNum(Parameters[5][1],  VPositive[(Ptr * 6) - 1]); delay(2);
  myNex.writeNum(Parameters[5][2],  VNegative[(Ptr * 6) - 1]); delay(2);
  myNex.writeNum(Parameters[5][6],  DOD[(Ptr * 6) - 1]); delay(2);
  myNex.writeNum(Parameters[5][7],  CurrentPosTemp[(Ptr * 6) - 1]); delay(2);
  myNex.writeNum(Parameters[5][8],  CurrentNegTemp[(Ptr * 6) - 1]); delay(2);
  myNex.writeNum(Parameters[5][9],  TemperatureTemp[(Ptr * 6) - 1]); delay(2);
  myNex.writeNum(Parameters[5][10],  AH[(Ptr * 6) - 1]); delay(2);
  myNex.writeNum(Parameters[5][11],  Cycles[(Ptr * 6) - 1]); delay(2);
  myNex.writeNum(Parameters[5][12],  Life[(Ptr * 6) - 1]); delay(2);


  if (Switch[Ptr * 6] == 1) {
    myNex.writeNum(Parameters[6][0], 1); 
  }
  else {
    myNex.writeNum(Parameters[6][0], 0); 
  }
  delay (2);
  if (PFuse[Ptr * 6] == 1) {
    myNex.writeNum(Parameters[6][3], 1); 
  }
  else {
    myNex.writeNum(Parameters[6][3], 0); 
  } 
  delay (2);
  if (OFuse[Ptr * 6] == 1) {
    myNex.writeNum(Parameters[6][4], 1); 
  }
  else {
    myNex.writeNum(Parameters[6][4], 0); 
  } 
  delay (5);
  if (NFuse[Ptr * 6] == 1) {
    myNex.writeNum(Parameters[6][5], 1); 
  }
  else {
    myNex.writeNum(Parameters[6][5], 0); 
  }
  delay (2);
  
   
   
  myNex.writeNum(Parameters[6][1],  VPositive[Ptr * 6]); delay(2);
  myNex.writeNum(Parameters[6][2],  VNegative[Ptr * 6]); delay(2);
  myNex.writeNum(Parameters[6][6],  DOD[Ptr * 6]); delay(2);
  myNex.writeNum(Parameters[6][7],  CurrentPosTemp[Ptr * 6]); delay(2);
  myNex.writeNum(Parameters[6][8],  CurrentNegTemp[Ptr * 6]); delay(2);
  myNex.writeNum(Parameters[6][9],  TemperatureTemp[Ptr * 6]); delay(2);
  myNex.writeNum(Parameters[6][10],  AH[Ptr * 6]); delay(2);
  myNex.writeNum(Parameters[6][11],  Cycles[Ptr * 6]); delay(2);
  myNex.writeNum(Parameters[6][12],  Life[Ptr * 6]); delay(2);
  Serial.println("Display Updated"); Serial.flush();
  }

// int OtherAlm[36];
// bool FusePAlm[36], FuseOAlm[36], FuseNAlm[36], SwitchAlm[36], ShelfAlarm[36], CabinetAlarm[36];

/*alarms

  1 voltage - less than 260 and higher than 352
  2 voltage - less than 260 and higher than 352
  3 fuse - 3 = alarm
  4 fuse - 3 = alarm
  5 fuse - 3 = alarm
  6 current positive over 9 and below -15 alarm
  7 current negative over 12 and below -12 alarm
  8 temperature below -10 and above 45
  9 switch 3 = alarm
  10 life remaining less than 50 alarm
  11 dod above 75 alarm
  12 ah below 3.5 alarm
  13 number of cycles above 1200 alarm
*/
