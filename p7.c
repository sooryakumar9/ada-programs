#include<stdio.h>

void display(int n,float w[],float p[],float r[])
{
    printf("\nItems\tWeight\tProfit\tRatio\n");
    for(int i=0;i<n;i++)
        printf("%d\t%.2f\t%.2f\t%.2f\n",i,w[i],p[i],r[i]);
}

void knapsack(int n,float w[],float p[],float capacity)
{
    float x[20],rem_cap,max_pro=0;
    int i,k;
    rem_cap=capacity;
    for(i=0;i<n;i++)
        x[i]=0.0;
    for(i=0;i<n;i++)
    {
        if(w[i]>rem_cap)
            break; 
        else
        {
            x[i]=1;
            rem_cap-=w[i];
            max_pro+=p[i];
        }
    }
    printf("the result of 0/1 knapsack is:\n");
    for(k=0;k<n;k++)
        printf("%.2f\t",x[k]);
    printf("maximum profit is %.2f\n",max_pro);
    printf("the result vector of fractional knapsack is:\n");
    if(i<n)
    {
        x[i]=(rem_cap/w[i]);
        max_pro=max_pro+(x[i]*p[i]);
    }
    for(i=0;i<n;i++)
        printf("%.2f\t",x[i]);
    printf("maximum profit is %.2f\n",max_pro);
}

int main() {
    float w[20],p[20],r[20],capacity,temp;
    int i,j,k,n;
    printf("enter the number of objects:");
    scanf("%d",&n);
    printf("enter the weight and profit\n");
    for(i=0;i<n;i++)
        scanf("%f%f",&w[i],&p[i]);
    for(i=0;i<n;i++)
        r[i]=(p[i]/w[i]);
    printf("enter the capacity of knapsack:");
    scanf("%f",&capacity);
    printf("before sorted:\n");
    display(n,w,p,r);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(r[j]<r[j+1])
            {
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    printf("after sorted:\n");
    display(n,w,p,r);
    knapsack(n,w,p,capacity);
    return 0;
}