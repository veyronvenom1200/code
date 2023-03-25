#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


// struct times {
//     int years;
//     int months;
//     int weeks;
//     int days;
//     int hours;
//     int minutes;
//     int seconds;
// };

// int conv(unsigned int *diff, int conv_fact) {

//     int new_value = *diff/conv_fact;
//     *diff = *diff%conv_fact;
//     return new_value;
// }

void fucking_ptr(const char *s) {
    s[0] = "b";
    printf("%s\n", s);

}

int main(int argc, char const *argv[])
{
    char *s = "pussy";
    fucking_ptr(s);
    printf("%s\n", s);
    // FILE *ft;
    // char buff[255];
    // ft = fopen("awesome.txt", "r");
    // while(fgets(buff, sizeof(buff), ft) != NULL) {
    //     printf("%s\n", buff);
    // }
    // printf("%p\n", buff);
    // printf("%p\n", buff+1);
    // fclose(ft);

    // time_t max_time = (unsigned int) UINT_MAX;
    // printf("DIFF: %lu\n", max_time);
    // time_t current = time(NULL);
    // printf("DIFF: %lu\n", current);
    // // long diff = difftime(max_time, current);
    // unsigned int diff = max_time - current;
    // printf("DIFF: %u\n", diff);
    // struct times convert_time;

    // const int sec_in_year = 31536000;
    // const int sec_in_month = 2628000;
    // const int sec_in_week = 613200;
    // const int sec_in_day = 87600;
    // const int sec_in_hours = 3660;
    // const int sec_in_minute = 60;

    // convert_time.years = conv(&diff, sec_in_year);
    // convert_time.months = conv(&diff, sec_in_month);
    // convert_time.weeks = conv(&diff, sec_in_week);
    // convert_time.days = conv(&diff, sec_in_day);
    // convert_time.hours = conv(&diff, sec_in_hours);
    // convert_time.minutes = conv(&diff, sec_in_minute);
    // convert_time.seconds = diff;
    // char *max_time_str = ctime(&current);
    // printf("MAX: %lu\nCURRENT: %lu\nDIFF: %s\n", max_time, current, max_time_str);
    // printf("YEARS: %d\nMONTHS: %d\nWEEKS: %d\nDAYS: %d\nHOURS: %d\nMINUTES: %d\nSECONDS: %d\n", convert_time.years, convert_time.months, convert_time.weeks, convert_time.days, convert_time.hours, convert_time.minutes, convert_time.seconds);

    // for(int i = 0; i < 5; i++) {
    //     printf("%p", p);
    // }

    return 0;
}