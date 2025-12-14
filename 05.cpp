/**
 * 05.cpp
 * 
 * Find rotten ingredients in the elves database
 */

#include <iostream>
#include <string>
#include <vector>

int main(int argv, char** argc){
    
    std::string inputLine;
    getline(std::cin,inputLine);
    do{
        std::cout << inputLine << '\n';
        getline(std::cin,inputLine);
    }while(inputLine != "");

    while(!std::cin.eof()){
        getline(std::cin,inputLine);
        std::cout << inputLine << '\n';
    }

    return 0;
}