#include<bits/stdc++.h>
using namespace std;

char cad[300];
int n,op,cl;
int main()
{
 cin>>cad;
 n=strlen(cad);
 queue<char> o,c;
 for(int i=0;i<n;i++)
 {
   if(cad[i]=='(') o.push(cad[i]);
   else c.push(cad[i]);
 }
 op=o.size();
 cl=c.size();
 if(op>cl) cout<<cl<<endl<<"No balanceada";
 else
 {
   if(cl>op) cout<<op<<endl<<"No balanceada";
   else cout<<cl<<endl<<"Balanceada";
 }
 
 return 0;
}

