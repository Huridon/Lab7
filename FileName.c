#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

int Task1(char c);
float Task2(float x, float y, char c);

int RomanValue(char c);
int RomanToYear(char c1, char c2, char c3, char c4, char c5,
    char c6, char c7, char c8, char c9);

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Task1
    char c;
    int kind;

    printf("Введите символ: ");
    scanf(" %c", &c);

    kind = Task1(c);

    if (kind == 1)
        printf("Это цифра\n");
    else if (kind == 2)
        printf("Это буква\n");
    else
        printf("Неизвестный символ\n");

    // Task2
    float x, y, res;
    char op;

    printf("\nВведите выражение (например, 5+3): ");
    scanf("%f%c%f", &x, &op, &y);

    switch (op)
    {
    case '+':
    case '-':
    case '*':
    case '^':
        res = Task2(x, y, op);
        printf("=%f\n", res);
        break;
    case '/':
        if (y == 0)
            printf("Ошибка: деление на ноль\n");
        else
        {
            res = Task2(x, y, op);
            printf("=%f\n", res);
        }
        break;
    default:
        printf("Неизвестная операция\n");
    }

    //Домашняя работа:

    int n, year;
    char r1 = '\0', r2 = '\0', r3 = '\0', r4 = '\0', r5 = '\0';
    char r6 = '\0', r7 = '\0', r8 = '\0', r9 = '\0';

    printf("\nВведите количество символов в записи года (от 1 до 9): ");
    scanf("%d", &n);

    if (n >= 1 && n <= 9)
    {
        printf("Введите год римскими цифрами: ");

        if (n >= 1) scanf(" %c", &r1);
        if (n >= 2) scanf(" %c", &r2);
        if (n >= 3) scanf(" %c", &r3);
        if (n >= 4) scanf(" %c", &r4);
        if (n >= 5) scanf(" %c", &r5);
        if (n >= 6) scanf(" %c", &r6);
        if (n >= 7) scanf(" %c", &r7);
        if (n >= 8) scanf(" %c", &r8);
        if (n >= 9) scanf(" %c", &r9);

        year = RomanToYear(r1, r2, r3, r4, r5, r6, r7, r8, r9);

        printf("Обычное значение года: %d\n", year);
    }
    else
    {
        printf("Ошибка: количество символов должно быть от 1 до 9\n");
    }

    return 0;
}

int Task1(char c)
{
    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return 1;
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
        return 2;
    default:
        return 0;
    }
}

float Task2(float x, float y, char c)
{
    switch (c)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '^':
        return pow(x, y);
    default:
        return 0;
    }
}

int RomanValue(char c)
{
    switch (c)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int RomanToYear(char c1, char c2, char c3, char c4, char c5,
    char c6, char c7, char c8, char c9)
{
    int v1 = RomanValue(c1);
    int v2 = RomanValue(c2);
    int v3 = RomanValue(c3);
    int v4 = RomanValue(c4);
    int v5 = RomanValue(c5);
    int v6 = RomanValue(c6);
    int v7 = RomanValue(c7);
    int v8 = RomanValue(c8);
    int v9 = RomanValue(c9);

    int result = 0;

    result += v1 < v2 ? -v1 : v1;
    result += v2 < v3 ? -v2 : v2;
    result += v3 < v4 ? -v3 : v3;
    result += v4 < v5 ? -v4 : v4;
    result += v5 < v6 ? -v5 : v5;
    result += v6 < v7 ? -v6 : v6;
    result += v7 < v8 ? -v7 : v7;
    result += v8 < v9 ? -v8 : v8;
    result += v9;

    return result;
}