
/* https://adventofcode.com/2022/day/5 */
/* gcc -o ./day5/a ./day5/main.c && ./day5/a  <- Change day here too*/
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>

#define MAX_STACKS 16
#define MAX_STACK_SZ 64

int main(void)
{   
    char c;
    FILE* f = open_data();
    if(f == NULL){
        printf("Could not open file\n");
        exit(1);
    }
    /* Write code between here */

    /* Stack and state variables */
    int state_counter = 0;
    char state[4096] = { ' ' }; /* Init a buffer of 4MB */
    char stack[MAX_STACK_SZ * MAX_STACKS * 2] = { '\n' };
    int stack_size[MAX_STACKS] = { 0 };
    int stacks_total = 0;

    /* Reading state variables*/
    int ii, jj, bi, bj;
    int hit_end_of_init = 0;
    int init_state_text_width = 0;
    int init_state_stack_sz = 0;
    
    /* Execute instructions variables */
    int from, targ, from_idx, targ_idx, i;
    char b;

    do
    {
        c = fgetc(f);
        if(hit_end_of_init == 0)
        {
            if(c == '\n')
            {
                hit_end_of_init = 1;

                /* Transform read stack into our internal stack */
                for(ii = 0; ii < stacks_total; ii++)
                {
                    bj = 4 * ii + 1;
                    for(jj = 0; jj < init_state_stack_sz - 1; jj++)
                    {
                        bi = init_state_stack_sz - 2 - jj;
                        c = state[bi * (init_state_text_width + 1) + bj];
                        stack[ii * MAX_STACK_SZ + jj] = c;
                        stack[ii * MAX_STACK_SZ + jj + MAX_STACK_SZ * MAX_STACKS] = c;
                        if(c != ' ')
                            stack_size[ii]++;
                    }
                }
            }
            else 
            {
                while(c != '\n')
                {
                    state[state_counter++] = c;
                    c = fgetc(f);
                }
                state_counter++;
                init_state_stack_sz++;
                if(init_state_text_width == 0)
                {
                    init_state_text_width = strlen(state);
                    stacks_total = (init_state_text_width + 1) / 4;
                }
            }
        }
        else
        {
            state_counter = 0;
            int vals[3];
            int c_val = 0;
            do
            {
                c = fgetc(f);
                if(c == ' ' || c == '\n' || c == EOF)
                {
                    if(state_counter > 0)
                    {
                        state[state_counter] = '\0';
                        vals[c_val] = atoi(state);
                        state_counter = 0;
                        c_val++;
                        if(c == '\n'){
                            c_val = 0;
                            break;
                        }
                    }
                }
                else if(('0' <= c && c <= '9'))
                    state[state_counter++] = c;
            } while(c != EOF);
            
            /* Debuging takes too long */
            from = vals[1] - 1;
            targ = vals[2] - 1;
            if(stack_size[from] < vals[0])
                exit(1);
                
            for(i = 0; i < vals[0]; i++)
            {
                from_idx = from * MAX_STACK_SZ + (stack_size[from] - 1 - i) + MAX_STACK_SZ * MAX_STACKS;
                targ_idx = targ * MAX_STACK_SZ + (stack_size[targ] + (vals[0] - i) - 1) + MAX_STACK_SZ * MAX_STACKS;
                b = stack[from_idx];

                stack[targ_idx] = b;
                stack[from_idx] = ' ';
            }
            for(i = 0; i < vals[0]; i++)
            {
                from_idx = from * MAX_STACK_SZ + stack_size[from] - 1;
                targ_idx = targ * MAX_STACK_SZ + stack_size[targ];
                b = stack[from_idx];

                stack[targ_idx] = b;
                stack[from_idx] = ' ';
                stack_size[from]--;
                stack_size[targ]++;
            }
        }
        /* code */
    } while (c != EOF);
    
    printf("Answer 1: ");
    for(int i = 0; i < stacks_total; i++)
        printf("%c", stack[i * MAX_STACK_SZ + stack_size[i] - 1]);
    printf("\n");
    printf("Answer 2: ");
    for(int i = 0; i < stacks_total; i++)
        printf("%c", stack[i * MAX_STACK_SZ + MAX_STACK_SZ * MAX_STACKS + stack_size[i] - 1]);
    printf("\n");
    fclose(f);
    return 0;
}