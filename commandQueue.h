/**
 * @file commandQueue.h
 * @author Alex Lambert
 *
 * Description:
 *   -Stores a queue of commands, allowing them to be added or executed
 *   -Allows detection if the queue is empty using isEmpty
 *
 * Assumptions/Implementation:
 *   -Uses a linked list implementation to store the queue
 *   -When this queue is deleted, all nodes and commands are deleted with it
 *   -Can handle executing invalid inputs or conditions smoothly
 */

#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include "libraryCommand.h"
#include "linkedListNode.h"
#include <iostream>

class CommandQueue {

public:
    //-----------------------------------------------------------------------
    /** CommandQueue()
     * Default Constructor
     *
     * Creates an empty CommandQueue
     * @pre None
     * @post front and back are set to nullptr
     */
    CommandQueue();

    //-----------------------------------------------------------------------
    /** ~CommandQueue()
     * Destructor Destructor
     *
     * Destroys the Command Queue and all commands within it
     * @pre None
     * @post Deallocates all memory for the Command Queue,
     * and all Linked List Nodes, and Library Command objects contained
     */
    virtual ~CommandQueue();

    //-----------------------------------------------------------------------
    /** enqueue()
     * Enqueue Command
     *
     * Inserts the given command into the back of the queue
     * @param command Command to be inserted into the queue
     * @pre command isn't a nullptr
     * @post Command is added to the back of the queue, if successful
     * @return Returns true if command was successfully enqueued
     */
    bool enqueue(LibraryCommand* command);

    //-----------------------------------------------------------------------
    /** executeNext()
     * Execute Next Command
     *
     * Executes and deletes the next command in the queue
     * @pre The Command Queue is not empty
     * @post Executes and deletes the frontmost command
     * @return Returns true if the command was successfully executed/removed
     */
    bool executeNext();

    //-----------------------------------------------------------------------
    /** isEmpty()
     * Check if Empty
     *
     * Returns if the Command Queue is currently empty
     * @pre None
     * @post No changes made.
     * @return Returns if the queue is empty
     */
    bool isEmpty() const;

private:
    // Points to the front/next command in the queue
    LinkedListNode* front;
    // Points to the back/last command in the queue
    LinkedListNode* back;
};

#endif