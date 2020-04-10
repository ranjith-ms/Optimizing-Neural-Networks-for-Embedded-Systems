# Optimizing Neural Networks for Embedded Systems
The paper is available at https://irjet.net/archives/V7/i4/IRJET-V7I4211.pdf
Deploying a system with deep neural network in cloud is highly limited as more latency is introduced since there is a round trip to server, privacy risks as the data needs to leave the device, connectivity as the data need to be sent to server, power consumption as network connections are power hungry. All these problems could be overcome by deploying the deep learning model in the edge devices like microcontroller, mobile devices. We achieve this by quantizing the trained neural network which reduces the size as well as increase the speed at the same time, the performance is not compensated.  
  
We train the neural network to identify the gestures based on sensor inputs, combination of accelerometer and gyroscope found to work well for training as well as gives good accuracy at test time. The trained network is then optimized by reducing the redundant computations which do not contribute much to the model accuracy also the pruning is done to reduce the floating-point precision. All these redundant computation and reduction in floating point precision is done based on the representative dataset which is similar to that of data given to the model at the test time so that the desired accuracy is maintained even after optimization.  
## EXPERIMENTAL SETUP
### Preparation of dataset
refer capture_data_acc_gyro folder for arduino code to capture data from the MPU6050. Covert the serially printed data into CSV and normalize the data in python environment.(Training.ipynp)
![](images/accelrometer.png)
