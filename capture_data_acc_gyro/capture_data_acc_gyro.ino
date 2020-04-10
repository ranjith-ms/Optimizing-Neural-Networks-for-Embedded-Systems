#include <MPU6050_tockn.h>
#include <Wire.h>
MPU6050 mpu6050(Wire);
const float accelerationThreshold = 2.5; // threshold of significant in G's
const int numSamples = 30;

int samplesRead = numSamples;
float aX, aY, aZ, gX, gY, gZ;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  Serial.println();
  Serial.println("aX,aY,aZ,gX,gY,gZ");
  
}

void loop() {
  
mpu6050.update();
  // wait for significant motion
  while (samplesRead == numSamples) {
    mpu6050.update();
    aX=mpu6050.getAccX();
    aY=mpu6050.getAccY();
    aZ=mpu6050.getAccZ();
    
      // sum up the absolutes
     float aSum = fabs(aX) + fabs(aY) + fabs(aZ);
      
            // check if it's above the threshold
      if (aSum >= accelerationThreshold) {
        // reset the sample read count
        samplesRead = 0;
        break;
      }
    
  }
//Serial.print("hii");
  // check if the all the required samples have been read since
  // the last time the significant motion was detected
  while (samplesRead < numSamples) {
    mpu6050.update();
    // check if both new acceleration and gyroscope data is
    // available
    //if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
      // read the acceleration and gyroscope data
     aX=mpu6050.getAccX();
     aY=mpu6050.getAccY();
     aZ=mpu6050.getAccZ();
     gX=mpu6050.getGyroX();
     gY=mpu6050.getGyroY();
     gZ=mpu6050.getGyroZ();

      samplesRead++;

      // print the data in CSV format
      Serial.print(aX, 3);
      Serial.print(',');
      Serial.print(aY, 3);
      Serial.print(',');
      Serial.print(aZ, 3);
      Serial.print(',');
      Serial.print(gX, 3);
      Serial.print(',');
      Serial.print(gY, 3);
      Serial.print(',');
      Serial.print(gZ, 3);
      Serial.println();

      if (samplesRead == numSamples) {
        // add an empty line if it's the last sample
        Serial.println();
      }
    
  }
}
