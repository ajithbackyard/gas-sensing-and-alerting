//copy past this code to arduino uno or arduinoDriod app
int LED1 = 11;
int buzzer = 8;
int smokeA0 = A5;
int sensorThreshold =85;
int sensor = 7;
int LED2 = 10;



void setup() {
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  digitalWrite(sensor,LOW);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThreshold )
  {
    digitalWrite(LED1, HIGH);
     digitalWrite(LED2, LOW);
     tone(buzzer, 100);
  
  if ( digitalRead(sensor)==HIGH )
  {
    
    digitalWrite(LED1, HIGH);
    tone(buzzer, 500);
     digitalWrite(LED2, HIGH);
    
     
  }
  }
   
  else
  {
    
    digitalWrite(LED1, LOW);
    noTone(buzzer);
     digitalWrite(LED2, LOW);
    }
  delay(100);
}

