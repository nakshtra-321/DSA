#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

struct Node* insertionSort(struct Node* head)
{
    struct Node* sorted = NULL;
    struct Node* current = head;

    while(current != NULL)
    {
        struct Node* next = current->next;

        if(sorted == NULL || sorted->data >= current->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            struct Node* temp = sorted;

            while(temp->next != NULL &&
                  temp->next->data < current->data)
            {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    return sorted;
}

void display(struct Node* head)
{
    struct Node* temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    struct Node* head = NULL;

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        insertEnd(&head, x);
    }

    head = insertionSort(head);

    display(head);

    return 0;
}