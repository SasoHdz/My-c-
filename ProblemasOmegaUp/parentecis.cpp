#include<bits/stdc++.h>
using namespace std;

char cad[300];
int n,op,x=0;
int main()
{
 cin>>cad;
 n=strlen(cad);
 stack<int> o,c;
 for(int i=0;i<n;i++)
 {
   if(cad[i]=='(') o.push(i);
   else c.push(i);
 }
 op=o.size();
 while(!c.empty()&& !o.empty())
 {
    if(c.top()>o.top())
    {
      x++;
      c.pop(); o.pop();
    }
    else o.pop();
    
 }
 if(x*2==n && n%2==0) cout<<op<<endl<<"Balanceada";
 else cout<<op<<endl<<"No balanceada";
 
 return 0;
}

