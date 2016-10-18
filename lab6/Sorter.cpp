#include "Sorter.h"
#include "library.h"
#include <cstring>
#include <utility>

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
        return strcmp(left.category, right.category);
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

    void sort(const Book **books, int size, CompareFun compare){
        for (int i = 0; i < size - 1; ++i){
            for (int j = i + 1; j < size; ++j){
                if (compare(*books[i], *books[j]) > 0){
                    std::swap(books[i], books[j]);
                }
            }
        }
    }

    const Book **extractBookPointers(const Library &lib){
        const Book **result = new const Book *[lib.size];
        for (int i = 0; i < lib.size; ++i){
            result[i] = &lib.books[i];
        }
        return result;
    }
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

const Book **sorted(const Library &lib, SortField field)
{
    if (field >= SortFieldCount){
        fprintf(stderr, "Bad sort field got.\n");
        return nullptr;
    }

    CompareFun compare = compareFuns[field];
    const Book **result = extractBookPointers(lib);
    sort(result, lib.size, compare);
    return result;
}
