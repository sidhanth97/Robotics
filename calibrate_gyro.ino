void calibrate_gyro(void) {
  if (use_manual_calibration) {
  	for (cal_int = 0; cal_int < 2000 ; cal_int ++) 
    {                                
      if (cal_int % 25 == 0) 
      	digitalWrite(PB4, !digitalRead(PB4));                    					  //Change the led status every 125 readings to indicate calibration.
      gyro_signalen();                                                                //Read the gyro output.
      gyro_roll_cal += gyro_roll;                                                     //Add roll value to gyro_roll_cal.
      gyro_pitch_cal += gyro_pitch;                                                   //Add pitch value to gyro_pitch_cal.
      gyro_yaw_cal += gyro_yaw;                                                       //Add yaw value to gyro_yaw_cal.
      delay(4);                                                                       //Small delay to simulate a 250Hz loop during calibration.
    }
    red_led(HIGH);                                                                     //Set output PB3 low.
    gyro_roll_cal /= 2000;                                                            //Divide the roll total by 2000.
    gyro_pitch_cal /= 2000;                                                           //Divide the pitch total by 2000.
    gyro_yaw_cal /= 2000;                                                             //Divide the yaw total by 2000.
    manual_gyro_pitch_cal_value = gyro_pitch_cal;                                     //Set the manual pitch calibration variable to the detected value.
    manual_gyro_roll_cal_value = gyro_roll_cal;                                       //Set the manual roll calibration variable to the detected value.
    manual_gyro_yaw_cal_value = gyro_yaw_cal;                                         //Set the manual yaw calibration variable to the detected value.           
  }     

  else {                                                                      
    manual_gyro_pitch_cal_value = 0;                                                  
    manual_gyro_roll_cal_value = 0;                                                   
    manual_gyro_yaw_cal_value = 0;        
  }    
}
