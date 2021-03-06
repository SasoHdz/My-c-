#include<iostream>
using namespace std;

#define Max 10

struct nodo //Estructura Nodo 
{
  int dato;
  struct nodo *siguiente;
};

int clave(int tam,int dato)//Funcion hash donde se determina la posicion del dato
{  
  return (dato%tam)-1;
}

void Insertar(struct nodo **tabla,int dato)//Funcion que inserta los valores en la tabla hash
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
        cout<<actual->dato<<" --->> ";//IMPRIME EL DATO DEL NODO CORRESPONDIENTE
        actual = actual->siguiente;//AVANZAMOS AL SIGUIENTE NODO
    }
    cout<<" NULL "<<endl;
}

int buscar(int dato, struct nodo *array[])
{
    int puntero=clave(Max,dato),x=0;
    struct nodo *actual=array[puntero];
    while(actual!=NULL)
    {
        if(actual->dato==dato)
        {
            x=1;
            break;
        }
        actual = actual->siguiente;
    }
    
    return x;
}

int datos[Max]={12,23,45,34,44,78,255,66,88,19}; //Arreglo de Datos
struct nodo *array[Max];//Arreglo de nodos, que cumple la funcion de Tabla Hash

int main()
{
  
  for(int i=0;i<Max;i++)
  {
    Insertar(&array[clave(Max,datos[i])],datos[i]); //Insertamos los datos a la tabla Hash
  }

  for(int i=0;i<Max;i++) //Imprimimos toda la Tabla Hash
  {
    cout<<"Nodo "<<i<<" :";
    mostrar(array[i]);
  }

  char boton;
  int numero;
    do
    {
        cout<<"Deseas buscar algun numero S/N"<<endl;
        cin>>boton;
        if(boton=='S')
        {
            cout<<"Ingresa el numero a buscar"<<endl;
            cin>>numero;
            if(buscar(numero,array)==1) 
              cout<<"Dato encontrado en: "<<clave(Max,numero)<<endl;
            else 
              cout<<"El dato no existe"<<endl;
        }
    }while(boton=='S');

    return 0;
}