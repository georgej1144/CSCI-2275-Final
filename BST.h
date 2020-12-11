#ifndef CSCI2275FINAL_BST_H
#define CSCI2275FINAL_BST_H


#include <string>
#include "Field.h"

using namespace std;


struct BSTNode{
    Field* fieldState;
    int scoreDiff;
    BSTNode* parent;
    BSTNode* leftChild;
    BSTNode* rightChild;

    BSTNode(Field* in_field, BSTNode *p, BSTNode *lc, BSTNode *rc)
    {
        fieldState = in_field;
        scoreDiff = fieldState->scoreDifference();
        parent = p;
        leftChild = lc;
        rightChild = rc;
    };
};


class BST {
private:
    void insertAt(Field* inField, BSTNode* parent, bool left); //use this function to find pointer to node in BST
    BSTNode* root = nullptr;
public:
    BST();
    void addNode(Field* inField);
    Field returnBest1();
    Field returnBest2();
    Field returnBest3();
};


#endif //CSCI2275FINAL_BST_H
