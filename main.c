#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define TAILLE 12

/* Dans cette version de la bataille navale, j'ai choisi de placer moi meme les bateaux de chaques joueurs,
par manque de temps et surtout pour rattraper mon retard sur ce devoir*/


//Prototypes_________________________________________________________________________________________





// Programme principal_______________________________________________________________________________
int main()
{
int coule1 = 0; //nb de bateau coule du j1
int coule2 = 0; //nb de bateau coule du j2
int *touche1;
int *touche2;

//Declaration gille de Tir J1
char Grille_tir1 [TAILLE][TAILLE]= {
    {' ','A','B','C','D','E','F','G','H','I','J',' '},
    {'1','~','~','~','~','~','~','~','~','~','~',' '},
    {'2','~','~','~','~','~','~','~','~','~','~','A'},
    {'3','~','~','~','~','~','~','~','~','~','~','X'},
    {'4','~','~','~','~','~','~','~','~','~','~','E'},
    {'5','~','~','~','~','~','~','~','~','~','~',' '},
    {'6','~','~','~','~','~','~','~','~','~','~','Y'},
    {'7','~','~','~','~','~','~','~','~','~','~',' '},
    {'8','~','~','~','~','~','~','~','~','~','~','|'},
    {'9','~','~','~','~','~','~','~','~','~','~','|'},
    {'X','~','~','~','~','~','~','~','~','~','~','V'},
    {' ','A','X','E',' ','X',' ','=','>',' ',' ',' '} };

//Declaration grille de tir J2
char Grille_tir2 [TAILLE][TAILLE]= {
    {' ','A','B','C','D','E','F','G','H','I','J',' '},
    {'1','~','~','~','~','~','~','~','~','~','~',' '},
    {'2','~','~','~','~','~','~','~','~','~','~','A'},
    {'3','~','~','~','~','~','~','~','~','~','~','X'},
    {'4','~','~','~','~','~','~','~','~','~','~','E'},
    {'5','~','~','~','~','~','~','~','~','~','~',' '},
    {'6','~','~','~','~','~','~','~','~','~','~','Y'},
    {'7','~','~','~','~','~','~','~','~','~','~',' '},
    {'8','~','~','~','~','~','~','~','~','~','~','|'},
    {'9','~','~','~','~','~','~','~','~','~','~','|'},
    {'X','~','~','~','~','~','~','~','~','~','~','V'},
    {' ','A','X','E',' ','X',' ','=','>',' ',' ',' '} };

//Declaration grille placement bateau J2
char Grille_J2 [TAILLE][TAILLE]= {
    {' ','A','B','C','D','E','F','G','H','I','J',' '},
    {'1','~','~','~','~','~','~','~','~','~','~',' '},
    {'2','#','#','#','#','#','~','~','~','~','~','A'},
    {'3','~','~','~','~','~','~','~','~','~','~','X'},
    {'4','~','~','@','~','~','~','~','~','~','>','E'},
    {'5','~','~','@','~','~','~','~','~','~','>',' '},
    {'6','~','~','@','~','~','~','~','~','~','>','Y'},
    {'7','~','~','~','~','~','~','~','~','~','>',' '},
    {'8','~','~','~','~','~','~','~','~','~','~','|'},
    {'9','*','~','~','~','~','~','~','~','~','~','|'},
    {'X','*','~','~','=','=','=','~','~','~','~','V'},
    {' ','A','X','E',' ','X',' ','=','>',' ',' ',' '} };

//Declaration grille placement bateau J2
char Grille_J1 [TAILLE][TAILLE]= {
    {' ','A','B','C','D','E','F','G','H','I','J',' '},
    {'1','=','=','=','~','~','~','~','~','~','~',' '},
    {'2','~','~','~','~','~','~','~','~','~','~','A'},
    {'3','~','~','~','~','~','@','@','@','~','~','X'},
    {'4','~','~','>','~','~','~','~','~','~','~','E'},
    {'5','~','~','>','~','~','~','~','~','~','~',' '},
    {'6','~','~','>','~','~','~','~','*','~','~','Y'},
    {'7','~','~','>','~','~','~','~','*','~','~',' '},
    {'8','~','~','~','~','~','~','~','~','~','~','|'},
    {'9','~','~','~','~','~','~','~','~','~','~','|'},
    {'X','~','~','~','~','~','#','#','#','#','#','V'},
    {' ','A','X','E',' ','X',' ','=','>',' ',' ',' '} };




affiche_base();
Entete_bat();
affiche(Grille_tir1);
Debut_partie();
//Boucle de deroulement de parrtie
while (coule1 < 5 || coule2 < 5){
        system( " cls " );//on efface l'ecran
        printf("=========================[VOS BATEAUX]==========================\n");
        affiche(Grille_J1);
        Entete_bat();
        printf("===========================-JOUEUR1-============================\n");
        printf("========================[GRILLE DE TIR]=========================\n");
        affiche(Grille_tir1);
        tir(Grille_J2,Grille_tir1);
        printf("Appuyez sur entree pour passer au joueur 2 ");
        fflush(stdin);
        getchar();
        system( " cls " );//on efface l'ecran
        printf("=========================[VOS BATEAUX]==========================\n");
        affiche(Grille_J2);
        Entete_bat();
        printf("===========================-JOUEUR2-============================\n");
        printf("========================[GRILLE DE TIR]=========================\n");
        affiche(Grille_tir2);
        tir(Grille_J1,Grille_tir2);
        printf("Appuyez sur entree pour passer au joueur 1 ");
        fflush(stdin);
        getchar();
        verif_bat(Grille_J1, Grille_J2, coule1, coule2);




}

    return 0;
}

//Procedure___________________________________________________________________________________

//Procedure d'affichage des grilles
void affiche(char Grilles[TAILLE][TAILLE])
{
    int i, j;
    for (i=0;i<TAILLE;i++){
    for (j=0;j<TAILLE;j++){
        printf("[%c]", Grilles[i][j]);
    }
    printf("\n");
  }

  printf("\n");
}

//procedure affichage message de base
void affiche_base()
{
    printf("Bienvenu dans cette version de la Bataille Navale en C\n");
    printf("C'est un jeux a deux joueurs, dans cette version , les bateaux sont deja place !\n\n");
}

//procedure affichage de la legende
void Entete_bat()
{
    printf("===========================-LEGENDE-============================\n");
    printf("Eau : ~   || Touche : X    || A l'eau: O   ||\n");
    printf("================================================================\n");
    printf("Pour cette partie, vous disposerai de :         | Lorqu'un ennemi \n");
    printf("1 Porte-Avion, 5 cases, symbole : #             | touche l'un de vos,\n");
    printf("1 Croiseur, 4 cases, symbole : >                | bateaux, celui-ci\n");
    printf("1 Contre-Torpilleur, 3 cases, Symbole : @       | prend un X ou un O si il loupe a\n");
    printf("1 Sous-Marin, 3 cases, Symbole : =              | L'emplacement\n");
    printf("1 Tropilleur, 2 cases, Symbole : *              | touche sur l'ecran au dessus\n");
    printf("================================================================\n\n");


}

//Procedure lancement de partie
void Debut_partie()
{
    printf("Pour commencer la partie, appujez sur Entree :\n");
    getchar();
    fflush(stdin);


}

void tir(char grille_bat[TAILLE][TAILLE], char grille_touche[TAILLE][TAILLE])
{
    char axe_X_L; //Axe X en lettre
    int axe_Y; // Axe Y  en chiffre
    int axe_X; // Axe X en chiffre
    int n_i;
    int touche;
    char bat [6] = {'#','@','>','=','*'};
    printf("Dans quelle case souhaitez vous tirer ?\n");
    fflush(stdin);
    printf("Sur l'axe X (choix colocne), entrez une Lettre MINUSCULE entre A et J:\n");
    scanf("%c",&axe_X_L);
    fflush(stdin);
    printf("Sur l'axe Y (choix ligne), entrez un chiffre entre 1 et 10\n");
    scanf("%d",&axe_Y);
    //attribution de la bonne cordonee
    switch (axe_X_L)
    {
    case 'a':
        axe_X = 1;
        break;
    case 'b':
        axe_X = 2;
        break;
    case 'c':
        axe_X = 3;
        break;
    case 'd':
        axe_X = 4;
        break;
    case 'e':
        axe_X = 5;
        break;
    case 'f':
        axe_X = 6;
        break;
    case 'g':
        axe_X = 7;
        break;
    case 'h':
        axe_X = 8;
        break;
    case 'i':
        axe_X = 9;
        break;
    case 'j':
        axe_X = 10;
        break;

    }
        touche = 0;
    for (n_i=0;n_i<5;n_i++)
        {    if (grille_bat[axe_Y][axe_X] == bat[n_i])
            {
                touche++;
            }
            else
            {
                touche = touche;
            }
    }

    if (touche == 1){
            grille_bat[axe_Y][axe_X] = 'X'; // on remplace le caractere du bateau par un X sur l'ecran du joueur
                grille_touche [axe_Y][axe_X] = 'X'; // on remplace le caractere d'eau par un X sur l'ecran de l'adversaire
        printf("Touche en %c , %d\n", axe_X_L, axe_Y);
    }
    else
    {
        grille_bat[axe_Y][axe_X] = 'O'; // on remplace le caractere du bateau par un O sur l'ecran du joueur
                grille_touche [axe_Y][axe_X] = 'O'; // on remplace le caractere d'eau par un O sur l'ecran de l'adversaire
        printf("Loupe en %c , %d\n", axe_X_L, axe_Y);
    }

}

void verif_bat(char grille_bat1[TAILLE][TAILLE],char grille_bat2[TAILLE][TAILLE],int *touche1,int *touche2 )
{

    if (grille_bat1[8][6] == 'X' && grille_bat1[8][7] == 'X')
    {
        touche1++;
        printf("Torpilleur coule");
    }
    if (grille_bat1[1][1] == 'X' && grille_bat1[2][1] == 'X' && grille_bat1[3][1] == 'X')
    {
        touche1++;
        printf("Sous-Marin coule");
    }
    if (grille_bat1[6][3] == 'X' && grille_bat1[7][3] == 'X' && grille_bat1[8][3] == 'X')
    {
        touche1++;
        printf("Contre-Torpilleur coule");
    }
    if (grille_bat1[3][4] == 'X' && grille_bat1[3][5] == 'X' && grille_bat1[3][6] == 'X'&& grille_bat1[3][7] == 'X')
    {
        touche1++;
        printf("Croiseur coule");
    }
    if (grille_bat1[6][10] == 'X' && grille_bat1[7][10] == 'X' && grille_bat1[8][10] == 'X'&& grille_bat1[9][10] == 'X'&& grille_bat1[10][10] == 'X')
    {
        touche1++;
        printf("Porte-Avion coule");
    }





        if (grille_bat2[1][9] == 'X' && grille_bat2[1][10] == 'X')
    {
        touche2++;
        printf("Torpilleur coule");
    }
    if (grille_bat2[4][10] == 'X' && grille_bat2[5][10] == 'X' && grille_bat2[6][10] == 'X')
    {
        touche2++;
        printf("Sous-Marin coule");
    }
    if (grille_bat2[3][4] == 'X' && grille_bat2[3][5] == 'X' && grille_bat2[3][6] == 'X')
    {
        touche2++;
        printf("Contre-Torpilleur coule");
    }
    if (grille_bat2[10][4] == 'X' && grille_bat2[10][5] == 'X' && grille_bat2[10][6] == 'X'&& grille_bat2[10][7] == 'X')
    {
        touche2++;
        printf("Croiseur coule");
    }
    if (grille_bat2[1][2] == 'X' && grille_bat2[2][2] == 'X' && grille_bat2[3][2] == 'X'&& grille_bat2[4][2] == 'X'&& grille_bat2[5][2] == 'X')
    {
        touche2++;
        printf("Porte-Avion coule");
    }

    if (touche1 == 5){printf("Bravo !!! le Joueur 1 GAGNE\n");}
    if (touche2 == 5){printf("Bravo !!! le Joueur 2 GAGNE\n");}
}


