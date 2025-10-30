#include <stdio.h>
#include <string.h>

int main() {
    /*
     * 🔹 Case 1: char array
     * - "name" is an array stored in stack memory.
     * - Its elements are mutable (you can modify characters).
     * - But the array name itself acts like a const pointer — it cannot point somewhere else.
     */
    char name[] = "Saurabh Singh is an engineer";
    printf("Original string: %s\n", name);

    name[2] = 'r';  // ✅ allowed — changing a character inside array
    // name++        // ❌ NOT allowed — 'name' behaves like a constant pointer
    // name = "Singh"; // ❌ NOT allowed — cannot assign a new string literal to array name

    /*
     * 🔹 strcpy example:
     * - Copies the content of one string into another.
     * - The destination (name) must be large enough.
     */
    char name2[] = "Singh Saab";
    printf("Before strcpy: name2 = %s, name = %s\n", name2, name);

    strcpy(name, name2);  // ✅ copies "Singh Saab" into name
    printf("After strcpy:  name2 = %s, name = %s\n", name2, name);


    /*
     * 🔹 Case 2: const char* (String literal)
     * - Points to a string literal stored in read-only memory.
     * - You CANNOT modify the literal (undefined behavior).
     * - You CAN change the pointer itself to point elsewhere.
     */
    const char *firstName = "saurabh";

    firstName = "singh";  // ✅ allowed — pointer now points to a new string literal
    firstName++;          // ✅ allowed — pointer arithmetic is fine
    // *firstName = 'k';  // ❌ NOT allowed — trying to modify read-only literal

    printf("Pointer now points to: %s\n", firstName);

    /*
     * ✅ Summary:
     * 1. char name[] = "text"; → stored in stack → mutable characters, fixed address.
     * 2. const char *p = "text"; → stored in read-only memory → immutable characters, pointer movable.
     * 3. strcpy(dest, src); → copies data (deep copy), not pointer.
     */

    char str1[] = "Hi";
    char str2[] = "Hi";
    printf("string comapre : %d\n", strcmp(str1, str2));

    return 0;
}
