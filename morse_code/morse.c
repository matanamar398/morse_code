#include "morse.h"
#include "str_cut.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)


int load_text_and_print_cmf(char file_name[], morse_st_ascii* letters, morse_st_ascii* numbers)
{
    int res;
    char ROW[ROWLENGTH];
    int i = 0;
    FILE* f1 = check_file_name_txt(file_name);
    if (!(f1))
        return 0;
    if ((res = check_text_input(f1)) == 0) //checks if the file data is ok
        return 0;
    fseek(f1, 0, SEEK_SET); //returns the pointer to the start
    while (!(feof(f1)))
    {
        fgets(ROW, ROWLENGTH, f1);    //take 1 row
        while (ROW[i] != '\0')
        {
            if (ROW[i] == '\n') {
                ROW[i] = '\0';
                i++;
                break;
            }
            if (ROW[i] == ' ')
            {
                printf("       ");
                i++;
            }
            print_txt_to_morse(ROW[i], letters, numbers); //prints the char in morse code 
            str_cut(&ROW, 0, 1); //cuts 1 char from the beginning of the string
        }
        printf("\n");
        i = 0;
    }
}

int print_txt_to_morse(char ch, morse_st_ascii* letters, morse_st_ascii* numbers)
{   
    char* c;
    c = &ch;
    morse_st_ascii* letters_tmp = letters; ///to start all iteration from begin 
    morse_st_numbers* numbers_tmp = numbers;
    int flag = 0;
    int l, n;
    for (l = 0; l < LETTERS; l++)
    {
        if (*c == *letters_tmp->ascii)
        {
            printf("%s", letters_tmp->morse);
            printf("   ");
            flag = 1;
            return flag;
            
        }
        else
        {
            letters_tmp++;
        }
    }
    if (flag == 0)
    {
        for (n = 0; n < NUMBERS; n++)
        {
            if (*c == *numbers_tmp->ascii_numbers)
            {
                printf("%s", numbers_tmp->morse);
                printf("   ");
                flag = 1;
                return flag;
            }
            else
            {
                numbers_tmp++;
            }
        }
    }
        return 0;
}



void load_text_and_save_cmf(char file_name[],char newfile_name[], morse_st_ascii* letters, morse_st_ascii* numbers)
{
    int res;
    char location[100] = "C:\\targil\\";
    strcat(location, newfile_name);
    strcat(location, ".cmf");
    FILE* save_t_to_m = fopen(location, "w");
    if (!(save_t_to_m))
    {
        printf("couldnt open the file!!\n");
        return;
    }
    FILE* f1;
    f1 = check_file_name_txt(file_name);
    if (!(f1))
        return 0;
    if ((res = check_text_input(f1)) == 0) //checks if data in the text file is valid
        return 0;
    fseek(f1, 0, SEEK_SET); //returns the pointer to the start of the string
    char ROW[ROWLENGTH];
    int i = 0;
    while (!(feof(f1)))
    {
        fgets(ROW, ROWLENGTH, f1);    //take 1 row
        while (ROW[i] != '\0')
        {
            while (ROW[i] == ' ')
            {
                fprintf(save_t_to_m, "%s","       "); //adds 7 space when it meets a space between words or letter
                i++;
            }
            save_txt_to_morse(save_t_to_m, ROW[i], letters, numbers); //searchs the ascii char and puts it as a morse code to the cmf file
            str_cut(&ROW, 0, 1); //cuts 1 char frfom the string
        }
        printf("\n");
        i = 0;
        fprintf(save_t_to_m, "%c", '\n');//if the text file contain several rows it outs new line to the cmf file
    }
    printf("cmf file Saved!!\n");
    fclose(save_t_to_m);
}

int save_txt_to_morse(FILE* file, char ch, morse_st_ascii* letters, morse_st_ascii* numbers) 
{
    char* c;
    c = &ch;
    morse_st_ascii* letters_tmp = letters; ///to start all iteration from begin 
    morse_st_numbers* numbers_tmp = numbers;
    int flag = 0;
    int l, n;
    for (l = 0; l < LETTERS; l++)
    {
        if (*c == *letters_tmp->ascii)
        {
            fprintf(file, "%s", letters_tmp->morse);
            fprintf(file, "%s", "   ");
            return 1;
        }
        else
        {
            letters_tmp++;
        }
    }
    if (flag == 0)
    {
        for (n = 0; n < NUMBERS; n++)
        {
            if (*c == *numbers_tmp->ascii_numbers)
            {
                fprintf(file, "%s", numbers_tmp->morse);
                fprintf(file, "%s", "   ");
                return 1;
            }
            else
            {
                numbers_tmp++;
            }
        }
    }
    return 0;
}




void translate_text_and_print_cmf(morse_st_ascii* letters, morse_st_ascii* numbers)
{
    int i = 0, n;
    char USERSTR[USERSTRLENGTH];
    int ch;
    int res;
    printf("Enter a text:\n");
    //while ((ch = getchar()) != '\n' && ch != EOF); //clears the buffer
    if (USERSTR[i] == '\n')
    {
        fgets(USERSTR,USERSTRLENGTH, stdin);
    }
    fgets(USERSTR, USERSTRLENGTH, stdin); //gets input from the user until the user press enter aka '\n'
    for (i; i < strlen(USERSTR); i++)
    {
        if (USERSTR[i + 1] == '\n')
            USERSTR[i + 1] = '\0';
    }
    if ((res = check_text_input_user(str)) == 0) //checks if the input is valid
    {
        return 0;
    }
    i = 0;
    while (USERSTR[i] != '\0')
    {
        while (USERSTR[i] == ' ') //puts 7 spaces when it meets a sapce
        {
            printf("       ");
            i++;
        }
        print_input_to_morse(USERSTR[i], letters, numbers); //prints the ascii char as a morse code
        i++;
    }
    printf("\n");
}

int print_input_to_morse(char ch, morse_st_ascii* letters, morse_st_ascii* numbers)
{
    char* c;
    c = &ch;
    morse_st_ascii* letters_tmp = letters; ///to start all iteration from begin 
    morse_st_numbers* numbers_tmp = numbers;
    int flag = 0;
    int l, n;
    for (l = 0; l < LETTERS; l++)
    {
        if (*c == *letters_tmp->ascii)
        {
            printf("%s", letters_tmp->morse);
            printf("   ");
            return 1;
        }
        else
        {
            letters_tmp++;
        }
    }
    if (flag == 0)
    {
        for (n = 0; n < NUMBERS; n++)
        {
            if (*c == *numbers_tmp->ascii_numbers)
            {
                printf("%s", numbers_tmp->morse);
                printf("   ");
                return 1;
            }
            else
            {
                numbers_tmp++;
            }
        }
    }
    
}