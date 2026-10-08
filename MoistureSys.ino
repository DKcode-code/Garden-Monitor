void setup() {
Serial.begin(9600);
}

int sensorPin = A0;
int sensorValue = 0;
int newValue = -1;
unsigned long checkTime = 0;
const unsigned long interval = 5000; //5 seconds
const int changeValue = 20; // printing new value if changes more that 20 units

int sensorTemp = A1;
int TemperatureValue = -1;

int NPK = A2;
int NPKvalue = -1;

void loop() {
 //MOISTURE SYSTEM
  unsigned long currentTime = millis(); //millis - clock and currentTime holds time
  
  if (newValue == -1) {
   sensorValue = analogRead(sensorPin); //this will analog value from the sensor
  
  Serial.println("Soil Moisture Value: " + sensorValue);

  printStatus(sensorValue);
  newValue = sensorValue;
  }

  if(currentTime - checkTime >= interval) {
    checkTime = currentTime;
    sensorValue = analogRead(sensorPin);
    if (abs(sensorValue - newValue) >= changeValue) {
        Serial.println("Soil Moisture Value: " + sensorValue);

  printStatus(sensorValue);
  newValue = sensorValue;
    }
  }
  //TEMPERATURE
    TemperatureValue = analogRead(sensorTemp);

float convertTemp = (TemperatureValue / 1024.0) * 5000;

float far = (((TemperatureValue / 10) * 9) / 5 + 32);

Serial.print("Temperature: ");
Serial.print(TemperatureValue);
Serial.println("F");

//NPK NUTRIENTS

NPKvalue = analogRead(NPK);

Serial.print("NPK: ");
Serial.println(NPKvalue); 

delay(10000);
}



void printStatus(int value) {

if (value <= 250) {
    Serial.println("WARNING: Too dry!");

    } else if (value > 250 && value <= 350) {
    Serial.println("Action needed: dry");

        } else if (value >= 620) {
        Serial.println("WARNING: Too moist");

    } else if (value >= 520 && value < 620) {
    Serial.println("Action needed: wet");

        } else {
        Serial.println("Moisture level: Good");
    }
}










