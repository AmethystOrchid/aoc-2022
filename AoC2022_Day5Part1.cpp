#include "AoCUtility.h"

int main() {
    
    // get input (literally every day starts with this now)
    vector<string> input = readLines("InputDay5Part1.txt");

    // OK I'M GONNA MAKE THE INPUT OF THE BOARD MANUALLY
    deque<deque<char>> stacks = {
        {'F', 'C', 'P', 'G', 'Q', 'R'},
        {'W', 'T', 'C', 'P'},
        {'B', 'H', 'P', 'M', 'C'},
        {'L', 'T', 'Q', 'S', 'M', 'P', 'R'},
        {'P', 'H', 'J', 'Z', 'V', 'G', 'N'},
        {'D', 'P', 'J'},
        {'L', 'G', 'P', 'Z', 'F', 'J', 'T', 'R'},
        {'N', 'L', 'H', 'C', 'F', 'P', 'T', 'J'},
        {'G', 'V', 'Z', 'Q', 'H', 'T', 'C', 'W'}
     };

    // process the input
    vector<vector<int>> steps = { }; 
    for (string i : input)
    {
        istringstream iss(i);
        string a,b,c,d,e,f;

        iss >> a >> b >> c >> d >> e >> f;
        vector<int> foo = { stoi(b), stoi(d)-1, stoi(f)-1 };
        steps.push_back(foo);
    }

    for (auto i : steps) {for (auto j : i) {cout << j << " ";} cout << "\n";}

    // moving the crates part 1
    int count = 1;
    for (vector<int> step : steps)
    {
        cout << "iteration " << count << "\n";

        char buffer;

        for (int i = 0; i < step[0]; i++)
        {
            buffer = *(stacks[step[1]].end()-1);
            stacks[step[2]].push_back(buffer);
            stacks[step[1]].pop_back();
        }

        for (auto i : stacks) {for (auto j : i) {cout << j << " ";} cout << "\n";}
        cout << "\n=============\n";
        
        count++;
    }

    // Output
    for (deque<char> i : stacks) {cout << *(i.end()-1);}

    return 0;
}