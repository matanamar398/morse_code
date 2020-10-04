
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROW rowFile
#define ROWLENGTH 150
#pragma warning (disable:4996)
typedef struct
{
    char letter;

} correct_chars;

int check_validation();

/*
This two functions gets a File name and check File name and File extension.
*/
FILE* check_file_name_txt();

FILE* check_file_name_cmf();

/*
This Four functions validates the user input or from file input
*/

int check_text_input();

int check_text_input_user();

int check_morse_input_from_user();

int check_input();

/*
This function gets a string ,len,and a string seperation index
*/
//int str_cut();

