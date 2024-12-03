//
// Created by Ayaan Irshad on 12/2/24.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


vector<string> splitText(string text, char delimiter){ //delimiter is the character separator
    vector<string> result;

    int startIndex = 0;
    for (int i = 0; i < text.length(); ++i){
        if (text.at(i) == delimiter){
            result.push_back(text.substr(startIndex, i-startIndex));
            if (i != text.length()-1){
                startIndex = i+1;
            }
        }

        if (i==text.length()-1){
            result.push_back(text.substr(startIndex));
        }
    }
    return result;
}

bool evaluateReports(string reports){ // True is safe, false is unsafe

    vector<string> sep = splitText(reports, ' ');
    bool increasing = false;
    if (  stoi(sep.at(1)) > stoi(sep.at(0))  ) {
        increasing = true;
    }


    int diff;
    for (int i = 1; i < sep.size(); ++i){
        if (increasing) {diff = stoi(sep.at(i)) - stoi(sep.at(i-1));}
        else {diff = stoi(sep.at(i-1)) - stoi(sep.at(i)) ;}

        if ( (diff > 0) && (diff <= 3) ) {
            continue;
        }else{
            return false;
        }
    }

    return true;
}


int main(){

    ifstream Input;
    string line;
    int safe = 0;

    Input.open("Day2/input.txt");

    if (Input.is_open()) {
        while (getline(Input, line)) {
            if (evaluateReports(line)){safe++;}
        }
        Input.close();
    }
    cout << safe << endl;

    return 0;
}