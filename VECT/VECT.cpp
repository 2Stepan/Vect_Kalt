
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// Перечисление операций
enum OPER {
    plus,
    minus,
    multiny,
    sclar
};

/**
 * Выводит вектор на экран.
 * @param vect Массив с координатами вектора.
 */
void vec(int vect[])
{
    cout << '(' << vect[0] << ';' << vect[1] << ')';
}

/**
 * Складывает два вектора.
 * @param vect1 Первый вектор.
 * @param vect2 Второй вектор.
 */
void vect_plus(int vect1[], int vect2[])
{
    cout << '(' << vect1[0] + vect2[0] << ';' << vect1[1] + vect2[1] << ')';
}

/**
 * Вычитает второй вектор из первого.
 * @param vect1 Первый вектор.
 * @param vect2 Второй вектор.
 */
void vect_minus(int vect1[], int vect2[])
{
    cout << '(' << vect1[0] - vect2[0] << ';' << vect1[1] - vect2[1] << ')';
}

/**
 * Выполняет покоординатное умножение векторов.
 * @param vect1 Первый вектор.
 * @param vect2 Второй вектор.
 */
void vect_multiny(int vect1[], int vect2[])
{
    cout << '(' << vect1[0] * vect2[0] << ';' << vect1[1] * vect2[1] << ')';
}

/**
 * Вычисляет скалярное произведение двух векторов.
 * @param vect1 Первый вектор.
 * @param vect2 Второй вектор.
 */
void vect_sclar(int vect1[], int vect2[])
{
    cout << '(' << vect1[0] * vect2[0] + vect1[1] * vect2[1] << ')';
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string str_vect;
    string operation;

    int vect1[2];
    int vect2[2];

    cout << "Введите вектора a=(x;y) b=(x;y): ";
    getline(cin, str_vect);

    int pos = str_vect.find('(');
    int pos2 = str_vect.find(';');
    int pos3 = str_vect.find(')');

    vect1[0] = stoi(str_vect.substr(pos + 1, pos2 - pos - 1));
    vect1[1] = stoi(str_vect.substr(pos2 + 1, pos3 - pos2 - 1));

    pos = str_vect.find('(', pos3);
    pos2 = str_vect.find(';', pos);
    pos3 = str_vect.find(')', pos2);

    vect2[0] = stoi(str_vect.substr(pos + 1, pos2 - pos - 1));
    vect2[1] = stoi(str_vect.substr(pos2 + 1, pos3 - pos2 - 1));

    cout << "Введите операцию (+, -, *, **): ";
    getline(cin, operation);

    OPER oper;

    if (operation == "+")
        oper = OPER::plus;
    else if (operation == "-")
        oper = OPER::minus;
    else if (operation == "*")
        oper = OPER::multiny;
    else if (operation == "**")
        oper = OPER::sclar;
    else
    {
        cout << "Неизвестная операция";
        return 0;
    }

    cout << "\nc=";

    switch (oper)
    {
    case OPER::plus:
        vect_plus(vect1, vect2);
        break;

    case OPER::minus:
        vect_minus(vect1, vect2);
        break;

    case OPER::multiny:
        vect_multiny(vect1, vect2);
        break;

    case OPER::sclar:
        vect_sclar(vect1, vect2);
        break;
    }

    return 0;
}
