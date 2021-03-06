//Lab_6 - элементарные преобразования матриц при помощи класса, вектораов при помощи наследованного класса

#include "pch.h"
#include <iostream>

class matrix
{
protected:
	double matr[10][10];
	int rows;
	int	colums;
	bool boo;
public:
	virtual bool input();
	void print();
	void plus(matrix matr2);
	void mult(matrix matr2);
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
		if (r < rows || c < colums || c > -1)
			return matr[r][c];
		std::cout << "Ошибка!";
		return -1;
	}
};

class vector : public matrix
{
public:
	virtual bool input();
	void xmult(double k);
	double scalmultvector(vector vec2);
};

int main()
{
	setlocale(0, "");
	
	matrix matrA, matrB;
	matrA.input();
	std::cout << "Матрица A \n";
	matrA.print();
	
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
	

	vector matrA1, matrB1;
	matrA1.input();
	std::cout << "Вектор A \n";
	matrA1.print();
	
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
	
	getchar();
	return 0;
}


bool matrix::input()
{
	std::cout << "Введите количество строк  ";
	std::cin >> rows;
	if (rows < 0 || rows > 10)
	{
		std::cout << "Ошибка!  \n" << std::endl;
		return false;
	}
	else {
		std::cout << "Введите количество столбцов  ";
		std::cin >> colums;
		if (colums < 0 || colums > 10)
		{
			std::cout << "Ошибка! \n" << std::endl;
			return false;
		}
		else {
			std::cout << "Введите элементы матрицы  " << std::endl;
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < colums; j++)
					std::cin >> matr[i][j];
			std::cout << "\n";
			return true;
		}
	}
}

void matrix::print()
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
				std::cout << matr[i][j] << "\t";
			std::cout << std::endl;
		}
		std::cout << "\n";
	}
}

void matrix::plus(matrix matr2)
{
	if (rows != matr2.getrows() || colums != matr2.getcolums())
	{
		boo = false;
	}
	else {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colums; j++)
				matr[i][j] += matr2.getelem(i, j);
		}
	}
}

void matrix::mult(matrix matr2)
{

	if (colums != matr2.getrows() || rows != matr2.getcolums())
	{
		boo = false;
	}
	else 
	{
		double matr3[10][10];

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colums; j++)
			{
				matr3[i][j] = matr[i][j];
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getcolums(); j++)
			{
				double x = 0.0;
				for (int t = 0; t < colums; t++)
				{
					x += matr3[i][t] * matr2.getelem(t, j);
				}
				matr[i][j] = x;

			}
		}
		colums = matr2.getcolums();
	}
}

void matrix::transp()
{
	if (rows != colums)
	{
		std::cout << "Мы транспонируем только квадратные матрицы.\n" << std::endl;
	}
	else 
	{
		std::cout << "Мы транспонируем матрицу A..." << std::endl;
		int o = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = i; j < colums; j++) {
				int o = matr[i][j];
				matr[i][j] = matr[j][i];
				matr[j][i] = o;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colums; j++)
				std::cout << matr[i][j] << "\t";
			std::cout << std::endl;
		}
		std::cout << "\n";
	}
}


bool vector::input()
{
	rows = 1;
	colums = 0;
	std::cout << "\nКоличество строк = 1" << std::endl;
	std::cout << "Введите количество столбцов  ";
	std::cin >> colums;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colums; j++)
			std::cin >> matr[i][j];
	std::cout << "\n";
	return true;
}

void vector::xmult(double k)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			matr[i][j] *= k;
		}
	}
}

double vector::scalmultvector(vector vec2)
{
	double product = 0;
	if (colums != vec2.getcolums()) 
	{
		boo = false;
		std::cout << "Мы вычисляем скалярное произведение только равных векторов." << std::endl;
	}
	else
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colums; j++) {
				product = product + matr[i][j] * vec2.getelem(i, j);
			}
		}
		return product;
	}
}









/*
Сlass-описание пользовательского сложного типа данных (конструкция с++).
Поля класса - свойства и методы.
Функция, входящая в состав класс,- метод.
Переменная, входящая в состав класса, - свойства.
Автоматизм вызова конструктора и деструктора обеспечивается высокоуровневыми средствами автоматизации языка. К строке, где объявлен объект, компилятор не явно от программиста, дописывает и вызов класса.
инкапсуляция – фактически объединение данных и методов, объединенных единым смыслом в одну конструкцию языка.
Полиморфизм- одно и то же описание ведет себя по-разному. Простыми словами, экземпляры одного класса ведут себя по-разному.
Наследование- создание производных классов от родительского и заимствование его свойств и методов. Инкапсуляция, наследование и полиморфизм –три основных идеи объектно-ориентированного программирования.
ПЕРЕДАЧА В ФУКНЦИЮ МАССИВОВ
fnc1(double a[размер_массива]);
ПЕРЕДАЧА МАССИВОВ В ФУНКЦИЮ
void fnc4_1(int matr[3][3]);
void fnc4_2(int matr[][3]);
void fnc4_3(int(&matr)[3][3]);
void fnc4_4(int ** matr);
1.НАСЛЕДОВАНИЕ КЛАССОВ-заимствование свойств и методов родительского классо дочерним.
синтаксис:
class имя_нового_класса: [тип_наследования] имя_родительского_класса1
2. Метод переопределенный в дочернем классе полностью заменит унаследованный родительский метод
Чтобы сначала выполнить родительский, а затем наследованный метод, то нужно указать таким способом
в родительском void reload1(){}
в дочернем void reload():void reload1();
3.Если объявить метод с словом virtual, то в данном классе можно не приводить реализацию метода, и определить его только в дочерних классах
ЗАДАНИЕ определить от класса матрицы дочерний класс вектора и дописать ему векторные операции(скалярное и векторное умножение)
4. Приведение типов. при попытке сложитьчисла двух различных типов(double и int), оба операнта автоматически преобразуются к наиболее сложному, длинному типу(double+int=double+doube)если char+int, то строку нужно привести к цифрами
*/
