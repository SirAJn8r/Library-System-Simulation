/**
 * @file linkedListNode.h
 * @author Alex Lambert
 *
 * Description:
 *   -Stores a command and the next link in the list
 *   -Allows for the command to be executed, but never changed
 *
 * Assumptions/Implementation:
 *   -A linked list node must not exist without a command
 *   -The command will be deleted when this node is deleted
 */

#include "linkedListNode.h"

//---------------------------------------------------------------------------
/** LinkedListNode()
 * Default Constructor
 *
 * Creates a Linked List Node with the given command
 * @param command The command to be executed when the queue is ready
 * @pre Command is not a nullptr
 * @post the command is stored and next is set to nullptr
 */
LinkedListNode::LinkedListNode(LibraryCommand* command)
{
    this->command = command;
    next = nullptr;
}

//---------------------------------------------------------------------------
/** ~LinkedListNode()
 * Default Destructor
 *
 * Destroys the Linked List Node
 * @pre None
 * @post Deallocates this node and its enclosed Library Command
 */
LinkedListNode::~LinkedListNode()
{
    delete command;
    command = nullptr;

    if (next) {
        delete next;
        next = nullptr;
    }
}

//---------------------------------------------------------------------------
/** execute()
 * Execute Command
 *
 * Executes the enclosed Library Command
 * @pre None
 * @post The library command executed, this is unchanged
 */
void LinkedListNode::execute()
{
    command->execute();
}