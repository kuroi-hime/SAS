#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define nbrLivreMax 3
#define longueurChaineMax 100

int menu(){
    int choix;
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Ajouter un livre au Stock.\n");
    printf("2. Afficher Tous les livres Disponibles.\n");
    printf("3. Mettre à Jour la Quantité d'un livre.\n");
    printf("4. Supprimer un livre du Stock.\n");
    printf("5. Afficher le Nombre Total de livres en Stock.\n");
    printf("6. Quitter\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);
    getchar();
    return choix;
}

int ajouterLivre(size_t nbrLivres, int dernierChoix, char titres[][longueurChaineMax], char auteurs[][longueurChaineMax], size_t quantites[], float prix[]){
    char reponse;
    size_t validation;
    printf("Ajouter un livre au Stock....\n");
    do{
        if(nbrLivres && dernierChoix == 1){
            do{
                printf("Voulez-vous ajouter un autre livre? [Y/N]\n");
                scanf("%c", &reponse);//pas d'idee comment surmonter une reponse de plus d'un caractere.
                getchar();
            }while (reponse != 'Y' && reponse != 'y' && reponse != 'N' && reponse != 'n');
        }
        else{
            reponse = 'y';
        }
        if(nbrLivres==nbrLivreMax && (reponse=='y'||reponse=='Y')){
            printf("\"\"\"Pas de place disponible pour ajouter un nouveau livre.\"\"\"");
            break;
        }
        
        if(reponse == 'Y' || reponse == 'y'){
            printf("Entrez le titre du livre: ");
            fgets(titres[nbrLivres], longueurChaineMax, stdin);
            printf("Entrez l'auteur du livre: ");
            fgets(auteurs[nbrLivres], longueurChaineMax, stdin);
            do{
                printf("Entrez le prix du livre: ");
                validation = scanf("%f", &prix[nbrLivres]);
                while(getchar()!='\n');
            }while(validation<=0);
            do{
                printf("Entrez la quantité du livre: ");
                validation = scanf("%zu", &quantites[nbrLivres]);
                while(getchar()!='\n');
            }while(validation<=0);
            nbrLivres++;
            dernierChoix = 1;
        }
        
    }while(reponse == 'Y' || reponse == 'y');

    return nbrLivres;
}

void afficherLivre(int position, char titre[], char auteur[], size_t quantite, float prix){
    printf("**[Livre %d]** Le titre du livre est: %s, son auteur est: %s sa quantité est: %zu et son prix est: %.2f\n", position, titre, auteur, quantite, prix);		
}

int afficherlivres(size_t nbrLivres, char titres[][longueurChaineMax], char auteurs[][longueurChaineMax], size_t quantites[], float prix[]){
    size_t i;
    printf("Liste des livres disponibles...\n");
    for(i=0;i<nbrLivres;i++){
        afficherLivre(i+1, titres[i], auteurs[i], quantites[i], prix[i]);
    }
    return 2;
}

int memeLongueur(char chaine1[], char chaine2[]){
    return strlen(chaine1)==strlen(chaine2);
}

size_t comparaison(char titreLivre[], char titres[]){
    size_t j = 0;
    int cmparaison;

    while(titreLivre[j]!='\0'){
        cmparaison = toupper(titreLivre[j])-toupper(titres[j]);
        if(cmparaison){
            break;
        }
        j++;
    }
    return j;
}

void livreExiste(size_t indice, size_t nLivres){
    if(indice==nLivres)
        printf("**** Ce livre n'existe pas. ****");
}

int mettreAjourQuantite(size_t nbrLivres, char titres[][longueurChaineMax], char auteurs[][longueurChaineMax], size_t quantite[], float prix[]){
    char titreLivre[longueurChaineMax];
    int validation, cmparaison;
    size_t nouvelleQuantite, i, j;

    printf("Mettre à Jour la Quantité d'un livre...\n");
    printf("Entrez le titre du livre: ");
    fgets(titreLivre, longueurChaineMax, stdin);
    do{
        printf("Entrez la quantite du livre: ");
        validation = scanf("%zu", &nouvelleQuantite);
        while(getchar()!='\n');
    }while(validation<=0);
    
    for(i=0;i<nbrLivres;i++){
        if(memeLongueur(titreLivre, titres[i])){
            j = comparaison(titreLivre, titres[i]);
            if(titreLivre[j]=='\0'){
                quantite[i] = nouvelleQuantite;
                printf("**[Livre %d]** Le titre du livre est: %s, son auteur est: %s sa nouvelle quantité est: %zu et son prix est: %.2f\n", i+1, titres[i], auteurs[i], quantite[i], prix[i]);
                break;
            }
        }
    }
    livreExiste(i, nbrLivres);

    return 3;
}

size_t supprimerLivre(size_t nLivres, char titres[][longueurChaineMax], char auteurs[][longueurChaineMax], size_t quantite[], float prix[]){
    char titreLivre[longueurChaineMax], titreTemp[longueurChaineMax], auteurTemp[longueurChaineMax];
    float prixTemp;
    size_t i, j, k, quantiteTemp;

    printf("Supprimer un livre du Stock...\n");
	printf("Entrez le titre du livre: ");
    fgets(titreLivre, longueurChaineMax, stdin);
    
    for(i=0;i<nLivres;i++){
        if(memeLongueur(titreLivre, titres[i])){
            j = comparaison(titreLivre, titres[i]);
            if(titreLivre[j]=='\0'){
                strcpy(titreTemp, titres[i]);
                strcpy(auteurTemp, auteurs[i]);
                prixTemp = prix[i];
                quantiteTemp = quantite[i];
                printf("** Le livre %s dont l'auteur est: %s, la quantité est: %zu et le prix est: %.2f a été supprimé avec succés.\n", titreTemp, auteurTemp, quantiteTemp, prixTemp);
            
                for (k = i; k < nLivres-1; k++){
                    strcpy(titres[k], titres[k+1]);
                    strcpy(auteurs[k], auteurs[k+1]);
                    prix[k] = prix[k+1];
                    quantite[k] = quantite[k+1];
                }
                nLivres--;
                break;
            }
        }
    }

    if(titreLivre[j]!='\0')
        livreExiste(i, nLivres);

    return nLivres;
}

int nbrTotalLivreEnStock(size_t nLivres, size_t quantite[]){
    size_t i, nbrTotallivres = 0;

    printf("Nombre Total de livres en Stock...\n");
    for(i=0;i<nLivres;i++){
        nbrTotallivres += quantite[i];
    }
    printf("le nombre total de livres en stock est: %zu.\n", nbrTotallivres);
    return 5;
}

void main(){
    int choix, dernierChoix=6;
    char titres[nbrLivreMax][longueurChaineMax], auteurs[nbrLivreMax][longueurChaineMax];
	float prix[nbrLivreMax];
	size_t quantite[nbrLivreMax], nbrLivres = 0;

    do{
        choix = menu();

        switch(choix){
            case 1:
                nbrLivres = ajouterLivre(nbrLivres, dernierChoix, titres, auteurs, quantite, prix);
                dernierChoix = 1;
            break;
            case 2: 
                dernierChoix = afficherlivres(nbrLivres, titres, auteurs, quantite, prix);
                break;
            case 3:
                dernierChoix = mettreAjourQuantite(nbrLivres, titres, auteurs, quantite, prix);
                break;
            case 4: 
                nbrLivres = supprimerLivre(nbrLivres, titres, auteurs, quantite, prix);
                dernierChoix = 4;
                break;
            case 5:
                dernierChoix = nbrTotalLivreEnStock(nbrLivres, quantite);
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                dernierChoix = 6;
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }while(choix!=6);
}