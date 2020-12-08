#ifndef CSCI2275FINAL_DLL_H
#define CSCI2275FINAL_DLL_H

using namespace std;

//16 red balls
//16 blue balls
//9 goals in tic tac toe
//A Ball Scored in a Goal is worth one (1) point for the Alliance of the color of the Ball.
//A Connected Row is worth six (6) points for that Alliance.

//TODO add user interaction and finalize

template <typename T>
struct LLNode {
    int index;
    T data;
    LLNode *next = nullptr;       //this is the 'link' to the next node in a linked list
    LLNode *prev = nullptr;
};

template <typename T>
class DLL {
private:
    LLNode<T> *head;
    LLNode<T> *tail;
public:
    DLL();
    ~DLL();
    T dataAtIndex(int index);
    LLNode<T>* getHead();
    //void prepend(T val);
    void append(T val);
    void showLL();
    T dataAtTail();
    void reverseShow();
};




#endif //CSCI2275FINAL_DLL_H
