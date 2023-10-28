#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

/// <summary>
/// Oblicz sumê ci¹gu artymetycznego z pierwszego elementu,
/// ró¿nicy oraz liczby elementów.
/// </summary>
void zad1()
{
    int a1(0), r(0), n(0), s(0);

    std::cout << "Podaj 1-szy element ciagu: ";
    std::cin >> a1;

    std::cout << "Podaj roznice ciagu: ";
    std::cin >> r;

    std::cout << "Podaj dlugosc ciagu: ";
    std::cin >> n;

    std::string str = "{";

    int c = a1;

    for (int i = 0; i < n; s += c, c += r, i++)
    {
        str.append(" ");
        str.append(std::to_string(c));
    }

    str.append(" }");

    system("cls");

    printf("a1 = %d, r = %d, n = %d", a1, r, n);

    std::cout << std::endl 
        << std::endl << str << ", S = " << s;
}

/// <summary>
/// Wylosuj has³o i sprawdzaj czy u¿ytkownik je zgad³.
/// </summary>
void zad2()
{
    srand(time(NULL));

    const char* chars = "abcdefghijklmnopqrstuvwyxzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int charCount = strlen(chars);

    int passLength(3);

    std::cout << "Podaj dlugosc hasla (min. 3): ";
    std::cin >> passLength;

    if (passLength < 3)
        passLength = 3;

    std::string pass = "";

    for (int i = 0; i < passLength; i++)
        pass += chars[rand() % charCount];

    std::cout << pass;

    std::string guess;
    int guesses(0);

    do
    {
        std::cout << "Liczba prob: " << guesses 
            << std::endl << "Podaj haslo: ";
        std::cin >> guess;
        guesses++;
    } while (pass.compare(guess) != 0);

    std::cout << "Zgadles haslo! - " << pass;
}

/// <summary>
/// Kamieñ, papier, no¿yce.
/// </summary>
void zad3()
{
    const std::string names[3] =
    {
        "Papier",
        "Kamien",
        "Nozyce"
    };

    srand(time(NULL));

    int winningScore(1);

    std::cout << "Podaj ilosc punktow do wygranej: ";
    std::cin >> winningScore;

    if (winningScore < 1)
        winningScore = 1;

    int playerScore(0), aiScore(0), curRound(1);

    system("cls");

    while (playerScore < winningScore && 
        aiScore < winningScore)
    {
        int playerChoice(0);
        printf("RUNDA %d - %d : %d  (%d)",
            curRound++, playerScore, aiScore, winningScore);
        std::cout << std::endl << "Wybierz:" << std::endl
            << "[1] Papier" << std::endl
            << "[2] Kamien" << std::endl
            << "[3] Nozyce" << std::endl;

        std::cin >> playerChoice;
        std::cout << std::endl;

        if (playerChoice > 3 || playerChoice < 1)
            playerChoice = 1;

        playerChoice--;
        int aiChoice = rand() % 3;

        int diff = aiChoice - playerChoice;

        switch (diff)
        {
        case 1:
        case -2:
            std::cout << names[playerChoice]
                << " > "
                << names[aiChoice];
            playerScore++;
            break;
        case -1:
        case 2:
            std::cout << names[playerChoice]
                << " < "
                << names[aiChoice];
            aiScore++;
            break;
        default:
            std::cout << names[playerChoice]
                << " = "
                << names[aiChoice];
            break;
        }

        std::cin;
        std::cout << std::endl << std::endl;
    }

    std::cout << "----------------------" << std::endl;

    if (playerScore > aiScore)
    {
        std::cout << "Gracz wygral!" << std::endl;
        return;
    }

    std::cout << "Komputer wygral!" << std::endl;
}

int main()
{
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