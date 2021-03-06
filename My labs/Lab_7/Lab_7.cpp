//Lab_7 - выделение динамической памяти для элементарных преобразований матриц при помощи класса

#include "pch.h"
#include <iostream>

class matrixdyn
{
protected:
	double *matr;
	int rows;
	int	colums;
	bool boo;
public:
	virtual void create();
	virtual void input();
	void print();
	void plus(matrixdyn matr2);
	void mult(matrixdyn matr2);
	void transp();
	int getrows()
	{
		return rows;
	}
	int getcolums()
	{
		return colums;
	}
	double getelem(int r, int c)
	{
		return matr[r*colums + c];
	}
	void del();
};

class vectordyn : public matrixdyn
{
public:
	virtual void input();
	virtual void create();
	void xmult(double k);
	double scalmultvector(vectordyn vec2);
};

int main()
{
	setlocale(0, "");

	matrixdyn matrA, matrB;
	matrA.create();
	matrA.input();
	std::cout << "Матрица A \n";
	matrA.print();

	matrB.create();
	matrB.input();
	std::cout << "Матрица B \n";
	matrB.print();

	matrA.transp();

	matrA.plus(matrB);
	std::cout << "A + B \n";
	matrA.print();

	matrA.mult(matrB);
	std::cout << "A * B \n";
	matrA.print();

	matrA.del();
	matrB.del();


	vectordyn matrA1, matrB1;
	matrA1.create();
	matrA1.input();
	std::cout << "Вектор A \n";
	matrA1.print();

	matrB1.create();
	matrB1.input();
	std::cout << "Вектор B \n";
	matrB1.print();

	matrA1.xmult(10);
	std::cout << "А * 10 \n";
	matrA1.print();

	matrA1.plus(matrB1);
	std::cout << "A * 10 + B \n";
	matrA1.print();

	double f = matrA1.scalmultvector(matrB1);
	std::cout << "(A * 10 + B) * B \n" << f << std::endl;

	matrA1.del();
	matrB1.del();

	getchar();
	return 0;
}


void matrixdyn::create()
{
	int p_rows;
	int p_colums;
	std::cout << "Введите количество строк" << std::endl;
	std::cin >> p_rows;
	std::cout << "Введите количество столбцов" << std::endl;
	std::cin >> p_colums;
	std::cout << "\n";
	rows = p_rows;
	colums = p_colums;
	matr = new double[rows*colums];
}

void matrixdyn::input()
{
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < colums; j++)
		{
			std::cout << "Матрица[" << i+1 << "][" << j+1 << "]";
			std::cin >> matr[i*colums + j];
		}
	std::cout << "\n";
	boo = true;
}

void matrixdyn::print()
{
	if (!boo)
	{
		std::cout << "Error!" << "\n" << "\n";
		boo = true;
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colums; j++)
				std::cout << matr[i*colums + j] << "\t";
			std::cout << std::endl;
		}
		std::cout << "\n";
	}
}

void matrixdyn::plus(matrixdyn matr2)
{
	if (rows != matr2.getrows() || colums != matr2.getcolums())
	{
		boo = false;
	}
	else {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < colums; j++)
				matr[i*colums + j] += matr2.getelem(i, j);
	}
}

void matrixdyn::mult(matrixdyn matr2)
{
	if (colums != matr2.getrows() || rows != matr2.getcolums())
		boo = false;
	else
	{
		double *matr3 = new double[colums*matr2.getrows()];
		for (int j = 0; j < matr2.getcolums(); j++)
			for (int i = 0; i < rows; i++) 
				for (int t = 0; t < colums; t++)
					matr3[i*colums + t] += matr[i*colums + t] * matr2.getelem(t, j);
		for (int i = 0; i < rows; i++) {
			for (int t = 0; t < matr2.getcolums(); t++)
				std::cout << matr3[i*colums + t] << "\t";
			std::cout << std::endl;
		}
		std::cout << "\n";
	}
}

void matrixdyn::transp()
{
	double *matr3 = new double[rows*colums];
	if (rows != colums)
	{
		std::cout << "Мы транспонируем только квадратные матрицы.\n" << std::endl;
	}
	else
	{
		std::cout << "Мы транспонируем матрицу A..." << std::endl;
		int o = 0;
		for (int i = 0; i < rows; i++)
			for (int j = i; j < colums; j++) 
			{
				int o = matr[i*colums + j];
				matr[i*colums + j] = matr[j*rows + i];
				matr[j*rows + i] = o;
			}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colums; j++)
				std::cout << matr[i*colums + j] << "\t";
			std::cout << std::endl;
		}
		std::cout << "\n";
	}
}

void matrixdyn::del()
{
	if (matr != NULL)
	{
		delete matr;
		matr = NULL;
	}
	else
		std::cout << "Тут чисто!" << std::endl;
}

void vectordyn::input()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colums; j++)
		{
			std::cout << "Вектор[" << j + 1 << "] = ";
			std::cin >> matr[i*colums + j];
		}
	std::cout << "\n";
	boo = true;
}

void vectordyn::create()
{
	int p_rows = 1;
	int p_colums;
	std::cout << "Количество строк = 1" <<std::endl;
	std::cout << "Введите количество столбцов" <<std::endl;
	std::cin >> p_colums;
	colums = p_colums;
	rows = p_rows;
	matr = new double[rows*colums];
}

void vectordyn::xmult(double k)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colums; j++)
			matr[i*colums + j] *= k;
}

double vectordyn::scalmultvector(vectordyn vec2)
{
	double product = 0;
	if (colums != vec2.getcolums())
	{
		boo = false;
		std::cout << "Мы вычисляем скалярное произведение только равных векторов.\n" << std::endl;
	}
	else
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < colums; j++) 
				product = product + matr[i*colums + j] * vec2.getelem(i, j);
		return product;
	}
}










/*
// стековая память ограничена, при неправльном испоьзовании стек переполняется (stack overflow)
// размерности массивов, выделяемых в стековой памяти, фиксированы и задаются константами
// int b[1000][1000] = { 0 }; - ПЕРЕПОЛНЕНИЕ СТЕКА

// для использования свободной памяти ОС (heap - "куча")
// обвляются динамические переменные по синтаксису
// указатель_на_тип имя_переменной = new тип;
// или тип * имя_переменной = new тип;
// работа с динамической памятью происходит через указатели

// Преимущестства
// 1) доступно гораздо больше памяти, нежели в стеке
// 2) размеры массивов и структур данных можно определять и менять
// во время работы приложения
// Особенность:
// Если приложение предназначено для длительной работы,
// во избежание переполнения памяти созданные переменные и блоки памяти после использования
// должны быть освобождены с помощью оператора delete:
// delete имя_переменной;

int * ptr_int = new int; // в нераспределённой памяти создаётся блок
//размером с int и указатель на него возвращается в переменную ptr_int

// вызов утечки памяти
for (int i = 0; i < 10000; i++)
	{
		// 1) каждый заход в стеке создаётся новый указатель
		// 2) выделяется блок new long long; в куче (нераспределённой памяти), приписанный к этой программе
		// 3) стековая переменная b исчезает
		// 4) а блок по-прежнему остаётся там же
		// 5) при следующем заходе выделяется новый блок
		long long * b = new long long;
		// совешать нужные действия с переменной
		delete b;// удалить блок памяти пока не потерян указатель на неё
	}

// пара операторов new/delete - это одно из нововведений C++ относительно C

// в динамичекой памяти могут выделяться только одномерные массивы
//		тип * имя_указателя = new тип[длина];
// удаляются одномерные массивы с помощью записи
//		delete[] имя_указателя;


// для выделения двумерного массива сначала создаётся одномерный массив, содержащий указатели на другие массивы (строки)
// МОЖЕМ ЗАДАВАТЬ РАЗМЕРНОСТИ ПЕРЕМЕННЫМИ
int ** dynamic2Darray = new int *[l1];
// затем выделяется блок памяти под каждую строку и указатель на неё возвращается в созданный массив указателей
for (int i = 0; i < l1; i++)
{
	dynamic2Darray[i] = new int[l2];//  dynamic2Darray[i] имеет тип (int*)  
		for (int j = 0; j < l2; j++)
		{
			dynamic2Darray[i][j] = j;
		}
	}

	cout << endl;
	cout << "ARRAY IN DYNAMIC MEMORY:" << endl;
	cout << "*** dynamic2Darray[0] ***" << endl;
	cout << "Address" << "\t\t\t" << "Value" << endl;
	cout << "--------------------------------" << endl;

	for (int * pointer = &dynamic2Darray[0][0] - 4;
		pointer < &dynamic2Darray[0][0] + 8;
		pointer++)
	{
		//cout << указатель << '\t' << значение << endl;
		cout << "0x" << pointer << '\t' << *pointer << endl;
	}

	cout << endl;
	cout << "ARRAY IN DYNAMIC MEMORY:" << endl;
	cout << "*** dynamic2Darray[1] ***" << endl;
	cout << "Address" << "\t\t\t" << "Value" << endl;
	cout << "--------------------------------" << endl;

	for (int * pointer = &dynamic2Darray[1][0] - 4;
		pointer < &dynamic2Darray[1][0] + 8;
		pointer++)
	{
		//cout << указатель << '\t' << значение << endl;
		cout << "0x" << pointer << '\t' << *pointer << endl;
	}

	cout << endl;
	cout << "ARRAY IN DYNAMIC MEMORY:" << endl;
	cout << "*** dynamic2Darray[2] ***" << endl;
	cout << "Address" << "\t\t\t" << "Value" << endl;
	cout << "--------------------------------" << endl;

	for (int * pointer = &dynamic2Darray[2][0] - 4;
		pointer < &dynamic2Darray[2][0] + 8;
		pointer++)
	{
		//cout << указатель << '\t' << значение << endl;
		cout << "0x" << pointer << '\t' << *pointer << endl;
	}

	print(dynamic2Darray, l1, l2);


	// осв.
	for (int i = 0; i < l1; i++)
	{
		delete[] dynamic2Darray[i];//  dynamic2Darray[i] имеет тип (int*)  
	}
	delete[] dynamic2Darray;

	// многомерные массивы фиксированной длины в стековой памяти чаще всего размещяются сплошным блоком
	// динамические - нет (где ОС выделила место под очередную строку - там она и будет находиться, и между строками будет неизвестно что)

	int fixed_array[3][3] = { { 10, 20, 30 },
	{ 40, 50, 60 },
	{ 70, 80, 90 } };

	cout << endl;
	cout << "ARRAY IN STACK MEMORY:" << endl;
	cout << "Address" << "\t\t\t" << "Value" << endl;
	cout << "--------------------------------" << endl;

	for (int * pointer = &fixed_array[0][0] - 10;
		pointer < &fixed_array[0][0] + 10;
		pointer++)
	{
		//cout << указатель << '\t' << значение << endl;
		cout << "0x" << pointer << '\t' << *pointer << endl;
	}

	int * matr = new int[l1*l2];
	for (int row = 0; row<l2; row++)
	{
		for (int col = 0; col<l1; col++)
		{
			matr[row*l1 + col] = row*l1 + col;
		}
	}

	for (int row = 0; row<l2; row++)
	{
		for (int col = 0; col<l1; col++)
		{
			cout << matr[row*l1 + col] << "\t";
		}
		cout << endl;
	}

	delete[] matr;
}
*/