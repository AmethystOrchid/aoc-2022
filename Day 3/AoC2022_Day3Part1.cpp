#include "AoCUtility.h"

int convert(char c)
{
    if (('a' <= c) && (c <= 'z')) {return (c - 'a' + 1);}
    if (('A' <= c) && (c <= 'Z')) {return (c - 'A' + 1 + 26);}
}

int main() {
    
    // get input
    vector<string> input = readLines("InputDay3Part1.txt");
    vector<int> lengths = { };
    for (string i : input) {lengths.push_back(i.length() / 2);}

    //cout << "check 1\n";

    vector<char> prioChar = { };

    // time to check for duplicate
    for (int i = 0; i < input.size(); i++)
    {
        //cout << input[i] << "\n";
        bool found = false;
        for (int j = 0; j < lengths[i]; j++)
        {
            for (int k = lengths[i]; k < (lengths[i]*2); k++)
            {
                //cout << "check 4\n";
                if (input[i][j] == input[i][k]) {prioChar.push_back(input[i][j]); found = true; break;}
            }
            if (found) {break;}
        }
    }

    //for (char i : prioChar) {cout << i << " ";}
    vector<int> prio = { };
    for (char i : prioChar) {prio.push_back(convert(i));}

    //for (int i : prio) {cout << i << " ";}
    cout << accumulate(prio.begin(), prio.end(), 0) << "\n";

    return 0;

}
