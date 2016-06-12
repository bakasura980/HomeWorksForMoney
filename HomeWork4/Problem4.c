#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Recursion(int x, int y)
{
    if(y == 1)
    {
        return x;
    }

    return x * Recursion(x, y-1);
}

int main()
{
    int nums[10];
    char input[10];
    int Sum = 7;

    int countOfResults = 0;
    scanf("%s", input);
    scanf("%d", &Sum);
    int z, c, f;

    for(int i = 0; i < strlen(input); i++)
    {
        nums[i] = input[i] - '0';
    }

    int end = Recursion(2, strlen(input) - 1);
    char result[end][26];
    int opers[strlen(input) - 1];



    for(int i = end - 1; i >= 0;i--)
    {

        int operNum = i;
        z = 0;

        while(operNum != 0)
        {
            int r = operNum % 2;
            operNum /= 2;
            opers[z] = r;
            z++;
        }

        int sum = nums[0];
        for(z = 1; z < strlen(input); z++)
        {
            if(opers[z - 1] != 0)
            {
                sum += nums[z];
            }
            else
            {
                sum -= nums[z];
            }
        }

        if(sum == Sum)
        {
            char arr[110];
            z = 1;
            arr[0] = nums[0] + '0';
            for( c = 1; c < strlen(input) * 2 - 1;c+=2, z++)
            {
                if(opers[z - 1] != 0)
                {
                    arr[c] = '+';
                }
                else
                {
                    arr[c] = '-';
                }

                arr[c+1] = nums[z] + '0';

            }

            arr[c] = '=';
            arr[c+1] = '\0';
            strcpy(result[countOfResults], arr);
            countOfResults++;
            //printf("%s", a}rr);
            //printf("%d\n", Sum);
        }
}

    char temp[25];

    for(int i=0; i < countOfResults ; i++){
        for( c=i+1; c< countOfResults; c++)
        {
            if(strcmp(result[i],result[c]) < 0)
            {
                strcpy(temp,result[i]);
                strcpy(result[i],result[c]);
                strcpy(result[c],temp);
            }
        }
    }

    for(int i = 0; i < countOfResults;i++)
    {
        printf("%s%d\n", result[i], Sum);
    }

    if(!countOfResults)
    {
        printf("-1");
    }

    return 0;

}
