#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LETTERS 26
#define NUMBERS 10
#define TXTEXT "txt"
#define CMFEXT "cmf"
#define ROW rowFile
#define ROWLENGTH 150
#pragma warning (disable:4996)

/*
    This function loads a morse code, translate it to ascii and prints it on the screen
*/

void load_cmf_and_print_text();

int print_morse_to_txt();



/*
    This function gets a cmffile , translates it ,and saves it as a text file
*/

int load_cmf_and_save_text();

int save_morse_to_txt();



/*
This function gets input from the user,translates it to ascii charecters ,and prints the ascii value
*/


void translate_cmf_and_print_text();

/*
this function recives a file name and returns the file type
*/

int print_format_name();