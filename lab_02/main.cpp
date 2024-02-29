#include <iostream>
#include <Windows.h>

int main() {
    
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int N;

    std::cout << "������� ����� N: ";
    std::cin >> N;

    int low = 1;
    int high = N;
    int steps = 0;

    while (low <= high) {

        int guess = (low + high) / 2;

        std::cout << "����� �: " << guess << std::endl;

        std::cout << "��� ����� (����/�����/������)? ";
        std::string answer;
        std::cin >> answer;

        if (answer == "����") {
            low = guess + 1;
        }
        else if (answer == "�����") {
            high = guess - 1;
        }
        else if (answer == "������") {
            std::cout << "������������ ���������� �����: " << steps << std::endl;
            break;
        }
        else {
            std::cout << "�������� �����. ���������� �����." << std::endl;
        }

        steps++;
    }

    return 0;
}
