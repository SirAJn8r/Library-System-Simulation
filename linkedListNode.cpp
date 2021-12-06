#include "linkedListNode.h"

LinkedListNode::LinkedListNode(LibraryCommand* command)
{
    this->command = command;
    next = nullptr;
}

LinkedListNode::~LinkedListNode()
{
    delete command;
    command = nullptr;

    if (next) {
        delete next;
        next = nullptr;
    }
}

void LinkedListNode::execute()
{
    command->execute();
}