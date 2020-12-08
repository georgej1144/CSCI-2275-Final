#ifndef CSCI2275FINAL_QUEUE_H
#define CSCI2275FINAL_QUEUE_H

#include <iostream>
#include <string>

using namespace std;


enum BallType {B = 1, R = 0, E = -1};
//circular queues
template <typename T>
class circQueue {
private:
    int head;
    int tail;
    int count;
    int maxSize;
public:

    T *queue;
    explicit circQueue(int size);

    bool isFull();
    bool isEmpty();
    T top();
    void enqueue(T);
    T dequeue();
    void printQueue();
};

#endif