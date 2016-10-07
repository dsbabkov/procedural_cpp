#include "other.h"

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
