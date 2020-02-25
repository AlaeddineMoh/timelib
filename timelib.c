#include "timelib.h"
#include <stdio.h>
#include <stdlib.h>

//Funktion welches errechnet, ob das übergebene Jahr ein Schlatjahr ist
int is_leap(int year)
{
    if (year < 1582)
    {
        return -1;
    }
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

//Funktion welches vom übergebenen Datum der wievielte Tag im Jahr errechnet
int day_of_the_year(int day, int month, int year)
{
    if(exist_date(day,month,year))
    {
        int number=0;
        int i;
        for(i=1;i<month;i++)
            {
                number+=get_days_for_month(i,year);
            }
        number+=day;
        return number;
    }
    return -1;

}

//Funktion welches die Anzahl an Tage in einem bestimmten Monat zurückgibt mit berücksichtigung der Schaltjahre
int get_days_for_month(int month, int year)
{
    int daysForMonth[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leap(year))
    {
        daysForMonth[1]=29;
    }
    return daysForMonth[month-1];
}

//Funktion welches überprüft, ob das eingebene Datum gültig ist
int exist_date(int day, int month, int year)
{
    if (year <1582 || year> 2400)
    {
        return 0;
    }

    if(day>get_days_for_month(month,year) || day<1)
    {
        return 0;
    }
    if(month>12 || month< 1)
    {
        return 0;
    }

    return 1;
}

//Funktion die eine Datumseingabe auffordert und dann das Datum liest
void input_date(int *day, int *month, int *year)
{
    do
    {
        printf("Bitte ein gueltiges Datum eingeben\n");
        printf("Tag: ");
        scanf("%i", day);
        printf("Monat: ");
        scanf("%i", month);
        printf("Jahr: ");
        scanf("%i", year);
        fflush(stdin);
    }
    while(exist_date(*day, *month, *year) == 0);
}
