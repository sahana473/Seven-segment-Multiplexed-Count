/*Interfacing two digit 7 Segment(Common Cathode) display to Arduino Uno to display value from 0 to 99
 * 
 * Hardware Components:
 * Sevensegment Display(Common Cathode)
 * Arduino Uno   
       
 * Hardware Connection:
 * Arduino Uno - Seven segment display connection
 * D2-D8 are connected to pin of seven segment display
 * To display digit:
 *                        a b c d e f g 
 *                   0 = {0,1,1,1,1,1,1}
 *                   1 = {0,0,0,0,1,1,0}
 *                   2 = {1,0,1,1,0,1,1}
 *                   3 = {1,0,0,1,1,1,1}
 *                   4 = {1,1,0,0,1,1,0}
 *                   5 = {1,1,0,1,1,0,1}
 *                   6 = {1,1,1,1,1,0,1}
 *                   7 = {0,0,0,0,1,1,1}
 *                   8 = {1,1,1,1,1,1,1}
 *                   9 = {1,1,0,1,1,1,1}
 *                   
 * Author : Sahana B G
 * Date   : 01 May 2021                                 
  */
 

// Data pins configuration from D2 - D8
const int FIRSTPIN = 2;
const int LASTPIN = 8;

// Control pins for 7 segment 
const int UNITCONTROLPIN = 13;
const int DECIMALCONTROLPIN = 12;

// Defining an array to store led pattern from 0 to 9
bool myArray[10][7] = {{0,1,1,1,1,1,1},
  {0, 0, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 0, 1, 1, 1, 1},
  {1, 1, 0, 0, 1, 1, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 1, 0, 1},
  {0, 0, 0, 0, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 0, 1, 1, 1, 1}};
 
void setup()
{
  // Configure control pins to output
  pinMode(UNITCONTROLPIN ,OUTPUT);
  pinMode(DECIMALCONTROLPIN ,OUTPUT);

  // Configure data pins to output 
  for(int i = FIRSTPIN ; i<=LASTPIN; i++ )
  pinMode(i,OUTPUT);

  // Initalise defaults for control pin. If control pin == HIGH -> turn off 7 segment 
  digitalWrite(UNITCONTROLPIN,HIGH);
  digitalWrite(DECIMALCONTROLPIN,HIGH);
}

void loop()
{
  // To display digit 0 - 99 repeatedly
  for(int i = 0;i<=99;i++)
  {
   displayNumber(i);
   delay(20);
  }
}

void displayNumber(const int num)
{
  // Turn on unit's place 7 segment
  digitalWrite(UNITCONTROLPIN,LOW);
  
  // Display number in unit place
  displayDigit(num%10);

  // Give delay to show the number
  delay(20);

  // Turn off unit's place 7 segment
  digitalWrite(UNITCONTROLPIN,HIGH);

  // Turn on decimal's place 7 segment
  digitalWrite(DECIMALCONTROLPIN , LOW);

  // Display number in decimal place
  displayDigit(num/10);

  // Give delay to show the number
  delay(20);

  // Turn off decimal's place 7 segment
  digitalWrite(DECIMALCONTROLPIN, HIGH);

}

void displayDigit(const int n)
{
  int pin = FIRSTPIN ; // Starts from first pin for next iteration
  
  // Iterate over pins to assign data
  for( int i = 0 ; i<7; i++)
  {
    digitalWrite(pin,myArray[n][i]);
    pin++;
  } 
}



 
