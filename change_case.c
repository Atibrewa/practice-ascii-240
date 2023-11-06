/*
 * Aahanaa (Atibrewa)
 * Contains functions to toggle case, lower case or upper case 
 * all characters in a string without changing the non-alphabetic characters.
 * Also contains helper functions to achieve this
 */

#include <stdio.h>
#include <string.h> // useful string operations
#include <ctype.h>  //useful character operations

/*
 * Purely for an example of looping through a string.
 * Use as a guide- you will need to do more in the functions below.
 */
void print_str(char *s) {
  	/* loop over a string using subscript*/
		int i;
    for(i = 0; i < strlen(s); i++) {
        printf("%c",s[i]);
    }
  	printf("\n");
}

/*
 * Useful helper function to build up a string by adding a char
 * to the end. Found on: https://ubuntuforums.org/showthread.php?t=1016188
 */
void append(char* s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

/*
 * Toggles the case of every alphabetic character in the string,
 * keeping non-alpha charaters intact.
 */
void toggle_case(char *s, char *newstr) {
	strcpy(newstr, ""); // initialize
    unsigned char mask = 32; // We need a one in the third bit from the left which is 2^5 = 32

    int i;
    for(i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) {
            char c = s[i] ^ mask;   // XOR flips the bit whereever we have a 1 in our mask
            append(newstr, c);
        } else {
            append(newstr, s[i]);   // If the char is non alphabetic, just adds it without masking
        }
    }
}

/*
 * Lowers the case of every alphabetic character in the string,
 * keeping non-alpha charaters intact.
 */
void lowerCase(char *s, char *newstr) {
	strcpy(newstr, ""); // initialize
    unsigned char mask = 32; // We need a one in the third bit from the left which is 2^5 = 32

    int i;
    for(i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) {
            char c = s[i] | mask;   // OR sets the third bit from left to 1 every time
            append(newstr, c);
        } else {
            append(newstr, s[i]);   // If the char is non alphabetic, just adds it without masking
        }
    }
}

/*
 * Raises the case of every alphabetic character in the string,
 * keeping non-alpha charaters intact.
 */
void upperCase(char *s, char *newstr) {
  	strcpy(newstr, ""); // initialize
    unsigned char mask = 32; // We need a one in the third bit from the left which is 2^5 = 32

    int i;
    for(i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) {
            char c = s[i] & ~mask;  // AND sets the third bit from left to 0 every time because mask has 0 in that position
            append(newstr, c);
        } else {
            append(newstr, s[i]);   // If the char is non alphabetic, just adds it without masking
        }
    }
}
