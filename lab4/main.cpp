
/*************************************************************
	Практическое занятие №3. Функции.
	Объявление, определение, вызов.
	Передача параметров. Возвращение значения.
	Указатели на функции
*************************************************************/
#include <iostream>
#include <ctime>
#include <random>
//#include <tchar.h>
//#include <cstdio>
//#include <cstdarg>
#include "other.h"


#define	  stop {int temp = 1; temp += 2;}

int main()
{
    srand(time(0));
    {
        /////////////////////////////////////////////////////////////////////////////
        // Задание 1. Ссылки.
        //Объявите ссылку на тип double. Посредством ссылки измените значение

        double value = 123;
        double &valueRef = value;
        valueRef = 321;


        //Раскомментируйте  следующую строчку. Что следует сделать, чтобы
        //linker не выдавал ошибки при создании exe-файла. Подсказка: ref - это
        //внешняя по отношению к данному файлу ссылка!

        extern double &ref;
        ref++;

        //Раскомментируйте следующую строку. Что следует сделать, чтобы
        //компилятор не выдавал ошибки
        int val1 = 1;
        int& ref1 = val1;



        //Задан указатель:
        char c='A';
        char* pc = &c;
        char *&pcRef = pc;
        //Объявите ссылку на указатель. Посредством ссылки измените
        //а) значение по адресу
        *pcRef = 'B';
        //б) сам адрес
        pcRef = 0;
    }

    {
        //Задание 2. Отличия при передаче параметров а) по значению,
        // б) по ссылке, в) по указателю
        //Объявите и определите три функции , которые увеличивают заданное
        //с помощью параметра значение на 1 ( а) - IncByValue(),
        // б) - IncByPointer(), в) - IncByReference() ).
        //Проверьте правильность с помощью отладчика.
        //
        //Замечание: объявления функций принято помещать в заголовочный файл
        int val =1;//значение этой переменной должно быть увеличено с помощью
                    //каждой из функций на единицу
        val = IncByValue(val);
        IncByPointer(&val);
        IncByReference(val);

        stop

        //Задание 2а. Передача параметров c помощью указателя и по ссылке.
        //Перегруженные имена функций.
        //Создайте функцию (функции) Swap(), которая меняет значения
        //переменных nX и nY местами.
        // а)Функция должна принимать два указателя на int, оперируя с
        //которыми менять значения переменных в вызывающей программе
        // б)Функция должна принимать две ссылки на int
        //Проверьте правильность с помощью приведенного ниже фрагмента.

        int	nX = 1;
        int nY = -1;
        Swap(&nX, &nY);	//поменяли местами значения nX и nY с
                            //помощью указателей на nX и nY
        Swap(nX, nY);	//а теперь обратно с помощью ссылок на nX и nY
        stop
    }

    {
        //Задание 3. Указатели на массивы в качестве аргументов.
        //3a.Напишите два варианта функции поиска минимального элемента
        //1. во встроенном двухмерном массиве
        //2. в динамическом двухмерном массиве (обе размерности вычисляются)

        //1.Например:

        int ar[N][M] = {1, 2, 3, 4, 5, 6, 7, 8, -1, -5, -6, -60};//подумайте - как и где должны быть заданы N и M

        int **arD = new int *[N];
        for (int i = 0; i < N; ++i){
            arD[i] = new int[M];
            for (int j = 0; j < M; ++j){
                arD[i][j] = rand();
            }
        }


        int res = Min(ar, N);
        res = Min(arD, N, M);
        stop


        //3b. Напишите функцию сравнения двух строк - MyStrCmp():
        //Функция должна принимать два указателя на сравниваемые
        //строки (возможно Вы должны указать компилятору, что функция
        //не имеет права модифицировать содержимое строк)
        //Функция должна возвращать отрицательное значение, если
        //первая строка лексиграфически меньше второй, 0 - если
        //они равны и положительное значение, если первая строка
        //больше второй.
        //Вспомните, что признаком конца строки является нулевой байт.


        //Создайте две строки для сравнения:
        const char* str1 = "abc";
        const char* str2 = "abs";

        //Вызовите функцию сравнения
        std::cout << "String compare: " << MyStrCmp(str1, str2) << '\n';
        //Выведите результат сравнения с помощью cout:

        stop
    }

    {
        //Задание 4.Ссылки в качестве параметров. Передача указателя на встроенный
        //массив в качестве параметра функции.
        //Напишите две взаимодополняющие друг друга функции:
        //1.  ... DayOfYear(...)
        //- преобразует день месяца (число,месяц и год задаются в качестве параметров)
        //в порядковый день года(возвращаемое значение)
        //2. ... DayOfMonth(...) - функция преобразует порядковый день года в день месяца
        // (принимает год и порядковый день года в качестве параметров и должна сформировать
        // день месяца и номер месяца и каким-то образом сообщить эти значения вызывающей процедуре)

        //Проверьте работоспособность обеих функций с помощью следующего фрагмента:


        //В процессе вычислений Вам придется учитывать "високосный - невисокосный" год.
        //Для этого предлагается в каждую функцию в качестве одного из параметров передавать
        //данные приведенного ниже двухмерного массива nDayTab

        int nDayTab[2][12]={
            {31,28,31,30,31,30,31,31,30,31,30,31}, //невисокосный год
            {31,29,31,30,31,30,31,31,30,31,30,31}	};	//високосный год

        //Вызов функции DayOfYear
        int day = DayOfYear(10, 9, nDayTab[0]);
        std::cout << day <<'\n';
        day = DayOfYear(10, 9, nDayTab[1]);
        std::cout << day <<'\n';


        //Проверка результата обратной функцией DayOfMonth
        int month = -1;
        day = DayOfMonth(253, month, nDayTab[0]);
        std::cout << day << ' ' << month << '\n';
        day = DayOfMonth(254, month, nDayTab[1]);
        std::cout << day << ' ' << month << '\n';


        stop
    }
	//Задание 5. Создайте одномерный массив (размерность вычисляется в процессе
	//выполнения программы), заполните его значениями.
	//Напишите функцию, которая добавляет в массив новое значение только при условии,
	//что такого значения в массиве еще нет. Подсказка: при этом размер
	//массива должен увеличиться!
	//Для проверки напишите функцию, которая выводит значения всех элементов на экран


/*
	//Задание 6. Рекурсивные функции. Напишите рекурсивную функцию вычисления
	//суммы первых N натуральных чисел.



*/
/*
	//Задание 7а. Функции с переменным числом параметров.
	//Напишите функцию (дана заготовка VarArgs, не использующая
	// макросы), которая принимает переменное число аргументов
	// типа int и выводит на печать число принятых параметров и
	// их значения.
	// Признаком конца списка является нулевое значение.
	
	int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;
	VarArgs(nN1,0);	
	VarArgs(nN1,nN2,0);	
	VarArgs(nN1,nN2,nN3,nN4,nN5,0);	
	stop


	//Задание 7б. Модифицируйте функцию 5а с помощью макросов
	// va_start, va_arg, va_end
*/




	//Задание 8. Возвращение адреса.
	//Напишите функцию, которая находит минимальное значение в массиве,
	// таким образом, чтобы ее вызов можно было использовать слева от знака 
	// равенства: *MyMin(параметры) = 0;
	
	

	return 0;
}//main

