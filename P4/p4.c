#include <stdio.h>
#include <stdlib.h>

#define TAM 8

typedef struct {
    int fila;
    int columna;
} Coordenada;

void imprimir_tablero(char** tablero)
{
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void movimientos_reina(Coordenada coordenada, char** tablero)
{
    int fila = coordenada.fila;
    int columna = coordenada.columna;
    
    // Movimientos horizontales y verticales
    for (int i = 0; i < TAM; i++) {
        if (i != columna) tablero[fila][i] = '*';
        if (i != fila) tablero[i][columna] = '*';
    }
    // Movimientos diagonales
    int i = fila, j = columna;
    while (i < TAM && j < TAM) {
        if (i != fila && j != columna) tablero[i][j] = '*';
        i++;
        j++;
    }
    i = fila, j = columna;
    while (i >= 0 && j >= 0) {
        if (i != fila && j != columna) tablero[i][j] = '*';
        i--;
        j--;
    }
    i = fila, j = columna;
    while (i >= 0 && j < TAM) {
        if (i != fila && j != columna) tablero[i][j] = '*';
        i--;
        j++;
    }
    i = fila, j = columna;
    while (i < TAM && j >= 0) {
        if (i != fila && j != columna) tablero[i][j] = '*';
        i++;
        j--;
    }
}

void movimientos_rey(Coordenada coordenada, char** tablero)
{
    int fila = coordenada.fila;
    int columna = coordenada.columna;
    
    // Movimientos horizontales y verticales
    if (columna > 0) tablero[fila][columna-1] = '*';
    if (columna < TAM-1) tablero[fila][columna+1] = '*';
    if (fila > 0) tablero[fila-1][columna] = '*';
    if (fila < TAM-1) tablero[fila+1][columna] = '*';
    // Movimientos diagonales
    if (fila > 0 && columna > 0) tablero[fila-1][columna-1] = '*';
    if (fila > 0 && columna < TAM-1) tablero[fila-1][columna+1] = '*';
    if (fila < TAM-1 && columna > 0) tablero[fila+1][columna-1] = '*';
    if (fila < TAM-1 && columna < TAM-1) tablero[fila+1][columna+1] = '*';
}
int main()
{
    char** tablero = (char**) malloc(TAM * sizeof(char*)); // asignación dinámica de memoria
    for (int i = 0; i < TAM; i++) {
        tablero[i] = (char*) malloc(TAM * sizeof(char));
    }
    
    int opcion;
    Coordenada coordenada;
    
    while (1) {
        printf("\n1.- Reina\n2.- Rey\n3.- salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        
        if (opcion ==1) {
            // Inicializar tablero
            for (int i = 0; i < TAM; i++) {
                for (int j = 0; j < TAM; j++)
                    tablero[i][j] = '-';
            }
            // Pedir coordenadas
            printf("\nIngresa la fila (1-%d): ", TAM);
            scanf("%d", &coordenada.fila);
            coordenada.fila--;
            printf("Ingresa la columna (1-%d): ", TAM);
            scanf("%d", &coordenada.columna);
            coordenada.columna--;
                
            tablero[coordenada.fila][coordenada.columna] = 'Q';
            movimientos_reina(coordenada, tablero);
                
        }
        
        else if (opcion == 2) {
            // Inicializar tablero
            for (int i = 0; i < TAM; i++) {
                for (int j = 0; j < TAM; j++)
                    tablero[i][j] = '-';
            }
            // Pedir coordenadas
            printf("\nIngresa la fila (1-%d): ", TAM);
            scanf("%d", &coordenada.fila);
            coordenada.fila--;
            printf("Ingresa la columna (1-%d): ", TAM);
            scanf("%d", &coordenada.columna);
            coordenada.columna--;
                
            tablero[coordenada.fila][coordenada.columna] = 'K';
            movimientos_rey(coordenada, tablero);
        }
       else if (opcion == 3) {
            break;
        }
        else {
            printf("Escogiste una opcion invalida");
        }
        
        // Imprimir tablero con movimientos válidos
        printf("\nMovimientos validos:\n");
        imprimir_tablero(tablero);
    }
    
    for (int i = 0; i < TAM; i++) {
        free(tablero[i]);
    }
    free(tablero);
    return 0;
}
