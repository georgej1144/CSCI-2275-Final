//#include "main.h"

#include <iostream>
#include <string>
#include <sstream>
#include "Queue.h"

using namespace std;

bool LLQueue::isEmpty() {
    return head == nullptr && tail == nullptr || size == 0;
}

void LLQueue::enqueue(string toQ) {
    if(isEmpty()) {
        head = new QNode(toQ);
        tail = head;
        size++;
        return;
    }
    if(isFull()) {
        dequeue();
    }
    auto tempTail = tail;
    tail = new QNode(toQ);
    tempTail->next = tail;
    tail->prev = tempTail;
    size++;
}

string LLQueue::dequeue() {     //careful, untested
    if(isEmpty()) {
        cout << "Queue is empty" << endl;
        return "E";
    }
    if(head->next) {
        auto temp = head;
        head = head->next;
        delete temp;
        size--;
    } else {
        enqueue("E");
        dequeue();
    }
    return head->data;
}

string LLQueue::top() {
    return tail->data;
}

void LLQueue::printQueue() {
    if (!isEmpty()) {
        auto crawler = head;

        while(crawler) {
            cout << crawler->data << "|";
            crawler = crawler->next;
        }
        cout << "   ";
    } else {
        cout << "q empty, can't print" << endl;
    }
}

stringstream LLQueue::outputQueue() {
    stringstream output;
    if (!isEmpty()) {
        auto crawler = head;
        //cout << "\nHead" << endl;
        while(crawler) {
            output << crawler->data << "|";
            crawler = crawler->next;
        }
        output << "   ";
    } else {
        cout << "q empty, can't print" << endl;
    }
    return output;
}

void LLQueue::inputQueue(stringstream input) {
    string ball;
    while(getline(input, ball, '|')) {
        if(ball == "R") enqueue("R");
        if(ball == "B") enqueue("B");
        if(ball == "E") enqueue("E");
    }
}

bool LLQueue::isFull() {
    return size == maxSize;
}

/*

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
        tail = -1;  ///
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
    if(isEmpty()) {
        cout << "Queue is empty" << endl;
        return "E";
    }
    string temp = queue[head];
    queue[head] = "E";
    head++;
    if(head > maxSize-1) head = 0;
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
        for (int i = maxSize-1; i >= head; i--) {
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
        for (int i = maxSize-1; i >= head; i--) {
            cout << queue[i] << "|";
            output << queue[i] << "|";
        }
    }
    cout << "   ";
    return output;
}


void circQueue::inputQueue(stringstream input) {
    string ball;
    while(getline(input, ball, '|')) {
        if(ball == "R") enqueue("R");
        if(ball == "B") enqueue("B");
        if(ball == "E") enqueue("E");
    }
}*/