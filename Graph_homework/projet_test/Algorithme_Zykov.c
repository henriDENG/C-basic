// Algorithme de Zykov
#define N 7

int complet_or_not(int M[][N], int sommet[]);
void methode_Zykov(int M[][N], int sommet[], int* num_chromatique);
void Zykov_minus(int M[][N], int sommet[], int* num_chromatique);
void Zykov_plus(int M[][N], int sommet[], int* num_chromatique);

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
