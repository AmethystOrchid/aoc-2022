#include "AoCUtility.h"

int main() {
    
    // get input
    vector<string> input = readLines("InputDay2Part1.txt");

    vector<string> opponent = { }; vector<string> self = { };

    for (string line : input)
    {
        string x, y;
        istringstream iss(line);
        iss >> x >> y;
        
        opponent.push_back(x); self.push_back(y);
    }

    /*
        A = rock, B = paper, C = scissors
        X = rock = 1, Y = paper = 2, Z = scissors = 3
        0 = lose, 3 = draw, 6 = win
    */

    /*
    for (string i : opponent) {cout << i << " ";}
    cout << "\n";
    for (string i : self) {cout << i << " ";}
    */

    // Part 1

    /*
    int totalScore = 0;

    for (int i = 0; i < self.size(); i++)
    {
        totalScore += ((self[i] == "Z") ? (3) : ((self[i] == "Y") ? (2) : (1)));
        
        if (self[i] == "X")
        {
            if (opponent[i] == "A") {totalScore += 3;}
            else if (opponent[i] == "C") {totalScore += 6;}
        }
        else
        if (self[i] == "Y")
        {
            if (opponent[i] == "B") {totalScore += 3;}
            else if (opponent[i] == "A") {totalScore += 6;}
        }
        else
        if (self[i] == "Z")
        {
            if (opponent[i] == "C") {totalScore += 3;}
            else if (opponent[i] == "B") {totalScore += 6;}
        }
    }

    cout << totalScore;

    */

    // Part 2

    int totalScore = 0;
    
    // X = lose, Y = draw, Z = win

    for (int i = 0; i < self.size(); i++)
    {
        totalScore += ((self[i] == "Z") ? (6) : ((self[i] == "Y") ? (3) : (0)));


        /*
            A = rock, B = paper, C = scissors
            X = rock = 1, Y = paper = 2, Z = scissors = 3
            0 = lose, 3 = draw, 6 = win
        */
        if (self[i] == "X")
        {
            if (opponent[i] == "A") {totalScore += 3;}
            else if (opponent[i] == "B") {totalScore += 1;}
            else if (opponent[i] == "C") {totalScore += 2;}
        }
        else
        if (self[i] == "Y")
        {
            if (opponent[i] == "A") {totalScore += 1;}
            else if (opponent[i] == "B") {totalScore += 2;}
            else if (opponent[i] == "C") {totalScore += 3;}
        }
        else
        if (self[i] == "Z")
        {
            if (opponent[i] == "A") {totalScore += 2;}
            else if (opponent[i] == "B") {totalScore += 3;}
            else if (opponent[i] == "C") {totalScore += 1;}
        }
    }

    cout << totalScore;

    return 0;
}
