#include "diagnostics.h"
#include <stdio.h>
#include <time.h>

#define MAX_ERRORS 10

typedef struct {
    time_t timestamp;
    char message[256];
} ErrorLog;

static ErrorLog error_logs[MAX_ERRORS];
static int error_count = 0;

void initialize_diagnostics() {
    printf("Initializing diagnostics system...\n");
    error_count = 0;
}

void log_error(const char *error_message) {
    if (error_count < MAX_ERRORS) {
        error_logs[error_count].timestamp = time(NULL);
        snprintf(error_logs[error_count].message, sizeof(error_logs[error_count].message), "%s", error_message);
        error_count++;
        printf("Error logged: %s\n", error_message);
    } else {
        printf("Error log full! Unable to store new errors.\n");
    }
}

void display_error_logs() {
    printf("System Error Logs:\n");
    for (int i = 0; i < error_count; i++) {
        printf("[%ld] %s\n", error_logs[i].timestamp, error_logs[i].message);
    }
}
