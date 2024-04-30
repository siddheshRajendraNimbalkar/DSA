#include<stdio.h>
#include<stdlib.h>
#define VERTICES 100

int adjacencyMatrix[VERTICES][VERTICES]={0};

void add(int v1, int v2) {
    adjacencyMatrix[v1][v2] = 1;
}

void printadjacencyMatrix(int v){
    printf("Adjacency matrix \n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d",adjacencyMatrix[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}

void printIndegree(int v){
  printf("Indegree: \n");
  for(int i = 0;i<v;i++){
    int indegree=0;
    for(int j=0;j<v;j++){
      if(adjacencyMatrix[j][i]==1){
        indegree++;
      }
    }
    printf("[ %d ]:%d",i,indegree /n);
  }
}

int main(){
    int e , v , i;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("\n Enter the number of edges: ");
    scanf("%d", &e);
    printf("\n Enter the edges");
    for(i = 0; i < e ; i++){
        int v1 , v2;
        scanf("%d %d",&v1 ,&v2);
        add(v1,v2);
    }
  printadjacencyMatrix(v);
  printIndegree(v);
}