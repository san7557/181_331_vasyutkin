//Lab_8 - Работа с файлом и строками
#include "pch.h" 
#include "iostream"
#include <string>
#include <fstream>
/*char cstr1[] = "c-style1";
char cstr2[] = "c-style2";
char cstr3[] = "c-style3";
*/


int main()
{
	setlocale(0, "");

	std::ofstream fout("Lab9.txt"); //Открываем файл и записываем в него строку
	fout << "gdfgrhdpolytechfdsfsdftvg" << std::endl;
	fout.close();

	char buff[100];
	std::ifstream fin1("Lab9.txt");
	fin1.getline(buff, 100);
	fin1.close();
	std::cout << "Строка: " << buff << std::endl;

	std::ifstream fin("Lab9.txt"); //Открываем файл
	char c;
	std::string s, find = "polytech";
	while (!fin.eof()) { //Прочитали его и заполнили строку
		fin.get(c);
		s.push_back(c);
	}
	fin.close();
	int pos = s.find(find); //Поиск
	std::cout << "Слово " << find << " находится на " << pos << " позиции";
	getchar();
	return 0;

	/* printf(cstr1); //вывод на печать
	int i = strcmp(cstr1, cstr2);
	printf_s("Result of strcmp(%s, %s) = %d\n", cstr1, cstr2, i);

	int lngth = strlen(cstr1); //длина строки
	printf_s("Result of strlen('%s')=%d\n", cstr1, lngth);

	strcpy_s(cstr3, 255, cstr2); //копирование одной строки в другую
	printf_s("Result of strcpy(%s,%s)\n", cstr3, cstr2);

	strcat_s(cstr3, 255, cstr1); //объединение строк
	std::cout « "Result of strcat(cstr2,cstr1)=" « cstr3 « std::endl;
	*/
}

