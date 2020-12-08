#ifndef CSCI2275FINAL_SCORE_H
#define CSCI2275FINAL_SCORE_H

#include <string>
#include <iostream>

using namespace std;

struct Score {
    int Home;
    int Away;
    string move;

    void printScore() const;
    void printScoreDifference() const;
    void printHome() const;
    void printAway() const;
    int difference() const;
};



#endif //CSCI2275FINAL_SCORE_H
