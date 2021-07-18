const int sensorPin = A0;
//Measure average tempurature in celsius and set as the baseline
const float baselineTemp = 25.0;

void setup() 
{
  //Initialize the serial port to the desired speed
  Serial.begin(9600); //open a serial port
  
  //Initialize the digital pin directions and turn off.
  for(int pinNumber = 2; pinNumber<5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}
void loop() 
{
  //Read the temperature sensor
  int sensorVal = analogRead(sensorPin);
  
  //Send the temperature sensor values to the computer
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  //Convert the sensor reading to voltage
  float voltage = (sensorVal/1023.0) * 5.0;
 
  //Send the calculated voltage value to the computer
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  //Convert the voltage to temperature in degrees celsius
  float temperature = (voltage - .5) * 100;
  //Send the calculated temperature value to the computer
  Serial.println(temperature);

  //Convert the temperature in celcius to fahrenheit
  float fahrenhiet = (1.8 * temperature) + 32;
  //Send the calculated fahrenhiet value to the computer
  Serial.print(fahrenhiet);
  Serial.print(", degrees F: ");
  //Display fahrenhiet value
  Serial.println(fahrenhiet);
 

  //Turn off LEDs for a low temperature
  if(temperature < baselineTemp)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW); 
  }
  //Turn on one LED for a low temperature
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW); 
  }
  //Turn on two LEDs for a medium temperature
  else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW); 
  }
  //Turn on three LEDs for a high temperature
  else if(temperature >= baselineTemp+6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH); 
  }
  //A small delay to stop the Analog-to-Digital converter reading too frequently
  delay(1);
}
