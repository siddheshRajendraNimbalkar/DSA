#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define v 100

int graph[v][v];
int dis[v];
int visited[v];

int minDistance(int ver){
  int min = INT_MAX;
  int min_index;
  for(int i = 0; i < ver; i++){
    if(dis[i] < min && visited[i] == 0){
      min = dis[i];
      min_index = i;
    }
  }
  return min_index;
}

void printSolution(int ver){
  printf("Vertex   Distance from Source\n");
  for(int i = 0; i < ver; i++)
    printf("%d \t\t %d\n",i,dis[i]);
}

void dijkstra(int ver,int sor){
  for(int i = 0;i<ver;i++){
    dis[i] = INT_MAX;
    visited[i] = 0;
  }
  dis[sor] = 0;

  for(int i = 1;i<ver;i++){
    int u = minDistance(ver);

    visited[u] = 1;
    
    for(int a = 0; a< ver; a++){
      if(!visited[a] && graph[u][a] && dis[u] != INT_MAX && dis[u] + graph[u][a] < dis[a]){
        dis[a] = dis[u] + graph[u][a];
      }
    }
  }
  printSolution(ver);
}

int main(){
  int ver,sor;
  printf("Enter The Verices: ");
  scanf("%d",&ver);
  printf("Enter The Adjacency Matrix: \n");
  for(int i=0;i<ver;i++){
    for(int j=0;j<ver;j++){
      scanf("%d",&graph[i][j]);
    }
  }

  printf("Enter The Source: ");
  scanf("%d",&sor);

  dijkstra(ver,sor);
  
  return 0;
}