#include <stdlib.h>
#include <stdio.h>


int main(){
    FILE* file1;
    FILE* file2;
    file1 = fopen("input_ok.txt", "r");
    file2 = fopen("output.txt", "w");
    int arrayE[3];
    int arrayC[5][3];
    int arrayR[5][3];
    int arrayA[3];
    int arrayP[5] = {0,0,0,0,0};
    int arrayPpr[5] = {0,0,0,0,0};
    int loop_flag = 1;
    fscanf(file1, "%d %d %d", &arrayE[0], &arrayE[1], &arrayE[2]);
    fscanf(file1, "%d %d %d", &arrayA[0], &arrayA[1], &arrayA[2]);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            fscanf(file1, "%d", &arrayC[i][j]);
        }
    }
    for(int i = 0 ; i < 5; i++){
        for(int j = 0; j < 3; j++){
            fscanf(file1, "%d", &arrayR[i][j]);
        }
    }
    while(loop_flag){
        int flag = 1;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(arrayA[j] < arrayR[i][j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                for(int j = 0; j < 5; j++) {
                    arrayA[j] += arrayC[i][j];
                }
                arrayP[i] = 1;
            }
        }
        loop_flag = 0;
        for(int i = 0; i < 5; i++){
            if(arrayP[i] != arrayPpr[i]){
                loop_flag = 1;
                arrayPpr[i] = arrayP[i];
            }
        }
        
    }
    int dead_lock = 0;
    for(int i = 0; i< 5; i++){
        if(arrayP[i] == 0)
            dead_lock +=1;
    }
    if(dead_lock == 0){
        fprintf(file2, "No procces deadloked");
    }
    if(dead_lock == 1){
        fprintf(file2, "Process");
        for(int i = 0; i < 5; i++)
            if (arrayP[i] == 0)
                fprintf(file2, " %d deadlocked", i);
    }
    if(dead_lock > 1){
        fprintf(file2, "Processes");
        for (int i = 0; i < 5; i++)
            if (arrayP[i] == 0)
                fprintf(file2, " %d", i + 1);
        fprintf(file2, " deadlocked");
    }
    return 0;
}
