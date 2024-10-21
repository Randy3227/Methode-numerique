#include <stdio.h>
#include <math.h>
/* Pour caluler l'integrale de e^sin5x sur l'intervalle [a,b]
On découpe la courbe n fois pour simplifier la calcul d'aire
 on obtient base = (b - a)/n ou base la base de chaque trapèze
 par la division de la courbe n fois
 La hauteur est hauteur = (f(xi) + f(x(i+1)))/2
 Donc la surface est Si = (base*((f(xi) + f(x(i+1)))/2))/2
 avec xi = a + i*hauteur
 xi = a + i*((b-a)/n)
 */
// Calculons integrale de e^sin5x dans un intervalle [a,b]
double integrale(double a,double b,int n){
// initialisation du résultat
    double surface = 0;
    double hauteur = 0;

// calcul des bases de chaque trapèze
   double base = (b-a)/n;

// calcul de la hauteur de chaque trapèze 
    for (int i = 0; i < n; i++){
        // hauteur = (f(xi) + f(x(i+1)))/2
        double x0 = a + i * (base);
        double x1 = a + (i + 1) * (base);
        hauteur = (exp(sin(5*x0)) + exp(sin(5*x1)))/2; 
        surface += base*hauteur;
    }

// Surface d'un trapèze 
    return surface;
}
int main(){
    /* appel de la fonction integrale pour avoir l'
     intégrale de e^sin(5x)*/
    double reponse = integrale(0,1,1000);
    printf("la valeur de l'integrale de e^sin5x sur l'intervalle [0,1] est %f\n",reponse);

}