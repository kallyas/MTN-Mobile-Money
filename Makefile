CC = gcc
CFLAGS = -Wall -g

SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests
UNITY_DIR = unity

SOURCES = $(SRC_DIR)/app.c $(SRC_DIR)/user.c $(SRC_DIR)/transaction.c $(SRC_DIR)/favorites.c
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLE = $(BUILD_DIR)/mtn

TEST_SOURCES = $(TEST_DIR)/test_user.c $(TEST_DIR)/test_transaction.c $(TEST_DIR)/test_favorites.c
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/%.test.o,$(TEST_SOURCES))
TEST_EXECUTABLES = $(patsubst $(TEST_DIR)/%.c,$(BUILD_DIR)/%.test,$(TEST_SOURCES))

UNITY_SRC = $(UNITY_DIR)/src/unity.c
UNITY_OBJ = $(BUILD_DIR)/unity.o

.PHONY: all clean test e2e_test

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

$(UNITY_OBJ): $(UNITY_SRC)
	$(CC) $(CFLAGS) -I$(UNITY_DIR)/src -c $< -o $@

$(BUILD_DIR)/%.test.o: $(TEST_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(UNITY_DIR)/src -c $< -o $@

$(BUILD_DIR)/test_user.test: $(BUILD_DIR)/test_user.test.o $(BUILD_DIR)/user.o $(UNITY_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

$(BUILD_DIR)/test_transaction.test: $(BUILD_DIR)/test_transaction.test.o $(BUILD_DIR)/user.o $(UNITY_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

$(BUILD_DIR)/test_favorites.test: $(BUILD_DIR)/test_favorites.test.o $(UNITY_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

test: $(TEST_EXECUTABLES)
	@echo "Running unit tests..."
	@for test_exec in $(TEST_EXECUTABLES); do \
		./$$test_exec; \
		done

e2e_test:
	@echo "Running E2E tests..."
	python3 $(TEST_DIR)/e2e_test.py

clean:
	rm -rf $(BUILD_DIR) user.dat favorites.dat