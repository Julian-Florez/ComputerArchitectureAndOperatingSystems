#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

// Función para recorrer directorios de forma recursiva
void listFiles(const char *path) {
    struct dirent *dp;
    DIR *dir = opendir(path);

    // Verificar si el directorio se pudo abrir
    if (dir == NULL) {
        perror("Error al abrir el directorio");
        return;
    }

    // Recorrer cada entrada en el directorio
    while ((dp = readdir(dir)) != NULL) {
        // Saltar los directorios especiales "." y ".."
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        // Crear la ruta completa al archivo o subdirectorio
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, dp->d_name);

        struct stat fileStat;
        if (stat(fullPath, &fileStat) == 0) {
            if (S_ISDIR(fileStat.st_mode)) {
                // Si es un directorio, hacer una llamada recursiva
                listFiles(fullPath);
            } else if (S_ISREG(fileStat.st_mode)) {
                // Si es un archivo regular, imprimir su tamaño
                printf("Archivo: %s, Tamaño: %ld bytes\n", fullPath, fileStat.st_size);
            }
        } else {
            perror("Error al obtener información del archivo");
        }
    }

    // Cerrar el directorio
    closedir(dir);
}

int main(int argc, char *argv[]) {
    // Verificar si se proporcionó el directorio inicial
    if (argc < 2) {
        printf("Uso: %s <directorio>\n", argv[0]);
        return 1;
    }

    // Llamar a la función para listar archivos y tamaños
    listFiles(argv[1]);

    return 0;
}
