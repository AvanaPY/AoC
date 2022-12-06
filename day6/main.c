
/* https://adventofcode.com/2022/day/ */
/* gcc -o ./a ./main.c && ./a */
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#define CHAR_COUNT 15
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
    int p = 0, i = 0, buf_count = 0;
    int cont[2] = { 1, 1 };
    char buf[CHAR_COUNT] = { '\0' };

    while((cont[0] == 1 || cont[1] == 1) && (c = fgetc(f)) != EOF)
    {
        i++;
        buf[buf_count] = c;
        buf_count = (buf_count + 1) % (CHAR_COUNT - 1);

        p = 0;
        if(cont[0] == 1){
            ans1++;
            if(i >= 4)
            {
                cont[0] = 0;
                int start = buf_count - 4;
                if(start < 0)
                    start += CHAR_COUNT - 1;

                for(int i = start; i != buf_count; i = (i + 1) % (CHAR_COUNT - 1))
                {
                    if((p & 1 << (buf[i] - 'a')) > 0)
                        cont[0] = 1;
                    else
                        p |= 1 << (buf[i] - 'a');
                }
            }
        }
        p = 0;
        if(cont[1] == 1)
        {
            ans2++;
            if(i >= 15)
            {
                cont[1] = 0;
                for(int i = 0; i < CHAR_COUNT - 1; i++)
                {
                    if((p & 1 << (buf[i] - 'a')) > 0)
                        cont[1] = 1;
                    else
                        p |= 1 << (buf[i] - 'a');
                }
            }
        }
    }
    /* and here */

    print_ans_int(ans1, ans2);
    fclose(f);
    return 0;
}