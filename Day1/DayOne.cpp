//
// Created by Ayaan Irshad on 11/30/24.
//
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string line;
    ifstream Input;
    //https://stackoverflow.com/questions/46719183/c-using-ifstream-to-read-file
    int dist = 0;
    vector<int> leftSide;
    vector<int> rightSide;
    Input.open("Day1/input.txt");
    if (Input.is_open()) {
        while (getline(Input, line)) {
            string left  = line.substr(0, 5);
            string right  = line.substr(8, 5);
            leftSide.push_back(stoi(left));
            rightSide.push_back(stoi(right));
        }//Every number is 5 digits
        Input.close();
    }

    std::sort(leftSide.begin(), leftSide.end());
    std::sort(rightSide.begin(), rightSide.end());
    cout << leftSide.size() << endl;
    cout << rightSide.size() << endl;
    for (int i = 0; i < leftSide.size(); ++i) {

        dist += abs(leftSide.at(i) - rightSide.at(i));
    }
    cout << dist;
    return 0;
}