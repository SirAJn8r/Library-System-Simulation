1. The program works completely as specified I believe. Of course, the files
need to be properly formatted as specified, but that is part of the
specification. Future expansions such as new commands or book types would be
easy to implement, as the design is focused on giving as much power to the
implementations of Book and LibraryCommand as possible.

2. There are 3 hashtables in the program: one for command types, one for book
types, and one for book formats. All of them only use single letter capital
inputs. The command/book types will return an int corresponding to which
implementation of the LibraryCommand or Book interface should be used. The
book format hashtable returns a bool signalling if the format is acceptable.
The command types hashtable is in CommandFactory.h, the book types and book
format are found in BookFactory.h.

3.
libraryBuilder.cpp: createLibrary(book file) 
    Loops through the book file, passing lines one at a time into insertBook()
bookDatabase.cpp: insertBook(line)
    Reads the first character of the line into getID() to determine which
    BSTree to store the book in. If it is valid, it calls createBook().
    After creating a book, it stores it into its respective BSTree.
bookFactory.cpp: getID(type character)
    Returns the ID number of the type using a hashtable
bookFactory.cpp: createBook(line)
    Uses getID() as well to get the type. Optionally will read the format of
    the book as well. Then uses an internal array to call the book's
    implementation's version of create()
fiction.cpp: create(line)
periodical.cpp: create(line)
children.cpp: create(line)
    These implementations create a book of their own type and return it
    using the line for initialization

4.
library.cpp: processCommands(command file)
    Reads nothing, just calls createCommands(). Then after that is done,
    calls commandQueue.executeNext().
commandFactory.cpp: createCommands(command file)
    Reads first char to determine the type. If it is valid, it uses its
    internal array to call the LibraryCommand's implementation's version
    of create() using the rest of the line. Stores the commands into
    the commandQueue using enqueue().
checkoutBook.cpp: create(parameters)
returnBook.cpp: create(parameters)
displayLibrary.cpp: create(parameters)
displayPatronHistory.cpp: create(parameters)
    These implementations create a command of their own type and return it
    using the parameters for initialization
commandQueue.cpp: enqueue(command)
    Stores the command into the back of the queue
commandQueue.cpp: executeNext()
    Executes and deletes the frontmost command

5. The book format (Hardcover) found in the command file, I feel like I
cheated on. It is unclear exactly how it is supposed to work, so I assumed
that every library item will have the same set of possible formats in the
future. Implementing it this way allowed for 1 hashtable in total, but each
implementation of Book would need it's own hashtable if I didn't assume
this. The only other thing I feel guilty about is that I named everything
Book rather than something like LibItem, but it doesn't impact the code in
any way at all.

6. I'm most proud of the UML Class Diagram during the design phase. I put in
a lot of effort to it, most of it was made by me. I'm proud of how detailed
it was, how readable I believe it was, and how much thought I put into it.
Although it wasn't perfect and I don't understand UML Class Diagrams
perfectly yet, I think I did well on it.