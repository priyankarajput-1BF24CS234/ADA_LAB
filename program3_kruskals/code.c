#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int u, v, weight;
};

int parent[MAX];

// Find function
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union function
void unionSet(int u, int v) {
    int u_root = find(u);
    int v_root = find(v);
    parent[u_root] = v_root;
}

// Compare edges for sorting
int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal function
void kruskal(struct Edge edges[], int V, int E) {
    struct Edge result[MAX];
    int count = 0, i = 0, total = 0;

    qsort(edges, E, sizeof(edges[0]), compare);

    for (int j = 0; j < V; j++)
        parent[j] = j;

    while (count < V - 1 && i < E) {
        int u = edges[i].u;
        int v = edges[i].v;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) {
            result[count++] = edges[i];
            total += edges[i].weight;
            unionSet(set_u, set_v);
        }
        i++;
    }

    printf("Edge \tWeight\n");
    for (int i = 0; i < count; i++) {
        printf("%d - %d \t%d\n", result[i].u, result[i].v, result[i].weight);
    }
    printf("Total Cost = %d\n", total);
}

int main() {
    int V;
    int graph[MAX][MAX];
    struct Edge edges[MAX];
    int E = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            // Only add each edge once (i < j)
            if (i < j && graph[i][j] != 0) {
                edges[E].u = i;
                edges[E].v = j;
                edges[E].weight = graph[i][j];
                E++;
            }
        }
    }

    kruskal(edges, V, E);

    return 0;
}
