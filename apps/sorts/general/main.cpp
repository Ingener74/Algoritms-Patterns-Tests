/*
 * main.cpp
 *
 *  Created on: Jun 15, 2014
 *      Author: ingener
 */

#include <iostream>

using namespace std;

void randa(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] = 100 * (rand() / double(RAND_MAX));
    }
}

void printa(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ", ";
    }
    cout << endl;
}

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int min = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[min]) min = j;
        }
        if (min != i)
        {
            swap(a[min], a[i]);
        }
    }
}

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

void gnome_sort(int a[], int N)
{
    int i = 0;
    while (i < N)
    {
        if (i == 0 || a[i - 1] <= a[i]) ++i;
        else
        {
            int T = a[i];
            a[i] = a[i - 1];
            a[i - 1] = T;
            --i;
        }
    }
}

void insertion_sort(int a[], int N)
{
    for (int i = 1; i < N; ++i)
    {
        int cur = a[i];
        int I = i - 1;
        while (I >= 0 && a[I] > cur)
        {
            a[I + 1] = a[I];
            a[I] = cur;
            I--;
        }
    }
}

void shell_sort(int a[], int N)
{
    for (int d = N / 2; d > 0; d /= 2)
    {
        for (int i = d; i < N; ++i)
        {
            for (int j = i; j >= d && a[j - d] > a[j]; j -= d)
                swap(a[j], a[j - d]);
        }
    }
}

void shift_down(int a[], int i, int j)
{
    int left = 2 * i + 1;
    int right = left + 1;
    int max_child = left;
    while (max_child < j)
    {
        if (right < j)
        {
            if (a[left] < a[right])
            {
                max_child = right;
            }
        }
        if (a[i] < a[max_child])
        {
            swap(a[i], a[max_child]);
        }
        else break;
        i = max_child;

        left = 2 * i + 1;
        right = left + 1;
        max_child = left;
    }
}
void heap_sort(int a[], int N)
{
    for (int i = N / 2 - 1; i >= 0; --i)
    {
        shift_down(a, i, N);
    }
    for (int i = N - 1; i > 0; --i)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        shift_down(a, 0, i);
    }
}

void quick_sort(int a[], int f, int l)
{
    int i = f, j = l, x = a[(f + l) / 2];

    do
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;

        if (i <= j)
        {
            if (i < j) swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    while (i <= j);
    if (i < l) quick_sort(a, i, l);
    if (f < j) quick_sort(a, f, j);
}

int main(int argc, char **argv)
{
    try
    {
        bool b = true;

        cout << "check boolalpha: b = " << boolalpha << b << endl;

        const int N = 60;
        int unsorted[N];

        {
            cout << "selection sort" << endl;
            randa(unsorted, N);

            printa(unsorted, N);

            cout << endl;

            selection_sort(unsorted, N);

            printa(unsorted, N);
        }

        {
            cout << "bubble sort" << endl;
            randa(unsorted, N);

            printa(unsorted, N);

            cout << endl;

            bubble_sort(unsorted, N);

            printa(unsorted, N);
        }

        {
            cout << "gnome sort" << endl;
            randa(unsorted, N);

            printa(unsorted, N);

            cout << endl;

            gnome_sort(unsorted, N);

            printa(unsorted, N);
        }

        {
            cout << "insertion sort" << endl;
            randa(unsorted, N);

            printa(unsorted, N);

            cout << endl;

            insertion_sort(unsorted, N);

            printa(unsorted, N);
        }

        {
            cout << "shell sort" << endl;
            randa(unsorted, N);

            printa(unsorted, N);

            cout << endl;

            shell_sort(unsorted, N);

            printa(unsorted, N);
        }

        {
            cout << "heap sort" << endl;
            randa(unsorted, N);

            printa(unsorted, N);

            cout << endl;

            heap_sort(unsorted, N);

            printa(unsorted, N);
        }

        {
            cout << "quick sort" << endl;
            randa(unsorted, N);

            printa(unsorted, N);

            cout << endl;

            quick_sort(unsorted, 0, N - 1);

            printa(unsorted, N);
        }

    }
    catch (exception const & e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}

