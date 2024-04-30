#include<stdio.h>
#include<stdlib.h>

#define MAX_V 100

int adjacency_matrix[MAX_V][MAX_V]={0};
int visited[MAX_V]={0};
int stack[MAX_V];
int top=-1;

void DFS(int vertics,int v){
  visited[vertics]=1;
  for(int i=0;i<v;i++){
    if(adjacency_matrix[vertics][i] && visited[i] == 0){
      DFS(i,v);
    }
  }
  stack[++top]=vertics;
}

void topoSort(int v){
  for(int i=0;i<v;i++){
    if(visited[i]==0){
      DFS(i,v);
    }
  }
  printf("Topological Sorting: ");
  while (top >= 0) {
      printf("%d ", stack[top]);
      top--;
  }
}

int main(){
  int v;
  printf("Enter the number of vertices: ");
  scanf("%d",&v);
  for(int i=0;i<v;i++){
    int v1,v2;
    scanf("%d %d",&v1,&v2);
    adjacency_matrix[v1][v2]=1;
  }
  printf("Adjacency matrix:\n");
  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      printf("%d ",adjacency_matrix[i][j]);
    }
    printf("\n");
  }

  topoSort(v);
  return 0;
}