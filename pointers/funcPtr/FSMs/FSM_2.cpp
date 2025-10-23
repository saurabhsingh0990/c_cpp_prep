
#include <stdio.h>

// Define LTE attach states
typedef enum {
    POWER_ON,
    SEARCHING,
    ATTACHING,
    AUTHENTICATING,
    ATTACHED,
    DETACHED,
    NUM_STATES // total number of states
} LTE_state;

// Define next state transitions
LTE_state next_state[] = {SEARCHING, ATTACHING, AUTHENTICATING, ATTACHED, DETACHED, POWER_ON};

// Define state handlers
void powerOn()        { printf("POWER_ON: Device is booting up\n"); }
void searching()      { printf("SEARCHING: Searching for a PLMN\n"); }
void attaching()      { printf("ATTACHING: Attach process started\n"); }
void authenticating() { printf("AUTHENTICATING: Authenticating with the network\n"); }
void attached()       { printf("ATTACHED: DUT attached to network\n"); }
void detached()       { printf("DETACHED: DUT detached!\n"); }

int main() {
    LTE_state current_state = POWER_ON;

    // Array of function pointers for each state
    void (*all_states[])(void) = {powerOn, searching, attaching, authenticating, attached, detached};

    // Run one full attach-detach cycle
    for (int i = 0; i < NUM_STATES; i++) {
        all_states[current_state]();
        current_state = next_state[current_state];
    }

    return 0;
}
