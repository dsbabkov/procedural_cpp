/*************************************************************
    Практическое занятие №3. Встроенные массивы.
                            Динамическое выделение памяти.
                            Простейшие алгоритмы сортировки и поиска.
                            Сложные указатели.
                            Ссылки.
*************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>

#define	  stop {int tmp = 0; tmp += 2;} //__asm (nop)

template <typename T>
void printArray(const T arr, size_t N, size_t M = 1) {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            std::cout << arr[i * M + j] << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    srand(time(0));
    goto task7;
///////////////////////////////////////////////////////////////
//			Встроенные массивы                               //
///////////////////////////////////////////////////////////////
    {
        //Задание 1. Объявите трехмерный N*M*K массив и сформируйте указанные
        //значения элементов следующим образом:
        const size_t N = 3;
        const size_t M = 4;
        const size_t K = 5;

        //а) проинициализируйте массив при объявлении
        int array1A[N][M][K] = {};
        //б)* объявите неинициализированный массив и присвойте значения элементам
        //	с помощью кода
        //					 |--------|
        //				   / |3  3  3 |
        //    			 |---------|3 |
        //			   / | 2  2  2 |3 |
        //			  |---------|2 |__|
        //			  | 1  1  1 |2 | /
        //			  | 1  1  1 |__|
        //			  | 1  1  1 | /
        //			  |_________|
        //Средствами отладчика проверьте правильность Вашего решения.
        int array1B[N][M][K];
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                for (size_t k = 0; k < K; ++k) {
                    array1B[i][j][k] = i + 1;
                }
            }
        }

        //в) найдите сумму элементов массива
        const size_t arrayElementCount = N * M * K;
        int sum = 0;
        for (int *it = **array1B, *end = it + arrayElementCount; it != end; ++it) {
            sum += *it;
        }

        stop;

        //г) проинициализируйте массив при определении:
        //					 |--------|
        //				   / |3  0  0 |
        //    			 |---------|0 |
        //			   / | 2  0  0 |0 |
        //			  |---------|0 |__|
        //			  | 1  0  0 |0 | /
        //			  | 0  0  0 |__|
        //			  | 0  0  0 | /
        //			  |_________|

        int array1D[3][3][3] = {
            {{1}},
            {{2}},
            {{3}}
        };

        stop;

        //д)* Инициализация массивов строковыми литералами:
        //Объявите и проинициализируйте строковыми литералами два массива:
        //двухмерный массив и массив указателей. Поясните разницу в использовании
        //элементов таких массивов.
        char strings1[][4] = { "foo", "bar" };
        const char *strings2[] = { "foo", "bar" };
        strings1[0][0] = 0;
        // strings2[0][0] = 0; // protected
        stop;
    }


///////////////////////////////////////////////////////////////
//			Динамическое выделение памяти                    //
///////////////////////////////////////////////////////////////
    {
        //Задание2. Создайте динамический двухмерный массив с размерностями,
        //вычисляемыми в процессе выполнения программы - N*M.
        //Задайте значения элементов помощью генератора случайных чисел.
        //Найдите  сумму элементов.
        //Подсказка 1: для генерации случайных чисел используйте функцию
        //стандартной библиотеки - rand() (<cstdlib>)
        //Подсказка 2: На самом деле те значения, которые создаются генератором случайных
        //чисел являются «псевдослучайными», то есть при двух последовательных запусках
        //приложения Вы получаете две одинаковые последовательности значений.
        //Для того чтобы генерируемые "случайные" значения были разными при каждом
        //запуске приложения используйте функции стандартной библиотеки srand() (<cstdlib>)
        //и time() (<ctime>).
        //Функция srand() осуществляет «привязку» начала генерации к указанному в качестве параметра значению.
        //Функция time() задает эту точку отсчета, считывая текущее время

        size_t rowCount = rand() % 10 + 1;
        size_t columnCount = rand() % 10 + 1;

        size_t elementCount = rowCount * columnCount;

        int *array2 = new int[elementCount];
        for (int *it = array2, *end = it + elementCount; it != end; ++it) {
            *it = rand() % 10;
        }

        std::cout << "Unsorted array:\n";
        printArray(array2, rowCount, columnCount);

        //Задание2а. В сформированном массиве отсортируйте каждую строку по
        //убыванию значений. Используйте сортировку "выбором"
        for (int *rowIt = array2, *end = array2 + elementCount; rowIt != end; rowIt += columnCount) {
            for (int *elementIt = rowIt, *end = elementIt + columnCount; elementIt != end; ++elementIt) {
                int *minElement = elementIt;
                for (int *elementIt2 = elementIt; elementIt2 != end; ++elementIt2) {
                    if (*elementIt2 < *minElement) {
                        minElement = elementIt2;
                    }
                }
                int tmp = *minElement;
                *minElement = *elementIt;
                *elementIt = tmp;
            }
        }

        std::cout << "Sorted array:\n";
        printArray(array2, rowCount, columnCount);

        stop;

        //Задание2б. Объявите одномерный массив размерностью N.
        //Сформируйте значение i-ого элемента одномерного массива
        //равным среднему значению элементов i-ой строки
        //двухмерного массива
        double *arrayOfAvg = new double[rowCount];

        const int *rowIt = array2;
        for (double *it = arrayOfAvg, *end = it + rowCount;
                it != end; ++it, rowIt += columnCount) {
            int rowSum = 0;
            for (const int *elementIt = rowIt, *end = elementIt + columnCount; elementIt != end; ++elementIt) {
                rowSum += *elementIt;
            }
            *it = static_cast<double>(rowSum) / columnCount;
        }

        std::cout << "Average values:\n";
        printArray(arrayOfAvg, rowCount);
        //Подсказка - не забудьте освободить память

        delete[] array2;
        delete[] arrayOfAvg;
    }
    stop;

    {
        /////////////////////////////////////////////////////////////////////
        //Задание 3. а) Напишите фрагмент кода, который вводит NN целых чисел с помощью
        //потока ввода в объявленный Вами встроенный одномерный массив, каждый раз
        //упорядочивая полученное значение по возрастанию
        const size_t NN = 5;
        {

            std::cout << "Input " << NN << " number(s) to be sorted: ";
            int array3[NN] = {};
            std::cin >> array3[0];

            for (size_t i = 1; i < NN; ++i) {
                stop;
                int insertableValue = 0;
                std::cin >> insertableValue;
                for (size_t j = 0; j <= i; ++j) {
                    if (insertableValue < array3[j]) {
                        int tmp = insertableValue;
                        insertableValue = array3[j];
                        array3[j] = tmp;
                    }
                }
                array3[i] = insertableValue;

                std::cout << "Debug print:\n";
                printArray(array3, NN);
            }
        }
        stop;


        //б) Простой поиск.
        //Модифицируйте предыдущее задание следующим образом:очередное значение
        //вводится в массив только при условии, что там еще такого нет (то есть
        //дубли игнорируются
        {

            std::cout << "Input unique " << NN << " number(s) to be sorted: ";
            int array3[NN] = {};
            std::cin >> array3[0];

            for (size_t i = 1; i < NN; ++i) {
                stop;
                int insertableValue = 0;
                std::cin >> insertableValue;

                bool arrayContainsValue = false;
                for (size_t j = 0; j < i; ++j) {
                    arrayContainsValue = (insertableValue == array3[j]);
                    if (arrayContainsValue) {
                        break; // --i; goto newIteration;
                    }
                }
                if (arrayContainsValue) {
                    --i;
                    continue;
                }


                for (size_t j = 0; j < i; ++j) {
                    if (insertableValue < array3[j]) {
                        int tmp = insertableValue;
                        insertableValue = array3[j];
                        array3[j] = tmp;
                    }
                }
                array3[i] = insertableValue;
            }
        }
        stop;
    }

    {
        task4:
        ///////////////////////////////////////////////////////////////////////////
        //Задание 4*.С помощью данной заготовки напишите программу,
        //которая:
        //вводит строки с клавиатуры с помощью cin>>...
        //в объявленный Вами двухмерный встроенный массив 5*80 элементов типа char;
        //признаком конца ввода является символ * (то есть строка - "*") или
        //заполнение массива (больше свободных строк нет);
        //сортировка строк в алфавитном порядке. Пояснение: крайне
        //не рекомендуется для сортировки сложных объектов физически
        //перемещать их в памяти. Намного эффективнее завести массив
        //указателей на соответствующие строки и перемещать только
        //указатели.

        //Подсказка: для лексиграфического сравнения строк пользуйтесь
        //функцией стандартной библиотеки strcmp(...), заголовочный файл <string>.


        //Определите необходимые значения как константы
        const char STOP_STRING[] = "*";	//признак "прекратить ввод"
        const size_t M = 80;	//максимальный размер одной строки
        const size_t N = 10;	//максимальное количество строк в массиве



        //Объявите двухмерный массив с именем cBuffer типа char и
        // размерностью N*M
        char cBuffer[M][N] = {};

        //Объявите массив (с именем cPointers) указателей на строки
        //размерностью N
        char *cPointers[N];

        //Цикл ввода строк:
        //а) выведите приглашение для ввода
        std::cout << "Input less or equal " << N << " strings.\n"
            "Tips: maximum length of string is " << M - 1<< ";\n"
            "      end of input \"*\" string.\n";

        //б) пока не введена строка STOP_STRING или не заполнен весь массив
        size_t stringCount = 0;
        while (stringCount != N){
            //ввод строки в массив cBuffer:
            std::cin >> cBuffer[stringCount];

            //если введена строка - признак окончания, то выйти из цикла
            if (!strcmp(cBuffer[stringCount], STOP_STRING)) {
                break;
            }
            //Присвойте элементу массива cPointers с индексом nIndex
            //указатель на строку с номером nIndex в массиве cBuffer
            cPointers[stringCount] = cBuffer[stringCount];
            ++stringCount;
        }


        //Выдать диагностику о том, что прием строк завершен.
        std::cout << "End of input\n";


        //Теперь сортируем строки:
        for (size_t i = 0; i < stringCount - 1; ++i) {
            for (size_t j = i + 1; j < stringCount; ++j) {
                if (strcmp(cPointers[i], cPointers[j]) > 0) {
                    char *tmp = cPointers[i];
                    cPointers[i] = cPointers[j];
                    cPointers[j] = tmp;
                }
            }

            std::cout << "Iteration debug:\n";
            for (size_t j = 0; j < stringCount; ++j) {
                std::cout << cPointers[j] << (i == j ? '*' : '\0') << '\n';
            }
            stop;
        }
        //Цикл сортировки строк по методу "всплывающего пузырька" в
        //порядке возрастания. На каждой итерации - промежуточная печать
        //отсортированных строк
        stop;
        std::cout << "Sorted strings:\n";
        for (size_t j = 0; j < stringCount; ++j) {
            std::cout << cPointers[j] << '\n';
        }

        stop;
    }
    {
        task5:
        //Задание 5*. Реализуйте задание №4, используя не встроенные,
        //а динамические массивы (массив?). Так как строки могут быть разной длины,
        //эффективным решением было бы отводить под каждую строку ровно столько байтов,
        //сколько требуется для ее хранения.
        //При этом необходимые параметры (количество строк
        // сформируйте с помощью потока ввода
        size_t stringCount = 0;
        std::cout << "Input string count: ";
        std::cin >> stringCount;

        char **strings = new char *[stringCount];

        const size_t M = 80;
        char buffer[M];


        //Цикл ввода строк:
        const char STOP_STRING[] = "*";
        for (size_t i = 0; i < stringCount; ++i) {
            std::cin >> buffer;
            if (!strcmp(buffer, STOP_STRING)) {
                stringCount = i;
                delete strings[i];
                break;
            }

            strings[i] = new char[strlen(buffer) + 1];
            strcpy(strings[i], buffer);
        }
        std::cout << "End of input\n";


        //Цикл сортировки строк по методу "всплывающего пузырька" в
        //порядке возрастания кода первого символа

        for (size_t i = 0; i < stringCount - 1; ++i){
            for (size_t j = i + 1; j < stringCount; ++j){
                std::cout << "Comparing " << strings[i] << " and " << strings[j] << "...\n";
                if (strcmp(strings[i], strings[j]) > 0){
                    char *tmp = strings[i];
                    strings[i] = strings[j];
                    strings[j] = tmp;
                }

                stop;
            }
            std::cout << "Iteration debug:\n";
            for (size_t j = 0; j < stringCount; ++j) {
                std::cout << strings[j] << (i == j ? '*' : '\0') << '\n';
            }
        }


        std::cout << "Sorted strings:\n";
        for (size_t j = 0; j < stringCount; ++j) {
            std::cout << strings[j] << '\n';
        }

        //Освобождение занятой памяти:


        for (size_t i = 0; i < stringCount; ++i){
            delete[] strings[i];
        }
        delete[] strings;
    }

    {
        //Задание 6*. Объявление и использование указателей на многомерные
        // массивы. Проинициализируйте трехмерный массив
        //double dArray[4][3][3] так, как показано на рисунке и напишите фрагмент
        //кода, который меняет местами значения элементов четных
        //и нечетных слоев:
        //	было:			     |--------|
        //  				   / |4  4  4 |
        //					 |--------|	4 |
        //				   / |3  3  3 |	4 |
        //    			 |---------|3 |   |
        //			   / | 2  2  2 |3 | /
        //			  |---------|2 |__|
        //			  | 1  1  1 |2 | /
        //			  | 1  1  1 |__|
        //			  | 1  1  1 | /
        //			  |_________|

        const int N = 4;
        const int M = 3;
        const int K = 3;
        double dArray [N][M][K] = {
            {
                {1.0, 1.0, 1.0},
                {1.0, 1.0, 1.0},
                {1.0, 1.0, 1.0}
            },

            {
                {2.0, 2.0, 2.0},
                {2.0, 2.0, 2.0},
                {2.0, 2.0, 2.0}
            },

            {
                {3.0, 3.0, 3.0},
                {3.0, 3.0, 3.0},
                {3.0, 3.0, 3.0},
            },

            {
                {4.0, 4.0, 4.0},
                {4.0, 4.0, 4.0},
                {4.0, 4.0, 4.0}
            }
        };

        //	стало:			     |--------|
        //  				   / |3  3  3 |
        //					 |--------|	3 |
        //				   / |4  4  4 |	3 |
        //    			 |---------|4 |   |
        //			   / | 1  1  1 |4 | /
        //			  |---------|1 |__|
        //			  | 2  2  2 |1 | /
        //			  | 2  2  2 |__|
        //			  | 2  2  2 | /
        //			  |_________|

        for(int i = 0; i < M * K; ++i)
        {
        //Замечание: НЕ НУЖНО МОДИФИЦИРОВАТЬ ВЫРАЖЕНИЯ СПРАВА ОТ ЗНАКА РАВЕНСТВА!!!
//            ... =  dArray[i];
//            ... =  dArray[i+1];
            //переставляем местами элементы i-того и i+1-ого слоев


        }
    }

    task7:
    {
        ///////////////////////////////////////////////////////////////////////////
        //Задание 7а. Объявите двухмерный встроенный массив элементов типа char.
        //Сформируйте значения элементов массива с помощью генератора случайных
        //чисел таким образом, чтобы в массиве были только символы '*' и '_'

        {
            const int N = 5;
            const int M = 6;

            char arr[N][M + 1] = {};

            for (int i = 0; i < N; ++i){
                for (int j = 0; j < M; ++j){
                    arr[i][j] = (rand() & 1) ? '*' : '_';
                }
            }

            //В каждой строке "сдвиньте звездочки" в начало строки, например:
            //было - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
            //стало: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
            //и распечатайте массив по строкам - "постройте распределение"

            std::cout << "Initial array:\n";
            printArray(arr, N);

            for (int i = 0; i < N; ++i){
                int starCount = 0;
                for (int j = 0; j < M; ++j){
                    if (arr[i][j] == '*'){
                        ++starCount;
                    }
                }

                for (int j = 0; j < starCount; ++j){
                    arr[i][j] = '*';
                }
                for (int j = starCount; j < M; ++j){
                    arr[i][j] = '_';
                }
            }

            std::cout << "Offseted array:\n";
            printArray(arr, N);

            char *pointers[N] = {};
            for (int i = 0; i < N; ++i){
                pointers[i] = arr[i];
            }

            for (int i = 0; i < N; ++i){
                for (int j = 0; j < M; ++j){
                    if (strcmp(pointers[i], pointers[j]) > 0){
                        char *tmp = pointers[i];
                        pointers[i] = pointers[j];
                        pointers[j] = tmp;
                    }
                }
            }


            std::cout << "Sorted array:\n";
            printArray(pointers, N);
        }



        // 7б. Модифицируйте предыдущее задание следующим способом:
        //После заполнения массива с помощью генератора случайных чисел
        //"сдвиньте" звездочки по столбцам вниз и распечатайте полученное
        //"распределение"
        {
            const int N = 5;
            const int M = 6;

            char arr[N][M + 1] = {};

            for (int i = 0; i < N; ++i){
                for (int j = 0; j < M; ++j){
                    arr[i][j] = (rand() & 1) ? '*' : '_';
                }
            }

            std::cout << "Initial array:\n";
            printArray(arr, N);

            for (int column = 0; column < M; ++column){
                int starCount = 0;
                for (int row = 0; row < N; ++row){
                    if (arr[row][column] == '*'){
                        ++starCount;
                    }
                }

                for (int j = 0; j < starCount; ++j){
                    arr[N - 1 - j][column] = '*';
                }
                for (int j = 0; j < N - starCount; ++j){
                    arr[j][column] = '_';
                }
            }

            std::cout << "Offseted array:\n";
            printArray(arr, N);
        }

    }
    return 0;
}
