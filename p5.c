#include<stdio.h>

void read_matrix(int n, int a[10][10]) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &a[i][j]);
}

void find_indegree(int n, int a[10][10], int indegree[]) {
    int i, j, sum;
    for(j=0; j<n; j++) {
        sum = 0;
        for(i=0; i<n; i++)
            sum += a[i][j];
        indegree[j] = sum;
    }
}

void topo(int n, int a[10][10]) {
    int top, i, j, u, k, v, t[10], indegree[10], s[10];
    find_indegree(n, a, indegree);
    top = -1;
    k = 0;
    for(i = 0; i < n; i++)
        if(indegree[i] == 0)
            s[++top] = i;

    while(top != -1) {
        u = s[top--];
        t[k++] = u;
        for(v = 0; v < n; v++) {
            if(a[u][v] == 1) {
                indegree[v]--;
                if(indegree[v] == 0)
                    s[++top] = v;
            }
        }
    }
    if(k != n)
        printf("topological sequence not possible\n");
    else {
        printf("topological sequence \n");
        for(i = 0; i < n; i++)
            printf("%d\t", t[i]);
        printf("\n");
    }
}

int main() {
    int a[10][10], n;
    printf("enter the number of nodes: ");
    scanf("%d", &n);
    printf("enter the adjacency matrix:\n");
    read_matrix(n, a);
    topo(n, a);
    return 0;
}
