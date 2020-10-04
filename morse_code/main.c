#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "morse.h"
#include "text.h"
#include "str_cut.h"
#pragma warning (disable:4996)
#define LETTERS 26
#define NUMBERS 10
#define CASE1 "load_cmf_and_print_text"
#define CASE2 "load_cmf_and_save_text"
#define CASE3 "load_text_and_print_cmf"
#define CASE4 "load_text_and_save_cmf"
#define CASE5 "translate_text_and_print_cmf"
#define CASE6 "translate_cmf_and_print_text"
#define CASE7 "print_format_name"
#define CASE8 "quit"
#define QUITLEN 5
#define NO "no"
#define YES "yes"
#define LOCATION "C:\\Users\\admin>"
void main()
{
    
    char to_split[100];
    char choose[100];
    char file_name[100];
    char new_file[100];
    int  res = 0;
    int i = 0,k;
    int len = 0;
    memset(choose, '\0', sizeof(choose));  
    memset(file_name, '\0', sizeof(file_name));  
    memset(new_file, '\0', sizeof(new_file));  
    morse_st_ascii letters[] = { {"* ---", "A"},
                              {"--- * * *", "B"},
                              {"--- * --- *", "C"},
                                {"--- * *","D"},
                                {"*","E"},
                                {"* * --- *", "F"},
                                {"--- --- *","G"},
                                {"* * * *","H"},
                                {"* *","I"},
                                {"* --- --- ---","J"},
                                {"--- * ---", "K"},
                                {"* --- * *","L"},
                                {"--- ---","M"},
                                {"--- *","N"},
                                {"--- --- ---","O"},
                                {"* --- --- *","P"},
                                {"--- --- * ---","Q"},
                                {"* --- *","R"},
                                {"* * *","S"},
                                {"---","T"},
                                {"* * ---","U"},
                                {"* * * ---","V"},
                                {"* --- ---","W"},
                                {"--- * * ---","X"},
                                {"--- * --- ---","Y"},
                                {"--- --- * *","Z"}
    };
    morse_st_numbers numbers[] =
    {
        {"--- --- --- --- ---", "0"},
        {"* --- --- --- ---", "1"},
        {"* * --- --- ---", "2"},
        {"* * * --- ---", "3"},
        {"* * * * ---", "4"},
        {"* * * * *", "5"},
        {"--- * * * *", "6"},
        {"--- --- * * *", "7"},
        {"--- --- --- * *", "8"},
        {"--- --- --- --- *", "9"}
    };
    do {
        do{
            printf(LOCATION);
            fgets(to_split, sizeof(to_split), stdin); //gets morse code from the user until he press enter aka '\n' 
            if (to_split[i] == '\n')
            {
                fgets(to_split, sizeof(to_split), stdin);
            }
            res = check_validation(to_split);
            if (res == 0) {
                printf("Enter a valid input\n");
            }
        } while (res==0);
        i = 0;
        res = 0;
        len = strlen(to_split);
        memset(choose, '\0', sizeof(choose));
        memset(file_name, '\0', sizeof(file_name));
        memset(new_file, '\0', sizeof(new_file));
        while (to_split[i] != '\0' && len > QUITLEN && (strcmp(to_split, "translate_text_and_print_cmf\n")) && (strcmp(to_split, "translate_cmf_and_print_text\n"))) //iterates untill the end of the line
        {
            i++;
            if (to_split[i] == ' '|| to_split[i] == '\n') // iterates untill it meets a space or new line '\n'
            {   
                if (res == 0) {
                    strncpy(choose, to_split, i);// copies i bytes from rowFile to temp   
                    res++;
                    while (to_split[i] == ' ')
                        i++;
                }
                if (res == 1 && to_split[i] == ' '|| to_split[i] =='\n')
                {
                    strncpy(file_name, to_split, i);                 
                    res++;    
                    if (to_split[i] == '\n') 
                    {
                        res--;
                        break;
                    }
                        i++;
                }
                if (res == 2) {
                    str_cut(to_split, 0, i);
                    i = 0;    
                    strcpy(new_file, to_split);
                    for (k = 0; k < strlen(new_file); k++) {
                        if (new_file[k] == '\n')
                           new_file[k] = '\0';
                    }
                    break;
                }
                str_cut(to_split, 0, i); 
                i = 0;
            }
        }
        if (res == 0)
        {
            strcpy(choose, to_split);
            for (k = 0; k < strlen(choose); k++)
                if (choose[k] == '\n')
                    choose[k] = '\0';
        }
        
           if (res == 1) { //two para
           if (strcmp(choose, CASE1) == 0)
           {
               load_cmf_and_print_text(file_name, &letters, &numbers);
           }

           else if (strcmp(choose, CASE3) == 0)
           {
               load_text_and_print_cmf(file_name, &letters, &numbers);
           }
           else if (strcmp(choose, CASE7) == 0)
               print_format_name(file_name);
           } 
          else if (res == 2)
          {
              if (strcmp(choose, CASE2) == 0)
              {
                  load_cmf_and_save_text(file_name, new_file, &letters, &numbers);
              }
              else if (strcmp(choose, CASE4) == 0)
              {
                  load_text_and_save_cmf(file_name, new_file, &letters, &numbers);
              }
          }
            else if (res == 0)
             {
                 if (strcmp(choose, CASE8) == 0)
                     return 0;
                 else if (strcmp(choose, CASE5) == 0)
                 {
                     translate_text_and_print_cmf(&letters, &numbers);
                 }

                 else if (strcmp(choose, CASE6) == 0)
                 {
                     translate_cmf_and_print_text(&letters, &numbers);
                 }
             }
            else {
            printf("%s is not recognized as an internal or external command,operable program or batch file.\n", choose);
            }
            printf("\n");
            printf("Do you want to quit?\nEnter yes or no\n");
            scanf("%s", choose);
            if (strcmp(choose, YES) == 0)
            {
                return 0;
            }
            else if (strcmp(choose, NO) == 0)
            {
                printf("Enter another command:\n");
            }
    } while (choose != CASE8);
}