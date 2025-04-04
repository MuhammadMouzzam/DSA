#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int array[],int size){
    for(int pass = 0; pass < size; pass++){
        for(int i = 0; i < size-1;i++){
            if(array[i] > array[i+1]){
                int hold = array[i];
                array[i] = array[i+1];
                array[i+1] = hold;
            }
        }
    }
}

int main(){
    int elements = 0;
    printf("Enter no. of elements: ");
    scanf("%d",&elements);
    int array[elements];
    for(int i = 0; i < 10; i++){
        printf("Enter element[%d]: ",i);
        scanf("%d",&array[i]);
    }
    int value = 0;
    printf("Enter value to find: ");
    scanf("%d",&value);
    bubbleSort(array,elements);
    int low = 0, high = elements-1;
    int middle = (high+low)/2;
    int count = 0;
    for(int i = 0; i < elements; i++){
        count++;
        if(array[middle] == value){
            printf("The value is at index %d\n",middle);
            break;
        }else if(value < array[middle]){
            high = middle;
            middle = (high+low)/2;
        }else if(value > array[middle]){
            low = middle;
            middle = (high+low)/2;
        }
    }
    printf("%d counts\n",count);
}