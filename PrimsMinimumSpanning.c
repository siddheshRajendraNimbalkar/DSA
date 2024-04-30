#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES] ={0};

int minDist(int dist[],int v){
  int min = 9999,min_index;
  for(int i =0;i<v;i++){
    if(dist[i]<min && visited[i]==0){
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}

void printMST(int dist[], int v) {
    printf("Edge   Weight\n");
    for (int i = 1; i < v; i++) {
        printf("0 - %d    %d \n", i, dist[i]);
    }
}


void primMST(int v){
  int to_Store[v];
  int dist[v];

  for(int i = 0; i < v; i++){
    dist[i] = 9999;
  }
  dist[0]=0;
  to_Store[0]=-1;
  for(int i = 0; i < v-1; i++){
    int u = minDist(dist,v);
    visited[u]=1;
    for(int a=0;a<v;a++){
      if(adjacencyMatrix[u][a] && visited[a] == 0 && adjacencyMatrix[u][a]<dist[a]){
        to_Store[a]=u;
        dist[a] = adjacencyMatrix[u][a];
      }
    }
  }
  printMST(to_Store, v);
}

int main(){
  int v,v1,v2;
  printf("Enter the number of vertices: ");
  scanf("%d",&v);
  printf("Enter the number of edges: ");
  for(int i=0; i<v;i++){
    scanf("%d %d",&v1,&v2);
    adjacencyMatrix[v1][v2]=1;
  }
  printf("Adjencency Matrix: \n");
  for(int i=0;i<v;i++){
    for(int j = 0; j < v;j++){
      printf("%d \t", adjacencyMatrix[i][j]);
    }
    printf("\n");
 }
  primMST(v);
  
  return 0;
}