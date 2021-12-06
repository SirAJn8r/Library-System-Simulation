#include "libraryBuilder.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream bookFile("data4books.txt");
    if (!bookFile) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    ifstream patronFile("data4patrons.txt");
    if (!patronFile) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    LibraryBuilder* libBuilder = new LibraryBuilder();
    Library* library = libBuilder->createLibrary(bookFile, patronFile);

    ifstream commandFile("data4commands.txt");
    if (!commandFile) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    library->processCommands(commandFile);

    delete libBuilder;
    delete library;
    libBuilder = nullptr;
    library = nullptr;

    return 0;
}