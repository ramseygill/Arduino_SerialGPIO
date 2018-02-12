//=======================================================================================================================
// PFF - Pneumatic Force Fixture {Provides serial control of 15 pneumatic transducers via Arduino Mega 2560)
// Author: Ramsey Gill
// Wiki:
// Created: 12/9/2016
// References:
// https://www.arduino.cc/en/Main/ArduinoBoardMega2560
// http://www.arduino.cc/en/Tutorial/SwitchCase2
//
//=======================================================================================================================
//Libraries

//=======================================================================================================================
//Variables and Pin Assignments

//Pin Assignments
//"PWM: 2 to 13 and 44 to 46. Provide 8-bit PWM output with the analogWrite() function. (15 total PWM lines)"
const int pwmPin1 = 2;  //Transducer 1 control pin
const int pwmPin2 = 3;  //Transducer 2 control pin
const int pwmPin3 = 4;  //Transducer 3 control pin
const int pwmPin4 = 5;  //Transducer 4 control pin
const int pwmPin5 = 6;  //Transducer 5 control pin
const int pwmPin6 = 7;  //Transducer 6 control pin
const int pwmPin7 = 8;  //Transducer 7 control pin
const int pwmPin8 = 9;  //Transducer 8 control pin
const int pwmPin9 = 10; //Transducer 9 control pin
const int pwmPin10 = 11; //Transducer 10 control pin
const int pwmPin11 = 12; //Transducer 11 control pin
const int pwmPin12 = 13; //Transducer 12 control pin
const int pwmPin13 = 44; //Transducer 13 control pin
const int pwmPin14 = 45; //Transducer 14 control pin
const int pwmPin15 = 46; //Transducer 15 control pin

//Variables
//-----------------------------------------------------------------------------------------------------------------
int workingPsi = 150; //change this to set systems working pressure.(used to debug approximate PWM to PSI calculations)
//-----------------------------------------------------------------------------------------------------------------

int aPSI; // Variable to store Transducer 1's estimated pressure value in.(debug only)
int bPSI;
int cPSI;
int dPSI;
int ePSI;
int fPSI;
int gPSI;
int hPSI;
int iPSI;
int jPSI;
int kPSI;
int lPSI;
int mPSI;
int nPSI;
int oPSI;

int aPWM = 0; // Variable to store Transducer 1's PWM value in
int bPWM = 0;
int cPWM = 0;
int dPWM = 0;
int ePWM = 0;
int fPWM = 0;
int gPWM = 0;
int hPWM = 0;
int iPWM = 0;
int jPWM = 0;
int kPWM = 0;
int lPWM = 0;
int mPWM = 0;
int nPWM = 0;
int oPWM = 0;

//=======================================================================================================================
//Setup

void setup() {
  // initialize serial communication:
  Serial.begin(115200); //faster than the usual 9600 baud, higher the data rate the better for test systems.

  pinMode (pwmPin1, OUTPUT); //configure PWM pins as outputs
  pinMode (pwmPin2, OUTPUT);
  pinMode (pwmPin3, OUTPUT);
  pinMode (pwmPin4, OUTPUT);
  pinMode (pwmPin5, OUTPUT);
  pinMode (pwmPin6, OUTPUT);
  pinMode (pwmPin7, OUTPUT);
  pinMode (pwmPin8, OUTPUT);
  pinMode (pwmPin9, OUTPUT);
  pinMode (pwmPin10, OUTPUT);
  pinMode (pwmPin11, OUTPUT);
  pinMode (pwmPin12, OUTPUT);
  pinMode (pwmPin13, OUTPUT);
  pinMode (pwmPin14, OUTPUT);
  pinMode (pwmPin15, OUTPUT);

}
//=======================================================================================================================
//Main Loop

void loop() {

  while (Serial.available()) { // checks for a serial connection to control PC
    int inByte = Serial.read(); //

    //Serial.println(inByte); //uncomment for debug

    switch (inByte) {
      case 'a': //Transducer 1
        aPWM = Serial.parseInt();                  //read in next three characters after the switch preamble
        if (aPWM >= 0 && aPWM <= 255) {            //IF statement provides user input validation.
                                                   //set to pwmPin12 to debug (built in LED on Arduino pin 13)
          analogWrite(pwmPin12, aPWM);              //write PWM value to PWM pin, this will drive the transducer 0-5 VDC
          aPSI = map(aPWM, 0, 255, 0, workingPsi); //map the PWM value from 0-255 to 0-workingPsi value.
          //Optional debug messages
          Serial.print("T01 - PWM:");              //print transducer number and PWM to one line in the serial monitor
          Serial.print(aPWM);                      //print transducer PWM value to the same serial monitor line
          Serial.print(" PSI:");                   //print PSI prefix and a space to the same serial monitor line
          Serial.println(aPSI);                    //print PSI value to the same line and finish with a carrige return.
        }
        break;
      case 'b': //Transducer 2
        bPWM = Serial.parseInt();
        if (bPWM >= 0 && bPWM <= 255) {
          analogWrite(pwmPin2, bPWM);
          bPSI = map(bPWM, 0, 255, 0, workingPsi);
          Serial.print("T02 - PWM:");
          Serial.print(bPWM);
          Serial.print(" PSI:");
          Serial.println(bPSI);
        }
        break;
      case 'c': //Transducer 3
        cPWM = Serial.parseInt();
        if (cPWM >= 0 && cPWM <= 255) {
          analogWrite(pwmPin3, cPWM);
          cPSI = map(cPWM, 0, 255, 0, workingPsi);
          Serial.print("T03 - PWM:");
          Serial.print(cPWM);
          Serial.print(" PSI:");
          Serial.println(cPSI);
        }
          break;
        case 'd': //Transducer 4

          break;
        case 'e': //Transducer 5

          break;
        case 'f': //Transducer 6

          break;
        case 'g': //Transducer 7

          break;
        case 'h': //Transducer 8

          break;
        case 'i': //Transducer 9

          break;
        case 'j': //Transducer 10

          break;
        case 'k': //Transducer 11

          break;
        case 'l': //Transducer 12

          break;
        case 'm': //Transducer 13

          break;
        case 'n': //Transducer 14

          break;
        case 'o': //Transducer 15

          break;

          //default: //uncomment to set a default state
          // turn all the tranducers off if invalid command is recieved.
          //for (int thisPin = 2; thisPin < 47; thisPin++) {
          //analogWrite(thisPin, 0);
        }
    }
  }

//=======================================================================================================================
  //Functions

//=======================================================================================================================

