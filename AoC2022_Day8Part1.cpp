#include "AoCUtility.h"

const int SIDE = 98;

bool checkVisible(const vector<vector<int>>& vec, int x, int y)
{
    bool visibleUp = true, visibleDown = true, visibleLeft = true, visibleRight = true;
    int value = vec[y][x];

    // Check up
    for (int i = 0; i < y; i++) {if (vec[i][x] >= value) {visibleUp = false; /*cout << "up broken\n";*/ break;}}

    // Check down
    for (int i = SIDE; i > y; i--) {if (vec[i][x] >= value) {visibleDown = false; /*cout << "down broken\n";*/ break;}}

    // Check left
    for (int i = 0; i < x; i++) {if (vec[y][i] >= value) {visibleLeft = false; /*cout << "left broken\n";*/  break;}}

    // Check right
    for (int i = SIDE; i > x; i--) {if (vec[y][i] >= value) {visibleRight = false; /*cout << "right broken\n";*/  break;}}

    return (visibleUp || visibleDown || visibleLeft || visibleRight);
}

int main() {
    
    // get input
    vector<string> input = readLines("InputDay8Part1.txt");

    // create grid
    vector<vector<int>> grid = { };

    // read grid
    for (string i : input)
    {
        vector<int> output = { };
        for (char j : i) {output.push_back(j - '0');}
        grid.push_back(output);
    }

    int result = SIDE*4;

    // check for visible trees
    for (int i = 1; i < SIDE; i++) 
    {
        for (int j = 1; j < SIDE; j++) 
        {
            if (checkVisible(grid, i, j)) {result++;}
        }
    }

    cout << result;
    return 0;
}