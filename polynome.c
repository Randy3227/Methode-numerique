#include <stdio.h>
#include <math.h>
// Soit à calculer un polynome p(x) pour une valeur de x
double polynome(int x,double* coefficient,int taille){
    // initialisation du résultat 
    double result = coefficient[0]*x;
    /* boucle qui permet d'acceder les éléments du tableau coefficient
     pour effectuer le calcul*/
    for (int i = 1; i < taille - 1; i++){
        /* on ajoute au résultat chaque coefficient[i] mais
        on ne prends pas la dernière indice car elle n'a pas
        de calcul avec la variable x et le
        tout multiplier par x*/
        result = (result + coefficient[i])*x;
    }
    // le resultat doit etre additionner avec la dernière indice
    return result + coefficient[taille-1];
    
}
int main(){
    // exemple de coefficient pour un polynome de degré 5
    double coefficient[] = {3, 2, 0, -3.5, 0.12, 4};
    int taille = sizeof(coefficient) / sizeof(coefficient[0]);
    // appel de la fonction polynome()
    double resultat = polynome(2,coefficient,taille);
    printf("pour le polynome P(x) = 3x^2 + 2x^4 - 3.5x^2 + 0.12x + 4,la valeur de P(x) pour x = 2 est : %f\n",resultat);
}
