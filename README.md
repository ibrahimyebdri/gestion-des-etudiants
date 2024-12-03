# gestion-des-etudiants
avec les fichier en langage C .

Présentation du Programme de Gestion d'Étudiants en Langage C

Structure Étudiant
Au début du programme, j'ai déclaré une structure nommée "Etudiant" qui comprend un identifiant de type entier, le nom et le prénom de type char, l'âge de type entier, et le niveau de type char.

Fonction creerFichier
La fonction creerFichier initialise un fichier en utilisant le mode "w" de la fonction fopen, créant automatiquement le fichier s'il n'existe pas. Cela crée une base pour stocker les informations des étudiants.

Procédure ajouterEtudiant
La procédure ajouterEtudiant ouvre le fichier en mode écriture "w", vérifie l'état de l'ouverture, et en cas de succès, remplit le fichier avec les informations saisies par l'utilisateur grâce à fprintf. Cette procédure permet d'ajouter de nouveaux étudiants au fichier.

Procédure afficherEtudiant
La procédure afficherEtudiant utilise une boucle while avec fgets pour lire chaque ligne du fichier, stocke ces lignes dans un tableau de caractères appelé "line", puis les affiche avec printf. Une fois toutes les lignes lues, le fichier est fermé avec fclose(file). Cela permet d'afficher les détails de tous les étudiants enregistrés.

Fonction supprimerEtudiant
La fonction supprimerEtudiant supprime un enregistrement d'étudiant à partir d'un fichier. Elle ouvre le fichier "FichierEtudiant.txt" en mode lecture et crée un fichier temporaire "temp.txt" en mode écriture. En parcourant chaque ligne du fichier d'origine, si l'ID de l'étudiant sur la ligne actuelle ne correspond pas à l'ID spécifié, la ligne entière est écrite dans le fichier temporaire. Ensuite, les fichiers sont fermés, le fichier d'origine est supprimé, et le fichier temporaire est renommé pour prendre le nom du fichier d'origine.

Fonction rechercherEtudiant
La fonction rechercherEtudiant a pour objectif de retrouver un étudiant dans un fichier en utilisant son identifiant (ID). Elle ouvre le fichier "FichierEtudiant.txt" en mode lecture, vérifie le succès de l'ouverture, puis parcourt chaque ligne du fichier. Si l'ID de l'étudiant correspond à l'ID spécifié, les détails de l'étudiant sont affichés à l'écran.

Fonction modifierEtudiant
La fonction modifierEtudiant permet la modification des informations d'un étudiant dans un fichier, en se basant sur son identifiant (ID). Elle ouvre le fichier "FichierEtudiant.txt" en mode lecture et crée un fichier temporaire "temp.txt" en mode écriture. En parcourant chaque ligne du fichier d'origine, si l'ID de l'étudiant correspond à l'ID spécifié, la variable etudiantTrouve est mise à un, et l'utilisateur est invité à choisir le champ d'information à modifier (nom, prénom, âge, niveau) via un menu. Selon le choix de l'utilisateur, la fonction effectue la modification correspondante. Les modifications sont ensuite écrites dans le fichier temporaire.

Fonction main
Dans la fonction main, le programme commence par l'initialisation d'un fichier d'étudiants à l'aide de la fonction creerFichier. Ensuite, le programme entre dans une boucle do-while qui affiche un menu d'options à l'utilisateur. L'utilisateur peut choisir parmi plusieurs actions telles que l'ajout, l'affichage, la suppression, la recherche et la modification d'étudiants.
Ajouter un étudiant: Permet à l'utilisateur de spécifier le nombre d'étudiants à ajouter et de fournir les détails tels que l'ID, le nom, le prénom, l'âge, et le niveau pour chaque étudiant. Ces informations sont ensuite ajoutées au fichier à l'aide de la fonction ajouterEtudiant.
Afficher les étudiants: Permet à l'utilisateur de visualiser tous les étudiants enregistrés en appelant la fonction afficherEtudiants.
Supprimer un étudiant: L'utilisateur peut entrer l'ID de l'étudiant à supprimer. La fonction supprimerEtudiant est alors appelée pour effectuer cette opération.
Rechercher un étudiant: L'utilisateur peut saisir l'ID, et la fonction rechercherEtudiant affiche les détails de l'étudiant trouvé, le cas échéant.
Modifier un étudiant: L'utilisateur peut entrer l'ID de l'étudiant à modifier. Le programme affiche un sous-menu avec des choix tels que le nom, le prénom, l'âge ou le niveau. Les modifications sont ensuite enregistrées dans le fichier à l'aide de la fonction modifierEtudiant.
Quitter: Met fin à la boucle, affiche un message de sortie et termine le programme.
Si l'utilisateur entre une option invalide, un message l'informe de son erreur, l'invitant à réessayer.

En résumé, la 1er partie de ce programme offre une interface utilisateur interactive pour gérer une liste d'étudiants, avec des fonctionnalités complètes d'ajout, d'affichage, de suppression, de recherche et de modification, tout en maintenant la persistance des données dans un fichier.





2eme partie :
Fonctions `creerFichierArrivant` et `creerFichierDepart`
1. creerFichierArrivant():
   - Cette fonction crée un fichier nommé "FichierArrivant.txt" en mode écriture (`"w"`).
   - Elle utilise une boucle infinie (`while (1)`) pour permettre à l'utilisateur de saisir les détails des étudiants arrivants, tels que l'ID, le nom, le prénom, l'âge et le niveau.
   - Les données saisies sont stockées dans une structure `struct Etudiant`.
   - Les informations de chaque étudiant sont écrites dans le fichier "FichierArrivant.txt" à chaque itération de la boucle.
   - La saisie se termine lorsque l'utilisateur entre "fin".
2. creerFichierDepart():
   - Cette fonction est similaire à `creerFichierArrivant()` mais elle crée un fichier "FichierDepart.txt" et recueille les détails des étudiants partants.
 Fonction `MaJ`
1. Cette fonction prend en paramètre les noms de quatre fichiers :
   - `fichierEtudiant`: Fichier original contenant les données des étudiants.
   - `fichierArrivant`: Fichier contenant les informations des étudiants arrivants.
   - `fichierEtudiantMaJ`: Fichier qui sera mis à jour avec les nouvelles données.
   - `fichierDepart`: Fichier contenant les identifiants des étudiants partants.
2. Elle ouvre les fichiers en mode lecture (`"r"`) et écriture (`"w"`).
3. Elle lit les identifiants des étudiants partants depuis "fichierDepart" et les stocke dans un tableau `idsDepart`.
4. Elle lit les informations des étudiants arrivants depuis "fichierArrivant" et les écrit dans "fichierEtudiantMaJ".
5. Elle parcourt le fichier "fichierEtudiant" et supprime les étudiants dont l'ID correspond à ceux présents dans "fichierDepart". Elle marque ces suppressions en écrivant une ligne vide dans "fichierEtudiantMaJ".
Fonction `afficherFichierEtudiantMaJ`
1. Cette fonction prend en paramètre le nom d'un fichier ("fichierEtudiantMaJ") et l'ouvre en mode lecture.
2. Elle lit chaque ligne du fichier et l'affiche à la console.
 Fonction `main`La fonction `main` contient un menu interactif avec différentes options, notamment l'option 6 pour effectuer la mise à jour des fichiers.L'option 6 appelle la fonction `MaJ` en lui fournissant les noms des fichiers nécessaires, puis affiche le contenu mis à jour en appelant `afficherFichierEtudiantMaJ`.
