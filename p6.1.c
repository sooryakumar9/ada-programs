#include <stdio.h>

void knapsack(int n, int m, int w[20], int p[20], int v[20][20]);
void print_optimalsoln(int n, int m, int w[20], int p[20], int v[20][20]);
int max(int a, int b);

int main() {
    int p[20], w[20], v[20][20], n, m, i, j;

    printf("Enter the number of objects:\n");
    scanf("%d", &n);

    printf("Enter the knapsack capacity:\n");
    scanf("%d", &m);

    printf("Enter the weights of %d objects:\n", n);
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter the profit of %d objects:\n", n);
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    knapsack(n, m, w, p, v);

    printf("Output is:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }

    print_optimalsoln(n, m, w, p, v);

    return 0;
}

void knapsack(int n, int m, int w[20], int p[20], int v[20][20]) {
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i] > j)
                v[i][j] = v[i - 1][j];
            else {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
        }
    }
}

void print_optimalsoln(int n, int m, int w[20], int p[20], int v[20][20]) {
    int i, j, x[10];
    int opti = 0;

    for (i = 0; i <= n; i++) {
        x[i] = 0;
    }

    i = n;
    j = m;
    while (i != 0 && j != 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[i] = 1;
            j = j - w[i];
        }
        i = i - 1;
    }

    printf("Items selected:\n");
    for (i = 1; i <= n; i++)
        if (x[i] == 1) {
            printf("%d\t", i);
            opti = opti + p[i];
        }

    printf("\nOptimal solution is %d\n", opti);
}

int max(int a, int b) {
    return a > b ? a : b;
}
