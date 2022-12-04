#include <iostream>
#include <fstream>


int main() {
    std::ifstream fin;
    fin.open("input.txt");

    int total = 0;

    std::string line;
    while(std::getline(fin, line)){
        if(line[0] == 'A'){
            if(line[2] == 'X'){
                total += 3;

            }
            else if(line[2] == 'Y'){
                total += 3;
                total += 1;
            }
            else if(line[2] == 'Z'){
                total += 6;
                total += 2;
            }
        }
        else if(line[0] == 'B'){
            if(line[2] == 'X'){
                total += 1;
            }
            else if(line[2] == 'Y'){
                total += 3;
                total += 2;
            }
            else if(line[2] == 'Z'){
                total += 6;
                total += 3;
            }
        }
        else if(line[0] == 'C'){
            if(line[2] == 'X'){
                total += 2;

            }
            else if(line[2] == 'Y'){
                total += 3;
                total += 3;
            }
            else if(line[2] == 'Z'){
                total += 6;
                total += 1;
            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}
