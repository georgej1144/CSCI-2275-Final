//#include "main.h"
#include "Calc.h"
#include <cmath>
#include "Field.h"
#include "Queue.h"
#include "DLL.h"
#include "Score.h"

Calc::Calc() = default;

//TODO optional, store deltas in tree for faster parse

void Calc::bestDelta() {
    Field best1;
    Field best2;
    Field best3;

    auto crawl = deltaCache.getHead();
    while(crawl) {
        if(crawl->data.currentScore().difference() > best1.currentScore().difference()) {
            best3 = best2;
            best2 = best1;
            best1 = crawl->data;
        } else if(crawl->data.currentScore().difference() > best2.currentScore().difference()) {
            best3 = best2;
            best2 = crawl->data;
        } else if(crawl->data.currentScore().difference() > best3.currentScore().difference()) {
            best3 = crawl->data;
        }

        crawl = crawl->next;
    }
    //mass output of best moves
    cout <<"-----Results from greatest to least-----" << endl;
    best1.currentScore().printScore();
    cout << "Resulting score difference: " << best1.currentScore().difference() << endl;
    cout << "Difference in score difference: " << best1.currentScore().difference() - preCalcScore.difference() << endl;
    cout << "Path: ";
    best1.lastMoveDump();
    cout << endl;

    best2.currentScore().printScore();
    cout << "Resulting score difference: " << best2.currentScore().difference() << endl;
    cout << "Difference in score difference: " << best2.currentScore().difference() - preCalcScore.difference() << endl;
    cout <<"Path: ";
    best2.lastMoveDump();
    cout << endl;

    best3.currentScore().printScore();
    cout << "Resulting score difference: " << best3.currentScore().difference() << endl;
    cout << "Difference in score difference: " << best3.currentScore().difference() - preCalcScore.difference();
    cout << "Path: ";
    best3.lastMoveDump();
    cout << endl;
}

void Calc::moveIterate(const Field& startState, int nIterations) {
    Field inputField(startState);

    preCalcScore = inputField.currentScore();

    deltaCache.append(inputField);
    for(int i = 0; i < pow(9,nIterations-1); i++) {
        deltaCache.append(inputField.R1(deltaCache.dataAtIndex(i)));
        deltaCache.append(inputField.R2(deltaCache.dataAtIndex(i)));
        deltaCache.append(inputField.R3(deltaCache.dataAtIndex(i)));
        deltaCache.append(inputField.R4(deltaCache.dataAtIndex(i)));
        deltaCache.append(inputField.R5(deltaCache.dataAtIndex(i)));
        deltaCache.append(inputField.R6(deltaCache.dataAtIndex(i)));
        deltaCache.append(inputField.R7(deltaCache.dataAtIndex(i)));
        deltaCache.append(inputField.R8(deltaCache.dataAtIndex(i)));
        deltaCache.append(inputField.R9(deltaCache.dataAtIndex(i)));
        inputField = deltaCache.dataAtIndex(i);
    }
}