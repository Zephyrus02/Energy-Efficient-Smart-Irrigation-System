
# **An Intelligent IoT based Energy-Efficient Framework for Smart Irrigation System**

**This system proposes a unique irrigation method based on IoT which is created with the help of precise crop data and real-time sensor data. The system generates customized irrigation schedules that minimizes water wastage and encourages optimal crop development. In order to optimize water usage, the system primarily uses an intricate and sophisticated artificial intelligence (AI) model that carefully examines sensor data and makes automatic irrigation decisions**

### Methodology
##### Figure 1. Flow chart of the model

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXfQ24iZPv-TriMQBB_QMwA-pSnU7pbnbaOCVkEmV1XzO5MtSM8NheZegYNP1DaEknTDHIbDPr-k0QiLaTD-7qawXvwipSzWu1RosYsAH-nnU1Ng2TyfTVR0q_vDV8CAFpyMcsC_wqZDiL-frB85ih6aJPc?key=me9y5hPWJZWgt-1FOUHwcA)**



### System Design & Architecture

We tested and experimented with various machine learning models like Decision Tree, Support Vector Machine (SVM), and Linear Regression to automate irrigation decisions based on real-time data obtained from the field and the crop information, we could conclude that the Decision Tree model performed the best on the provided data. The comparison of the effectiveness of all the 3 tested AI models has been depicted in Table 1. All the 4 evaluation parameters which were accuracy, precision, recall and F1 score of the tested AI models have been visualized in Figure 2.
##### Table 1. Comparison between all tested AI models.
| AI Model | Accuracy | Precision | Recall | F1 |
|--|--|--|--|--|
| Logistic Regression | 0.891 | 0.778 | 0.972 | 0.864 |
| Decision Tree | 0.980 | 0.972 | 0.972 | 0.972 |
| Support Vector Machine | 0.881 | 0.760 | 0.972 | 0.8536 |



##### Figure 2. Visualization of the model efficiency parameters

![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdqZLrVY8DH0VqiylmnpipZdyDlb2jOdnErtDEOdOn2-Vvs9rZvufcPgog8Y3LzeYZhZ3hAeZsN1OaY-5tbOFgdROIaA19I4sW8Fcefa00fnuCWk08EzxLC3EQk9tA9UHUQZE1nBjvUU3xusi6qOB951KOm?key=me9y5hPWJZWgt-1FOUHwcA "Chart")



The decision tree model is visually clear and easy to understand, so farmers can understand how the model decides when to water the crops. The model is also very flexible as it easily allows the accommodation of new crops. It also can adjust to different environmental conditions. The model is also computationally efficient, which allows it to take real-time decisions on low-end devices.

The efficiency of the decision tree model which we used completely depends on the dataset used to train it. The dataset includes previous records of data readings from the farm such as soil moisture, temperature, humidity, days required for crops to fully cultivate, water requirement information for different crop types, and successful irrigation practices leading to optimal crop growth. The model analyzes this data, identifies relationships between the data, crop type, and successful irrigation event. The used dataset has been visualized in Figure 3.

##### Figure 3. Visualization of the dataset

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXeif4ifIo-bVnzRajH7DCDzOyRnp_8U9kCkOjeKilc4B4eU-vW66pioGfIgOnOftSEUFgYl0yNSgm_y-MGTE-_hpzF1rNZ9jptn26IOQQaaTXGP0jpgW-Plllp2X9HQZx92hOMwOSIB_02jmFm1t1XT2Ted?key=me9y5hPWJZWgt-1FOUHwcA)**

### Irrigation System Circuit Design

The irrigation system circuit design incorporates a Blynk project that receives sensor readings from the ESP8266 code. This code acts as a data bridge, transferring the readings for analysis, visualization, and potential control strategies. The ESP8266 code connects to the Blynk project via Wi-Fi and regularly transmits sensor data to the AI model and mobile application.  
  
The code is responsible for setting up serial communication, pin configuration, Wi-Fi and Blynk connections, and a timer for periodic sensor readings. It continuously runs, checking the Blynk connection and the timer, and when the timer expires, it calls the sendSensor function. This function reads sensor data and sends it to designated virtual pins in the Blynk project. Debugging messages are also printed to the serial monitor for monitoring sensor readings.  
  
The AI model processes the sensor data and makes predictions about the farm's state. If the moisture level falls below a certain threshold, it activates a pump connected to a motor driver. The Arduino Uno powers the motor driver, as the motor requires 5V input voltage, while the ESP8266 supplies a maximum of 3V. The input pins of the motor driver (L293D) are connected to the ESP8266, and the VCC and GND pins are connected to the Arduino Uno.

**![](https://lh7-rt.googleusercontent.com/docsz/AD_4nXdaSxqLByKHXdBZalxuQh86GmhYCVVZDAlNti4rSc9a5t20zjQ5B-itTg11X8eU5A8X0VYlLsDuVj4sDQIEQ5Sy-YMEjsRlW-1vF4jxdzQ993DYlCx9KyqUkNmZdbGgdj-GGTNyfFL2YWbzCF8nDos2S_iD?key=me9y5hPWJZWgt-1FOUHwcA)**

### Conclusion
The system makes use of real-time sensor data such as temperature, humidity, and soil moisture that is gathered by sensors connected to Esp8266. This gathered data acts as input to the ML model and it predicts whether the soil requires water or not for the user defined crop type.

After continuous testing, the decision tree model was found to be the most effective machine learning model which uses sensor data and user input analysis to automate irrigation decisions. This approach helps in delivering water only till the threshold of soil moisture is reached. The integration of a BLYNK mobile application with a user-friendly dashboard allows remote monitoring of the soil moisture level by farmers, allowing for real-time data .

This smart irrigation system offers a significant step towards sustainable agricultural practices by optimizing water usage and maximizing crop yield. This project paves the way for the development of intelligent and data-driven irrigation solutions that can empower farmers to manage their resources effectively and contribute to a more sustainable agricultural future.

Future advancements could involve incorporating additional sensors, such as light sensors, to capture a more holistic view of the environmental conditions. Moreover, integrating historical weather data and machine learning algorithms could further enhance the system's predictive capabilities, enabling it to anticipate weather changes and adjust irrigation schedules accordingly.