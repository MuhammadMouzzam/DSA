#include <stdio.h>
#include <stdlib.h>

struct queueNode
{
    char data;                 // define data as a char
    struct queueNode *nextPtr; // queueNode pointer
};
typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;
// function prototypes
void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void instructions(void);
int main(void)
{
    QueueNodePtr headPtr = NULL; // initialize headPtr
    QueueNodePtr tailPtr = NULL; // initialize tailPtr
    char item = '\0';            // char input by user
    instructions();              // display the menu
    printf("%s", "? ");
    int choice = 0; // user's menu choice
    scanf("%d", &choice);
    // while user does not enter 3
    while (choice != 3)
    {
        switch (choice)
        {
        case 1: // enqueue value
            printf("%s", "Enter a character: ");
            scanf("\n%c", &item);
            enqueue(&headPtr, &tailPtr, item);
            printQueue(headPtr);
            break;
        case 2: // dequeue value
            // if queue is not empty
            if (!isEmpty(headPtr))
            {
                item = dequeue(&headPtr, &tailPtr);
                printf("%c has been dequeued.\n", item);
            }
            printQueue(headPtr);
            break;
        default:
            puts("Invalid choice.\n");
            instructions();
            break;
        }
        printf("%s", "? ");
        scanf("%d", &choice);
    }
    puts("End of run.");
}
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value)
{
    QueueNodePtr newPtr = malloc(sizeof(QueueNodePtr));
    if (newPtr != NULL)
    {
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        if (*headPtr == NULL)
        {
            *headPtr = newPtr;
            *tailPtr = newPtr;
        }
        else
        {
            (*tailPtr)->nextPtr = newPtr;
            *tailPtr = newPtr;
        }
    }
    else
    {
        puts("No space available");
    }
}

char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
    if (*headPtr == *tailPtr)
    {
        QueueNodePtr tempPtr = *headPtr;
        *headPtr = NULL;
        *tailPtr = NULL;
        free(tempPtr);
    }
    else
    {
        QueueNodePtr tempPtr = *headPtr;
        *headPtr = (*headPtr)->nextPtr;
        free(tempPtr);
    }
}

// display program instructions to user
void instructions(void)
{
    printf("Enter your choice:\n"
           " 1 to add an item to the queue\n"
           " 2 to remove an item from the queue\n"
           " 3 to end\n");
}

void printQueue(QueueNodePtr currentPtr)
{
    if (currentPtr == NULL)
    { // if queue is empty
        puts("Queue is empty.\n");
    }
    else
    {
        puts("The queue is:");
        while (currentPtr != NULL)
        { // while not end of queue
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        puts("NULL\n");
    }
}

int isEmpty(QueueNodePtr headPtr)
{
    return headPtr == NULL;
}