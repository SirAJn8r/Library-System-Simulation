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

#ifndef LLNODE_H
#define LLNODE_H

#include "libraryCommand.h"

class LinkedListNode {
public:
    //-----------------------------------------------------------------------
    /** LinkedListNode()
    * Default Constructor
    *
    * Creates a Linked List Node with the given command
    * @param command The command to be executed when the queue is ready
    * @pre Command is not a nullptr
    * @post the command is stored and next is set to nullptr
    */
    LinkedListNode(LibraryCommand* command);

    //-----------------------------------------------------------------------
    /** ~LinkedListNode()
    * Default Destructor
    *
    * Destroys the Linked List Node
    * @pre None
    * @post Deallocates this node and its enclosed Library Command
    */
    virtual ~LinkedListNode();

    //-----------------------------------------------------------------------
    /** execute()
    * Execute Command
    *
    * Executes the enclosed Library Command
    * @pre None
    * @post The library command executed, this is unchanged
    */
    void execute();

    // Points to the next command in the queue
    LinkedListNode* next;

private:
    // Stores the command associated with this place in the queue
    LibraryCommand* command;
};

#endif