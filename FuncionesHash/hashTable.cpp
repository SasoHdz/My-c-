#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXC 10
#define MAXA 10

struct nodo
{
        int *cadena;
        struct nodo *siguiente;
};

int hash (int clave)
{
        int posicion=clave%MAXA;
        
        return posicion;
}

void insertar(struct nodo **ptabla, int cadena)//Insertar nuevo elemento en una lista
{
        struct nodo *nuevo = (struct nodo*) malloc(sizeof(struct nodo));//Creamos el nuevo nodo
        nuevo->cadena = cadena; //Guardamos cadena
        nuevo->siguiente = NULL; //Como se va a insertar al final, sera el que apunte a NULL
        struct nodo *actual=*ptabla; //Creamos un puntero auxiliar a nodo
        
        if (*ptabla == NULL)
        {
                *ptabla=nuevo; //Si lista vacia, entonces: nuevo es el primer elemento
        }
        else
        {
                while(actual->siguiente != NULL)
                {
                        cout<<actual->cadena; //Imprime el dato del nodo correpondiente
                        actual = actual->siguiente; //Avanzamos al siguiente nodo
                }
                actual->siguiente = nuevo;
        }
}

void mostrar(struct nodo *ptabla)//IMPRIMIR LA TABLA
{
    struct nodo *actual=ptabla;//ACTUAL ES UN PUNTERO AUXILIAR PARA RECORRER LA LISTA
    
    while (actual!=NULL)//MIENTRAS NO SEA EL FINAL DE LA LISTA
    {
        cout<<actual->cadena;//IMPRIME EL DATO DEL NODO CORRESPONDIENTE
        actual = actual->siguiente;//AVANZAMOS AL SIGUIENTE NODO
    }
    cout<<"NULLnn";
}
 


int main()
{
    int datos[MAXC]={12,23,45,34,44,78,255,66,88,19};
    struct nodo *ptabla[MAXA];//ARREGLO DE PUNTEROS PARA NODOS
    int op, clavecadena, pos;//VARIABLES USADAS PARA MENU Y POSICION EN EL ARREGLO
    
    for(int i=0;i<MAXC;i++)
   {
        op=hash(datos[i]);
       cout<<"Hash: "<<op<<" dato:"<<datos[i]<<endl;
       insertar(**ptabla, datos[i]);
   }

        return 0;
}
