#pragma once

struct Book;
struct Library;

enum SortField{
    Author,
    Title,
    Year,
    Price,
    Category,
    SortFieldCount
};

void sort(Library &lib, SortField field);
const Book **sorted(const Library &lib, SortField field);
