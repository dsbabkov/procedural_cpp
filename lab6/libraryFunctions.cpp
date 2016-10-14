#include "book.h"
#include "libraryFunctions.h"
#include <cstring>
#include <cstdio>

const BookFunctionCommand commandMap[] = {
    {'p', printLibrary, "Print all books"}
};

void printLibrary(BookArrayRef books, int &bookCount)
{
    for (int i = 0; i < bookCount; ++i){
        printf("%d\n", i + 1);
        printBook(books[i]);
    }
}

void addBook(BookArrayRef books, int &bookCount)
{
    Book *newBooks = new Book[bookCount + 1];

    for (int i = 0; i < bookCount; ++i){
        copyBook(newBooks[i], books[i]);
    }
    delete[] books;
    books = newBooks;

    inputBook(books[bookCount++]);
}

void removeBook(BookArrayRef books, int &bookCount)
{
    printf("Input book id: ");
    int bookId;
    scanf("%d", &bookId);
}

void writeToFile(BookArrayRef books, int &bookCount)
{

}

void readFromFile(BookArrayRef books, int &bookCount)
{

}

void help(BookArrayRef, int &)
{

}

void quit(BookArrayRef, int &)
{

}
