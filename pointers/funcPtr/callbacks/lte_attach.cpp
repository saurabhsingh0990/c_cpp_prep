#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum {
    POWER_ON,
    CELL_SEARCH,
    ATTACH_REQ,
    AUTHENTICATION,
    ATTACH_COMPLETE,
    NUM_STATE
} State;

typedef enum {
    EVENT_SUCCESS,
    EVENT_TIMEOUT,
    EVENT_FAILURE
} Event;

// --- Callback function types ---
typedef void (*EventHandler)(State currentState, Event e);

// --- Function prototypes ---
void sendAttachRequest(EventHandler handler);
void performCellSearch(EventHandler handler);
void authenticateNetwork(EventHandler handler);
void attachComplete(EventHandler handler);

// --- Generic event callback handler ---
void handleEvent(State currentState, Event e);

// --- Main ---
int main() {
    srand(time(NULL));

    printf("📶 Modem Powering On...\n");
    handleEvent(POWER_ON, EVENT_SUCCESS);

    return 0;
}

// --- Event simulation ---
Event randomEvent() {
    int r = rand() % 10;
    if (r < 6) return EVENT_SUCCESS; // 60% success
    else if (r < 8) return EVENT_TIMEOUT;
    else return EVENT_FAILURE;
}

// --- State Procedures ---

void performCellSearch(EventHandler handler) {
    printf("🔍 Scanning for available cells...\n");
    sleep(1);
    handler(CELL_SEARCH, randomEvent());
}

void sendAttachRequest(EventHandler handler) {
    printf("📡 Sending ATTACH REQUEST to network...\n");
    sleep(1);
    handler(ATTACH_REQ, randomEvent());
}

void authenticateNetwork(EventHandler handler) {
    printf("🔐 Authenticating with network...\n");
    sleep(1);
    handler(AUTHENTICATION, randomEvent());
}

void attachComplete(EventHandler handler) {
    printf("✅ ATTACH COMPLETE — UE is now connected to the network.\n");
    printf("🎉 RRC Connection Established.\n");
}

// --- Callback Implementation ---

void handleEvent(State currentState, Event e) {
    switch (currentState) {
        case POWER_ON:
            printf("STATE: POWER_ON\n");
            printf("-> Boot complete, initiating CELL_SEARCH.\n");
            performCellSearch(handleEvent);
            break;

        case CELL_SEARCH:
            if (e == EVENT_SUCCESS) {
                printf("CELL_SEARCH successful! Proceeding to ATTACH_REQ.\n");
                sendAttachRequest(handleEvent);
            } else {
                printf("CELL_SEARCH failed. Retrying...\n");
                performCellSearch(handleEvent);
            }
            break;

        case ATTACH_REQ:
            if (e == EVENT_SUCCESS) {
                printf("ATTACH_REQ accepted! Proceeding to AUTHENTICATION.\n");
                authenticateNetwork(handleEvent);
            } else if (e == EVENT_TIMEOUT) {
                printf("ATTACH_REQ timed out. Retrying...\n");
                sendAttachRequest(handleEvent);
            } else {
                printf("ATTACH_REQ failed. Restarting CELL_SEARCH.\n");
                performCellSearch(handleEvent);
            }
            break;

        case AUTHENTICATION:
            if (e == EVENT_SUCCESS) {
                printf("AUTHENTICATION successful! Finalizing attachment.\n");
                attachComplete(handleEvent);
            } else {
                printf("AUTHENTICATION failed. Restarting ATTACH_REQ.\n");
                sendAttachRequest(handleEvent);
            }
            break;

        default:
            printf("Unknown state.\n");
            break;
    }
}
