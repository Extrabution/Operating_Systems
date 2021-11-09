#include <stdio.h>
#include <unistd.h>
#include <linux/input.h>
#include <fcntl.h>

int main(){
    FILE* output = fopen("./ex3.txt", "w+");
    int file;
    struct input_event event;
    file = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    int a=0,c=0,p=0,e=0,t=0,y=0;
    if (file == -1)
        return -1;
    printf("Available shortcuts:\n");
    printf(" C + A + P - print \"Get some cappuccino!\"\n");
    printf(" P + E - print \"I passed the Exam!\"\n");
    printf(" T + Y - print \"Wow it's a shortcut!\"\n");
    fprintf(output, "available shortcuts:\n");
    fprintf(output," C + A + P - print \"Get some cappuccino!\"\n");
    fprintf(output," P + E - print \"I passed the Exam!\"\n");
    fprintf(output," T + Y - print \"Wow it's a shortcut!\"\n");
    fflush(output);
    int it=0;
    while(1) {
        read(file, &event, sizeof(event));
        if(event.type == EV_KEY) {
            if(event.value == 0){
                switch (event.code) {
                    case KEY_A:
                        a = 0;
                        break;
                    case KEY_C:
                        c = 0;
                        break;
                    case KEY_P:
                        p = 0;
                        break;
                    case KEY_E:
                        e = 0;
                        break;
                    case KEY_T:
                        t = 0;
                        break;
                    case KEY_Y:
                        y = 0;
                        break;
                }
            }
            else if (event.value == 1) {	// Pressed
                switch (event.code) {
                    case KEY_A: a = 1;break;
                    case KEY_C: c = 1;break;
                    case KEY_P: p = 1;break;
                    case KEY_E: e = 1;break;
                    case KEY_T: t = 1;break;
                    case KEY_Y: y = 1;break;
                }
            }
            if(c && a &&p) {
                printf("Get some cappuccino!\n");
                fprintf(output,"Get some cappuccino!\n");
            }
            if(p && e) {
                printf("I passed the Exam!\n");
                fprintf(output,"I passed the Exam!\n");
            }
            if(t && y) {
                printf("Wow it's a shortcut!\n");
                fprintf(output,"Wow it's a shortcut!\n");
            }
            fflush(output);
        }
    }
    return  0;
}
