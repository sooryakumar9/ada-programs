#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void step_1();
void step_2();
void generate_random_numbers(long int a[], long int n);
void selection_sort(long int a[], long int n);
void display(long int n,long int a[]);

int main(void) 
{
    step_1();
    step_2();
}

void step_1()
{
    long int n;
    long int a[100000];
    printf("Enter the value of n:");
    scanf("%ld",&n);
    printf("Enter the array: \n");
    for(int i=0;i<n;i++)
        scanf("%ld",&a[i]);
    printf("Before Sorting:\n");
    display(n,a);
    selection_sort(a,n);    
    printf("After Sorting:\n");
    display(n,a);
}

void step_2()
{
    long int n = 10000;
    long int a[100000];
    double time[10];
    int it = 0;
    clock_t start, end;
    
    printf("Input Size, Time Complexity\n");

    while (it < 5) {
        generate_random_numbers(a, n);
        start = clock();
        selection_sort(a, n);
        end = clock();
        time[it] = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%li, %f\n", n, time[it]);

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

void selection_sort(long int a[], long int n) {
    long int i, j, min, temp;
    for (i = 0; i < n - 1; i++) { 
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;    
    }
}

void display(long int n,long int a[])
{
    for(int i = 0; i < n; i++)
        printf("%ld\t",a[i]);
     printf("\n\n");
}
