#ifndef FAVORITES_H
#define FAVORITES_H

#define MAX_FAVORITES 10

typedef struct {
    char name[50];
    char phoneNumber[15];
} Favorite;

void manageFavorites();

#endif