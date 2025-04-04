#include <stdio.h>
#include <stdlib.h>

struct listNode
{
    char data;
    struct listNode* nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode* ListNodePtr;

void printList(ListNodePtr currentPtr)
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

void insert(ListNodePtr *sPtr, char value){
    ListNodePtr newPtr = malloc(sizeof(ListNode));
    if(newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;
        while(currentPtr != NULL && value > currentPtr->data){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if(previousPtr == NULL){
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }else{
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }else{
        printf("NO SPACE AVAILABLE\n");
    }
}

void delete(ListNodePtr *sPtr, char value){
    if((*sPtr)->data == value){
        ListNodePtr tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
    }else{
        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;
        while(currentPtr != NULL && value != currentPtr->data){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if(currentPtr != NULL){
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
        }else{
            printf("Value Not Found\n");
        }
    }
    printList(*sPtr);
}

ListNodePtr linkedList(){
    ListNodePtr startPtr = NULL;
    char item = '\0';
    int choice = 0;
    do{
        printf("1- Add Node\n2- Delete Node\n3- End run\n%c ",'?');
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("%s","Enter a Character: ");
            scanf("\n%c",&item);
            insert(&startPtr,item);
            printList(startPtr);
            break;
        case 2:
            printf("%s","Enter the character you want to delete: ");
            scanf("\n%c",&item);
            delete(&startPtr, item);
            break;
        }
    }while(choice > 0 && choice < 3);
    puts("End of Run. Linked list created!");
    return startPtr;
}

ListNodePtr concatenate(ListNodePtr *startPtr1, ListNodePtr *startPtr2){
    ListNodePtr previousPtr = NULL;
    ListNodePtr currentPtr = *startPtr1;
    ListNodePtr newStartPtr = *startPtr1;
    while(currentPtr != NULL){
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    currentPtr->nextPtr = *startPtr2;
    return newStartPtr;
}

int main(){
    
}