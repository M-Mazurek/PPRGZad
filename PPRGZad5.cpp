#include <iostream>

void zad1_swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int zad1_partition(int arr[], int l, int r)
{
    int p = arr[r];
    int i = (l - 1);

    for (int j = l; j < r; j++)
    {
        if (arr[j] <= p)
        {
            i++;
            zad1_swap(&arr[i], &arr[j]);
        }
    }
    zad1_swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}

void zad1_qsort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = zad1_partition(arr, l, r);
        zad1_qsort(arr, l, p - 1);
        zad1_qsort(arr, p + 1, r);
    }
}

template <unsigned int XA, unsigned int YA, unsigned int XB, unsigned int YB>
void zad2_matrices(int const (&arr1)[XA][YA], int const (&arr2)[XB][YB])
{
    if (XA != YB)
        return;

    int res[XB][YA];

    for (int x = 0; x < XA; x++)
    {
        for (int y = 0; y < YB; y++)
        {
            res[x][y] = 0;
            for (int i = 0; i < YA; i++)
                res[x][y] += arr1[x][i] * arr2[i][y];
        }
    }

    for (int x = 0; x < XA; x++)
    {
        for (int y = 0; y < YB; y++)
        {
            std::cout << res[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

int zad3_seq_sum(float a1, float r, int n)
{
    if (n < 1)
        return 0;

    std::cout << "A:" << std::endl;
    int sum_a(a1), cur_a(a1);

    std::cout << cur_a << " ";

    for (int i = 0; i < n - 1; i++)
    {
        cur_a += r;
        sum_a += cur_a;
        std::cout << cur_a << " ";
    }
    std::cout << std::endl << sum_a << std::endl;

    std::cout << "G:" << std::endl;
    int sum_g(a1), cur_g(a1);

    std::cout << cur_g << " ";

    for (int i = 0; i < n - 1; i++)
    {
        cur_g *= r;
        sum_g += cur_g;
        std::cout << cur_g << " ";
    }
    std::cout << std::endl << sum_g << std::endl;
}

int main()
{
    std::cout << "Zad 1." << std::endl;

    int arr[] = { 0, -3, 3, 4, -5, 6, 2, -2};

    for (int i : arr)
        std::cout << i << " ";

    std::cout << std::endl;

    zad1_qsort(arr, 0, sizeof(arr) / sizeof(arr[0]));

    for (int i : arr)
        std::cout << i << " ";

    std::cout << std::endl << "Zad 2." << std::endl;

    int arr1[2][3] =
    {
        { 3, 5, 2},
        {1, 0, 3}
    };

    int arr2[3][2] =
    {
        { 2, 3},
        {1, 2},
        {0, 2}
    };

    zad2_matrices(arr1, arr2);

    std::cout << "Zad 3-2." << std::endl;

    zad3_seq_sum(13, -2, 3);

    return 0;
}
