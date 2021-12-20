#include <iostream>     /* cout */
#include <math.h>       /* pow, sqrt */
#include <stdio.h>      /* NULL */
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
int N, tmax, nl;

srand48 (time(NULL));

cout<<"Inserte el numero  de particulas"<<endl;
cin>> N;


tmax= 10*N;
double Pr=0,P1=0, P2=0, Varianza, Pc=0, fluctuaciones, probabilidad;
int  z=1, x=0;
nl=N;
for(int i =1; i<= tmax;i++){
    probabilidad = (double)nl/(double)N;
    double aleatorio = drand48();
    if(aleatorio<= probabilidad)
    {
        nl--;
        }
    else
    {
        nl++;
        }
    if(nl== N/2){
        x=1;
        }
    if(x==1){

    P2= P2 + pow((double)nl, 2.0);
    Pc= P2/(double)z;
    P1=P1 + nl;
    Pr= P1/(double)z;
    Varianza= Pc - pow(Pr,2.0);
    fluctuaciones= sqrt(Varianza)/Pr;
    cout<< "Pr :" << Pr<< "Pc :" << Pc << "nl :" <<nl<< "Varianza :"<<Varianza<<endl;
    cout<<"Valor de fluctuaciones relativas :"<<fluctuaciones<<endl;
    z++;
        }    
    }
}