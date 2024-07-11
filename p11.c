#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long int a[100000],b[100000];
long int temp,i,j,n,key,low,high,mid,h,k,num;

time_t t;

void merge(long int,long int,long int);

void merge_sort(long int low,long int high)
{
    long int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}

void merge(long int low,long int mid,long int high)
{
    long int h,i,j,k;
    long int b[100000];
    h=low;
    i=low;
    j=mid+1;
    while((h<=mid) && (j<=high))
    {
        if(a[h]<a[j])
        {
            b[i]=a[h];
            h++; 
        }
        else 
        {
            b[i]=a[j];
            j++; 
        }
        i++; 
    }
    if(h>mid) 
    {
        for(k=j;k<=high;k++)
        {
            b[i]=a[k];
            i++; 
        }
    }
    else 
    {
        for(k=h;k<=mid;k++)
        {
            b[i]=a[k];
            i++; 
        }
    }
    for(k=low;k<=high;k++)
    {
        a[k]=b[k]; 
    }
}

int main(void) {
    clock_t s,e;
    long int n=10000;
    long int it=0;
    double tim1[10];
    srand((unsigned)time(&t));
    printf("Input Size, Time Complexity\n");
    while(it++<5)
    {
        for(i=0;i<n;i++)
            a[i]=rand()%100;
        s=clock();
        merge_sort(0,n-1);
        e=clock();
        tim1[it]=(double)(e-s);
        printf("%li, %li\n",n,(long int)(tim1[it]));
        n+=10000;
    }
}

// ./a.out>p11.txt
// gnuplot
// plot './p11.txt' using 1:2 with linespoints