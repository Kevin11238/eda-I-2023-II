#include <stdio.h>
#include <stdlib.h>

// Funciones para obtener los movimientos permitidos del alfil y la torre
void alfil(int x, int y, int movi[][2], int* num_movi) {
    *num_movi= 0;
    for (int i = 1; i < 8; i++) {
        if (x+i <= 7 && y+i <= 7) {
            movi[*num_movi][0] = x+i;
            movi[*num_movi][1] = y+i;
            (*num_movi)++;
        }
        if (x+i <= 7 && y-i >= 0) {
            movi[*num_movi][0] = x+i;
            movi[*num_movi][1] = y-i;
            (*num_movi)++;
        }
        if (x-i >= 0 && y+i <= 7) {
            movi[*num_movi][0] = x-i;
            movi[*num_movi][1] = y+i;
            (*num_movi)++;
        }
        if (x-i >= 0 && y-i >= 0) {
            movi[*num_movi][0] = x-i;
            movi[*num_movi][1] = y-i;
            (*num_movi)++;
        }
    }
}

void torre(int x, int y, int movi[][2], int* num_movi) {
    *num_movi = 0;
    for (int i = 1; i < 8; i++) {
        if (x+i <= 7) {
            movi[*num_movi][0] = x+i;
            movi[*num_movi][1] = y;
            (*num_movi)++;
        }
        if (x-i >= 0) {
            movi[*num_movi][0] = x-i;
            movi[*num_movi][1] = y;
            (*num_movi)++;
        }
        if (y+i <= 7) {
            movi[*num_movi][0] = x;
            movi[*num_movi][1] = y+i;
            (*num_movi)++;
        }
        if (y-i >= 0) {
            movi[*num_movi][0] = x;
            movi[*num_movi][1] = y-i;
            (*num_movi)++;
        }
    }
}

// Función para imprimir el tablero con la pieza y los movimientos permitidos
void print_tablero(char pieza, int x, int y, int movi[][2], int num_movi) {
    char tablero[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tablero[i][j] = ' ';
        }
    }
    tablero[x][y] = pieza;
    for (int i = 0; i < num_movi; i++) {
        tablero[movi[i][0]][movi[i][1]] = '*';
    }
    for (int i = 0; i < 8; i++) {
        printf("|");
        for (int j = 0; j < 8; j++) {
            printf("%c|", tablero[i][j]);
        }
        printf("\n");
    }
}

// Función principal
int main() {
    int x, y, opcion;
    int moves[28][2];
    int num_movi;

    while (1) {
        printf("Menu:\n");
        printf("1. Alfil\n");
        printf("2. Torre\n");
        printf("3. Salir\n");
        printf("Elija una opcion:\n");
        scanf("%d", &opcion);
            if (opcion == 1) {
        printf("Ingrese las coordenadas x e y del alfil (0-7)*sin coma*:\n ");
        scanf("%d %d", &x, &y);
        alfil(x, y, moves, &num_movi);
        print_tablero('A', x, y, moves, num_movi);
    } else if (opcion == 2) {
        printf("Ingrese las coordenadas x e y de la torre (0-7)*sin coma*:\n");
        scanf("%d %d", &x, &y);
        torre(x, y, moves, &num_movi);
        print_tablero('T', x, y, moves, num_movi);
    } else if (opcion == 3) {
        break;
    } else {
        printf("Opcion no valida\n");
    }
}

return 0;
}