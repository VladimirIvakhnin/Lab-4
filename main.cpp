// Example program
#include <iostream>
#include <cmath>    // для sin, tan, log, pow, cbrt
#include <iomanip>  // для форматування виводу
using namespace std;

// Оголошення користувацьких функцій та процедур
void sort_dec3(int &A, int &B, int &C);   // Процедура впорядковування 3 чисел за спаданням
double deg_to_rad(double D);              // Функція переведення градусів у радіани

// Оголошення функцій для задачі Math
bool inputX(double &x);                   // Функція введення x + перевірка коректності
double calcY(double x);                   // Функція обчислення y
void printResult(double x, double y);     // Функція виведення результату

// Оголошення функцій-завдань
void task_Proc13();
void task_Proc41();
void task_Math();

int main()
{
    int taskNum;
    cout << "Введiть номер завдання (1 - Proc13, 2 - Proc41, 3 - Math): ";
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
            task_Math();
            break;
        default:
            cout << "Помилка! Потрiбно ввести 1, 2 або 3." << endl;
    }

    return 0;
}

// Визначення користувацьких функцій та процедур

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

// Реалізація задачі Math

// 1) Введення x + перевірка коректності
bool inputX(double &x)
{
    cout << "Введiть значення x: ";
    cin >> x;

    if (cin.fail())
    {
        cout << "Помилка! Ви ввели не число." << endl;
        return false;
    }

    // Перевірки коректності:
    if (x == 0)
    {
        cout << "Помилка! x не може дорiвнювати 0 (log|x| не iснує)." << endl;
        return false;
    }

    if ((x + 2.5 * fabs(tan(x))) <= 0)
    {
        cout << "Помилка! Пiдкореневий вираз повинен бути > 0." << endl;
        return false;
    }

    return true; // дані коректні
}

// 2) Обчислення значення y
double calcY(double x)
{
    double numerator = cbrt( fabs((x * x) / 2 - pow(sin(x * x * x), 2)) * (log(fabs(x)) / log(2.5)) );
    double denominator = pow(2, x) * sqrt(x + 2.5 * fabs(tan(x)));

    return numerator / denominator;
}

// 3) Виведення результату
void printResult(double x, double y)
{
    cout << fixed << setprecision(2);  // 2 знаки після коми
    cout << "Для x = " << x << ", y = " << y << endl;
}

// Визначення функцій-завдань
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

// Завдання Math – обчислення значення y для введеного x
void task_Math()
{
    cout << "Task Math" << endl;

    double x, y;

    // Вводимо x і перевіряємо
    if (!inputX(x))
        return; // Якщо некоректно → завершуємо без розрахунків

    // Обчислюємо y
    y = calcY(x);

    // Виводимо результат
    printResult(x, y);
}
