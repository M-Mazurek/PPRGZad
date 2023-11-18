#include <iostream>
#include <chrono>
#include <cmath>

int zad1_is_cube(int a)
{
    for (int i = 2; i < a / 3; i++)
        if (a == i * i * i)
            return true;

    return false;
}

long long zad2_nwt_rec(long long n, unsigned long long k)
{
    return k == 0 || k == n ?
        1 :
        (zad2_nwt_rec(n - 1, k - 1) + zad2_nwt_rec(n - 1, k));
}

long long zad2_nwt_itr(long long n, unsigned long long k)
{
    long long C[n + 1][k + 1];

    for (long long i = 0; i <= n; i++)
    {
        for (long long j = 0; j <= (i < k ? i : k); j++)
        {
            if (j == 0 || i == j)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

long long zad2_euc_rec(long long a, long long b)
{
    if (b == 0)
        return a;

    return zad2_euc_rec(b, a % b);
}

long long zad2_euc_itr(long long a, long long b)
{
    long long t;
    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

unsigned int zad3_area(unsigned int a)
{
    return a * a;
}

unsigned int zad3_area(unsigned int a, unsigned int b)
{
    return a * b;
}

double zad3_area(unsigned int a, unsigned int b, unsigned int c)
{
    double p = static_cast<double>(a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}


int main()
{
    printf("Zad 1:\n%d %d\n\n", zad1_is_cube(100), zad1_is_cube(27));

    // rekurencja szybsza jedynie dla malych wartosci tj. np. (3, 2)

    long long n(3), k(2);

    printf("Zad 2:\n(%lld, %lld) nwt:\n", n, k);

    auto bfr_nwt_rec = std::chrono::high_resolution_clock::now();
    long long nwt_rec = zad2_nwt_rec(n, k);
    auto aft_nwt_rec = std::chrono::high_resolution_clock::now();
    auto time_nwt_rec = std::chrono::duration_cast<std::chrono::nanoseconds>(aft_nwt_rec - bfr_nwt_rec).count();

    printf("\trec: %lld (%lld ns)\n", nwt_rec, time_nwt_rec);

    auto bfr_nwt_itr = std::chrono::high_resolution_clock::now();
    long long nwt_itr = zad2_nwt_itr(n, k);
    auto aft_nwt_itr = std::chrono::high_resolution_clock::now();
    auto time_nwt_itr = std::chrono::duration_cast<std::chrono::nanoseconds>(aft_nwt_itr - bfr_nwt_itr).count();

    printf("\titr: %lld (%lld ns)\n", nwt_itr, time_nwt_itr);

    // czas bardzo zblizony nawet dla wiekszych liczb

    long long a(100233282352), b(40334623532466);

    printf("(%lld %lld) euc:\n", a, b);

    auto bfr_euc_rec = std::chrono::high_resolution_clock::now();
    long long euc_rec = zad2_euc_rec(a, b);
    auto aft_euc_rec = std::chrono::high_resolution_clock::now();
    auto time_euc_rec = std::chrono::duration_cast<std::chrono::nanoseconds>(aft_euc_rec - bfr_euc_rec).count();

    printf("\trec: %lld (%lld ns)\n", euc_rec, time_euc_rec);

    auto bfr_euc_itr = std::chrono::high_resolution_clock::now();
    long long euc_itr = zad2_euc_itr(a, b);
    auto aft_euc_itr = std::chrono::high_resolution_clock::now();
    auto time_euc_itr = std::chrono::duration_cast<std::chrono::nanoseconds>(aft_euc_itr - bfr_euc_itr).count();

    printf("\titr: %lld (%lld ns)\n\n", euc_itr, time_euc_itr);

    printf("Zad. 3:\n%d\n%d\n%f2", zad3_area(4), zad3_area(4, 6), zad3_area(5, 4, 2));

    return 0;
}
