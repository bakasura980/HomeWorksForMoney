#include <stdio.h>
#include <string.h>

int main()
{
    char houses[4][30] = {"Bluebridge", "Alyson Books", "FUNimation Productions, Ltd." ,"Pyramid Books"};
    char id[4][6] = {"933346", "55583", "4210", "01"};

    char string[20];
    scanf("%s", string);
    int sum = 0, index = 0;

    if(strlen(string) != 17)
    {
        printf("0\n");
        return 0;
    }

    if(string[0] != '9' || string[1] != '7' || (string[2] != '8' && string[2] != 9))
    {
        printf("0\n");
        return 0;
    }

    for(int i = 0; i < strlen(string) - 1;i++)
    {
        if(string[i] != '-' && i < strlen(string))
        {
            if(index % 2 == 0)
            {
                sum += string[i] - '0';


            }
            else
            {
                sum += 3 * (string[i] - '0');
            }
            index++;
        }
    }

    sum = 10 - (sum % 10);
    if(sum != string[strlen(string) - 1] - '0')
    {
        printf("0\n");
        return 0;
    }else{
      printf("1\n");
    }


   index = 0;
    for(int i = 0; i < strlen(string); i++)
    {
        if(string[i] - '0' == -3)
        {
            index++;
            if(index == 2)
            {
                index = i + 1;
                break;
            }
        }
    }

    for(int i = 0; i < 4;i++)
    {
        if(index == (strstr(string, id[i]) - string ))
        {
            printf("%s\n", houses[i]);
            break;
        }
    }

    return 0;

}
