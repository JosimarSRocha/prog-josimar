#include<stdio.h>
#include<stdlib.h>

int main(){
int i,j,k,v1,v2,v3,v4,n,r,a,b,cont;
printf("Digite a quantidade de elementos do conjunto A:");
scanf("%d",&n);

printf("\nA={");
for(i=0;i<n;i++)
{ if (i<n-1) printf("%d,",i);
else 
printf("%d}\n",i);
}


int tabela[n][n];
for(i=0;i<n;i++)
for(j=0;j<n;j++)
tabela[i][j]=0;

r=-1;
do{
printf("Digite a quantidade de elementos da relação R: ");
scanf("%d",&r);
if (r<0||r>n*n) printf("Digite um valor entre 0 e %d",n*n);
}while (r<0||r>n*n);

cont=0;
do{
printf("Digite a e b em A  para formar o  par ordenado (a, b):");
scanf("%d%d",&a,&b);
if (a<0||a>=n||b<0||b>=n) printf("Par ordenado invalido!\n");
else 
if (tabela[a][b]==1)  printf("Par ordenado já inserido!\n");
else {cont++; tabela[a][b]=1;}

}while (a<0||a>=n||b<0||b>=0&&cont<r);

printf("A quantidade de pares ordenados inseridos é %d\n",cont);

printf("\nR = {");

cont=0;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if (tabela[i][j]==1) {cont++;
printf("(%d,%d)",i,j);
if (cont<r) printf(",");
 else printf("}\n");
}
v1=1;
for(i=0;i<n;i++)
if (tabela[i][i]==0) {v1=0; break;}

if (v1==1) printf("A relação R é reflexiva!\n");
else printf("A relação R não é reflexiva!\n");

v2=1;

for(i=0;i<n;i++)
for(j=0;j<n;j++)
if (tabela[i][j]!=tabela[j][i]) {v2=0; break;}
if (v2==1) printf("A relação R é simétrica!\n");
else printf("A relação R não é simétrica!\n");

v3=1;

for(i=1;i<n;i++)
for(j=0;j<i;j++)
if (tabela[i][j]*tabela[j][i]==1){v3=0; break;}

if (v3==1) printf("A relação R é antissimétrica!\n");
else printf("A relação R não é antissimétrica!\n");

v4=1;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
for(k=0;k<n;k++)
if (tabela[i][j]&&tabela[j][k]&&(!tabela[i][k])) {v4=0; break;}
if (v4==1) printf("A relação R  é transitiva!\n");
else printf("A relação R não é transitiva!\n");


if(v1*v3*v4==1) printf("A relação R é uma relação de ordem!\n");
else printf("A relação R não é uma relação de ordem!\n");

if(v1*v2*v4==1) { 
printf("A relação R é uma relação de equivalência!\n");
int classes[n];

for(i=0;i<n;i++);
classes[i]=i;
printf("\nClasses de equivalência:");
for(i=0;i<n;i++)
if (classes[i]!=-1) { 
printf("\nClasse do %d: ",i);
for(j=0;j<n;j++)
if (tabela[i][j]!=0) {
printf("%d ",j); 
classes[j]=-1;}
}
}
else printf("A relação R não é uma relação de equivalência!\n");

printf("\n");

return 0;
}



