#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED
struct date{
    int year;
    int month;
    int day;
};
int is_leap(int year);
int day_of_the_year(struct date enteredDate);
int get_days_for_month(int month, int year);
int exist_date(struct date enteredDate);
struct date input_date();
#endif // TIMELIB_H_INCLUDED
