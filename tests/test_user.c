#include "unity.h"
#include "../src/user.h"
#include <string.h>
#include <stdlib.h>

void setUp(void) {
    // set up before each test
}

void tearDown(void) {
    // clean up after each test
}

void test_createUser_and_saveUser(void) {
    User* user1 = createUser("John Doe", "+1234567890", 100.0);
    TEST_ASSERT_NOT_NULL(user1);
    TEST_ASSERT_EQUAL_STRING("John Doe", user1->name);
    TEST_ASSERT_EQUAL_STRING("+1234567890", user1->phoneNumber);
    TEST_ASSERT_EQUAL_FLOAT(100.0, user1->balance);

    saveUser(user1);
    free(user1);
}

void test_loadUser(void) {
    // Ensure a user is saved before loading
    User* tempUser = createUser("Jane Doe", "+0987654321", 200.0);
    saveUser(tempUser);
    free(tempUser);

    User* loadedUser = loadUser();
    TEST_ASSERT_NOT_NULL(loadedUser);
    TEST_ASSERT_EQUAL_STRING("Jane Doe", loadedUser->name);
    TEST_ASSERT_EQUAL_STRING("+0987654321", loadedUser->phoneNumber);
    TEST_ASSERT_EQUAL_FLOAT(200.0, loadedUser->balance);

    free(loadedUser);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_createUser_and_saveUser);
    RUN_TEST(test_loadUser);
    return UNITY_END();
}