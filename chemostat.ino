#include <Stepper.h>
#include <TimedAction.h>

int Relay = 7;
//initalizes Timer variable which is used to delay vacuum operation
unsigned long Timer;
//sets the delay for running the vacuum in milliseconds
unsigned long vacuumDelay = 4000UL;

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

// initializes the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
// set timer delays for both objects
//TimedAction stepperAction = TimedAction(100, stepper);
//TimedAction vacuumAction = TimedAction(1000, vacuum);
void setup()
{
   // set the speed at 60 rpm:
  myStepper.setSpeed(60);
   // initialize the serial port:
  Serial.begin(9600); 
  pinMode(Relay, OUTPUT); 
}

         
void loop(){
     myStepper.step(stepsPerRevolution);
     if (digitalRead(Relay)==LOW){
        Timer = millis(), digitalWrite(Relay, HIGH);
        Serial.println("relay on");
        delay(1);
     }
     if (millis()-Timer >= vacuumDelay){
         digitalWrite(Relay, LOW);
         Serial.println("relay off");
     }  
}

/*void stepper(){
    Serial.println("clockwise");

}
void vacuum(){
         digitalWrite(Relay, HIGH);  // turn on relay
         delay(10000);
         digitalWrite(Relay, LOW);   // turn off relay
}*/


