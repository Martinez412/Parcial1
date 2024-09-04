%{
#include <stdio.h>
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*[ ]*=[ ]*lambda[ ]*[a-zA-Z_][a-zA-Z0-9_]*[ ]*:[ ]*[a-zA-Z_][a-zA-Z0-9_]*[ ]*\*\*[ ]*[0-9]+ {
    printf("ACEPTA (lambda detectada)\n");
}

print[ ]*\([a-zA-Z_][a-zA-Z0-9_]*[ ]*\([0-9]+\)\) {
    printf("ACEPTA (print detectado)\n");
}

.|\n {
    printf("NO ACEPTA\n");
}

%%

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Uso: %s <archivo.txt>\n", argv[0]);
        return 1;
    }

    FILE *archivo = fopen(argv[1], "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo %s\n", argv[1]);
        return 1;
    }

    yyin = archivo;
    yylex();
    fclose(archivo);

    return 0;
}
