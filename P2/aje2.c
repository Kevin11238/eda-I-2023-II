#include <stdio.h>
#include <stdlib.h>

#define TAM 8

void imprimir_tablero(char tablero[TAM][TAM])
{
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void movimientos_reina(int fila, int columna, char tablero[TAM][TAM])
{
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

void movimientos_rey(int fila, int columna, char tablero[TAM][TAM])
{
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
    char tablero[TAM][TAM];
    int opcion, fila, columna;

    
        // Imprimir menú
    while (1) {
        printf("***MENU****\n1.- Reina\n2.- Rey\n3.- Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

         if (opcion == 1) {
            // Inicializar tablero
            for (int i = 0; i < TAM; i++) {
                for (int j = 0; j < TAM; j++)
                tablero[i][j] = '-';
            }
        // Pedir coordenadas
        printf("\nIngresa la fila (1-%d): ", TAM);
        scanf("%d", &fila);
        fila--;
        printf("Ingresa la columna (1-%d): ", TAM);
        scanf("%d", &columna);
        columna--;
	 
            tablero[fila][columna] = 'Q';
            movimientos_reina(fila, columna, tablero);
	}
		else if (opcion == 2) {
			 // Inicializar tablero
            for (int i = 0; i < TAM; i++) {
                for (int j = 0; j < TAM; j++)
                tablero[i][j] = '-';
            }
        // Pedir coordenadas
        printf("\nIngresa la fila (1-%d): ", TAM);
        scanf("%d", &fila);
        fila--;
        printf("Ingresa la columna (1-%d): ", TAM);
        scanf("%d", &columna);
        columna--;
        
            tablero[fila][columna] = 'K';
            movimientos_rey(fila, columna, tablero);
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
     }

      
    



