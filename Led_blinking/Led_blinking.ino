const byte ledPin = 13;              // to select inbuilt led
const byte intrPin = 2;              //uno board has interrupt pins as digital 2&3, weuse pin 2 here
volatile byte state = LOW;           //keping led as LOW initially using 'state' variable
void setup() {
 pinMode(ledPin,OUTPUT); // put your setup code here, to run once:
 pinMode(intrPin, INPUT_PULLUP);  //INPUT_PULLUP with pinMode() monitors the state of a switch by establishing 
                                  //serial communication between your Arduino and your computer over USB.
 
 attachInterrupt(digitalPinToInterrupt(intrPin), blinks , LOW);        //Using Interrupt in 'CHANGE' mode. Interrupt syntax. See references.
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledPin, state);
}

void blinks()       //Interrupt Service Routine(i.e. function)
{
  state = !state;      //changing the state
  }


/*References:-
 * https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
 * https://www.arduino.cc/en/Tutorial/InputPullupSerial
 * https://electronics.stackexchange.com/questions/67007/whats-the-difference-between-input-and-input-pullup
 */
