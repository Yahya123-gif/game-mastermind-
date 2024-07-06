#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
                  
                  
#define ANSI_COLOR_Bright_Green "\033[92m"
#define ANSI_COLOR_Bright_Red  "\033[91m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_RESET "\x1b[0m"

 FILE *pi;

 char nvtab[40];
 int verifier1[5] ={0,0,0,0,0};
 int verifier2[5] ={0,0,0,0,0};
int b, m = 0, x = 0, o,j, y=2,r=2;
    int h, q = 0;
    int tempi =0;
    int sc[5];
    int dox=0;
    int v[5]={0,0,0,0,0};
    char nom1[10];
    char nom2[10];
    int niveau, g;
    int c[5];
    int i = 0;
    int n=100;
    int selection=0;
    /*FONCTION POUR L ANIMATION LORE DE LA VICTOIRE*/
 void winner() { 
    int iterations = 10;
   printf(ANSI_COLOR_GREEN );
   printf("\033[101m");
    const char *youWinArt[] = {
        "\n\n\n\n\n\n\n",
        "\t\t\t\t\tYYY   YYY  OOO   UU   UU    W      WW    IIIII  NN   NN !!",
        "\t\t\t\t\t YYY YYY  O   O  UU   UU    WW     WW     III   NNN  NN !!",
        "\t\t\t\t\t  YYYYY   O   O  UU   UU    WW WWW WW     III   NNNN NN !!",
        "\t\t\t\t\t   YYY    O   O  UU   UU    WWW   WWW     III   NN NNNN !!",
        "\t\t\t\t\t   YYY     OOO    UUUUU     WWW   WWW    IIIII  NN  NNN !!"
    };
    system("cls");
    for (int i = 0; i < iterations; i++) {
    
        if (i % 2 == 0) {
            for (int j = 0; j < 6; j++) {
                printf("%s\n", youWinArt[j]);
            }
        } else {
            for (int j = 0; j < 6; j++) {
                printf("\n");
            }
        }

        
        usleep(500000); 
        system("cls");
    }
   printf(ANSI_RESET);
  
}

//AFFICHAGE D ANIMATION LORS DE LA DEFAITE
void loser() { 
    int iterations = 10;
    //printf(ANSI_COLOR_RED);
    system("color F6");
    const char *youLoseArt[] = {
        "\n\n\n\n\n\n\n",
        "\t\t\t\t\tYYY   YYY  OOO   UU   UU    LL       OOO   SSSS  EEEE ",
        "\t\t\t\t\t YYY YYY  O   O  UU   UU    LL      O   O  S     E    ",
        "\t\t\t\t\t  YYYYY   O   O  UU   UU    LL      O   O  SSSS  EEEE      ",
        "\t\t\t\t\t   YYY    O   O  UU   UU    LL      O   O      S E    ",
        "\t\t\t\t\t   YYY     OOO    UUUUU     LLLLLL   OOO   SSSS  EEEE "
    };
    system("cls");
    for (int i = 0; i < iterations; i++) {
    
        if (i % 2 == 0) {
            for (int j = 0; j < 6; j++) {
                printf("%s\n", youLoseArt[j]);
            }
        } else {
            for (int j = 0; j < 6; j++) {
                printf("\n");
            }
        }

        usleep(500000); 
        system("cls");
    }
    printf(ANSI_RESET);
}


/*fonction pour trier et stocke les noms et les scores du joueur de niveau debutant */

 void foncttraiter1(int scoress, char nom[20]) {
    
    static int compteur = 0;
    static int sco[10];  
    static char joueur[10][20]; 

    sco[compteur] = scoress;
    strcpy(joueur[compteur], nom);

   /*triage des scores par ordre decroissant*/
    for (int i = 0; i <= compteur; i++) {
        for (int j = i + 1; j <= compteur; j++) {
            if (sco[i] > sco[j]) {
                int tempScore = sco[i];
                sco[i] = sco[j];
                sco[j] = tempScore;

                char tempName[20];
                strcpy(tempName, joueur[i]);
                strcpy(joueur[i], joueur[j]);
                strcpy(joueur[j], tempName);
            }
        }
    }

    FILE *pi = fopen("SCORE niv1.txt", "w");  
    fprintf(pi,"le nom:\t\t\tscore: \n");

    for (int i = 0; i <= compteur; i++) {
        fprintf(pi, "%s \t\t\t %d\n", joueur[i], sco[i]);
    }

    fclose(pi); 
    compteur++; 
}
/*fonction pour trier et stocker les noms et les scores du joueur de niveau expert*/
void foncttraiter2(int scoress, char nom[20]) {

    static int compteur2 = 0;
    static int sco2[10];  
    static char joueur2[10][20]; 

    sco2[compteur2] = scoress;
    strcpy(joueur2[compteur2], nom);

    /*triage des scores par ordre decroissant*/
    for (int i = 0; i <= compteur2; i++) {
        for (int j = i + 1; j <= compteur2; j++) {
            if (sco2[i] > sco2[j]) {
                int tempScore2 = sco2[i];
                sco2[i] = sco2[j];
                sco2[j] = tempScore2;

                char tempName2[20];
                strcpy(tempName2, joueur2[i]);
                strcpy(joueur2[i], joueur2[j]);
                strcpy(joueur2[j], tempName2);
            }
        }
    }

    FILE *pi = fopen("SCORE niv2.txt", "w"); 
    fprintf(pi,"le nom:\t\t\tscore: \n");
     
    for (int i = 0; i <= compteur2; i++) {
        fprintf(pi, "%s \t\t\t %d\n", joueur2[i], sco2[i]);
    }

    fclose(pi);  
    compteur2++;
}
	 
	 
	 
/*fonction pour ralentir l ecriture */
 void ralentir(char l[]) {
    int i;
    for (i = 0; l[i] != '\0'; i++) {
        putchar(l[i]);
        usleep(20000);
    }
}
void menu();
/*fonction du choix de niveau*/
void affichage_menu() {
	
    system("cls");
    const char *options[] = {
        "\n\n\t\t DEBUTANT (pas de repetition)\n",
        "\t\t EXPERT (avec repetition)\n",
        "\t\t Quitter"
    };
    const int nombres = sizeof(options) / sizeof(options[0]);

   
    for (int i = 0; i < nombres; i++) {
        if (i == selection) {
            printf("\033[0;33m");
            printf("\t>%s\n", options[i]);
        } else {
            printf("\033[0;37m");
            printf(" %s\n", options[i]);
        }
    }
}


/*fonction pour system("system cls)*/
void scroll() {
	system("color F0");
    system("cls");
}


/* fonction pour recuperer les codes*/
void tab(int code[5]) {
    int i;
   	printf("\n\n\n\t\t");
    for (i = 0; i < 5; i++) {
        
        scanf("%d", &code[i]);
        printf("\t\t");
    }
}


/*fonction du niveau debutant*/
void debutant() {
 system("color F0");
    scroll();
    while(r==2 || dox==1){
	x=0;
    b=0;
    int f=19;
    m=0;
    char ka[]="\n\n\n\t\t Entrer le nom du 1 er joueur: ";
    ralentir(ka);
    printf("         ");
    scanf("%s",nom1);
    printf("\n\n");
    char kb[]="\n\n\n\t\t Entrer le nom du 2 eme joueur: ";
    ralentir(kb);
    printf("         ");
    scanf("%s",nom2);
    scroll();
    printf("\n\n\n\n\t\t\t%s \t",nom1);
    char kc[]="ENTRER UN CODE SANS REPETER LE MEME NOMBRE (5 chiffres)";
    ralentir(kc);
    printf("\n");
    tab(sc);
    scroll();
    /*BOUCLE POUR NIVEAU DEBUTANT*/
    for (b = 0; b < 20; b++) {
    	for(i=0;i<5;i++){
    		v[i]=0;
		}
    	 m=0;
    	 x=0;
    	/*CONDITION POUR LE JOCKER*/
    	if (b >= 10 && b<=16 && y==2) {
    		printf("\t\t\t%s \n", nom2);
    		char kd[]="vous pouvez utiliser un joker";
            ralentir(kd);
            printf("\n");
            char ke[]="  1 --- > Utiliser joker";
            ralentir(ke);
            printf("\n");
            char kf[]="   2 --- > Ignorer joker ";
            ralentir(kf);
            printf("\n");
            scanf("%d", &y);

            if (y == 1) {
            	char kg[]="ENTRER LE NUMERO DE LA CASE QUE VOUS VOULEZ AFFICHER:";
                ralentir(kg);
                scanf("%d", &h);
                b = b + 3;/*POUR SOUSSTRARIRE LE NOMBRE DE TENTAYIVE RESTANT PAR 3*/
                f=f-3;/*POUR SOUSSTRARIRE LE NOMBRE DE TENTAYIVE RESTANT PAR 3*/
            } else if (y == 2) {
                scroll();
            }

            switch (h) {
                case 1:
                    printf("\n\n\t\t\t\t\t\tLA CASE 1 CONTIENT LE NUMERO : %d\n", sc[0]);
                    break;
                case 2:
                    printf("\n\n\t\t\t\t\t\tLA CASE 2 CONTIENT LE NUMERO : %d\n", sc[1]);
                    break;
                case 3:
                    printf("\n\n\t\t\t\t\t\tLA CASE 3 CONTIENT LE NUMERO : %d\n", sc[2]);
                    break;
                case 4:
                    printf("\n\n\t\t\t\t\t\tLA CASE 4 CONTIENT LE NUMERO : %d\n", sc[3]);
                    break;
                case 5:
                    printf("\n\n\t\t\t\t\t\tLA CASE 5 CONTIENT LE NUMERO : %d\n", sc[4]);
                    break;
            }
        }
        printf("\n\n\n\t\t %s ", nom2);
    	char kh[]="devine le code a 5 chiffres que ";
        ralentir(kh);
    	    printf(" %s ", nom1);
            char kk[]="a entrer :";
            ralentir(kk);
        printf("\n\n\t !!  || Essayer ||  !! \n");
        tab(c);
        /*COMPTER LES ELEMENS BIEN PLACES*/
        for (i = 0; i < 5; i++) {
        if (sc[i] == c[i]){
            x++;
            v[i]=1;
        }
        }
        /*COMPTER LES ELEMENS MAL PLACES*/
        for (i = 0; i < 5; i++){
    	if(v[i]==0){
        for (j = 0; j < 5; j++) {
            	if( c[i] == sc[j] && v[j]!=1 && i!=j){
                m++;   
				break;       
                }
	        }
	   }
	   }
	   /*AFFICHAGE DE NOMBRES DES ELEMENTS MAL PLACES ET BINE PLACES*/
	   if(x!=5){
             printf("\n\t\t%d ", m);
           	char kl[]=" mal placees ";
            ralentir(kl);
            printf("\t");
             printf("\n\t\t%d ", x);
           	char km[]=" bien placees ";
            ralentir(km);
            
        }
       
        /*AFFICHAGE DE NOMBRE DE TENTATIVE RESTANT*/
        while(f>=0 && x!=5 ){
        	if(x!=5){
        	 printf("  \n \t");
        	char kn[]="\n\n\n\t\t il vous reste  ";
            ralentir(kn);
            printf("%d tentatives \n", f);
           
            f--;
            break;
        }
        }
        int score;
         score = b+1;
         /* AFFICHAGE D ANIMATION LORS DE LA VICTOIRE   */
        if (x == 5) {
        	foncttraiter1(score,nom2);
			/*ENVOIE DU SCORE ET NOMS DU JOUEURS POUR LES TRIER ET L ENVOYER AU FICHIER*/
            winner();
            system("color F0");
            printf("\n\n\n\t\tVotre score est :%d",score);
             printf("\n\n\n\n\t");
            printf("TAPEZ ENTRER!");
            
        }
        getch();
        scroll();
        if( b==19 && x!=5 ){
        	loser();
        	printf(ANSI_RESET);
		}
        
       /*POSSIBILITE DE REJOUER UNE AUTRE FOIS*/
       if(b==19 || x==5){
       	system("color F0");
        char kq[]="\n\n\n\t\tsi vous voulez rejouer taper 2 sinon si tu veux retourner au menu taper 1 :  ";
             ralentir(kq);
        	 scanf("%d",&dox);
        	 if(dox == 1){
        	 	menu();
			 }
            scroll();
        	m = 0;
            x = 0;
            break;
		}
	}  
        
      
        
}
}

/*fonction du niveau expert*/
void expert() {
	 system("color F0");
     printf("Mode expert : les chiffres peuvent se r?p?ter.\n");
     scroll();
    while(r==2 || dox==1){
    	int f=19;
    	x=0;
    	m=0;
    char ka[]="Entrer le nom du 1 er joueur:";
    ralentir(ka);
    printf("         ");
    scanf("%s",nom1);
    printf("\n\n");
    char kb[]="Entrer le nom du 2 eme joueur:";
    ralentir(kb);
    printf("         ");
    scanf("%s",nom1);
    scroll();
    
   	printf("%s",nom1);
    char kp[]=" ENTRER UN CODE EN REPETANT QUELQUE CHIFFRE  ";
    ralentir(kp);
    printf("\n");
    tab(sc);
    scroll();
     /*BOUCLE POUR NIVEAU DEBUTANT*/
    for (b = 0; b < 20; b++) {
    	for(i=0;i<5;i++){
    		verifier1[i] = 0;
            verifier2[i] = 0;
		}
        /*CONDITION POUR L OPTION DU JOCKER*/
    	if (b >= 10 && b<=16 && y==2) {
            printf("\t\t\t%s ", nom2);
    		char kd[]="vous pouvez utiliser un joker";
            ralentir(kd);
            printf("\n");
            char ke[]="  1 --- > Utiliser joker";
            ralentir(ke);
            printf("\n");
            char kf[]="   2 --- > Ignorer joker ";
            ralentir(kf);
            printf("\n");
            scanf("%d", &y);

            if (y == 1) {
            	char kx[]="ENTRER LE NUMERO DE LA CASE QUE VOUS VOULEZ AFFICHER:";
                ralentir(kx);
                scanf("%d", &h);
                b = b + 3;
				/*bach itheydo lih 3 dyal lmohawalat*/
                f=f-3;
				/*bach le nombre dyal les tentatives hta hoa itno9sso meno 3*/
            } else if (y == 2) {
                scroll();
            }

            switch (h) {
                case 1:
                    printf("\n\n\t\t\t\t\t\tLA CASE 1 CONTIENT LE NUMERO : %d\n", sc[0]);
                    break;
                case 2:
                    printf("\n\n\t\t\t\t\t\tLA CASE 2 CONTIENT LE NUMERO : %d\n", sc[1]);
                    break;
                case 3:
                    printf("\n\n\t\t\t\t\t\tLA CASE 3 CONTIENT LE NUMERO : %d\n", sc[2]);
                    break;
                case 4:
                    printf("\n\n\t\t\t\t\t\tLA CASE 4 CONTIENT LE NUMERO : %d\n", sc[3]);
                    break;
                case 5:
                    printf("\n\n\t\t\t\t\t\tLA CASE 5 CONTIENT LE NUMERO : %d\n", sc[4]);
                    break;
            }
        }
    	
    	
        printf(" %s ", nom2);
    	char kh[]="devine le code a 5 chiffres que ";
        ralentir(kh);
        printf(" %s ", nom1);
        char kk[]="a entre :";
        ralentir(kk);
        tab(c);
    
    for (int i = 0; i < 5; i++) {
     /*COMPTER LES ELEMENS BIEN PLACES*/
    if (c[i] == sc[i]) {
        x++;
        verifier1[i] = 1; 
        verifier2[i] = 1; 
    }
    }

   for (int i = 0; i < 5; i++) {
    for (int j = 0; j <5; j++) {
         /*COMPTER LES ELEMENS MAL PLACES*/
        if (!verifier1[i] && !verifier2[j] && sc[i] == c[j]) {
            m++;
            verifier1[i] = 1; 
            verifier2[j] = 1; 
            break; 
        }
    }
    }
    /*AFFICHAGE DES ELEMENTS MAL/BIEN PLACES*/
    if(x!=5){
        printf("\n\t\t%d ",m);
        char kl[]=" mal placees ";
        ralentir(kl);
        printf("\t");
        printf("\n\t\t%d ",x);
        char km[]=" bien placees ";
        ralentir(km);
    }
	    int score2=b+1;
	    /*AFFICHAGE DE L ANIMATION LORS DE LA VICTOIRE*/
         if (x == 5) {
         	scroll();
        	foncttraiter2(score2,nom2);
			/*ENVOIE DU SCORE ET NOMS DU JOUEURS POUR LES TRIER ET L ENVOYER AU FICHIER*/
            winner();
            printf(ANSI_RESET);
            printf("\t\t\tVotre score est :%d",score2);
            printf("\n\n\nAPPUYER SUR ENTRER POUR PROCEDER");
            
        }
        /*AFFICHAGE DU NOMBRE D ELEMENT  MAL ET BIEN PLACES*/
         while(f>=0 && x!=5){
         	if(x!=5){
            printf("  \n \t");
        	char kn[]=" il vous reste  ";
            ralentir(kn);
            printf("%d tentatives \n", f);
            f--;
            break;
        }
        }
        getch();
        scroll();
        if( b==19 ){
        	loser();
        	printf(ANSI_RESET);
		}
        
    /*POSSIBILITE DE REJOUER UNE AUTRE FOIS*/
       if(b==19 || x==5){
       	system("color F0");
        char kq[]="si vous voulez rejouer taper 2 sinon si tu veux retourner au menu taper 1 :  ";
             ralentir(kq);
        	 scanf("%d",&dox);
        	 if(dox == 1){
        	 	menu();
			 }
             scroll();
         	m = 0;
            x = 0;
            break;
		}
		
		m = 0;
        x = 0;
    }
    
    scroll();
    }
    
  
    }
/*FONCTION POUR SELECTIONNER LE MENU*/
void menu() {
	printf(ANSI_RESET);
    while (1) {
    	
        affichage_menu();
        int c = getch();
        if (c == 0xE0) {
            c = getch();
            if (c == 72 && selection > 0) /*FLECHE HAUT*/
                selection--;
            else if (c == 80 && selection < 2) /*FLECHE BAS*/
                selection++;
        } else if (c == 13) {
            if (selection == 2) { /*POUR QUITTER LE JEU*/
                exit(0);
            } else if (selection == 0) { /*OPTION DEBUTANT*/
                do {
                    debutant();
                    if (dox == 1) {
                        system("cls");
                         menu() ;
                
                    }
                    system("cls");
                    getch();
                } while (r == 2);
            } else if (selection == 1) { /* EXPERT option*/
                do {
                    expert();
                    if (r == 1) {
                        system("cls");
                        break;
                    }
                    system("cls");
                    affichage_menu();
                    printf("\nAppuyez sur une touche pour continuer...");
                    getch();
                } while (r == 2);
            }
        }
    }
}

int main() {
 
    /* Affichage du telechargement*/
    for (int i = 0; i <= n; i++) {
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t Telechargement du jeu \n");
        printf("\t\t\t\t\t %d %% \r\t\t\t", i);
        if (i == n) {
            system("cls");
        }
        if(i%2==0){
        	printf("%s",ANSI_COLOR_Bright_Red);
        	
		}else{
			printf("%s",ANSI_COLOR_Bright_Green);
		}
        Sleep(40);
        fflush(stdout);
       
        system("cls");
    }
       system("color F0");
    /*Affichage de bienvenue*/
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\tBBBBB  III  EEEEE NN   NN V   V  EEEEE NN   NN U   U  EEEEE\n");
    printf("\t\t\tB   B   I   E     NNN  NN V   V  E     NNN  NN U   U  E    \n");
    printf("\t\t\tBBBBB   I   EEEE  NN N NN V   V  EEEE  NN N NN U   U  EEEE \n");
    printf("\t\t\tB   B   I   E     NN  NNN  V V   E     NN  NNN U   U  E    \n");
    printf("\t\t\tBBBBB  III  EEEEE NN   NN   V    EEEEE NN   NN  UUU   EEEEE\n");
    char zdss[]="\n\n\n\t\ttapez <<entrer>> ";
    ralentir(zdss);
    getch();
    scroll();
    
   /*affichage des lois du jeu*/
    char zx[]="\n\n\nPRINCIPE DU JEU : \n\n\n\t\tTrouver un code de 5 chiffres en se basant sur le nombre des chiffres biens places et mal places.";
    ralentir(zx);
    char zc[]="\n\n\n\nMethode : Le jeu doit se derouler en suivant les etapes suivantes :\n\n\n\t\t\t\t1. Le joueur 1 propose un code (entrer au clavier de 5 chiffres)";
    char zv[]="\n\t\t\t\t2. Le joueur 2 propose un autre code de 5 chiffres.\n\t\t\t\t3. Le programme indique le nombre des chiffres bien places et mal places.";
    char zs[]="\n\t\t\t\t4. Si le nombre max d'essais est atteint (20 tentatives),vous perder.";
    char zd[]="\n\t\t\t\t5. Vous avez une option de 'JOCKER' ou vous pouvez afficher un chiffre de votre choix.\n\t\t\t\t Cette option n'est disponible qu'a partir de la 10 eme tentative. Dans ce cas precis,\n\t\t\t\t vous perdez 3 essais.";
    char zds[]="\n\n\n\t\ttapez <<entrer>> ";
    ralentir(zc);
    ralentir(zv);
    ralentir(zs);
    ralentir(zd);
    ralentir(zds);
    getch();
    system("color F0");
    scroll();
   	printf("\033[30m");
   	printf(ANSI_RESET);
	menu();
	return 0;
}

