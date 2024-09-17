
/*
#include <stdio.h>

int main() {
    char inputString[100];

    printf("Enter a string with spaces: ");
    scanf("%99[^\n]", inputString);

    printf("You entered: %s\n", inputString);

    return 0;
} */
#include <stdio.h>

int main() {
    char inputString[100];

    printf("Enter a string with spaces: ");
    fgets(inputString, sizeof(inputString), stdin);


    printf("You entered: %s\n", inputString);

    return 0;
}

