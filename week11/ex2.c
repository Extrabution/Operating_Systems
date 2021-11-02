#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main() {
    FILE* file;
    char path[100] = ".";
    DIR* directory = opendir(path);
    struct dirent* next_file = readdir(directory);
    struct stat curr_file;
    while(next_file != NULL) {
        printf("%s\n", next_file->d_name);
        next_file = readdir(directory);
    }
    closedir(directory);
    return 0;
}