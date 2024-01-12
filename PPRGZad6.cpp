/*
 * 2.8: Da rade i jest zaimplementowane przy pomocy petli while.
 */
#include <iostream>
#include <cmath>

struct Punkt {
public:
    Punkt(double x, double y) {
        this->x = x;
        this->y = y;
    }
    double x, y;
};

struct Osoba {
public:
    Osoba(std::string imie, std::string nazwisko, unsigned int wiek) {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->wiek = wiek;
    }
    Osoba() = default;
    std::string imie, nazwisko;
    unsigned int wiek = 0;
};

double Zad1_Odleglosc(Punkt a, Punkt b) {
    double x = b.x - a.x;
    double y = b.y - a.y;

    return sqrt(x*x + y*y);
}

void Zad1() {
    Punkt a(5.0, -5.0), b(3.0, -7.0);
    std::cout << Zad1_Odleglosc(a, b);
}

// courtesy of ChatGPT :)
Osoba Zad2_TestArr[] = {{"Jan", "Kowalski", 24}, {"Adam", "Nowak", 28}, {"Piotr", "Wisniewski", 19}, {"Michal", "Dabrowski", 22}, {"Krzysztof", "Lewandowski", 30}, {"Marcin", "Wojcik", 18}, {"Tomasz", "Kaminski", 25}, {"Pawel", "Kowalczyk", 27}, {"Jakub", "Zielinski", 20}, {"Mateusz", "Szymanski", 29}, {"Bartosz", "Wozniak", 26}, {"Marek", "Kozlowski", 17}, {"Wojciech", "Jankowski", 23}, {"Igor", "Mazur", 21}, {"Grzegorz", "Krawczyk", 30}, {"Karol", "Piotrowski", 18}, {"Rafal", "Grabowski", 29}, {"Sebastian", "Zajac", 22}, {"Artur", "Pawlowski", 25}, {"Dawid", "Michalak", 16}, {"Kamil", "Nowicki", 28}, {"Lukasz", "Wrobel", 19}, {"Adrian", "Majewski", 22}, {"Dominik", "Olszewski", 30}, {"Mikolaj", "Stepien", 18}, {"Kacper", "Dudek", 25}, {"Alan", "Blaszczyk", 27}, {"Filip", "Sikora", 20}, {"Szymon", "Konieczny", 29}, {"Radoslaw", "Glowacki", 26}, {"Ivan", "Witkowski", 17}, {"Denis", "Walczak", 23}, {"Eryk", "Sobolewski", 21}, {"Hubert", "Lis", 30}, {"Oskar", "Malinowski", 18}, {"Damian", "Czarnecki", 29}, {"Tadeusz", "Zawadzki", 22}, {"Hubert", "Sadowski", 25}, {"Blazej", "Witkowski", 16}, {"Tymon", "Chmielewski", 28}, {"Olaf", "Urbanski", 19}, {"Krystian", "Karpinski", 22}, {"Bruno", "Baran", 30}, {"Nikodem", "Pajak", 18}, {"Iwo", "Cieslak", 25}, {"Dorian", "Ostrowski", 27}, {"Alan", "Rutkowski", 20}, {"Ksawery", "Lipinski", 29}, {"Maciej", "Sokolowski", 26}, {"Seweryn", "Szewczyk", 17}, {"Konrad", "Gajewski", 23}, {"Witold", "Janowski", 21}, {"Maksymilian", "Mazurek", 30}, {"Kornel", "Sobczyk", 18}, {"Teodor", "Rybak", 29}, {"Mieszko", "Bielecki", 22}, {"Fryderyk", "Marcinkowski", 25}, {"Leon", "Nowacki", 16}};

std::string Zad2_OsobaStr(Osoba& o) {
    return o.imie + " " + o.nazwisko + " " + std::to_string(o.wiek);
}

void Zad2_Swap(Osoba& a, Osoba& b) {
    Osoba t = a;
    a = b;
    b = t;
}

enum Zad2_CmpRes {
    Identical,
    Ascending,
    Descending
};

Zad2_CmpRes Zad2_StrCmp(std::string a, std::string b) {
    if (a == b)
        return Identical;

    unsigned int n = a.length();
    bool isALonger = true;

    if (b.length() > n) {
        isALonger = false;
        n = b.length();
    }

    for (int i = 0; i < n; i++) {
        if (a[i] < b[i])
            return Ascending;
        else if (a[i] > b[i])
            return Descending;
    }
}

void Zad2_TabSort(Osoba tab[], unsigned int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            bool isNextSmaller = true;
            Zad2_CmpRes nameCmp, lNameCmp;

            nameCmp = Zad2_StrCmp(tab[j].imie, tab[j + 1].imie);
            if (nameCmp == Descending)
                goto Swap;
            if (nameCmp == Ascending)
                continue;

            lNameCmp = Zad2_StrCmp(tab[j].nazwisko, tab[j + 1].nazwisko);
            if (lNameCmp == Descending)
                goto Swap;
            if (lNameCmp == Ascending)
                continue;

            if (tab[j].wiek > tab[j + 1].wiek)
                goto Swap;

            continue;

            Swap:
            Zad2_Swap(tab[j], tab[j + 1]);
            swapped = true;
        }

        if (!swapped)
            break;
    }
}

void Zad2_List(Osoba tab[], unsigned int n, unsigned int a, unsigned int b, unsigned int m) {
    std::cout << std::endl << "Posortowac? (1: Tak): ";
    std::string s;
    std::cin >> s;

    if (s == "1")
        Zad2_TabSort(tab, n);

    std::cout << std::endl << "Osoby w tablicy:" << std::endl;
    for (unsigned int i = a; i <= b; i++)
        if (tab[i].wiek <= m)
            std::cout << i << ". " << Zad2_OsobaStr(tab[i]) << std::endl;

    system("pause");
}

void Zad2_List(Osoba tab[], unsigned int n) {
    Zad2_List(tab, n, 0, n - 1, std::numeric_limits<unsigned int>::max());
}

Osoba* Zad2_CreateTable(Osoba tab[], unsigned int& n) {
    int _n;
    do {
        std::cout << std::endl << "Podaj wielkosc tablicy: ";
        std::cin >> _n;
    } while (_n <= 0);
    n = _n;
    tab = new Osoba[n];

    for (int i = 0; i < n; i++) {
        std::cout << i << "." << std::endl;
        tab[i] = Osoba();
        std::cout << "\tPodaj imie: ";
        std::cin >> tab[i].imie;
        std::cout << "\tPodaj nazwisko: ";
        std::cin >> tab[i].nazwisko;
        std::cout << "\tPodaj wiek: ";
        std::cin >> tab[i].wiek;
    }
    std::cout << std::endl;
    return tab;
}

void Zad2_AgeQuery(Osoba tab[], unsigned int a, unsigned int b, unsigned int n) {
    std::cout << "Podaj maksymalny wiek (0 dla wszystkich): ";
    unsigned int m;
    std::cin >> m;
    Zad2_List(tab, n, a, b, m == 0 ? std::numeric_limits<unsigned int>::max() : m);
}


void Zad2_RangeQuery(Osoba tab[], unsigned int n) {
    unsigned int a, b;
    std::cout << "Podaj wycinek tablicy (i max = " << n - 1 << ")" << std::endl;

    Input:
    std::cout << "Podaj a: ";
    std::cin >> a;
    std::cout << "Podaj b: ";
    std::cin >> b;
    std::cout << std::endl;

    if (a > b || a >= n || b >= n) {
        std::cout << "Niepoprawny zakres (" << a << ", " << b << ")" << std::endl;
        goto Input;
    }

    Zad2_AgeQuery(tab, a, b, n);
}

void Zad2_ListQuery(Osoba tab[], unsigned int n) {
    if (n == 0) {
        std::cout << std::endl << "Tablica jest pusta." << std::endl;
        system("pause");
        return;
    }

    std::cout << std::endl << "Wypisz: " << std::endl;
    std::cout << "1. Wszystkich" << std::endl;
    std::cout << "2. Wybranych" << std::endl;
    std::cout << "3. Powrot do menu" << std::endl;

    std::string s;
    std::cin >> s;

    switch (s[0]) {
        case '1':
            Zad2_List(tab, n);
            break;
        case '2':
            Zad2_RangeQuery(tab, n);
            break;
        default:
            return;
    }
}

void Zad2() {;
    unsigned int n(0);
    auto tab = new Osoba[0];

    while (true) {
        std::cout << "Wybierz jedna z ponizszych opcji: " << std::endl;
        std::cout << "1. Stworz nowa tablice" << std::endl;
        std::cout << "2. Zaladuj tablice testowa" << std::endl;
        std::cout << "3. Wypisz tablice" << std::endl;
        std::cout << "4. Wyjdz" << std::endl;

        std::string s;
        std::cin >> s;
        switch (s[0]) {
            case '1':
                tab = Zad2_CreateTable(tab, n);
                break;
            case '2':
                tab = Zad2_TestArr;
                n = sizeof(Zad2_TestArr)/sizeof(Osoba);
                std::cout << "Pomyslnie zaladowano tablice testowa.";
                break;
            case '3':
                Zad2_ListQuery(tab, n);
                break;
            case '4':
                return;
        }
    }
}

int main() {
    std::cout << "Podaj nr. zadania: ";
    switch (getchar()) {
        case '1':
            Zad1();
            break;
        case '2':
            Zad2();
            break;
    }
    return 0;
}
