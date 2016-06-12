#include <stdio.h>
#include <string.h>

int validegn(char *egn) {

    int arr[] = { 2, 4, 8, 5, 10, 9, 7, 3, 6 };
    int valid = 0, month = (egn[2] - '0') * 10 + (egn[3] - '0');

    if (strlen(egn) == 10) {

        for (int i = 0; i < strlen(egn) - 1; i++)
            valid += (egn[i] - '0') * arr[i];

        valid %= 11;
        if (valid != egn[9] - '0' || valid > 10)
            return 0;


        if (!((month >= 1 && month <= 12) || (month >= 21 && month <= 32) ||
            (month >= 41 && month <= 52)))
            return 0;

        return 1;

    } else
        return 0;
}

int main() {

    char egn[12];
    scanf("%s", egn);

    printf("%d\n", validegn(egn));

    return 0;
}
