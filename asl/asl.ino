
//include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 13, d4 = 11, d5 = 10, d6 = 9, d7 = 8;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

//flex analog input pins 
#define flex1_Pin 0
#define flex2_Pin 1
#define flex3_Pin 5

//accelorometer analog input pins 
#define accelorometerX_Pin 2
#define accelorometerY_Pin 3


void setup() {
        //set the cursor of the LCD
        lcd.begin(16, 2);
    
        //Serial.begin(9600);  //uncomment this line to set in debug mode (to enable RX and TX pins)
        
        //Output pins for apr33a3
        pinMode(0,OUTPUT);
        pinMode(1,OUTPUT);
        pinMode(2,OUTPUT);
        pinMode(3,OUTPUT);
        pinMode(4,OUTPUT);
        pinMode(5,OUTPUT);
        pinMode(6,OUTPUT);
        pinMode(7,OUTPUT);
}

void loop() {

    //to clear the output if any on the display
    lcd.clear();

    //set the cursor to first column and second row
    lcd.setCursor(0, 1);

    // read the input pin flex sensor pin 1
    int flexSensor1 = analogRead(flex1_Pin); 

    // convert it into window of 0 to 9
    flexSensor1 = map(flexSensor1, 465, 590, 0, 9); 

    // read the input pin flex sensor pin 2
    int flexSensor2 = analogRead(flex2_Pin); 

    // convert it into window of 0 to 9
    flexSensor2 = map(flexSensor2, 435, 535, 0, 9);

     // read the input pin X axis pin
    int accelorometerX = analogRead(accelorometerX_Pin);
    
    accelorometerX = map(accelorometerX, 260, 415, 0, 9);

    // read the input pin y axis pin
    int accelorometerY = analogRead(accelorometerY_Pin); 
    
    accelorometerY = map(accelorometerY, 260, 420, 0, 9);

    //read the 3rd flex input from 5th pin 
    int flexSensor3 = analogRead(flex3_Pin);

    flexSensor3 = map(flexSensor3, 445, 520, 0, 9);

    //uncommnet the folowing section to check the readings of all sensors and enable rx and tx pins
//    Serial.println("--------------------------------------------");
//    Serial.print("Flex 1--->");Serial.println(flexSensor1);
//    // read the input pin
//    Serial.print("Flex 2----->");Serial.println(flexSensor2);
//    Serial.print("Flex 3--->");Serial.println(flexSensor3);
//    Serial.print("Accelorometer x ----->");Serial.println(accelorometerX);
//    // read the input pin
//    Serial.print("Acceleromoeter y----->");Serial.println(accelorometerY);
//    Serial.println("--------------------------------------------");
//    Serial.println();

    //buffer period for accelorometer and flex
    int error_range_flex=2;
    int error_range_accelorometer=3;

    
     // match the signs to standard store values values depend on wearing hands 
    if ((flexSensor1>=-21-error_range_flex && flexSensor1<=-21+error_range_flex) && 
        (flexSensor2>=-23-error_range_flex && flexSensor2<=-23+error_range_flex )&& 
        (flexSensor3>=-3-error_range_flex && flexSensor3<=-3+error_range_flex)&&
        (accelorometerX>=40-error_range_accelorometer && accelorometerX<=40+error_range_accelorometer) &&
        (accelorometerY>=37-error_range_accelorometer && accelorometerY<=37+error_range_accelorometer))  {

            // Show message on LCD
            lcd.print("I am Manish"); 

            // select voice command 1 on APR 33A3
            digitalWrite(0,LOW); 
            
            digitalWrite(1,HIGH );
            
            digitalWrite(2,HIGH);
            
            digitalWrite(3, HIGH);
            
            digitalWrite(4, HIGH);
            
            digitalWrite(5, HIGH);
            
            digitalWrite(6, HIGH);
            
            digitalWrite(7, HIGH);
            
            delay (100);
            
            digitalWrite(0, HIGH); // make it off
            
            digitalWrite(1,HIGH);
            
            digitalWrite(2, HIGH);
            
            digitalWrite(3, HIGH);
            
            digitalWrite(4, HIGH);
            
            digitalWrite(5, HIGH);
            
            digitalWrite(6, HIGH);
            
            digitalWrite(7,HIGH);
            
            delay(3000);

      } else if ( (flexSensor1>=-21-error_range_flex && flexSensor1<=-21+error_range_flex) && 
                  (flexSensor2>=-5-error_range_flex && flexSensor2<=-5+error_range_flex)&&
                  (flexSensor3>=-1-error_range_flex && flexSensor3<=-1+error_range_flex)&&  
                  (accelorometerX>=40-error_range_accelorometer && accelorometerX<=40+error_range_accelorometer) && 
                  (accelorometerY>=23-error_range_accelorometer && accelorometerY<=23+error_range_accelorometer)) {
      
                  lcd.print("I am sorry");

                   // select voice command 2 on APR 33A3
                  digitalWrite(0,HIGH);
                  
                  digitalWrite(1,LOW );
                  
                  digitalWrite(2,HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7, HIGH);
                  
                  delay (100);
                  
                  digitalWrite(0, HIGH); // make it off
                  
                  digitalWrite(1,HIGH);
                  
                  digitalWrite(2, HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7,HIGH);
                  
                  delay(3000);
      
      } else if ((flexSensor1>=-17-error_range_flex && flexSensor1<=-17+error_range_flex) && 
                  (flexSensor2>=-19-error_range_flex && flexSensor2<=-19+error_range_flex) &&
                  (flexSensor3>=-19-error_range_flex && flexSensor3<=-19+error_range_flex)&&                  
                  (accelorometerX>=28-error_range_accelorometer && accelorometerX<=28+error_range_accelorometer) && 
                  (accelorometerY>=24-error_range_accelorometer && accelorometerY<=24+error_range_accelorometer)
                    ) {
      
                  lcd.print("Hello,How are u?");

                  // select voice command 3 on APR 33A3
                  digitalWrite(0,HIGH );
                  
                  digitalWrite(1,HIGH );
                  
                  digitalWrite(2,LOW);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7, HIGH);
                  
                  delay (100);

                   // make it off
                  digitalWrite(0, HIGH);
                  
                  digitalWrite(1,HIGH);
                  
                  digitalWrite(2, HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7,HIGH);
                  
                  delay(3000);
      } else if ((flexSensor1>=-11-error_range_flex && flexSensor1<=-11+error_range_flex) && 
                  (flexSensor2>=-22-error_range_flex && flexSensor2<=-22+error_range_flex)  &&
                  (flexSensor3>=-21-error_range_flex && flexSensor3<=-21+error_range_flex) &&                  
                  (accelorometerX>=27-error_range_accelorometer && accelorometerX<=27+error_range_accelorometer) && 
                  (accelorometerY>=27-error_range_accelorometer && accelorometerY<=27+error_range_accelorometer)
                  ) {
      
                  lcd.print("Thank You!");
                  
                  digitalWrite(0,HIGH ); // select voice command 4 on APR 33A3
                  
                  digitalWrite(1,HIGH );
                  
                  digitalWrite(2, HIGH);
                  
                  digitalWrite(3, LOW);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7, HIGH);
                  
                  delay (100);
                  
                  digitalWrite(0, HIGH); // make it off
                  
                  digitalWrite(1,HIGH);
                  
                  digitalWrite(2, HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7,HIGH);
                  
                  delay(3000);
      
      } else if ((flexSensor1>=-15-error_range_flex && flexSensor1<=-15+error_range_flex) && 
                  (flexSensor2>=-11-error_range_flex && flexSensor2<=-11+error_range_flex) &&
                  (flexSensor3>=-8-error_range_flex && flexSensor3<=-8+error_range_flex) &&
                  (accelorometerX>=27-error_range_accelorometer && accelorometerX<=27+error_range_accelorometer) && 
                  (accelorometerY>=21-error_range_accelorometer && accelorometerY<=21+error_range_accelorometer)
                  ) {
      
                  lcd.print("Please, Give me Water.");

                   // select voice command 5 on APR 33A3
                  digitalWrite(0,HIGH );
                  digitalWrite(1,HIGH );
                  
                  digitalWrite(2,HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, LOW);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7, HIGH);
                  
                  delay (100);

                  // make it off
                  digitalWrite(0, HIGH); 
                  
                  digitalWrite(1,HIGH);
                  
                  digitalWrite(2, HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7,HIGH);
                  
                  delay(3000);
      
      } else if ((flexSensor1>=-15-error_range_flex && flexSensor1<=-15+error_range_flex) && 
                  (flexSensor2>=-10-error_range_flex && flexSensor2<=-10+error_range_flex) &&
                  (flexSensor3>=-18-error_range_flex && flexSensor3<=-18+error_range_flex) &&
                  (accelorometerX>=27-error_range_accelorometer && accelorometerX<=27+error_range_accelorometer) && 
                  (accelorometerY>=20-error_range_accelorometer && accelorometerY<=20+error_range_accelorometer)
                  ) {
      
                  lcd.print("You are looking nice");

                   // select voice command 6 on APR 33A3
                  digitalWrite(0,HIGH );
      
                  digitalWrite(1,HIGH );
                  
                  digitalWrite(2,HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, LOW);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7, HIGH);
                  
                  delay (100);

                   // make it off
                  digitalWrite(0, HIGH);
                  
                  digitalWrite(1,HIGH);
                  
                  digitalWrite(2, HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7,HIGH);
                  
                  delay(3000);
      
      } else if ((flexSensor1>=-10-error_range_flex && flexSensor1<=-10+error_range_flex) && 
                  (flexSensor2>=-3-error_range_flex && flexSensor2<=-3+error_range_flex) &&
                  (flexSensor3>=-2-error_range_flex && flexSensor3<=-2+error_range_flex) &&
                  (accelorometerX>=28-error_range_accelorometer && accelorometerX<=28+error_range_accelorometer) && 
                  (accelorometerY>=21-error_range_accelorometer && accelorometerY<=21+error_range_accelorometer)
                  ) {
      
                  lcd.print("Excuse me !!");
                  
                   // select voice command 7 on APR 33A3
                  digitalWrite(0,HIGH);
      
                  digitalWrite(1,HIGH );
                  
                  digitalWrite(2,HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, LOW);
                  
                  digitalWrite(7, HIGH);
                  
                  delay (100);

                   // make it off
                  digitalWrite(0, HIGH);
                  
                  digitalWrite(1,HIGH);
                  
                  digitalWrite(2, HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7,HIGH);
                  
                  delay(3000);
      }  else if ((flexSensor1>=-22-error_range_flex && flexSensor1<=-22+error_range_flex) && 
                  (flexSensor2>=-23-error_range_flex && flexSensor2<=-23+error_range_flex) && 
                  (flexSensor3>=-20-error_range_flex && flexSensor3<=-20+error_range_flex) &&
                  (accelorometerX>=27-error_range_accelorometer && accelorometerX<=27+error_range_accelorometer) && 
                  (accelorometerY>=18-error_range_accelorometer && accelorometerY<=18+error_range_accelorometer)
                  ) {
      
                  lcd.print("I am not feeling well");
      
                  digitalWrite(0,HIGH); // select voice command 8 on APR 33A3
      
                  digitalWrite(1,HIGH );
                  
                  digitalWrite(2,HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7, LOW);
                  
                  delay (100);
                  
                  digitalWrite(0, HIGH); // make it off
                  
                  digitalWrite(1,HIGH);
                  
                  digitalWrite(2, HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7,HIGH);
                  
                  delay(3000);
      
      } else {
                   // inital message
                  lcd.print(" System on ");
                  
                  digitalWrite(0, HIGH);
                  
                  digitalWrite(1,HIGH );
                  
                  digitalWrite(2, HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, HIGH);
                  
                  digitalWrite(7,HIGH);
      
      }
      
                  delay(400); // delay of 200 msec
      
      }
