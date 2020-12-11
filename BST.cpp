#include "BST.h"
#include <string>
#include <fstream>
#include <iostream>
#include "BST.h"

using namespace std;

BST::BST() {}

//void BST::printBST(BSTNode *node) {
//    if(node->leftChild != nullptr) printBST(node->leftChild);
//    cout << node->word << " | " << node ->count << endl;
//    if(node->rightChild != nullptr) printBST(node->rightChild);
//}

//void BST::printPreOrderBST(BSTNode *node) {
//    cout << node->word << " | " << node ->count << endl;
//    if(node->leftChild != nullptr) printBST(node->leftChild);
//    if(node->rightChild != nullptr) printBST(node->rightChild);
//}

//void BST::countBSTNodes(BSTNode *node, int &c) {
//    if(node->leftChild != nullptr) countBSTNodes(node->leftChild, c);
//    c++;
//    if(node->rightChild != nullptr) countBSTNodes(node->rightChild, c);
//}

//void BST::printWord(std::string word) {
//    auto crawler = root;
//
//    while(crawler != nullptr) {
//
//        if(crawler->word.compare(word) > 0) {   //left tree
//            if(crawler->leftChild != nullptr) crawler = crawler->leftChild;
//        } else if(crawler->word.compare(word) < 0) {    //right tree
//            if(crawler->rightChild != nullptr) crawler = crawler->rightChild;
//        } else {    //up count
//            cout << "The word " << word << " appears " << crawler->count << "." << endl;
//            if(crawler->parent != nullptr) cout << "Parent word is " << crawler->parent->word << "." << endl;
//            if(crawler->leftChild != nullptr) cout << "Left Child word is " << crawler->leftChild->word << "." << endl;
//            if(crawler->rightChild != nullptr) cout << "Right Child word is " << crawler->rightChild->word << "." << endl;
//            return;
//        }
//        //put = on right side crawler.compare(word) <= 0
//    }
//}

//void BST::printInOrderBST() {
//    printBST(root);
//}

//void BST::printPreOrderBST() {
//    printPreOrderBST(root);
//}

//int BST::countBSTNodes() {
//    int count = 0;
//    countBSTNodes(root, count);
//    return count;
//}

//void BST::findAlphaRange(string word1, string word2) {
//    findAlphaRangeRecursive(root, word1, word2);
//}

//void BST::findAlphaRangeRecursive(BSTNode* node, string word1, std::string word2) {
//    if(node == nullptr) return;
//    int wordCheck1 = node->word.compare(word1);
//    int wordCheck2 = node->word.compare(word2);
//    if(wordCheck1 > 0) {
//        findAlphaRangeRecursive(node->leftChild, word1, word2);
//    }
//    if(wordCheck1 >= 0 && wordCheck2 <= 0) {
//        cout << node->word << " | " << node->count << endl;
//    }
//    if(wordCheck2 < 0) {
//        findAlphaRangeRecursive(node->rightChild, word1, word2);
//    }
//}

void BST::insertAt(Field* inField, BSTNode* parent, bool left) {

    auto newNode = new BSTNode(inField, parent, nullptr, nullptr);

    (left) ? parent->leftChild = newNode : parent->rightChild = newNode;

}

void BST::addNode(Field* inField) {

    if (root == nullptr) {
        //auto *newNode = new BSTNode(word, nullptr, nullptr, nullptr);
        root = new BSTNode(inField, nullptr, nullptr, nullptr);
        return;
    }

    auto crawler = root;

    while (crawler) {

        if (crawler->scoreDiff < inField->scoreDifference()) {   //left tree
            if (crawler->leftChild == nullptr) {
                insertAt(inField, crawler, true);
            } else {
                crawler = crawler->leftChild;
            }
        } else if (crawler->scoreDiff > inField->scoreDifference()) {    //right tree
            if (crawler->rightChild == nullptr) {
                insertAt(inField, crawler, false);
            } else {
                crawler = crawler->rightChild;
            }
        } else {    //up count
            return;
        }
        //put = on right side crawler.compare(word) <= 0
    }
}

//Field BST::returnBest1() {
//    auto crawler = root;
//
//    while(crawler->rightChild) {
//        crawler = crawler->rightChild;
//    }
//
//    return crawler->fieldState;
//}
//
//Field BST::returnBest2() {
//    auto crawler = root;
//
//    while(crawler->rightChild) {
//        crawler = crawler->rightChild;
//    }
//
//    return crawler->parent->fieldState;
//
//}
//Field BST::returnBest3() {
//    auto crawler = root;
//
//    while(crawler->rightChild) crawler = crawler->rightChild;
//    if(crawler->parent->leftChild) {
//        crawler = crawler->parent->leftChild;
//        while(crawler->rightChild)crawler = crawler->rightChild;
//        return crawler->fieldState;
//    }
//    return crawler->parent->parent->fieldState;
//}