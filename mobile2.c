#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define FILENAME_USER "user.txt"
#define FILENAME_TRANSACTION "transaction.txt"

struct MobileMoney {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NAME_LENGTH];
    char network[MAX_NAME_LENGTH];
    int amount;
};

struct MobileMoneyTransaction {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NAME_LENGTH];
    char network[MAX_NAME_LENGTH];
    int amount;
    char transactionType[MAX_NAME_LENGTH];
};

void saveDataToFile(const char *filename, const void *data, size_t dataSize) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fwrite(data, dataSize, 1, file);
    fclose(file);
}

void loadDataFromFile(const char *filename, void *data, size_t dataSize) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
         saveDataToFile(filename, data, dataSize);
        return;
    }

    fread(data, dataSize, 1, file);
    fclose(file);
}

void registerUser(struct MobileMoney *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your phone number: ");
    scanf("%s", user->number);
    printf("Enter your network: ");
    scanf("%s", user->network);
    printf("Enter your initial amount: ");
    scanf("%d", &user->amount);
    saveDataToFile(FILENAME_USER, user, sizeof(struct MobileMoney));
    printf("Registration successful!\n");
}

void performTransaction(struct MobileMoney *user, struct MobileMoneyTransaction *transaction, const char *transactionType) {
    printf("Enter your name: ");
    scanf("%s", transaction->name);
    printf("Enter your phone number: ");
    scanf("%s", transaction->number);
    printf("Enter your network: ");
    scanf("%s", transaction->network);
    printf("Enter the transaction amount: ");
    scanf("%d", &transaction->amount);
    strcpy(transaction->transactionType, transactionType);

    if (strcmp(user->name, transaction->name) == 0 &&
        strcmp(user->number, transaction->number) == 0 &&
        strcmp(user->network, transaction->network) == 0) {
        if (transaction->amount > 0) {
            if (strcmp(transactionType, "Deposit") == 0) {
                user->amount += transaction->amount;
            } else if (strcmp(transactionType, "Withdraw") == 0) {
                if (transaction->amount <= user->amount) {
                    user->amount -= transaction->amount;
                } else {
                    printf("Withdrawal failed! Insufficient balance.\n");
                    return;
                }
            } else if (strcmp(transactionType, "Transfer") == 0) {
                if (transaction->amount <= user->amount) {
                    user->amount -= transaction->amount;
                } else {
                    printf("Transfer failed! Insufficient balance.\n");
                    return;
                }
            }
            saveDataToFile(FILENAME_USER, user, sizeof(struct MobileMoney));
            saveDataToFile(FILENAME_TRANSACTION, transaction, sizeof(struct MobileMoneyTransaction));
            printf("%s successful! Your new balance is %d\n", transactionType, user->amount);
        } else {
            printf("Invalid amount entered.\n");
        }
    } else {
        printf("%s failed! Please check your details and try again.\n", transactionType);
    }
}

void checkBalance(const struct MobileMoney *user) {
    printf("Your balance is %d\n", user->amount);
}

void displayDetails(const void *data, const char *dataType) {
    if (strcmp(dataType, "User") == 0) {
        struct MobileMoney *user = (struct MobileMoney *)data;
        printf("Name: %s\n", user->name);
        printf("Phone Number: %s\n", user->number);
        printf("Network: %s\n", user->network);
        printf("Amount: %d\n", user->amount);
    } else if (strcmp(dataType, "Transaction") == 0) {
        struct MobileMoneyTransaction *transaction = (struct MobileMoneyTransaction *)data;
        printf("Name: %s\n", transaction->name);
        printf("Phone Number: %s\n", transaction->number);
        printf("Network: %s\n", transaction->network);
        printf("Amount: %d\n", transaction->amount);
        printf("Transaction Type: %s\n", transaction->transactionType);
    }
}

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
    struct MobileMoney user;
    struct MobileMoneyTransaction transaction;
    int choice;

    loadDataFromFile(FILENAME_USER, &user, sizeof(struct MobileMoney));
    loadDataFromFile(FILENAME_TRANSACTION, &transaction, sizeof(struct MobileMoneyTransaction));

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser(&user);
                break;
            case 2:
                performTransaction(&user, &transaction, "Deposit");
                break;
            case 3:
                performTransaction(&user, &transaction, "Withdraw");
                break;
            case 4:
                performTransaction(&user, &transaction, "Transfer");
                break;
            case 5:
                checkBalance(&user);
                break;
            case 6:
                displayDetails(&user, "User");
                break;
            case 7:
                displayDetails(&transaction, "Transaction");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
