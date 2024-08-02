#include <stdio.h>

int cost[10][10];
int i, j, n, mincost = 0;

int Prims(int cost[10][10], int n);

int main() {
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("The entered cost matrix is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    printf("Prim's MST edges and cost are:\n");
    mincost = Prims(cost, n);
    printf("\nMST cost is %d\n", mincost);
    printf("----------\n");

    return 0;
}

int Prims(int cost[10][10], int n) {
    int nearV[10], t[10][3], u = 0, i, j, k, mincost = 0;

    for (i = 2; i <= n; i++) {
        nearV[i] = 1;
    }
    nearV[1] = 0;

    for (i = 1; i < n; i++) {
        int min = 999;
        for (j = 1; j <= n; j++) {
            if (nearV[j] != 0 && cost[j][nearV[j]] < min) {
                min = cost[j][nearV[j]];
                u = j;
            }
        }

        t[i][1] = u;
        t[i][2] = nearV[u];
        mincost += min;
        nearV[u] = 0;

        for (k = 1; k <= n; k++) {
            if (nearV[k] != 0 && cost[k][nearV[k]] > cost[k][u]) {
                nearV[k] = u;
            }
        }

        printf("%d) min edge is (%d, %d) and cost is %d\n", i, t[i][1], t[i][2], min);
    }

    return mincost;
}
