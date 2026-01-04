#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Edge edges[100];
int parent[20];
int n, e_cnt = 0;

int find(int i) {
    if (parent[i] == -1)
        return i;
    return find(parent[i]);
}

void Union(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    if(xset != yset)
        parent[xset] = yset;
}

int compare(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;
}

void kruskalMST() {
    int mst_weight = 0;
    qsort(edges, e_cnt, sizeof(edges[0]), compare);
    
    for (int i = 0; i < n; i++) 
        parent[i] = -1;

    printf("Edge \tWeight\n");
    for (int i = 0; i < e_cnt; i++) {
        int x = find(edges[i].src);
        int y = find(edges[i].dest);

        if (x != y) {
            printf("%d - %d \t%d \n", edges[i].src, edges[i].dest, edges[i].weight);
            mst_weight += edges[i].weight;
            Union(x, y);
        }
    }
    printf("Total Cost: %d\n", mst_weight);
}

int main() {
    int weight;
    printf("Name: M M VASANTH\n");
    printf("Roll No: CH.SC.U4CSE24227\n\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e_cnt);
    
    for(int i = 0; i < e_cnt; i++) {
        printf("Enter src, dest, weight for edge %d: ", i+1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }
    
    kruskalMST();
    return 0;
}
