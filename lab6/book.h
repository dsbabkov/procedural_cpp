#pragma once
#include <cstdio>

extern const char *knownCategories[];

const char bookFileFormat[] = /*Author*/ "%s"
							/*Title*/ " %s"
							/*Year*/ " %d"
							/*Price*/ " %lf"
							/*Category*/ " %s";
const char bookStdoutFormat[] = "Author: %s\n"
								"Title: %s\n"
								"Year: %d\n"
								"Price: %g\n"
								"Category: %s\n";

struct Book
{
	char author[80];
	char title[250];
	int year;
	double price;
	char category[10];
};

void inputBook(Book &book);
bool isKnownCategory(char category[]);

void printBook(const Book &book, const char *format = bookStdoutFormat, FILE *stream = stdout);
void copyBook(Book &dest, const Book &source);

void swap(Book &left, Book &right);

