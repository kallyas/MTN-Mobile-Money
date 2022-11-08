// Mobile Money Application in C with saving to file

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

// Function to save the user details to a file
void saveUserDetails(struct mobileMoney *user) {
    FILE *file;
    file = fopen("user.txt", "w");
    fprintf(file, "%s %s %s %s", user->name, user->number, user->network, user->amount);
    fclose(file);
}

// Function to save the transaction details to a file
void saveTransactionDetails(struct mobileMoneyTransaction *transaction) {
    FILE *file;
    file = fopen("transaction.txt", "w");
    fprintf(file, "%s %s %s %s %s", transaction->name, transaction->number, transaction->network, transaction->amount, transaction->transaction);
    fclose(file);
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
    saveUserDetails(user);
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
        saveUserDetails(user);
        saveTransactionDetails(transaction);
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
            saveUserDetails(user);
            saveTransactionDetails(transaction);
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
            saveUserDetails(user);
            saveTransactionDetails(transaction);
        }
    } else {
        printf("Transfer failed! Please check your details and try again.");
    }
}

// Function to check balance
void checkBalance(struct mobileMoney *user) {
    printf("Your balance is %s", user->amount);
}

// Function to load the user details from the file
void loadUserDetails(struct mobileMoney *user) {
    FILE *file;
    file = fopen("user.txt", "r");
    fscanf(file, "%s %s %s %s", user->name, user->number, user->network, user->amount);
    fclose(file);
}

// Function to load the transaction details from the file
void loadTransactionDetails(struct mobileMoneyTransaction *transaction) {
    FILE *file;
    file = fopen("transaction.txt", "r");
    fscanf(file, "%s %s %s %s %s", transaction->name, transaction->number, transaction->network, transaction->amount, transaction->transaction);
    fclose(file);
}

// Function to display the transaction details
void displayTransactionDetails(struct mobileMoneyTransaction *transaction) {
    printf("Name: %s", transaction->name);
    printf("Phone Number: %s", transaction->number);
    printf("Network: %s", transaction->network);
    printf("Amount: %s", transaction->amount);
    printf("Transaction: %s", transaction->transaction);
}

// Function to display the user details
void displayUserDetails(struct mobileMoney *user) {
    printf("Name: %s", user->name);
    printf("Phone Number: %s", user->number);
    printf("Network: %s", user->network);
    printf("Amount: %s", user->amount);
}

// Function to display the menu
void displayMenu() {
    printf("1. Register\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Transfer\n");
    printf("5. Check Balance\n");
    printf("6. Display User Details\n");
    printf("7. Display Transaction Details\n");
    printf("8. Exit\n");
}


int main() {
    struct mobileMoney user;
    struct mobileMoneyTransaction transaction;
    int choice;
    loadUserDetails(&user);
    loadTransactionDetails(&transaction);
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
                displayUserDetails(&user);
                break;
            case 7:
                displayTransactionDetails(&transaction);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }
    return 0;
}