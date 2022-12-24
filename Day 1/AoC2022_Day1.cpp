#include "AoCUtility.h"

int main() {

    // get input
    vector<string> input = readLines("InputDay1Part1.txt");

    vector<int> bruh = { 0 };
    int index = 0;
    int b = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == "") {index++; bruh.push_back(b); b = 0; continue;} else {b += stoi(input[i]);}
    }

    // Part 1
    cout << *max_element(bruh.begin(), bruh.end());

    // Part 2
    int r = 0;
    r += *max_element(bruh.begin(), bruh.end());
    bruh.erase(remove(bruh.begin(), bruh.end(), *max_element(bruh.begin(), bruh.end())), bruh.end());
    r += *max_element(bruh.begin(), bruh.end());
    bruh.erase(remove(bruh.begin(), bruh.end(), *max_element(bruh.begin(), bruh.end())), bruh.end());
    r += *max_element(bruh.begin(), bruh.end());
    cout << r;
    
    return 0;
}
