#ifndef CSCI2275FINAL_QUEUE_H
#define CSCI2275FINAL_QUEUE_H

//#include "main.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


enum BallType {B = 1, R = 0, E = -1};
//circular queues

class circQueue {
private:
    int head;
    int tail;
    int count;
    int maxSize;
public:

    stringstream outputQueue();
    void inputQueue(stringstream input);
    BallType *queue;
    explicit circQueue(int size);
    bool isFull();
    bool isEmpty();
    BallType top();
    void enqueue(BallType);
    BallType dequeue();
    void printQueue();
};

#endif