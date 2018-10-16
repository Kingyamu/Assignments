#ifndef ALARM_H
#define ALARM_H
#include <string>
#include <vector>

    int readUser(int pinCode);
    void loggUser(int userID, std::string loggText);
    bool checkIfPinExists(int pinCode, std::vector<int> line);

   #endif