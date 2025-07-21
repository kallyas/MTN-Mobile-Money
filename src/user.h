#ifndef USER_H
#define USER_H

#define MAX_NAME_LENGTH 50
#define PHONE_NUMBER_LENGTH 15

// The full definition of the User struct is needed by other modules.
struct User {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[PHONE_NUMBER_LENGTH];
    double balance;
};

typedef struct User User;

// Function prototypes
User* createUser(const char* name, const char* phoneNumber, double balance);
void saveUser(const User* user);
User* loadUser();
void registerNewUser();

#endif