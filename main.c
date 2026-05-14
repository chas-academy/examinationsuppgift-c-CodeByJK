//Write your code in this file
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STUDENTS 5
#define TESTS 13

void fixName(char *name) {
    name[0] = toupper(name[0]);
    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
}

int main() {
    char names[STUDENTS][20];
    int scores[STUDENTS][TESTS];
    double averages[STUDENTS];

    for (int i = 0; i < STUDENTS; i++) {
        scanf("%s", names[i]);
        for (int j = 0; j < TESTS; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    for (int i = 0; i < STUDENTS; i++) {
        int sum = 0;
        for (int j = 0; j < TESTS; j++) {
            sum += scores[i][j];
        }
        averages[i] = sum / (double)TESTS;
    }

    int bestIndex = 0;
    for (int i = 1; i < STUDENTS; i++) {
        if (averages[i] > averages[bestIndex]) {
            bestIndex = i;
        }
    }

    double groupSum = 0;
    for (int i = 0; i < STUDENTS; i++) {
        groupSum += averages[i];
    }
    double groupAvg = groupSum / STUDENTS;

    fixName(names[bestIndex]);
    printf("%s\n", names[bestIndex]);

    for (int i = 0; i < STUDENTS; i++) {
        if (averages[i] < groupAvg) {
            fixName(names[i]);
            printf("%s\n", names[i]);
        }
    }

    return 0;
}


