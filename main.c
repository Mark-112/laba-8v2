#include <stdio.h>
#include <stdlib.h>

int quicksort(int *n, int l, int r, int size)
{
    int p;
    int l1 = l;
    int r1 = r;
    p = n[l];
    while (l < r)
    {
        while ((n[r] >= p) && (l < r))
        {
            r--;
        }
        n[size]++;
        if (l != r)
        {
            n[l] = n[r];
            l++;
            n[size+1]++;
        }
        while ((n[l] <= p) && (l < r))
        {
            l++;
        }
        n[size] ++;
        if (l != r)
        {
            n[r] = n[l];
            r--;
            n[size+1]++;
        }
    }
    n[l] = p;
    p = l;
    l = l1;
    r = r1;
    if (l < p)
        quicksort(n, l, p - 1, size);
    if (r > p)
        quicksort(n, p + 1, r, size);
}

int main()
{

    int n, c, i, j, sravn, perest;
    sravn = 0;
    perest = 0;
    c = 0;
    printf("vvedite chislo elementov massiva\n");
    scanf("%d", &n);
    int a[n], b[n+2];
    printf("vvedite massiv\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    b[n] = 0; // тут будут лежать сравнения у quicksort
    b[n+1] = 0; // а тут перестановки для него

    //пузырек
    for (j = 0; j < n-1; j++)
    {
        for (i = n - 2; i >= j; i--)
        {
            if (a[i] > a[i+1])
            {
                c = a[i];
                a[i] = a[i+1];
                a[i+1] = c;
                perest += 1;
            }
            sravn += 1;
        }
    }

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nkolvo sravneniy v bubble_sorted: %d\n", sravn);
    printf("kolvo perestanovok v bubble_sorted: %d\n", perest);
    // конец пузырька


    sravn = 0;
    perest = 0;

    // Quicksort
    quicksort(b, 0, n-1, n);
    for (i = 0; i <n; i++)
        printf("%d ", b[i]);
    printf("\nkolvo sravneniy v quicksort: %d\n", b[n]);
    printf("kolvo perestanovok v quicksort: %d\n", b[n+1]);
    // конец quicksort

    return 0;
}
