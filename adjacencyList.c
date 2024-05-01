#include<stdio.h>
#include<stdlib.h>

#define MAX_V 100

struct node{
  int data;
  struct node *next;
};

struct node *createNode(int dist){
  struct node *newNode =(struct node*)malloc(sizeof(struct node));
  newNode->data = dist;
  newNode->next = NULL;
  return newNode;
}

void addEdges(struct node *adjList[],int src,int dist){
  struct node *newNode = createNode(dist);
  newNode->next = adjList[src];
  adjList[src] = newNode;
}

void printGraph(struct node *adjList[],int v){
  printf("Adjacency List:\n");
  for(int i=0;i<v;i++){
    struct node *temp = adjList[i];
    printf("vertex %d: ",i);
    while(temp){
      printf("%d ",temp->data);
      temp = temp -> next;
    }
    printf("\n");
  }
}

int main(){

  int v,e;
  printf("Enter the number of vertices: ");
  scanf("%d",&v);
  printf("Enter the number of vertices: ");
  scanf("%d",&e);

  struct node *adjList[MAX_V]={0};
  for(int i = 0;i<e;i++){
    int src,dist;
    printf("\n Enter The SCR and DIST: ");
    scanf("%d %d",&src,&dist);
    addEdges(adjList,src,dist);
  }

  printGraph(adjList,v);
  
  return 0;
}