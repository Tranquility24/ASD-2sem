#include <iostream>
#include <stack>
#include <string>

bool areBracketsBalanced(std::string str) {

    std::stack<char> st;
    const int n = str.length();

    char open_brackets[] = { '(', '[', '{' };
    char close_brackets[] = { ')', ']', '}' };

    for (int i = 0; i < n; i++) {

        char bracket = str[i];

        if (bracket == '(' || bracket == '[' || bracket == '{') {

            st.push(bracket);

        }
        else {

            if (st.empty()) {

                return false;

            }
            char top = st.top();

            if ((bracket == ')' && top == '(') || (bracket == ']' && top == '[') || (bracket == '}' && top == '{')) {

                st.pop();

            }
            else {

                return false;

            }
        }
    }

    return st.empty();
}

int main() {

    setlocale(LC_ALL, "ru");

    std::string str;
    std::cout << "������� ������ � ��������� � ��������: ";
    getline(std::cin, str);

    if (areBracketsBalanced(str)) {

        std::cout << "������ ����������� �����" << std::endl;
    }
    else {

        std::cout << "������ ����������� �� �����" << std::endl;
    }

    return 0;
}
