#define trigPin 7
#define echoPin 8

void setup() 
{
 	Serial.begin (9600);
 	pinMode(trigPin, OUTPUT);
 	pinMode(echoPin, INPUT);
 	pinMode(10,OUTPUT);
 	pinMode(11,OUTPUT);
}

void loop() 
{
	long duration, distance;
     digitalWrite(trigPin, LOW);  // Added this line
     delayMicroseconds(2); // Added this line
     digitalWrite(trigPin, HIGH);
			//  delayMicroseconds(1000); - Removed this line
     delayMicroseconds(10); // Added this line
     digitalWrite(trigPin, LOW);
     duration = pulseIn(echoPin, HIGH);
     distance = (duration/2) / 29.1;
     if (distance < 10) // This is where the LED On/Off happens
	{  			
     		digitalWrite(11,HIGH);
  		digitalWrite(10,LOW);
 	}
  	else 
	{
    		digitalWrite(11,LOW);
 		digitalWrite(10,HIGH);
   	}
  	if (distance >= 200 || distance <= 0)
	{
    		Serial.println("Out of range");
  	}
  	else 	
	{
    		Serial.print(distance);
    		Serial.println(" cm");
  	}
  	delay(500);
} 
