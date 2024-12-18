#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
void f(char* input) {
    int countSpaces = 0;
    int i = 0, max = 0, maxi = 0;
    while (input[i] != '\0') {
        if (input[i] == ' ') {
            countSpaces++;
            if (countSpaces > max) {
                max = countSpaces;
                maxi = i - max + 1;
            }
        }
        else {
            countSpaces = 0;
        }
        i++;
    }
    if (max % 3 == 0) {
        for (int i = maxi; i < maxi + max; i++)
        {
            input[i] = '*';
        }
    }
    else {
        for (int i = 0; i < max; i++) {
            memmove(&input[maxi], &input[maxi + 1], strlen(input) - maxi);
        }
    }
}

void main() {
    char input[100];
    printf("do: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    f(input);
    printf("posle: %s\n", input);
}*/


/*

void f(char* input) {
    int countSpaces = 0;
    int i = 0, max = 0, maxi = 0;
    while (input[i] != '\0') {
        if (input[i] == ' ') {
            countSpaces++;
            if (countSpaces > max) {
                max = countSpaces;
                maxi = i - max + 1;
            }
        }
        else {
            countSpaces = 0;
        }
        i++;
    }
    if (max % 3 == 0) {
        for (int i = maxi; i < maxi + max; i++)
        {
            input[i] = '*';
        }
    }
    else {
        for (int i = 0; i < max; i++) {
            memmove(&input[maxi], &input[maxi + 1], strlen(input) - maxi);
        }
    }
}


void main() {
    char input[100];
    printf("do: ");
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        input[i] = c;
        i++;
    }
    input[i] = '\0';
    f(input);
    printf("posle: %s\n", input);
}
*/






/*
void processString(char* input) {
    int countSpaces = 0;
    int i = 0, max = 0, maxi = 0;
    while (input[i] != '\0') {
        if (input[i] == ' ') {
            countSpaces++;
            if (countSpaces > max) {
                max = countSpaces;
                maxi = i - max + 1;
            }
        }
        else {
            countSpaces = 0;
        }
        i++;
    }
    if (max % 3 == 0) {
        for (int i = maxi; i < maxi + max; i++)
        {
            input[i] = '*';
        }
    }
    else {
        for (int i = 0; i < max; i++) {
            memmove(&input[maxi], &input[maxi + 1], strlen(input) - maxi);
        }
    }
}
int main() {
    FILE* fileIn = NULL;
    FILE* fileOut = NULL;
    errno_t errIn = fopen_s(&fileIn, "input.txt", "r");
    errno_t errOut = fopen_s(&fileOut, "output.txt", "w");

    if (!fileIn || !fileOut) {
        fprintf(stderr, "Ошибка открытия файла.\n");
        exit(EXIT_FAILURE);
    }
    char line[100];
    while (fgets(line, sizeof(line), fileIn)) {
        line[strcspn(line, "\n")] = '\0';

        processString(line);

        fputs(line, fileOut);
        fputc('\n', fileOut);

    }
    fclose(fileIn);
    fclose(fileOut);
    return 0;
}*/





/*

void processString(char* input) {
    int countSpaces = 0;
    int i = 0, max = 0, maxi = 0;
    while (input[i] != '\0') {
        if (input[i] == ' ') {
            countSpaces++;
            if (countSpaces > max) {
                max = countSpaces;
                maxi = i - max + 1;
            }
        }
        else {
            countSpaces = 0;
        }
        i++;
    }
    if (max % 3 == 0) {
        for (int i = maxi; i < maxi + max; i++)
        {
            input[i] = '*';
        }
    }
    else {
        for (int i = 0; i < max; i++) {
            memmove(&input[maxi], &input[maxi + 1], strlen(input) - maxi);
        }
    }
}

int main() {
    char* input = NULL;

    printf("do: ");

    // Динамически выделяем память под строку, используя malloc
    input = (char*)malloc(sizeof(char));

    if (input == NULL) {
        fprintf(stderr, "error\n");
        return 1;
    }

    int i = 0;
    char c;

    while ((c = getchar()) != '\n' && c != EOF) {
        input[i++] = c;

        input = (char*)realloc(input, sizeof(char) * (i + 1));

        if (input == NULL) {
            fprintf(stderr, "error 1\n");
            free(input);
            return 1;
        }
    }

    input[i] = '\0';

    processString(input);

    printf("posle: %s\n", input);

    free(input);

    return 0;
}*/








/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void processString(char* input) {
    int countSpaces = 0;
    int i = 0, max = 0, maxi = 0;
    while (input[i] != '\0') {
        if (input[i] == ' ') {
            countSpaces++;
            if (countSpaces > max) {
                max = countSpaces;
                maxi = i - max + 1;
            }
        }
        else {
            countSpaces = 0;
        }
        i++;
    }
    if (max % 3 == 0) {
        for (int i = maxi; i < maxi + max; i++)
        {
            input[i] = '*';
        }
    }
    else {
        for (int i = 0; i < max; i++) {
            memmove(&input[maxi], &input[maxi + 1], strlen(input) - maxi);
        }
    }
}
int main() {

    char* input = NULL;

    printf("do: ");

    // Динамически выделяем память под строку, используя malloc
    input = (char*)malloc(sizeof(char));

    if (input == NULL) {
        fprintf(stderr, "error\n");
        return 1;
    }

    int i = 0;
    char c;

    while ((c = getchar()) != '\n' && c != EOF) {
        input[i++] = c;

        input = (char*)realloc(input, sizeof(char) * (i + 1));

        if (input == NULL) {
            fprintf(stderr, "error 1\n");
            free(input);
            return 1;
        }
    }

    input[i] = '\0';

    FILE* fileOut = NULL;
    errno_t errOut = fopen_s(&fileOut, "output.txt", "w");

    if (!fileOut) {
        fprintf(stderr, "Ошибка открытия файла.\n");
        exit(EXIT_FAILURE);
    }

    processString(input);

    if (fputs(input, fileOut) == EOF) {
        fprintf(stderr, "Ошибка записи строки в файл\n");
        return 1;
    }


    fclose(fileOut);
    return 0;
}
*/




