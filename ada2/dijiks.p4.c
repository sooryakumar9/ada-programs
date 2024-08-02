#include <stdio.h>
#define INF 999

void Dij(int cost[10][10], int dist[10], int sv, int n, int path[10], int visited[10]);
void PrintPath(int sv, int n, int dist[10], int path[10]);

int main() {
    int i, j, sv, n;
    int dist[10], visited[10];
    int cost[10][10], path[10];

    printf("DIJKSTRA\n");
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter cost matrix\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    printf("The entered cost matrix is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    printf("Enter source\n");
    scanf("%d", &sv);

    Dij(cost, dist, sv, n, path, visited);
    PrintPath(sv, n, dist, path);

    printf("-----------\n");

    return 0;
}

void Dij(int cost[10][10], int dist[10], int sv, int n, int path[10], int visited[10]) {
    int count = 2, min, v = 0;

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        dist[i] = cost[sv][i];
        if (cost[sv][i] == INF) {
            path[i] = 0;
        } else {
            path[i] = sv;
        }
    }

    visited[sv] = 1;

    while (count <= n) {
        min = INF;
        for (int w = 1; w <= n; w++) {
            if ((dist[w] < min) && (visited[w] == 0)) {
                min = dist[w];
                v = w;
            }
        }

        visited[v] = 1;
        count++;

        for (int w = 1; w <= n; w++) {
            if (visited[w] == 0 && dist[w] > dist[v] + cost[v][w]) {
                dist[w] = dist[v] + cost[v][w];
                path[w] = v;
            }
        }
    }
}

void PrintPath(int sv, int n, int dist[10], int path[10]) {
    for (int w = 1; w <= n; w++) {
        if (w != sv) {
            printf("\nShortest distance between %d -> %d is %d\n", sv, w, dist[w]);
            printf("The path is %d", w);
            int t = path[w];
            while (t != sv) {
                printf(" <- %d", t);
                t = path[t];
            }
            printf(" <- %d\n", sv);
        }
    }
}
