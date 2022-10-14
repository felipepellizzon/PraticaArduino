// Initialize Pins
int analogPin = 2;
int chargePin = 8;
int dischargePin = 7;

// Initialize Resistor
int resistorValue = 3000;

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
  Serial.begin(9600);
  elapsedTime = 0;
  digitalWrite(chargePin, HIGH); // Carrega capacitor
  startTime = millis(); // Start no tempo
  
  while(analogRead(analogPin) < 648)
  {       
    // nao faz nada ate carregar o capacitor em 63,2% da capacidade dele
    Serial.println(elapsedTime);
    //Serial.println(analogRead(analogPin)); 
  }

  elapsedTime= millis() - startTime; // Tempo para carregar o capacitor
  microFarads = ((float)elapsedTime / resistorValue) * 1000;
  //Serial.println(elapsedTime);       
  //Serial.println(" mS    ");  
  //Serial.println(analogRead(analogPin));
  
    if (microFarads > 1) 
  {
    //Serial.print((long)microFarads);       
    //Serial.println(" microFarads");         
  }

  else
  {
    //nanoFarads = microFarads * 1000.0;      
    //Serial.print((long)nanoFarads);         
    //Serial.println(" nanoFarads");          
    //delay(500); 
  }

  //delay(500);
  digitalWrite(chargePin, LOW); // Para de carregar o capacitor
  pinMode(dischargePin, OUTPUT); 
  digitalWrite(dischargePin, LOW); // Processo de descarga   
  while(analogRead(analogPin) > 8)
  {
    // Somente para descarregar o capacitor
    //Serial.println(analogRead(analogPin));
    Serial.println(elapsedTime);
       
  }
  //Serial.println(elapsedTime); 
  Serial.println(analogRead(analogPin));
  Serial.end();
  pinMode(dischargePin, INPUT); // Prevenção para não carregar o capacitor
   
}
