#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define V 100

int minDistance(int dist[], int visited[], int ver){
  int min = INT_MAX;
  int min_index;
  for(int i = 0; i < ver; i++){
    if(dist[i] < min && visited[i] == 0){
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}

void printSolution(int dist[], int ver){
  printf("Vertex   Distance from Source\n");
  for(int i = 0; i < ver; i++)
    printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src, int ver){
  int dis[V];
  int visited[V];
  
  for(int i = 0; i < ver; i++){
    dis[i] = INT_MAX;
    visited[i] = 0;
  }
  dis[src] = 0;

  for(int i = 0; i < ver - 1; i++){
    int u = minDistance(dis, visited, ver);
    visited[u] = 1;
    
    for(int a = 0; a < ver; a++){
      if(!visited[a] && graph[u][a] && dis[u] != INT_MAX && dis[u] + graph[u][a] < dis[a]){
        dis[a] = dis[u] + graph[u][a];
      }
    }
  }
  printSolution(dis, ver);
}

int main(){
  int ver, src;
  int graph[V][V];

  printf("Enter The Number of Vertices: ");
  scanf("%d", &ver);
  printf("Enter The Adjacency Matrix: \n");
  for(int i = 0; i < ver; i++){
    for(int j = 0; j < ver; j++){
      scanf("%d", &graph[i][j]);
    }
  }

  printf("Enter The Source Vertex: ");
  scanf("%d", &src);

  dijkstra(graph, src, ver);
  
  return 0;
}
