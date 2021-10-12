#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(){
//running this program with bash command 'top' i can see that every second
//program activates and sleeps
//also i can see that evety second 10 mb of main memory increses
	for(int i = 0; i<100; i++){
		char* arr = (char*)malloc(10*1024*1024);
		memset(arr, '0', 10*1024*1024);
		sleep(1);
	}
}
