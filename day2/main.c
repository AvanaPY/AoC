#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(void)
{   
    FILE* f = open_data();
    if(f == NULL){
        printf("Could not open file\n");
        exit(1);
    }
    
    char c, cb[2] = { ' ' };
    int zz[3] = { 2, 3, 1 };
    int ans1 = 0, ans2 = 0;
    while((c = fgetc(f)) != EOF)
    {
        cb[0] = c - 64;         fgetc(f);
        cb[1] = fgetc(f) - 87;  fgetc(f);

        if(cb[0] == cb[1])
            ans1 += 3 + cb[1];
        else if(cb[0] == ((cb[1] + 1) % 3 + 1))
            ans1 += 6 + cb[1];
        else 
            ans1 += cb[1];

        if(cb[1] == 1) 
            ans2 += (cb[0] + 1) % 3 + 1;
        else if(cb[1] == 2)
            ans2 += cb[0] + 3;
        else
            ans2 += zz[cb[0] - 1] + 6;   
    }

    print_ans_int(ans1, ans2);
    fclose(f);
    return 0;
}