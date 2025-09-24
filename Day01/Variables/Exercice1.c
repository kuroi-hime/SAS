// Challenge 1 : Affichage Informations
// Écrivez un programme en C qui va permettre d'afficher vos informations personnelles :
// nom, prénom, âge, sexe, et adresse email. Les données sont saisies à partir du clavier.
#include<stdio.h>

int main(int argc, char const *argv[])
{
    char nom[50], prenom [50], email[100];
    int age, sexe;
    printf("Entrez votre nom:");
    fgets(nom,sizeof(nom),stdin);

    printf("Entrez votre prénom:");
    fgets(prenom,sizeof(prenom),stdin);

    printf("Entrez votre âge:");
    scanf("%d", &age);

    printf("Entrez votre sexe:\n 1 pour femme \n 2 pour homme\n");
    scanf("%d", &sexe);
    getchar();

    printf("Entrez votre email:");
    fgets(email,sizeof(email),stdin);

    printf("Vos informations personnelles sont:\n");
    printf("nom : %s",nom);
    printf("prenom : %s",prenom);
    printf("age : %d",age);
    printf("\nsexe : ");
    switch(sexe){
        case 1: printf("Femme");break;
        case 2: printf("Homme");break;
        default: printf("choix errone");
    }
    printf("\nemail : %s",email);

    return 0;
}
