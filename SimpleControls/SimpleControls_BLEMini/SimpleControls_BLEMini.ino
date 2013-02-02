#include <Servo.h> 

/*

      Don't leave Digital-In pin floating
      e.g. Connect it to a button 

*/
 
#define DIGITAL_OUT_PIN    4
#define DIGITAL_IN_PIN     5
#define PWM_PIN            6
#define SERVO_PIN          7
#define ANALOG_IN_PIN      A5

Servo myservo;

unsigned long currentMillis;        // store the current value from millis()
unsigned long previousMillis;       // for comparison with currentMillis
int samplingInterval = 250;          // how often to run the main loop (in ms)

void setup()
{  
  pinMode(DIGITAL_OUT_PIN, OUTPUT);
  pinMode(DIGITAL_IN_PIN, INPUT);
  
  myservo.attach(SERVO_PIN);
  
  //BLE Mini is connected to pin 0 and 1.
  Serial.begin(57600);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop()
{
  static boolean analog_enabled = false;
  static byte old_state = LOW;
  
  // If data is ready
  while (Serial.available())
  {    
    delay(10);
    
    // read out command and data
    byte data0 = Serial.read();
    byte data1 = Serial.read();
    byte data2 = Serial.read();
    
    if (data0 == 0x01)  // Command is to control digital out pin
    {
      if (data1 == 0x01)
        digitalWrite(DIGITAL_OUT_PIN, HIGH);
      else
        digitalWrite(DIGITAL_OUT_PIN, LOW);
    }
    else if ((data0) == 0xA0) // Command is to enable analog in reading
    {
      if (data1 == 0x01)
        analog_enabled = true;
      else
        analog_enabled = false;
    }
    else if (data0 == 0x02) // Command is to control PWM pin
    {
      analogWrite(PWM_PIN, data1);
    }
    else if (data0 == 0x03)  // Command is to control Servo pin
    {
      myservo.write(data1);
    }
  }
  
  if (analog_enabled)  // if analog reading enabled
  {
    currentMillis = millis();
    if (currentMillis - previousMillis > samplingInterval)
    {
      previousMillis += samplingInterval;
      
      // Read and send out
      uint16_t value = analogRead(ANALOG_IN_PIN); 
      Serial.write((byte) 0x0B);
      Serial.write((byte) (value >> 8));
      Serial.write((byte) (value & 0x00FF));
    }
  }
  
  // If digital in changes, report the state
  if (digitalRead(DIGITAL_IN_PIN) != old_state)
  {
    old_state = digitalRead(DIGITAL_IN_PIN);
    
    if (digitalRead(DIGITAL_IN_PIN) == HIGH)
    {
      Serial.write((byte)0x0A);
      Serial.write((byte)0x01);
      Serial.write((byte)0x00);    
    }
    else
    {
      Serial.write((byte)0x0A);
      Serial.write((byte)0x00);
      Serial.write((byte)0x00);
    }
  }  
}
