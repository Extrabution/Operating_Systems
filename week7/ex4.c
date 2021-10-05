#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* reallocate(void* ptr, size_t size){
	void* newptr;
	if(ptr == NULL){
		newptr = malloc(size);
	}
	else if(ptr == 0){
		free(ptr);
	}
	else{
		newptr = malloc(size);
		newptr = memcpy(newptr, ptr, size);
	}
	return newptr;
}
void main(){
	int n1;
	printf("Number1: ");
	scanf("%d", &n1);
	int* arr;
	arr = reallocate(arr, n1*sizeof(int));
	for(int i = 0; i<n1; i++){
		arr[i] = 1;
		printf("%d ", arr[i]);
	}
	printf("\n");
	int n2;
	printf("Number2: ");
	scanf("%d", &n2);
	arr = reallocate(arr, n2*sizeof(int));
	for(int i = 0; i<n2; i++){
		printf("%d ", arr[i]);
	}
	reallocate(arr, 0);
}
