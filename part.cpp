#include <iostream>     /* cout */
#include <math.h>       /* pow, sqrt */
#include <stdio.h>      /* NULL */
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
int N, tmax, nl, intentos;
double probabilidad, Pro;
srand48 (time(NULL));

cout<<"Inserte el numero  de particulas"<<endl;
    cin>> N;
cout<<"Numero de intentos"<<endl;
    cin>> intentos;


tmax= 10*N;
int Particulas[tmax][intentos], Suma[tmax],parti[tmax];
for(int v =1; v <= intentos; v++){
    nl=N;
    for(int i =1; i<= tmax;i++){
    probabilidad = (double)nl/(double)N;
    double aleatorio = drand48();
    if(aleatorio<= probabilidad){
        nl--;
        }
    else {
        nl++;
        }
    parti[i-1]= nl;
    Particulas[i-1][v-1]= nl;
    }
}




for (int i=0;i<tmax; i++){
Suma[i]= Particulas[i][0]+Particulas[i][1] + Particulas[i][2]+Particulas[i][3] + Particulas[i][4];

Pro = (double)Suma[i]/intentos;

cout << Pro<<"   "<<Particulas[i][0] <<"  "<<Particulas[i][1] << "  "<<Particulas[i][2]<< "  "<<Particulas[i][3]<<"  "<<Particulas[i][4]<<endl;
 }
}