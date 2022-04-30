#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <ctype.h>

typedef struct nodo_pila{ 
    int num;
    struct nodo_pila *siguiente; 
}nodoP; 

typedef nodoP *Pila;

typedef struct nodo_estudiante{
	int cedula;
	char nombre[20];
	float promedio;
	int edad;
	struct nodo_estudiante *siguiente; 
}nodoest;

typedef nodoest *Lista;

typedef struct listadoble{
	int valor;
	struct listadoble *siguiente;
	struct listadoble *anterior;
}nododoble;

typedef nododoble *listad;

/////MENUS///////
///////////////////////////////////
void menu4(){
printf("%s","BIENVENIDO AL MUNDO DE LAS PILAS\n");
printf("%s","1. PUSH\n");
printf("%s","2.  MOSTRAR PILA\n");
printf("%s","4. Salir al menu principal\n");

}

//////////////////////////////////////////////////////////////////////////////////////
void menu2(){
printf("%s","BIENVENIDO AL MUNDO DE LAS listas simples\n");
printf("%s","1. Insertar estudiantes\n");
printf("%s","2. Buscar estudiantes por cedula\n");
printf("%s","3.  MOSTRAR estudiantes\n");
printf("%s","4. Salir al menu principal ");
}
//////////////////////////////////////////////////////////////////////////////////////

void menu3(){
printf("%s","BIENVENIDO AL MUNDO DE LAS listas dobles\n");
printf("%s","1. Insertar numero\n");
printf("%s","2. imprimir numeros\n");
printf("%s","3. editar numero\n");
printf("%s","4. Eliminar numeros que inicien en 4\n");
printf("%s","5. Salir al menu principal: ");
}
///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
void menu1(){
printf("%s","BIENVENIDO AL MUNDO DINAMICO\n");
printf("%s","1. Menu lista simple\n");
printf("%s","2. Menu lista doble\n");
printf("%s","3. Menu pilas\n");
printf("%s","4. SALIR\n");

}
//funciones lista simple///
//funcion para comprobar si la cedula ya esta en la lista
int comprobarEst(Lista milista,int cedula){
	while(milista!=NULL){
		if(milista->cedula==cedula){
			return 1;
		}
		milista=milista->siguiente;
	}
	return 0;
}
//funcion para buscar cedula en la lista
//////////////////////////////////////////////////////////////////////////////////////
void buscarEnL(Lista milista,int cedula){
	if(milista==NULL){
		printf("lista vacia");
	}else{
		while(milista!=NULL){
			if(milista->cedula==cedula){
				printf("%s","Cedula: ");
				printf("%d",milista->cedula);
				printf ("\n");
				printf("%s","Nombres: ");
				printf("%s",milista->nombre);
				printf ("\n");
				printf("%s","promedio: ");
				printf("%f",milista->promedio);
				printf ("\n");
				printf("%s","Edad: ");
				printf("%d",milista->edad);
				printf ("\n");
				printf("***********************");
				printf ("\n");
				break;
			}
		milista=milista->siguiente;
		}
		if(milista==NULL){
			printf("no se encontro el estudiante...");
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////
//funcion para mostrar estudiantes de la lista
void mostrarEst(Lista milista){
	if(milista==NULL){
		printf("lista vacia");
	}else{
		while(milista!=NULL){
				printf("%s","Cedula: ");
				printf("%d",milista->cedula);
				printf ("\n");
				printf("%s","Nombres: ");
				printf("%s",milista->nombre);
				printf ("\n");
				printf("%s","promedio: ");
				printf("%f",milista->promedio);
				printf ("\n");
				printf("%s","Edad: ");
				printf("%d",milista->edad);
				printf ("\n");
				printf("***********************");
				printf ("\n");	
		milista=milista->siguiente;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////
//funcion para insertar estudiantes a la lista simple
void insertarE(Lista *milista, int cedula, char *nombre,float promedio,int edad){
		Lista nuevo_nodo;
		nuevo_nodo=(Lista)malloc(sizeof(nodoest));
		nuevo_nodo->cedula=cedula;
		nuevo_nodo->promedio=promedio;
		nuevo_nodo->edad=edad;
		strcpy(nuevo_nodo->nombre,nombre);
		nuevo_nodo->siguiente=*milista;
		*milista=nuevo_nodo;
}
//////////////////////////////////////////////////////////////////////////////////////
//funciones lista doble////
//funcion para saber si ya hay un numero igual en la lista
int comprobarnum(listad milistad,int valor){
	while(milistad!=NULL){
		if(milistad->valor==valor){
			return 1;
		}
		milistad=milistad->siguiente;
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////
//funcion para saber si un numero termina en 7
int terminaen7(int valor){
	if(valor%10==7){
		return 1;
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
//funcion para saber si un numero es primo
int primo(int valor){
	int esprimo=0;
	int cont=0;
	for(int i=1;i<=valor;i++){
		if(valor%i==0){
			cont++;
		}
	}
		if(cont==2){
			esprimo=1;
			return esprimo;
		}else{
			esprimo=0;
			return esprimo;
		}
}
//////////////////////////////////////////////////////////////////////////////////////
//funcion para mostrar la lista doble
void mostrarld(listad milistad){
	if(milistad==NULL){
		printf("lista vacia");
	}else{
		while(milistad!=NULL){
				printf("%d",milistad->valor);
				printf ("\n");
				printf("***********************");
				printf ("\n");	
		milistad=milistad->siguiente;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//funcion para editar nodo de la lista doble
int cambiarnum(listad milistad, int cambiado){
	int numcambiado=0;
		while(milistad!=NULL){
			if(comprobarnum(milistad,cambiado)==0 && terminaen7(cambiado)==0 && cambiado>=0 && primo(cambiado)==0){
				milistad->valor=cambiado;
				numcambiado=1;
				return numcambiado;
			}
		milistad=milistad->siguiente;
		}
	return numcambiado;
}
/////////////////////////////////////////////////////////////////////////////////////
//funcion para saber si un numero empieza en 4
int empieza4(listad milistad){

	while(milistad!=NULL){
		int valor1=milistad->valor;
		int valor=valor1;
		while(valor/10!=0){
			valor=valor/10;
		}
		if(valor%10==4){
			return valor1;				  
		}
	milistad=milistad->siguiente;
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//funcion para eliminar numeros de la lista que inicien en 4
void eliminar4(listad *milistad){
	listad aux_borrar;
	listad anterior=NULL;
	listad primero=*milistad;
	listad actual=primero;
	listad ultimo;
	int encontrado=0;

	if(primero!=NULL){
		while(actual!=NULL &&encontrado!=1){
			if(actual->valor == empieza4(*milistad)){
				if(actual==primero){
					primero=primero->siguiente;
					primero->anterior=NULL;
				}else if(actual==ultimo){
					anterior->siguiente=NULL;
					ultimo=anterior;
				}else{
					anterior->siguiente=actual->siguiente;
					actual->siguiente->anterior=anterior;
				}
				printf("nodo eliminado:");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->siguiente;
		}
		if(encontrado==0){
			printf("no hay numeros que inicien en 4");
		}else{
			free(anterior);
		}
	}else{
		printf("lista vacia");
	}
}    
//////////////////////////////////////////////////////////////////////////////////////
//funcion para crear nodos de lista doble
void insertarLD(listad *milistad, int valor){
	if(comprobarnum(*milistad,valor)==0 && terminaen7(valor)==0 && valor>=0 && primo(valor)==0){
		listad nuevo_nodo;
		nuevo_nodo=(listad)malloc(sizeof(nododoble));
		nuevo_nodo->siguiente=*milistad;
		nuevo_nodo->anterior=NULL;

		if((*milistad)!=NULL)
			(*milistad)->anterior=nuevo_nodo;
			(*milistad)=nuevo_nodo;
			nuevo_nodo->valor=valor;
	}else{
		printf("no se puede ingresar el numero");
	}

}

///////////////////funciones pilas////////////////
//////////////////////////////stackempty: verifica si la pila est� vacia//////////////
int stackempty(Pila Pilainicial){
int vacia=0; // vacia es 0 la pila est� vacia, si es 1 la pila tiene elementos
if (Pilainicial==NULL){
	return vacia;
	 }
else
{
 vacia=1;
 return vacia;
 }
}
////////////////////////////////////////////////////
//funcion para determinar si un numero tiene 3 digitos
int contardigitos(int valor){
	int contar=0;
	while(valor!=0){
		valor=valor/10;
		contar++;
	}
	if(contar==3){
		return 1;
	}
 return 0;
}
////////////////////////////////////////////////////
//funcion para determinar si la suma de los digitos de un numero inicia en 4
int suma4(int valor){
	int sumadigitos=0;
	int auxnum;
	while(valor!=0){
		auxnum=valor%10;
		valor=valor/10;
		sumadigitos=sumadigitos+auxnum;
	}
	while(sumadigitos/10!=0){
		sumadigitos=sumadigitos/10;
	}
	if(sumadigitos%10==4){
			return 1;
	}
	return 0;
}
//funcion para saber si ya hay un numero igual en la pila
int comprobarpil(Pila Pilainicial,int valor){
	while(Pilainicial!=NULL){
		if(Pilainicial->num==valor){
			return 1;
		}
		Pilainicial=Pilainicial->siguiente;
	}
	return 0;
}

////////////////////Funci�n push///////////////////
void Push(Pila *Pilainicial, int valor){
	if(comprobarpil(*Pilainicial,valor)==0 && contardigitos(valor)==0 && suma4(valor)==0 && valor>=0){
		Pila nuevo_nodo;
		nuevo_nodo = (Pila)malloc(sizeof(nodoP)); 
		nuevo_nodo->num = valor; 
		nuevo_nodo->siguiente = *Pilainicial; 
		*Pilainicial = nuevo_nodo; 
	}else{
		printf("no se puede ingresar el numero");
	}
}
/////////////////////stacktop(S): determina cual es el elemento disponible de la pila///
int stacktop(Pila Pilainicial){
    return Pilainicial->num;
}
//////////////////////////////////////////mostrar pila/////////////////////////////////
//funcion para mostrar la lista doble
void mostrarpila(Pila Pilainicial){
	if(Pilainicial==NULL){
		printf("Pila vacia");
	}else{
		while(Pilainicial!=NULL){
				printf("%d",Pilainicial->num);
				printf ("\n");
				printf("***********************");
				printf ("\n");	
		Pilainicial=Pilainicial->siguiente;
		}
	}
}

//main
///////////////////////////////////////////////////////////////////////////////
int main(){
	Pila mipila;
	mipila=NULL;
	int opc=0,opc2=0,opc3=0,opc4=0,edad,valor_cedula,cedbus,num,numcambiar,numcambiado,pilita;
	char aux_nombres[20];
	float promedio;
	Lista milista;
	milista=NULL;
	listad milistad;
	milistad=NULL;


	while(opc!=4){
		system("cls");
		menu1();
		printf("escoja una opcion: ");
		printf("\n");
		scanf("%d",&opc);
		switch(opc){
			//verifica los datos de entrada a la lista simple
			case 1: system("cls");
					menu2();
					printf("\nescoja una opcion: ");
					printf ("\n");
					scanf("%d",&opc2);
					while(opc2!=4){	
						system("cls");
						switch(opc2){
						case 1: system("cls");
								printf("Ingrese estudiantes a la lista, presione -1 para terminar: \n");
    							printf("Ingrese la cedula: ");
								scanf("%d",&valor_cedula);
								printf ("\n");
								while(valor_cedula!=-1){
									if(comprobarEst(milista,valor_cedula)==0){
										printf("ingrese nombre: ");
										printf ("\n");
										scanf("%s",&aux_nombres);
										printf("ingrese promedio: ");
										printf ("\n");
										scanf("%f",&promedio);
										printf("ingrese edad");
										scanf("%d",&edad);
										if(edad>18){
											insertarE(&milista,valor_cedula,aux_nombres,promedio,edad);
										}else{
											printf("no se permite ingresar menores de edad");
										}
										printf("\n");
									}else{
										printf("el estudiante ya existe");
									}
										printf("%s \n","\n*********************************");
										printf("Ingrese mas datos,  recuerde que con -1 termina: \n");
       					 				printf("Ingrese la cedula: ");
										scanf("%d",&valor_cedula);
								}
						break;

						case 2:	system("cls");
								printf("ingrese cedula a buscar: ");
								printf("\n");
								scanf("%d",&cedbus);
								system("cls");
								buscarEnL(milista,cedbus);
						break;
						
						case 3: system("cls");
								mostrarEst(milista);
						break;
						}	
						printf("\n");
		  				printf("ingrese el numero 4 para volver al menu de lista simple: ");
  						scanf("%d",&opc2); 
						  if(opc2==4){
							system("cls");
							menu2();
							printf("\nescoja una opcion: ");
							printf ("\n");
							scanf("%d",&opc2);
						  }
					}	

			break;
			case 2: system("cls");
					menu3();
					printf("\nescoja una opcion: ");
					printf ("\n");
					scanf("%d",&opc3);
					while(opc3!=5){
						system("cls");
						menu3();
						switch(opc3){
							case 1: system("cls");
									printf("Ingrese numeros a la lista, presione -1 para terminar: \n");
									printf("Ingrese un numero: ");
									scanf("%d",&num);
									printf ("\n");
									while(num!=-1){
										insertarLD(&milistad,num);
										printf ("\n");
										printf("Ingrese mas datos,  recuerde que con -1 termina: \n");
										printf("Ingrese un numero ");
										scanf("%d",&num);
									} 
							break;
							case 2: system("cls");
									mostrarld(milistad);
							break;
							case 3: system("cls");
									printf("ingrese el numero a cambiar: ");
									scanf("%d",&numcambiar);
									if(comprobarnum(milistad, numcambiar)==1){
										printf("por cual numero desea cambiarlo ");
										scanf("%d",&numcambiado	);
									}else{
										printf("el numero que quiere cambiar no existe");
									}
									if(cambiarnum(milistad,numcambiado)==1){
										printf("el numero ha sido cambiado");
									}else{
										printf("el numero no se puede cambiar");
									}
									
									
									
							break;
							case 4: system("cls");
									eliminar4(&milistad);

							break;
						}
						printf("\n");
		  				printf("ingrese el numero 5 para volver al menu de lista doble: ");
  						scanf("%d",&opc3); 
						  if(opc3==5){
							system("cls");
							menu3();
							printf("\nescoja una opcion: ");
							printf ("\n");
							scanf("%d",&opc3);
						  }
					}
			break;
			case 3: system("cls");
					menu4();
					printf("escoja una opcion: ");
					scanf("%d",&opc4);
					while(opc4!=4){
						switch(opc4){
							case 1: system("cls");
									printf("Ingrese numeros a la pila, presione -1 para terminar: \n");
									printf("Ingrese un numero: ");
									scanf("%d",&pilita);
									printf ("\n");
									while(pilita!=-1){
										Push(&mipila,pilita);
										printf ("\n");
										printf("Ingrese mas datos,  recuerde que con -1 termina: \n");
										printf("Ingrese un numero ");
										scanf("%d",&pilita);
									} 
							break;
							case 2: system("cls");
									mostrarpila(mipila);
							break;
						}
						printf("\n");
		  				printf("ingrese el numero 4 para volver al menu de pilas ");
  						scanf("%d",&opc4); 
						  if(opc4==4){
							system("cls");
							menu4();
							printf("\nescoja una opcion: ");
							printf ("\n");
							scanf("%d",&opc4);
						  }
					}
					
			break;
			case 4: system("cls");
					return 0;
			break;

		}	
			printf("\n");
		  	printf("ingrese el numero 5 para volver al menu principal: ");
  			scanf("%d",&opc); 
	}


return 0;
}

