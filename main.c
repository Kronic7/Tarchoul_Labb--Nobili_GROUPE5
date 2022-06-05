#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

int i,j,l;    //i pour les lignes et j pour les colonnes
char *JEU;
char *MINES;

float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}


// cette fonction va regarder le nombre de mine présent dans autour d'une case choisis dans une dimension de 3x3
// Nous l'avons créer de manière à "checker" chaque coin d'une case en les parcourant selon si nous sommes sur un coin de la grille

int minesAutour(int i, int j, int l, int taille)
{
    int N=0;

    if (i==0)
    {
        if (j==0)
        {
            if(MINES[i * l + (j+1)]=='M')
            {
                N++;
            }
            if(MINES[(i+1) * l + j]=='M')
            {
                N++;
            }
            if(MINES[(i+1) * l + (j+1)]=='M')
            {
                N++;
            }
        }
        else
        {
            if(j==taille-1)
            {
                if(MINES[i * l + (j-1)]=='M')
                {
                    N++;
                }
                if(MINES[(i+1) * l + (j-1)]=='M')
                {
                    N++;
                }
                if(MINES[(i+1) * l + j]='M')
                {
                    N++;
                }
            }
            else
            {
                if(MINES[i * l + (j-1)]=='M')
                {
                    N++;
                }
                if(MINES[i * l + (j+1)]=='M')
                {
                    N++;
                }
                if(MINES[(i+1) * l + (j-1)]=='M')
                {
                    N++;
                }
                if(MINES[(i+1) * l + j]=='M')
                {
                    N++;
                }
                if(MINES[(i+1) * l + (j+1)]=='M')
                {
                    N++;
                }
            }
        }
    }
    else
    {
        if (i==taille-1)
        {
            if (j==0)
            {
                if(MINES[(i-1) * l + j]=='M')
                {
                    N++;
                }
                if(MINES[(i-1) * l + (j+1)]=='M')
                {
                    N++;
                }
                if(MINES[i * l + (j+1)]=='M')
                {
                    N++;
                }
            }
            else
            {
                if(j==taille-1)
                {
                    if(MINES[(i-1) * l + (j-1)]=='M')
                    {
                        N++;
                    }
                    if(MINES[(i-1) * l + j]=='M')
                    {
                        N++;
                    }
                    if(MINES[i * l + (j-1)]=='M')
                    {
                        N++;
                    }
                }
                else
                {
                    if(MINES[(i-1) * l + (j-1)]=='M')
                    {
                        N++;
                    }
                    if(MINES[(i-1) * l + j]=='M')
                    {
                        N++;
                    }
                    if(MINES[(i-1) * l + (j+1)]=='M')
                    {
                        N++;
                    }
                    if(MINES[i * l + (j-1)]=='M')
                    {
                        N++;
                    }
                    if(MINES[i * l + (j+1)]=='M')
                    {
                        N++;
                    }
                }
            }
        }
        else
        {
            if(MINES[(i-1) * l +(j-1)]=='M')
            {
                N++;
            }
            if(MINES[(i-1) * l + j]=='M')
            {
                N++;
            }
            if(MINES[(i-1) * l + (j+1)]=='M')
            {
                N++;
            }
            if(MINES[i * l + (j-1)]=='M')
            {
                N++;
            }
            if(MINES[i * l + (j+1)]=='M')
            {
                N++;
            }
            if(MINES[(i+1) * l + (j-1)]=='M')
            {
                N++;
            }
            if(MINES[(i+1) * l + j]=='M')
            {
                N++;
            }
            if(MINES[(i+1) * l + (j+1)]=='M')
            {
                N++;
            }
        }

    }
    return(N);

}

//Cette fonction compte uniquement le nombre de mine restante dans une grille de jeu

int compteurMINE(char *JEU, int i1, int j1,int l){

    int cpt = 0;

    for(int i1=0;i1<l;i1++)
    {
        for(int j1=0;j1<l;j1++)
        {
            if(JEU[i1*l+j1] == 'M')
            {
                cpt ++;
            }
        }
    }

    return cpt;
}


//Cette fonction permet de relever le nombre de bombe de chaque case autour d'une case choisie jusqu'à que la "frontière" soit délimitée uniquement par des "1"


void decouverteCase(int i, int j, int l, int taille){

    if (i==0)
    {
        if (j==0)
        {
            if(minesAutour(i,j+1,l,taille) != 0){
                JEU[i * l + (j+1)] = minesAutour(i,j+1,l,taille) + '0';
            }
            else{
                JEU[i * l + (j+1)] = '~';
            }

            if(minesAutour(i+1,j,l,taille) != 0){
                JEU[(i+1) * l + j] = minesAutour(i+1,j,l,taille) + '0';
            }
            else{
                JEU[(i+1) * l + j] = '~';
            }

            if(minesAutour(i+1,j+1,l,taille) != 0){
                JEU[(i+1) * l + (j+1)] = minesAutour(i+1,j+1,l,taille) + '0';
            }
            else{
                JEU[(i+1) * l + (j+1)] = '~';
            }
        }
        else
        {
            if(j==taille-1)
            {
                if(minesAutour(i,j-1,l,taille) != 0){
                    JEU[i * l + (j-1)] = minesAutour(i,j-1,l,taille) + '0';
                }
                else{
                    JEU[i * l + (j-1)] = '~';
                }

                if(minesAutour(i+1,j-1,l,taille) != 0){
                    JEU[(i+1) * l + (j-1)] = minesAutour(i+1,j-1,l,taille) + '0';
                }
                else{
                    JEU[(i+1) * l + (j-1)] = '~';

                }

                if(minesAutour(i+1,j,l,taille) != 0){
                    JEU[(i+1) * l + j] = minesAutour(i+1,j,l,taille) + '0';
                }
                else{
                    JEU[(i+1) * l + j] = '~';

                }
            }
            else
            {
                if(minesAutour(i,j-1,l,taille) != 0){
                    JEU[i * l + (j-1)] = minesAutour(i,j-1,l,taille) + '0';
                }
                else{
                    JEU[i * l + (j-1)] = '~';
                    //decouverteCase(i,j-1,l,taille);
                }

                if(minesAutour(i,j+1,l,taille) != 0){
                    JEU[(i) * l + (j+1)] = minesAutour(i,j+1,l,taille) + '0';
                }
                else{
                    JEU[(i) * l + (j+1)] = '~';
                    //decouverteCase(i,j+1,l,taille);
                }

                if(minesAutour(i+1,j,l,taille) != 0){
                    JEU[(i+1) * l + j] = minesAutour(i+1,j,l,taille) + '0';
                }
                else{
                    JEU[(i+1) * l + j] = '~';
                    //decouverteCase(i+1,j,l,taille);
                }
                if(minesAutour(i+1,j+1,l,taille) != 0){
                    JEU[(i+1) * l + (j+1)] = minesAutour(i+1,j+1,l,taille) + '0';
                }
                else{
                    JEU[(i+1) * l + (j+1)] = '~';
                    //decouverteCase(i+1,j+1,l,taille);
                }
                if(minesAutour(i+1,j-1,l,taille) != 0){
                    JEU[(i+1) * l + (j-1)] = minesAutour(i+1,j-1,l,taille) + '0';
                }
                else{
                    JEU[(i+1) * l + (j-1)] = '~';
                    //decouverteCase(i+1,j-1,l,taille);
                }
            }
        }
    }
    else
    {
        if (i==taille-1)
        {
            if (j==0)
            {
                if(minesAutour(i-1,j,l,taille) != 0){
                    JEU[(i-1) * l + (j)] = minesAutour(i-1,j,l,taille) + '0';
                }
                else{
                    JEU[(i-1) * l + (j)] = '~';
                }

                if(minesAutour(i-1,j+1,l,taille) != 0){
                    JEU[(i-1) * l + (j+1)] = minesAutour(i-1,j+1,l,taille) + '0';
                }
                else{
                    JEU[(i-1) * l + (j+1)] = '~';
                }

                if(minesAutour(i,j+1,l,taille) != 0){
                    JEU[(i) * l + (j+1)] = minesAutour(i,j+1,l,taille) + '0';
                }
                else{
                    JEU[(i) * l + (j+1)] = '~';
                }
            }
            else
            {
                if(j==taille-1)
                {
                    if(minesAutour(i-1,j-1,l,taille) != 0){
                        JEU[(i-1) * l + (j-1)] = minesAutour(i-1,j-1,l,taille) + '0';
                    }
                    else{
                        JEU[(i-1) * l + (j-1)] = '~';
                    }

                    if(minesAutour(i-1,j,l,taille) != 0){
                        JEU[(i-1) * l + (j)] = minesAutour(i-1,j,l,taille) + '0';
                    }
                    else{
                        JEU[(i-1) * l + (j)] = '~';
                    }

                    if(minesAutour(i,j-1,l,taille) != 0){
                        JEU[(i) * l + (j-1)] = minesAutour(i,j-1,l,taille) + '0';
                    }
                    else{
                        JEU[(i) * l + (j-1)] = '~';
                    }
                }
                else
                {
                    if(minesAutour(i-1,j-1,l,taille) != 0){
                        JEU[(i-1) * l + (j-1)] = minesAutour(i-1,j-1,l,taille) + '0';
                    }
                    else{
                        JEU[(i-1) * l + (j-1)] = '~';
                        //decouverteCase(i-1,j-1,l,taille);
                    }
                    if(minesAutour(i-1,j,l,taille) != 0){
                        JEU[(i-1) * l + (j)] = minesAutour(i-1,j,l,taille) + '0';
                    }
                    else{
                        JEU[(i-1) * l + (j)] = '~';
                        //decouverteCase(i-1,j,l,taille);
                    }

                    if(minesAutour(i-1,j+1,l,taille) != 0){
                        JEU[(i-1) * l + (j+1)] = minesAutour(i-1,j+1,l,taille) + '0';
                    }
                    else{
                        JEU[(i-1) * l + (j+1)] = '~';
                        //decouverteCase(i-1,j+1,l,taille);
                    }
                    if(minesAutour(i,j-1,l,taille) != 0){
                        JEU[(i) * l + (j-1)] = minesAutour(i,j-1,l,taille) + '0';
                    }
                    else{
                        JEU[(i) * l + (j-1)] = '~';
                        //decouverteCase(i,j-1,l,taille);
                    }
                    if(minesAutour(i,j+1,l,taille) != 0){
                        JEU[(i) * l + (j+1)] = minesAutour(i,j+1,l,taille) + '0';
                    }
                    else{
                        JEU[(i) * l + (j+1)] = '~';
                        //decouverteCase(i,j+1,l,taille);
                    }
                }
            }
        }
        else
        {
            if(minesAutour(i-1,j-1,l,taille) != 0){
                JEU[(i-1) * l + (j-1)] = minesAutour(i-1,j-1,l,taille) + '0';
            }
            else{
                JEU[(i-1) * l + (j-1)] = '~';
                //decouverteCase(i-1,j-1,l,taille);
            }
            if(minesAutour(i-1,j,l,taille) != 0){
                JEU[(i-1) * l + (j)] = minesAutour(i-1,j,l,taille) + '0';
            }
            else{
                JEU[(i-1) * l + (j)] = '~';
                //decouverteCase(i-1,j,l,taille);
            }

            if(minesAutour(i-1,j+1,l,taille) != 0){
                JEU[(i-1) * l + (j+1)] = minesAutour(i-1,j+1,l,taille) + '0';
            }
            else{
                JEU[(i-1) * l + (j+1)] = '~';
                //decouverteCase(i-1,j+1,l,taille);
            }
            if(minesAutour(i,j-1,l,taille) != 0){
                JEU[(i) * l + (j-1)] = minesAutour(i,j-1,l,taille) + '0';
            }
            else{
                JEU[(i) * l + (j-1)] = '~';
                //decouverteCase(i,j-1,l,taille);
            }
            if(minesAutour(i,j+1,l,taille) != 0){
                JEU[(i) * l + (j+1)] = minesAutour(i,j+1,l,taille) + '0';
            }
            else{
                JEU[(i) * l + (j+1)] = '~';
                //decouverteCase(i,j+1,l,taille);
            }
            if(minesAutour(i+1,j-1,l,taille) != 0){
                JEU[(i+1) * l + (j-1)] = minesAutour(i+1,j-1,l,taille) + '0';
            }
            else{
                JEU[(i+1) * l + (j-1)] = '~';
                //decouverteCase(i+1,j-1,l,taille);
            }
            if(minesAutour(i+1,j,l,taille) != 0){
                JEU[(i+1) * l + (j)] = minesAutour(i+1,j,l,taille) + '0';
            }
            else{
                JEU[(i+1) * l + (j)] = '~';
                //decouverteCase(i+1,j,l,taille);
            }
            if(minesAutour(i+1,j+1,l,taille) != 0){
                JEU[(i+1) * l + (j+1)] = minesAutour(i+1,j+1,l,taille) + '0';
            }
            else{
                JEU[(i+1) * l + (j+1)] = '~';
                //decouverteCase(i+1,j+1,l,taille);
            }
        }

}
}

//Fonction basique pour afficher le tableau avec les bombes dedans

void afficheTABBombe(char *MINES, int i1, int j1, int l){

    printf("VOICI LE TABLEAU TRICHE : \n\n");
    printf("   |   0   1   2   3   4   5   6   7   8   \n");
    printf("___|_____________________________________\n");
    for(i1=0;i1<l;i1++)
    {

        if(i1 == 0){

            printf(" %d |   ",i1);

            for(j1=0;j1<l;j1++)
            {
                printf("%c   ",MINES[j1]);             //vérification du tableau de mines
            }

            printf(" \n");
        }
        else if(i1 == 9){

            for(j1=0;j1<l;j1++)
            {
                printf("%c   ",MINES[i1*l+j1]);             //vérification du tableau de mines
            }

            printf(" \n %d |  ",i1);

        }
        else{

            printf(" %d |   ",i1);

            for(j1=0;j1<l;j1++)
            {
                printf("%c   ",MINES[i1*l+j1]);             //vérification du tableau de mines
            }

            printf(" \n");

        }

    }
    printf("\n \n");

}

//Affiche le tableau du joueur

void afficheTAB(char *JEU, int i1, int j1,int l){

    printf("VOICI LE TABLEAU JOUEUR : \n\n");
    printf("   |   0   1   2   3   4   5   6   7   8   \n");
    printf("___|_____________________________________\n");
    for(i1=0;i1<l;i1++)
    {
        if(i1 == 0){

            printf(" %d |   ",i1);

            for(j1=0;j1<l;j1++)
            {
                printf("%c   ",JEU[j1]);             //vérification du tableau de mines
            }
            printf(" \n");
        }
        else if(i1 == 9){

            for(j1=0;j1<l;j1++)
            {
                printf("%c   ",JEU[i1*l+j1]);             //vérification du tableau de mines
            }
            printf(" \n %d |  ",i1);

        }
        else{

            printf(" %d |   ",i1);
            for(j1=0;j1<l;j1++)
            {
                printf("%c   ",JEU[i1*l+j1]);             //vérification du tableau de mines
            }
            printf(" \n");

        }

    }
    printf("\n \n");

}

//Fonction qui permet d'effacer la console en appuyant sur entrer

void effaceConsole(){
    printf("\nAppuyez sur Entrée pour continuer...\n" );
        getchar();
        system("clear");
}

int main(){
    const char* filename1 = "scorefacile";
    const char* filename2 = "scoredifficile";
    FILE* f;
    struct timeval start;
    struct timeval end;
    char pseudo [10];
    char choix;
    int choixjeu, mines, cmtmines;
    int i1,j1;
    srand(time(NULL));
    printf("Entrer votre pseudo : \n");
    scanf("%s", pseudo);
    getchar();
    effaceConsole();
    while (choix != '1' && choix != '2')  //boucle pour que le choix du jeu soit bien en facile ou intermédiaire et faire répéter sinon
    {
        printf("Veuillez choisir la difficulté: (soit 1 soit 2)\n");   //choix difficulté
        printf(" - 1 : Facile (grille en 9x9 avec 10 mines)\n");
        printf(" - 2 : Intermédiaire (grille en 16x16 avec 40 mines)\n");
        scanf("%c",&choix);
        getchar();
    }
    if(choix=='1')
    {
        choixjeu=1;
    }
    else
    {
        choixjeu=2;
    }

    while (choixjeu<0 || choixjeu>3);
    switch (choixjeu)
    {
        case 1 :
            i=9;
            j=9;
            l=9;
            mines=10;
            effaceConsole();
            printf("Vous avez choisi la difficulté facile \n");
        break;
        case 2 :
            i=16;
            j=16;
            l=16;
            mines=40;
            effaceConsole();
            printf("Vous avez choisi la difficulté intermédiaire \n");
        break;

    }
    JEU=malloc(i*j*sizeof(char));
    MINES=malloc(i*j*sizeof(char));

    for(i1=0;i1<l;i1++)
    {
        for(j1=0;j1<l;j1++)
        {
            JEU[i1 * l + j1]='-';
            MINES[i1 * l + j1]='~';
        }
    }
    printf("Initialisation des bombes \n");
    for(cmtmines=0;cmtmines<mines;cmtmines++)
    {
        i1=rand()%l;
        j1=rand()%l;
        if(MINES[i1*l+j1]=='~')
        {
            MINES[i1*l+j1]='M';
        }
        else
        {
            mines++;
        }
    }
    afficheTABBombe(MINES,i1,j1,l);
    afficheTAB(JEU,i1,j1,l);
    effaceConsole();
    gettimeofday(&start, NULL);
    while(compteurMINE(MINES,i1,j1,l) != 0){
        char choixpose = '0';
        char choix = '0';
        //boucle pour que le choix du jeu soit bien en facile ou intermédiaire et faire répéter sinon
        while (choix != '1' && choix != '2')
        {
            effaceConsole();
            afficheTABBombe(MINES,i1,j1,l);
            afficheTAB(JEU,i1,j1,l);
            printf("1 - Decouvrir la case\n");   //choix difficulté
            printf("2 - Poser un drapeau\n");
            scanf("%c",&choix);
            getchar();
        }

        if(choix=='1')
        {
            choixpose=1;
        }
        else
        {
            choixpose=2;
        }
        if(choixpose == 1){
            int choixligne = -1;
            int choixcolonne = -1;
            printf("Choix de la case :\n");
            while (choixligne<0 || choixligne>i)  //boucle pour que le choix du jeu soit bien en facile ou intermédiaire et faire répéter sinon
            {
                printf("Veuillez entrer la ligne concernée selon l'affichage ci-dessus : \n");
                scanf("%d",&choixligne);
                getchar();
            }
            while (choixcolonne<0 || choixcolonne>i)  //boucle pour que le choix du jeu soit bien en facile ou intermédiaire et faire répéter sinon
            {
                printf("Veuillez entrer la colonne concernée selon l'affichage ci-dessus : \n");
                scanf("%d",&choixcolonne);
                getchar();
            }
            i1 = choixligne;
            j1 = choixcolonne;
            if(MINES[(i1)*l + (j1)] == 'M'){
                printf("Vous avez perdu !\n");
                break;
            }
            else{
                if(minesAutour(i1,j1,l,i) == 0){
                    JEU[(i1)*l + (j1)] =  '~';
                    decouverteCase(i1,j1,l,i);

                }
                else{
                    JEU[(i1)*l + (j1)] = minesAutour(i1,j1,l,i) + '0';
                }

            }
            effaceConsole();

        }
        else{
            int choixligne = -1;
            int choixcolonne = -1;
            printf("Choix de la case :\n");
            while (choixligne<0 || choixligne>i)  //boucle pour que le choix du jeu soit bien en facile ou intermédiaire et faire répéter sinon
            {
                printf("Veuillez entrer la ligne concernée selon l'affichage ci-dessus : \n");
                scanf("%d",&choixligne);
                getchar();
            }
            while (choixcolonne<0 || choixcolonne>i)  //boucle pour que le choix du jeu soit bien en facile ou intermédiaire et faire répéter sinon
            {
                printf("Veuillez entrer la colonne concernée selon l'affichage ci-dessus : \n");
                scanf("%d",&choixcolonne);
                getchar();
            }
            i1 = choixligne;
            j1 = choixcolonne;
            JEU[(i1)*l + (j1)] = 'D';
            MINES[(i1)*l + (j1)] = '~';
            effaceConsole();
        }

    }

    gettimeofday(&end, NULL);
    printf("Temps ecoulé : %0.8f sec\n",time_diff(&start, &end));

    if(compteurMINE(MINES,i1,j1,l) == 0){
        printf("Félicitation vous avez réussis à neutraliser toutes les bombes, vous venez donc de gagner la partie !\n");
    }


    // Cette partie du code permet de sauvegarder les meilleurs scores dans un fichier et les afficher

    if(i==9){
      FILE* output_file = fopen(filename1, "a+");
      if (!output_file) {
          perror("fopen");
          exit(EXIT_FAILURE);
      }
      fprintf(output_file, "[%s] - %0.8f secondes\n",pseudo,time_diff(&start, &end));
      fclose(output_file);
      exit(EXIT_SUCCESS);

      char ch;

      f = fopen("scorefacile.txt", "w");

      if(f==NULL){
          printf("Erreur lors de l'ouverture d'un fichier");
          exit(1);
      }

      while((ch=getchar())!=EOF){
          fputc(ch, f);
      }

      fclose(f);


    }
    else{
      FILE* output_file = fopen(filename2, "a+");
      if (!output_file) {
          perror("fopen");
          exit(EXIT_FAILURE);
      }
      fprintf(output_file, "[%s] - %0.8f secondes\n",pseudo,time_diff(&start, &end));
      fclose(output_file);
      exit(EXIT_SUCCESS);

      char ch;

      f = fopen("scoredifficile.txt", "w");

      if(f==NULL){
          printf("Erreur lors de l'ouverture d'un fichier");
          exit(1);
      }

      while((ch=getchar())!=EOF){
          fputc(ch, f);
      }

      fclose(f);
    }


    return 0;

    //fin du code

}//fin du code

// VERIFIER FONCTION COMPTAGE BOMBE EN DIAGONALE-
