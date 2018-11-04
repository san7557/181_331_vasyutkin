#include "pch.h" 
#include <iostream>

class matrix {
private:
	bool boo;
	int rows;
	int colums;
	int matr[10][10];
	int p_rows = 10, p_colums = 10;

public:
	void inpsw();
	void input();
	void print();

	bool sum(matrix matr2);
	bool multi(matrix matr2);
	void transp();
	int getelem(int i, int j) {
		return matr[i][j];
	} 
	int getrows() {
		return rows;
	}
	int getcolums() {
		return colums;
	}
};

class vector :public matrix {
private:
	int number = 0;
	int colums;
	const int rows = 1;
	int p_rows = 1;
	int vec[10][10];
	int p_colums = 10;

public:
	void inpc();
	void input();
	void printc();

	bool sum(vector vec2);
	bool multi(vector vec2);
	void multnum();
	int getelemc(int i, int j) {
		return vec[i][j];
	}
	int getcolumsc() {
		return colums;
	}
};

int main()
{
	setlocale(0, "");
	
	matrix matrA, matrB;
	matrA.inpsw();
	matrA.input();
	matrA.print();

	matrB.inpsw();
	matrB.input();
	matrB.print();

	matrA.sum(matrB);
	matrA.print();
	matrA.multi(matrB);
	matrA.print();
	matrA.transp();
	matrA.print();

	vector vecA, vecB;
	vecA.inpc();
	vecA.input();
	vecA.printc();

	vecB.inpc();
	vecB.input();
	vecB.printc();

	vecA.sum(vecB);
	vecA.printc();
	vecA.multi(vecB);
	vecA.printc();
	vecA.multnum();
	vecA.printc();

	getchar(); 
	return 0;
}

int rows = 0, colums = 0;

void matrix::inpsw()
{
	std::cin >> p_rows >> p_colums;
}

void matrix::input()
{
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = 0; colums < p_colums; colums++)
			std::cin >> matr[rows][colums]; //ввод очередного элемента матрицы 
	}
}

void matrix::print()
{
	if (boo = false) {
		std::cout << "Error!";
	}
	else {
		for (rows = 0; rows < p_rows; rows++) {
			for (colums = 0; colums < p_colums; colums++)
				std::cout << matr[rows][colums] << "\t"; //вывод очередного элемента матрицы 
			std::cout << std::endl; //переход на новую строку после вывода всех элементов строки 
		}
	}
}

bool matrix::sum(matrix matr2)
{
	if (rows != matr2.getrows() or colums != matr2.getcolums())
	{
		boo = false;
		return false;
	}
	else {
		for (rows = 0; rows < p_rows; rows++)
		{
			for (colums = 0; colums < p_colums; colums++)
				matr[rows][colums] = matr[rows][colums] + matr2.getelem(rows, colums);
		}
		return true;
	}
}

bool matrix::multi(matrix matr2)
{
	if (colums != matr2.getrows() or rows != matr2.getcolums())
	{
		return false;
		std::cout << "Error!";
	}
	if (rows == matr2.getcolums() and colums == matr2.getrows())
	{
		int inner = 0;
		int s = 0;
		for (rows = 0; rows < p_rows; rows++) {
			for (colums = 0; colums < p_colums; colums++) {
				for (inner = 0; inner < rows; inner++)
					matr[rows][colums] += matr[rows][inner] * matr2.getelem(inner, colums);
			}
		}
		return true;
	}
}

void matrix::transp()
{
	int o = 0;
	for (rows = 0; rows < p_rows; rows++) {
		for (colums = rows; colums < p_colums; colums++) {
			int o = matr[rows][colums];
			matr[rows][colums] = matr[colums][rows];
			matr[colums][rows] = o;
		}
	}
}

void vector::inpc()
{
	std::cout << "Введите размер вектора" << std::endl;
	std::cin >> p_colums;
}

void vector::input()
{
	for (colums = 0; colums < p_colums; colums++) {
		std::cin >> vec[rows][colums];
	}
}

void vector::printc()
{
	for (colums = 0; colums < p_colums; colums++) {
		std::cout << vec[rows][colums] << '/t';
	}
	std::cout << std::endl;
}

bool vector::sum(vector vec2)
{
	if (colums != vec2.getcolumsc()) {
		return false;
	}
	else {
		for (colums = 0; colums < p_colums; colums++) {
			vec[rows][colums] = vec[rows][colums] + vec2.getelemc(rows, colums);
		}
		return true;
	}
}

bool vector::multi(vector vec2)
{
	if (colums != vec2.getcolumsc()) {
		return false;
	}
	else {
		for (colums = 0; colums < p_colums; colums++) {
			vec[rows][colums] = vec[rows][colums] * vec2.getelemc(rows, colums);
		}
		return true;
	}
}

void vector::multnum()
{
	std::cout << "Insert the number" << std::endl;
	std::cin >> number;
	for (colums = 0; colums < p_colums; colums++) {
		vec[rows][colums] = vec[rows][colums] * number;
	}
}
