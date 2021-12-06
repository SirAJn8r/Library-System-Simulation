#include "commandQueue.h"

CommandQueue::CommandQueue()
{
    front = nullptr;
    back = nullptr;
}

CommandQueue::~CommandQueue()
{
    if (front)
        delete front;

    front = nullptr;
    back = nullptr;
}

bool CommandQueue::enqueue(LibraryCommand* command)
{
    if (!command)
        return false;

    LinkedListNode* newNode = new LinkedListNode(command);

    if (!back) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }

    return true;
}

bool CommandQueue::executeNext()
{
    if (isEmpty())
        return false;

    front->execute();

    LinkedListNode* nextNode = front->next;
    front->next = nullptr;
    delete front;

    front = nextNode;
    return true;
}

bool CommandQueue::isEmpty() const
{
    return !front;
}