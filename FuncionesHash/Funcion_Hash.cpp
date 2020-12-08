#include<iostream>
#include<string>
using namespace std;

#define Max 10

struct nodo //Estructura Nodo 
{
  string dato;
  struct nodo *siguiente;
};

int clave(int tam,string nombre)//Funcion hash donde se determina la posicion del dato
{  
    int x=0;
    for(int i=0;i<nombre.size();i++)
        x+=nombre[i];
  return (x%tam)-1;
}

void Insertar(struct nodo **tabla,string dato)//Funcion que inserta los valores en la tabla hash
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

int buscar(string usuario, struct nodo *array[])
{
    int puntero=clave(Max,usuario),x=0;
    struct nodo *actual=array[puntero];
    while(actual!=NULL)
    {
        if(actual->dato==usuario)
        {
            x=1;
            break;
        }
    }
    return x;
}

string nombres[Max]; //Arreglo de Datos
struct nodo *array[Max];//Arreglo de nodos, que cumple la funcion de Tabla Hash

int main()
{
    for(int i=0;i<Max;i++)
    {
        cin>>nombres[i];
    }

    for(int i=0;i<Max;i++)
    {
     Insertar(&array[clave(Max,nombres[i])],nombres[i]); //Insertamos los datos a la tabla Hash
    }

    for(int i=0;i<Max;i++) //Imprimimos toda la Tabla Hash
    {
        cout<<"Nodo "<<i<<" :";
        mostrar(array[i]);
    }

    char boton;
    string usuario;
    do
    {
        cout<<"Deseas buscar algun usuario S/N";
        cin>>boton;
        if(boton=='S')
        {
            cout<<"Ingresa el nombre del usuario";
            cin>>usuario;
            if(buscar(usuario,array)==1) cout<<"Usuario encontrado en posicion :"<<clave(Max,usuario)<<endl;
            else cout<<"El usuario no existe"<<endl;
        }
    }while(boton=='S');

    return 0;
}