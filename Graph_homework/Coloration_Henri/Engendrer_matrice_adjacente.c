// Engendrer matrice adjacente du graphe
#include<time.h>
#define N 7

void engendrer_adjacence(int M[][N]);
void show(int M[][N]);

void engendrer_adjacence(int M[][N])
{
	int r,i,j;
	srand((unsigned)time(NULL)); // each time we generate a different random number set
	double p = 0.65;
	for (i = 0; i < N; i++){
		for (j = i; j < N; j++){
			r=rand() % 1000;
			if(r < p*1000 && i != j) {
				M[i][j] = 1;
				M[j][i] = 1;
			}
			else {
                M[i][j] = 0;
                M[j][i] = 0;
            }
		}
	}
}

void show(int M[][N])
{
    printf("M : \n");
    for (int i = 0; i < N; i++ ){
        for ( int j = 0; j <N; j++ ){
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}
