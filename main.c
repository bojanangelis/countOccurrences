#include <stdio.h>
#include <string.h>

int countOccurrences(char *line, char *word) {
    int i, counter = 0;
    for (i = 0; i < strlen(line) - strlen(word); i++) {
        if (!strncmp(word, line + i, strlen(word))) {
            ++counter;
        }
    }
    return counter;
}

int countOccurrencesRecursive(char *line, char *word) {
    char *res = strstr(line, word);
    if (res == NULL) return 0;
    //overlap res + 1 ==> res + strlen(word)
    return 1 + countOccurrencesRecursive(res + strlen(word), word);
}

int main() {
    FILE *f = fopen("/Users/bojanangjeleski/CLionProjects/untitled135/text.txt", "r");
    char word[100];
    scanf("%s", word);
    char currLine[100];
    int occurrences = 0;
    while (fgets(currLine, 100, f) != NULL) {
        occurrences += countOccurrencesRecursive(currLine, word);
    }

    printf("Zborot %s se pojavuva %d pati vo datotekata.", word, occurrences);
    fclose(f);
    return 0;
}

/*
 Задача 6
Да се напише програма која на екран ќе го отпечати бројот на појавувања на даден збор составен само од цифри (зборот се чита од тастатура) во текстуална датотека со име dat.txt.

Пример
Ако од тастатура се внесе зборот

123

и ако датотеката dat.txt ја има следнава содржина:

Zdravo 123, kako si?
Eve 321, dobro sum. A ti?
I jas dobro. Kako se tvoite 123? Ima li neshto novo? 123
Dobri se i tie. Si kupiv avtomobil.
тогаш програмата треба да отпечати:

Zborot 123 se pojavuva 3 pati vo datotekata.
 */