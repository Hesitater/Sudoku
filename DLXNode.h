//
// Created by Andy on 2017/9/22.
//

#pragma once

#include <iostream>

//DLXNode, the one with horizontal and vertical loop links
class DLXNode {
public:
    DLXNode* leftNode = NULL;
    DLXNode* rightNode = NULL;
    DLXNode* upNode = NULL;
    DLXNode* downNode = NULL;
    int columnIndex = -1;

    DLXNode(): leftNode(this), rightNode(this), upNode(this), downNode(this) {}

    void appendLeftNode(DLXNode* tempNode);

    void appendRightNode(DLXNode* tempNode);

    void appendUpNode(DLXNode* tempNode);

    void appendDownNode(DLXNode* tempNode);
};

//Column head node
class ColumnHead: public DLXNode {
public:
    int numberOfOne = 0;

    ColumnHead(int columnIndex) {
        this->columnIndex = columnIndex;
    }
};

//Common node inside lists
class CommonNode: public DLXNode {
public:
    int rowIndex;
    ColumnHead* columnHead = NULL;

    CommonNode(int rowIndex, ColumnHead *columnHead) : rowIndex(rowIndex), columnHead(columnHead) {}
};
