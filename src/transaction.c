#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transaction.h"
#include "user.h"

void performDeposit(User *user) {
    char buffer[100];
    double amount;

    printf("Enter the amount to deposit: ");
    while (getchar() != '\n' && getchar() != EOF); // Clear input buffer
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    amount = strtod(buffer, NULL);

    if (amount > 0) {
        user->balance += amount;
        saveUser(user);
        printf("Deposit successful! Your new balance is %.2f\n", user->balance);
    } else {
        printf("Invalid amount entered.\n");
    }
}

void performWithdrawal(User *user) {
    char buffer[100];
    double amount;

    printf("Enter the amount to withdraw: ");
    while (getchar() != '\n' && getchar() != EOF); // Clear input buffer
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    amount = strtod(buffer, NULL);

    if (amount > 0 && amount <= user->balance) {
        user->balance -= amount;
        saveUser(user);
        printf("Withdrawal successful! Your new balance is %.2f\n", user->balance);
    } else {
        printf("Invalid amount or insufficient balance.\n");
    }
}

void performTransfer(User *user) {
    char buffer[100];
    char recipientPhoneNumber[PHONE_NUMBER_LENGTH];
    double amount;

    printf("Enter the recipient's phone number: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    sscanf(buffer, "%s", recipientPhoneNumber);

    printf("Enter the amount to transfer: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    amount = strtod(buffer, NULL);

    if (amount > 0 && amount <= user->balance) {
        user->balance -= amount;
        saveUser(user);
        printf("Transfer successful! You have sent %.2f to %s. Your new balance is %.2f\n", amount, recipientPhoneNumber, user->balance);
    } else {
        printf("Invalid amount or insufficient balance.\n");
    }
}
