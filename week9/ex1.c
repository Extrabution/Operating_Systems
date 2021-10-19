#include <stdlib.h>
#include <stdio.h>


int main(){
    FILE* file;
    file = fopen("input.txt", "r");
    int b_sum = 0, a;
    int n = 100;
    unsigned char counters[n];
    int page_frames[n];
    for(int i = 0; i < n; i++){
        counters[i] = 0;
        page_frames[i] = 0;
    }
    for(int i = 0; i < n; i++){
        strtol(file, "%d ", &a);
        a -= 1;
        if(page_frames[a] == 0){
            page_frames[a] = 1;
            b_sum += 0;
            counters[a] = 0;
            printf("0\n");
        }
        else{
            printf("1\n");
            b_sum +=1;
            counters[a] = (counters[a] >> 1);
            counters[a] |= (1 << 7);
            //printf("%hhu", counters[0]);
            int min_val = 1000, index = 0;
            for(int j = 0; j < n; j++){
                if(counters[j]<min_val){
                    min_val = counters[j];
                    index = j;
                }
            }
            page_frames[index] = 1;
            counters[index] = 0;
        }
    }
    double r = (double) b_sum/(n-b_sum);
    printf("%f", r);
    return 0;
}