#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "favorites.h"

void addFavorite() {
    Favorite fav;
    printf("Enter name: ");
    scanf("%s", fav.name);
    printf("Enter phone number: ");
    scanf("%s", fav.phoneNumber);

    FILE *file = fopen("favorites.dat", "ab");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fwrite(&fav, sizeof(Favorite), 1, file);
    fclose(file);
    printf("Favorite added successfully!\n");
}

void viewFavorites() {
    Favorite fav;
    FILE *file = fopen("favorites.dat", "rb");
    if (file == NULL) {
        printf("No favorites found.\n");
        return;
    }

    printf("\n--- Favorites ---\n");
    while (fread(&fav, sizeof(Favorite), 1, file)) {
        printf("Name: %s, Phone Number: %s\n", fav.name, fav.phoneNumber);
    }
    printf("-----------------\n");

    fclose(file);
}

void manageFavorites() {
    int choice;
    do {
        printf("\nManage Favorites\n");
        printf("1) Add Favorite\n");
        printf("2) View Favorites\n");
        printf("0) Back\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFavorite();
                break;
            case 2:
                viewFavorites();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 0);
}
