// Example program
#include <iostream>
#include <cmath>
using namespace std;

//  Оголошення користувацьких функцій та процедур 
void sort_dec3(int &A, int &B, int &C);       // Процедура впорядкування 3 чисел за спаданням
double deg_to_rad(double D);                  // Функція переведення градусів у радіани
int tens_digit(int N);                        // Функція повертає цифру десятків числа

// --- Оголошення функцій-завдань ---
void task_Proc13();
void task_Proc41();
void task_Integer31();

int main()
{
    int taskNum;
    cout << "Введiть номер завдання (1 - Proc13, 2 - Proc41, 3 - Integer31): ";
    cin >> taskNum;

    switch (taskNum)
    {
        case 1:
            task_Proc13();
            break;
        case 2:
            task_Proc41();
            break;
        case 3:
            task_Integer31();
            break;
        default:
            cout << "Помилка! Потрiбно ввести 1, 2 або 3." << endl;
    }

    return 0;
}

//  Визначення користувацьких функцій та процедур 
// Процедура впорядковує A, B, C за спаданням
void sort_dec3(int &A, int &B, int &C)
{
    int t;
    if (A < B) { t = A; A = B; B = t; }
    if (A < C) { t = A; A = C; C = t; }
    if (B < C) { t = B; B = C; C = t; }
}

// Функція переводить градуси у радіани
double deg_to_rad(double D)
{
    const double PI = 3.14;
    return (D * PI) / 180.0;
}

// Функція повертає цифру десятків цілого числа
int tens_digit(int N)
{
    N = abs(N);
    return (N / 10) % 10;
}

//  Визначення функцій-завдань 

// Завдання Proc13 – впорядкування 3 чисел
void task_Proc13()
{
    int A, B, C;
    cout << "Task Proc13" << endl;

    cout << "Введiть три числа A B C: ";
    cin >> A >> B >> C;
    sort_dec3(A, B, C);
    cout << "1) Пiсля впорядкування: " << A << " " << B << " " << C << endl;

    cout << "Введiть три числа A B C: ";
    cin >> A >> B >> C;
    sort_dec3(A, B, C);
    cout << "2) Пiсля впорядкування: " << A << " " << B << " " << C << endl;
}

// Завдання Proc41 – переведення градусів у радіани
void task_Proc41()
{
    double D;
    cout << "Task Proc41" << endl;

    cout << "Введiть кут у градусах: ";
    cin >> D;
    cout << "1) У радiанах: " << deg_to_rad(D) << endl;

    cout << "Введiть кут у градусах: ";
    cin >> D;
    cout << "2) У радiанах: " << deg_to_rad(D) << endl;
}

// Завдання Integer31 – цифра десятків числа
void task_Integer31()
{
    int N;
    cout << "Task Integer31" << endl;

    cout << "Введiть цiле число: ";
    cin >> N;
    cout << "1) Цифра десяткiв: " << tens_digit(N) << endl;

    cout << "Введiть цiле число: ";
    cin >> N;
    cout << "2) Цифра десятків: " << tens_digit(N) << endl;
}
