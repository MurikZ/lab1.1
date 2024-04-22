#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

// Функция для проверки, является ли строка числом
bool isNumber(const std::string& s) {
    istringstream iss(s);
    double num;
    iss >> num;
    return !iss.fail() && iss.eof();
}

// Функция для выполнения арифметической операции
double performOperation(double operand1, double operand2, char operation) {
    switch (operation) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        cerr << "Ошибка: Неверная операция" << endl;
        return 0;
    }
}

// Функция для вычисления значения выражения в обратной польской записи
double evaluateReversePolishNotation(const std::string& expression) {
    stack<double> st;

    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isNumber(token)) { // Если токен - число, помещаем его в стек
            st.push(stod(token));
        }
        else { // Если токен - операция, выполняем операцию над двумя верхними элементами стека
            if (st.size() < 2) {
                std::cerr << "Ошибка: Недостаточно операндов для выполнения операции" << endl;
                return 0;
            }
            double operand2 = st.top();
            st.pop();
            double operand1 = st.top();
            st.pop();
            st.push(performOperation(operand1, operand2, token[0]));
        }
    }

    if (st.size() != 1) {
        cerr << "Ошибка: Неверное количество операндов и операторов" << endl;
        return 0;
    }

    return st.top(); // Возвращаем результат вычислений
}

int main() {
    setlocale(0, "RU");
    string expression = "2 3 + 3 1 - *"; // Пример выражения в обратной польской записи

    double result = evaluateReversePolishNotation(expression);

    cout << "Значение выражения: " << result << endl;

    return 0;
}

