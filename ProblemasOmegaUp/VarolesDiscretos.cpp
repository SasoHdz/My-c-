#include<bits/stdc++.h>
using namespace std;

float Media=0,Varianza=0,Desviacion=0,x[2][20];
int n;

int main()
{
 
   cout<<"..................Ingresa la cantidad de datos ................"<<endl;
   cin>>n;
   cout<<"................Ingresa x con su f(x) respectivamente.........."<<endl;
   
   for(int i=0;i<n;i++)
   {
     cin>>x[0][i];
     cin>>x[1][i];
     Media+= x[0][i]*x[1][i];
   }
   for(int i=0;i<n;i++)
   {
     Varianza+=(x[0][i] - Media)*(x[0][i] - Media)*x[1][i];
   }
   Desviacion= sqrt(Varianza);
   
   cout<<"----------------------------------------------------------------------"<<endl;
   cout<<".........Media = "<<Media<< "......................."<<endl;
   cout<<".........Varianza = "<<Varianza<<"  ............. Desviacion estandar = "<<Desviacion<<endl;
   
 return 0;
}
