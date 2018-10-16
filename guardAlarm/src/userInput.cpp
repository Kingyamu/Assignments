/************************************
* Filename:userInput.cpp
* 
* author: valentin
* created: 2018-10-08
* notes:
* 
* desc:
* 
* ver: 2018-10-08 first version
* 
* 
* **********************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//function to read from user file
int readUser(int pinCode){

    //declaration of array and vector
    int users[5];
    std::vector<int> line;
    
    //variables
    double tmp;
    int count;

    std::ifstream inFile;
    inFile.open("users.dat");   //opens user file


    //suppose to put user.dat content into vector but dosn't work
    inFile >> count;
    for(int i = 0; i < count; i++){

        inFile >> tmp;
        line.push_back(tmp);
        std::vector<int> line(users, users+5);
        std::cout << count;
    }

    inFile.close();    //closes the file
    return checkIfPinExists(pinCode, line);
}

//bool function to see if pincode is in the file
bool checkIfPinExists(int pinCode, std::vector<int> line){

    for(int i = 0; i < line.size(); i++){
        if(pinCode == line.at(i)){
            return true;
        }
        return false;
    }
}