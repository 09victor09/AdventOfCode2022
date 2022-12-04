#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    auto iss = std::ifstream{"input.txt"};

    int total1 = 0;
    int total2 = 0;
    std::string line;
    while(std::getline(iss, line)){
        //split the line in two tokens
        std::stringstream tokenss(line);
        std::string token1;
        std::string token2;
        std::getline(tokenss, token1, ',');
        std::getline(tokenss, token2);

        //split the first token into two chars
        std::stringstream charss1(token1);
        std::string char1;
        std::string char2;
        std::getline(charss1, char1, '-');
        std::getline(charss1, char2);

        //split the second token into two chars
        std::stringstream charss2(token2);
        std::string char3;
        std::string char4;
        std::getline(charss2, char3, '-');
        std::getline(charss2, char4, '\r');

        //part1
        //token1 is greater than the token2
        if((stoi(char1)<=stoi(char3)) && (stoi(char2)>=stoi(char4))) total1++;
            //token2 is greater than token1
        else if((stoi(char1)>=stoi(char3)) && (stoi(char2)<=stoi(char4))) total1++;

        //part2
        if((stoi(char1)<=stoi(char4)) && (stoi(char2)>=stoi(char3))) total2++;

    }
    std::cout << total1 << std::endl;
    std::cout << total2 << std::endl;
    return 0;
}
