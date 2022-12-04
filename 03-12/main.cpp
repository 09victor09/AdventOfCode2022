#include <iostream>
#include <fstream>

int main() {
    std::ifstream fin;
    fin.open("input.txt");

    int total = 0;

    /*std::string line;
    while(std::getline(fin, line)){
        for (int i = 0; i < (line.size())/2; ++i) {
            for (int j = (line.size())/2; j < line.size(); ++j) {
                if(line[i] == line[j]){
                    if(int(line[i]) > 96) total += (int(line[i]) - 96);
                    else total += (int(line[i]) - 38);
                    i = line.size();
                    j = line.size() + 1;
                }
            }
        }
    }*/

    std::string line1;
    std::string line2;
    std::string line3;

    while(std::getline(fin, line1)){
        std::getline(fin, line2);
        std::getline(fin, line3);

        for (int i = 0; i < line1.size(); ++i) {
            for (int j = 0; j <line2.size(); ++j) {
                for (int k = 0; k < line3.size(); ++k) {
                    if(line1[i] == line2[j] && line1[i] == line3[k]){
                        if(int(line1[i]) > 96) total += (int(line1[i]) - 96);
                        else total += (int(line1[i]) - 38);
                        i = line1.size() +1;
                        j = line2.size() +1;
                        k = line3.size() +1;
                    }
                }
            }

        }
    }

    std::cout << total << std::endl;

    return 0;
}
