#pragma once
#include "book.h"

struct Library
{
	Book *books;
	int size;
	int capacity;
};

typedef void(*LibraryFunction)(Library &);

struct LibraryFunctionCommand {
	const char letter;
	LibraryFunction function;
	const char *description;
};

void printLibrary(Library &lib);
void printSortedLibrary(Library &lib);
void addBook(Library &lib);
void removeBook(Library &lib);
void writeToFile(Library &lib);
void readFromFile(Library &lib);
void sort(Library &);
void help(Library &);
void quit(Library &);

void copyBooks(Book *dest, const Book *source, int size);
void deleteLibrary(Library &lib);
LibraryFunction functionForCommand(char letter);
void reserve(Library &lib, int capacity);
