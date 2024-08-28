#include<stdio.h>
#include<stdlib.h>

int main()
{
	// Initialize variables
	int n = 1,index=0,i,j,ch;
	FILE *arrFile;

	//Read from file
	arrFile = fopen("../data.txt","r");
	if(arrFile==NULL){
		printf("File does not exist.\n");
		return 0;
	}

	// Count numbers
	while((ch=fgetc(arrFile))!= EOF){
        if (ch==','){
            n++;
        }
    }
    // Set file pointer back to beginning
    rewind(arrFile);

	int *Arr;
	// Add elements to array
	Arr = (int*)calloc(n, sizeof(int));
	for(i=0;i<n;i++)
	{
		fscanf(arrFile,"%d,",&Arr[i]);
	}
    fclose(arrFile);

    // Print original array
	printf("Original Array :\n[ ");
	for(i=0;i<n;i++)
	{
		printf("%d ",Arr[i]);
	}
	printf("]\n");

	//Sort the array using Selection sort
	for(i=0;i<n-1;i++)
	{
		// Get current index
		index = i;
		//Compare with every next index element
		for(j=i+1;j<n;j++)
		{
			if(Arr[j]<Arr[index])
			{
				// Get index that has smaller value than current index
				index = j;
			}
		}
		// Swap if index with smaller element found
		if(index != i)
		{
			Arr[index]= Arr[index]+Arr[i];
			Arr[i]=Arr[index]-Arr[i];
			Arr[index]=Arr[index]-Arr[i];
		}
	}

	// Print sorted array
	printf("Sorted Array using Selection Sort :\n[ ");

	for(i=0;i<n;i++)
	{
		printf("%d ",Arr[i]);
	}
	printf("]\n");

	// Free allocated memory
    free(Arr);
	
	return 0;
}
