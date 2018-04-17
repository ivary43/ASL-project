
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 13, 11, 10, 9, 8); // Check circuit diagram for pin connections
void setup() {

lcd.begin(16, 2);
//Serial.begin(9600);

//Output pin for apr33a3
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

    lcd.clear();
    lcd.setCursor(0, 1);

    int val0 = analogRead(0); // read the input pin flex sensor pin 1

    val0 = map(val0, 465, 590, 0, 9); // convert it into window of 0 to 9

    int val1 = analogRead(1); // read the input pin flex sensor pin 2

    val1 = map(val1, 435, 535, 0, 9);

    int val2 = analogRead(2); // read the input pin X axis pin
    
    val2 = map(val2, 260, 415, 0, 9);
    
    int val3 = analogRead(3); // read the input pin y axis pin
    
    val3 = map(val3, 260, 420, 0, 9);

    int flexSensor3 = analogRead(5);

    flexSensor3 = map(flexSensor3, 445, 520, 0, 9);
    
    Serial.println("--------------------------------------------");
    Serial.print("Flex 1--->");Serial.println(val0);
    // read the input pin
    Serial.print("Flex 2----->");Serial.println(val1);
    Serial.print("Flex 3--->");Serial.println(flexSensor3);
    Serial.print("Accelorometer x ----->");Serial.println(val2);
    // read the input pin
    Serial.print("Acceleromoeter y----->");Serial.println(val3);
    Serial.println("--------------------------------------------");
    Serial.println();

    //buffer period for accelorometer and flex
    int bufferp=2;
    int accpuffer=3;
     // match the signs to standard store values values depend on wearing hands 
    if ((val0>=-21-bufferp && val0<=-21+bufferp) && 
        (val1>=-23-bufferp && val1<=-23+bufferp )&& 
        (flexSensor3>=-3-bufferp && flexSensor3<=-3+bufferp)
//        (val2>=40-accpuffer && val2<=40+accpuffer) &&
//        (val3>=37-accpuffer && val3<=37+accpuffer)
            )  {

            lcd.print("I am Manish"); // Show message on LCD
            
            digitalWrite(0,LOW); // select voice command 1 on APR 33A3
            
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

      } else if ( (val0>=-21-bufferp && val0<=-21+bufferp) && 
                  (val1>=-5-bufferp && val1<=-5+bufferp)&&
                  (flexSensor3>=-1-bufferp && flexSensor3<=-1+bufferp)  
//                  (val2>=40-accpuffer && val2<=40+accpuffer) && 
//                  (val3>=23-accpuffer && val3<=23+accpuffer)
                      ) {
      
                  lcd.print("I am sorry");
                  
                  digitalWrite(0,HIGH); // select voice command 2 on APR 33A3
                  
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
      
      } else if ((val0>=-17-bufferp && val0<=-17+bufferp) && 
                  (val1>=-19-bufferp && val1<=-19+bufferp) &&
                  (flexSensor3>=-19-bufferp && flexSensor3<=-19+bufferp) 
                  
//                  (val2>=28-accpuffer && val2<=28+accpuffer) && 
//                  (val3>=24-accpuffer && val3<=24+accpuffer)
                    ) {
      
                  lcd.print("Hello,How are u?");
      
                  digitalWrite(0,HIGH ); // select voice command 3 on APR 33A3
                  
                  digitalWrite(1,HIGH );
                  
                  digitalWrite(2,LOW);
                  
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
      } else if ((val0>=-11-bufferp && val0<=-11+bufferp) && 
                  (val1>=-22-bufferp && val1<=-22+bufferp)  &&
                  (flexSensor3>=-21-bufferp && flexSensor3<=-21+bufferp)
                  
//                  (val2>=27-accpuffer && val2<=27+accpuffer) && 
//                  (val3>=27-accpuffer && val3<=27+accpuffer)
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
      
      } else if ((val0>=-15-bufferp && val0<=-15+bufferp) && 
                  (val1>=-11-bufferp && val1<=-11+bufferp) &&
                  (flexSensor3>=-8-bufferp && flexSensor3<=-8+bufferp)
//                  (val2>=27-accpuffer && val2<=27+accpuffer) && 
//                  (val3>=21-accpuffer && val3<=21+accpuffer)
                  ) {
      
                  lcd.print("Please, Give me Water.");
      
                  digitalWrite(0,HIGH ); // select voice command 5 on APR 33A3
                  digitalWrite(1,HIGH );
                  
                  digitalWrite(2,HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, LOW);
                  
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
      
      } else if ((val0>=-15-bufferp && val0<=-15+bufferp) && 
                  (val1>=-10-bufferp && val1<=-10+bufferp) &&
                  (flexSensor3>=-18-bufferp && flexSensor3<=-18+bufferp)
//                  (val2>=27-accpuffer && val2<=27+accpuffer) && 
//                  (val3>=20-accpuffer && val3<=20+accpuffer)
                  ) {
      
                  lcd.print("You are looking nice");
      
                  digitalWrite(0,HIGH ); // select voice command 6 on APR 33A3
      
                  digitalWrite(1,HIGH );
                  
                  digitalWrite(2,HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, LOW);
                  
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
      
      } else if ((val0>=-10-bufferp && val0<=-10+bufferp) && 
                  (val1>=-3-bufferp && val1<=-3+bufferp) &&
                  (flexSensor3>=-2-bufferp && flexSensor3<=-2+bufferp) 
//                  (val2>=28-accpuffer && val2<=28+accpuffer) && 
//                  (val3>=21-accpuffer && val3<=21+accpuffer)
                  ) {
      
                  lcd.print("Excuse me !!");
      
                  digitalWrite(0,HIGH); // select voice command 7 on APR 33A3
      
                  digitalWrite(1,HIGH );
                  
                  digitalWrite(2,HIGH);
                  
                  digitalWrite(3, HIGH);
                  
                  digitalWrite(4, HIGH);
                  
                  digitalWrite(5, HIGH);
                  
                  digitalWrite(6, LOW);
                  
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
      }  else if ((val0>=-22-bufferp && val0<=-22+bufferp) && 
                  (val1>=-23-bufferp && val1<=-23+bufferp) && 
                  (flexSensor3>=-20-bufferp && flexSensor3<=-20+bufferp)
//                  (val2>=27-accpuffer && val2<=27+accpuffer) && 
//                  (val3>=18-accpuffer && val3<=18+accpuffer)
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
      
                  lcd.print(" System on "); // inital message
                  
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
