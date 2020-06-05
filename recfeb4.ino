#include <VirtualWire.h>
#include <VirtualWire_Config.h>
#include <SoftwareSerial.h>



// Pins definition
const int led_pin = 13;
const int transmit_pin = 12;
const int receive_pin = 11;
const int buzz = 10;
String textForSMS;
SoftwareSerial SIM900(7, 8);//rx,tx

void setup()
{
   // Init
   delay(1000);
   Serial.begin(9600); // Debugging only
   SIM900.begin(9600);
   Serial.println("setup");

   // Initialise the IO and ISR
   vw_set_rx_pin(receive_pin);
   vw_setup(2000); // Transmission rate

   // Start the receiver PLL
   vw_rx_start();

   SIM900.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000); 
 SIM900.println("AT+CNMI=2,2,0,0,0\r"); // AT Command to receive a live SMS
 delay(1000);
  SIM900.println("AT+CMGDA=\r");
  delay(1000);
  Serial.println("DEL ALL");

   // Set LED pin
   pinMode(led_pin, OUTPUT);
}

void loop()
{
   uint8_t buf[VW_MAX_MESSAGE_LEN];
   uint8_t buflen = VW_MAX_MESSAGE_LEN;
   //delay(5000);
   // Check if a message was received
if (vw_get_message(buf, &buflen))
   {
   // Flash a light to show received good message
   digitalWrite(led_pin, HIGH);
    Serial.print("Got: ");
    
    textForSMS =  "\nIntruder detected";  
       //digitalWrite(relay, HIGH); 
  sendSMS(textForSMS);

  //  digitalWrite(led_pin, LOW);





  

   // Print message
   for (int i = 0; i < buflen; i++)
   {
     Serial.print(char(buf[i]));
     Serial.print(' ');
   }
   Serial.println();
   delay(1000);
   digitalWrite(led_pin, LOW);
   }

     int i=0;int j=0;
 char data[200]="";
 char ch;
 while(j<5)
 {
  //if(digitalRead(9)==LOW)
  //{
   // call();
  //}
  if(SIM900.available())
  {
   while(SIM900.available()<=0);
   //Serial.println("Hi");
   ch=SIM900.read();
   if(ch=='#')
   break;
   data[i]=data[i]+ch;
   i++;
 }j++;
 }
 Serial.println(data);
 if(strstr(data,"buzz"))
 {
  Serial.println("buzzing");
  digitalWrite(10,HIGH);
  delay(5000);
  digitalWrite(10,LOW);
 }
}



void sendSMS(String message)
{   Serial.println("CALLING."); 
  SIM900.println("ATD+918072708412;");
    delay(15000);
    SIM900.println("ATH");
  SIM900.print("AT+CMGF=1\r");                     // AT command to send SMS message
  delay(1000);
 //SIM900.println("AT + CMGS = \"+919176907540\"");  // recipient's mobile number, in international format
 
  delay(1000);
  SIM900.println(message);                         // message to send
  delay(1000);
  SIM900.println((char)26);                        // End AT command with a ^Z, ASCII code 26
  delay(1000); 
  SIM900.println();
  delay(100);                                     // give module time to send SMS
 
}
