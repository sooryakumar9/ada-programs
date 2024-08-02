#include <stdio.h>

int union1(int i, int j, int parent[]);
int find(int i, int parent[]);
int Kruskal(int cost[10][10], int n);

int main() {
    int cost[10][10];
    int i, j, n, mincost = 0;

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

    printf("Kruskal's MST edges and cost are:\n");
    mincost = Kruskal(cost, n);
    printf("\nMST cost is %d\n", mincost);
}

int Kruskal(int cost[10][10], int n) {
    int parent[10], ne = 1, mincost = 0;
    int i, j, min, a, b, u, v;

    for (i = 1; i <= n; i++) {
        parent[i] = 0;
    }

    while (ne < n) {
        min = 999; // Initialize to a large number
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u, parent);
        v = find(v, parent);

        if (union1(u, v, parent)) {
            printf("Edge %d:(%d, %d) cost:%d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999; // Mark as visited
    }

    return mincost;
}

int find(int i, int parent[]) {
    while (parent[i] != 0) {
        i = parent[i];
    }
    return i;
}

int union1(int i, int j, int parent[]) {
    if (i != j) {
        parent[j] = i;
        return 1;
    } else {
        return 0;
    }
}
