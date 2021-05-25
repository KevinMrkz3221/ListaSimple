void Ingresa_Datos(Nodo* Nuevo_Alumno) {
	printf("\n-----------------------\n");//Linea de formato
	printf("Introduce el nombre: ");
	scanf(" %s", Nuevo_Alumno->Nombre);
	printf("Introduce apellido paterno: ");
	scanf(" %s", Nuevo_Alumno->Apellido);
	printf("Introduce matricula: ");
	scanf(" %i", &Nuevo_Alumno->Matricula);
	printf("\n-----------------------\n");//Linea de formato
}

void Ingresa_Datos_Existentes(Nodo* Nuevo_Alumno, FILE* PF) {//Toma datos al abrir un archivo
	char Espacio1;
	char Espacio2;
	char Salto_Linea;

	Nuevo_Alumno->Psig = NULL;

	fscanf(PF, "%c", &Salto_Linea);
	fscanf(PF, "%s", Nuevo_Alumno->Nombre);
	fscanf(PF, "%c", &Espacio1);
	fscanf(PF, "%s", Nuevo_Alumno->Apellido);
	fscanf(PF, "%c", &Espacio2);
	fscanf(PF, "%i", &Nuevo_Alumno->Matricula);

}


Nodo* Crea_Nodo(Nodo* Lista, FILE* PF) {

	Nodo* Nuevo_Alumno, * A;
	Nuevo_Alumno = NULL;

	if (PF == NULL) {
		Nuevo_Alumno = (Nodo*)malloc(sizeof(Nodo));
		Nuevo_Alumno->Psig = NULL;
		Ingresa_Datos(Nuevo_Alumno);


		if (Lista == NULL) {
			Lista = Nuevo_Alumno;
		}
		else {
			A = Lista;
			while (A->Psig != NULL) {
				A = A->Psig;

			}
			A->Psig = Nuevo_Alumno;
		}
	}
	else {
		while (!feof(PF)) {
			Nuevo_Alumno = (Nodo*)malloc(sizeof(Nodo));
			Ingresa_Datos_Existentes(Nuevo_Alumno, PF);

			if (Lista == NULL) {
				Lista = Nuevo_Alumno;
			}
			else {
				A = Lista;
				while (A->Psig != NULL) {
					A = A->Psig;
				}
				A->Psig = Nuevo_Alumno;
			}
		}
	}
	return Lista;
}

void Imprime_Lista(Nodo* Lista) {
	printf("\n-----------------------\n");//Linea de formato
	if (Lista == NULL) {
		printf("La lista esta vacia\n");
	}
	else {
		printf("%20s%20s%20s\n", "Nombre", "Apellido", "Matricula");

		while (Lista != NULL) {
			printf("%20s%20s%20i\n", Lista->Nombre, Lista->Apellido, Lista->Matricula);
			Lista = Lista->Psig;
		}
	}
	printf("\n-----------------------\n");//Linea de formato
}

Nodo* Busca_Alumno(Nodo* Lista) {
	int Matricula;

	if (Lista == NULL) {
		printf("\n-----------------------\n");//Linea de formato
		printf("La lista esta vacia\n");
		return NULL;
	}
	else {
		printf("\n-----------------------\n");//Linea de formato
		printf("Introduce la matricula que quieres buscar: ");
		scanf(" %i", &Matricula);
		for (;;) {

			if (Lista->Matricula == Matricula) {
				printf("\n-----------------------\n");//Linea de formato
				printf("\nSe encontro alumno\n\n");
				printf("%20s%20s%20s\n", "Nombre", "Apellido", "Matricula");
				printf("%20s%20s%20i\n", Lista->Nombre, Lista->Apellido, Lista->Matricula);
				printf("\n-----------------------\n");//Linea de formato
				return Lista;
			}

			if (Lista->Psig == NULL) {
				printf("\n-----------------------\n");//Linea de formato
				printf("\nNo se encontro alumno\n");
				printf("\n-----------------------\n");//Linea de formato
				return NULL;
			}
			Lista = Lista->Psig;
		}
	}
	printf("\n-----------------------\n");//Linea de formato	
}


Nodo* Baja(Nodo* Lista) {
	Nodo* Baja, * Aux;
	int Seleccion, * PS;

	PS = &Seleccion;
	Baja = Busca_Alumno(Lista);
	Aux = Lista;

	printf("\n-----------------------\n");//Linea de formato

	for (;;) {

		if (Baja == NULL) {
			printf("No se puedo realizar baja\n");
			printf("\n-----------------------\n");//Linea de formato
			return Lista;
		}
		else if (Baja == Lista) {
			printf("Seguro que quiere realizar la baja?\n1. Si\nCualquier numero para salir\nOpcion: ");
			scanf(" %i", PS);
			if (*PS == 1) {
				Lista = Lista->Psig;;
				free(Baja);
				printf("\n-----------------------\n");//Linea de formato
				printf("Se ha dado de baja\n");
				printf("\n-----------------------\n");//Linea de formato	
				return Lista;
			}
			else {
				printf("\n-----------------------\n");//Linea de formato	
				printf("No se realizara la baja\n");
				printf("\n-----------------------\n");//Linea de formato
				Lista = Aux;
				return Lista;
			}
		}
		else if (Lista->Psig == Baja) {
			printf("Seguro que quiere realizar la baja?\n1. Si\nCualquier numero para salir\nOpcion: ");
			scanf(" %i", PS);

			if (*PS == 1) {
				Lista->Psig = Baja->Psig;
				free(Baja);

				printf("Se ha dado de baja\n");
				printf("\n-----------------------\n");//Linea de formato	
				Lista = Aux;
				return Lista;
			}
			else {
				printf("No se realizara la baja\n");
				printf("\n-----------------------\n");//Linea de formato
				Lista = Aux;
				return Lista;
			}
		}
		Lista = Lista->Psig;
	}
}


Nodo* Borra_Lista(Nodo* Lista) {
	Nodo* Aux;
	int Seleccion;
	if (Lista == NULL) {
		printf("\n-----------------------\n");//Linea de formato
		printf("La lista esta vacia\n");
		return NULL;
	}
	for (;;) {
		printf("\n\nSeguro que quiere borrar la lista?\n1. Si\n2. No\nOpcion:  ");
		scanf(" %i", &Seleccion);

		if (Seleccion == 1) {
			while (Lista != NULL) {
				Aux = Lista->Psig;
				free(Lista);
				Lista = Aux;
			}
			printf("\n-----------------------\n");//Linea de formato
			printf("====Se borro la lista====\n");
			return Lista;
		}
		else if (Seleccion == 2) {
			printf("\n-----------------------\n");//Linea de formato
			printf("No se borrara nada\n");
			break;
		}
		else {
			printf("\n-----------------------\n");//Linea de formato
			printf("Opcion no valida\n");
		}
	}
}

void Menu(int* PS) {
	printf("\n-----------------------\n");//Linea de formato
	printf("\n1. Dar de alta\n2. Dar de baja\n3. Buscar alumno\n4. Imprimir lista\n5. Borrar lista\n6. Guardar\n7. Guardar Como\n8. Abrir\n0. Salir\nOpcion: ");
	scanf(" %i", PS);
}

void Salida(int* PS, Nodo* Lista) {
	Nodo* Aux;

	for (;;) {
		printf("Seguro que quiere salir?\n1. Si\n2. No\nOpcion: ");
		scanf(" %i", PS);

		if (*PS == 1) {

			while (Lista != NULL) {
				Aux = Lista->Psig;
				free(Lista);
				Lista = Aux;
			}

			printf("\n-----------------------\n");//Linea de formato
			printf("====Se borro la lista====\n");
			printf("\tAdios :'C\n");
			*PS = 0;
			break;
		}
		else if (*PS == 2) {
			printf("\n-----------------------\n");//Linea de formato
			printf("Usted no saldra\n");
			*PS = 100;
			break;
		}
		else {
			printf("\n-----------------------\n");//Linea de formato
			printf("La opcion seleccionada no es valida\n");
		}
	}
}

void Algoritmo_De_Escritura(Nodo* Lista, FILE* PF) {// Funcion que guarda los datos en el disco, la llamare dentro la funcion guardar
	while (Lista != NULL) {
		fprintf(PF, "\n%s %s %i", Lista->Nombre, Lista->Apellido, Lista->Matricula);
		Lista = Lista->Psig;
		if (Lista == NULL) {
			printf("\n-----------------------\n");//Linea de formato
			printf("Se ha guardado la lista\n");
		}
	}
}

void Guardar(Nodo* Lista) {
	FILE* PF;
	int Seleccion;


	if ((PF = fopen("Lista_Alumnos.txt", "r")) == NULL) {
		PF = fopen("Lista_Alumnos.txt", "w");
		printf("\n-----------------------\n");//Linea de formato
		printf("La lista se guardara en un documento de texto llamado Lista_Alumnos.txt");
		Algoritmo_De_Escritura(Lista, PF);
		fclose(PF);
	}

	else {
		printf("\n-----------------------\n");//Linea de formato
		printf("El archivo siempre se guardara en el documento Lista_Alumnos.txt\nSi usted continuar se sobrescribiran los datos de dicho documento.");

		for (;;) {
			printf("\nDesea continuar?\n1. Si\n2. No\nOpcion: ");
			scanf(" %i", &Seleccion);

			if (Seleccion == 1) {
				PF = fopen("Lista_Alumnos.txt", "w");
				Algoritmo_De_Escritura(Lista, PF);
				fclose(PF);
				break;
			}
			else if (Seleccion == 2) {
				printf("No se realizara ningun cambio en el documento\n");
				break;
			}
			else {
				printf("La Opcion no es valida\n");
			}
		}
	}
}

void Guardar_Como(Nodo* Lista) {
	FILE* PF;
	char Nombre_Archivo[30];
	int Seleccion;

	printf("\n-----------------------\n");//Linea de formato
	printf("Introduce un nombre para el documento: ");
	scanf(" %s", Nombre_Archivo);

	if ((PF = fopen(Nombre_Archivo, "r")) == NULL) {
		PF = fopen(Nombre_Archivo, "w");
		Algoritmo_De_Escritura(Lista, PF);
		fclose(PF);
	}
	else {
		for (;;) {
			printf("El archivo existe. Desea sobreescribirlo?\n1. Si\n2. No\nOpcion: ");
			scanf(" %i", &Seleccion);
			if (Seleccion == 1) {
				PF = fopen(Nombre_Archivo, "w");
				Algoritmo_De_Escritura(Lista, PF);
				fclose(PF);
				break;
			}
			else if (Seleccion == 2) {
				printf("\n-----------------------\n");//Linea de formato
				printf("No se guardara la lista\n");
				break;
			}
			else {
				printf("\n-----------------------\n");//Linea de formato
				printf("La opcion no es valida\n");
			}
		}
	}
}



Nodo* Abrir(Nodo* Lista) {
	FILE* PF;
	char Nombre_Archivo[30];

	printf("\n-----------------------\n");//Linea de formato
	printf("Nombre del archivo que desea abrir: ");
	scanf(" %s", Nombre_Archivo);

	if ((PF = fopen(Nombre_Archivo, "r")) == NULL) {
		printf("El Archivo no existe\n");
	}
	else {
		PF = fopen(Nombre_Archivo, "r");
		Lista = Crea_Nodo(Lista, PF);
		Imprime_Lista(Lista);
		fclose(PF);
	}
	return Lista;
}