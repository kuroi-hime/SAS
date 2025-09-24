#include<stdio.h>
#include<string.h>
#define nbrLivreMax 1000
#define longueurChaineMax 100



int main(){
	int choix;
	char reponse, titres[nbrLivreMax][longueurChaineMax], auteurs[nbrLivreMax][longueurChaineMax];
	float prix[nbrLivreMax];
	size_t quantite[nbrLivreMax], nbrLivres=0, i;
	char titreLivre[longueurChaineMax];
    size_t nouvelleQuantite, positionLivre, j;
    int cmp;
	char titreTemp[longueurChaineMax], auteurTemp[longueurChaineMax];
	float prixTemp;
	size_t quantiteTemp, k, nbrTotallivres = 0, dernierChoix;

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
						printf("Voulez-vous ajouter un autre livre? [Y/N]\n");
						scanf("%c",&reponse);
						getchar();
					}

					if (!nbrLivres)
					{
						reponse = 'y';
					}
					
					if(reponse == 'Y' || reponse == 'y'){
						printf("Entrez le titre du livre: ");
						fgets(titres[nbrLivres], longueurChaineMax, stdin);
						printf("Entrez l'auteur du livre: ");
						fgets(auteurs[nbrLivres], longueurChaineMax, stdin);
						printf("Entrez le prix du livre: ");
						scanf("%f", &prix[nbrLivres]);
						printf("Entrez la quantit� du livre: ");
						scanf("%zu", &quantite[nbrLivres]);
						nbrLivres++;
						getchar();
						
						dernierChoix = 1;
					}
					
				}while(reponse == 'Y' || reponse == 'y');
                break;
            case 2:
                printf("Liste des livres disponibles...\n");
				dernierChoix = 2;
				for(i=0;i<nbrLivres;i++){
					if(quantite[i]){
						printf("[Livre %d]  Le titre du livre est: %s, son auteur est: %s sa quantité est: %zu et son prix est: %.2f\n", i+1, titres[i], auteurs[i], quantite[i], prix[i]);
					}
				}
                break;
            case 3:
                printf("Mettre à Jour la Quantité d'un livre...\n");
				dernierChoix = 3;
				printf("Entrez le titre du livre: ");
				fgets(titreLivre, longueurChaineMax, stdin);
				printf("Entrez la quantite du livre: ");
				scanf("%zu", &nouvelleQuantite);
				getchar();
				
				for(i=0;i<nbrLivres;i++){
					j=0;
					while(titreLivre[j]!='\0'){
						cmp = titreLivre[j]-titres[i][j];
						cmp = (cmp<0)?(-1*cmp):cmp;
						if(!(cmp==32 || cmp==0)){
							break;
						}
						j++;
					}
					
					if(titreLivre[j]=='\0'){
						quantite[i] = nouvelleQuantite;
						break;
					}
				}
	
                break;
            case 4:
                printf("Supprimer un livre du Stock...\n");
				dernierChoix = 4;
				printf("Entrez le titre du livre: ");
				fgets(titreLivre, longueurChaineMax, stdin);
				
				for(i=0;i<nbrLivres;i++){
					j=0;
					while(titreLivre[j]!='\0') {
						cmp = titreLivre[j]-titres[i][j];
						cmp = (cmp<0)?(-1*cmp):cmp;
						if(!(cmp==32 || cmp==0)){
							break;
						}
						j++;
					}
					
					if(titreLivre[j]=='\0'){
						j=0;
						while(titreLivre[j]!='\0') {
							titreTemp[j]=titres[i][j];
							j++;
						}
						titreTemp[j]='\0';
						j=0;
						while(auteurs[i][j]!='\0') {
							auteurTemp[j]=auteurs[i][j];
							j++;
						}
						auteurTemp[j]='\0';
						prixTemp = prix[i];
						quantiteTemp = quantite[i];
						for (k = i; k < nbrLivres-1; k++)
						{
							j=0;
							while(titres[k+1][j]!='\0') {
								titres[k][j]=titres[k+1][j];
								j++;
							}
							titres[k][j]='\0';
							j=0;
							while(auteurs[k+1][j]!='\0') {
								auteurs[k][j]=auteurs[k+1][j];
								j++;
							}
							auteurs[k][j]='\0';
							prix[k] = prix[k+1];
							quantite[k] = quantite[k+1];
						}
						nbrLivres--;
						break;
					}
				}
	
                break;
            case 5:
                printf("Nombre Total de livres en Stock...\n");
				dernierChoix = 5;
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
