#include <stdio.h>
#include <stdlib.h>

struct queueNode
{
    int data;                 // define data as a char
    struct queueNode *nextPtr; // queueNode pointer
};
typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;
// function prototypes
void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr topPtr);
void push(QueueNodePtr *topPtr, char value);
char pop(QueueNodePtr *stackPtr);
void instructions(void);
int main(void)
{
    QueueNodePtr stackPtr = NULL; // initialize headPtr
    int item = 0;            // char input by user
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
            scanf("\n%d", &item);
            push(&stackPtr, item);
            printQueue(stackPtr);
            break;
        case 2: // dequeue value
            // if queue is not empty
            if (!isEmpty(stackPtr))
            {
                item = pop(&stackPtr);
                printf("%d has been dequeued.\n", item);
            }
            printQueue(stackPtr);
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

void push(QueueNodePtr *topPtr, char value){
    QueueNodePtr newPtr = malloc(sizeof(QueueNode));
    if(newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }else{
        puts("No space Available");
    }
}

char pop(QueueNodePtr *topPtr){
    QueueNodePtr tempPtr = *topPtr;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
}

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
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        puts("NULL\n");
    }
}

int isEmpty(QueueNodePtr topPtr)
{
    return topPtr == NULL;
}