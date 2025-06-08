#include<stdio.h>
#include <stdlib.h>
/*
directed graph - all edges are directed(one way)
undirected graph - all edges are undirected(two way)
outdegree - number of nodes going out of the node
indegree- number of nodes coming into the node\

adjacency list - mark the nodes with the list of its neighbors
adjacency matrix-Aij = 1 for an edge between i and j, 0 otherwise.
Edge set - store the pair of nodes/vertices connected with an edge. Eg.={(0,1)}
Other implementations to represent a graph also exists. For e.g. Compact list representation,cost adjacency list,
,cost adjacency matrix etc.

graph traversal
-Breadth first search(BFS)
-depth first search(DFS)
BFS - start with a node and start exploring its connected nodes. The same process is repeated with all 
the connectin nodes until all the nodes are visited.
*/

//bfs code
/*
we can start with any vertex
there can be multiple BFS results for a given graph.
The order of visiting the verticfes can be anything
*/
typedef struct queue
{
    int size;
    int r;
    int f;
    int * arr;
}queue;

void enqueue(queue * ptr,int element);
int dequeue(queue * ptr);
int isfull(queue * ptr);
int isempty(queue * ptr);
int peek(queue *ptr,int position);
int first(queue *ptr);
int last(queue * ptr);
     int a[7][7] = {  //adjacency matrix of the graph
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0}
     };

void DFS(int i,int *visit)
{
    int j;
    printf("%d,",i);
    visit[i] =1;
    for(int j = 0;j<7;j++)
    {
        if(a[i][j] == 1 && visit[j] == 0)
        {
            DFS(j,visit);
        }
    }

}
//main function is here.
int main()
{


    //initializing queue
     queue q;
     q.size = 400;
     q.f = q.r = 0;
     q.arr = (int*)malloc(q.size*sizeof(int));

     //BFS implementation
     int node; //value of the node that was dequeued
     int s = 6; //first node that is given
     int visited[7] = {0,0,0,0,0,0,0}; //tracks which elements were visited using the indices as value
     printf("%d,",s);//printing the source node
     visited[s] = 1; //showing that the source node was visited
     enqueue(&q,s);//putting the source node for exploration
     while(!isempty(&q))
     {
        node = dequeue(&q);
        for(int j = 0; j<7;j++)
        {
            if(a[node][j]==1 && visited[j]==0)
            {   
                printf("%d,",j);
                visited[j] = 1;
                enqueue(&q,j);
            }
        }
     }
    printf("\n");
     //DFS implementation
     int visit[7] = {0,0,0,0,0,0,0};
     s = 4;
     DFS(s,visit);

}
//main function ends here



void enqueue(queue * ptr,int element)
{
    if(isfull(ptr))
    {
        printf("This Queue is full.\n");
        return;
    }

    ptr->r++;
    ptr->arr[ptr->r] = element;
    return;
}

int dequeue(queue * ptr)
{
        if(isempty(ptr))
    {
        printf("This Queue is empty.\n");
        return -1;
    }

    ptr->f++;
    int element = ptr->arr[ptr->f];
    return element;
}
int isfull(queue * ptr)
{
    if(ptr->r == ptr->size -1)
    {
        return 1;
    }
    return 0;
}
int isempty(queue * ptr)
{
    if(ptr->f == ptr->r)
    {
        return 1;
    }
    return 0;
}
int peek(queue *ptr,int position)
{
    if(ptr->f+position>ptr->r)
    {
        printf("No element at this position\n");
        return -1;
    }
    return ptr->arr[ptr->f+position];
}
int first(queue *ptr)
{
    return ptr->arr[ptr->f+1];
}
int last(queue * ptr)
{
    return ptr->arr[ptr->r];
}
