int boardLed = D7; //LED pin

int moisture_pin = A1;
int moisture_analog = 0;// Pin where sensor is plugged in
int mVoltage = 0;



void setup() {
    pinMode(boardLed, OUTPUT);
    pinMode(moisture_pin, INPUT); //Sensor is input to read the moisture level
    
    
    //Make sure the code working, Led must turn on and off quickly for 5s
    digitalWrite(boardLed, HIGH);
    delay(500);
    digitalWrite(boardLed,LOW);
    delay(500);
}

void loop() {
    
    /* Read the sendor and publish to the cloud */
    
    digitalWrite(boardLed, HIGH);
    //Taking data ... 
    
    int moisture_analog = analogRead(moisture_pin); //Reading
    mVoltage = (moisture_analog*3300)/4096;
    
    if(mVoltage < 2000){
        Particle.publish("Plant_Status", "Plant is dry");
    }
    
    //LED turns off
    digitalWrite(boardLed, LOW);
    

    
    
    
    //Delay for 30s to take the varibales for every 30s
    delay(30000);

}
