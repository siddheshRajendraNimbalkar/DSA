#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES] ={0};

void DFS(int vertex,int v){
  visited[vertex] = 1;
  printf("%d ",vertex);
  for(int i=0;i<v;i++){
    if(adjacencyMatrix[vertex][i] && !visited[i]){
      DFS(i,v);
    }
  }
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

  DFS(0,v);
  
  return 0;
}