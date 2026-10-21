#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

int Task1();
int Task2();

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Task1();
    Task2();

    //Домашняя работа:

    char roman[20];
    int result = 0;
    int current, next;

    printf("\nВведите год римскими цифрами: ");
    scanf("%19s", roman);

    for (int i = 0; roman[i] != '\0'; i++)
    {
        switch (roman[i])
        {
        case 'I': current = 1; break;
        case 'V': current = 5; break;
        case 'X': current = 10; break;
        case 'L': current = 50; break;
        case 'C': current = 100; break;
        case 'D': current = 500; break;
        case 'M': current = 1000; break;
        default: current = 0;
        }

        switch (roman[i + 1])
        {
        case 'I': next = 1; break;
        case 'V': next = 5; break;
        case 'X': next = 10; break;
        case 'L': next = 50; break;
        case 'C': next = 100; break;
        case 'D': next = 500; break;
        case 'M': next = 1000; break;
        default: next = 0;
        }

        result += current < next ? -current : current;
    }

    printf("Обычное значение года: %d\n", result);

    return 0;
}

int Task1()
{
    char c;

    printf("Введите символ: ");
    scanf(" %c", &c);

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
        printf("Это цифра\n");
        break;
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
        printf("Это буква\n");
        break;
    default:
        printf("Неизвестный символ\n");
    }

    return 0;
}

int Task2()
{
    float x, y;
    char c;

    printf("\nВведите выражение (например, 5+3): ");
    scanf("%f%c%f", &x, &c, &y);

    switch (c)
    {
    case '+':
        printf("=%f\n", x + y);
        break;
    case '-':
        printf("=%f\n", x - y);
        break;
    case '*':
        printf("=%f\n", x * y);
        break;
    case '/':
        printf("=%f\n", x / y);
        break;
    case '^':
        printf("=%f\n", pow(x, y));
        break;
    default:
        printf("Неизвестная операция\n");
    }

    return 0;
}