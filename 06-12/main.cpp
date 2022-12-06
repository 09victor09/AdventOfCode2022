#include <iostream>
#include <fstream>
#include <queue>

#define N_ELEMENTS 14

bool all_unique_queue(std::deque<char> &elements){
    for (int i = 0; i < elements.size(); ++i) {
        for (int j = i+1; j < elements.size(); ++j) {
            if(elements[i]==elements[j]){
                return false;
            }
        }
    }
    return true;
}


int main() {
    std::ifstream input{"input.txt"};
    std::string line;

    int position;

    std::getline(input, line);

    std::deque<char> elements;

    for(position = 0; position < N_ELEMENTS; ++position){
        elements.push_back(line[position]);
    }

    for (position = N_ELEMENTS; position < line.size(); ++position) {
        elements.pop_front();
        elements.push_back(line[position]);
        if(all_unique_queue(elements)) {
            position++;
            break;
        }
    }
    std::cout << position << std::endl;
    return 0;
}
