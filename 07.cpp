/**
 * 07.cpp
 * 
 * Determine the number of total tachyon beams in the teleportation device
 */

#include <iostream>
#include <vector>

void printGrid(std::vector<std::string>& v){
    for(auto s : v){
        printf("%s\n",s.c_str());
    }
}
// beam goes straight down until it reaches a splitter, then goes left and right
long quantumDeterminator(std::vector<std::string>& grid,int x, int y){
    long timelines = 0;
    for(int i = y; i < grid.size(); i++){
        if(grid[i][x] == '^'){
            // go left
            timelines += quantumDeterminator(grid,x-1,i+1);
            // go right
            timelines += quantumDeterminator(grid,x+1,i+1);
            break;
        } 
    }
    printf("%li\n",timelines);
    return timelines == 0? 1:timelines;
}

int main(int argv, char** argc){
    std::vector<std::string> splitterGrid;
    while(!std::cin.eof()){
        std::string inputLine;
        getline(std::cin,inputLine);
        splitterGrid.push_back(inputLine);
    }
    std::vector<std::string> workGrid(splitterGrid);
    printGrid(workGrid);
    long sum = 0;
    for(int i = 0; i < workGrid.size() - 1; i++){
        for(int j = 0; j < workGrid[i].length(); j++){
            // beam must go on
            if(workGrid[i][j] == '|' || workGrid[i][j] == 'S'){
                if(workGrid[i+1][j] == '^'){
                    workGrid[i+1][j-1] = '|';
                    workGrid[i+1][j+1] = '|';
                    sum++;
                }
                else{
                    workGrid[i+1][j] = '|';                    
                }
            }
        }
        printGrid(workGrid);
    }
    // reserve the memory for the quantum grid
    std::vector<std::vector<long>> quantumPaths(splitterGrid.size());
    for(auto v : quantumPaths){
        v.reserve(splitterGrid[0].length());
    }
    // fill grid
    for(int i = 0; i < splitterGrid.size(); i++){
        for(int j = 0; j < splitterGrid[0].length(); j++){
            quantumPaths[i].push_back(0);
        }
    }
    for(int i = 0; i < splitterGrid[0].length(); i++){
        quantumPaths[quantumPaths.size()-1][i] = 1;
    }
    for(int i = quantumPaths.size()-2; i >= 0; i--){
        // go through each
        for(int j = 1; j < splitterGrid[0].length()-1;j++){
            if(splitterGrid[i][j] == '^'){
                quantumPaths[i][j] = quantumPaths[i+1][j-1] + quantumPaths[i+1][j+1];
            }
            else{
                quantumPaths[i][j] = quantumPaths[i+1][j];
            }
        }
    }

    // for(auto v : quantumPaths){
    //     for(auto l : v){
    //         printf("%li ",l);
    //     }
    //     printf("\n");
    // }

    //long lsum = quantumDeterminator(splitterGrid,splitterGrid[0].find('S'),0);
    long lsum = 0;
    for(auto l : quantumPaths[0]){
        if(l > lsum){
            lsum = l;
        }
    }
    printf("Sum:  %li\n",sum);
    printf("lSum: %li\n",lsum);

    return 0;
}