int fsrPin = A0; //FSR to analog 0
int speakerPin = 8; //speaker to pin 8
int fsrReading; //number freading from fsr
int speakerMap;
int starttime = millis();

void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(9600)
;}

void loop(void) {
  // put your main code here, to run repeatedly:
  fsrReading = analogRead(fsrPin);
  int num = fsrReading/5;
  Serial.print("analog reading = ");
  Serial.println(fsrReading);
  starttime = 0;

  if(fsrReading > 360)
  {
    while (starttime != 5000) //keep expression for 5 sec
    {

    }
  }
  else
  {
    while (starttime != 5000) //keep expression for 5 sec
    {

    }
  }

  speakerMap = map(fsrReading, 0, 1000, 120, 1500);
  tone(speakerPin, speakerMap, 10);
  delay(100);
}


void speakerOutput(int i)
{
  if(i = 0) //hard pressure
  {

  }
  else // soft pressure
  {

  }
}

void screenoOutput(int i)
{
  if(i = 0) // hard ressure
  {
    // angry face
  }
  else if (i = 1) //soft pressure
  {
    // happy face
  }
  else //resting or no action
  {
    // normal face
  }

  delay(100);
  //blink animation
}