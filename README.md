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



Maybe you can use the following MPU9250-specific info:

// Sensors x (y)-axis of the accelerometer/gyro is aligned with the y
(x)-axis of the magnetometer;
// the magnetometer z-axis (+ down) is misaligned with z-axis (+ up) of
accelerometer and gyro!
// We have to make some allowance for this orientation mismatch in feeding
the output to the quaternion filter.
// We will assume that +y accel/gyro is North, then x accel/gyro is East.
So if we want te quaternions properly aligned
// we need to feed into the madgwick function Ay, Ax, -Az, Gy, Gx, -Gz,
Mx, My, and Mz. But because gravity is by convention
// positive down, we need to invert the accel data, so we pass -Ay, -Ax,
Az, Gy, Gx, -Gz, Mx, My, and Mz into the Madgwick
// function to get North along the accel +y-axis, East along the accel
+x-axis, and Down along the accel -z-axis.
// This orientation choice can be modified to allow any convenient
(non-NED) orientation convention.
// This is ok by aircraft orientation standards!
// Pass gyro rate as rad/s
MadgwickQuaternionUpdate(-ay, -ax, az, gy_PI/180.0f, gx_PI/180.0f,
-gz_PI/180.0f, mx, my, mz);
// if(passThru)MahonyQuaternionUpdate(-ay, -ax, az, gy_PI/180.0f,
gx_PI/180.0f, -gz_PI/180.0f, mx, my, mz);
