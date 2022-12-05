#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>


int main() {

    std::ifstream input{"input.txt"};
    std::string line;

    int n_deque = 9;
    int n_lines = 8;

    // declare an array of stacks
    std::deque<char> array[n_deque];

    //read the first 8 lines
    for (int i = 0; i < n_lines; ++i) {
        std::getline(input, line);
        //read the elements from the line and push into stack
        for (int j = 0; j < n_deque; ++j) {
            if(line[4*j+1] != ' ') array[j].emplace_front(line[4*j+1]);
        }
    }

    //ignore the next two lines
    std::string dummy;
    std::getline(input, dummy);
    std::getline(input, dummy);

    //move the values
    int moves, from, towards;
    std::stack<char> temp;
    while(std::getline(input, line)){
        std::stringstream ss{line};
        ss >> dummy;
        ss >> moves;
        ss >> dummy;
        ss >> from;
        ss >> dummy;
        ss >> towards;

        for (int i = 0; i < moves; ++i) {
            temp.push(array[from-1].back());
            array[from-1].pop_back();
        }
        for (int i = 0; i < moves; ++i) {
            array[towards-1].emplace_back(temp.top());
            temp.pop();
        }
    }

    //print the top values
    for (int i = 0; i < n_deque; ++i) {
        std::cout << array[i].back();
    }

    std::cout << std::endl;
    return 0;
}
