#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *link;
    char name[25], usn[15], programme[10];
    int sem;
    int ph_no;
} *newnode, *head = NULL, *temp, *tail, *prev;

struct node *create()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->link = NULL;
    printf("\nEnter Name:");
    scanf("%s", newnode->name);
    printf("Enter USN:");
    scanf("%s", newnode->usn);
    printf("Enter Programme:");
    scanf("%s", newnode->programme);
    printf("Enter Sem:");
    scanf("%d", &newnode->sem);
    printf("Enter Phone Number:");
    scanf("%d", &newnode->ph_no);
    return newnode;
}

int insertfront()
{
    newnode = create();
    newnode->link = head;
    head = newnode;
}
int delfront()
{
    temp = head;
    head = temp->link;
}
int insertend()
{
    newnode = create();
    temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newnode;
    newnode->link = NULL;
}
int delend()
{
    temp = head;
    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    tail = prev;
}
void display()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;

        while (temp != NULL)
        {
            printf("\nDetails of Student\n");
            printf("|Name:%s|Usn:%s|Programme:%s|Sem:%d|Phone Number:%d|", temp->name, temp->usn, temp->programme, temp->sem, temp->ph_no);
            temp = temp->link;
        }
    }
}
int main()
{
    int i, m, ch;
    while (1)
    {
        printf("\nSingle linkedlist for Student details\n\n1.Insert at front\n2.Delete at front\n3.Insert at end\n4.Delete at end\n5.Display\n6.Exit\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertfront();
            break;
        case 2:
            delfront();
            break;
        case 3:
            insertend();
            break;
        case 4:
            delend();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("\ninvalid choice\n");
            break;
        }
    }
}