#include "library.h"
#include <cstdio>
#include <cstdlib>

static const LibraryFunctionCommand commandMap[] = {
	{ 'p', printLibrary, "Print all books" },
	{ 'a', addBook, "Add new book" },
	{ 'r', removeBook, "Remove book by id" },
	{ 's', writeToFile, "Save library to file" },
	{ 'o', readFromFile, "Open library file" },
	{ 'm', help, "Show this message" },
	{ 'q', quit, "Quit" }
};

static const int commandMapSize = sizeof(commandMap) / sizeof(*commandMap);

void printLibrary(Library &lib) {
	for (int i = 0; i < lib.size; ++i) {
		printf("%d\n", i + 1);
		printBook(lib.books[i]);
	}
}

void addBook(Library &lib) {
	reserve(lib, lib.size + 1);

	inputBook(lib.books[lib.size++]);
}

void removeBook(Library &lib) {
	printf("Input book id: ");
	int bookId;
	scanf("%d", &bookId);

	--bookId;

	if (bookId >= lib.size || bookId < 0) {
		fprintf(stderr, "Invalid book id got\n");
		return;
	}

	copyBooks(lib.books + bookId, lib.books + bookId + 1, lib.size - 1 - bookId);
	--lib.size;
}

void writeToFile(Library &lib) {
	char fileName[255];
	printf("Input file name: ");
	scanf("%254s", fileName);

	FILE *file = fopen(fileName, "w");
	if (!file) {
		fprintf(stderr, "Unable to open file for write.\n");
		return;
	}

	fprintf(file, "%d\n", lib.size);
	
	for (int i = 0; i < lib.size; ++i) {
		printBook(lib.books[i], bookFileFormat, file);
		fprintf(file, "\n");
	}

    fclose(file);
}

void readFromFile(Library &lib) {
	char fileName[255];
	printf("Input file name: ");
	scanf("%254s", fileName);

	FILE *file = fopen(fileName, "r");
	if (!file) {
		fprintf(stderr, "Unable to open file for read.\n");
		return;
	}

	int bookCount;
	fscanf(file, "%d", &bookCount);

	reserve(lib, bookCount);
	lib.size = bookCount;

	for (int i = 0; i < lib.size; ++i) {
		Book &book = lib.books[i];
		fscanf(file, bookFileFormat, &book.author, &book.title, &book.year, &book.price, &book.category);
	}

    fclose(file);
}

void help(Library &) {
	for (int i = 0; i < commandMapSize; ++i) {
		const LibraryFunctionCommand &command = commandMap[i];

		printf("%c\t%s\n\n", command.letter, command.description);
	}
	printf("\n\n");

}

void quit(Library &) {
	exit(0);
}

void copyBooks(Book *dest, const Book *source, int count) {
	for (int i = 0; i < count; ++i) {
		dest[i] = source[i];
	}
}

void deleteLibrary(Library &lib) {
	delete[] lib.books;
	lib.size = lib.capacity = 0;
}

LibraryFunction functionForCommand(char letter) {
	for (int i = 0; i < commandMapSize; ++i) {
		if (commandMap[i].letter == letter) {
			return commandMap[i].function;
		}
	}

	return nullptr;
}

void reserve(Library &lib, int capacity) {
	if (capacity <= lib.capacity) {
		return;
	}

	Book *tempBooks = new Book[capacity];
	copyBooks(tempBooks, lib.books, lib.size);

	delete[] lib.books;
	lib.books = tempBooks;
	lib.capacity = capacity;
}
