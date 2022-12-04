#include <stdio.h>
#include <stdlib.h>

FILE* open_data()
{
    return fopen("./day1/data.txt", "r");
}

int main(void)
{
    char cb[10] = { '\n' }, c;
    int n, m, s, i, h[3] = { 0 };

    FILE* f = open_data();
    if(f == NULL){
        printf("Could not open file\n");
        exit(1);
    }

    m = 0;
    s = 0;
    i = 0;
    do {
        c = fgetc(f);
        if(c == '\n' || c == EOF)
        {
            if(i == 0)
            {
                if(m < s)
                    m = s;
                s = 0;
                if(h[0] < m)
                {
                    h[2] = h[1];
                    h[1] = h[0];
                    h[0] = m;
                }
                continue;
            }
            else
            {
                cb[i] = '\n';
                n = atoi(cb);
                s += n;
                i = 0;
            }
        }
        else
        {
            cb[i++] = c;
        }
        
    } while(c != EOF);

    int hs = h[0] + h[1] + h[2];
    printf("Answer 1: %d\n", m);
    printf("Answer 2: %d\n", hs);
    
    fclose(f);
    return 0;
}