#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "utils.h"

typedef struct AdjNode {
    int vertex;
    struct AdjNode* next;
} AdjNode;

typedef struct Graph {
    int numVertices;
    AdjNode* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
} Graph;

static Graph graph;

static AdjNode* create_adj_node(int v) {
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));
    node->vertex = v;
    node->next = NULL;
    return node;
}

static void init_graph(int vertices) {
    graph.numVertices = vertices;
    for(int i = 0; i < vertices; i++) {
        graph.adjLists[i] = NULL;
        graph.visited[i] = 0;
    }
}

static void add_edge(int src, int dest) {
    AdjNode* newNode = create_adj_node(dest);
    newNode->next = graph.adjLists[src];
    graph.adjLists[src] = newNode;

    // For undirected graph add edge both ways
    newNode = create_adj_node(src);
    newNode->next = graph.adjLists[dest];
    graph.adjLists[dest] = newNode;
}

static void display_graph(void) {
    clear_screen();
    printf("Graph adjacency lists:\n");
    for (int i = 0; i < graph.numVertices; i++) {
        printf("Vertex %d: ", i);
        AdjNode* temp = graph.adjLists[i];
        while(temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

static void BFS(int startVertex) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    for(int i=0; i < graph.numVertices; i++) graph.visited[i] = 0;

    queue[rear++] = startVertex;
    graph.visited[startVertex] = 1;
    printf("BFS traversal starting from vertex %d:\n", startVertex);

    while(front != rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        AdjNode* temp = graph.adjLists[currentVertex];

        while(temp) {
            int adjVertex = temp->vertex;
            if(!graph.visited[adjVertex]) {
                queue[rear++] = adjVertex;
                graph.visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

static void DFS_util(int vertex) {
    graph.visited[vertex] = 1;
    printf("%d ", vertex);
    AdjNode* temp = graph.adjLists[vertex];
    while(temp){
        if(!graph.visited[temp->vertex])
            DFS_util(temp->vertex);
        temp = temp->next;
    }
}

static void DFS(int startVertex) {
    for(int i=0; i < graph.numVertices; i++) graph.visited[i] = 0;
    printf("DFS traversal starting from vertex %d:\n", startVertex);
    DFS_util(startVertex);
    printf("\n");
}

void graph_menu(void) {
    int choice, vertices, src, dest, start;
    do {
        clear_screen();
        printf("Graph (Undirected) - Adjacency List\n");
        printf("1. Create graph\n2. Display adjacency list\n3. BFS traversal\n4. DFS traversal\n0. Return to main menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice) {
            case 1:
                printf("Enter number of vertices (max %d): ", MAX_VERTICES);
                scanf("%d", &vertices);
                if(vertices < 1 || vertices > MAX_VERTICES){
                    printf("Invalid vertices count.\n");
                    pause();
                    break;
                }
                init_graph(vertices);
                int edges;
                printf("Enter number of edges: ");
                scanf("%d", &edges);
                for(int i=0; i<edges; i++) {
                    printf("Enter edge %d source and destination (0 to %d): ", i+1, vertices-1);
                    scanf("%d %d", &src, &dest);
                    if(src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
                        printf("Invalid vertices.\n");
                        i--;
                        continue;
                    }
                    add_edge(src, dest);
                }
                printf("Graph created.\n");
                pause();
                break;

            case 2:
                display_graph();
                pause();
                break;

            case 3:
                printf("Enter start vertex for BFS (0 to %d): ", graph.numVertices - 1);
                scanf("%d", &start);
                if(start < 0 || start >= graph.numVertices){
                    printf("Invalid start vertex.\n");
                    pause();
                    break;
                }
                BFS(start);
                pause();
                break;

            case 4:
                printf("Enter start vertex for DFS (0 to %d): ", graph.numVertices - 1);
                scanf("%d", &start);
                if(start < 0 || start >= graph.numVertices){
                    printf("Invalid start vertex.\n");
                    pause();
                    break;
                }
                DFS(start);
                pause();
                break;

            case 0: break;

            default:
                printf("Invalid choice!\n");
                pause();
        }
    } while(choice != 0);
}
