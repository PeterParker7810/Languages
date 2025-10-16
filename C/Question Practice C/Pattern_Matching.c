#include <stdio.h>
#include <string.h>

int main() {
    char str[100], pattern[100], temp[100] = "";
    int start = 0;

    printf("Enter the String: ");
    scanf("%s", str);

    printf("Enter the Pattern: ");
    scanf("%s", pattern);

    int len = strlen(pattern);

    for (int i = 0; i < len; i++) {
        if (pattern[i] == '.') {
            temp[strlen(temp)] = pattern[i + 1];
            temp[strlen(temp) + 1] = '\0';
            start = i + 1;
        } 
        else {
            temp[strlen(temp)] = pattern[i];
            temp[strlen(temp) + 1] = '\0';
        }
    }

    strcpy(pattern, temp);
    strcpy(temp, "");

    char *pos = strchr(pattern, '*');
    if (pos != NULL) {
        memmove(pos, pos + 1, strlen(pos));  // Remove '*'
    }

    for (int i = start; i < strlen(str); i++) {
        strcat(temp, pattern + start);
    }

    strcat(pattern, temp);
    pattern[strlen(str)] = '\0';

    if (strcmp(str, pattern) == 0) {
        printf("Yess....String Matches the Pattern\n");
    } 
    else {
        printf("Noo....String does not Match the Pattern\n");
    }

    return 0;
}