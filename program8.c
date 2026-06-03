#include <stdio.h>

#define MAX 10

int a[MAX][MAX], indegree[MAX], queue[MAX];
int n;

void topologicalSort() {
    int front = 0, rear = 0;
    int count = 0;

    // Find indegree of each vertex
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            indegree[i] += a[j][i];
        }
    }

    // Insert vertices with indegree 0 into queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Ordering: ");

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        count++;

        for (int i = 0; i < n; i++) {
            if (a[v][i] == 1) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if (count != n) {
        printf("\nGraph contains a cycle");
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    topologicalSort();

    return 0;
}
