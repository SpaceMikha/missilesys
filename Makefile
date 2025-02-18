CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = main.c system_init.c navigation.c guidance.c control.c telemetry.c communication.c diagnostics.c power_management.c
OBJ = $(SRC:.c=.o)
EXEC = missile_firmware

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

flash:
	@echo "Flashing firmware to microcontroller..."
	# Replace with actual flashing command, e.g., avrdude for AVR chips


TESTS = tests/test_navigation tests/test_guidance tests/test_power_management

tests: $(TESTS)

tests/test_%: tests/test_%.c
	$(CC) $(CFLAGS) -o $@ $< $(SRC)

run-tests: tests
	@echo "Running all tests..."
	@for test in $(TESTS); do ./$$test || exit 1; done
	@echo "All tests passed!"

clean:
	rm -f $(OBJ) $(EXEC) $(TESTS)