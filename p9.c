#include<stdio.h>
#include<stdlib.h>
#include<time.h>

time_t t;

int main(void) {
    long int i,j,min,temp,n=10000,a[100000];
    double tim[10];
    long int it=0;
    clock_t start,s,e;
    srand((unsigned)time(&t));
    printf("Input Size, Time Complexity\n");
    while(it++<5)
    {
        for(i=0;i<n;i++)
            a[i]=rand()%100;
        s=clock();
        for(i=0;i<n-2;i++)
        { 
            min=i;
            for(j=i+1;j<n-1;j++)
                if(a[i]<a[min])
                    min=j;
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;    
        }
        e=clock();
        tim[it]=(double)(e-s);
        printf("%li, %li\n",n,(long int)tim[it]);
        n+=10000;
    }
    printf("\nTime taken=%f\n",(float)(e-s)/(CLOCKS_PER_SEC));
}
// ./a.out>p9.txt
// gnuplot
// plot './p9.txt' using 1:2 with linespoints