#include "other.h"
#include <cstring>
#include <iostream>
#include <cstdarg>

double globalValue = 3;
double &ref = globalValue;

///////////////////////////////////////////////////



//Подсказка-заготовка для задания 5а
//Без использования макросов
/*
void VarArgs(int arg1,...)
{
	int number = 0;	//счетчик элементов
	//Объявите указатель на int и инициализируйте его адресом
	//первого аргумента
	
	//Пока не достигнут конец списка:
	// а) печать значения очередного аргумента
	// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
	// в) увеличить счетчик элементов




	//Печать числа элементов

}
*/



void IncByPointer(int *val)
{
    ++(*val);
}

void IncByReference(int &val)
{
    ++val;
}

int IncByValue(int val)
{
    return ++val;
}

void Swap(int *left, int *right)
{
    int tmp = *left;
    *left = *right;
    *right = tmp;

}

void Swap(int &left, int &right)
{
    int tmp = left;
    left = right;
    right = tmp;
}

int Min(int **array, int rows, int cols)
{
    int result = array[0][0];
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            if (array[i][j] < result){
                result = array[i][j];
            }
        }
    }
    return result;
}

int Min(int array[][M], int rows)
{
    return Min(&array[0][0], rows * M);
}

int Min(int *array, int elementCount)
{
    int result = *array;

    for (int *p = array, *end = p + elementCount * M; p != end; ++p){
        if (*p < result){
            result = *p;
        }
    }

    return result;
}

int MyStrCmp(const char *left, const char *right)
{
    if (!left || !right || right == left){
        return 0;
    }

    while (*left == *right && *left && *right){
        ++left;
        ++right;
    }
    return *left - *right;
}

int DayOfYear(int day, int month, const int (&dayTab)[12])
{
    for (int i = 0; i < month - 1; ++i){
        day += dayTab[i];
    }
    return day;
}

int DayOfMonth(int day, int &month, const int (&dayTab)[12])
{
    month = 0;
    while (day > dayTab[month] && month < 12){
        day -= dayTab[month++];
    }
    ++month;

    return day;
}

void printArray(const int *arr, int n)
{
    for (int i = 0; i < n; ++i){
        std::cout << arr[i] << '\t';
    }
    std::cout << '\n';
}

int *addUnique(int *arr, int &n, int value)
{
    if (valueExists(arr, n, value)){
        std::cerr << "Value allready exists\n";
        return arr;
    }

    int *result = new int[n + 1];

    memcpy(result, arr, sizeof(*arr) * n);

    result[n++] = value;
    delete[] arr;

    return result;
}

bool valueExists(const int *arr, int n, int value)
{
    for (int i = 0; i < n; ++i){
        if (arr[i] == value){
            return true;
        }
    }

    return false;
}

int naturalSum(int n)
{
    return n == 1 ?
                1 :
                n + naturalSum(n - 1);
}

void VarArgs(int val1, ...)
{
    std::cout << val1;

    if (val1){
        char *p = reinterpret_cast<char *>(&val1 + 1);
        while( (val1 = *reinterpret_cast<int *>(p)) ){
            std::cout << ' ' << val1;
            p += sizeof(p);
        };

        std::cout << '\n';
    }
}

void VarArgsM(int val1, ...)
{
    std::cout << val1;

    if (val1){
        va_list p;
        va_start(p, val1);

        while (val1 = va_arg(p, int)){
            std::cout << ' ' << val1;
        }
    }

    std::cout << '\n';
}

int *MyMin(int *arr, int n)
{
    int *min = arr;

    for (int i = 0; i < n; ++i){
        if (*min > arr[i]){
            std::swap(*min, arr[i]);
        }
    }

    return min;
}
