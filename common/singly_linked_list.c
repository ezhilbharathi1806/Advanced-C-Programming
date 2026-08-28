#include <stdio.h>
#include <stdlib.h>

// 1. Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// 2. Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    // Assign data and link old head to the next of new node
    new_node->data = new_data;
    new_node->next = (*head_ref);
    
    // Move the head to point to the new node
    *head_ref = new_node;
}

// 3. Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    new_node->data = new_data;
    new_node->next = NULL;
    
    // If the Linked List is empty, make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    // Otherwise, traverse till the last node
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    
    // Change the next of last node
    last->next = new_node;
}

// 4. Function to delete a node by its value
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp);             // free old head
        printf("Node with value %d deleted.\n", key);
        return;
    }
    
    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in linked list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }
    
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    printf("Node with value %d deleted.\n", key);
}

// 5. Function to print the linked list
void printList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// 6. Function to free all nodes to avoid memory leaks
void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next_node;
    
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head_ref = NULL;
}

// 7. Main function to test the implementations
int main() {
    // Initialize an empty list
    struct Node* head = NULL;
    
    printf("--- Inserting Elements ---\n");
    insertAtEnd(&head, 10);        // List: 10 -> NULL
    insertAtEnd(&head, 20);        // List: 10 -> 20 -> NULL
    insertAtBeginning(&head, 5);   // List: 5 -> 10 -> 20 -> NULL
    insertAtEnd(&head, 30);        // List: 5 -> 10 -> 20 -> 30 -> NULL
    
    printf("Current Linked List: ");
    printList(head);
    
    printf("\n--- Deleting Elements ---\n");
    deleteNode(&head, 5);   // Delete head
    printList(head);        // List: 10 -> 20 -> 30 -> NULL
    
    deleteNode(&head, 20);  // Delete middle node
    printList(head);        // List: 10 -> 30 -> NULL
    
    deleteNode(&head, 99);  // Attempt to delete non-existent node
    
    // Clean up memory before exiting
    freeList(&head);
    
    return 0;
}
