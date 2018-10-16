/************************************
* Filename:loggInput.cpp
* 
* author: valentin
* created: 2018-10-14
* notes:
* 
* desc:
* 
* ver: 2018-10-14 first version
* 
* 
* **********************************/
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

//function to logg when using pincode
void loggUser(int userID, std::string loggText){

    //declaration for variables in logg file
    int pinCode;
    int loggNo = 0;
    std::string reserved = "";
    std::string loggText;

    //loggs time of user input
    time_t my_time = time(NULL);
    std::string date = ctime(&my_time);

    std::ofstream outFile;
    outFile.open("system.log", std::ofstream::app);    //opens logg file

        loggNo++;
        outFile << loggNo << ";" << date << ";" << userID << ";" << reserved << ";" << loggText << '\n';    //inputs variables into file
    
    outFile.close();    //closes logg file
}