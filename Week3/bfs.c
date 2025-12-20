#include <stdio.h>
int queue[20], front = -1, rear = -1;
int visited[20], adj[20][20], n;
void bfs(int start) {
    int i;
    printf("BFS Traversal: ");
    queue[++rear] = start;
    visited[start] = 1;
    while (front != rear) {
        start = queue[++front];
        printf("%d ", start);
        for (i = 0; i < n; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
int main() {
    int i, j, start;
    printf("Name: M M VASANTH\n");
    printf("Roll No: CH.SC.U4CSE24227\n\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    bfs(start);
    return 0;
}
