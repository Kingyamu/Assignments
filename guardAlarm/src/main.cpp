/************************************
* Filename:guardAlarm.cpp
* 
* author: valentin
* created: 2018-09-25
* notes:
* 
* desc:
* 
* ver: 2018-09-25 first version
* 
* 
* **********************************/
#include <iostream>
#include <string>
#include <iomanip>

#include "cd../inc/alarm.h"

int main(){

    //declare variables
    int pinCode;
    int userID;
    int menu = 0, x = 3, z = 3, i = 0;

    bool repeat = true;
    while(repeat){ //infinite loop to always leave alarm ON/OFF and ask if you wanna turn it ON/OFF
    
        //shows that alarm is ON
        std::cout << std::setw(41) << std::setfill('*') << "*" << std::endl;
        std::cout << "*\t\t\t\t\t*" << std::endl;
        std::cout << "*\t\t\t\t\t*" << std::endl;
        std::cout << "*\t\tAlarm is ON\t\t*" << std::endl;
        std::cout << "*\t\t\t\t\t*" << std::endl;
        std::cout << "*\t\t\t\t\t*" << std::endl;
        std::cout << std::setw(41) << std::setfill('*') << "*" << std::endl;
        std::cout << "\t\t\t\t\t" << std::endl;

        std::cout << "Enter your pin: ";
        std::cin >> pinCode;

        if(readUser(pinCode)){
            loggUser(userID, "Alarm Off");

            //shows that alarm is OFF
            std::cout << std::setw(41) << std::setfill('*') << "*" << std::endl;
            std::cout << "*\t\t\t\t\t*" << std::endl;
            std::cout << "*\t\t\t\t\t*" << std::endl;
            std::cout << "*\t\tAlarm is OFF\t\t*" << std::endl;
            std::cout << "*\t\t\t\t\t*" << std::endl;
            std::cout << "*\t\t\t\t\t*" << std::endl;
            std::cout << std::setw(41) << std::setfill('*') << "*" << std::endl;
            std::cout << "\t\t\t\t\t" << std::endl;
        }

                //looks if pin entered is (pin +1) to see if it's an assualt
        else if(!checkIfPinExists){
            std::cout << std::setw(41) << std::setfill('*') << "*" << std::endl;
            std::cout << "*\t\t\t\t\t*" << std::endl;
            std::cout << "*\t\t\t\t\t*" << std::endl;
            std::cout << "*\t\tAlarm is OFF\t\t*" << std::endl;
            std::cout << "*\t\t\t\t\t*" << std::endl;
            std::cout << "*\t\t\t\t\t*" << std::endl;
            std::cout << std::setw(41) << std::setfill('*') << "*" << std::endl;
            std::cout << "\t\t\t\t\t" << std::endl;
            std::cout << "An alarm signal has been sent to the alarm central!";
            return 0;
        }
        else if(i == 3){
            std::cout << "You alarm is locked for failing to many times, the alarm central is notified.";
            return 0; //if user entered incorrect all tries program closes
        }
        else{
            std::cout << "PIN incorrect!" << std::endl;
            std::cout << "Try again please (" << x << " left): ";
            std::cin >> pinCode;
            i++;
        }

        //shows the menu
        std::cout << "*******************************************" << std::endl;
        std::cout << "*    What you wanna do?                   *" << std::endl;
        std::cout << "*                                         *" << std::endl;
        std::cout << "*    Alarm ON (press 1)                   *" << std::endl;
        std::cout << "*    Configure the alarm (press 2)        *" << std::endl;
        std::cout << "*                                         *" << std::endl;
        std::cout << "*******************************************" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "Press 1 or 2: ";
        std::cin >> menu;

        //looks what got selected on menu
        if(menu == 1){
            std::cout << "Enter your pin: ";
            std::cin >> pinCode;
            
            //same code as above to check if pin is correct
            bool checkPin3 = false;
            while(!checkPin3){
                for(int i = 0; i < 4; i++){
                    if(checkIfPinExists){
                        std::cout << "Your pin was correct!" << std::endl;
                        checkPin3 = true;
                        break;                      
                    }
                    else if(i == 3){
                        std::cout << "You alarm is locked for failing to many times, the alarm central is notified.";
                        return 0;
                    }
                    else{
                        std::cout << "PIN incorrect!" << std::endl;
                        std::cout << "Try again please (" << z << " left): ";
                        std::cin >> pinCode;
                        z--;
                    }
                }
            }
        }

        //if option 2 is selected or any others input is used program shuts down
        else{
            return 0;
        }
    }
}