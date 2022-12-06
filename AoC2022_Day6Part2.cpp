#include "AoCUtility.h"

int main() {
    
    // get input
    vector<string> input = readLines("InputDay6Part1.txt");

    vector<char> foo = { };
    for (int k = 0; k < input[0].length(); k++)
    {
        foo.push_back(input[0][k]);
    }

    //print1Dcontainer(foo);

    int iter = 14;

    // unordered set, reminds me of my python days eh
    for (; iter < foo.size(); iter++)
    {
        unordered_set<char> test = { };

        for (int i = 0; i < 14; i++) {test.insert(foo[iter-i]); }
        //print1Dcontainer(test);

        if (test.size() == 14) {break;}
    }

    cout << iter+1;

    return 0;
}