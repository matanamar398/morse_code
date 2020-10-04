#include "text.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "morse.h"
#include "str_cut.h"
#pragma warning (disable:4996)


void load_cmf_and_print_text(char name[], morse_st_ascii* letters, morse_st_ascii* numbers)
{
    int flag = 1;
    int b = 0;
    int count_sp = 0;
    char ROW[ROWLENGTH];
    char temp_word[100];
    int i = 0;
    int res;
    FILE*f1=check_file_name_cmf(name);
    if (!(f1))
        return 0;
    res = check_input(f1); //checks if the file is empty
    if (res == 0)
        return 0;
    fseek(f1, 0, SEEK_SET); //brings the pointer to the beginning of the file
     while (!(feof(f1)))
     {
         fgets(ROW, ROWLENGTH, f1); //gets a row from the file and puts in the rowFile string
         while (ROW[i] != '\0')// interates untill the row ends
         {
             while (ROW[i] != ' ' || ROW[i + 1] != ' ' || ROW[i + 2] != ' ')
             {
                 if (ROW[i] == '\n') //if the last char of the row is '\n' we turns it to '\0'
                 {
                     ROW[i] = '\0';
                     i++;
                     break; //breaks from the loop
                 }
                 if (ROW[i] == '\0')
                 {
                     break;
                 }
                 i++;
             }
             memset(temp_word, '\0', sizeof(temp_word));  //resets the array
             strncpy(temp_word, ROW, i);// copies i bytes from rowFile to temp_word
          res = print_morse_to_txt(temp_word, letters, numbers); //checks if temp_word contain a valid morse code
          if (res == 0)
              return 0;
             count_sp = 0;
             while (ROW[i] == ' ') //counts the spaces
             {
                 count_sp++;
                 i++;
             }
             str_cut(&ROW, 0, i); //cuts rowFile untill after the spaces
             i = 0;
             if (count_sp == 7) {
                 printf(" ");
             }
         }
         printf("\n\n");
     }
}

 int print_morse_to_txt(char word[], morse_st_ascii* letters, morse_st_ascii* numbers)
{
    morse_st_ascii* letters_tmp = letters; ///to start all iteration from begin 
    morse_st_numbers* numbers_tmp = numbers;
    int flag = 0;
    int l, n;
    for (l = 0; l < LETTERS; l++)
    {
        if (strcmp(word, letters_tmp->morse) == 0)
        {
            printf("%c", *letters_tmp->ascii);
            flag = 1;
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
            if (strcmp(word, numbers_tmp->morse) == 0)
            {
                printf("%c", *numbers_tmp->ascii_numbers);
                flag = 1;
                return 1;
            }
            else
            {
                numbers_tmp++;
            }
        }
    }
        printf(" the input from file: %s\n", word);
        printf("this Morse code does not exist!!\n");
        return 0;
}



 int load_cmf_and_save_text(char name[],char newFileName[], morse_st_ascii* letters, morse_st_ascii* numbers)
 {
     int res;
     int count_sp = 0;
     char ROW[ROWLENGTH];
     char temp_word[100];
     int i = 0;
     int flag = 1;
     char location[100] = "C:\\targil\\";
     strcat(location, newFileName);
     strcat(location, ".txt");
     FILE* save_m_to_t = fopen(location, "w");
     FILE* f1 = check_file_name_cmf(name);
     if (!(f1))
         return 0;
     res = check_input(f1);
     if (res == 0)
         return 0;
     fseek(f1, 0, SEEK_SET); //returns the pointer to the start
     while (!(feof(f1)))
     {
         fgets(ROW, ROWLENGTH, f1);    //take 1 row
         while (ROW[i] != '\0')
         {
             while (ROW[i] != ' ' || ROW[i + 1] != ' ' || ROW[i + 2] != ' ')
             {
                 if (ROW[i] == '\n')
                 {
                     ROW[i] = '\0';
                     i++;
                     break;
                 }
                 if (ROW[i] == '\0')
                 {
                     break;
                 }
                 i++;
             }
             memset(temp_word, '\0', sizeof(temp_word));  //reset array
             strncpy(temp_word, ROW, i); //copy n bits
             res = save_morse_to_txt(save_m_to_t, temp_word, letters, numbers); //finds the morse code and saves its ascii value in the text file
             if (res == 0)
                 return 0;
             count_sp = 0;
             while (ROW[i] == ' ') //counts spaces
             {
                 count_sp++;
                 i++;
             }
             str_cut(&ROW, 0, i); //cuts i bits from rowFile from the start
             i = 0;
             if (count_sp == 7) //if there are 7 spaces we put 1 space in the text file  
             {
                 fprintf(save_m_to_t,"%c", ' ');
             }
         }
             fprintf(save_m_to_t, "%c", '\n');
     }
     fclose(save_m_to_t);
     printf("Text file Saved!!\n");
 }
   

int save_morse_to_txt(FILE* file_save, char word[], morse_st_ascii* letters, morse_st_ascii* numbers)
{
    morse_st_ascii* letters_tmp = letters; ///to start all iteration from begin 
    morse_st_numbers* numbers_tmp = numbers;
    int flag = 0;
    int l, n;
    for (l = 0; l < LETTERS; l++)
    {
        if (strcmp(word, letters_tmp->morse) == 0)
        {
            fprintf(file_save, "%s", letters_tmp->ascii);
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
            if (strcmp(word, numbers_tmp->morse) == 0)
            {
                fprintf(file_save, "%s", numbers_tmp->ascii_numbers);
                flag = 1;
                return 1;
            }
            else
            {
                numbers_tmp++;
            }
        }
    }
    printf(" the input from file: %s\n", word);
    printf("this Morse code does not exist!!\n");
    return 0;
}


void translate_cmf_and_print_text(morse_st_ascii* letters, morse_st_ascii* numbers)
{
    int res;
    int flag = 1;
    int b = 0;
    int i = 0;
    char str[100];
    char tmp[100];
    int ch;
    int space_count = 0;
    printf("Enter a morse code:\n");
    //while ((ch = getchar()) != '\n' && ch != EOF); //clears buffer
    if (str[i] == '\n')
    {
        fgets(str, sizeof(str), stdin);
    }
    fgets(str, sizeof(str), stdin); //gets morse code from the user until he press enter aka '\n'
    res = check_morse_input_from_user(str); // checks input validation
    if (res == 0)
        return 0;
    while (str[i] != '\0')
    {
        while (str[i] != ' ' ||str[i + 1] != ' ' || str[i + 2] != ' ')
        {
            if (str[i] == '\n')
            {
                str[i] = '\0';
                i++;
                break;
            }
            if (str[i] == '\0')
            {
                break;
            }
            i++;
        }
        memset(tmp, '\0', sizeof(tmp));  //reset array
        strncpy(tmp, str, i); //copies i chars from str to tmp
        res=print_morse_to_txt(tmp, letters, numbers); //prints morse letter as ascii chars
        if (res == 0)
            return 0;
        space_count = 0;
        while (str[i] == ' ')
        {
            space_count++;
            i++;
        }
        str_cut(&str, 0, i); //cuts i chars from str from the start
        i = 0;
        if (space_count == 7) {
            printf(" ");
        }
    }
    printf("\n");
}


int print_format_name(char file_name[])
{
    char name1[100] = "C:\\targil\\";
    char name2[100] = "C:\\targil\\";
    strcat(name1, file_name);
    strcat(name2, file_name);
    strcat(name1, ".txt");
    strcat(name2, ".cmf");
    FILE* txtfile = fopen(name1, "r+");
    if (txtfile)
    {
        printf("File extension: txt\n");
        fclose(txtfile);
        return;
    }
    FILE* cmffile = fopen(name2, "r+");
    if(cmffile)
    {
        if(cmffile)
        printf("File extension: cmf\n");
        fclose(cmffile);
        return;
    }
    else
    {
        printf("File does not exist or invalid extension!!\n");
        return;
    }
}