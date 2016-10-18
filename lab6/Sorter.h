#pragma once

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
