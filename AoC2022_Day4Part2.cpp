#include "AoCUtility.h"

int main() {
    
    // get input (literally every day starts with this now)
    vector<string> input = readLines("InputDay4Part1.txt");

    vector<string> process1 = { }; 

    vector<vector<int>> processed = { }; 
    
    for (string i : input)
    {
        istringstream iss(i);
        string line;

        while (getline(iss, line, ',')) {process1.push_back(line);}
    }

    int buffer = 0;
    vector<int> result = { };

    for (string i : process1)
    {
        istringstream iss(i);
        string line;
        
        while (getline(iss, line, '-')) 
        {
            result.push_back(stoi(line));
            buffer++;

            if (buffer >= 4) 
            {
                processed.push_back(result);
                buffer = 0;
                result = { };
            }
        }
    }

    //for (auto i : processed) {for (auto j : i) {cout << j << " ";} cout << "\n";}
    
    // check for pairs

    // Part 2

    int pairs = 1000;

    for (auto i : processed)
    {
        for (auto j : i) {cout << j << " ";} 
        if (i[0] > i[2])
        {
            if (i[0] > i[3])
            {cout << "no"; pairs--;}
        } 
        else if (i[2] > i[0])
        {
            if (i[2] > i[1])
            {cout << "no"; pairs--;}
        } 
        else {cout << "yes";}
        cout << "\n";
    }
    
    cout << pairs;

    return 0;
}


