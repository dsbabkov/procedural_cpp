#include <iostream>

//Прототипы используемых в данном задании функций:
template <typename T>
void printArray(const T *arr, int n)
{
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << '\t';
	}
	std::cout << '\n';
}

void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) );
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);

double Sum(double first, double second);
double Sub(double first, double second);
double Mul(double first, double second);
double Div(double first, double second);

int indexOf(const char arr[], int size, char c);

void SwapInt(void *p1, void *p2);
int CmpInt(void *p1, void *p2);

void SwapDouble(void *p1, void *p2);
int CmpDouble(void *p1, void *p2);

void SwapStr(void *p1, void *p2);
int CmpStr(void *p1, void *p2);

const char* GetString1();
const char* GetString2();
