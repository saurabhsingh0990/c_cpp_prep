#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

/*
===========================================
 LTE ATTACH PROCEDURE (EVENT-BASED FSM)
===========================================
INTERVIEW NOTES:
---------------
🧠 Concepts Covered:
  ✅ Finite State Machine (FSM)
  ✅ Transition table using 2D array
  ✅ Function pointers for state handlers
  ✅ Event-driven transitions
  ✅ Enumerations for state/event abstraction

💬 How to Explain in Interview:
  - "This is an event-driven FSM that models LTE attach procedure."
  - "Each state has a handler function, and transitions are determined
     by a 2D table mapping [current_state][event] → next_state."
  - "I used function pointers to make it modular and scalable."
  - "Adding a new state/event just needs one entry in the enum
     and one row/column in the table — no logic rewriting."
*/

// ------------------- ENUM DEFINITIONS -------------------

typedef enum {
    POWER_ON,
    SEARCHING,
    ATTACH_REQUEST,
    AUTHENTICATING,
    ATTACHED,
    DETACHED,
    NUM_STATES  // Keeps track of total number of states
} State;

typedef enum {
    EVENT_SUCCESS,
    EVENT_FAILURE,
    EVENT_TIMEOUT,
    NUM_EVENTS  // Keeps track of total number of events
} Event;

// ------------------- TRANSITION TABLE -------------------
/*
Transition Table:
Rows  -> represent STATES
Columns -> represent EVENTS
Each cell contains the NEXT STATE for [current_state][event]

Example:
transition_table[SEARCHING][EVENT_SUCCESS] = ATTACH_REQUEST
means: if we’re SEARCHING and SUCCESS occurs → move to ATTACH_REQUEST.
*/

State transition_table[NUM_STATES][NUM_EVENTS] = {
    // EVENT_SUCCESS,      EVENT_FAILURE,    EVENT_TIMEOUT
    {SEARCHING,            SEARCHING,        SEARCHING},        // POWER_ON
    {ATTACH_REQUEST,       POWER_ON,         SEARCHING},        // SEARCHING
    {AUTHENTICATING,       SEARCHING,        ATTACH_REQUEST},   // ATTACH_REQUEST
    {ATTACHED,             SEARCHING,        AUTHENTICATING},   // AUTHENTICATING
    {DETACHED,             SEARCHING,        SEARCHING},        // ATTACHED
    {POWER_ON,             SEARCHING,        SEARCHING}         // DETACHED
};

// ------------------- STATE HANDLER FUNCTIONS -------------------
/*
Each function represents an ACTION taken when the device is in a given state.
*/

void powerOnState()       { printf("\nPOWER_ON: Device booting up..."); }
void searchingState()     { printf("\nSEARCHING: Looking for PLMN..."); }
void attachReqState()     { printf("\nATTACH_REQUEST: Sending attach request..."); }
void authState()          { printf("\nAUTHENTICATING: Authenticating with network..."); }
void attachedState()      { printf("\nATTACHED: Device attached successfully!"); }
void detachedState()      { printf("\nDETACHED: Device detached."); }

// ------------------- HELPER ARRAYS -------------------
const char *event_name[] = {"EVENT_SUCCESS", "EVENT_FAILURE", "EVENT_TIMEOUT"};
const char *state_name[] = {"POWER_ON", "SEARCHING", "ATTACH_REQUEST", "AUTHENTICATING", "ATTACHED", "DETACHED"};

// ------------------- MAIN FUNCTION -------------------

int main() {
    srand(time(NULL));  // Seed for random event generation

    Event e = EVENT_SUCCESS;  // Initial event
    State current_state = POWER_ON;  // FSM starts from POWER_ON

    // Array of function pointers for all state handlers
    void (*all_states[])(void) = {
        powerOnState, searchingState, attachReqState, authState, attachedState, detachedState
    };

    printf("=== LTE Attach FSM Simulation Start ===\n");

    for (int i = 0; i < 15; i++) {  // Simulate a few cycles of attach process
        // Call handler for current state
        all_states[current_state]();

        // Log current event and next transition
        printf(" | Event: %s", event_name[e]);

        // Get next state using the transition table
        State next_state = transition_table[current_state][e];
        // printf(" --> Next State: %s\n", state_name[next_state]);

        // Simulate transition
        current_state = next_state;

        // ✅ Early exit if attached successfully
        if (current_state == ATTACHED) {
            printf("\n✅ Device successfully attached to network!\n");
            break;
        }

        // Delay to simulate real-time process (optional)
        sleep(1);

        // EVENT selection logic:
        // After POWER_ON → always success, else random
        if (strcmp(state_name[current_state], "POWER_ON") == 0)
            e = EVENT_SUCCESS;
        else
            e = static_cast<Event>(rand() % NUM_EVENTS);
    }

    printf("\n=== LTE Attach FSM Simulation End ===\n");
    return 0;
}
