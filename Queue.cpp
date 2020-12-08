#pragma once

#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

template <typename T>
circQueue<T>::circQueue(int size) {
    head = tail = -1;
    maxSize = size;
    count = 0;
    queue = new T[maxSize];
    for(int i = 0; i < maxSize; i++) {
        queue[i] = E;
    }
}

template <typename T>
void circQueue<T>::enqueue(T toQ) {
    //cout << "Enqueueing " << toQ << endl;
    if(tail == maxSize-1) {
        if(isFull()) {
            cout << "Queue is already full" << endl;
            return;
        }
        tail = -1;
    }
    if(head == -1) {
        head = 0;
    }
    tail++;
    count++;
    queue[tail] = toQ;
}

template <typename T>
T circQueue<T>::dequeue() {
    if(queue[head] == -1) {
        cout << "Queue is empty" << endl;
        return E;
    }
    if(head > maxSize-1) head = 0;
    T temp = queue[head];
    queue[head] = E;
    head++;
    count--;
    //cout << "Dequeueing " << temp << endl;
    return temp;
}

template <typename T>
void circQueue<T>::printQueue() {
    if (head == -1) {
        cout << "Queue empty" << endl;
        return;
    }

    cout << "\nPrinting (circular) queue: " << endl;
    if (tail >= head) {
        for (int i = head; i <= tail; i++) {
            cout << "q[" << i << "]: " << queue[i] << " | ";
        }
    } else {
        for (int i = head; i < maxSize; i++) {
            cout << "q[" << i << "]: " << queue[i] << " | ";
        }
        for (int i = 0; i <= tail; i++) {
            cout << "q[" << i << "]: " << queue[i] << " | ";
        }
    }
    cout << endl;
}

template <typename T>
bool circQueue<T>::isFull() {
    return count == maxSize;
}

template <typename T>
bool circQueue<T>::isEmpty() {
    return count == 0;
}

template <typename T>
T circQueue<T>::top() {
    return queue[tail];
}