#pragma once

extern const char *knownCategories[];

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

void printBook(const Book &book);
void copyBook(Book &dest, const Book &source);
