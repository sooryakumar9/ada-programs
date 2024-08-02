#include <stdio.h>

int n, a[10][10], p[10][10];

int min(int a, int b) {
    return a < b ? a : b;
}

void floyd() {
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}

int main() {
    int i, j;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            p[i][j] = a[i][j];
        }

    floyd();

    printf("All pair shortest paths are:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (p[i][j] == 999)
                printf("INF\t");
            else
                printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    return 0;
}
