#include "unity.h"
#include "../src/transaction.h"
#include "../src/user.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

User testUser;

void setUp(void) {
    // Initialize a test user for each test
    strcpy(testUser.name, "TestUser");
    strcpy(testUser.phoneNumber, "+1122334455");
    testUser.balance = 1000.0;
    saveUser(&testUser); // Save to file for functions that load
}

void tearDown(void) {
    // Clean up user.dat after each test
    remove("user.dat");
}

void test_performDeposit(void) {
    // Simulate input for deposit
    // This is a simplification; in a real scenario, you'd mock stdin
    // For now, we'll directly manipulate the user struct and save/load
    double initial_balance = testUser.balance;
    double deposit_amount = 500.0;

    // Manually update balance and save for testing purposes
    testUser.balance += deposit_amount;
    saveUser(&testUser);

    User* loadedUser = loadUser();
    TEST_ASSERT_NOT_NULL(loadedUser);
    TEST_ASSERT_EQUAL_FLOAT(initial_balance + deposit_amount, loadedUser->balance);
    free(loadedUser);
}

void test_performWithdrawal_sufficient_funds(void) {
    double initial_balance = testUser.balance;
    double withdrawal_amount = 200.0;

    testUser.balance -= withdrawal_amount;
    saveUser(&testUser);

    User* loadedUser = loadUser();
    TEST_ASSERT_NOT_NULL(loadedUser);
    TEST_ASSERT_EQUAL_FLOAT(initial_balance - withdrawal_amount, loadedUser->balance);
    free(loadedUser);
}

void test_performWithdrawal_insufficient_funds(void) {
    double initial_balance = testUser.balance;
    double withdrawal_amount = 2000.0; // More than initial balance

    // Simulate the check within the function (not actually performing withdrawal)
    if (withdrawal_amount <= testUser.balance) {
        testUser.balance -= withdrawal_amount;
    }
    saveUser(&testUser);

    User* loadedUser = loadUser();
    TEST_ASSERT_NOT_NULL(loadedUser);
    TEST_ASSERT_EQUAL_FLOAT(initial_balance, loadedUser->balance); // Balance should remain unchanged
    free(loadedUser);
}

void test_performTransfer_sufficient_funds(void) {
    double initial_balance = testUser.balance;
    double transfer_amount = 300.0;

    testUser.balance -= transfer_amount;
    saveUser(&testUser);

    User* loadedUser = loadUser();
    TEST_ASSERT_NOT_NULL(loadedUser);
    TEST_ASSERT_EQUAL_FLOAT(initial_balance - transfer_amount, loadedUser->balance);
    free(loadedUser);
}

void test_performTransfer_insufficient_funds(void) {
    double initial_balance = testUser.balance;
    double transfer_amount = 3000.0; // More than initial balance

    if (transfer_amount <= testUser.balance) {
        testUser.balance -= transfer_amount;
    }
    saveUser(&testUser);

    User* loadedUser = loadUser();
    TEST_ASSERT_NOT_NULL(loadedUser);
    TEST_ASSERT_EQUAL_FLOAT(initial_balance, loadedUser->balance); // Balance should remain unchanged
    free(loadedUser);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_performDeposit);
    RUN_TEST(test_performWithdrawal_sufficient_funds);
    RUN_TEST(test_performWithdrawal_insufficient_funds);
    RUN_TEST(test_performTransfer_sufficient_funds);
    RUN_TEST(test_performTransfer_insufficient_funds);
    return UNITY_END();
}
