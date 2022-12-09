#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Booleanos

struct nodo{
	int dato;
	nodo *siguiente;
};
struct nodo *pcima=NULL; // nodo cima
int suma=0;
// Prototipos de funciones

void push(int valor);	//agregar valor a la pila
void pop(int valor);		// sacar valor, borrar
void imprimir(void);
int tamanio(void); // El tamaño de la pila
bool vacia(void);  // Indica si la pila está vacía
int ultimo(void);  // El último elemento. Devuelve 0 si no hay elementos


// BusquedaIndexada o tabla hash


int main(int argc, char *argv[]) {
//	int Datos[funcion][2]={{69,"Pepe"},{30,"Juan"},{24,"Peralta"},{14,"Ochoa"},{34,"Pena"}};	
	int Datos[75][5];	// unidad, prec, dia, mes, a, status
	int hash[75][6];// unidad, prec, dia, mes, a, status
	int funcion=75; // n datos
	int resultado=0, i=0, j=0, ele=0;
	// almace Datos
    int unidad, dia, mes, anio;
    int precio;
	// imprime Datos
	
				// almacena Datos desde data.txt

    FILE *f;
    f = fopen("data.txt", "r");
// unidades / precio / caducidad dia.mes.ano
    while( fscanf(f, "%i %i %i %i %i", &unidad,&precio, &dia, &mes,&anio) == 5)
    {
//        printf("unidad: %i precio: %.2f dia:%i / %i / %i \n", unidad, precio, dia, mes, anio);
        Datos[i][0]=unidad;
        Datos[i][1]=precio; // clave para el modulo
        Datos[i][2]=dia;
        Datos[i][3]=mes;
        Datos[i][4]=anio;
        i++;
    }
    fclose(f);        
        printf("Datos alamacenados\n");
    	for(i=0;i<75;i++){
		
		        printf("unidad: %d precio: %d Fecha de caducidad:%d / %d / %d \n", Datos[i][0], Datos[i][1], Datos[i][2], Datos[i][3], Datos[i][4]);
		
	}
        printf("Datos alamacenados exitosamente\n");

	// Generar tabla hash
	
	for(i=0;i<75;i++){
		for(j=0;j<6;j++){
				hash[i][j]=0;
		}
	}
	for(i=0;i<=74;i++){
		resultado=Datos[i][0]%funcion;
//		printf("%d",resultado);
		//printf("%d %d \n", hash[resultado][2], resultado);
		while((hash[resultado][2])!=0){
			
			fflush(stdin);
			resultado++;
			if(resultado>74){
				resultado=0;
			}
		}
	
		hash[resultado][0]=Datos[i][0];	//unidades
		hash[resultado][1]=Datos[i][1];	//precio
		hash[resultado][2]=1;	//status
		hash[resultado][3]=Datos[i][2];	//dia
		hash[resultado][4]=Datos[i][3];	//status
		hash[resultado][5]=Datos[i][4];	//status
		
		// hash[]=valor clave status
	}
/*		printf("tabla hash \n");
	
	for(i=0;i<75;i++){
		        printf("unidad: %d precio: %d status:%d dia:%d / %d / %d \n", hash[i][0], hash[i][1], hash[i][2], hash[i][3], hash[i][4],hash[i][5]);
				printf("\n ");
	}
*/	while(ele!=-1){

	printf("\t\t\t\t tienda departamental\n");
	printf("----Menu------\n");
	printf("1. Almacenar venta de un producto\n");
	printf("2. Consultar producto\n");
	printf("3. Borrar venta de un producto\n Elige una opcion \n");
	scanf("%d",&ele);
	switch(ele){
		case 1:{
			
	int VB=0, existe=0;
	printf("Ingresa el identificador del producto (numero del 0-74) \n ");
	scanf("%d",&VB);
	resultado=VB%funcion;
	while(hash[resultado][0]!=VB){
		resultado++;

		if(resultado>74){
			resultado=0;
			existe++;
			if(existe>2){
				printf("valor no registrado");
							break;
			}
		}
	}
	
	//printf("%d", hash[resultado][0]);// unidades
	//printf("sum%d", hash[resultado][1]);// precio
	
      printf("Ingresando producto con unidades: %d\n",hash[resultado][0]);
      suma=suma+hash[resultado][1]+(hash[resultado][1])*0.6;
      printf("Costo total : %d\n", suma);
      
    	push(hash[resultado][0]);
			break;
		}
		case 2:{
			// Consulta
			
	// Valor a buscar 
	// ingresando el identificador o indice registrado en la tabla hash
	/*
	int VB=220;
	resultado=VB%funcion;
	*/
	int VB=0, existe=0;
	
	printf("Ingresa el identificador del producto (numero del 0-74) \n ");
	scanf("%d",&VB);
	resultado=VB%funcion;
	while(hash[resultado][0]!=VB){
		resultado++;

		if(resultado>74){
			resultado=0;
			existe++;
			if(existe>2){
				printf("valor no registrado");
							break;
			}
		}
	}
		        printf("unidad: %d precio: %d Fecha de caducidad:%d / %d / %d \n", hash[resultado][0], hash[resultado][1], hash[resultado][2], hash[resultado][3], hash[resultado][4]);
			break;
		}
		case 3:{
			pop(hash[resultado][0]);
			      suma=suma-(hash[resultado][1]+(hash[resultado][1])*0.6);
      printf("Costo total : %d\n", suma);

			break;
		}
	}
}	
	return 0;
}

void push(int valor){ //  push(int valor, nodo *&pcima)
	nodo *nod= new (nodo);
	nod->dato=valor;
	nod->siguiente=pcima;
	pcima=nod;
}
void pop(int valorsal){
	//validamos si pcima==NULL
	if(!pcima){
		printf("\t Pila vacia \n");
		//return= "esta vacia"
	}else{
		nodo *aux= new (nodo);
		valorsal=aux->dato;
		printf("El valor %d es eliminado", pcima->dato);
		//pcima->siguiente=aux->siguiente;
		pcima=pcima->siguiente;
		delete aux;
	}
}
