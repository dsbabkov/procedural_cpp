#pragma once

struct Book;

typedef Book *&BookArrayRef;

typedef void (*BookFunction)(BookArrayRef book, int &bookCount);

struct BookFunctionCommand{
    const char command;
    BookFunction function;
    const char *description;
};

extern const BookFunctionCommand commandMap[];

void printLibrary(BookArrayRef books, int &bookCount);
void addBook(BookArrayRef books, int &bookCount);
void removeBook(BookArrayRef books, int &bookCount);
void writeToFile(BookArrayRef books, int &bookCount);
void readFromFile(BookArrayRef books, int &bookCount);
void help(BookArrayRef, int &);
void quit(BookArrayRef, int &);

