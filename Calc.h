#ifndef CSCI2275FINAL_CALC_H
#define CSCI2275FINAL_CALC_H

//#include "main.h"

#include "Queue.h"
#include "DLL.h"
#include "Field.h"
#include "Score.h"

class Calc {
private:
    DLL<Field> deltaCache;
    Score preCalcScore;
public:
    Calc();
    void bestDelta();
    void moveIterate(const Field& startState, int nIterations);
};


#endif //CSCI2275FINAL_CALC_H
