#include <iostream>
#include <Windows.h>

int main() {
    
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int N;

    std::cout << "Введите число N: ";
    std::cin >> N;

    int low = 1;
    int high = N;
    int steps = 0;

    while (low <= high) {

        int guess = (low + high) / 2;

        std::cout << "Число Х: " << guess << std::endl;

        std::cout << "Ваш ответ (мало/много/угадал)? ";
        std::string answer;
        std::cin >> answer;

        if (answer == "мало") {
            low = guess + 1;
        }
        else if (answer == "много") {
            high = guess - 1;
        }
        else if (answer == "угадал") {
            std::cout << "Максимальное количество шагов: " << steps << std::endl;
            break;
        }
        else {
            std::cout << "Неверный ответ. Попробуйте снова." << std::endl;
        }

        steps++;
    }

    return 0;
}
