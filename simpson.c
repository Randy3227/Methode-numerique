#include "stdio.h"
#include "math.h"

float f(float x);
void displayResult(float a,float b,float aire,float aireEps,int n,int eps);
float aireN(float a,float b,int n);
float aireEps(float a,float b,int n);

int main(){
    printf("Calcul de l'integrale de f dans [a;b]\n");
	/// Entree des donnees
	float a = 0, b = 1, 	// les bornes d'integration
		airen = 8.654,aireeps = 8.654;	  	// l'integrale a calculer
	int n = 30;                         //nombre de sous intervalle de discretisation
    int eps = 30;				    //nombre d'epsylon
    airen = aireN(a,b,n);
    aireeps = aireEps(a,b,eps);
    displayResult(a,b,airen,aireeps,n,eps);
    return 0;
}

float f(float x){
    return exp(sin(5*x));
}

void displayResult(float a,float b,float aire,float aireEps,int n,int eps){
	printf("L'integrale de f dans [%g;%g] par n = %i sous intervalle est aire = %g\n",a,b,n,aire);
	printf("L'integrale de f dans [%g;%g] par eps = %i est aire = %g\n",a,b,eps,aireEps);
}

float aireN(float a,float b,int n){
    float AT = 0 , somme_xi = 0 , somme_xi2 = 0;    //initialisation des resultats
    float h = (b - a)/n;        //definition de la hauteur
    float xi = a + h ;            // determination de xi
    float xi2 = (a + h)/2;      //determination de x i+0.5
    //somme de f(xi) pour i = 1 jusqu'à n-1
    for(int i = 1; i < n; i++){
        somme_xi += f(xi);
        xi += h;
    }
    //somme de f(x i+0.5) pour i = 0 à n-1
    for (float i = 0; i < n; i++){
        somme_xi2 += f(xi2);
        xi2 += h; 
    }
    
    AT = (h/6)*(f(a) + 2*somme_xi + f(b) + 4*somme_xi2);
    return AT;
}

float aireEps(float a,float b,int eps){
    int n = 10;		//le nb de sous intervalles de discretion
	float AT1 = 0, AT2 = 0;
	AT1 = aireN(a,b,n);
	AT2 = aireN(a,b,n+20);
	while(fabs(AT1-AT2)>eps){
		AT1 = AT2;
		n += 20;
		AT2 = aireN(a,b,n);
	}
	return AT2;
    return AT1;
}