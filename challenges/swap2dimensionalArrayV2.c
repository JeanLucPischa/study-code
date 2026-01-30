#include <stdio.h>

void printArray(int arr[2][2], const char* name) {
    printf("%s:\n", name);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void swapArrays(int arr1[2][2], int arr2[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int temp = arr1[i][j];
            arr1[i][j] = arr2[i][j];
            arr2[i][j] = temp;
        }
    }
}

int main() {
    int arr1[2][2] = {{1, 2}, {3, 4}};
    int arr2[2][2] = {{5, 6}, {7, 8}};

    printf("Current content of arr1 and arr2:\n");
    printArray(arr1, "arr1");
    printArray(arr2, "arr2");

    swapArrays(arr1, arr2);

    printf("\nSwapped content of arr1 and arr2:\n");
    printArray(arr1, "arr1");
    printArray(arr2, "arr2");

    return 0;
}
