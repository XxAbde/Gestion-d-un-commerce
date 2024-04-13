#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour les produits
struct produit {
    char nom[50];
    float prix;
    int id;
};

// Structure pour les clients
struct client {
    int id;
    char nom[50];
    char adresse[100];
    char telephone[20];
};

// Structure pour les fournisseurs
struct fournisseur {
    int id;
    char nom[50];
    char adresse[100];
    char telephone[20];
};

// Structure pour les transactions de ventes
struct transaction {
    struct produit produit;
    int quantite;
    float prix_unitaire;
    struct client client;
};

int main() {
    // D�claration des variables
    struct produit produits[10];
    struct client clients[10];
    struct fournisseur fournisseurs[10];
    struct transaction transactions[10];

    int nb_produits = 0;
    int nb_clients = 0;
    int nb_fournisseurs = 0;
    int nb_transactions = 0;

    // Menu principal
    printf("Syst�me de gestion de commerce\n");
    printf("=============================\n");
    printf("Choix d'une option :\n");
    printf("1. Gestion des produits\n");
    printf("2. Gestion des clients\n");
    printf("3. Sortir du syst�me\n");

    // Fonction d'ajout d'un produit
    void ajouter_produit() {
        struct produit nouveau_produit;
        printf("Entrez le nom du produit : ");
        scanf("%s", nouveau_produit.nom);
        printf("Entrez le prix du produit : ");
        scanf("%f", &nouveau_produit.prix);

        produits[nb_produits++] = nouveau_produit;
    }

    // Fonction de modification d'un produit
    void modifier_produit() {
        int id_produit;
        struct produit produit_modifie;
        struct produit nouveau_produit;

        printf("Entrez l'id du produit � modifier : ");
        scanf("%d", &id_produit);
        printf("Entrez le nouveau nom du produit : ");
        scanf("%s", produit_modifie.nom);
        printf("Entrez le nouveau prix du produit : ");
        scanf("%f", &produit_modifie.prix);

        // Recherche du produit par son id
        for (int i = 0; i < nb_produits; i++) {
            if (produits[i].id == id_produit) {
                produits[i] = nouveau_produit;
                break;
            }
        }
    }

    // Fonction de suppression d'un produit
    void supprimer_produit() {
        int id_produit;


        printf("Entrez l'id du produit � supprimer : ");
        scanf("%d", &id_produit);

        // Recherche du produit par son id
        for (int i = 0; i < nb_produits; i++) {
            if (produits[i].id == id_produit) {
                produits[i] = produits[nb_produits - 1];
                nb_produits--;
                break;
            }
        }
    }

    // Fonction de consultation des produits
    void consulter_produits() {
        for (int i = 0; i < nb_produits; i++) {
            printf("Produit %d :\n", i);
            printf("Id : %d\n", produits[i].id);
            printf("Nom : %s\n", produits[i].nom);
            printf("Prix : %f\n", produits[i].prix);
        }
    }
    void gestion_produits() {
        int choix;
        printf("1. Ajouter un produit\n");
        printf("2. Modifier un produit\n");
        printf("3. Supprimer un produit\n");
        printf("4. Consulter les produits\n");
        printf("5. Retourner au Menu Principal\n");

        // Boucle de choix d'une action sur les produits
        while (1) {
            printf("Votre choix ? ");
            scanf("%d", &choix);

            switch (choix) {
                case 1: // Ajouter un produit
                    ajouter_produit();
                    break;
                case 2: // Modifier un produit
                    modifier_produit();
                    break;
                case 3: // Supprimer un produit
                    supprimer_produit();
                    break;
                case 4: // Consulter les produits
                    consulter_produits();
                    break;
                case 5: // retourn au menu principal
                    return 1 ;
            }
        }
    }

    // Fonction de gestion des clients


    // Fonction d'ajout d'un client
    void ajouter_client() {
        struct client nouveau_client;

        printf("Entrez le nom du client : ");
        scanf("%s", nouveau_client.nom);
        printf("Entrez l'adresse du client : ");
        scanf("%s", nouveau_client.adresse);
        printf("Entrez le t�l�phone du client : ");
        scanf("%s", nouveau_client.telephone);

        clients[nb_clients++] = nouveau_client;
    }

    // Fonction de modification d'un client
    void modifier_client() {
        int id_client;
        struct client client_modifie;
        struct client nouveau_client;

        printf("Entrez l'id du client � modifier : ");
        scanf("%d", &id_client);
        printf("Entrez le nouveau nom du client : ");
        scanf("%s", client_modifie.nom);
        printf("Entrez le nouveau t�l�phone du client : ");
        scanf("%s", client_modifie.telephone);

        // Recherche du client par son id
        for (int i = 0; i < nb_clients; i++) {
            if (clients[i].id == id_client) {
                clients[i] = nouveau_client;
                break;
            }
        }
    }

    // Fonction de suppression d'un client
    void supprimer_client() {
        int id_client;

        printf("Entrez l'id du client � supprimer : ");
        scanf("%d", &id_client);

        // Recherche du client par son id
        for (int i = 0; i < nb_clients; i++) {
            if (clients[i].id == id_client) {
                clients[i] = clients[nb_clients - 1];
                nb_clients--;
                break;
            }
        }
    }

    // Fonction de consultation des clients
    void consulter_clients() {
        for (int i = 0; i < nb_clients; i++) {
            printf("Client %d :\n", i);
            printf("Nom : %s\n", clients[i].nom);
            printf("Adresse : %s\n", clients[i].adresse);
            printf("T�l�phone : %s\n", clients[i].telephone);
        }
    }
    void gestion_clients() {
        int choix;
        printf("1. Ajouter un client\n");
        printf("2. Modifier un client\n");
        printf("3. Supprimer un client\n");
        printf("4. Consulter les clients\n");
        printf("5. Retourner au Menu Principal");

        // Boucle de choix d'une action sur les clients
        while (1) {
            printf("Votre choix ? ");
            scanf("%d", &choix);

            switch (choix) {
                case 1: // Ajouter un client
                    ajouter_client();
                    break;
                case 2: // Modifier un client
                    modifier_client();
                    break;
                case 3: // Supprimer un client
                    supprimer_client();
                    break;
                case 4: // Consulter les clients
                    consulter_clients();
                    break;
                case 5:
                    return 1 ;
            }
        }
    }

    while (1) {
        int choix;
        printf("Votre choix ? ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: // Gestion des produits
                gestion_produits();
                break;
            case 2: // Gestion des clients
                gestion_clients();
                break;
            case 3: // Sortir du syst�me
                printf("Au revoir !\n");
                return 0;
        }
    }
}
