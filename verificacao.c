#include<stdio.h>
#include<stdlib.h>


int main(){
int c,a,p,q;
a=1;

for(p=0;p<2;p++)
{
for(q=0;q<2;q++)
    {
    a=(p==q)==(((!p)||q)&&((!q)||p));
    if (a==0) break;
    }
if (a==0) break;
}
if (a==0) { printf("Não é  uma tautologia");}
else printf("É uma tautologia");
return 0;
}
