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

    int iter = 3;

    // unordered set, reminds me of my python days eh
    for (; iter < foo.size(); iter++)
    {
        unordered_set<char> test = { };
        cout << foo[iter-3] << foo[iter-2] << foo[iter-1] << foo[iter] << "\n";

        test.insert(foo[iter]); 
        test.insert(foo[iter-1]); 
        test.insert(foo[iter-2]); 
        test.insert(foo[iter-3]);
        //print1Dcontainer(test);

        if (test.size() == 4) {break;}
    }

    cout << iter+1;

    return 0;
}
