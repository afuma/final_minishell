#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 64

char* generate_unique_filename() {
    const size_t filename_length = MAX_FILENAME_LENGTH;
    char* unique_filename = (char*)malloc((filename_length + 1) * sizeof(char));

    if (!unique_filename) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // Utiliser l'adresse d'une variable locale comme entropie
    char address_str[20];  // Une taille suffisante pour stocker une adresse en tant que chaîne
    sprintf(address_str, "%p", (void*)&unique_filename);

    // Utiliser la chaîne d'adresse comme base pour le nom de fichier
    snprintf(unique_filename, filename_length, "%s_unique", address_str);

    return unique_filename;
}

int main() {
    // Exemple d'utilisation
    char* filename = generate_unique_filename();
    printf("Unique Filename: %s\n", filename);

    // N'oubliez pas de libérer la mémoire
    free(filename);

    return 0;
}
