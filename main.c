/*
*Programm welches nach Eingabe des aktuellen Datums berechnet, der wievielte Tag in diesem Jahr es ist.
*Autor: Mohamed Alaeddine
*Datum: 14.01.2020
*/
#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int main()
{
    struct date enteredDate;
    enteredDate = input_date();
    printf("%i",day_of_the_year(enteredDate));
    return 0;
}
