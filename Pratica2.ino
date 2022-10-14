// Initialize Pins
int analogPin = 2;
int chargePin = 8;
int dischargePin = 7; //speeds up discharging process, not necessary though

// Initialize Resistor
int resistorValue = 10000;

// Initialize Timer
unsigned long startTime;
unsigned long elapsedTime;

// Initialize Capacitance Variables
float microFarads;                
float nanoFarads;

void setup()
{
  pinMode(chargePin, OUTPUT);     
  digitalWrite(chargePin, LOW);  
  Serial.begin(9600); // Necessary to print data to serial monitor over USB
}

void loop()
{
  digitalWrite(chargePin, HIGH); // Begins charging the capacitor
  startTime = millis(); // Begins the timer
  
  while(analogRead(analogPin) < 648)
  {       
    // Does nothing until capacitor reaches 63.2% of total voltage
    Serial.println(elapsedTime); 
  }

  elapsedTime= millis() - startTime; // Determines how much time it took to charge capacitor
  //microFarads = ((float)elapsedTime / resistorValue) * 1000;
  Serial.println(elapsedTime);       
  //Serial.println(" mS    ");         

  delay(500);
  digitalWrite(chargePin, LOW); // Stops charging capacitor
  pinMode(dischargePin, OUTPUT); 
  digitalWrite(dischargePin, LOW); // Allows capacitor to discharge    
  while(analogRead(analogPin) > 0)
  {
    // Do nothing until capacitor is discharged 
       
  }
  Serial.println(elapsedTime); 
  Serial.end();
  pinMode(dischargePin, INPUT); // Prevents capacitor from discharging 
   
}
