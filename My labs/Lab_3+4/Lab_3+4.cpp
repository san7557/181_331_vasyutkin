//Lab_3 - сортировки
//Lab_4 - сортировка через функцию
#include "pch.h"
#include <iostream>

//Функция для сортировки пузрьком.
int *puz(int arr[10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10 - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int o = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = o;

			}
		}
	}
	return arr;
};

int main()
{
	//Задание 1.

	int a = 1;
	int *ptr_int = &a;
	double b = 56.7;
	double *ptr_double = &b;
	char c = 7;
	char *ptr_char = &c;
	long d = 528288;
	long *ptr_long = &d;
	bool e = true;
	bool *ptr_bool = &e;

	std::cout << "int pointer size = " << sizeof(ptr_int) << std::endl;
	std::cout << "double pointer size = " << sizeof(ptr_double) << std::endl;
	std::cout << "char pointer size = " << sizeof(ptr_char) << std::endl;
	std::cout << "long long pointer size = " << sizeof(ptr_long) << std::endl;
	std::cout << "bool pointer size = " << sizeof(ptr_bool) << std::endl;

	//Задание 2. Шифр Цезаря.

	int alps[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int alpb[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	char code[20] = { 'I','n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'o', 'n', ' ', 'S', 'e', 'c', 'u', 'r', 'i', 't', 'y' };

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 26; j++) {
			if (code[i] == alpb[j]) {
				code[i] = alpb[(j + 3) % 26];
				break;
			}
			if (code[i] == alps[j]) {
				code[i] = alps[(j + 3) % 26];
				break;
			}
		}
	}
	std::cout << "Information Security = " << code[0] << code[1] << code[2] << code[3] << code[4] << code[5] << code[6] << code[7] << code[8] << code[9] << code[10] << code[11] << code[12] << code[13] << code[14] << code[15] << code[16] << code[17] << code[18] << code[19] << std::endl;

	//Задание 3. Сортировка пузырьком.

	int arr1[10] = { 5,6,7,4,3,2,1,8,9,0 };
	*puz(arr1);
	for (int i = 0; i < 10; i++) {
		std::cout << arr1[i] << "\t";
	}
	std::cout << std::endl;

	//Задание 4. Шейкерная сортировка массива.
	int sh[10] = { 256,1024,512,2,2048,64,16,128,65536,4 };
	int br = 0;
	int st;
	for (int i1 = 0; i1 < 5; i1++) {
		for (int zr = 0 + br; zr < 9 - br; zr++) {
			if (sh[zr] > sh[zr + 1]) {
				st = sh[zr];
				sh[zr] = sh[zr + 1];
				sh[zr + 1] = st;
			}
		}
		for (int zt = 9 - br; zt > br; zt--) {
			if (sh[zt] < sh[zt - 1]) {
				st = sh[zt];
				sh[zt] = sh[zt - 1];
				sh[zt - 1] = st;
			}
		}
		br++;
	}
	for (int di = 0; di < 10; di++) {
		std::cout << sh[di] << "  ";
	}
}