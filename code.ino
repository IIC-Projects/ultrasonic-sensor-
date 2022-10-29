Ultrasonic Sensor
BY DEBANKAR SHUBHRAM


#define trigPin 5   //defing pin
#define echoPin 6   //defing pin
int ledPin=10;      //defing pin
void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);    //describing the  pin action input or output
  pinMode(echoPin, INPUT);     //describing the  pin action input or output
  pinMode(ledPin,OUTPUT);       //describing the  pin action input or output
}
void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);        //to start the pin action need to be low 
  delayMicroseconds(3);              
  digitalWrite(trigPin, HIGH);       // the pin action need to be high
  delayMicroseconds(10);           
  digitalWrite(trigPin, LOW);        
  duration = pulseIn(echoPin, HIGH);  
  distance = (duration/2) / 29.1;      //formula for distance calculation
  if (distance >= 100 || distance <= 0)   //condition
  {
    Serial.println("Out of range");   //statement
  }
  else 
  {
    Serial.print(distance);
    Serial.println(" cm");
     digitalWrite(ledPin,HIGH);          //statement according to the condition
    delay(1000);               
    digitalWrite(ledPin,LOW);  
    delay(1000);
  }
  delay(500);
}
