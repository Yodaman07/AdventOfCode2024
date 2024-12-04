//
// Created by Ayaan Irshad on 12/3/24.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;
int main(){
    string line;
    ifstream Input;

    regex pattern;
    pattern.assign("mul\\((\\d+),(\\d+)\\)"); //Regex 101
    smatch sm;
    int total = 0;


    Input.open("Day3/input.txt");
    if (Input.is_open()) {
        while (getline(Input, line)) {

            while (true) {
                regex_search(line, sm, pattern);
                //Not most efficent but works https://stackoverflow.com/questions/21667295/how-to-match-multiple-results-using-stdregex


//                cout << sm[1] << "+ " << sm[2] << endl;
                if (sm.empty()) {break;}
                total += (stoi(sm[1]) * stoi(sm[2]));
                line = sm.suffix();
            }


        }
        Input.close();
    }
    cout << total;
    return 0;
}