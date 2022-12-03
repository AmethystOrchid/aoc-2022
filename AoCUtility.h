#ifndef AOCUTIL
#define AOCUTIL

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

// Basic Read Lines, modify type whenever
vector<string> readLines(string filename)
{
    ifstream file(filename);
    string line;
    vector<string> result;

    while (getline(file, line)) {result.push_back(line);}

    return result;
}

template <typename T>
vector<T> readLinewithComma(string input)
{
    istringstream iss(input);
    string line;
    vector<T> result;

    while (getline(iss, line, ',')) {result.push_back(line);}

    return result;
}


#endif