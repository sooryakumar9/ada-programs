#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void step_1();
void step_2();

void quick(long int low, long int high);
int partition(long int low, long int high);
void swap(long int *a, long int *b);

void display(long int n, long int a[]);
void generate_random_numbers(long int a[], long int n);

long int a[100000];

int main(void) 
{
    step_1();  
    step_2(); 
}

void step_1()
{
    long int n;
    printf("Enter the value of n: ");
    scanf("%ld", &n);
    printf("Enter the array: \n");
    for(int i = 0; i < n; i++)
        scanf("%ld", &a[i]);
    
    printf("Before Sorting:\n");
    display(n, a);

    quick(0, n - 1);    
    
    printf("After Sorting:\n");
    display(n, a);
}

void step_2()
{
    long int n = 10000;
    double time[10];
    int it = 0;
    clock_t start, end;
    
    printf("Input Size, Time Complexity\n");

    while (it < 5) {
        generate_random_numbers(a, n);

        start = clock();
        quick(0, n - 1);
        end = clock();
        
        time[it] = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%li, %.6f\n", n, time[it]);

        n += 10000;
        it++;
    }

    printf("\nTotal Time taken=%f seconds\n", (float)(end - start) / CLOCKS_PER_SEC);
}

void generate_random_numbers(long int a[], long int n) {
    time_t t;
    srand((unsigned) time(&t));
    for (long int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

void quick(long int low, long int high) {
    if (low < high) {
        long int j = partition(low, high);
        quick(low, j - 1);
        quick(j + 1, high);
    }
}

int partition(long int low, long int high) {
    long int key = a[low];
    long int i = low + 1;
    long int j = high;
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
    long int temp = *a;
    *a = *b;
    *b = temp;
}

void display(long int n, long int a[]) {
    for(int i = 0; i < n; i++)
        printf("%ld\t", a[i]);
    printf("\n\n");
}
