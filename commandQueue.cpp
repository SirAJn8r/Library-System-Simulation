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

#include "commandQueue.h"

using namespace std;

//---------------------------------------------------------------------------
/** CommandQueue()
 * Default Constructor
 *
 * Creates an empty CommandQueue
 * @pre None
 * @post front and back are set to nullptr
 */
CommandQueue::CommandQueue()
{
    front = nullptr;
    back = nullptr;
}

//---------------------------------------------------------------------------
/** ~CommandQueue()
 * Destructor Destructor
 *
 * Destroys the Command Queue and all commands within it
 * @pre None
 * @post Deallocates all memory for the Command Queue,
 * and all Linked List Nodes, and Library Command objects contained
 */
CommandQueue::~CommandQueue()
{
    if (front)
        delete front;

    front = nullptr;
    back = nullptr;
}

//---------------------------------------------------------------------------
/** enqueue()
 * Enqueue Command
 *
 * Inserts the given command into the back of the queue
 * @param command Command to be inserted into the queue
 * @pre command isn't a nullptr
 * @post Command is added to the back of the queue, if successful
 * @return Returns true if command was successfully enqueued
 */
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

//---------------------------------------------------------------------------
/** executeNext()
 * Execute Next Command
 *
 * Executes and deletes the next command in the queue
 * @pre The Command Queue is not empty
 * @post Executes and deletes the frontmost command
 * @return Returns true if the command was successfully executed/removed
 */
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

//---------------------------------------------------------------------------
/** isEmpty()
 * Check if Empty
 *
 * Returns if the Command Queue is currently empty
 * @pre None
 * @post No changes made.
 * @return Returns if the queue is empty
 */
bool CommandQueue::isEmpty() const
{
    return !front;
}