#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Write a number: ");
	scanf("%d", &n);
	int* array = (int*)malloc(n*sizeof(int));
	for(int i = 0; i<n; i++){
		array[i] = i;
		printf("%d", array[i]);
	}
	free(array);
	return 0;
}
