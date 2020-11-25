#include<iostream>
using namespace std;

#define Max 10

struct nodo 
{
  int dato;
  struct nodo *siguiente;
};

int clave(int tam,int dato)
{  
  return dato%tam;
}

void Insertar(struct nodo **tabla,int dato)
{
   struct nodo *nuevo = (struct nodo *) malloc(sizeof(nodo));
   nuevo->dato = dato;
   nuevo->siguiente = NULL;
   struct nodo *aux = *tabla;

   if(*tabla == NULL)
    *tabla=nuevo;
   else
   {
     while(aux->siguiente != NULL)
     {
       cout<<aux->dato;
       aux = aux->siguiente;
     }
     aux->siguiente= nuevo;
   }
}

void mostrar(struct nodo *tabla)//IMPRIMIR LA TABLA
{
    struct nodo *actual=tabla;//ACTUAL ES UN PUNTERO AUXILIAR PARA RECORRER LA LISTA
    
    while (actual!=NULL)//MIENTRAS NO SEA EL FINAL DE LA LISTA
    {
        cout<<actual->dato<<" ";//IMPRIME EL DATO DEL NODO CORRESPONDIENTE
        actual = actual->siguiente;//AVANZAMOS AL SIGUIENTE NODO
    }
    cout<<" NULLnn ";
}


int datos[Max]={12,23,45,34,44,78,255,66,88,19};
struct nodo *array[Max];

int main()
{
  
  for(int i=0;i<Max;i++)
  {
    Insertar(&array[clave(Max,datos[i])],datos[i]);
  }
  for(int i=0;i<Max;i++)
  {
    cout<<"Nodo "<<i<<" :";
    mostrar(array[i]);
  }

    return 0;
}