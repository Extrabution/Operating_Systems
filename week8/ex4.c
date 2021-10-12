#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

void main(){
	for(int i = 0; i<10; i++){
		char* arr = malloc(100*1024*1024);
		memset(arr, '0', 100*1024*1024);
		int who = RUSAGE_SELF;
		struct rusage usage;
		int r = getrusage(who, &usage);
		printf("Memory usage: %ld\n", usage.ru_maxrss);
		//free(arr);
		sleep(1);
	}
}
