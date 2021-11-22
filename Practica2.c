// Cervera Cordero, Javier (hace entrega de la practica en Canvas)
// Coney González, Andrew Iñaki
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// Resto de include necesarios

#define MAX_ORDENES 150
#define MAX_CAD 100

#define ANCHO_ALM 31
#define ALTO_ALM 20

#define NOMBRE_FICHERO "robot.txt"

struct orden {
	char info[MAX_CAD];
	int x; // representa la altura en el mapa
	int y; // representa la anchura en el mapa
};

struct robot {
	int mapa[ALTO_ALM][ANCHO_ALM];
	int posX; // posicion dentro del mapa del robot en el alto del mapa
	int posY; // posicion dentro del mapa del robot en el ancho del mapa
	struct orden ordenes[MAX_ORDENES];
};

// Funciones auxiliares para el funcionamiento del programa
int menu();
void incializarOrdenes(struct orden ordenes[], int max_ordenes);
void crearMapa(int filas, int cols, int mapa[][cols]);
struct orden leerOrden();
void ordenATexto(struct orden ord);
// funcion para limpiar el buffer
void flush();

// Funciones a implementar
int insertarOrden(int alto, int ancho, int mapa[][ancho], struct orden ordenes[], int capacidad, struct orden nueva);
void listarOrdenes(struct orden ordenes[], int max_ordenes);
struct orden buscarOrden(struct orden ordenes[], int capacidad, int x, int y);
int borrarOrdenes(struct orden ordenes[], int capacidad, char info[]);
void mostrarMapa(int filas, int cols, int mapa[][cols], struct orden ordenes[], int capacidad);
// Parte OPCIONAL y EXTRA
void crearPlanEjecucion(int alto, int ancho, int mapa[][ancho], struct orden ordenes[], int capacidad);

int main()
{
	srand(time(NULL));
	int opcion;
	struct robot robot;
	char info[MAX_CAD];

	crearMapa(ALTO_ALM, ANCHO_ALM, robot.mapa);
	robot.posX = 1;
	robot.posY = 1;
	robot.mapa[robot.posX][robot.posY] = 2;

	incializarOrdenes(robot.ordenes, MAX_ORDENES);

	// Insertar aqui el codigo para la lectura del fichero robot.txt

	do {
		opcion = menu();
		switch (opcion)
		{
		case 1: {
			struct orden nuevo = leerOrden();
			if (insertarOrden(ALTO_ALM, ANCHO_ALM, robot.mapa, robot.ordenes, MAX_ORDENES, nuevo))
				printf("\nOrden insertada con exito\n");
			else
				printf("\nError, orden no valida\n");
			break;
		}
		case 2: {
			printf("Opcion 2\n");
			int x, y;
			printf("\nIntroduce la posicion x donde buscar: ");
			scanf("%d", &x);
			printf("\nIntroduce la posicion y donde buscar: ");
			scanf("%d", &y);

			struct orden buscada = buscarOrden(robot.ordenes, MAX_ORDENES, x, y);
			if (strcmp(buscada.info, "?") != 0) {
				printf("\n");
				ordenATexto(buscada);
				printf("\n");
			}
			else
				printf("\nNo hay ninguna orden en la posición [%d, %d]\n", x, y);

			break;
		}
		case 3:
			listarOrdenes(robot.ordenes, MAX_ORDENES);
			break;
		case 4: {
			printf("Opcion 4\n");

			printf("\nIntroduce la info a borrar: ");
			gets(info);
			int numOrdenesBorradas = borrarOrdenes(robot.ordenes, MAX_ORDENES, info);
			if (numOrdenesBorradas > 0)
				printf("\n%d orden(es) borrada(s) con exito\n", numOrdenesBorradas);
			else
				printf("\nError, no existen ordenes con esa info\n");
			break;
		}
		case 5: {
			mostrarMapa(ALTO_ALM, ANCHO_ALM, robot.mapa, robot.ordenes, MAX_ORDENES);
			break;
		}
		case 6: {
			crearPlanEjecucion(ALTO_ALM, ANCHO_ALM, robot.mapa, robot.ordenes, MAX_ORDENES);
			break;
		}
		case 7: {
			// Incluir aqui la escritura de ordenes al fichero robot.txt

			printf("\nHasta la vista\n");
			break;
		}
		default: printf("\nOpcion no valida\n");
		}
	} while (opcion != 7);
	return 0;
}

// Funciones auxiliares ya implementadas. NO SE PUEDEN MODIFICAR

void ordenATexto(struct orden ord) {
	printf("%-25s%4d%4d", ord.info, ord.x, ord.y);
}

int menu()
{
	int opcion;
	printf("\n1. Insertar orden");
	printf("\n2. Buscar orden");
	printf("\n3. Listar ordenes");
	printf("\n4. Borrar orden");
	printf("\n5. Mostrar mapa");
	printf("\n6. Simular robot");
	printf("\n7. Salir");
	printf("\nIntroduce opcion: ");
	scanf("%d", &opcion);
	flush();
	return opcion;
}

void flush() {
	while (getchar() != '\n');
}

struct orden leerOrden() {
	struct orden ordenNueva;
	printf("\nIntroduce descripción de orden: ");
	gets(ordenNueva.info);
	printf("\nIntroduce coordenada del alto en el area de juego: ");
	scanf("%d", &ordenNueva.x);
	printf("\nIntroduce coordenada del ancho en el area de juego: ");
	scanf("%d", &ordenNueva.y);
	flush();

	return ordenNueva;
}

void crearMapa(int filas, int cols, int mapa[][cols]) {
	int r;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == 0 || i == filas - 1 || j == 0 || j == cols - 1)
				mapa[i][j] = -1;
			else {
				r = rand() % 21;
				if (r < 2)
					mapa[i][j] = -1;
				else
					mapa[i][j] = 0;
			}
		}
	}
}

void incializarOrdenes(struct orden ordenes[], int max_ordenes) {
	for (int i = 0; i < max_ordenes; i++) {
		strcpy(ordenes[i].info, "?");
		ordenes[i].x = -1;
		ordenes[i].y = -1;
	}
}

// Funciones a implementar
int insertarOrden(int alto, int ancho, int mapa[][ancho], struct orden ordenes[], int capacidad, struct orden nueva) {
	printf("Parte no implementada\n");
	return -2;
}

void listarOrdenes(struct orden ordenes[], int max_ordenes) {
	printf("Parte no implementada\n");
}

struct orden buscarOrden(struct orden ordenes[], int capacidad, int x, int y) {
	struct orden r = {"?", -2, -2};
	printf("Parte no implementada\n");
	return r;
}

int borrarOrdenes(struct orden ordenes[], int capacidad, char info[])
{
	printf("Parte no implementada\n");
	return -2;
}

void mostrarMapa(int filas, int cols, int mapa[][cols], struct orden ordenes[], int capacidad) {
	printf("Parte no implementada\n");
}

void crearPlanEjecucion(int alto, int ancho, int mapa[][ancho], struct orden ordenes[], int capacidad) {
	printf("Parte no implementada\n");
}
