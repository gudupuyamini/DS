//DFS implementation
#include <stdio.h>
#define MAX 10
int graph[MAX][MAX];      // Adjacency matrix
int visited[MAX];         // Visited array for DFS and BFS
// Function to add an edge (undirected)
void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1; // For undirected graph
}
// DFS using recursion
void DFS(int v, int n) {
	int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}
// Main function
int main() {
    int vertices,i,j;
    char ch;
    printf("Enter number of vertices:");
	scanf("%d",&vertices);
	for(i=0;i<vertices;i++)
	{
		for(j=i+1;j<vertices;j++)
		{
			printf("Do you want edge from %d to %d:",i,j);
			scanf(" %c",&ch);
			if(ch=='Y'||ch=='y')
			addEdge(i,j);
		}
	}
    printf("DFS starting from vertex 0:\n");
    for (i = 0; i < vertices; i++) 
			visited[i] = 0;
    DFS(0, vertices);
    return 0;
}
