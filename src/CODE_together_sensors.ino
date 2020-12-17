int const trigPin = 10;
int const echoPin = 9;
int buzzPin = 3;
int vibPin =11;
int shkPin = 6;    //pin number allocations.

void setup()

{
  pinMode(buzzPin, OUTPUT); //buzzer will recieve signal from arduino to buzz.
  pinMode(vibPin, INPUT);   //vib sensor will send measurement input to the uno.
  pinMode(shkPin, INPUT);   // shock sensor will send val input to the uno.
  pinMode(trigPin, OUTPUT); // trig pin will have pulses output.
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width

  Serial.begin(9600); 
}



void loop()

{

  long measurement =vibration();  //stores the vibration value measured by the vib sensor
  Serial.println(measurement);

 
  int val = digitalRead (shkPin);   //stores the value 0 or 1 from the shock sensor
  Serial.println(val);





 //shock sensor
/* if (val == HIGH) {             //if sensor goes high, trun on the buzzer
  digitalWrite(buzzPin, LOW);
  Serial.println("Shock Detected");
  Serial.println("Resetting...");
  delay(500);
 }
 else {
  digitalWrite(buzzPin, HIGH);
 }*/

  int duration, distance; 
 delay(1);
 digitalWrite(trigPin, HIGH);     //send the ultasonic wave and be ready for reflection.
  delay(1);
  digitalWrite(trigPin, LOW);     // Measure the pulse input in echo pin

  duration = pulseIn(echoPin, HIGH);  // Distance is half the duration devided by 29.1 (from datasheet)
 
  distance = (duration/2) / 29.1;    // if distance less than 0.15 meter and more than 0 (0 or less means over range) 




    if (distance <= 7.5 && distance >= 0 and val == HIGH and measurement > 15000)  {
      // Buzz
      digitalWrite(buzzPin, LOW);
      Serial.println("Proximity ALert, Shock and Vibration detected");
      Serial.println("Resetting..."); 
      delay(500); 
    }


    else if (distance <= 7.5 and distance >= 0 and measurement > 2000)  {
      // Buzz
      digitalWrite(buzzPin, LOW);
      Serial.println("Proximity ALert and vibration detected");
      Serial.println("Resetting...");  
      delay(500);
    }

     else if (val= HIGH and measurement > 10000)  {
      // Buzz
      digitalWrite(buzzPin, LOW);
      Serial.println("shock and vibration detected");
      Serial.println("Resetting..."); 
      delay(500); 
    }

    else if ( measurement > 35000)  {
      // Buzz
      digitalWrite(buzzPin, LOW);
      Serial.println("strong vibration detected");
      Serial.println("Resetting..."); 
      delay(500); 
    }

    else {
      // Don't buzz
      digitalWrite(buzzPin, HIGH);

    }
 }
    
 long vibration(){  //Helper function for getting vibration measurements 
  delay(10);
  long measurement=pulseIn (vibPin, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}
