#include "BSTNode.h"

BSTNode::BSTNode()
{
    left = nullptr;
    right = nullptr;
    data = nullptr;
}

BSTNode::BSTNode(BSTData* data)
{
    left = nullptr;
    right = nullptr;
    this->data = data;
}

BSTNode::~BSTNode()
{
    if (left)
        delete left;
    left = nullptr;

    if (right)
        delete right;
    right = nullptr;

    if (data)
        delete data;
    data = nullptr;
}