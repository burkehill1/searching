#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DELTA 4
#define SIZE 10000
int * arr;
int key;
int useless;

void binarySearch(int * arr);
void ternarySearch(int * arr);
void printShit(int *);


int main() {
    srand(time(0));

    int i;

    int * arr = (int *) calloc(SIZE, sizeof(int));
    arr[0] = 0; // not useful
    for (i = 1; i < SIZE; i++)
    {
        int delta = rand() % (DELTA + 1);
        if (delta < 0)
            delta = -delta;

        arr[i] = delta + arr[i - 1];
        
    }
    
    while (1) {
        char input[100];
        scanf("%s", input);

        if (strcmp(input, "bi") == 0) {
            binarySearch(arr);
        }
        else if (strcmp(input, "ter") == 0) {
            ternarySearch(arr);
        }
    }
}

void binarySearch(int * arr) {
    int lo = 0;
    int hi = SIZE -1;
    int operations;
    int targetind = -1;
    int min = arr[0];
    int max = arr[SIZE - 1];

    int key = abs(rand() % (max - min + 1)) + min;

    while (lo <= hi) {

        int mid = (hi + lo) / 2;
        operations++; 

        if (key < arr[mid]) {
            hi = mid -1;
        }
        else if (key > arr[mid]) {
            lo = mid + 1;
        }
        else {
            key = mid;
            break;
        }
    }
    //printf("%d", operations);
    printf("Target was %d, took %d operations\n", key, operations);
}

void ternarySearch(int * arr) {
    int lo = 0;
    int hi = SIZE - 1;
    int operations;
    int min = arr[0];
    int max = arr[SIZE -1];
    int targetInd = -1;

    int key = abs(rand() % (max - min + 1)) + min;


    while (lo <= hi) {
        int mid1 = lo + ((hi - lo) / 3);
        int mid2 = hi - ((hi - lo) / 3);

        operations++;

        if (key < arr[mid1]) {
            hi = mid1 - 1;
        }
        else if (key > arr[mid1] && key < arr[mid2]) {
            lo = mid1 + 1;
            hi = mid2 - 1;
        }
        else if (key > arr[mid2]) {
            lo = mid2 + 1;
        }
        else {
            targetInd = key;
            break;
        }


    }
    printf("Number was %d, took %d operations", key, operations);
}





