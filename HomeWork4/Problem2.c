#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStatus(int status)
{
    switch(status)
            {
                case 0: printf("Door: CLOSED\n");
                break;
                case 1: printf("Door: OPENING\n");
                break;
                case 2: printf("Door: OPEN\n");
                break;
                case 3: printf("Door: CLOSING\n");
                break;
                case 4: printf("Door: STOPPED_WHILE_CLOSING\n");
                break;
                case 5: printf("Door: STOPPED_WHILE_OPENING\n");
                break;
            }
}

int main()
{
    char *command =  (char*) malloc(1);
    int status = 0;
    printStatus(status);

    while(scanf("%s", command) != EOF)
    {
        if(strcmp(command, "button_clicked") == 0)
        {
            switch(status)
            {
                case 0:
                status = 1;
                printStatus(status);
                break;
                case 1:
                status = 5;
                printStatus(status);
                break;
                case 2:
                status = 3;
                printStatus(status);
                break;
                case 3:
                status = 4;
                printStatus(status);
                break;
                case 4:
                status = 1;
                printStatus(status);
                break;
                case 5:
                status = 3;
                printStatus(status);
                break;
            }
        }
        else if(strcmp(command, "cycle_complete") == 0)
        {
            switch(status)
            {
                case 1:
                status = 2;
                printStatus(status);
                break;
                case 3:
                status = 0;
                printStatus(status);
                break;
            }
        }
    }

    free(command);
    return 0;
}
