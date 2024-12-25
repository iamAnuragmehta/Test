#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Create a new node with given data
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the front of the list
void insertFront(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Insert a node at the end of the list
void insertEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Delete a node from the front of the list
void deleteFront(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Delete a node from the end of the list
void deleteEnd(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    Node *temp = *head;
    if (temp->next == NULL)
    { // Only one node in the list
        *head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    }
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Display the elements of the list
void display(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    printf("List elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the operations
int main()
{
    Node *head = NULL;

    int choice, data;
    while (1)
    {
        printf("\n1. Insert Front\n2. Insert End\n3. Delete Front\n4. Delete End\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at front: ");
            scanf("%d", &data);
            insertFront(&head, data);
            break;
        case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertEnd(&head, data);
            break;
        case 3:
            deleteFront(&head);
            break;
        case 4:
            deleteEnd(&head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
