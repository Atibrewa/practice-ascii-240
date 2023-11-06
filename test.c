/*
 * Aahanaa (Atibrewa)
 * Test file containing throrough tests of the functions in 
 * change_case.c using asserts.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

// included functions from change_case.c
void toggle_case(char *s, char *newstr);
void upperCase(char *s, char *newstr);
void lowerCase(char *s, char *newstr);

/*
 * Tests the functions in change_case.c
 */
int main() {

    // Set-up for running tests! We can use the same new string for all runs
    char *new;
    
    // Basic test for a string with mixed case, numericals and special characters
    char *s = "hELlo90;";
    lowerCase(s, new);
    assert(0 == strcmp(new, "hello90;"));
    upperCase(s, new);
    assert(0 == strcmp(new, "HELLO90;"));
    toggle_case(s, new);
    assert(0 == strcmp(new, "HelLO90;"));

    // All alphabets
    char *all_lower = "abcdefghijklmnopqrstuvwxyz";
    char *all_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *all_mixed = "abcdefghijklMNOPQRSTUVWxyz";

    // Checking all functions on lowercase characters
    lowerCase(all_lower, new);
    assert(0 == strcmp(new, all_lower));
    upperCase(all_lower, new);
    assert(0 == strcmp(new, all_upper));
    toggle_case(all_lower, new);
    assert(0 == strcmp(new, all_upper));

    // Checking all functions on uppercase characters
    lowerCase(all_upper, new);
    assert(0 == strcmp(new, all_lower));
    upperCase(all_upper, new);
    assert(0 == strcmp(new, all_upper));
    toggle_case(all_upper, new);
    assert(0 == strcmp(new, all_lower));

    // Checking all functions on mixed case characters
    lowerCase(all_mixed, new);
    assert(0 == strcmp(new, all_lower));
    upperCase(all_mixed, new);
    assert(0 == strcmp(new, all_upper));
    toggle_case(all_mixed, new);
    assert(0 == strcmp(new, "ABCDEFGHIJKLmnopqrstuvwXYZ"));

    // No alphabets, only special chars and all numericals
    char *no_alpha = "!@ #$/\"\\^& *()1234 5678 90";
    lowerCase(no_alpha, new);
    assert(0 == strcmp(new, no_alpha));
    upperCase(no_alpha, new);
    assert(0 == strcmp(new, no_alpha));
    toggle_case(no_alpha, new);
    assert(0 == strcmp(new, no_alpha));

    // Newline charcters inside string
    char *newline_char = "woo\nwoo";
    lowerCase(newline_char, new);
    assert(0 == strcmp(new, newline_char));
    upperCase(newline_char, new);
    assert(0 == strcmp(new, "WOO\nWOO"));
    toggle_case(newline_char, new);
    assert(0 == strcmp(new, "WOO\nWOO"));
    
    // Edges of ranges (one beneath and one above alphabets): @, A, Z, [, ', a, z, {
    char *edges = "@AZ[ 'az{";
    lowerCase(edges, new);
    assert(0 == strcmp(new, "@az[ 'az{"));
    upperCase(edges, new);
    assert(0 == strcmp(new, "@AZ[ 'AZ{"));
    toggle_case(edges, new);
    assert(0 == strcmp(new, "@az[ 'AZ{"));

    // Very short strings
    char *short_str = "aB";
    lowerCase(short_str, new);
    assert(0 == strcmp(new, "ab"));
    upperCase(short_str, new);
    assert(0 == strcmp(new, "AB"));
    toggle_case(short_str, new);
    assert(0 == strcmp(new, "Ab"));

    // String with length 1
    char *single_char = "a";
    lowerCase(single_char, new);
    assert(0 == strcmp(new, "a"));
    upperCase(single_char, new);
    assert(0 == strcmp(new, "A"));
    toggle_case(single_char, new);
    assert(0 == strcmp(new, "A"));

    // Empty string
    char *empty = "";
    lowerCase(empty, new);
    assert(0 == strcmp(new, empty));
    upperCase(empty, new);
    assert(0 == strcmp(new, empty));
    toggle_case(empty, new);
    assert(0 == strcmp(new, empty));

    // Early Null character /0 (which ends strings)
    char *early_n = "ABCdef\0ghijkl";
    lowerCase(early_n, new);
    assert(0 == strcmp(new, "abcdef"));
    upperCase(early_n, new);
    assert(0 == strcmp(new, "ABCDEF"));
    toggle_case(early_n, new);
    assert(0 == strcmp(new, "abcDEF"));
    // This case is interesting - C stops at the null character because it indicates the end of strings
    // so it only reads the string a far as the null, and changes case that far

    return 0;
}
