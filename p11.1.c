#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long int a[100000];

void step_1();
void step_2();
void merge_sort(long int low, long int high);
void merge(long int low, long int mid, long int high);
void generate_random_numbers(long int a[], long int n);
void display(long int n, long int a[]);

int main(void) 
{
    //step_1(); 
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

    merge_sort(0, n - 1);    
    
    printf("After Sorting:\n");
    display(n, a);
}

void generate_random_numbers(long int a[], long int n) {
    time_t t;
    srand((unsigned) time(&t));
    for (long int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

void display(long int n, long int a[]) {
    for (long int i = 0; i < n; i++) {
        printf("%ld\t", a[i]);
    }
    printf("\n\n");
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
        merge_sort(0, n - 1);
        end = clock();
        
        time[it] = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%li, %.6f\n", n, time[it]);

        n += 10000;
        it++;
    }

    printf("\nTotal Time taken=%f seconds\n", (float)(end - start) / CLOCKS_PER_SEC);
}

void merge_sort(long int low, long int high)
{
    if(low < high)
    {
        long int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(long int low, long int mid, long int high) {
    long int i = low, j = mid + 1, k = low;
    long int b[100000]; 

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while (i <= mid) {
        b[k++] = a[i++];
    }

    while (j <= high) {
        b[k++] = a[j++];
    }

    for (i = low; i <= high; i++) {
        a[i] = b[i];
    }
}
