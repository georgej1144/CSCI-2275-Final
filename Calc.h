#ifndef CSCI2275FINAL_CALC_H
#define CSCI2275FINAL_CALC_H

#include "Queue.h"
#include "Queue.cpp"
#include "DLL.h"
#include "DLL.cpp"
#include "Field.h"
#include "Score.h"

class Calc {
private:
    DLL<Field> deltaCache;
    Score preCalcScore;
public:
    Calc();
    void bestDelta();
    void moveIterate(Field &startState, int nIterations);
};


#endif //CSCI2275FINAL_CALC_H
