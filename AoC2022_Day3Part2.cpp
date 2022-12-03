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
    for (string i : input) {lengths.push_back(i.length());}

    vector<char> prioChar = { };

    // time to check for duplicate
    for (int i = 0; i < input.size(); i += 3)
    {
        bool found = false;
        for (int j = 0; j < lengths[i]; j++)
        {
            for (int k = 0; k < lengths[i+1]; k++)
            {
                for (int l = 0; l < lengths[i+2]; l++)
                {
                    if ((input[i][j] == input[i+1][k]) && (input[i+1][k] == input[i+2][l]) && (input[i][j] == input[i+2][l])) {prioChar.push_back(input[i][j]); found = true; break;}
                }
                if (found) {break;}
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