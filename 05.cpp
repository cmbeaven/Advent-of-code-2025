/**
 * 05.cpp
 * 
 * Find rotten ingredients in the elves database
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>

typedef std::pair<long,long> range;

int main(int argv, char** argc){
    
    std::string inputLine;
    std::vector<range> freshRanges;
    std::vector<long> ingredients;
    getline(std::cin,inputLine);
    do{
        int splitLocation = inputLine.find('-');
        range temp;
        temp.first = std::stol(inputLine.substr(0,splitLocation));
        temp.second = std::stol(inputLine.substr(splitLocation+1,inputLine.length()));
        std::cout << temp.first << "-" << temp.second << "\n";
        freshRanges.push_back(temp);
        getline(std::cin,inputLine);
    }while(inputLine != "");

    while(!std::cin.eof()){
        getline(std::cin,inputLine);
        ingredients.push_back(std::stol(inputLine));
        std::cout << inputLine << '\n';
    }

    return 0;
}