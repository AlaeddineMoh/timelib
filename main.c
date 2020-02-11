/*
*Programm welches nach Eingabe des aktuellen Datums berechnet, der wievielte Tag in diesem Jahr es ist.
*Autor: Mohamed Alaeddine und Jaimie Haake
*Datum: 14.01.2020
*/
#include <stdio.h>
#include <stdlib.h>

//Funktion um zu Überprüfen ob das Jahr ein Schaltjahr ist
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
    printf("%i",day_of_the_year(30,3,2000));
    return 0;
}
