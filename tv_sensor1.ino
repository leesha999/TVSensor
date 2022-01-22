const int trigPin = 11;
const int echoPin = 9;
long duration;
int distance;
int led = 5;
//int buzz = 8;

void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
//pinMode(buzz, OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
//This calculates the distance and prints it in the serial monitors 
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);  
  
  if(distance <= 5)
  {
    digitalWrite(led, HIGH); 
    //digitalWrite(buzz, HIGH);                   
  }else if(distance >= 150)
  {
    digitalWrite(led, LOW);     
  }
  else
  {    
   digitalWrite(led, HIGH); 
   //digitalWrite(buzz, LOW);
  }
  
  if(distance <=5 || distance >= 150)
  {
    digitalWrite(led, LOW);    
  }  
}
