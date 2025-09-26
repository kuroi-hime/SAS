#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define nbrLivreMax 3
#define longueurChaineMax 100



int main(){
	int choix, validation;
	char reponse, titres[nbrLivreMax][longueurChaineMax], auteurs[nbrLivreMax][longueurChaineMax];
	float prix[nbrLivreMax];
	size_t quantite[nbrLivreMax], nbrLivres=0, i;
	char titreLivre[longueurChaineMax];
    size_t nouvelleQuantite, positionLivre, j;
    int cmparaison;
	char titreTemp[longueurChaineMax], auteurTemp[longueurChaineMax];
	float prixTemp;
	size_t quantiteTemp, k, nbrTotallivres = 0, dernierChoix = 7;

    do {
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

        switch (choix) {
            case 1:
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
							validation = scanf("%zu", &quantite[nbrLivres]);
							while(getchar()!='\n');
						}while(validation<=0);
						nbrLivres++;
						
						dernierChoix = 1;
					}
					
				}while(reponse == 'Y' || reponse == 'y');
                break;
            case 2:
                printf("Liste des livres disponibles...\n");
				dernierChoix = 2;
				for(i=0;i<nbrLivres;i++){
					printf("**[Livre %d]** Le titre du livre est: %s, son auteur est: %s sa quantité est: %zu et son prix est: %.2f\n", i+1, titres[i], auteurs[i], quantite[i], prix[i]);
				}
                break;
            case 3:
                printf("Mettre à Jour la Quantité d'un livre...\n");
				dernierChoix = 3;
				printf("Entrez le titre du livre: ");
				fgets(titreLivre, longueurChaineMax, stdin);
				do{
					printf("Entrez la quantite du livre: ");
					validation = scanf("%zu", &nouvelleQuantite);
					while(getchar()!='\n');
				}while(validation<=0);
				
				for(i=0;i<nbrLivres;i++){
					if(strlen(titreLivre)==strlen(titres[i])){
						j=0;
						while(titreLivre[j]!='\0'){
							cmparaison = toupper(titreLivre[j])-toupper(titres[i][j]);
							if(cmparaison){
								break;
							}
							j++;
						}
						if(titreLivre[j]=='\0'){
							quantite[i] = nouvelleQuantite;
							printf("**[Livre %d]** Le titre du livre est: %s, son auteur est: %s sa nouvelle quantité est: %zu et son prix est: %.2f\n", i+1, titres[i], auteurs[i], quantite[i], prix[i]);
							break;
						}
					}
				}
				if(i==nbrLivres)
					printf("**** Ce livre n'existe pas. ****");
	
                break;
            case 4:
                printf("Supprimer un livre du Stock...\n");
				dernierChoix = 4;
				printf("Entrez le titre du livre: ");
				fgets(titreLivre, longueurChaineMax, stdin);
				
				for(i=0;i<nbrLivres;i++){
					if(strlen(titreLivre)==strlen(titres[i])){
						j=0;
						while(titreLivre[j]!='\0'){
							cmparaison = toupper(titreLivre[j])-toupper(titres[i][j]);
							if(cmparaison){
								break;
							}
							j++;
						}
						if(titreLivre[j]=='\0'){
							strcpy(titreTemp, titres[i]);
							strcpy(auteurTemp, auteurs[i]);
							prixTemp = prix[i];
							quantiteTemp = quantite[i];
							printf("** Le livre %s dont l'auteur est: %s, la quantité est: %zu et le prix est: %.2f a été supprimé avec succés.\n", titreTemp, auteurTemp, quantiteTemp, prixTemp);
						
							for (k = i; k < nbrLivres-1; k++){
								strcpy(titres[k], titres[k+1]);
								strcpy(auteurs[k], auteurs[k+1]);
								prix[k] = prix[k+1];
								quantite[k] = quantite[k+1];
							}
							nbrLivres--;
							break;
						}
					}
				}

				if(i==nbrLivres && titreLivre[j]!='\0')
					printf("**** Ce livre n'existe pas. ****");
				
                break;
            case 5:
                printf("Nombre Total de livres en Stock...\n");
				dernierChoix = 5;
				nbrTotallivres = 0;
				for(i=0;i<nbrLivres;i++){
					nbrTotallivres += quantite[i];
				}
				printf("le nombre total de livres en stock est: %d.\n", nbrTotallivres);
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
				dernierChoix = 6;
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 6);

	return 0;
}
