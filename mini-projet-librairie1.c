#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

int count = 0;

typedef struct {
    char nom[20];
    char tlf[20];
    char email[20];
} Contact;

Contact stock[max];

int ajouter_contact();
int modifier_contact();
int supprimer_contact();
int rechercher_contact();
int afficher_contact();
int recherche(char*);

int valide(int a) {
    if ((a >= 'a' || a <= 'z') ||(a >= 'A' || a <= 'Z') ) {
        return 6;  // Vrai : c'est une lettre
    } else {
        return a;
    }
}


int main() {
    int a;
    int result;

    do {
        printf("1- Ajouter contact \n");
        printf("2- Modifier contact \n");
        printf("3- Supprimer contact \n");
        printf("4- Rechercher contact \n");
        printf("5- afficher les contacts \n");
        printf("0- Quitter programme \n");

        scanf("%d", &a);
        result = valide(a);
        while (getchar() != '\n'); // Vider le tampon d'entrée
        switch(result) {
            case 1:
                ajouter_contact();
                break;
            case 2:
                modifier_contact();
                break;
            case 3:
                supprimer_contact(); // Activer cette fonction si implémentée
                break;
            case 4:
                rechercher_contact();
                break;
            case 5:
                afficher_contact();
                break;
            case 6:
                printf("entrez un nombre !\n");
                break;
            case 0:
                printf("Programme quitté !\n");
                break;
            default:
                printf("Tapez un nombre de la liste svp !\n");
        }
    } while (result != 0);

    return 0;
}

int ajouter_contact() {

    Contact nouveau_contact;

    printf("Tapez le nom du contact :\n");
    scanf(" %[^\n]", nouveau_contact.nom);

    printf("Tapez le telephone du contact :\n");
    scanf(" %[^\n]", nouveau_contact.tlf);


    printf("Tapez l email du contact :\n");
    scanf(" %[^\n]", nouveau_contact.email);


    if (count < max) {
        stock[count] = nouveau_contact;
        count++;
        printf("Contact ajouté !\n");
    } else {
        printf("Contact non ajouté !\n");
    }
    return 0;
}

int modifier_contact() {

    char search[20];
    printf("Tapez le nom du contact à modifier :\n");
    fgets(search, sizeof(search), stdin);
    strtok(search, "\n");

    int index = recherche(search);
    if (index != -1) {
        printf("Tapez le nouveau nom du contact :\n");
        fgets(stock[index].nom, sizeof(stock[index].nom), stdin);
        strtok(stock[index].nom, "\n");

        printf("Tapez le nouveau téléphone du contact :\n");
        fgets(stock[index].tlf, sizeof(stock[index].tlf), stdin);
        strtok(stock[index].tlf, "\n");

        printf("Tapez le nouveau email du contact :\n");
        fgets(stock[index].email, sizeof(stock[index].email), stdin);
        strtok(stock[index].email, "\n");

        printf("Contact modifié avec succès !\n");
    } else {
        printf("Contact non trouvé !\n");
    }
    return 0;
}

int rechercher_contact() {
    char search[20];
    printf("Tapez le nom du contact :\n");
    fgets(search, sizeof(search), stdin);
    strtok(search, "\n");

    int index = recherche(search);
    if (index != -1) {
        printf("Le nom du contact est : %s\n", stock[index].nom);
        printf("L'email du contact est : %s\n", stock[index].email);
        printf("Le téléphone du contact est : %s\n", stock[index].tlf);
    } else {
        printf("Contact non trouvé !\n");
    }
    return 0;
}

int recherche(char* a) {
    for (int i = 0; i < count; i++) {
        if (strcmp(stock[i].nom, a) == 0) {
            return i;
        }
    }
    return -1;
}

int afficher_contact(){
    if(count!=0){
    for(int i=0; i<count; i++){
        printf("Contact %d :\n",i+1);
        printf("le nom est: %s \n",stock[i].nom);
        printf("le email est: %s \n",stock[i].email);
        printf("le telephone est: %s \n \n",stock[i].tlf);
    }
    }
    else{
        printf(" le repertoire est vide! \n");
        return 0;
    }
}


int supprimer_contact() {
    char search[20];
    printf("entrez le nom du contact :\n");
    scanf(" %[^\n]",&search);
    if( recherche(search)!= -1){
        for(int j= recherche(search) ; j<count; j++){
            stock[j] = stock[j+1];
            count--;
        }

        printf("contact supprime! \n");
    }
    else{
        printf("contact non valide ! \n");
    }


}
