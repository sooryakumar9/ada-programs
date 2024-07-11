#include<stdio.h>
#define max 50
int maxi(int a, int b)
{
   return (a>b)?a:b;
}
int knap(int values[],int weights[],int n,int capacity)
{
    int i,w,v[max+1][capacity+1];
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=capacity;w++)
        {
            if(i==0 || w==0)
                v[i][w]=0;
            else if(weights[i]<=w)
                v[i][w]=maxi(values[i]+v[i-1][w-weights[i]],v[i-1][w]);
            else
                v[i][w]=v[i-1][w];
        } 
    }
   return v[n][capacity];
}
int main() {
    int values[max],weights[max],capacity,i,n;
    printf("enter the number of items and capacity:\n");
    scanf("%d%d",&n,&capacity);
    printf("enter the values:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&values[i]);
    printf("enter the weights:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&weights[i]);
    int res=knap(values,weights,n,capacity);
    printf("the result of the 0-1 knapsack is: %d\n",res);
    return 0;
}