#include <Wire.h>
#define MPU9250_ADDRESS 0x68
#define PWR_MGMT_1 0x6B
#define GYRO_LPF_CONFIG 0x1A
#define GYRO_ADDRESS 0x1B
#define ACCEL_ADDRESS 0x1C
#define ACCEL_LPF_CONFIG 0x1D

void I2Cread(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint16_t* Data) 
{
  Wire.beginTransmission(Address);
  Wire.write(Register);
  Wire.endTransmission();
  Wire.requestFrom(Address, Nbytes);
  int count = Nbytes/2;
  while (count--)
    Data[count] = Wire.read() << 8 | Wire.read();
}

void I2CwriteByte(uint8_t Address, uint8_t Register, uint8_t Data) 
{
  Wire.beginTransmission(Address);
  Wire.write(Register);
  Wire.write(Data);
  Wire.endTransmission();
}

void setup()
{
  Serial.begin(57600);
  Serial.println("Begin");
  Wire.begin();

  // Power Management Register for IMU
  I2CwriteByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x00);
  Serial.println("PMR");

  // Gyroscope set to 500 deg/sec
  I2CwriteByte(MPU9250_ADDRESS, GYRO_ADDRESS, 0x08);
  Serial.println("Gyroscope");

  //  Accelerometer set to 4g along with LPF of 10.2Hz
  I2CwriteByte(MPU9250_ADDRESS, ACCEL_ADDRESS, 0x10);
  Serial.println("Accelerometer");
}

void loop()
{
  Serial.println("New Loop");
  uint16_t mpu_buff[7];
  I2Cread(MPU9250_ADDRESS, 0x3B, 14, mpu_buff);
  Serial.print("gx:");
  Serial.print(mpu_buff[0]);

  Serial.print(" gy:");
  Serial.print(mpu_buff[1]);

  Serial.print(" gz:");
  Serial.print(mpu_buff[2]);

  Serial.print(" ax:");
  Serial.print(mpu_buff[3]);

  Serial.print(" ay:");
  Serial.print(mpu_buff[4]);

  Serial.print(" az:");
  Serial.print(mpu_buff[5]);

  Serial.println();
  delay(250);
}
