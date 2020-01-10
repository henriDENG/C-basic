Quelques explications pour mes codes:

1. Les quatres m¨¦thodes sont dans quatre fichiers et il y a un fichier pour engendrer une matrice adjacente au hasard. 
   (On doit attendre quelques secondes...) Vous pouvez tester dimensions diff¨¦rentes en changeant la valeur de N 
    dans les fichier "main.c" et "engendrer_matrice_adjacente.c". Pour voir le r¨¦sultat, il suffit de "run" le fichier 'main.c'.

2. La premi¨¨re partie est la m¨¦thode brutale. Le programme va continuer de tester jusqu'¨¤ avoir la bonne valeur de K.  
    Vous pouvez tester la valeur de K de peitite ¨¤ grande pour obtenir la minimum valeur de K et une coloration correspondante.

3. La m¨¦thode de Zykov va trouver la minimum valeur de K pour colorer le graphe.  Cette m¨¦thode est beaucoup plus
    rapide que la m¨¦thode brutale. Une remarque est que les varariables dans la fonction "main" est tous pour 
    la m¨¦thode de Zykov. Par contre, les m¨¦thodes approch¨¦es sont toutes ind¨¦pendantes.

4. Pour les deux m¨¦thodes approch¨¦es, je d¨¦brouille ¨¦xatement comme ce que dit l'algorithme qu'on a ¨¦tudi¨¦. 
    Une remarque est que quand les degr¨¦s de deux points sont ¨¦gaux, je choisis le point d'un num¨¦ro plus grand. 
    Donc l'ordre de la coloration pourrait ¨ºtre diff¨¦rent de celui dans le polycopi¨¦. J'ai aussi donn¨¦ les colorations 
    correspondantes de Leighton et de Br¨¦laz.

5. Dans le fichier "main.c", j'ai donn¨¦ un contre exemple pour les deux m¨¦thodes approch¨¦es qui est de dimension 14.
    Vous pouvez le tester dans le ficher "coloration_total.c" qui comprend tous mes codes. Ce sera plus rapid.

6. Si vous rencontrez des erreurs quand vous "build" les fichers, vous pouvez "run" le fichier "coloration_total.c" qui 
    comprend tous mes codes. En fait, les autres fichiers sont juste une s¨¦paration des m¨¦thodes.