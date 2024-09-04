#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Ajouté pour strtok
#define MAX_LIVRES 100

typedef struct {
    char titre[20];
    char auteur[20];
    float prix;
    int quantite;
} Livre;

Livre stock[MAX_LIVRES];
int nombre_livre = 0;

int ajouter_livre();
int afficher_livre();
int rechercher_livre();
int update_livre();
int delete_livre();
int total_livre();

int main() {
    int a;
    do {
        printf("Qu'est-ce que vous voulez ?\n");
        printf(" 1 : Ajouter un livre. \n");
        printf(" 2 : Afficher tous les livres disponibles.\n");
        printf(" 3 : Rechercher un livre par son titre.\n");
        printf(" 4 : Mettre à jour la quantité d'un livre.\n");
        printf(" 5 : Supprimer un livre du stock.\n");
        printf(" 6 : Afficher le nombre total de livres en stock.\n");
        printf(" 0 : Quitter.\n");
        scanf("%d", &a);
        getchar(); // Consomme le caractère de nouvelle ligne laissé dans le buffer
        
        switch(a) {
            case 1:
                ajouter_livre();
                break;
            case 2:
                afficher_livre();
                break;
            case 3:
                rechercher_livre();
                break;
            case 4:
                update_livre();
                break;    
            case 5:
                delete_livre();
                break;   
             case 6:
                total_livre();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Tapez un nombre de la liste svp !\n");
        }
    } while (a != 0);

    return 0;
}

int ajouter_livre() {
    Livre nouveau_livre;
    printf("Tapez le titre du livre :\n");
    fgets(nouveau_livre.titre, sizeof(nouveau_livre.titre), stdin);
    strtok(nouveau_livre.titre, "\n"); // Enlève le retour à la ligne

    printf("Entrez l'auteur du livre :\n");
    fgets(nouveau_livre.auteur, sizeof(nouveau_livre.auteur), stdin);
    strtok(nouveau_livre.auteur, "\n");

    printf("Entrez le prix du livre :\n");
    scanf("%f", &nouveau_livre.prix);
    printf("Entrez la quantité des livres :\n");
    scanf("%d", &nouveau_livre.quantite);
    getchar(); // Consomme le caractère de nouvelle ligne laissé dans le buffer

    if (nombre_livre < MAX_LIVRES) {
        stock[nombre_livre] = nouveau_livre;
        nombre_livre++;
        printf("Livre ajouté avec succès !\n");
    } else {
        printf("Le stock est plein !\n");
    }
}

int afficher_livre() {
    if (nombre_livre == 0) {
        printf("Le stock est vide !\n");
        return 0;
    }
    for (int i = 0; i < nombre_livre; i++) {
        printf("Livre %d \n", i + 1);
        printf("Le titre est : %s \n", stock[i].titre);
        printf("L'auteur est : %s \n", stock[i].auteur);
        printf("Le prix est : %.2f \n", stock[i].prix);
        printf("La quantité est : %d \n\n", stock[i].quantite);
    }
}

int rechercher_livre(){
    char search[20];
    printf("tapez le titre du livre :\n");
    fgets(search, sizeof(search), stdin);
    strtok(search, "\n"); 
    for (int i=0; i<nombre_livre ;i++){
        if(strcmp(search, stock[i].titre) == 0){
            printf("Le titre est : %s \n", stock[i].titre);
            printf("L'auteur est : %s \n", stock[i].auteur);
            printf("Le prix est : %.2f \n", stock[i].prix);
            printf("La quantité est : %d \n\n", stock[i].quantite);
            return 1;
        }
    }    
            printf("livre ne se trouve pas!\n");
            return 0;
}

int update_livre(){
    char search[20];
    printf("tapez le titre du livre: \n");
    fgets(search, sizeof(search), stdin);
    strtok(search, "\n");
     for (int i=0; i<nombre_livre ;i++){
        if(strcmp(search, stock[i].titre) == 0){
            printf("livre trouve! \n");
            printf("donnez la nouvelle quantite svp :\n");
            scanf("%d",&stock[i].quantite);
            printf("livre updated avec succes! \n");
            return 0;
        }
   }
   printf("livre non trouve !\n");
    
}

int delete_livre(){
    char title[20];
    int a;
    printf("tapez le titre du livre que vous voulez supprimer :\n");
    fgets(title, sizeof(title), stdin);
    strtok(title, "\n");
    for(int i=0; i < nombre_livre; i++){
        if(strcmp(title , stock[i].titre)==0){
            printf("est-ce que vous etes sur! \n ");
            printf("1 : OUI \n ");
            printf("2 : NON \n ");
            scanf("%d",&a);
            if(a==1){
                for (int j=i; j<nombre_livre ;j++){
                    stock[j]=stock[j+1];
                    nombre_livre--;
                }
                printf("livre suprime! \n");
            }}
            
        
        }
    }
  
int total_livre(){
    int somme=0;
    for(int i=0; i<nombre_livre; i++){
        somme+=stock[i].quantite;
    }
    printf("le nombre total de livre en stock est : %d \n",somme);
}