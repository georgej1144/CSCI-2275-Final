//#include "main.h"

#include <iostream>
#include <string>
#include <sstream>
#include "Queue.h"

using namespace std;

circQueue::circQueue(int size) {
    head = tail = -1;
    maxSize = size;
    count = 0;
    queue = new string[maxSize];
    for(int i = 0; i < maxSize; i++) {
        queue[i] = "E";
    }
}

void circQueue::enqueue(string toQ) {
    //cout << "Enqueueing " << toQ << endl;
    if(tail == maxSize-1) {
        if(isFull()) {
            dequeue();
        }
        tail = -1;
    }
    if(head == -1) {
        head = 0;
    }
    tail++;
    count++;
    queue[tail] = toQ;
    //cout << tail << ": "<< toQ << endl;
}

string circQueue::dequeue() {
    if(queue[head] == "E") {
        cout << "Queue is empty" << endl;
        return "E";
    }
    if(head > maxSize-1) head = 0;
    string temp = queue[head];
    queue[head] = "E";
    head++;
    count--;
    //cout << "Dequeueing " << temp << endl;
    return temp;
}

void circQueue::printQueue() {
    if (head == -1) {
        cout << "error, shouldnt be empty like this";
        return;
    }

    //cout << "\nPrinting (circular) queue: " << endl;
    if (tail >= head) {
        for (int i = tail; i >= head; i--) {
            cout << queue[i] << "|";
        }
    } else {
        for (int i = tail; i >= 0; i--) {  ////////////
            cout << queue[i] << "|";
        }
        for (int i = maxSize; i >= head; i--) {
            cout << queue[i] << "|";
        }
    }
    cout << "   ";
}


bool circQueue::isFull() {
    return count == maxSize;
}


bool circQueue::isEmpty() {
    return count == 0;
}


string circQueue::top() {
    return queue[tail];
}


stringstream circQueue::outputQueue() {
    stringstream output;
    if (head == -1) {
        cout << "error, shouldnt be empty like this";
    }

    if (tail >= head) {
        for (int i = tail; i >= head; i--) {
            cout << queue[i] << "|";
            output << queue[i] << "|";
        }
    } else {
        for (int i = tail; i >= 0; i--) {  ////////////
            cout << queue[i] << "|";
            output << queue[i] << "|";
        }
        for (int i = maxSize; i >= head; i--) {
            cout << queue[i] << "|";
            output << queue[i] << "|";
        }
    }
    cout << "   ";
    return output;
}


void circQueue::inputQueue(stringstream input) {
    string line;
    string goal;
    string ball;
    while(getline(input, ball, '|')) {
        if(ball == "R") enqueue("R");
        if(ball == "B") enqueue("B");
        if(ball == "E") enqueue("E");
    }
}
