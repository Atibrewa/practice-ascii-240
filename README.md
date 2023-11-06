# Manipulation ASCII Strings

**NAMES FOR CODE FILES:** 

	change_case.c
	test.c

**NAME FOR CODE EXECUTABLE:** 

	change_case

### ASCII character manipulation to change case

In an alphabetic ascii character, the third bit from the left is the *case-shift bit*. This bit is zero for upper case letters and 1 for lower case letters. Except for this bit, the code of an uppercase letter is the same as its lowercase counterpart.

#### Your Task
You will write functions that contain a bitmask variable for the case-shift bit. Write three functions, each of which takes an original string and a string that will be filled with a new version of the string. The definition and signature of the three functions are as follows:

	/*
	 * Toggles the case of every alphabetic character in the string,
	 * keeping non-alpha characters intact.
	 */
	void toggle_case(char *s, char *newstr)

	/*
	 * Lowers the case of every alphabetic character in the string,
	 * keeping non-alpha characters intact.
	 */
	void lower_case(char *s, char *newstr)


	/*
	 * Raises the case of every alphabetic character in the string,
	 * keeping non-alpha characters intact.
	 */
	void upper_case(char *s, char *newstr)

The basic framework for each of these is a for loop that will handle each character in the string `s` and place it into the string `newstr`. You may want to start by getting this loop working by simply printing back each character. Note that once you have the loop working over each character, then you can use your mask and operator on each character to create a new character to print out.

Write several test cases in your test.c file that demonstrate the functions working correctly. Be thorough.

**Sample output for one test case**

	original    : C string 1$
	toggle case : c STRING 1$
	upper case  : C STRING 1$
	lower case  : c string 1$


**RULES**

- You *cannot* use the functions `tolower()` or `toupper()` from `<ctype.h>`. You are in essence exploring how these are written by doing the bitwise operation with a mask yourself. You can use other functions in `<ctype.h>` (hint: isalpha() is useful).

- Your functions should do nothing to characters that are not alphabetic.

#### Grading
You will be graded on:

- Code compiles and runs
- Code documented and written as described in Homework Expectations
- Each function works
- Each function uses a bitwise operator to change the character
- Followed rules given above
- Thoroughness of test cases
