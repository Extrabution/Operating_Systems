#include <stdio.h>
#include <unistd.h>
#include <linux/input.h>
#include <fcntl.h>


int main(){
    int keyEvent;
    struct input_event event;
    keyEvent = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);

    if(keyEvent == -1)
        return -1;
    while(1) {
        read(keyEvent, &event, sizeof(event));
        if(event.type == EV_KEY) {
            if(event.value == 1)
                printf("PRESSED 0x%04x (%d)\n", event.code, event.code);
            else if(event.value == 0)
                printf("RELEASED 0x%04x (%d)\n", event.code, event.code);

        }
    }
    return 0;
}