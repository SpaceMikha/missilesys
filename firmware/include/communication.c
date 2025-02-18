#include "communication.h"
#include <stdio.h>
#include <string.h>

#define ENCRYPTION_KEY 0x5A // Simple XOR encryption key (placeholder)

void initialize_communication() {
    printf("Initializing communication system...\n");
}

void encrypt_message(char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] ^= ENCRYPTION_KEY;
    }
}

void decrypt_message(char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] ^= ENCRYPTION_KEY; // XOR reverses encryption
    }
}

void send_data(const char *data) {
    char encrypted_data[256];
    strncpy(encrypted_data, data, sizeof(encrypted_data));
    encrypt_message(encrypted_data);

    printf("Transmitting encrypted data: %s\n", encrypted_data);
}

void receive_data(char *data) {
    decrypt_message(data);
    printf("Received decrypted data: %s\n", data);
}
