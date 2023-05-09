#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Definición de la estructura de la lista
typedef struct List {
    Node *head;
    Node *tail;
    int size;
} List;

// Función para crear un nuevo nodo
Node *createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Función para crear una nueva lista
List *createList() {
    List *newList = (List*) malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

// Función para agregar un elemento al principio de la lista
void addFirst(List *list, int data) {
    Node *newNode = createNode(data);
    if(list->size == 0) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->size++;
}

// Función para agregar un elemento al final de la lista
void addLast(List *list, int data) {
    Node *newNode = createNode(data);
    if(list->size == 0) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        newNode->next = list->head;
        list->head->prev = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// Función para agregar un elemento en una posición específica de la lista
void addAt(List *list, int data, int position) {
    if(position < 1 || position > list->size + 1) {
        printf("Error: Posición inválida.\n");
        return;
    }
    if(position == 1) {
        addFirst(list, data);
    } else if(position == list->size + 1) {
        addLast(list, data);
    } else {
        Node *newNode = createNode(data);
        Node *currentNode = list->head;
        int i = 1;
        while(i < position - 1) {
            currentNode = currentNode->next;
            i++;
        }
        newNode->prev = currentNode;
        newNode->next = currentNode->next;
        currentNode->next->prev = newNode;
        currentNode->next = newNode;
        list->size++;
    }
}

// Función para eliminar el primer elemento de la lista
void removeFirst(List *list) {
    if(list->size == 0) {
        printf("Error: Lista vacía.\n");
        return;
    }
    if(list->size == 1) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = list->tail;
        list->tail->next = list->head;
    }
    list->size--;
}

// Función para eliminar el último elemento de la lista
void removeLast(List *list) {
    if(list->size == 0) {
        printf("Error: Lista vacía.\n");
        return;
    }
    if(list->size == 1) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        free(list->tail->next);
        list->tail->next = list->head;
        list->head->prev = list->tail;
    }
    list->size--;
}

// Función para eliminar un elemento en una posición específica de la lista
void removeAt(List *list, int position) {
    if(position < 1 || position > list->size) {
        printf("Error: Posición inválida.\n");
        return;
    }
    if(position == 1) {
        removeFirst(list);
    } else if(position == list->size) {
        removeLast(list);
    } else {
        Node *currentNode = list->head;
        int i = 1;
        while(i < position) {
            currentNode = currentNode->next;
            i++;
        }
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
        free(currentNode);
        list->size--;
    }
}

// Función para imprimir la lista
void printList(List *list) {
    if(list->size == 0) {
        printf("La lista está vacía.\n");
        return;
    }
    Node *currentNode = list->head;
    printf("La lista es: ");
    do {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    } while(currentNode != list->head);
    printf("\n");
}

int main() {
    List *list = createList();
    int opcion, dato, posicion;
    while(1) {
        printf("\nOpciones:\n");
        printf("\n\t1. Agregar un elemento al principio de la lista.\n");
        printf("\n\t2. Agregar un elemento al final de la lista.\n");
        printf("\n\t3. Agregar un elemento en una posicion especifica de la lista.\n");
        printf("\n\t4. Eliminar el primer elemento de la lista.\n");
        printf("\n\t5. Eliminar el Ultimo elemento de la lista.\n");
        printf("\n\t6. Eliminar un elemento en una posicion especifica de la lista.\n");
        printf("\n\t7. Imprimir la lista.\n");
        printf("\n\t8. Salir del programa.\n");
        printf("\n\n\tElija una opcion:\n\t ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                printf("Ingrese el elemento a agregar: ");
                scanf("%d", &dato);
                addFirst(list, dato);
                break;
            case 2:
                printf("Ingrese el elemento a agregar: ");
                scanf("%d", &dato);
                addLast(list, dato);
                break;
            case 3:
                printf("Ingrese el elemento a agregar: ");
                scanf("%d", &dato);
                printf("Ingrese la posicion donde desea agregar el elemento: ");
                scanf("%d", &posicion);
                addAt(list, dato, posicion);
                break;
            case 4:
                removeFirst(list);
                break;
            case 5:
                removeLast(list);
                break;
            case 6:
                printf("Ingrese la posición del elemento a eliminar: ");
                scanf("%d", &posicion);
                removeAt(list, posicion);
                break;
            case 7:
                printList(list);
                break;
            case 8:
                printf("Saliendo del programa...\n");
                exit(0);
            default:
                printf("Opción inválida.\n");
        }
    }
    return 0;
}

