#include <iostream>
#include <fstream>


int main() {
    std::ifstream fin;
    fin.open("input.txt");

    int first = 0;
    int second = 0;
    int third = 0;
    int total = 0;

    std::string line;
    while(std::getline(fin, line)){
        if(line == "\r"){
            if(total > first){
                second = first;
                third = second;
                first = total;
            }else if(total > second){
                third = second;
                second = total;
            }else if(total > third){
                third = total;
            }
            total = 0;

        }else
            total += std::stoi(line);
    }

    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << third << std::endl;
    std::cout << first+second+third << std::endl;
    return 0;
}
