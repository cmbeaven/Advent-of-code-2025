/*
    02.cpp

    Find invalid product ids in a comma deliminted list
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <utility>

long verifyPair(std::pair<std::string,std::string>& idPair){
    long illegalSum = 0;
    for(long x = std::stol(idPair.first); x <= std::stol(idPair.second); ++x){
        std::string temp = std::to_string(x);
        //printf("%s %s %s\n",temp.c_str(),temp.substr(0,temp.length()/2).c_str(),temp.substr(temp.length()/2,temp.length()).c_str());
        if(temp.substr(0,temp.length()/2) == temp.substr(temp.length()/2,temp.length()))
            illegalSum += x;
    }
    return illegalSum;
}

int main(int argv, char** argc){

    std::vector<std::pair<std::string,std::string>> idPairs;
    while(!std::cin.eof()){
        std::string input;
        getline(std::cin,input,',');
        int dash = input.find('-');
        std::string first = input.substr(0,dash);
        std::string second = input.substr(dash+1,input.length());
        idPairs.push_back(std::pair<std::string,std::string>(first,second));
    }

    long sum = 0;
    for(auto idPair : idPairs){
        printf("First: %s Second: %s\n",idPair.first.c_str(),idPair.second.c_str());
        sum += verifyPair(idPair);
    }
    printf("Sum: %li\n",sum);

    return 0;
}