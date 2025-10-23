#include <stdio.h>

/* ==========================================================
   Example: Finite State Machine (FSM) using Function Pointers
   ----------------------------------------------------------
   Concept Recap:
   1. Each "state" is represented by an enum constant.
   2. Each state has an associated function (handler).
   3. Transitions between states are defined in an array.
   4. Function pointers are used to call the state’s behavior.
   ========================================================== */

// --- Define possible states in the state machine ---
typedef enum {
    RED,        // 0
    GREEN,      // 1
    YELLOW,     // 2
    NUM_STATES  // always keep last to count total states
} State;

/* ==========================================================
   Function Declarations
   Each function represents the "action" taken in that state.
   ========================================================== */
void redState(void);
void greenState(void);
void yellowState(void);

/* ==========================================================
   State Transition Table
   nextState[state] → defines what the next state will be.

   Example:
   RED    → GREEN
   GREEN  → YELLOW
   YELLOW → RED
   ========================================================== */
State nextState[] = { GREEN, YELLOW, RED };

/* ==========================================================
   Array of Function Pointers (State Handlers)
   Each index corresponds to a state and stores a pointer to 
   that state’s handler function.
   ========================================================== */
void (*stateHandler[])(void) = { redState, greenState, yellowState };

/* ==========================================================
   Implement State Functions
   Each function defines what happens when that state is active.
   ========================================================== */
void redState(void) {
    printf("State: RED → Stop!\n");
}

void greenState(void) {
    printf("State: GREEN → Go!\n");
}

void yellowState(void) {
    printf("State: YELLOW → Slow down!\n");
}

/* ==========================================================
   Driver Code: Simulate the State Machine
   ----------------------------------------------------------
   - We start from an initial state (RED).
   - For each cycle:
       a) Execute the function for the current state.
       b) Move to the next state using the transition table.
   ========================================================== */
int main(void) {
    State current = RED;  // initial state

    // Run the state machine for 6 cycles (2 full rotations)
    for (int i = 0; i < 6; i++) {
        // Execute current state's behavior via function pointer
        (*stateHandler[current])();

        // Move to next state
        current = nextState[current];
    }

    return 0;
}

/* ==========================================================
   Key Interview Takeaways:
   ----------------------------------------------------------
   ✅ 1. Function pointers allow dynamic selection of behavior.
   ✅ 2. FSMs are used in embedded systems, protocols, and UI flows.
   ✅ 3. Transitions and behaviors can be modified without using
         multiple switch-case statements.
   ✅ 4. Improves scalability: adding a new state means
         - Add one function.
         - Add one entry in both arrays.
   ✅ 5. This design pattern is flexible and modular.
   ========================================================== */
