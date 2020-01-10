//  Algorithme brutale
#define N 7
int methode_brutale(int M[][N], int K);

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
