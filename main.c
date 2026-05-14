//Write your code in this file
#include <stdio.h>
#include <ctype.h> // funktioner för stor och liten bokstav

// Antal studenter och antal testresultat per student
// Dessa värden styr hela programmet
#define STUDENTS 5
#define TESTS 13

// Funktion, gör första bokstaven stor och resten små
void formatNameCase(char *name) {
    name[0] = toupper(name[0]);
    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
}

// Huvudprogrammet
int main() {
    // Namn på studenterna (max 20 tecken per namn)
    char names[STUDENTS][20];

    // Tabell med poäng: 5 studenter × 13 prov
    int scores[STUDENTS][TESTS];

    // Medelvärden för varje student
    double averages[STUDENTS];

    // Input
    // Vi läser in namn + 13 testresultat för varje student
    for (int i = 0; i < STUDENTS; i++) {
        scanf("%s", names[i]);
        for (int j = 0; j < TESTS; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    // Beräknar medelvärden
    for (int i = 0; i < STUDENTS; i++) {
        int sum = 0;
        for (int j = 0; j < TESTS; j++) {
            sum += scores[i][j];
        }
        averages[i] = sum / (double)TESTS;
    }

    // Hitta student med högst medelvärde
    int bestIndex = 0;
    for (int i = 1; i < STUDENTS; i++) {
        if (averages[i] > averages[bestIndex]) {
            bestIndex = i;
        }
    }

    // Beräkna gruppens genomsnitt
    double groupSum = 0;
    for (int i = 0; i < STUDENTS; i++) {
        groupSum += averages[i];
    }
    double groupAvg = groupSum / STUDENTS;

    // Output
    // Korrigera namn och skriv ut den bästa studenten 
    formatNameCase(names[bestIndex]);
    printf("%s\n", names[bestIndex]);

    // Skriv ut alla som ligger under gruppens medelvärde
    // och korrigerar namn
    for (int i = 0; i < STUDENTS; i++) {
        if (averages[i] < groupAvg) {
            formatNameCase(names[i]);
            printf("%s\n", names[i]);
        }
    }

    return 0;
}



