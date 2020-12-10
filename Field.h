#ifndef CSCI2275FINAL_FIELD_H
#define CSCI2275FINAL_FIELD_H

//#include "main.h"

#include "Queue.h"
#include "DLL.h"
#include "Score.h"

//TODO create field object that stores total field state

/*
 * BR RBR RB
 * BR     RB
 * BR BRB RB
 */

//TODO create field object interaction methods to change field state

class Field {
private:
    circQueue fieldState[9] = {circQueue(3), circQueue(3), circQueue(3), circQueue(3), circQueue(3), circQueue(3), circQueue(3), circQueue(3), circQueue(3)};
    DLL<string> lastMove;
    int freeRedBalls = 7;
    int freeBlueBalls = 7;
public:
    Field();
    //Field(Field const &source);
    Field clone();
    circQueue* getFieldState();
    Score currentScore();
    void printField();
    void lastMoveDump();
    void printAll();
    Field R1(Field seed);
    Field R2(Field seed);
    Field R3(Field seed);
    Field R4(Field seed);
    Field R5(Field seed);
    Field R6(Field seed);
    Field R7(Field seed);
    Field R8(Field seed);
    Field R9(Field seed);

    int scoreDifference();
    int towersOccupied();

};


#endif //CSCI2275FINAL_FIELD_H
