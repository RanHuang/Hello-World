#include<stdio.h>

#define MAXSIZE 100

void printIntergerArray(int arr[], int n);

int main()
{
	int array[MAXSIZE],i;
	int length;
	printf("Enter the length of a array:");
	scanf("%d", &length);
	printf("Enter the elements(Interger) of the array:\n");
	for(i=0; i<length; i++)
		scanf("%d", &array[i]);

	printf("The sorted array:\n");
	printIntergerArray(array, length);

	return 0;
}

void printIntergerArray(int arr[], int n)
{
	int i;
	printf("\t");
	for(i=1; i<=n; i++){
		printf("%d ", arr[i-1]);
		if(0 == (i%15)) printf("\n\t");
	}
	printf("\n\n");
}
