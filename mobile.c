// Mobile Money Application in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the mobile money application
struct mobileMoney {
    char name[20];
    char number[20];
    char network[20];
    char amount[20];
};

// Structure for the mobile money transaction
struct mobileMoneyTransaction {
    char name[20];
    char number[20];
    char network[20];
    char amount[20];
    char transaction[20];
};

// Function to display the menu
void displayMenu() {
    printf("1. Register\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Transfer\n");
    printf("5. Check Balance\n");
    printf("6. Exit\n");
}

// Function to register a new user
void registerUser(struct mobileMoney *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your phone number: ");
    scanf("%s", user->number);
    printf("Enter your network: ");
    scanf("%s", user->network);
    printf("Enter your amount: ");
    scanf("%s", user->amount);
}

// Function to deposit money
void depositMoney(struct mobileMoney *user, struct mobileMoneyTransaction *transaction) {
    printf("Enter your name: ");
    scanf("%s", transaction->name);
    printf("Enter your phone number: ");
    scanf("%s", transaction->number);
    printf("Enter your network: ");
    scanf("%s", transaction->network);
    printf("Enter your amount: ");
    scanf("%s", transaction->amount);
    strcpy(transaction->transaction, "Deposit");
    if (strcmp(user->name, transaction->name) == 0 && strcmp(user->number, transaction->number) == 0 && strcmp(user->network, transaction->network) == 0) {
        int amount = atoi(user->amount) + atoi(transaction->amount);
        sprintf(user->amount, "%d", amount);
        printf("Deposit successful! Your new balance is %s", user->amount);
    } else {
        printf("Deposit failed! Please check your details and try again.");
    }
}

// Function to withdraw money
void withdrawMoney(struct mobileMoney *user, struct mobileMoneyTransaction *transaction) {
    printf("Enter your name: ");
    scanf("%s", transaction->name);
    printf("Enter your phone number: ");
    scanf("%s", transaction->number);
    printf("Enter your network: ");
    scanf("%s", transaction->network);
    printf("Enter your amount: ");
    scanf("%s", transaction->amount);
    strcpy(transaction->transaction, "Withdraw");
    if (strcmp(user->name, transaction->name) == 0 && strcmp(user->number, transaction->number) == 0 && strcmp(user->network, transaction->network) == 0) {
        int amount = atoi(user->amount) - atoi(transaction->amount);
        if (amount < 0) {
            printf("Withdraw failed! You do not have enough balance.");
        } else {
            sprintf(user->amount, "%d", amount);
            printf("Withdraw successful! Your new balance is %s", user->amount);
        }
    } else {
        printf("Withdraw failed! Please check your details and try again.");
    }
}

// Function to transfer money
void transferMoney(struct mobileMoney *user, struct mobileMoneyTransaction *transaction) {
    printf("Enter your name: ");
    scanf("%s", transaction->name);
    printf("Enter your phone number: ");
    scanf("%s", transaction->number);
    printf("Enter your network: ");
    scanf("%s", transaction->network);
    printf("Enter your amount: ");
    scanf("%s", transaction->amount);
    strcpy(transaction->transaction, "Transfer");
    if (strcmp(user->name, transaction->name) == 0 && strcmp(user->number, transaction->number) == 0 && strcmp(user->network, transaction->network) == 0) {
        int amount = atoi(user->amount) - atoi(transaction->amount);
        if (amount < 0) {
            printf("Transfer failed! You do not have enough balance.");
        } else {
            sprintf(user->amount, "%d", amount);
            printf("Transfer successful! Your new balance is %s", user->amount);
        }
    } else {
        printf("Transfer failed! Please check your details and try again.");
    }
}

// Function to check balance
void checkBalance(struct mobileMoney *user) {
    printf("Your balance is %s", user->amount);
}

// Main function
int main() {
    struct mobileMoney user;
    struct mobileMoneyTransaction transaction;
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerUser(&user);
                break;
            case 2:
                depositMoney(&user, &transaction);
                break;
            case 3:
                withdrawMoney(&user, &transaction);
                break;
            case 4:
                transferMoney(&user, &transaction);
                break;
            case 5:
                checkBalance(&user);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }
    return 0;
}

