#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables
    int n = 1, i, j, key, ch;
    FILE *arrFile;

    // Read from file
    arrFile = fopen("data.txt", "r");
    if (arrFile == NULL) {
        printf("File does not exist.\n");
        return 0;
    }

    // Count numbers
    while ((ch = fgetc(arrFile)) != EOF) {
        if (ch == ',') {
            n++;
        }
    }
    // Set file pointer back to beginning
    rewind(arrFile);

    int *Arr;
    // Allocate memory for array
    Arr = (int *)calloc(n, sizeof(int));
    for (i = 0; i < n; i++) {
        fscanf(arrFile, "%d,", &Arr[i]);
    }
    fclose(arrFile);

    // Print original array
    printf("Original Array :\n[ ");
    for (i = 0; i < n; i++) {
        printf("%d ", Arr[i]);
    }
    printf("]\n");

    // Sort the array using Insertion Sort
    for(i=1;i<n;i++){
        key=Arr[i];
        j=i-1;
        
        while(j >= 0 && Arr[j]>key){
            Arr[j+1]=Arr[j];
            j--;
        }
        Arr[++j]=key;
    }

    // Print sorted array
    printf("Sorted Array using Insertion Sort :\n[ ");
    for (i = 0; i < n; i++) {
        printf("%d ", Arr[i]);
    }
    printf("]\n");

    // Free allocated memory
    free(Arr);

    return 0;
}
