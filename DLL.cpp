#pragma once

#include <string>
#include <iostream>
#include "DLL.h"

using namespace std;

//doubly linked list

template <typename T>
DLL<T>::DLL() {
    head = nullptr;
    tail = nullptr;
}

template <typename T>
DLL<T>::~DLL() {
    if(head == nullptr) {
        cout << "Nothing to delete, LL empty." << endl;
    }
    LLNode<T> *crawler = head;
    while(crawler != nullptr) {
        head = head->next;
        //cout << "deleting node with key: " << crawler->index << endl;
        delete crawler;
        crawler = head;
    }
    head = nullptr;
}

////add value to the front of the list
//template <typename T>
//void DLL<T>::prepend(T value) {
//    if(head == nullptr) {
//        auto *node = new LLNode<T>;
//        node->data = value;
//        head = node;
//        tail = node;
//        return;
//    }
//    auto *node = new LLNode<T>;
//    node->data = value;
//    node->next = head;
//    head->prev = node;
//
//    head = node;
//}

//add value to the end
template <typename T>
void DLL<T>::append(T value) {
    if(head == nullptr) {
        auto *node = new LLNode<T>;
        node->data = value;
        node->index = 0;
        head = node;
        tail = node;
        return;
    }
    auto *node = new LLNode<T>;
    node->data = value;
    node->prev = tail;
    tail->next = node;
    node->index = node->prev->index + 1;

    tail = node;
}

//iterate through LL and print each value
template <typename T>
void DLL<T>::showLL() {
    if (head == nullptr) {
        cout << "empty LL" << endl;
        return;
    }

    LLNode<T> *crawler = head;
    while(crawler != nullptr) {
        cout << crawler->index;
        if (crawler->next != nullptr) //no arrow after last node
            cout << " --> ";
        crawler = crawler->next;
    }

    cout << "\n\nhead: " << head->index << endl;
    cout << "tail: " << tail->index << endl << endl;
}

template <typename T>
void DLL<T>::reverseShow() {
    LLNode<T> *crawler;

    crawler = tail;

    while(crawler!= NULL) {
        cout << crawler->index << " --> ";
        crawler = crawler->prev;

    }
}

template <typename T>
T DLL<T>::dataAtTail() {
        if(!tail) {return nullptr;}
    return tail->data;
}

template<typename T>
T DLL<T>::dataAtIndex(int index) {
    auto crawl = head;

    while(crawl) {
        if(crawl->index == index) {
            return crawl->data;
        }
        crawl = crawl->next;
    }
}

template<typename T>
LLNode<T>* DLL<T>::getHead() {
    return head;
}