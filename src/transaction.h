#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "user.h"

typedef enum {
    DEPOSIT,
    WITHDRAWAL,
    TRANSFER
} TransactionType;

void performDeposit(User *user);
void performWithdrawal(User *user);
void performTransfer(User *user);

#endif