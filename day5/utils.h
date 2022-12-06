#pragma once
#include <stdio.h>
#include <stdlib.h>

FILE* open_data()
{
    return fopen("./data.txt", "r");
}

void print_ans_string(char* ans1, char* ans2)
{
    printf("Answer 1: %s\nAnswer 2: %s\n", ans1, ans2);
}