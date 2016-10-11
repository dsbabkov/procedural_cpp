
//Прототипы используемых в данном задании функций:

const int N = 4;
const int M = 5;

int IncByValue(int val);
void IncByPointer(int *val);
void IncByReference(int &val);

void Swap(int *left, int *right);
void Swap(int &left, int &right);

int Min (int **array, int rows, int cols);
int Min (int array[][M], int rows);
int Min (int *array, int elementCount);

int MyStrCmp(const char *left, const char *right);

int DayOfYear(int day, int month, const int (&dayTab)[12]);
int DayOfMonth(int day, int &month, const int (&dayTab)[12]);

void printArray(const int *arr, int n);
int *addUnique(int *arr, int& n, int value);
bool valueExists(const int *arr, int n, int value);

int naturalSum (int n);

void VarArgs(int val1, ...);
void VarArgsM(int val1, ...);
