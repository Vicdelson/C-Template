#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
	int weight;
	int value;
	struct node_s *next;
} node_t;

typedef struct prio_queue_s {
	node_t *head;
} prio_queue_t;

// Function to enqueue a node with given value and weight 
void enqueue(prio_queue_t * const queue, int value, int weight) { 
    node_t *node = (node_t *)malloc(sizeof(node_t)); 
    node->value = value; 
    node->weight = weight; 
    node->next = NULL; 
  
    // If queue is empty, add the node and return 
    if (queue->head == NULL) { 
        queue->head = node; 
        return; 
    } 
  
    // Find a position to add the node with given weight 
    node_t *current = queue->head; 
    node_t *prev = NULL; 
    while (current != NULL && current->weight < weight) { 
        prev = current; 
        current = current->next; 
    } 
  
    // Add the node 
    if (prev == NULL) { 
        node->next = queue->head; 
        queue->head = node; 
    } 
    else { 
        prev->next = node; 
        node->next = current; 
    } 
} 

// Function to dequeue a node from the head of the queue 
node_t *dequeue(prio_queue_t * const queue) { 
    // If queue is empty, return NULL 
    if (queue->head == NULL) 
        return NULL; 
  
    // Store the head node 
    node_t *node = queue->head; 
  
    // Move the head pointer to the next node 
    queue->head = queue->head->next; 
  
    // Return the stored node 
    return node; 
} 

// Function to print the nodes of the queue 
void print_nodes(const prio_queue_t * const queue) { 
	if (!queue->head) { 
		printf("EMPTY\n"); 
		return; 
	} 
	for (node_t *node = queue->head; node; node = node->next) { 
		printf(" -> %d", node->value); 
	} 
	printf("\n"); 
	return; 
} 

int main() { 
	int N; 
	scanf("%d", &N); 
	prio_queue_t queue = { 
		.head = NULL, 
	}; 
	for (int i = 0; i < N; i++) { 
		char op[8]; 
		scanf("%s", op); 
		if (!strcmp(op, "ENQUEUE")) { 
			int v, w; 
			scanf("%d%d", &v, &w); 
			enqueue(&queue, v, w); 
		} 
		else if (!strcmp(op, "DEQUEUE")) { 
			free(dequeue(&queue)); 
		} 
		print_nodes(&queue); 
	} 
	return 0; 
}