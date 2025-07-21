#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

User* createUser(const char* name, const char* phoneNumber, double balance) {
    User* newUser = (User*)malloc(sizeof(User));
    if (newUser != NULL) {
        strncpy(newUser->name, name, MAX_NAME_LENGTH - 1);
        newUser->name[MAX_NAME_LENGTH - 1] = '\0';
        strncpy(newUser->phoneNumber, phoneNumber, PHONE_NUMBER_LENGTH - 1);
        newUser->phoneNumber[PHONE_NUMBER_LENGTH - 1] = '\0';
        newUser->balance = balance;
    }
    return newUser;
}

void saveUser(const User* user) {
    FILE *file = fopen("user.dat", "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fwrite(user, sizeof(User), 1, file);
    fclose(file);
}

User* loadUser() {
    FILE *file = fopen("user.dat", "rb");
    if (file == NULL) {
        return NULL;
    }

    User* user = (User*)malloc(sizeof(User));
    if (user != NULL) {
        fread(user, sizeof(User), 1, file);
    }

    fclose(file);
    return user;
}

void registerNewUser() {
    char buffer[100];
    char name[MAX_NAME_LENGTH];
    char phoneNumber[PHONE_NUMBER_LENGTH];
    double balance;
    int c;
    
    // Clear input buffer
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter your name: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    sscanf(buffer, "%s", name);

    printf("Enter your phone number: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    sscanf(buffer, "%s", phoneNumber);

    printf("Enter your initial deposit amount: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    balance = strtod(buffer, NULL);

    User* newUser = createUser(name, phoneNumber, balance);
    if (newUser != NULL) {
        saveUser(newUser);
        printf("Registration successful!\n");
        free(newUser);
    }
}