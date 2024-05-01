#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES] = {0};

int minDist(int dist[], int v) {
    int min = 9999, min_index;
    for (int i = 0; i < v; i++) {
        if (dist[i] < min && visited[i] == 0) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int dist[], int v) {
    printf("Edge   Weight\n");
    for (int i = 1; i < v; i++) {
        printf("0 - %d    %d \n", dist[i], i);
    }
}

void primMST(int v) {
    int dist[v];

    for (int i = 0; i < v; i++) {
        dist[i] = 9999;
    }
    dist[0] = 0;

    for (int i = 0; i < v - 1; i++) {
        int u = minDist(dist, v);
        visited[u] = 1;
        for (int a = 0; a < v; a++) {
            if (adjacencyMatrix[u][a] && visited[a] == 0 && adjacencyMatrix[u][a] < dist[a]) {
                dist[a] = adjacencyMatrix[u][a];
            }
        }
    }
    printMST(dist, v);
}



int main() {
    int v, e, v1, v2, weight;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    printf("Enter edges in the format: <vertex1> <vertex2> <weight>\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &v1, &v2, &weight);
        adjacencyMatrix[v1][v2] = weight;
        adjacencyMatrix[v2][v1] = weight; // Assuming undirected graph
    }

    printf("Adjacency Matrix: \n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d \t", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    primMST(v);

    return 0;
}
