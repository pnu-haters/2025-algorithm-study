#include <iostream>
#define MAXSIZE 10000
int DFS_output[MAXSIZE] = {0,};
int BFS_output[MAXSIZE] = {0,};

typedef struct node {
    int vertex;
    struct node* link;
} node;

typedef struct Graph {
    int n;
    node* adj_list[MAXSIZE];
} Graph;

void init(Graph* pGh) {
    pGh->n = 0;
    for (int v = 0; v < MAXSIZE; v++)
        pGh->adj_list[v] = NULL;
}

void insertEdge(Graph* pGh, int st, int dst) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->vertex = dst;
    newnode->link = pGh->adj_list[st];
    pGh->adj_list[st] = newnode;
}

void undirectedEdge(Graph* pGh, int u, int v) {
    insertEdge(pGh, u, v);
    insertEdge(pGh, v, u);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void DFS(Graph* pGh, int start) {
    int stack[MAXSIZE];
    int visited[MAXSIZE] = {0,};
    int top = -1;
    int outputIdx = 0;

    stack[++top] = start;

    while (top != -1) {
        int preNode = stack[top--];

        if (!visited[preNode]) {
            visited[preNode] = 1;
            DFS_output[outputIdx++] = preNode;

            node* nextNode = pGh->adj_list[preNode];
            int neighbors[MAXSIZE], count = 0;

            while (nextNode) {
                if (!visited[nextNode->vertex]) {
                    neighbors[count++] = nextNode->vertex;
                }
                nextNode = nextNode->link;
            }

            qsort(neighbors, count, sizeof(int), compare);

            for (int i = count - 1; i >= 0; i--) {
                stack[++top] = neighbors[i];
            }
        }
    }
    DFS_output[outputIdx] = -1;
}

void BFS(Graph* pGh, int start) {
    int queue[MAXSIZE];
    int visited[MAXSIZE] = {0,};
    int front = 0, rear = 0;
    int outputIdx = 0;

    queue[rear++] = start;

    while (front < rear) {
        int preNode = queue[front++];

        if (!visited[preNode]) {
            visited[preNode] = 1;
            BFS_output[outputIdx++] = preNode;

            node* nextNode = pGh->adj_list[preNode];
            int neighbors[MAXSIZE], count = 0;

            while (nextNode) {
                if (!visited[nextNode->vertex]) {
                    neighbors[count++] = nextNode->vertex;
                }
                nextNode = nextNode->link;
            }

            qsort(neighbors, count, sizeof(int), compare);

            for (int i = 0; i < count; i++) {
                queue[rear++] = neighbors[i];
            }
        }
    }
    BFS_output[outputIdx] = -1;
}

void freeGraph(Graph* pGh) {
    for (int i = 0; i < pGh->n; i++) {
        node* current = pGh->adj_list[i];
        while (current) {
            node* temp = current;
            current = current->link;
            free(temp);
        }
    }
}

int main() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    init(g);

    int vertex, edge, start;
    scanf("%d %d %d", &vertex, &edge, &start);
    g->n = vertex;

    for (int i = 0; i < edge; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        undirectedEdge(g, v1, v2);
    }

    DFS(g, start);
    BFS(g, start);

    for (int i = 0; DFS_output[i] != -1; i++) {
        printf("%d ", DFS_output[i]);
    }
    printf("\n");

    for (int i = 0; BFS_output[i] != -1; i++) {
        printf("%d ", BFS_output[i]);
    }
    printf("\n");

    freeGraph(g);
    free(g);
    return 0;
}
