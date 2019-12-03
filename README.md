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
8. Battery health circuit

CODES:
1. MPU Interfacing
2. Flysky reciever Interfacing
3. Complementary or Madgwick Filter (Yaw is important)
4. PID controller
5. Logic for calculating pulse value:
     1. Equating reciever inputs to throttle stick value : U_RL + U_RR = U_R
     2. Equating PID controller calculated control value : delta_U_R = PID()
     3. Equating Mechanics Equations to servo control value : Mult(delta_U_R,k) = U_S
     4. Calculating U_RL,U_RR individually from equation 1 and 2 : U_RL,U_RR

