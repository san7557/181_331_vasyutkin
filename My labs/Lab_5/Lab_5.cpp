//Lab_5 - сортировка через класс
#include "pch.h"
#include <iostream>


class Lab5 {
private:
	int br;
public:
	void *puz(int arr[10]) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10 - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int o = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = o;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			std::cout << arr[i] << "\t";
		}
		return 0;
	}

	void *shk (int arr[10]){
		for (int i1 = 0; i1 < 5; i1++) {
			for (int zr = 0 + br; zr < 9 - br; zr++) {
				if (arr[zr] > arr[zr + 1]) {
					int st = arr[zr];
					arr[zr] = arr[zr + 1];
					arr[zr + 1] = st;
				}
			}
			for (int zt = 9 - br; zt > br; zt--) {
				if (arr[zt] < arr[zt - 1]) {
					int st = arr[zt];
					arr[zt] = arr[zt - 1];
					arr[zt - 1] = st;
				}
			}
			br++;
		}
		for (int di = 0; di < 10; di++) {
			std::cout << arr[di] << "  ";
		};
		return 0;
	};
};

int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++) {
		std::cin >> arr[i];
	}
	Lab5 sort;
	sort.puz(arr);
	sort.shk(arr);
}
