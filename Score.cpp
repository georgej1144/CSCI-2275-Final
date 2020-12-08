#include "Score.h"
#include <iostream>

void Score::printScore() const {
    cout << "Home: " << Home << " Away: " << Away << endl;
}

void Score::printScoreDifference() const {
    cout << "Score difference: " << difference() << endl;
}

void Score::printHome() const {
    cout << Home << endl;
}

void Score::printAway() const {
    cout << Away << endl;
}

int Score::difference() const {
    return Home - Away;
}