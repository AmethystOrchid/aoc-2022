#include "AoCUtility.h"

const int SIDE = 98;

bool checkVisible(const vector<vector<int>>& vec, int x, int y)
{
    bool visibleUp = true, visibleDown = true, visibleLeft = true, visibleRight = true;
    int value = vec[y][x];

    // Check up
    for (int i = 0; i < y; i++) {if (vec[i][x] >= value) {visibleUp = false; break;}}

    // Check down
    for (int i = SIDE; i > y; i--) {if (vec[i][x] >= value) {visibleDown = false; break;}}

    // Check left
    for (int i = 0; i < x; i++) {if (vec[y][i] >= value) {visibleLeft = false; break;}}

    // Check right
    for (int i = SIDE; i > x; i--) {if (vec[y][i] >= value) {visibleRight = false; break;}}

    return (visibleUp || visibleDown || visibleLeft || visibleRight);
}


int calculateScenicScore(const vector<vector<int>>& vec, int x, int y)
{
    cout << "coords: (" << x << ", " << y << ") \t";

    int up = 0, down = 0, left = 0, right = 0;

    int currentVal = vec[y][x];

    // calculate up
    for (int i = y; i >= 0; i--)
    {
        // reached edge
        if (i-1 < 0) {break;}
        else
        {
            up++;
            if (vec[i-1][x] >= currentVal) {break;}
        }
    }

    // calculate down
    for (int i = y; i < SIDE; i++)
    {
        // reached edge
        if (i+1 > SIDE) {break;}
        else
        {
            down++;
            if (vec[i+1][x] >= currentVal) {break;}
        }
    }

    // calculate left
    for (int i = x; i >= 0; i--)
    {
        // reached edge
        if (i-1 < 0) {break;}
        else
        {
            left++;
            if (vec[y][i-1] >= currentVal) {break;}
        }
    }

    // calculate right
    for (int i = x; i < SIDE; i++)
    {
        // reached edge
        if (i+1 > SIDE) {break;}
        else
        {
            right++;
            if (vec[y][i+1] >= currentVal) {break;}
        }
    }

    cout << up << "\t" << down << "\t" << left << "\t" << right << "\n";

    return (up * down * left * right);
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

    // calculate the list of scenic scores
    vector<int> scores = { };

    for (int i = 1; i < SIDE; i++) 
    {
        for (int j = 1; j < SIDE; j++) 
        {
            scores.push_back(calculateScenicScore(grid, i, j));
        }
    }

    cout << *max_element(scores.begin(), scores.end());
    return 0;
}