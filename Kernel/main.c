#include "include/printm.h"
#include "include/shell.h"
#include "include/esheduler.h"
#include "include/dost.h"
#include "include/nop.h"

// WARNING
// THIS PROJECT IS SOLELY FOR HOBBY PURPOSES AND SHOULD NEVER
// EXPECT PROFESSIONAL RESULTS
// HAVE A GOOD DAY

// 1. GENERAL IMPORTANT VARIABLES, DEFINITIONS AND STATES
typedef int KERN_BASE;
typedef double LLU;
typedef char CAR;
typedef enum {basicmode, absolutely_normal_panic, kern_panic} KERN_STATE;
typedef float _kernbus;
typedef long long absolutely_long;

KERN_BASE megalo = 0;
KERN_BASE taskerplus = 0;
CAR oturumsifrecisi[36] = "lestwoods2026";

// 2. MAIN SECTION
KERN_BASE main() { 
    cls(); // Function to clear the screen
    dost_init(); // Initializing the DOST system
    dost_crkla("madebybirturk"); // Directory created as a signature
    dost_crkla("lestwoods kern"); // A directory for users to explore
    cls();
    // splash screen sequence
    printm("Folders are being created.");
    gimme_a_sec();
    cls();
    printm("Folders are being created..");
    gimme_a_sec();
    cls();
    printm("Folders are being created...");
    gimme_a_sec();
    cls();
    gimme_a_sec();
    printm("Welcome to... \n");
    printm("LESTWOODS 0.01! \n");
    start_shell();


    // Critical part to prevent kernel instability.
    while (1)
    {
        // WE ADDED A COUNTER SO THE KERNEL CAN DO MULTITASK.
        esheduler_tick();
    }
}

// More functions will be added here;

// MADE IN TURKIYE
// MADE BY BIRTURK