const int servoPin = 13;

int dutyCycle = 0;

const int PWMFreq = 50;
const int PWMChannel = 0;
const int PWMResolution = 8;
const int MAX_DUTY_CYCLE = (int)(pow(2, PWMResolution) - 1);

void setup()
{  
  Serial.begin(115200);
  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  ledcAttachPin(servoPin, PWMChannel);
  ledcWrite(PWMChannel, dutyCycle);
}
void loop()
{
  for(dutyCycle = 5; dutyCycle <= 32; dutyCycle++)
  {
    ledcWrite(PWMChannel, dutyCycle);
    delay(70);    
  }
  for(dutyCycle = 32; dutyCycle >= 5; dutyCycle--)
  {
    ledcWrite(PWMChannel, dutyCycle);
    delay(70);    
  }
}
