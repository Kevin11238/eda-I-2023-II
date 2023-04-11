#include <stdio.h>
#include <stdlib.h>

// Estructura para un nodo de la cola
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Estructura para la cola
typedef struct Cola {
    Nodo* primero;
    Nodo* ultimo;
} Cola;

// Estructura para la pila
typedef struct Pila {
    int elementos[10];
    int tope;
} Pila;

// Prototipos de funciones
void encolar(Cola* cola, int dato);
int desencolar(Cola* cola);
void push(Pila* pila, int dato);
int pop(Pila* pila);

int main() {
    // Inicializar pila y cola
    Pila pila = {.elementos = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, .tope = 10};
    Cola cola = {.primero = NULL, .ultimo = NULL};

    int opcion = 0;
    int turno = 0;

    do {
        // Mostrar menú
        printf("\n");
        printf("Sistema de turnos\n");
        printf("1. Formarse\n");
        printf("2. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Obtener turno de la pila
                turno = pop(&pila);

                // Agregar elemento a la cola
                encolar(&cola, turno);

                // Mostrar mensaje
                printf("Se ha asignado el turno %d al elemento de la cola\n", turno);
                break;
            case 2:
                // Salir del programa
                break;
            default:
                // Opción inválida
                printf("Opción inválida\n");
                break;
        }
    } while (opcion != 2);

    // Mostrar estado de la pila y la cola
    printf("\n");
    printf("Estado de la pila: ");
    for (int i = pila.tope; i < 10; i++) {
        printf("%d ", pila.elementos[i]);
    }
    printf("\n");

    printf("Estado de la cola: ");
    Nodo* actual = cola.primero;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");

    return 0;
}

// Función para agregar un elemento a la cola
void encolar(Cola* cola, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    if (cola->primero == NULL) {
        cola->primero = nuevoNodo;
    } else {
        cola->ultimo->siguiente = nuevoNodo;
    }
    cola->ultimo = nuevoNodo;
}

// Función para quitar el primer elemento de la cola
int desencolar(Cola* cola) {
    Nodo* primero = cola->primero;
    int dato = primero->dato;
    cola->primero = primero->siguiente;
    if (cola->primero == NULL) {
        cola->ultimo = NULL;
    }
    free(primero);
    return dato;
}

// Función para agregar un elemento a la pila
void push(Pila* pila, int dato) {
    if (pila->tope < 10) {
        pila->elementos[pila->tope] = dato;
        pila->tope++;
    }
}

// Función para quitar y devolver el elemento superior de la pila
int pop(Pila* pila) {
    if (pila->tope == 0) {
        return -1; // Error, la pila está vacía
    }
    pila->tope--;
    return pila->elementos[pila->tope];
}
