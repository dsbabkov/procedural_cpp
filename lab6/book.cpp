#include "book.h"
#include <cstdio>
#include <cstring>

const char *knownCategories[] = {
   "Adventure",
   "Science"
};

void inputBook(Book &book)
{
    printf("Input author: ");
    scanf("%79s", &book.author);

    printf("Input title: ");
    scanf("%249s", &book.title);

    while(true) {
        printf("Input year: ");
        scanf("%d", &book.year);
        if (book.year > 1234){
            break;
        }
        printf("Wrong year got.\n");
    };

    while(true) {
        printf("Input price: ");
        scanf("%lf", &book.price);
        if (book.price >= 0){
            break;
        }
        printf("Wrong price got.\n");
    };

    while(true) {
        printf("Input category: ");
        scanf("%9s", &book.category);
        if (isKnownCategory(book.category)){
            break;
        }
        printf("Unknown category.\n");
    }
}

bool isKnownCategory(char category[])
{
    for (int i = 0; i < sizeof(knownCategories) / sizeof(*knownCategories); ++i){
        if (!strcmp(knownCategories[i], category)){
            return true;
        }
    }
    return false;
}

void printBook(const Book &book, const char *format, FILE *stream)
{
    fprintf(stream, format, book.author, book.title, book.year, book.price, book.category);
}

void copyBook(Book &dest, const Book &source)
{
    dest.price = source.price;
    dest.year = source.year;

    strcpy(dest.author, source.author);
    strcpy(dest.title, source.author);
    strcpy(dest.category, source.category);
}
