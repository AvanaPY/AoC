
/* https://adventofcode.com/2022/day/5 */
/* gcc -o ./day5/a ./day5/main.c && ./day5/a  <- Change day here too*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int init_state_text_width = 0;
    
    const int MAX_STACKS   = 16;
    const int MAX_STACK_SZ = 64;
    
    char prnt_frmt_buf[MAX_STACK_SZ*2+6];
    for(int i = 0; i < MAX_STACK_SZ*2+5; i++)
        prnt_frmt_buf[i] = '-';
    prnt_frmt_buf[MAX_STACK_SZ*2+5] = '\n';

    int state_ptr = 0;
    char state[4096] = { ' ' }; /* Init a buffer of 4MB */
    char stack[MAX_STACK_SZ * MAX_STACKS];
    for(int i = 0; i < MAX_STACK_SZ * MAX_STACKS; i++)
        stack[i] = ' ';
    int stack_size[MAX_STACKS];
    for(int i = 0; i < MAX_STACKS; i++)
        stack_size[i] = 0;

    int hit_end_of_init = 0;
    int stacks_total = 0;
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
                        if(c != ' ')
                            stack_size[i]++;
                    }
                }
            }
            else 
            {
                while(c != '\n')
                {
                    state[state_ptr++] = c;
                    c = fgetc(f);
                }
                state_ptr++;
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
            state_ptr = 0;
            int vals[3];
            int c_val = 0;
            do
            {
                c = fgetc(f);
                if(c == ' ' || c == '\n' || c == EOF)
                {
                    if(state_ptr > 0)
                    {
                        state[state_ptr] = '\0';
                        vals[c_val] = atoi(state);
                        state_ptr = 0;
                        c_val++;
                        if(c == '\n'){
                            c_val = 0;
                            break;
                        }
                    }
                }
                else if(('0' <= c && c <= '9'))
                    state[state_ptr++] = c;
            } while(c != EOF);
            state[state_ptr] = '\0';

            /* Debuging takes too long */
            for(int i = 0; i < vals[0]; i++)
            {
                int from = vals[1] - 1;
                int targ = vals[2] - 1;

                if(stack_size[from] == 0)
                    break;

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

    // printf("Stack state:\n%s", prnt_frmt_buf);
    // for(int i = 0; i < init_state_stack_sz; i++)
    // {
    //     printf("|%d: ", i + 1);
    //     for(int j = 0; j < MAX_STACK_SZ; j++)
    //     {
    //         printf("%c ", stack[i * MAX_STACK_SZ + j]);
    //     }
    //     printf("| (%d)\n", stack_size[i]);
    // }
    // printf("%s", prnt_frmt_buf);
    /* and here */
    
    printf("Answer 1: ");
    for(int i = 0; i < stacks_total; i++)
        printf("%c", stack[i * MAX_STACK_SZ + stack_size[i] - 1]);
    printf("\n");
    printf("Answer 2: %d\n", ans2);
    fclose(f);
    return 0;
}