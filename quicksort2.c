#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(double a[], int first, int last)
{
    int i, j;
    double x, t;

    x = a[(first + last) / 2];
    i = first;
    j = last;
    for ( ; ; ) {
        while (a[i] < x) i++;
        while (x < a[j]) j--;
        if (i >= j) break;
        t = a[i];  a[i] = a[j];  a[j] = t;
        i++;  j--;
    }
    if (first < i - 1) quicksort(a, first, i - 1);
    if (j + 1 < last) quicksort(a, j + 1, last);
}

#define N 300000

int main(void)
{
    int i, n;
    double t1, t2, a[N];

    srand(time(NULL));
   for (n = 0; n <= N; n += 5000) {
        for (i = 0; i < n; i++) {
            a[i] = rand() / (RAND_MAX + 1.0);
        }
         t1 = clock();
         quicksort(a, 0, n-1);
         t2 = clock();
         printf("%d,%g\n", n, (t2 - t1) / CLOCKS_PER_SEC);
    }
        
    return 0;
}