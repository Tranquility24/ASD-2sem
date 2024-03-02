#include <iostream>
#include <ctime>
#include <vector>
#include <time.h>

int randomNumberFunction(int iMIN, int iMAX);
void sortBubble(std::vector<int>& list);
void sortShell(std::vector<int>& list);
void sortSelection(std::vector<int>& list);
void sortQuick(std::vector<int>& list, int low, int high);

int main() {

	setlocale(LC_ALL, "ru");
	srand((unsigned)time(NULL));

	//Задание 1

	int N;

	std::cout << "Введите число N:";
	std::cin >> N;

	//Задание 2

	std::vector<int> A;

	for (int i = 0; i < N; i++) {

		A.push_back(randomNumberFunction(-20, 20));
	}

	//Задание 3
	
	std::cout << "Сгенерированная последовательность A: ";
	for (auto number : A) {

		std::cout << number << '\t';
	}

	//Задание 4

	std::vector<int> B, C, D, E;

	B = C = D = E = A;

	//Задание 5

	clock_t start = clock();

	sortBubble(B);

	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;

	std::cout << "\nОтсортированный массив B(пузырьковая сортировка): ";
	for (auto number : B) {

		std::cout << number << '\t';
	}

	std::cout << "\nВремя сортировки(пузырьковая сортировка): " << seconds << std::endl;
	
	//Задание 6

	start = clock();

	sortShell(C);

	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;

	std::cout << "\nОтсортированный массив C(сортировка вставкой): ";
	for (auto number : C) {

		std::cout << number << '\t';
	}

	std::cout << "\nВремя сортировки(сортировка вставкой): " << seconds << std::endl;

	//Задание 7

	start = clock();

	sortSelection(D);

	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;

	std::cout << "\nОтсортированный массив D(сортировка выбора): ";
	for (auto number : D) {

		std::cout << number << '\t';
	}

	std::cout << "\nВремя сортировки(сортировка выбора): " << seconds << std::endl;

	//Задание 8

	start = clock();

	sortQuick(E, 0, E.size() - 1);

	end = clock();
	seconds = (double)(end - start) / CLOCKS_PER_SEC;

	std::cout << "\nОтсортированный массив E(быстрой сортировкой): ";
	for (auto number : E) {

		std::cout << number << '\t';
	}

	std::cout << "\nВремя сортировки(быстрой сортировкой): " << seconds << std::endl;


	return 0;
}

int randomNumberFunction(int iMIN, int iMAX) {
	
	int number = (int)(((double)rand() / (double)RAND_MAX) * (iMAX - iMIN) + iMIN);
	return number;
}

void sortBubble(std::vector<int>& list)
{
	int intermediateVariable{};

	for (int i = 0; i < list.size() - 1; ++i) {

		for (int j = 0; j < list.size() - i - 1; ++j) {

			if (list.at(j) > list.at(j + 1)) {
				
				intermediateVariable = list.at(j);
				list.at(j) = list.at(j + 1);
				list.at(j + 1) = intermediateVariable;

			}

		}

	}
}

void sortShell(std::vector<int>& list) {

	int intermediateVariable{};

	for (int interval = list.size() / 2; interval > 0; interval /= 2) {

		for (int i = interval; i < list.size(); ++i) {

			intermediateVariable = list.at(i);
			int j = i;

			while (j >= interval && list.at(j - interval) > intermediateVariable) {

				list.at(j) = list.at(j - interval);
				j -= interval;

			}

			list.at(j) = intermediateVariable;
		}
	}
}

void sortSelection(std::vector<int>& list) {

	int n = list.size();

	for (int i = 0; i < n - 1; ++i) {

		int minIndex = i;

		for (int j = i + 1; j < n; ++j) {

			if ( list.at(j) < list.at(minIndex) ) {

				minIndex = j;

			}
		}
		std::swap(list.at(i), list.at(minIndex));
	}
}

void sortQuick(std::vector<int>& list, int low, int high) {

	if (low < high) {
		int pivot = list[(low + high) / 2];
		int i = low;
		int j = high;

		while (i <= j) {
			while (list[i] < pivot) {
				i++;
			}
			while (list[j] > pivot) {
				j--;
			}
			if (i <= j) {
				std::swap(list[i], list[j]);
				i++;
				j--;
			}
		}

		sortQuick(list, low, j);
		sortQuick(list, i, high);
	}
}