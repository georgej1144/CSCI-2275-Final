//#include "main.h"
#include "Field.h"
#include "Queue.h"
#include <string>
#include "DLL.h"

Field::Field() {
    ///////////////////////////////
    fieldState[0].enqueue(R);
    fieldState[0].enqueue(B);

    fieldState[1].enqueue(R);
    fieldState[1].enqueue(B);
    fieldState[1].enqueue(R);

    fieldState[2].enqueue(B);
    fieldState[2].enqueue(R);
    ///////////////////////////////
    fieldState[3].enqueue(R);
    fieldState[3].enqueue(B);


    fieldState[5].enqueue(B);
    fieldState[5].enqueue(R);
    ///////////////////////////////
    fieldState[6].enqueue(R);
    fieldState[6].enqueue(B);

    fieldState[7].enqueue(B);
    fieldState[7].enqueue(R);
    fieldState[7].enqueue(B);

    fieldState[8].enqueue(B);
    fieldState[8].enqueue(R);
    ///////////////////////////////

    lastMove.append("");
}

//Field::Field(const Field &source) {
//    copy(&source.fieldState[0], &source.fieldState[0]+9, &fieldState[0]);
//}

Field Field::clone() {
    auto newField = new Field();

    for(int x = 0; x < 9; x++) {
        newField->fieldState[x].inputQueue(fieldState[x].outputQueue());
        if((x+1)%3 == 0) cout << endl;
    }
    newField->lastMove.inputDLL(lastMove.outputDLL());

    newField->freeRedBalls = freeRedBalls;
    newField->freeBlueBalls = freeBlueBalls;

    return *newField;
}

Score Field::currentScore() {
    Score output;

    for(int i = 0; i < 9; i++) {        //todo FIX, JUST ADD COUNTERS DEQUEUEING BAD BAD
        auto *tempQueue = new circQueue(3);
        tempQueue = fieldState;

        BallType tempBall;

        while(!tempQueue[i].isEmpty()) {
            tempBall = tempQueue[i].dequeue();

            if(tempBall == R) output.Home++;
            if(tempBall == B) output.Away++;
        }
    }

    freeRedBalls = 16-output.Home;
    freeBlueBalls = 16-output.Away;

    if(fieldState[1].top() == R && fieldState[2].top() == R && fieldState[3].top() == R) output.Home += 6;
    if(fieldState[4].top() == R && fieldState[5].top() == R && fieldState[6].top() == R) output.Home += 6;
    if(fieldState[7].top() == R && fieldState[8].top() == R && fieldState[9].top() == R) output.Home += 6;
    if(fieldState[1].top() == R && fieldState[4].top() == R && fieldState[7].top() == R) output.Home += 6;
    if(fieldState[2].top() == R && fieldState[5].top() == R && fieldState[8].top() == R) output.Home += 6;
    if(fieldState[3].top() == R && fieldState[6].top() == R && fieldState[9].top() == R) output.Home += 6;
    if(fieldState[1].top() == R && fieldState[5].top() == R && fieldState[9].top() == R) output.Home += 6;
    if(fieldState[3].top() == R && fieldState[5].top() == R && fieldState[7].top() == R) output.Home += 6;

    if(fieldState[1].top() == B && fieldState[2].top() == B && fieldState[3].top() == B) output.Away += 6;
    if(fieldState[4].top() == B && fieldState[5].top() == B && fieldState[6].top() == B) output.Away += 6;
    if(fieldState[7].top() == B && fieldState[8].top() == B && fieldState[9].top() == B) output.Away += 6;
    if(fieldState[1].top() == B && fieldState[4].top() == B && fieldState[7].top() == B) output.Away += 6;
    if(fieldState[2].top() == B && fieldState[5].top() == B && fieldState[8].top() == B) output.Away += 6;
    if(fieldState[3].top() == B && fieldState[6].top() == B && fieldState[9].top() == B) output.Away += 6;
    if(fieldState[1].top() == B && fieldState[5].top() == B && fieldState[9].top() == B) output.Away += 6;
    if(fieldState[3].top() == B && fieldState[5].top() == B && fieldState[7].top() == B) output.Away += 6;

    return output;
}

void Field::lastMoveDump() {
    lastMove.showLL();
}

Field Field::R1(Field seed) {
    Field output = seed.clone();

    if(!(lastMove.dataAtTail() == "CLOSE1")) {
        if(output.freeRedBalls > 0) {
            output.lastMove.append("addR1");
            output.fieldState[1].enqueue(R);
            output.freeRedBalls--;
        } else {
            output.lastMove.append("No more red balls on the field");
            output.lastMove.append("CLOSE1");
        }
    }
    return output;
}
Field Field::R2(Field seed) {
    Field output = seed.clone();

    if(!(lastMove.dataAtTail() == "CLOSE2")) {
        if(output.freeRedBalls > 0) {
            output.lastMove.append("addR2");
            output.fieldState[2].enqueue(R);
            output.freeRedBalls--;
        } else {
            output.lastMove.append("No more red balls on the field");
            output.lastMove.append("CLOSE2");
        }
    }
    return output;
}
Field Field::R3(Field seed) {
    Field output = seed.clone();

    if(!(lastMove.dataAtTail() == "CLOSE3")) {
        if(output.freeRedBalls > 0) {
            output.lastMove.append("addR3");
            output.fieldState[3].enqueue(R);
            output.freeRedBalls--;
        } else {
            output.lastMove.append("No more red balls on the field");
            output.lastMove.append("CLOSE3");
        }
    }
    return output;
}
Field Field::R4(Field seed) {
    Field output = seed.clone();

    if(!(lastMove.dataAtTail() == "CLOSE4")) {
        if(output.freeRedBalls > 0) {
            output.lastMove.append("addR4");
            output.fieldState[4].enqueue(R);
            output.freeRedBalls--;
        } else {
            output.lastMove.append("No more red balls on the field");
            output.lastMove.append("CLOSE4");
        }
    }
    return output;
}
Field Field::R5(Field seed) {
    Field output = seed.clone();

    if(!(lastMove.dataAtTail() == "CLOSE5")) {
        if(output.freeRedBalls > 0) {
            output.lastMove.append("addR5");
            output.fieldState[5].enqueue(R);
            output.freeRedBalls--;
        } else {
            output.lastMove.append("No more red balls on the field");
            output.lastMove.append("CLOSE5");
        }
    }
    return output;
}
Field Field::R6(Field seed) {
    Field output = seed.clone();

    if(!(lastMove.dataAtTail() == "CLOSE6")) {
        if(output.freeRedBalls > 0) {
            output.lastMove.append("addR6");
            output.fieldState[6].enqueue(R);
            output.freeRedBalls--;
        } else {
            output.lastMove.append("No more red balls on the field");
            output.lastMove.append("CLOSE6");
        }
    }
    return output;
}
Field Field::R7(Field seed) {
    Field output = seed.clone();

    if(!(lastMove.dataAtTail() == "CLOSE7")) {
        if(output.freeRedBalls > 0) {
            output.lastMove.append("addR7");
            output.fieldState[7].enqueue(R);
            output.freeRedBalls--;
        } else {
            output.lastMove.append("No more red balls on the field");
            output.lastMove.append("CLOSE7");
        }
    }
    return output;
}
Field Field::R8(Field seed) {
    Field output = seed.clone();

    if(!(lastMove.dataAtTail() == "CLOSE8")) {
        if(output.freeRedBalls > 0) {
            output.lastMove.append("addR8");
            output.fieldState[8].enqueue(R);
            output.freeRedBalls--;
        } else {
            output.lastMove.append("No more red balls on the field");
            output.lastMove.append("CLOSE8");
        }
    }
    return output;
}
Field Field::R9(Field seed) {
    Field output = seed.clone();

    if(!(lastMove.dataAtTail() == "CLOSE9")) {
        if(output.freeRedBalls > 0) {
            output.lastMove.append("addR9");
            output.fieldState[9].enqueue(R);
            output.freeRedBalls--;
        } else {
            output.lastMove.append("No more red balls on the field");
            output.lastMove.append("CLOSE9");
        }
    }
    return output;
}

circQueue *Field::getFieldState() {
    return fieldState;
}
