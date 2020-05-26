#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

using namespace std;

template < typename T >
struct list
{
T id;
list* next;
};

template < typename T >
void push(list<T>** ptr, T x)
{
list<T>* tmp = new list<T>;
(*tmp).id = x;
tmp->next = *ptr;
*ptr = tmp;
}

template < typename T >
void print_list(list<T>* ptr)
{
while(ptr)
{
cout<<ptr->id<<" -> ";
ptr = ptr->next;
}
}
template < typename T >
T pop(list<T>** ptr)
{
list<T>* tmp = *ptr;
T x = tmp->id;
*ptr = (*ptr)->next;
delete(tmp);
return(x);
}

int status(char k)
{
int t;
if (k=='=') t=1;
if (k=='+') t=2;
if (k=='-') t=2;
if (k=='*') t=3;
if (k=='/') t=3;
if (k=='(') t=4;
if (k==')') t=4;
return t;
}

template < typename T >
void kpop(list<T>**t, int x)
{
list<T>*p=*t;
list<T>*r=(*t)->next;
if(p->id==x) pop(t);
else
{
while ((r->id!=x)&&(r->next))
{
p=r;
r=r->next;
}
if(p->next->id==x)
{
p->next=r->next;
}
delete(r);
}
}

void limon(list<double>**s, list<char>*t)
{
switch(t->next->id)
{
case '+':
{
(*s)->next->id=(*s)->next->id+(*s)->id;
pop(s);
break;
}
case '-':
{
(*s)->next->id=(*s)->next->id-(*s)->id;
pop(s);
break;
}
case '/':
{
(*s)->next->id=((*s)->next->id)/((*s)->id);
pop(s);
break;
}
case '*':
{
(*s)->next->id=((*s)->next->id)*((*s)->id);
pop(s);
break;
}
}
}

template < typename T >
void poptail(list<T>**t)
{
list<T>*p=*t;
while(p->next) p=p->next;
kpop(t, p->id);
}

template < typename T >
void aftertail(list<T>**t, double x)
{
list<T>*p=*t;
while(p->next) p=p->next;
list<T>*r=new list<T>;
r->next=NULL;
r->id=x;
p->next=r;
}

void ck(char vvod[], int i, char vivod[], int j, list<double>**lstX, int flag)
{
char b[255];
int z=i, k=0;
int m;
while(vvod[z]>'0'&&vvod[z]<'9'){
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
}
if (vvod[z]=='.') {
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
}
while(vvod[z]>'0'&&vvod[z]<'9'){
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
}
if (vvod[z]=='e') {
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; j++;
}
double r=atof(b);
if (flag==-1) r=r*(-1);
push(lstX, r);
i=z-1;
}

void insertOneSymb(char* str, char symb)
{
if(!str) return;
char * tmp = NULL;
int size = strlen(str);
tmp = new char[size+1];
memcpy(tmp, str, size+1);
str[0] = symb;
memcpy(str+1,tmp,size+1);
delete[]tmp;
return;
}

int main()
{
setlocale(LC_ALL, "Russian");
char vvod[70], vivod[70];
 ifstream fin("input.txt");
    fin.getline(vvod,100);
    fin.close();
    cout <<"primer:"<<vvod<<endl;
char y;
int i=0, j=0, s=0;
char dom[70];
double r;

list<double>* lstX = NULL;
list<char>* lstY = NULL;
print_list(lstX);
insertOneSymb(vvod, '(');
insertOneSymb(vvod, '(');
while(vvod[s]!='=') {
vvod[s]=vvod[s+1];
s++;
}
vvod[s-1]=')';
vvod[s]='=';
if(vvod[0]=='(') push(&lstY,'(');
while(i<strlen(vvod))
{
if((vvod[i]=='(')&& (vvod[i+1]=='-')&&(vvod[i+2]=='(')) {
push(&lstX, 0.0);
/*vivod[j]='0';
j++;
vivod[j]=' ';
j++;*/
}
if((vvod[i]=='(')&&(vvod[i+1]=='-')&&(vvod[i+2]!='('))
{
push(&lstY, '(');
i=i+2;
vivod[j]='-';
j++;
char b[255]="\0";
int z=i, k=0;
int m;
while(vvod[z]>='0'&&vvod[z]<='9'){
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
}
if (vvod[z]=='.') {
b[k]=',';
vivod[j]=vvod[z];
z++; k++; j++;
}
while(vvod[z]>='0'&&vvod[z]<='9'){
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
}
if (vvod[z]=='e') {
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; j++;
}
double r=atof(b);
r=r*(-1);
push(&lstX, r);
i=z-1;
vivod[j]=' ';
j++;
}
else
{
if (('0'<=vvod[i])&&(vvod[i]<='9'))
{
char b[255]="\0";
int z=i, k=0;
int m;

while(vvod[z]>='0'&&vvod[z]<='9'){
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
}
if (vvod[z]=='.') {
b[k]=',';
vivod[j]=vvod[z];
z++; k++; j++;
}
while(vvod[z]>='0'&&vvod[z]<='9'){
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
}
if (vvod[z]=='e') {
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; k++; j++;
b[k]=vvod[z];
vivod[j]=vvod[z];
z++; j++;
}
double r=atof(b);
push(&lstX, r);
i=z-1;
vivod[j]=' ';
j++;
}
else
{
push(&lstY, vvod[i]);
if((lstY->id)==')')
{
while (lstY->next->id!='(')
{
vivod[j]=lstY->next->id;
j++;
vivod[j]=' ';
j++;
limon(&lstX, lstY);
y=lstY->id;
pop(&lstY);
pop(&lstY);
push(&lstY, y);
}
kpop(&lstY, '(');
kpop(&lstY, ')');
}
while ((lstY->next)&&(status(lstY->next->id)>=status(lstY->id))&&(lstY->next->id!='('))
{
vivod[j]=lstY->next->id;
j++;
vivod[j]=' ';
j++;
limon(&lstX, lstY);
y=lstY->id;
pop(&lstY);
pop(&lstY);
push(&lstY, y);
}

}
if((lstY)&&(status(lstY->id)==1))
{
vivod[j]=lstY->id;
}
}
i++;
}
if(lstX->id+1>lstX->id)
{
for (i=0; i<j+1; i++)
cout<<vivod[i];
cout<<endl;
cout<<vvod<<lstX->id;
cout<<endl;
}
else cout<<"деление на 0 запрещено!"<<endl;
return 0;
}
