#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)
#define LETTERS 26
#define NUMBERS 10
#define ROW rowFile
#define ROWLENGTH 150
#define USERSTR str
#define USERSTRLENGTH 100

typedef struct   //this struct contain the chars A-Z
{
    char* morse;
    char* ascii;
} morse_st_ascii;

typedef struct   //this struct contain the chars 0-9
{
    char* morse;
    char* ascii_numbers;
} morse_st_numbers;

/*
    This function loads a text file , translates it to morse and prints it on the screen
*/
int load_text_and_print_cmf();

int print_txt_to_morse();
/*
    This function gets a text file , translates it ,and saves it as a morse code file

*/
void load_text_and_save_cmf();

int save_txt_to_morse();


/*
    This function get text input , translates it to morse and prints it on the screen
*/
void translate_text_and_print_cmf();

int print_input_to_morse();