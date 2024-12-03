#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure d'un étudiant
struct Etudiant {
    int id;
    char nom[50];
    char prenom[50];
    int age;
    char niveau[50];
};

// Procédures pour gérer les fichiers
void creerFichier() {
    FILE *file = fopen("FichierEtudiant.txt", "w");
    fclose(file);
}

void ajouterEtudiant(struct Etudiant etudiant) {
    FILE *file = fopen("FichierEtudiant.txt", "a");
    if (file != NULL) {
        fprintf(file, "%d %s %s %d %s\n", etudiant.id, etudiant.nom, etudiant.prenom, etudiant.age, etudiant.niveau);
        fclose(file);
    } else {
        printf("Impossible d'ouvrir le fichier\n");
    }
}

void afficherEtudiants() {
    FILE *file = fopen("FichierEtudiant.txt", "r");
    if (file != NULL) {
        char line[255];
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Impossible d'ouvrir le fichier\n");
    }
}

void supprimerEtudiant(int id) {
    FILE *file = fopen("FichierEtudiant.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char line[255];

    if (file != NULL && temp != NULL) {
        while (fgets(line, sizeof(line), file) != NULL) {
            // Utiliser une copie de la ligne pour éviter de modifier line par strtok
            char lineCopy[255];
            strcpy(lineCopy, line);

            // Vérifier si l'ID de la ligne correspond à l'ID à supprimer
            if (atoi(strtok(lineCopy, " ")) != id) {
                fprintf(temp, "%s", line);
            } else {
                // Si l'ID correspond, ne pas copier cette ligne dans le fichier temporaire
                continue;
            }
        }

        fclose(file);
        fclose(temp);

        remove("FichierEtudiant.txt");
        rename("temp.txt", "FichierEtudiant.txt");
    } else {
        printf("Impossible d'ouvrir le fichier\n");
    }
}

void rechercherEtudiant(int id) {
    FILE *file = fopen("FichierEtudiant.txt", "r");
    char line[255];

    if (file != NULL) {
        int etudiantTrouve = 0;
        while (fgets(line, sizeof(line), file) != NULL) {
            struct Etudiant etudiant;
            sscanf(line, "%d %s %s %d %s", &etudiant.id, etudiant.nom, etudiant.prenom, &etudiant.age, etudiant.niveau);

            if (etudiant.id == id) {
                etudiantTrouve = 1;
                printf("%d %s %s %d %s\n", etudiant.id, etudiant.nom, etudiant.prenom, etudiant.age, etudiant.niveau);
            }
        }
        fclose(file);

        if (!etudiantTrouve) {
            printf("Aucun etudiant trouve avec l'ID %d\n", id);
        }
    } else {
        printf("Impossible d'ouvrir le fichier\n");
    }
}

void modifierEtudiant(int id) {
    FILE *file = fopen("FichierEtudiant.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char line[255];
    int etudiantTrouve = 0;

    if (file != NULL && temp != NULL) {
        while (fgets(line, sizeof(line), file) != NULL) {
            struct Etudiant etudiant;
            sscanf(line, "%d %s %s %d %s", &etudiant.id, etudiant.nom, etudiant.prenom, &etudiant.age, etudiant.niveau);

            if (etudiant.id == id) {
                etudiantTrouve = 1;
                printf("Que voulez-vous modifier pour l'etudiant avec l'ID %d?\n", id);
                printf("1. Nom\n");
                printf("2. Prenom\n");
                printf("3. Age\n");
                printf("4. Niveau\n");
                printf("0. Annuler\n");

                int choix;
                scanf("%d", &choix);

                switch (choix) {
                    case 1:
                        printf("Entrez le nouveau nom : ");
                        scanf("%s", etudiant.nom);
                        break;

                    case 2:
                        printf("Entrez le nouveau prenom : ");
                        scanf("%s", etudiant.prenom);
                        break;

                    case 3:
                        printf("Entrez le nouvel age : ");
                        scanf("%d", &etudiant.age);
                        break;

                    case 4:
                        printf("Entrez le nouveau niveau : ");
                        scanf("%s", etudiant.niveau);
                        break;

                    case 0:
                        printf("Modification annulee.\n");
                        break;

                    default:
                        printf("Choix invalide. Aucune modification effectuee.\n");
                        break;
                }
            }

            fprintf(temp, "%d %s %s %d %s\n", etudiant.id, etudiant.nom, etudiant.prenom, etudiant.age, etudiant.niveau);
        }

        fclose(file);
        fclose(temp);

        remove("FichierEtudiant.txt");
        rename("temp.txt", "FichierEtudiant.txt");

        if (!etudiantTrouve) {
            printf("Aucun etudiant trouve avec l'ID %d\n", id);
        } else {
            printf("Modification effectuee avec succes.\n");
        }
    } else {
        printf("Impossible d'ouvrir le fichier\n");
    }
}

void creerFichierArrivant() {
    printf("Remplissez le fichier des étudiants arrivants (ID, nom, prenom, age, niveau). Entrez 'fin' pour terminer.\n");
    struct Etudiant etudiant;
    FILE *fileArrivant = fopen("FichierArrivant.txt", "w");

    while (1) {
        printf("Entrez l'ID de l'etudiant ou 'fin' pour terminer : ");
        char idInput[10];
        scanf("%s", idInput);

        if (strcmp(idInput, "fin") == 0) {
            break;
        }

        etudiant.id = atoi(idInput);

        printf("Entrez le nom de l'etudiant : ");
        scanf("%s", etudiant.nom);

        printf("Entrez le prenom de l'etudiant : ");
        scanf("%s", etudiant.prenom);

        printf("Entrez l'age de l'etudiant : ");
        scanf("%d", &etudiant.age);

        printf("Entrez le niveau de l'etudiant : ");
        scanf("%s", etudiant.niveau);

        fprintf(fileArrivant, "%d %s %s %d %s\n", etudiant.id, etudiant.nom, etudiant.prenom, etudiant.age, etudiant.niveau);
    }

    fclose(fileArrivant);
}

void creerFichierDepart() {
    printf("Remplissez le fichier des etudiants partants (ID, nom, prénom, age, niveau). Entrez 'fin' pour terminer.\n");
    struct Etudiant etudiant;
    FILE *fileDepart = fopen("FichierDepart.txt", "w");

    while (1) {
        printf("Entrez l'ID de l'etudiant ou 'fin' pour terminer : ");
        char idInput[10];
        scanf("%s", idInput);

        if (strcmp(idInput, "fin") == 0) {
            break;
        }

        etudiant.id = atoi(idInput);

        printf("Entrez le nom de l'etudiant : ");
        scanf("%s", etudiant.nom);

        printf("Entrez le prenom de l'etudiant : ");
        scanf("%s", etudiant.prenom);

        printf("Entrez l'age de l'etudiant : ");
        scanf("%d", &etudiant.age);

        printf("Entrez le niveau de l'etudiant : ");
        scanf("%s", etudiant.niveau);

        fprintf(fileDepart, "%d %s %s %d %s\n", etudiant.id, etudiant.nom, etudiant.prenom, etudiant.age, etudiant.niveau);
    }

    fclose(fileDepart);
}



void MaJ(char *fichierEtudiant, char *fichierArrivant, char *fichierEtudiantMaJ, char *fichierDepart) {
  // Ouverture des fichiers en mode lecture et écriture
  FILE *fileEtudiant = fopen(fichierEtudiant, "r");
  FILE *fileArrivant = fopen(fichierArrivant, "r");
  FILE *fileEtudiantMaJ = fopen(fichierEtudiantMaJ, "w");
  FILE *fileDepart = fopen(fichierDepart, "r");

  // Si les fichiers ne peuvent pas être ouverts, on affiche un message d'erreur
  if (fileEtudiant == NULL || fileArrivant == NULL || fileEtudiantMaJ == NULL || fileDepart == NULL) {
    printf("Impossible d'ouvrir les fichiers\n");
    return;
  }

  // Lire et stocker les identifiants des étudiants à supprimer
  int idDepart;
  int idsDepart[100];  // Supposons qu'il y a au maximum 100 étudiants à supprimer
  int nbDepart = 0;
  while (fscanf(fileDepart, "%d", &idDepart) == 1) {
    idsDepart[nbDepart++] = idDepart;
  }

  // Lire et stocker les informations des étudiants arrivants
  struct Etudiant etudiantsArrivants[100];  // Supposons qu'il y a au maximum 100 étudiants arrivants
  int nbArrivants = 0;
  while (fscanf(fileArrivant, "%d %s %s %d %s", &etudiantsArrivants[nbArrivants].id, etudiantsArrivants[nbArrivants].nom, etudiantsArrivants[nbArrivants].prenom, &etudiantsArrivants[nbArrivants].age, etudiantsArrivants[nbArrivants].niveau) == 5) {
    nbArrivants++;
  }

  // Écrire les étudiants arrivants dans fichierEtudiantMaJ
  for (int i = 0; i < nbArrivants; i++) {
    fprintf(fileEtudiantMaJ, "%d %s %s %d %s\n", etudiantsArrivants[i].id, etudiantsArrivants[i].nom, etudiantsArrivants[i].prenom, etudiantsArrivants[i].age, etudiantsArrivants[i].niveau);
  }

  // Parcourir entièrement le fichier fichierEtudiant et supprimer les étudiants correspondant aux identifiants dans fichierDepart
  struct Etudiant etudiant;
  while (fscanf(fileEtudiant, "%d %s %s %d %s", &etudiant.id, etudiant.nom, etudiant.prenom, &etudiant.age, etudiant.niveau) == 5) {
    for (int i = 0; i < nbDepart; i++) {
      if (etudiant.id == idsDepart[i]) {
        // Écrire une ligne vide pour marquer la suppression de l'étudiant
        fprintf(fileEtudiantMaJ, "\n");
        break;
      }
    }
  }

  // Fermer les fichiers
  fclose(fileEtudiant);
  fclose(fileArrivant);
  fclose(fileEtudiantMaJ);
  fclose(fileDepart);
}


void afficherFichierEtudiants(char *fichierEtudiantMaJ) {
    FILE *file = fopen(fichierEtudiantMaJ, "r");

    if (file != NULL) {
        char line[255];
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Impossible d'ouvrir le fichier\n");
    }
}

// Fonction principale
int main() {
    creerFichier();  // Création du fichier principal FichierEtudiant.txt

    int choice;
    do {
        printf("Menu:\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Supprimer un etudiant\n");
        printf("4. Rechercher un etudiant par ID\n");
        printf("5. Modifier un etudiant\n");
        printf("6. Mettre a jour les fichiers\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Combien d'etudiants voulez-vous ajouter? ");
                int numStudents;
                scanf("%d", &numStudents);
                for (int i = 0; i < numStudents; i++) {
                    struct Etudiant etudiant;
                    printf("Entrez l'ID de l'etudiant : ");
                    scanf("%d", &etudiant.id);
                    printf("Entrez le nom de l'etudiant : ");
                    scanf("%s", etudiant.nom);
                    printf("Entrez le prenom de l'etudiant : ");
                    scanf("%s", etudiant.prenom);
                    printf("Entrez l'age de l'etudiant : ");
                    scanf("%d", &etudiant.age);
                    printf("Entrez le niveau de l'etudiant : ");
                    scanf("%s", etudiant.niveau);
                    ajouterEtudiant(etudiant);
                }
                break;
            }

            case 2:
                afficherEtudiants();
                break;

            case 3: {
                printf("Entrez l'ID de l'etudiant a supprimer : ");
                int id;
                scanf("%d", &id);
                supprimerEtudiant(id);
                break;
            }

            case 4: {
                printf("Entrez l'ID de l'etudiant a rechercher : ");
                int id;
                scanf("%d", &id);
                rechercherEtudiant(id);
                break;
            }

            case 5: {
                printf("Entrez l'ID de l'etudiant à modifier : ");
                int id2;
                scanf("%d", &id2);
                modifierEtudiant(id2);
                break;
            }

            case 6: {
                // Option pour la mise à jour
                //creerFichierDepart();
                //creerFichierArrivant();
                MaJ("FichierEtudiant.txt", "FichierArrivant.txt", "FichierEtudiantMaJ.txt", "FichierDepart.txt");
                printf("\nContenu mis a jour du fichier FichierEtudiantMaJ.txt :\n");
                afficherFichierEtudiants("FichierEtudiantMaJ.txt");
                printf("\nContenu  du fichier DEPART :\n");
                afficherFichierEtudiants("FichierDepart.txt");
                break;
            }

            case 0:
                printf("Au revoir!\n");
                break;

            default:
            printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choice != 0);

    return 0;
}   