
/* https://adventofcode.com/2022/day/ */
/* gcc -o ./a ./main.c && ./a */
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(void)
{   
    char c;
    int ans1 = 0, ans2 = 0;
    FILE* f = open_data();
    if(f == NULL){
        printf("Could not open file, make sure you changed the day in the open_data() function\n");
        exit(1);
    }
    
    /* Write code between here */
    do
    {
        /* code */
    } while ((c = fgetc(f)) != EOF);
    /* and here */

    print_ans_int(ans1, ans2);
    fclose(f);
    return 0;
}