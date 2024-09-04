#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int count_occurrences(FILE *file, const char *keyword) {
    char line[MAX_LINE_LENGTH];
    int count = 0;
    size_t keyword_len = strlen(keyword);

    while (fgets(line, sizeof(line), file)) {
        char *ptr = line;
        while ((ptr = strstr(ptr, keyword)) != NULL) {
            count++;
            ptr += keyword_len;
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <archivo> <clave>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    const char *keyword = argv[2];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }

    int occurrences = count_occurrences(file, keyword);
    fclose(file);

    printf("La palabra '%s' se repite %d veces en el texto.\n", keyword, occurrences);

    return EXIT_SUCCESS;
}
