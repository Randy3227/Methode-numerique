#include <stdio.h>
#include <math.h>

float f(float x);
void displayResult(float a,float b,float aire,int n);
float trapezes(float a,float b,float eps);
float trapn(float a,float b,int n);

int main(){
	printf("Calcul de l'integrale de f dans [a;b]\n");
	/// Entree des donnees
	float a = 0, b = 1, 	// les bornes d'integration
		aire = 8.654;	  	// l'integrale a calculer
	int n = 1000;				//nombre de sous intervalle de discretisation
	
	/// Calcul
	aire = trapn(a,b,n);
	float aireeps = trapezes(a,b,1e-007);
	printf("oho%g",aire);
	printf("oho%g",aireeps);
	/// Sortie de resultat
	displayResult(a,b,aire,n);
	
	return 0;
}
float f(float x){
	return exp(sin(5*x));
}
void displayResult(float a,float b,float aire,int n){
	printf("L'integrale de f dans [%g;%g] est aire = %g\n",a,b,aire);
	printf("en utilisant n = %d sous intervalles\n" , n);
}
float trapezes(float a,float b,float eps){
	int n = 10;		//le nb de sous intervalles de discretion
	float AT1 = 0, AT2 = 0;
	AT1 = trapn(a,b,n);
	AT2 = trapn(a,b,n+20);
	while(fabs(AT1-AT2)>eps){
		AT1 = AT2;
		n += 20;
		AT2 = trapn(a,b,n);
	}
	printf("\nEn decoupant n = %d sous-intervalle\n",n);
	return AT2;
}
float trapn(float a,float b,int n){
	float AT = 0;
	float h = (b - a)/n;
	float x = a + h;
	for(int i = 1 ; i < n ; i++){
		AT += f(x);
		x+=h;
	}
	AT *= 2;
	AT += f(a);
	AT += f(b);
	AT = (AT*h)/2;
	return AT;
}
