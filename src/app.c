#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "transaction.h"

#include "favorites.h"

void displayMenu();
void sendMoney(User *user);
void airtimeBundles();
void momoPay();
void payments();
void savingsLoans();
void financialServices();
void eastAfrica(User *user);
void restOfAfrica(User *user);
void sendWithCare(User *user);
void donations(User *user);

int main() {
    User *user = loadUser();
    int choice;

    if (user == NULL) {
        printf("No user data found. Please register.\n");
        registerNewUser();
        user = loadUser();
    }

    if (user != NULL) {
        printf("Welcome back, %s!\n", user->name);

        while (1) {
            displayMenu();
            printf("Enter your choice: ");
            scanf("%d", &choice);
            while (getchar() != '\n'); // Consume the newline character


            switch (choice) {
                case 1:
                    sendMoney(user);
                    break;
                case 2:
                    airtimeBundles();
                    break;
                case 3:
                    momoPay();
                    break;
                case 4:
                    payments();
                    break;
                case 5:
                    savingsLoans();
                    break;
                case 6:
                    financialServices();
                    break;
                case 7:
                    performWithdrawal(user);
                    break;
                case 8:
                    manageFavorites();
                    break;
                case 9:
                    printf("Your current balance is %.2f\n", user->balance);
                    break;
                case 10:
                    free(user);
                    exit(0);
                default:
                    printf("Invalid choice! Please try again.\n");
            }
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nMTN Mobile Money:\n");
    printf("1) Send Money\n");
    printf("2) Airtime & Bundles\n");
    printf("3) MomoPay\n");
    printf("4) Payments\n");
    printf("5) Savings & Loans\n");
    printf("6) Financial Services\n");
    printf("7) Withdraw Money\n");
    printf("8) My Account\n");
    printf("9) Check Balance\n");
    printf("10) Exit\n");
}

void sendMoney(User *user) {
    int choice;
    printf("\nSend Money\n");
    printf("1) Mobile User\n");
    printf("2) East Africa\n");
    printf("3) Rest Of Africa\n");
    printf("4) Send With Care\n");
    printf("5) Donations\n");    printf("0) Back\n");    scanf("%d", &choice);    while (getchar() != '\n'); // Consume the newline character

    switch (choice) {
        case 1:
            performTransfer(user);
            break;
        case 2:
            eastAfrica(user);
            break;
        case 3:
            restOfAfrica(user);
            break;
        case 4:
            sendWithCare(user);
            break;
        case 5:
            donations(user);
            break;
        case 0:
            return;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

void airtimeBundles() {
    printf("\nAirtime & Bundles: Choose an option.\n");
    // Add sub-menu for airtime/bundles
}

void momoPay() {
    printf("\nMomoPay: Scan QR code or enter merchant code.\n");
    // Add MomoPay logic
}

void payments() {
    printf("\nPayments: Select bill type.\n");
    // Add payments logic
}

void savingsLoans() {
    printf("\nSavings & Loans: View savings or apply for loan.\n");
    // Add savings and loans logic
}

void financialServices() {
    printf("\nFinancial Services: Access banking and insurance.\n");
    // Add financial services logic
}

void eastAfrica(User *user) {
    int choice;
    printf("\nEast Africa\n");
    printf("1) Safaricom MPesa\n");
    printf("2) MTN Rwanda\n");
    printf("3) Tanzania\n");
    printf("4) Ecocash Burundi\n");
    printf("0) Back\n");
    scanf("%d", &choice);
    while (getchar() != '\n'); // Consume the newline character

    switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
            performTransfer(user); // Reusing transfer for simplicity
            break;
        case 0:
            return;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

void restOfAfrica(User *user) {
    int choice;
    printf("\nRest Of Africa\n");
    printf("1) MTN Zambia\n");    printf("0) Back\n");    scanf("%d", &choice);    while (getchar() != '\n'); // Consume the newline character



    switch (choice) {
        case 1:
            performTransfer(user); // Reusing transfer for simplicity
            break;
        case 0:
            return;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

void sendWithCare(User *user) {
    int choice;
    printf("\nSend With Care\n");
    printf("1) Mobile User\n");
    printf("2) Favorites\n");
    printf("3) School Fees\n");
    printf("4) MyCaretaker\n");
    printf("5) AYO send with care Balances or Claim\n");    printf("0) Back\n");    scanf("%d", &choice);    while (getchar() != '\n'); // Consume the newline character

    switch (choice) {
        case 1:
            performTransfer(user); // Reusing transfer for simplicity
            break;
        case 2:
            manageFavorites(); // Re-use existing favorites management
            break;
        case 3:
        case 4:
        case 5:
            printf("Functionality for this option is not yet fully implemented.\n");
            break;
        case 0:
            return;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

void donations(User *user) {
    printf("\nDonations: Choose a charity to donate to.\n");
    // Add donations logic
}
