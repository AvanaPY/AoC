#pragma once
#include <stdio.h>
#include <stdlib.h>

FILE* open_data()
{
    return fopen("./data.txt", "r");
}