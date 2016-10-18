#include "Sorter.h"
#include "library.h"
#include <cstring>

namespace {
    int compareBooksByAuthor(const Book &left, const Book &right){
        return strcmp(left.author, right.author);
    }

    int compareBooksByTitle(const Book &left, const Book &right){
        return strcmp(left.title, right.title);
    }

    int compareBooksByYear(const Book &left, const Book &right){
        return left.year - right.year;
    }

    int compareBooksByPrice(const Book &left, const Book &right){
        double dif = left.price - right.price;
        return (0 < dif) - (dif < 0);
    }

    int compareBooksByCategory(const Book &left, const Book &right){
        return left.category - right.category;
    }

    typedef int (*CompareFun)(const Book &left, const Book &right);
    CompareFun compareFuns[] = {
        compareBooksByAuthor,
        compareBooksByTitle,
        compareBooksByYear,
        compareBooksByPrice,
        compareBooksByCategory
    };
    static_assert(sizeof(compareFuns) / sizeof(*compareFuns) == SortFieldCount,
                  "Bad compare function count.");
}

void sort(Library &lib, SortField field)
{
    if (field >= SortFieldCount){
        fprintf(stderr, "Bad sort field got.\n");
        return;
    }

    CompareFun compare = compareFuns[field];
    for (int i = 0; i < lib.size - 1; ++i){
        for (int j = i + 1; j < lib.size; ++j){
            if (compare(lib.books[i], lib.books[j]) > 0){
                swap(lib.books[i], lib.books[j]);
            }
        }
    }
}
