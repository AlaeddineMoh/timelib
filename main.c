/*
*Programm welches nach Eingabe des aktuellen Datums berechnet, der wievielte Tag in diesem Jahr es ist.
<<<<<<< HEAD
*Autor: Mohamed Alaeddine und Jaimie Haake
=======
>>>>>>> 691f8332f4a1ad9a57a038c0bc0acc34954830d7
*Autor: Mohamed Alaeddine
*Datum: 14.01.2020
*/
#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"


/*void input_date(int &day, int &month, int &year)
{

}*/

int get_days_for_month(int month, int year)
{
    int daysForMonth[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leap(year))
    {
        daysForMonth[1]=29;
    }
    return daysForMonth[month-1];
}

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
int main()
{
    int day, month ,year;
    input_date(&day,&month,&year);
    printf("%i",day_of_the_year(day,month,year));
    return 0;
}
