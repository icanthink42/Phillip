#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

//initalize LCD
LCDWIKI_KBV mylcd(ILI9486,A3,A2,A1,0,A4);

//define some colour values
#define BLACK   0x0000
#define BLUE    0xAF5D
#define PINK    0xED9C
#define WHITE   0xFFFF

int fsrPin = A0; //FSR to analog 1
int fsrReading; //number freading from fsr
int speakerMap;
int starttime = millis();
int count = 0;

void setup(void) {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mylcd.Init_LCD();
  mylcd.Set_Rotation(1);
;}

void loop(void) {
  // put your main code here, to run repeatedly:
  fsrReading = analogRead(fsrPin);
  int num = fsrReading/5;
  Serial.print("analog reading = ");
  Serial.println(fsrReading);
  starttime = 0;
  mylcd.Fill_Screen(WHITE);

  if(fsrReading > 500 && fsrReading < 1000) // soft pressure
  {
    screenOut(0);
  }
  else if(fsrReading <= 500 && fsrReading > 20) // hard pressure
  {
    screenOut(1);
    //count++;
  }
  else //no action
  {
    screenOut(2);
  }
}


void screenOut(int i)
{
  //c = 4;
  //Serial.println(i);
  if(i == 1) // hard pressure
  {
    // angry face
    Serial.println("angry");
    Angry_face();
  }
  else if (i == 0) //soft pressure
  {
    // happy face
    Serial.println("happy");
    Happy_face();
  }
  else //resting or no action
  {
    // normal face
    NormalFace();
  }

  delay(1000);
}

void Angry_face()
{
  //eyes
      mylcd.Set_Draw_color(BLACK);
      mylcd.Fill_Circle(125, 90, 70);
      mylcd.Fill_Circle(480-125, 90, 70);
      mylcd.Set_Draw_color(WHITE);
      mylcd.Fill_Circle(100, 60, 25);
      mylcd.Fill_Circle(150, 120, 15);
      mylcd.Fill_Circle(480-150, 60, 25);
      mylcd.Fill_Circle(480-100, 120, 15);

      //cheeks
      mylcd.Set_Text_Back_colour(WHITE);
      mylcd.Set_Text_colour(PINK);
      mylcd.Set_Text_Size(5);
      mylcd.Print_String("\\", 125, 180);
      mylcd.Print_String("\\", 95, 180);
      mylcd.Print_String("\\", 65, 180);
      mylcd.Print_String("///", 480-125, 180);
    if(count < -1)
    {
      //sad
      //eyes (tears)
      mylcd.Fill_Circle(480-125+55, 90+55, 15);
      mylcd.Fill_Circle(480-125+45, 90+65, 15);
      mylcd.Fill_Circle(125-55, 90+55, 15);
      mylcd.Fill_Circle(125-45, 90+65, 15);
      mylcd.Set_Draw_color(BLUE);
      mylcd.Fill_Circle(480-125+55, 90+55, 10);
      mylcd.Fill_Circle(480-125+45, 90+65, 10);
      mylcd.Fill_Circle(125-55, 90+55, 10);
      mylcd.Fill_Circle(125-45, 90+65, 10);

      //mouth
      mylcd.Set_Draw_color(BLACK);
      mylcd.Fill_Circle(240, 280, 75);
      mylcd.Set_Draw_color(WHITE);
      mylcd.Fill_Circle(240, 280, 60);
      mylcd.Fill_Rectangle(240-90, 280, 240+90, 380);
    }
    else
    {
      //eyes (eyebrow)
      mylcd.Set_Draw_color(BLACK);
      mylcd.Fill_Rectangle(125-70, 90-35, 125+70, 90-70); //125, 90, 70
      mylcd.Fill_Rectangle(480-125-70, 90-35, 480-125+70, 90-70); //125, 90, 70
      // mouth
      mylcd.Set_Draw_color(BLACK);
      mylcd.Fill_Rectangle(240, 280, 240+90, 300); 
    }
}

void Happy_face()
{
  //eyes
    mylcd.Set_Draw_color(BLACK);
    mylcd.Fill_Circle(125, 90, 70);
    mylcd.Fill_Circle(480-125, 90, 70);
    mylcd.Set_Draw_color(WHITE);
    mylcd.Fill_Circle(125, 90, 55);
    mylcd.Fill_Circle(480-125, 90, 55);
    mylcd.Fill_Rectangle(10, 90, 480, 200);
    //cheeks
    mylcd.Set_Text_Back_colour(WHITE);
    mylcd.Set_Text_colour(PINK);
    mylcd.Set_Text_Size(5);
    mylcd.Print_String("\\", 125, 140);
    mylcd.Print_String("\\", 95, 140);
    mylcd.Print_String("\\", 65, 140);
    mylcd.Print_String("///", 480-125, 140);
    //mouth
    mylcd.Set_Draw_color(BLACK);
    mylcd.Fill_Circle(240, 220, 75);
    mylcd.Fill_Round_Rectangle(240-75, 220, 240+75, 220-75, 5);
    mylcd.Set_Draw_color(PINK);
    mylcd.Fill_Circle(240, 220, 60);
}

void NormalFace()
{
  //eyes
    mylcd.Set_Draw_color(BLACK);
    mylcd.Fill_Circle(125, 90, 70);
    mylcd.Fill_Circle(480-125, 90, 70);
    mylcd.Set_Draw_color(WHITE);
    mylcd.Fill_Circle(100, 60, 25);
    mylcd.Fill_Circle(150, 120, 15);
    mylcd.Fill_Circle(480-150, 60, 25);
    mylcd.Fill_Circle(480-100, 120, 15);

    mylcd.Set_Text_Back_colour(WHITE);
    mylcd.Set_Text_colour(PINK);
    mylcd.Set_Text_Size(15);
   //mouth
    mylcd.Print_String("w", 200, 180);
    mylcd.Set_Text_Size(5);
    
    //cheeks
    mylcd.Print_String("\\", 125, 180);
    mylcd.Print_String("\\", 95, 180);
    mylcd.Print_String("\\", 65, 180);
    mylcd.Print_String("///", 480-125, 180);
}