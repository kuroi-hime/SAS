#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define nbrContactsMax 3
#define longueurChaineMax 100

typedef struct contact{
	char nom[longueurChaineMax];
	char numTelephone[13];
	char adresseEmail[longueurChaineMax];
}contact;

int menu(){
    int choix;
    printf("\n=== Carnet de contacts ===\n");
    printf("1. Ajouter un nouveau contact.\n");
    printf("2. Afficher Tous les contacts.\n");
    printf("3. Modifier un contact.\n");
    printf("4. Supprimer un contact.\n");
    printf("5. Rechercher un contact.\n");
    printf("6. Quitter\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);
    getchar();
    return choix;
}

size_t numeroValide(char numTele[]){
	int l=0;
	
	while(numTele[l]!='\0'){
		if(!l){
  		    if((numTele[l]!='+')&&!(isdigit(numTele[l]))){
			    printf("0");	
  		    	break;
			  }
		}
//		if((l!=0)&&(numTele[l]<'0' || numTele[l]>'9')){ //Probleme ici
//				printf("!%d!", l);
//				break;
//		}
		l++;
		printf("**%d**\n", l);
	}
 
	if (numTele[l]=='\0')
	   return 1;
    return 0;
//    return (numTele[l]=='\0')? 1:0;
}

size_t adresseEmailValide(char adresseEmail[]){
	
}

int ajouterContact(size_t nbrContacts, int dernierChoix, contact contacts[]){
    char reponse;
    
    printf("Ajouter un contact....\n");
    do{
        if(nbrContacts && dernierChoix == 1){
            do{
                printf("Voulez-vous ajouter un autre contact? [Y/N]\n");
                scanf("%c", &reponse);//pas d'idee comment surmonter une reponse de plus d'un caractere.
                getchar();
            }while (reponse != 'Y' && reponse != 'y' && reponse != 'N' && reponse != 'n');
        }
        else{
            reponse = 'y';
        }
        if(nbrContacts==nbrContactsMax && (reponse=='y'||reponse=='Y')){
            printf("\"\"\"Pas de place disponible pour ajouter un nouveau contact.\"\"\"");
            break;
        }
        
        if(reponse == 'Y' || reponse == 'y'){
            printf("Entrez le nom du contact: ");
            fgets(contacts[nbrContacts].nom, longueurChaineMax, stdin);
            do{
            	printf("Entrez le numéro de téléphone du contact: ");
            	fgets(contacts[nbrContacts].numTelephone, longueurChaineMax, stdin);
            	printf("%s.\n", numeroValide(contacts[nbrContacts].numTelephone));
			}while(!numeroValide(contacts[nbrContacts].numTelephone));
            printf("Entrez l'adresse email du contact: ");
            fgets(contacts[nbrContacts].adresseEmail, longueurChaineMax, stdin);
            
            nbrContacts++;
            dernierChoix = 1;
        }
        
    }while(reponse == 'Y' || reponse == 'y');

    return nbrContacts;
}

void afficherContact(int position, contact c){
    printf("**[Contact %d]**\n\tNom contact: %s\n\tNum: %s\n\tEmail: %s\n", position, c.nom, c.numTelephone, c.adresseEmail);		
}

int afficherContacts(size_t nbrContacts, contact contacts[]){
    size_t i;
    printf("Liste de Tous les contacts...\n");
    for(i=0;i<nbrContacts;i++){
        afficherContact(i+1, contacts[i]);
    }
    return 2;
}

int memeLongueur(char chaine1[], char chaine2[]){
    return strlen(chaine1)==strlen(chaine2);
}

size_t comparaison(char nom1[], char nom2[]){
    size_t j = 0;
    int cmparaison;

    while(nom1[j]!='\0'){
        cmparaison = toupper(nom1[j])-toupper(nom2[j]);
        if(cmparaison){
            break;
        }
        j++;
    }
    return j;
}

void contactExiste(size_t indice, size_t nContacts){
    if(indice==nContacts)
        printf("**** Ce contact n'existe pas. ****");
}

int rechercherContact(size_t nContacts, contact contacts[]){
	char nomContact[longueurChaineMax];
	size_t i, j;
	
    printf("Entrez le nom du contact: ");
    fgets(nomContact, longueurChaineMax, stdin);
	
	for(i=0;i<nContacts;i++){
        if(memeLongueur(nomContact, contacts[i].nom)){
            j = comparaison(nomContact, contacts[i].nom);
            if(nomContact[j]=='\0'){
            	afficherContact(i, contacts[i]);
                break;
            }
        }
    }
    contactExiste(i+1, nContacts);
    
    return 5;
}

int modifierContact(size_t nbrContacts, contact contacts[]){
    char nomContact[longueurChaineMax], nouveauNum[longueurChaineMax], nouvelleAdresseEmail[longueurChaineMax];
    int validation, cmparaison;
    size_t i, j;

    printf("Modifier un contact...\n");
    printf("Entrez le nom du contact: ");
    fgets(nomContact, longueurChaineMax, stdin);
    do{
        printf("Entrez le nouveau numéro de contact: ");
        scanf("%s", nouveauNum);
//        while(getchar()!='\n');
    }while((nouveauNum[0]!='0')&&(nouveauNum[0]!='+'));
    printf("Entrez le nouvelle adresse email de contact: ");
    scanf("%s", nouvelleAdresseEmail);
    
    for(i=0;i<nbrContacts;i++){
        if(memeLongueur(nomContact, contacts[i].nom)){
            j = comparaison(nomContact, contacts[i].nom);
            if(nomContact[j]=='\0'){
            	strcpy(contacts[i].numTelephone, nouveauNum);
            	strcpy(contacts[i].adresseEmail, nouvelleAdresseEmail);
            	afficherContact(i, contacts[i]);
                break;
            }
        }
    }
    contactExiste(i+1, nbrContacts);

    return 3;
}

size_t supprimerContact(size_t nContacts, contact contacts[]){
    char nomContact[longueurChaineMax];
    contact temp;
    size_t i, j, k;

    printf("Supprimer un contact...\n");
	printf("Entrez le nom de contact: ");
    fgets(nomContact, longueurChaineMax, stdin);
    
    for(i=0;i<nContacts;i++){
        if(memeLongueur(nomContact, contacts[i].nom)){
            j = comparaison(nomContact, contacts[i].nom);
            if(nomContact[j]=='\0'){
                strcpy(temp.nom, contacts[i].nom);
                strcpy(temp.numTelephone, contacts[i].numTelephone);
                strcpy(temp.adresseEmail, contacts[i].adresseEmail);
            
                printf("** Le contact %s dont le numéro est: %s, l'adresse email est: %s a été supprimé avec succés.\n", temp.nom, temp.numTelephone, temp.adresseEmail);
            
                for (k = i; k < nContacts-1; k++){
                    strcpy(contacts[k].nom, contacts[k+1].nom);
                    strcpy(contacts[k].numTelephone, contacts[k+1].numTelephone);
                    strcpy(contacts[k].adresseEmail, contacts[k+1].adresseEmail);
                }
                nContacts--;
                break;
            }
        }
    }

    if(nomContact[j]!='\0')
        contactExiste(i, nContacts);

    return nContacts;
}

void main(){
    int choix, dernierChoix=6;
	contact contacts[nbrContactsMax];
	size_t nbrContacts = 0;
	
    do{
        choix = menu();

        switch(choix){
            case 1:
//                nbrContacts = ajouterContact(nbrContacts, dernierChoix, contacts);
                printf("Entrez le numéro de téléphone du contact: ");
            	fgets(contacts[0].numTelephone, longueurChaineMax, stdin);
            	
            	printf("%s\nLE / %d", contacts[0].numTelephone,numeroValide(contacts[0].numTelephone));
                dernierChoix = 1;
            break;
            case 2: 
                dernierChoix = afficherContacts(nbrContacts, contacts);
                break;
            case 3:
                dernierChoix = modifierContact(nbrContacts, contacts);
                break;
            case 4: 
                nbrContacts = supprimerContact(nbrContacts, contacts);
                dernierChoix = 4;
                break;
            case 5:
                dernierChoix = rechercherContact(nbrContacts, contacts);
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                dernierChoix = 6;
                printf("Choix invalide. Veuillez réssayer.\n");
        }
    }while(choix!=6);
}
