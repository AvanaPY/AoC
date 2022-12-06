
/* https://adventofcode.com/2022 */
/* gcc -o ./a ./main.c && ./a */
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

char c;
int ans1=0, 
    ans2=0;
FILE* f;

int main(void)
{   
    f = open_data();
    if(f == NULL){
        printf("Could not open the input file.\n");
        exit(1);
    }
    if(solved() != 0)
        printf("Failed to solve");

    print_ans_int(ans1, ans2);
    fclose(f);
    return 0;
}

int solve(void)
{
    /* Write code between here */
    do
    {
        
    } while ((c = fgetc(f)) != EOF);

    /* and here */
    return 0;
}