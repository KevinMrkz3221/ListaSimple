typedef struct Nodo {
    char Nombre[20];
    char Apellido[20];
    int Matricula;

    struct Nodo* Psig;
}Nodo;