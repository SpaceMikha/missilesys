#ifndef COMMUNICATION_PROTOCOL_H
#define COMMUNICATION_PROTOCOL_H

#define MAX_MESSAGE_SIZE 256

typedef struct {
    float latitude;
    float longitude;
    float altitude;
    float velocity;
    float heading;
    float battery_level;
} TelemetryData;

#endif // COMMUNICATION_PROTOCOL_H
