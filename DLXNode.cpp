//
// Created by Andy on 2017/9/20.
//

//Basic DLX node
#include <iostream>
#include "DLXNode.h"

void DLXNode:: appendLeftNode(DLXNode* tempNode) {
        this->leftNode = tempNode;
        tempNode->rightNode = this;
}

void DLXNode:: appendRightNode(DLXNode* tempNode) {
    this->rightNode = tempNode;
    tempNode->leftNode = this;
}

void DLXNode:: appendUpNode(DLXNode* tempNode) {
    this->upNode = tempNode;
    tempNode->downNode = this;
}

void DLXNode:: appendDownNode(DLXNode* tempNode) {
    this->downNode = tempNode;
    tempNode->upNode = this;
}

