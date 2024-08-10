#include<stdio.h>

int cost[10][10], visited[10] = {0}, min, mincost = 0;
void input(int num)
{
    int i,j;
    printf("Enter the Cost Matrix:\n");
    for( i=1;i <= num;i++)
    {
        for(j = 1;j <= num;j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
}

void display(int num)
{
    int i, j;
    printf("\nThe entered cost matrix is:\n");
    for( i=1;i <= num;i++)
    {
        for(j = 1;j <= num;j++)
        {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
}

void prims(int num)
{
    int i, j, ne = 1, a, b;
    visited[1] = 1;
    for( i=1;i <= num;i++)
    {
        for(j = 1;j <= num;j++)
        {
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    while(ne < num)
    {
        min = 999;
        for( i=1;i <= num;i++)
        {
            for(j = 1;j <= num;j++)
            {
                if(visited[i] == 1 && visited[j] == 0)
                {
                    if(i != j && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        visited[b] = 1;
        mincost = mincost + min;
        ne++;
        printf("\n(%d -> %d) Cost: %d", a, b, min);
    }
    printf("\n\n\n Minimum Cost = %d", mincost);
}
int main(void)
{
    int num;
    printf("\n\t Prims Algorithm\n");
    printf("\nEnter the number of node:\n");
    scanf("%d", &num);
    input(num);
    display(num);
    prims(num);
}