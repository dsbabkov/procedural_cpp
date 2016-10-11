#include "other.h"
#include <cstring>

///////////////////////////////////////////////////


void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) )
{
	int i;
	for(i=1; i<nNumber; i++)
		for(int j=nNumber-1; j>=i; j--)
		{
			char* pCurrent = pcFirst+j*size;
			char* pPrevious = pcFirst+(j-1)*size;
			if((*Compare)( pPrevious, pCurrent ) > 0)//требуется
												//переставить
				(*Swap)( pPrevious, pCurrent );
		}
}

double Sum(double first, double second) {
	return first + second;
}

double Sub(double first, double second) {
	return first - second;
}

double Mul(double first, double second) {
	return first * second;
}

double Div(double first, double second) {
	return first / second;
}

int indexOf(const char arr[], int size, char c) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == c) {
			return i;
		}
	}
	return -1;
}

void SwapInt(void *p1, void *p2) {
	int &val1 = *static_cast<int*>(p1);
	int &val2 = *static_cast<int*>(p2);

	int t = val1;
	val1 = val2;
	val2 = t;
}

int CmpInt(void *p1, void *p2) {
	int &val1 = *static_cast<int*>(p1);
	int &val2 = *static_cast<int*>(p2);

	return val1 - val2;
}

void SwapDouble(void *p1, void *p2) {
	double &val1 = *static_cast<double*>(p1);
	double &val2 = *static_cast<double*>(p2);

	double t = val1;
	val1 = val2;
	val2 = t;
}

int CmpDouble(void *p1, void *p2) {
	double &val1 = *static_cast<double*>(p1);
	double &val2 = *static_cast<double*>(p2);

	return val1 - val2;
}

void SwapStr(void *p1, void *p2) {
	char *&val1 = *static_cast<char**>(p1);
	char *&val2 = *static_cast<char**>(p2);

	char *t = val1;
	val1 = val2;
	val2 = t;

}

int CmpStr(void *p1, void *p2) {
	char *val1 = *static_cast<char**>(p1);
	char *val2 = *static_cast<char**>(p2);


	return strcmp(val1, val2);
}

const char* GetString1() {
	printf("GetString1:\n");
	char *res = new char[80];
	scanf("%s", res);
	return res;
}
const char* GetString2() {
	printf("GetString2:\n");
	char *res = new char[80];
	scanf("%s", res);
	return res;
}
