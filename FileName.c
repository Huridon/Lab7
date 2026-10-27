#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

int Task1(char c);
float Task2(float x, char c, float y);

int Value(char c);
char Next(char prev);
int AddSymbol(int sum, char prev, char cur);

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Task1
    char ch;
    int kind;

    printf("Введите символ: ");
    scanf(" %c", &ch);

    kind = Task1(ch);

    switch (kind)
    {
    case 1:
        printf("Это цифра\n");
        break;
    case 2:
        printf("Это буква\n");
        break;
    default:
        printf("Неизвестный символ\n");
    }

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
        res = Task2(x, op, y);
        printf("=%f\n", res);
        break;
    case '/':
        if (y == 0)
        {
            printf("Ошибка: деление на ноль\n");
        }
        else
        {
            res = Task2(x, op, y);
            printf("=%f\n", res);
        }
        break;
    default:
        printf("Неизвестная операция\n");
    }

    //Домашняя работа:

    char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15;
    int year;

    printf("\nВведите год римскими цифрами: ");
    scanf(" %c", &c1);

    year = AddSymbol(0, ' ', c1);
    c2 = Next(c1);   year = AddSymbol(year, c1, c2);
    c3 = Next(c2);   year = AddSymbol(year, c2, c3);
    c4 = Next(c3);   year = AddSymbol(year, c3, c4);
    c5 = Next(c4);   year = AddSymbol(year, c4, c5);
    c6 = Next(c5);   year = AddSymbol(year, c5, c6);
    c7 = Next(c6);   year = AddSymbol(year, c6, c7);
    c8 = Next(c7);   year = AddSymbol(year, c7, c8);
    c9 = Next(c8);   year = AddSymbol(year, c8, c9);
    c10 = Next(c9);  year = AddSymbol(year, c9, c10);
    c11 = Next(c10); year = AddSymbol(year, c10, c11);
    c12 = Next(c11); year = AddSymbol(year, c11, c12);
    c13 = Next(c12); year = AddSymbol(year, c12, c13);
    c14 = Next(c13); year = AddSymbol(year, c13, c14);
    c15 = Next(c14); year = AddSymbol(year, c14, c15);

    printf("Обычное значение года: %d\n", year);

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


float Task2(float x, char c, float y)
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


int Value(char c)
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


char Next(char prev)
{
    char c;

    if (prev == '\n')
        return '\n';

    scanf("%c", &c);
    return c;
}


int AddSymbol(int sum, char prev, char cur)
{
    int p = Value(prev);
    int v = Value(cur);

    if (p < v)
        return sum + v - 2 * p;

    return sum + v;
}