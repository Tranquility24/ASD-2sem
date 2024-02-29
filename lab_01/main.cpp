#include <iostream>
#include <time.h>

long long getFibonacciNumberCycle(int N) {

	if (N == 0)
	{
		return 0;
	}
	if (N == 1)
	{
		return 1;
	}

	long long number{};
	long long numberMemory[2]{ 0, 1 };

	for (int i = 1; i < N; i++)
	{
		number = numberMemory[0] + numberMemory[1];
		numberMemory[0] = numberMemory[1];
		numberMemory[1] = number;
	}

	return number;
}

long long getFibonacciNUmberRecursion(int N) {

		if (N == 0)
			return 0;

		if (N == 1)
			return 1;

		return getFibonacciNUmberRecursion(N - 2) + getFibonacciNUmberRecursion(N - 1);
}

int main() {

	setlocale(LC_ALL, "ru");

	int N;

	std::cout << "Введите число N:";
	std::cin >> N;
	
	clock_t start1 = clock();

	std::cout << "Число Фибоначчи(через цикл): " << getFibonacciNumberCycle(N) << std::endl;

	clock_t end1 = clock();
	double seconds = (double)(end1 - start1) / CLOCKS_PER_SEC;
	std::cout << "Время выполнения с помощью цикла: " << seconds << std::endl;

	clock_t start2 = clock();

	std::cout << "Число Фибоначчи(через рекурсию): " << getFibonacciNUmberRecursion(N) << std::endl;

	clock_t end2 = clock();
	seconds = (double)(end2 - start2) / CLOCKS_PER_SEC;
	std::cout << "Время выполнения с помощью рекурсии: " << seconds << std::endl;

	return 0;
}