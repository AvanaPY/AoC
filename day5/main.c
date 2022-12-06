
/* https://adventofcode.com/2022/day/5 */
/* gcc -o ./day5/a ./day5/main.c && ./day5/a  <- Change day here too*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACKS 16
#define MAX_STACK_SZ 64
FILE* open_data()
{
    return fopen("./day5/data.txt", "r");
}

int main(void)
{   
    char c;
    int ans1 = 0, ans2 = 0;
    FILE* f = open_data();
    if(f == NULL){
        printf("Could not open file\n");
        exit(1);
    }
    /* Write code between here */

    int state_counter = 0;
    char state[4096] = { ' ' }; /* Init a buffer of 4MB */
    char stack[MAX_STACK_SZ * MAX_STACKS] = { '\n' };
    char stack2[MAX_STACK_SZ * MAX_STACKS] = { '\n' };
    int stack_size[MAX_STACKS] = { 0 };
    int stacks_total = 0;

    int hit_end_of_init = 0;
    int init_state_text_width = 0;
    int init_state_stack_sz = 0;
    
    do
    {
        c = fgetc(f);
        if(hit_end_of_init == 0)
        {
            if(c == '\n')
            {
                hit_end_of_init = 1;

                /* Transform read stack into our internal stack */
                for(int i = 0; i < stacks_total; i++)
                {
                    int bj = 4 * i + 1;
                    for(int j = 0; j < init_state_stack_sz - 1; j++)
                    {
                        int bi = init_state_stack_sz - 2 - j;
                        c = state[bi * (init_state_text_width + 1) + bj];
                        stack[i * MAX_STACK_SZ + j] = c;
                        stack2[i * MAX_STACK_SZ + j] = c;
                        if(c != ' ')
                            stack_size[i]++;
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
            state[state_counter] = '\0';

            /* Debuging takes too long */
            int from = vals[1] - 1;
            int targ = vals[2] - 1;
            if(stack_size[from] < vals[0])
                exit(1);
                
            for(int i = 0; i < vals[0]; i++)
            {
                int from_idx = from * MAX_STACK_SZ + stack_size[from] - 1 - i;
                int targ_idx = targ * MAX_STACK_SZ + stack_size[targ] + (vals[0] - i) - 1;
                char b = stack2[from_idx];
                stack2[targ_idx] = b;
                stack2[from_idx] = ' ';
            }
            for(int i = 0; i < vals[0]; i++)
            {
                int from_idx = from * MAX_STACK_SZ + stack_size[from] - 1;
                int targ_idx = targ * MAX_STACK_SZ + stack_size[targ];
                char b = stack[from_idx];
                stack[targ_idx] = b;
                stack[from_idx] = ' ';
                stack_size[from]--;
                stack_size[targ]++;
            }
        }
        /* code */
    } while (c != EOF);
    /* and here */
    
    printf("Answer 1: ");
    for(int i = 0; i < stacks_total; i++)
        printf("%c", stack[i * MAX_STACK_SZ + stack_size[i] - 1]);
    printf("\n");
    printf("Answer 2: ");
    for(int i = 0; i < stacks_total; i++)
        printf("%c", stack2[i * MAX_STACK_SZ + stack_size[i] - 1]);
    printf("\n");
    fclose(f);
    return 0;
}