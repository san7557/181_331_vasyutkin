//Lab_6 - элементарные преобразования матриц при помощи класса, вектораов при помощи наследованного класса
#include "pch.h" 
#include <iostream>
using namespace std;

class matrix {
private:
	int matr[10][10];
	int matr2[10][10];
	int matr3[10][10];
	int p_rows = 10, p_colums = 10;
	int rows, colums;
	bool boo;

public:
	void inputrc();
	void input();
	void print();
	void sum(matrix matr, matrix matr2);
	void multi(matrix matr, matrix matr2);
	void transp();
	int getrows() {
		return rows;
	}
	int getcolums() {
		return colums;
	}
	int getelem(int i, int j) {
		return matr[i][j];
	}
};

int main()
{
	setlocale(0, "");
	matrix matrA, matrB, matrC;
	matrA.inputrc();
	matrA.input();
	matrA.print();

	matrB.inputrc();
	matrB.input();
	matrB.print();

	matrC.sum(matrA, matrB);
	matrC.print();
	matrC.multi(matrA, matrB);
	matrC.print();

	matrA.transp();
	matrA.print();

}


void matrix::inputrc()
{
	cout << "Введите количество строк и столбцов для матрицы" << endl;
	cin >> p_rows >> p_colums;
}

void matrix::input()
{
	cout << "Введите элементы матрицы" << endl;
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			cin >> matr[rows][colums];
	}
}

void matrix::print()
{
	if (!boo) {
		cout << "Ошибка!" << endl;
	}
	
	else {
		cout << endl;
		for (rows = 0; rows < p_rows; rows++) {
			for (colums = 0; colums < p_colums; colums++)
				cout << matr[rows][colums]<<"\t";
			cout << endl;
		}
	}
}

void matrix::sum(matrix matr, matrix matr2)
{
	if (matr.getrows() != matr2.getrows() || matr.getcolums() != matr2.getcolums()) 
		boo = false;
	else {
		cout << "Мы суммируем матрицы..." << endl;
		for (rows = 0; rows < p_rows; rows++) {
			for (colums = 0; colums < p_colums; colums++)
				matr3[rows][colums] = matr.getelem(rows, colums) + matr2.getelem(rows, colums);
		}
	}
}

void matrix::multi(matrix matr, matrix matr2)
{
	if (matr.getrows() != matr2.getcolums() || matr.getcolums() != matr2.getrows()) 
		boo = false;
	else {
		if (matr.getrows() == matr2.getcolums() && matr.getcolums() == matr2.getrows()) {
			cout << "Мы умножаем матрицы..." << endl;
			int inner = 0;
			for (rows = 0; rows < p_rows; rows++) {
				for (colums = 0; colums < matr2.getcolums(); colums++) {
					for (inner = 0; inner < p_colums; inner++) 
						matr3[rows][colums] += matr.getelem(rows, colums) * matr2.getelem(rows, colums);
				}
			}
		}
	}
}

void matrix::transp()
{
	std::cout << "Мы транспонируем матрицу..." << std::endl;
	int o = 0;
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = rows; colums < p_colums; colums++) {
			int o = matr[rows][colums];
			matr[rows][colums] = matr[colums][rows];
			matr[colums][rows] = o;
		}
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