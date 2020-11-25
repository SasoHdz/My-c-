#include<iostream>
using namespace std;

char cad[100];
int n,a=0,b=0;
int main()
{
   cin>>n;
   cin>>cad;
   for(int i=0;i<n/2;i++)
   {
	   switch(cad[i])
	   {
	     case 'R':
		     if(cad[i+1]=='P')
		     {
			     b++;
			     cout<<"Beto gana"<<endl;
		     }
		     else
		     {
			     a++;
			     cout<<"Ana gana"<<endl;
		     }

		     break;
             case 'P':
		     if(cad[i+1]=='T')
                     {
                             b++;
                             cout<<"Beto gana"<<endl;
                     }
                     else
                     {
                             a++;
                             cout<<"Ana gana"<<endl;
                     }

		     break;
             case 'T':
		     if(cad[i+1]=='R')
                     {
                             b++;
                             cout<<"Beto gana"<<endl;
                     }
                     else
                     {
                             a++;
                             cout<<"Ana gana"<<endl;
                     }

                     break;		     
	   }
   }
   if(b>a) cout<<"Beto gana el torneo"<<endl;
   else cout<<"Ana gana el torneo"<<endl;



	return 0;
}
