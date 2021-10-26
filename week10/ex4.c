#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

int main() {
    FILE* file;
    file = fopen("ex4.txt", "w");
    fprintf(file ,"File —– Hard Links\n");
    char path[100] = "tmp";
    DIR* directory = opendir(path);
    if(directory == NULL){
        return 9011;
    }
    int i_nodes_numbers[100];
    struct dirent* next_file = readdir(directory);
    struct stat curr_file;
    while(next_file != NULL) {
        char file_path[256];
        strcat(file_path, path);
        strcat(file_path, "/");
        strcat(file_path, next_file->d_name);
        stat(file_path, &curr_file);
        if (((strlen(next_file->d_name) == 1) && (strcmp(next_file->d_name, ".")) == 0) ||
                ((strlen(next_file->d_name) == 2) && (strcmp(next_file->d_name, "..") == 0))) {
            next_file = readdir(directory);
            continue;
        }
        else{
            if (curr_file.st_nlink >= 2) {
                fprintf(file, "%s --- ", next_file->d_name);
                int inumber = (int)next_file->d_ino;
                DIR *sameDir = opendir(path);
                struct dirent *next_file2 = readdir(sameDir);
                while (next_file2 != NULL) {
                    if (next_file2->d_ino == inumber) {
                        fprintf(file, "%s ", next_file2->d_name);
                    }
                    next_file2 = readdir(sameDir);
                }
                fprintf(file, "\n");
            }
        }
        next_file = readdir(directory);
    }

    return 0;
}
