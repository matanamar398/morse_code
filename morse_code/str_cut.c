#include "str_cut.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INLETTER_SPACE 1
#define BETWEEN_LETTERS 3
#define BETWEEN_WORDS 7
#define GOODCHARS 3
#pragma warning (disable:4996)


int check_validation(char to_split[])
{
    int sp = 0;
    int i;
    
    if (strlen(to_split) < 5)
        return 0;
    for (i = 0;i < strlen(to_split);i++) {
        if (to_split[i] == ' ')
            sp++;
    }
    if (strcmp(to_split, "quit\n") == 0)
        return 1;
    else if(strcmp(to_split, "translate_text_and_print_cmf\n") == 0 || strcmp(to_split, "translate_cmf_and_print_text\n") == 0)
        return 1;
    else if (sp > 0)
        return 1;
    else
        return 0;
}


FILE* check_file_name_txt(char file_name[])
{
    char name1[100] = "C:\\targil\\";
    strcat(name1, file_name);
    strcat(name1, ".txt");
    FILE* f = fopen(name1, "r+");
    if (!(f))
    {
        printf("couldnt open the file,or file not exist!!\n");
        return 0;
    }
    return f;
}

FILE* check_file_name_cmf(char file_name[])
{
    char name1[100] = "C:\\targil\\";
    strcat(name1, file_name);
    strcat(name1, ".cmf");
    FILE* f = fopen(name1, "r+");
    if (!(f))
    {
        printf("couldnt open the file,or file not exist!!\n");
        return 0;
    }
    return f;
}


int check_text_input(FILE* file) // check validation of input
{
    int flag = 1, size;
    int b = 0;
    char rowFile[150];
    if (NULL != file) { // check if file is empty
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        if (0 == size) {
            printf("file is empty\n");
            return 0;
        }
    }
    fseek(file, 0, SEEK_SET);
    while (!(feof(file))) // check if input is valid
    {
        fgets(rowFile, 150, file);    //take 1 row
        b = 0;
        flag = 0;
        while (rowFile[b] != '\0')
        {
            if (rowFile[b] == '\n')
                break;
            if (rowFile[b] >= 'A' && rowFile[b] <= 'Z' || rowFile[b] == ' ' || rowFile[b] >= '0' && rowFile[b] <= '9')
               
                flag = 1;
            else {
                flag=0;
            }
            b++;
        }
        if (flag == 0) {
            printf("The chars are not ok!\n");
            return 0;
        }
    }
    return 1;
}


int check_text_input_user(char str[]) // check validation of input
{
    int flag = 1, size;
    int b = 0;
    char rowFile[150];
        b = 0;
        flag = 0;
        while (str[b]!= '\0')
        {
            if (str[b] == '\n')
                break;
            if (str[b] >= 'A' && str[b] <= 'Z' || str[b] == ' ' || str[b] >= '0' && str[b] <= '9')
                flag = 1;
            else {
                flag = 0;
            }
            b++;
        }
        if (flag == 0) {
            printf("The chars are not ok!\n");
            return 0;
        }
    
        return 1;
}

int str_cut(char* str, int begin, int len)
{
    int l = strlen(str);

    if (len < 0) len = l - begin;
    if (begin + len > l) len = l - begin;
    memmove(str + begin, str + begin + len, l - len + 1);
    return len;
}


int check_input(FILE* file) // check validation of input
{
    correct_chars correct[] =
    {
        {'*'},
        {' '},
        {'-'}
    };
   int  s = 0;
    int count_sp = 0;
    int j,k;
    int flag = 1, size;
    int b = 0;
    char rowFile[150];
    if (NULL != file) { // check if file is empty
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        if (0 == size) {
            printf("file is empty\n");
            return 0;
        }
    }
    fseek(file, 0, SEEK_SET);
    while (!(feof(file))) // check if input is valid
    {
        fgets(rowFile, 150, file);    //take 1 row
        b = 0;
        flag = 1;
        while (rowFile[b] != '\0')
        {
            if (rowFile[b] == '\n')
                break;

            for (j = 0; j < GOODCHARS; j++)
            {   
                if (rowFile[b] == correct[j].letter) {
                    flag = 1;
                    break;
                }
                else {
                    flag = 0;
                }
            }
            if (flag == 0) {
                printf("Incorrect Chars!!\n");
                return flag;
            }
            else if (flag == 1)
            {
                if (rowFile[b] == ' ')
                {
                    
                    while (rowFile[b] == ' ')
                    {
                        count_sp++;

                        s = 1;
                        b++;
                    }
                    if (count_sp != BETWEEN_LETTERS && count_sp != BETWEEN_WORDS && count_sp != INLETTER_SPACE) {
                        flag = 0;
                        printf("worng spaces!!!!\n");
                        return flag;
                    }    
                }
            }
            if (s == 0) {
                b++;
            }
            s = 0;
            count_sp = 0;
        }
    }
}


int check_morse_input_from_user(char string[]) // check validation of input
{
    correct_chars correct[] =
    {
        {'*'},
        {' '},
        {'-'}
    };
    int  s = 0;
    int count_sp = 0;
    int j, k;
    int flag = 1, size;
    int b = 0;

    if (strlen(string) < 1) {
        printf("string is empty\n");
        return 0;
    }

    b = 0;
    flag = 1;
    while (string[b] != '\0')
    {
        if (string[b] == '\n')
            break;

        for (j = 0; j < GOODCHARS; j++)
        {
            if (string[b] == correct[j].letter) {
                flag = 1;
                break;
            }
            else {
                flag = 0;
            }
        }
        if (flag == 0) {
            printf("Incorrect Chars!!\n");
            return flag;
        }
        else if (flag == 1)
        {
            if (string[b] == ' ')
            {

                while (string[b] == ' ')
                {
                    count_sp++;

                    s = 1;
                    b++;
                }
                if (count_sp != BETWEEN_LETTERS && count_sp != BETWEEN_WORDS && count_sp != INLETTER_SPACE) {
                    flag = 0;
                    printf("worng spaces!!!!\n");
                    return flag;
                }
            }
        }
        if (s == 0) {
            b++;
        }
        s = 0;
        count_sp = 0;
    }
}