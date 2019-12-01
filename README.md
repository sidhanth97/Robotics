# stm32_controller

TO BUY: 
1. Battery
2. Mechanics set pieces
3. Cardboard, Measuring scale etc
4. Oil 
5. Amazon cart

BUILD:
1. Add more LEDs
2. Place for battery
3. Check COM
4. Check Wheel Allignment
5. Calculate Mass, COM distances, Dimensions of the vehicle
6. Place for control circuit
7. Oil all actuators

CODES:
  -> MPU Interfacing
  -> Flysky reciever Interfacing
  -> Complementary or Madgwick Filter (Yaw is important)
  -> PID controller
  -> Logic has to be {
                        "Equating reciever inputs to throttle stick value" : U_RL + U_RR = U_R,
                        "Equating PID controller calculated control value" : delta_U_R = PID(),
                        "Equating Mechanics Equations to servo control value": delta_U_R*k = U_S,
                        "Calculating U_RL,U_RR individually from equation 1 and 2": U_RL,U_RR
                      } 
                       
