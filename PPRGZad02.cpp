#include <iostream>

void zad1()
{
    int x, y;

    std::cout << "Podaj x: ";
    std::cin >> x;

    std::cout << "Podaj y: ";
    std::cin >> y;

    while (x <= y)
    {
        bool isPrime = true;
        for (int i = 2; i < x; i++)
        {
            if (x % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            std::cout << x << " ";
        x++;
    }
}

void zad2()
{
    int x, y;

    std::cout << "Podaj x: ";
    std::cin >> x;

    std::cout << "Podaj y: ";
    std::cin >> y;

    for (int i = x; i <= y; i++)
    {
        for (int j = x; j <= y; j++)
        {
            int iSum = 0, jSum = 0;

            for (int _i = 1; _i < i; _i++)
                if (i % _i == 0)
                    iSum += _i;

            for (int _j = 1; _j < j; _j++)
                if (j % _j == 0)
                    jSum += _j;

            if (iSum == j && jSum == i)
                printf("(%d,%d) ", i, j);
        }
    }
}

void zad3()
{
    int x, a = 0, b = 1;

    std::cout << "Podaj x: ";
    std::cin >> x;

    if (x < 2)
    {
        printf("F(%d) = %d", x, x);
        return;
    }

    for (int i = 0; i < x; i++)
    {
        int temp = a + b;
        b = a;
        a = temp;
    }

    printf("F(%d) = %d", x, a);
}

int main()
{
    // 1.
    // Napisz program, który wypisze na ekranie wszystkie
    // liczby pierwsze z zakresu.
    
    std::cout << "Wybierz nr. zadania" << std::endl;
    std::cout << "1: Zad. 1" << std::endl;
    std::cout << "2: Zad. 2" << std::endl;
    std::cout << "3: Zad. 3" << std::endl;

    int z;
    std::cin >> z;

    system("cls");

    switch (z)
    {
    case 1:
        zad1();
        break;
    case 2:
        zad2();
        break;
    case 3:
        zad3();
        break;
    default:
        break;
    }
}
