#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include"Engendrer_matrice_adjacente.c"
#include"Algorithme_Brutale.c"
#include"Algorithme_Zykov.c"
#include"Algorithme_Leighton.c"
#include"Algorithme_Brelaz.c"

#define N 7

// fonctions utilisees
void engendrer_adjacence(int M[][N]);
void show(int M[][N]);
int methode_brutale(int M[][N], int K);
int complet_or_not(int M[][N], int sommet[]);
void methode_Zykov(int M[][N], int sommet[], int* num_chromatique);
void Zykov_minus(int M[][N], int sommet[], int* num_chromatique);
void Zykov_plus(int M[][N], int sommet[], int* num_chromatique);
void methode_Leighton(int M[][N]);
void methode_Brelaz(int M[][N]);

int main()
{
    while(1){
        int K;
        int M[N][N] = {0};
        int sommet[N] = {0}; // 0 = exist, 1 = pas exist
        int num_chromatique = 1000; // number chromatic
        int flag = -1;
        /*
        int A[14][14]={{0,0,0,0,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                       {0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                       {0,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,0,0,1},
                       {0,0,0,0,0,0,0,1,1,0,1,1,0,0},
                       {0,0,0,0,0,1,1,0,1,1,0,1,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,0,1,0},
                       {0,0,0,1,1,0,0,0,0,0,0,1,0,1},
                       {1,1,1,0,0,0,0,0,1,0,0,0,1,0}}; // un contre exemple pour les deux méthodes approchées
        */
        // int B[5][5] = {{0,1,1,0,1},{1,0,0,0,0},{1,0,0,1,0},{0,0,1,0,1},{1,0,0,1,0}}; // un contre exemple pour la methode_Leighton
        engendrer_adjacence(M);
        show(M);
        while( flag != 1 ){
            printf("valeur de K: ");
            scanf("%d", &K);
            flag = methode_brutale(M, K);
        }
        methode_Zykov(M, sommet, &num_chromatique);
        printf("Nombre chromatique du graphe est %d selon methode de Zykov.\n", num_chromatique);
        methode_Brelaz(M);
        methode_Leighton(M);
        printf("\n");
    }
    return 0;
}
