#include <stdio.h>
#include <stdlib.h>

char* generate_unique_filename()
{
    char* unique_filename;
    char address_str;

    unique_filename = malloc((10 + 1) * sizeof(char));
    if (!unique_filename)
    {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    printf("%p", &unique_filename);
    printf("%s_unique", address_str);

    return (unique_filename);
}

int main(void)
{
    char* filename;

    filename = generate_unique_filename();
    printf("Unique Filename: %s\n", filename);
    free(filename);

    return (0);
}
