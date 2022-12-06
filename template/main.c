
/* https://adventofcode.com/2022/day/ */
/* gcc -o ./dayX/a ./dayX/main.c && ./dayX/a  <- Change day here too*/
#include <stdio.h>
#include <stdlib.h>

FILE* open_data()
{
    /* Remember to change day */
    return fopen("./day1/data.txt", "r");
}

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

    printf("Answer 1: %d\n", ans1);
    printf("Answer 2: %d\n", ans2);
    fclose(f);
    return 0;
}