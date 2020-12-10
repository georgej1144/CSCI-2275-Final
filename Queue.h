#ifndef CSCI2275FINAL_QUEUE_H
#define CSCI2275FINAL_QUEUE_H

//#include "main.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


//enum BallType {B = 1, R = 0, E = 2};
//circular queues

struct QNode {
    string data;
    QNode* next;
    QNode* prev;

    QNode() {
        data = nullptr;
        next = nullptr;
        prev = nullptr;
    }

    explicit QNode(string toQ) {
        data = toQ;
        next = nullptr;
    }
};

class LLQueue {
private:
    QNode* head;
    QNode* tail;
    int maxSize;
    int size = 0;

public:
    LLQueue() {
        maxSize = 3;
        head = nullptr;
        tail = nullptr;
    };
    bool isEmpty();
    bool isFull();
    void enqueue(string);  //optional
    string dequeue();      //optional
    string top();
    void printQueue();
    stringstream outputQueue();
    void inputQueue(stringstream input);
};

/*
class circQueue {
private:
    int head;
    int tail;
    int count;
    int maxSize;
    string* queue;

public:
    stringstream outputQueue();
    void inputQueue(stringstream input);
    explicit circQueue(int size);
    bool isFull();
    bool isEmpty();
    string top();
    void enqueue(string);
    string dequeue();
    void printQueue();
};
*/
#endif