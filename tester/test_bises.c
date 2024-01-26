#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Une fonction simple pour générer une séquence pseudo-aléatoire
unsigned int custom_random() {
    static unsigned int seed = 0;
    seed = (seed * 1103515245 + 12345) & 0xFFFFFFFF;
    return seed;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(char *str, size_t len) {
    // Initialisation de la graine pour la séquence pseudo-aléatoire
    unsigned int current_seed = (unsigned int)time(NULL);
    srand(current_seed);

    // Algorithme de Fisher-Yates pour le mélange aléatoire
    for (size_t i = len - 1; i > 0; --i) {
        size_t j = custom_random() % (i + 1);
        swap(&str[i], &str[j]);
    }
}

int main() {
    char input[] = "abcdefghijklmnopkrstuvwxyz";
    size_t len = sizeof(input) - 1;  // -1 pour exclure le caractère nul

    printf("Avant le mélange : %s\n", input);

    // Mélanger la chaîne de caractères
    shuffle(input, len);

    printf("Après le mélange : %s\n", input);
    shuffle(input, len);
    printf("Après le mélange : %s\n", input);
        shuffle(input, len);
    printf("Après le mélange : %s\n", input);
        shuffle(input, len);
    printf("Après le mélange : %s\n", input);
        shuffle(input, len);
    printf("Après le mélange : %s\n", input);
        shuffle(input, len);
    printf("Après le mélange : %s\n", input);
        shuffle(input, len);
    printf("Après le mélange : %s\n", input);
        shuffle(input, len);
    printf("Après le mélange : %s\n", input);
        shuffle(input, len);
    printf("Après le mélange : %s\n", input);
        shuffle(input, len);
    printf("Après le mélange : %s\n", input);
        shuffle(input, len);
    printf("Après le mélange : %s\n", input);
        shuffle(input, len);
    printf("Après le mélange : %s\n", input);
        shuffle(input, len);
    printf("Après le mélange : %s\n", input);
    return 0;
}
