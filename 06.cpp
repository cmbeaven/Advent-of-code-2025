/**
 * 06.cpp
 * 
 * Help a young cephalapod with his homework
 */

#include <iostream>
#include <string>
#include <vector>

struct problem{
    std::vector<int> operands;
    char op;
};

std::vector<std::vector<std::string>> findOperands(const std::vector<std::string>& lines){
    std::vector<std::vector<std::string>> output;
    int prevCursor = 0;
    int cursor = 0;
    while(cursor <= lines[0].length()){
        bool isSpaces = true;
        for(auto line : lines){
            if(cursor == lines[0].length()) break;
            if(line[cursor] != ' '){
                cursor++;
                isSpaces = false;
                break;
            }
        }

        if(!isSpaces) continue;

        std::vector<std::string> nums;
        for(auto line : lines){
            nums.push_back(line.substr(prevCursor,cursor-prevCursor));
        }
        prevCursor = ++cursor;
        output.push_back(nums);
    }
    return output;
}

long sumEq(std::vector<problem>& ps){
    long sum = 0;
    for(auto p : ps){
        long temp = p.op == '*' ? 1:0;
        for(auto i : p.operands){
            switch(p.op){
                case '+':
                    temp += i;
                    break;
                case '*':
                    temp *= i;
                    break;
                default:
                    break;
            }
        }
        sum += temp;
    }
    return sum;
}

 int main(int argv, char** argc){
    std::vector<std::string> lines;
    std::vector<char> operators;

    while(!std::cin.eof()){
        std::string inputLine;
        getline(std::cin, inputLine);

        int prevCursor = 0;
        int cursor = 0;
        if(inputLine[0] == '*' || inputLine[0] == '+'){
            for(auto c : inputLine){
                if(c == '*' || c == '+')
                    operators.push_back(c);
            }
            break;
        }
        lines.push_back(inputLine);
    }

    std::vector<problem> p1Problems;
    std::vector<problem> p2Problems;

    std::vector<std::vector<std::string>> operands = findOperands(lines);

    for(auto op : operands){
        for(auto s : op){
            printf("%s ",s.c_str());
        }
        printf("\n");
    }
    for(auto c : operators){
        printf("%c ",c);
    }
    printf("\n");


    for(int i = 0; i < operands.size(); i++){
        problem p;
        p.op = operators[i];
        for(auto s : operands[i]){
            p.operands.push_back(std::stoi(s));
        }
        p1Problems.push_back(p);
    }

    for(int i = 0; i < operands.size(); i++){
        problem p;
        p.op = operators[i];
        std::vector<std::string> nums = operands[i];
        for(int j = 0; j < nums[0].length(); j++){
            std::string num = "";
            for(auto s : nums){
                printf("%s|%c\n",s.c_str(),s[j]);
                num.push_back(s[j]);
            }
            printf("%i|%s\n",num.length(),num.c_str());
            p.operands.push_back(std::stoi(num));
        }
        p2Problems.push_back(p);
    }

    long sum = sumEq(p1Problems);
    printf("sum: %li\n",sum);
    long sum2 = sumEq(p2Problems);
    printf("sum2:%li\n",sum2);

    return 0;
 }