#include <iostream>     /* cout */
#include <math.h>       /* pow, sqrt */
#include <stdio.h>      /* NULL */
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int main() {
int N,nl,nr,derecha[10],izquierda[10],micro[2000];
int inter, comparaciones, coincidencias;
double taza, entropia, error, teorico;
srand48 (time(NULL));
cout<< "Digite el numero de particulas"<<'\n';
cin>> N;
cout<< "Cuantas estaran en la izquierda"<<'\n';
cin>> nl;
cout<< "Determine el numero de intercambios"<<'\n';
cin>> inter;
cout<< "Cual es el valor teorico a comparar "<< '\n';
cin>> teorico;

nr = N-nl;
micro[0] = 0;

comparaciones= inter*(inter-1)/2;
for(int e = 1; e <= nl; e++){
    izquierda[e]=e;
    micro[0]=micro[0]+ pow(2.0,(double)e);
}

for(int e=1; e<=nr; e++){
    derecha[e]=e+nl;
}
for(int i=1; i<= inter; i++){
    double ni = drand48()*(double)nl;
    double nd = drand48()*(double)nr;
    int indi = (int)ni + 1;
    int indd = (int)nd + 1;

    int pariz = izquierda[indi];
    int parde = derecha[indd];

    izquierda[indi]= parde;
    derecha[indd]=pariz;

    micro[i]= micro [i-1] + pow(2.0,(double)parde);
    micro[i]= micro [i] - pow(2.0,(double)pariz);
}

coincidencias = 0;
for(int x = 1; x < inter; x++){
    for(int y = x+1; y <= inter; y++){
    if (micro[x]== micro[y]){ 
        coincidencias++;
        }
    }
}
cout << "coincidencias:" << coincidencias <<'\n';
cout << "comparaciones:" << comparaciones <<'\n';
taza = (double)coincidencias/(double)comparaciones;
if (taza > 0 && taza != 1){
    entropia = log(1/taza);
    error =(teorico-entropia)*100/teorico;
    cout << "EL valor de proporcion es:  "<< taza <<'\n';
    cout << "El valor de entropia es:  "<< entropia <<'\n';
    cout<< "El error asociado es :"<< error<<endl;
    }
}