// Algorithme de Brelaz
#define N 7
void methode_Brelaz(int M[][N]);

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
        if ( degre_sommet[i] >= degre_sommet[target] ) // on prend le sommet du numero plus grand
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
