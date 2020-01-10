#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define N 14
// int M[N][N] = {{0,0,1,1},{0,0,0,1},{1,0,0,1},{1,1,1,0}};

void engendrer_adjacence(int M[][N]);
void show(int M[][N]);
int methode_brutale(int M[][N], int K);
int complet_or_not(int M[][N], int sommet[]);
void methode_Zykov(int M[][N], int sommet[], int* num_chromatique);
void Zykov_minus(int M[][N], int sommet[], int* num_chromatique);
void Zykov_plus(int M[][N], int sommet[], int* num_chromatique);
void methode_Brelaz(int M[][N]);
void methode_Leighton(int M[][N]);

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

int methode_brutale(int M[][N], int K)
{
    int total_case[N] = {0}; // all the coloration possibilities
    int flag = 0; // sign of stop
    int times = 0; // times of iteration
    int judge = 0; // 0 = yes, 1 = no
    int sign = 0;
    while ( flag == 0 ){
        flag = 1;
        judge = 0;
        for ( int i = 0; i < N; i++ ){
            if ( total_case[i] >= K ){
                total_case[i] = total_case[i]-K;
                total_case[i+1]++;
            }
        }
        /*
        for (int i = 0; i < N; i++){
            printf("%d ", total_case[i]);
        }
        printf("\n");
        */
        times++;
        for( int i = 1; i < N; i ++ ){
            for ( int j = 0; j < i; j++ ){
                if ( total_case[i] == total_case[j] && M[i][j] == 1 ){
                    judge = 1;
                    break;
                }
            }
            if ( judge == 1)
                break;
        }
        if ( judge == 0 )
            break;

        for ( int i = 0; i < N; i++ ){
            if ( total_case[i] != K-1 )
                flag = 0;
        }
        total_case[0]++;
    }
    //printf("it: %d\n", times);
    if ( judge == 0 ){
        printf("BRAVO! On peut utiliser %d couleurs pour dessiner le graphe selon methode brutale. \n", K);
        printf("Une coloration possible est suivante: ");
        for ( int i = 0; i < N; i++){
            printf("%d ", total_case[i]+1);
        }
        printf(".\n");
        sign = 1;
        //return 1;
    }
    if ( judge == 1 ){
        printf("DOMMAGE! Aucune solution est trouvee selon methode brutale.\n");
        sign = 0;
        //return 0;
    }
    return sign;
}

int complet_or_not(int M[][N], int sommet[])
{
    int judge = 0; // 0 = yes, 1 = no
    for ( int i = 0; i < N; i++ ){
        for ( int j = i; j < N; j++ ){
            if ( M[i][j] == 0 && sommet[i] == 0 && sommet[j] == 0 && i != j ){
                judge = 1;
                break;
            }
        }
        if ( judge == 1 )
            break;
    }
    /*
    if ( judge == 0 )
        printf("Le graphe est complet.\n");
    if ( judge == 1 )
        printf("Le graphe n'est pas complet.\n");
    */
    return judge;
}

void methode_Zykov(int M[][N], int sommet[], int* num_chromatique) // idee comme a binary tree
{
    int length = 0;
    int flag1 = -1; // 0=stop. 1=continue
    int flag2 = -1;
    int temp1[N][N] = {0};
    int temp2[N][N] = {0};
    int temp1_sommet[N] = {0};
    int temp2_sommet[N] = {0};
    for ( int i = 0; i < N; i++ ){
        for ( int j = 0; j < N; j++ ){
            temp1[i][j] = M[i][j];
            temp2[i][j] = M[i][j];
        }
        temp1_sommet[i] = sommet[i];
        temp2_sommet[i] = sommet[i];
    }

    flag1 = complet_or_not(temp1, temp1_sommet);
    if ( flag1 == 0 ){
        for ( int i = 0; i < N; i++ ){
            if ( temp1_sommet[i] == 0)
                length++;
        }
        if ( length < *num_chromatique ){
            *num_chromatique = length;
        }
    }
    else
        Zykov_minus(temp1, temp1_sommet, num_chromatique);

    length = 0;
    flag2 = complet_or_not(temp2, temp2_sommet);
    if ( flag2 == 0 ){
        for ( int i = 0; i < N; i++ ){
            if ( temp2_sommet[i] == 0)
                length++;
        }
        if ( length < *num_chromatique ){
            *num_chromatique = length;
        }
    }
    else
        Zykov_plus(temp2, temp2_sommet, num_chromatique);
}

void Zykov_minus(int M[][N], int sommet[], int* num_chromatique)
{
    int flag = 0; // sign of stop
    for ( int i = 0; i < N; i++ ){
        for ( int j = i; j < N; j++ ){
            if ( M[i][j] == 0 && sommet[i] == 0 && sommet[j] == 0 && i != j ){
                for ( int k = 0; k < N; k++ ){
                    if ( M[j][k] == 1 && sommet[k] == 0 && k != i)
                        M[i][k] =1;
                } // add branches to new point
                for ( int k = 0; k < N; k++ ){
                    M[j][k] = 0;
                } // eliminate branches of the point grand
                sommet[j] = 1;
                flag = 1;
                break;
            }
        }
        if ( flag == 1 )
            break;
    }
    methode_Zykov(M, sommet, num_chromatique);
}

void Zykov_plus(int M[][N], int sommet[], int* num_chromatique)
{
    int flag = 0; // sign of stop
    for ( int i = 0; i < N; i++ ){
       for ( int j = i; j < N; j++ ){
            if ( M[i][j] == 0 && sommet[i] == 0 && sommet[j] == 0 && i != j ){
                M[i][j] = 1;
                M[j][i] = 1;
                flag = 1;
                break;
            }
       }
       if ( flag == 1)
            break;
    }
    methode_Zykov(M, sommet, num_chromatique);
}

void methode_Brelaz(int M[][N])
{
    int sommet[N] = {0}; // 1 = traite, 0 = non traite
    int color_sommet[N] = {0}; // phi(s)
    int total_color = 0; // total number of colors
    int flag_color[N+1] = {0}; // 0 = unused, 1 = used
    int voisin_sommet[N] = {0}; // beta(s)
    int diff_voisin[N][N+1] = {0}; // 0 = unused, 1 = used
    int degre_sommet[N] = {0};  // d(s)
    int target = 0; // choix du sommet
    int num_target = 0; // nombre du sommets traites
    int temp = 0;
    int judge = 0; // 0 = not find color available, 1 = find a color available
    int first_place = 0; // index of the premier etape target
    // premier etape
    for ( int i = 0; i < N; i++ ){
        for ( int j = 0; j < N; j++ ){
            if ( M[i][j] == 1 && i != j )
                degre_sommet[i]++;
        }
    }
    for ( int i = 1; i < N; i++ ){
        if ( degre_sommet[i] >= degre_sommet[target] )
            target = i;
    }
    total_color++;
    color_sommet[target] = total_color;
    for ( int i = 0; i < N; i++){
        if ( M[target][i] ==  1 && i != target ){
            voisin_sommet[i]++;
            diff_voisin[i][total_color] = 1;
        }
    }
    sommet[target] = 1;
    num_target++;
    first_place = target;

    //etape supplementaire pour les sommets isoles
    for ( int i = 0; i < N; i++ ){
        if ( degre_sommet[i] == 0 ){
            color_sommet[i] = 1;
            num_target++;
            sommet[i] = 1;
        }
    }

    //second etape
    while( num_target < N ){
        for ( int i = 0 ; i < N+1 ; i++){
            flag_color[i] = 0;
        }
        target = first_place; // chaque fois beta(target) initial = 0 important!!!
        temp = 0;
        judge = 0;
        for ( int i = 0 ; i < N; i++ ){
            if ( voisin_sommet[i] > voisin_sommet[target] && sommet[i] == 0 )
                target = i;
            if ( voisin_sommet[i] == voisin_sommet[target] && degre_sommet[i] >= degre_sommet[target] && sommet[i] == 0 ) // ">=" est important ici
                target = i;
        }
        for ( int i = 0; i < N; i++ ){
            if ( M[target][i] == 1 && color_sommet[i] != 0 ){
                temp = color_sommet[i];
                flag_color[temp] = 1;
            }
        }
        for ( int i = 1; i <= total_color; i++ ){
            if ( flag_color[i] == 0 ){
                color_sommet[target] = i;
                judge = 1;
                break;
            }
        }
        if ( judge == 0 ){
            total_color++;
            color_sommet[target] = total_color;
        }
        for ( int i = 0; i < N; i++ ){
            temp = color_sommet[target];
            if ( M[target][i] == 1 && sommet[i] == 0 && diff_voisin[i][temp] == 0 ){
                voisin_sommet[i]++;
                diff_voisin[i][temp] = 1;
            }
        }
        sommet[target] = 1;
        num_target++;
    }
    printf("Une estimation du nombre chromatique est %d selon methode de Brelaz.\n", total_color);
    printf("La coloration correspondante est suivante: ");
    for ( int i = 0; i < N; i++ ){
        printf("%d ", color_sommet[i]);
    }
    printf(".\n");
}

void methode_Leighton(int M[][N])
{
    int sommet[N] = {0};
    int degre_sommet[N] = {0};
    int color_sommet[N] = {0};
    int colorflag_sommet[N] = {0};
    int total_color = 0;
    int total_sommet = N;
    int target = 0;
    int flag = 0; // sign of done for Zykov_minus, 0 = no, 1 = yes
    int sign = 1; // sign of stop for algorithm , 1 = continue, 0 = stop
    int first_place = 0;  // begin position of comparison
    int num_chromatique = 0;
    int temp = -1;

    while( sign == 1 ){
        //initialisation
        for ( int i = 0; i < N; i++ ){
            degre_sommet[i] = 0;
        }
        target = 0;
        flag = 0;
        sign = 1;
        first_place = 0;

        for ( int i = 0; i < N; i++ ){
            for ( int j = 0; j < N; j++ ){
                if ( M[i][j] == 1 )
                    degre_sommet[i]++;
            }
        } //renew degree
        for ( int i = 0; i < N; i++ ){
            if ( degre_sommet[i] <= degre_sommet[first_place] && sommet[i] == 0){
                first_place = i;
            }
        } // find the begin position of comparison important!!!
        target = first_place;
        for ( int i = 0; i < N; i++ ){
            if ( degre_sommet[i] >= degre_sommet[target] && degre_sommet[i] < total_sommet-1 && sommet[i] == 0 ) // ">=" est important ici
                target = i;
        } // determine the target

        for ( int j = 0; j < N; j++ ){
            if ( M[target][j] == 0 && sommet[j] == 0 && target != j ){
                for ( int k = 0; k < N; k++ ){
                    if ( M[j][k] == 1 && sommet[k] == 0 && k != target){
                         M[target][k] = 1;
                         M[k][target] = 1;
                    }
                }
                for ( int k = 0; k < N; k++ ){
                    M[j][k] = 0;
                    M[k][j] = 0;
                }
                sommet[j] = 1;
                colorflag_sommet[j] = target;
                flag = 1;
                break;
            }
        }
        if ( flag == 1)
            total_sommet--; // once minus, number of total sommets minus aussi
        sign = complet_or_not(M, sommet);
    }
    for ( int i = 0; i < N; i++ ){
        if ( sommet[i] == 0 )
            num_chromatique++;
    }
    // printf("Nombre du sommets restants: %d .\n", total_sommet);
    printf("Le nombre chromatique prevu par le methode de Leighton est %d.\n", num_chromatique);

    // find the coloration correspondant
    for ( int i = 0; i < N; i++ ){
        temp = colorflag_sommet[i];
        while( sommet[temp] == 1 ){
            temp = colorflag_sommet[temp];
        }
        colorflag_sommet[i] = temp;
    }
    for ( int j = 0; j < N; j++ ){
        if ( sommet[j] == 0 ){
            total_color++;
            color_sommet[j] = total_color;
        }
    }
    for ( int i = 0; i < N; i++ ){
        if ( sommet[i] == 1){
            temp = colorflag_sommet[i];
            color_sommet[i] = color_sommet[temp];
        }
    }
    printf("La coloration correspondante est suivante: ");
    for ( int k = 0; k < N; k++ ){
        printf("%d ", color_sommet[k]);
    }
    printf(".\n");
}

int main()
{
    while(1){
        int K;
        int M[N][N] = {0};
        int sommet[N] = {0}; // 0 = exist, 1 = pas exist
        int num_chromatique = 1000; // nombre chromatique
        int flag = -1;
        int A[14][14]={{0,0,0,0,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                       {0,0,0,0,0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                       {0,0,0,0,0,0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,0,0,1},
                       {0,0,0,0,0,0,0,1,1,0,1,1,0,0},
                       {0,0,0,0,0,1,1,0,1,1,0,1,0,0},
                       {0,0,0,0,0,0,0,0,0,1,1,0,1,0},
                       {0,0,0,1,1,0,0,0,0,0,0,1,0,1},
                       {1,1,1,0,0,0,0,0,1,0,0,0,1,0}}; // un contre exemple pour les deux m¨¦thodes approch¨¦es
        // int B[5][5] = {{0,1,1,0,1},{1,0,0,0,0},{1,0,0,1,0},{0,0,1,0,1},{1,0,0,1,0}}; // un contre exemple pour la methode_Leighton
        /*
        engendrer_adjacence(M);
        show(M);
        while( flag != 1 ){
            printf("valeur de K: ");
            scanf("%d", &K);
            flag = methode_brutale(M, K);
        }
        */
        methode_Zykov(A, sommet, &num_chromatique);
        printf("Nombre chromatique du graphe est %d selon methode de Zykov.\n", num_chromatique);
        methode_Brelaz(A);
        methode_Leighton(A);
        printf("\n");
    }
    return 0;
}
