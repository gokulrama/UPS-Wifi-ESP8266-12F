#include "Energia.h"


// Include application, user and local libraries

#ifndef __CC3200R1M1RGC__
#include <SPI.h>                // Do not include SPI for CC3200 LaunchPad
#endif
#include <WiFi.h>


// Define structures and classes


// Define variables and constants
static const uint8_t smps_14 = 2;  
static const uint8_t smps_33  = 6;
static const uint8_t cap_relay = 24;
long smps_14_voltage = 0;
long smps_33_voltage = 0;
long caprelay_voltge = 0;
long sensorValue2 = 0;
long sensorValue1 = 0;
long s=0;  
long r=0;  
char wifi_name[]     ="ESP-8266";
char wifi_password[] ="12341234";
int compare_string =0;
int compare_string1=0;
int compare_string2=0;
int compare_string3=0;
int compare_string4=0;
int compare_string5=0;
const int indicationpin=YELLOW_LED;
const int loadrelaypin=30;
const char res[] ={"CHECK"};
const char battery_voltage_request[]          = {xxx};
const char battery_voltage_response[]         = {xxx};
const char battery_percentage_request[]       = {xxx};
const char battery_remaining_request[]        = {xxx};
const char Load_percentage_request[]          = {xxx};
const char Load_percentage_response[]         = {xxx};
const char Mains_response[]                   = {xxx};
const char Dups_On[]                          = {xxx};
const char Dups_Off[]                         = {xxx};
const char Dups_On_response[]                 = {xxx};
const char Dups_Off_response[]                = {xxx};
const char Dups_sync[]                        = {xxx};
const char Dups_sync_response[]               = {xxx};



WiFiServer myServer(8000);

uint8_t oldCountClients = 0;
uint8_t countClients = 0;


// Add setup code
void setup()
{
    Serial.begin(9600);
    delay(500);
    pinMode(indicationpin, OUTPUT);
     pinMode(loadrelaypin, OUTPUT);
    Serial.println("*** LaunchPad CC3200 WiFi Web-Server in AP Mode");
    
    // Start WiFi and create a network with wifi_name as the network name
    // with wifi_password as the password.
    Serial.print("Starting AP... ");
    WiFi.beginNetwork(wifi_name, wifi_password);
    while (WiFi.localIP() == INADDR_NONE)
    {
        // print dots while we wait for the AP config to complete
        Serial.print('.');
        delay(300);
    }
    //Serial.println("DONE");
    
    Serial.print("LAN name = ");
    Serial.println(wifi_name);
    Serial.print("WPA password = ");
    Serial.println(wifi_password);
    
  
    
   IPAddress ip = WiFi.localIP();
  //IPAddress ip(192,168,1,1);
    Serial.print("Webserver IP address = ");
    Serial.println(ip);
    Serial.print("Web-server port = ");
    myServer.begin();                           // start the web server on port 80
    Serial.println("80");
    //Serial.println();
}

     void loop()
    {
     
      WiFiClient myClient = myServer.available();
      if (myClient)
       {                                                            
        char buffer[300] = {0};                                   
        int8_t i = 0;
        while (myClient.connected())
        {                                                          
            if (myClient.available())                              

            {
             
              char string[100]={0};
             
                       
              int availableBytes = myClient.available();
              int indication =availableBytes;
          
                 if (indication>0)
                  {
                  digitalWrite(indicationpin,HIGH);
                  delay(100);
                  digitalWrite(indicationpin,LOW);
                  }
                                                                                                                                                                                        
                  for(int i=0; i<(availableBytes); i++)
                   {
                   string[i] =  myClient.read();
                   //Serial.print(string[i]);
                   }
                   
                   Serial.print("MOBILE  ---->  DUPS :");

                  for(int i=0; i<8; i++)
                   {
                    Serial.print(string[i]);
                   
                   }
                  
                  
                   

                  
                 // compare_string =strcmp(string,Dups_sync);
                 // compare_string1=strcmp(string,Dups_On);
                  //compare_string2=strcmp(string,Dups_Off);
                  //compare_string3=strcmp(string,battery_voltage_request);
                  compare_string4=strcmp(string,res);
                 // compare_string5=strcmp(string,Load_percentage_request);

                 
                 /*if(compare_string==0)
                 {
                   for(int a=0;a<8;i++)
                  {
                     myClient.print(Dups_sync_response[a]);
                   
                  }


                   Serial.print("DUPS  ---->  MOBILE :");
                  
                   for(int a=0;a<8;i++)
                  {
                   
                     Serial.print(Dups_sync_response[a],HEX);
                  }
                  
                 }


                 
                 if(compare_string1==0)
                 {
                  
                     //myClient.print(Dups_On_response);
                  
                     //Serial.print("DUPS  ---->  MOBILE :");
                  
                    
                   
                     Serial.print(Dups_On_response);
                     
                 
                }
                   
                  if(compare_string2==0)
                  
                 {
                     for(int a=0;a<8;i++)
                    {
                     myClient.print(Dups_Off_response[a]);
                    }


                    Serial.print("DUPS  ---->  MOBILE :");
                  
                    for(int a=0;a<8;i++)
                    {
                   
                     Serial.print(Dups_Off_response[a],HEX);
                    }
                 
                 }

                if(compare_string3==0)
                  {
                   for(int a=0;a<8;i++)
                    {
                     myClient.print(battery_voltage_response[a]);
                    }

                    Serial.print("DUPS  ---->  MOBILE :");
                  
                    for(int a=0;a<8;i++)
                    {
                   
                     Serial.print(battery_voltage_response[a],HEX);
                    }
                 
                  }
                  */
                  // if(compare_string4==0)
                 // {
                     //myClient.print("Message Received");
                     Serial.print("DUPS  ---->  MOBILE :");
                     for(i=0;i<8;i++) 
                     {
                       //myClient.print(Load_percentage_response[i]);
                       //myClient.print(battery_voltage_response[i]);
                        myClient.print(Mains_response[i]);
                     }
                    
                     //Serial.print("Message Received");
                  //}


                  
                  /*if(compare_string5==0)
                  {
                    for(int a=0;a<8;i++)
                     {
                     myClient.print(Load_percentage_response[a]);
                     }

                     Serial.print("DUPS  ---->  MOBILE :");
                  
                    for(int a=0;a<8;i++)
                     {
                     Serial.print(Load_percentage_response[a],HEX);
                     }
                     
                  }*/
                              
               // myClient.println(s);
             
            }
        }
        
        // close the connection:
        myClient.stop();
        //Serial.println(". Client disconnected from server");
        //Serial.println();
    }
}
 




