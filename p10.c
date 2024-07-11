#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quick(long int low, long int high);
int partition(long int low, long int high);
void swap(long int *a, long int *b);

long int a[100000], i, j, temp, n, key;

void quick(long int low, long int high) {
    if (low < high) {
        j = partition(low, high);
        quick(low, j - 1);
        quick(j + 1, high);
    }
}

int partition(long int low, long int high) {
    key = a[low];
    i = low + 1;
    j = high;
    while (1) {
        while (i < high && key >= a[i])
            i++;
        while (key < a[j])
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
        else {
            swap(&a[j], &a[low]);
            return j;
        }
    }
}

void swap(long int *a, long int *b) {
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    long int n = 10000, it = 0;
    clock_t s, e;
    double tim1[5]; 

    srand((unsigned)time(NULL));
    printf("Input Size, Time Complexity\n");
    while (it < 5) { 
        for (int i = 0; i < n; i++)
            a[i] = rand() % 100;
        
        s = clock();
        quick(0, n - 1);
        e = clock();
        
        tim1[it] = (double)(e - s) / CLOCKS_PER_SEC; 
        
        printf("%li, %.6f\n", n, tim1[it]); 
        n += 10000;
        it++;
    }

    return 0;
}

// ./a.out>p10.txt
// gnuplot
// plot './p10.txt' using 1:2 with linespoints