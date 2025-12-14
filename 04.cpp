/**
 * 04.cpp
 * 
 * Helps the elves maximize their efficiency in the printing dept.
 */

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

class charMatrix{
    public:
        void addRow(std::string_view row);
        char getLocation(int x, int y);
    private:
        int rowLength = 0;
        std::vector<std::string> matrix;
};

int main(int argv, char** argc){

    return 0;
}

void charMatrix::addRow(std::string_view row){
    if(rowLength == 0)
        rowLength = row.length();
    else if(rowLength != row.length())
        return;
    matrix.push_back(row.data());
}
char charMatrix::getLocation(int x, int y){
    // check bounds
    if(x < 0)
        return 0;
    if(y < 0)
        return 0;
    if(y > rowLength)
        return 0;
    if(x > matrix.size())
        return 0;
    
    return matrix[x][y];
}