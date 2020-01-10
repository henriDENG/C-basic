// Algorithme de Leighton

void methode_Leighton(int M[][N]);

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
