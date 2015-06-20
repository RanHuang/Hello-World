/*
 * File: calendar.c
 * ----------------
 * This program is used to generate a calendar for a year entered by a user.
 *
 */

#include<stdio.h>

/*
 * Constants:
 *
 */

#define Sunday    0
#define Monday    1
#define Tuesday   2
#define Wednesday 3
#define Thursday  4
#define Friday    5
#define Saturday  6

/*
 * Function prototypes
 */

void GiveInstructions(void);
int GetYearFromUser(void);
void PrintCalendar(int year);
void PrintCalendarMonth(int month, int year);
void IndentFirstLine(int weekday);
int MonthDays(int month, int year);
int FirstDayOfMonth(int month, int year);
char* MonthName(int month);
int IsLeapYear(int year);

/* Main Program */

int main(void)
{
    int year;
    GiveInstructions();
    year = GetYearFromUser();
    PrintCalendar(year);
    return 0;
}

void GiveInstructions()
{
    printf("This program displays a calendar for a full\n");
    printf("year. The year must not before 1900.\n");
}

int GetYearFromUser(void)
{
    int year;
    
    while(1){
        printf("Which year? ");
	scanf("%d", &year);
	if(year >= 1900) return year;
	printf("The year must be at least 1900.\n");
    }
}

void PrintCalendar(int year)
{
    int month;

    for(month = 1; month <= 12; month++)
    {
	PrintCalendarMonth(month, year);
	printf("\n");
    }
}

void PrintCalendarMonth(int month, int year)
{
    int weekday, nDays, day;

    printf("    %s %d\n", MonthName(month), year);
    printf(" Su Mo Tu We Th Fr Sa\n");

    nDays = MonthDays(month, year);
    weekday = FirstDayOfMonth(month, year);
    IndentFirstLine(weekday);
    
    for(day = 1; day <= nDays; day++)
    {
	printf(" %2d", day);
	if(weekday == Saturday) printf("\n");
        weekday = (weekday + 1) % 7;
    } 
}

int MonthDays(int month, int year)
{
    switch(month) {
	case 2:
	  if(IsLeapYear(year)) return 29;
	  return 28;
	case 4:
	case 6:
	case 9:
	case 11:
	  return 30;
	default:
	  return 31;
    }
}
/*
 * 例如：1900年1月1日是星期一
 */
int FirstDayOfMonth(int month, int year)
{
    int weekday, i;

    weekday = Monday;
    for(i = 1900; i < year; i++)
    {
	weekday = (weekday + 365) % 7;
        if(IsLeapYear(i)) weekday = (weekday + 1) % 7;
    }
    
    for(i = 1; i < month; i++)
    {
	weekday = (weekday + MonthDays(i, year)) % 7;
    }
    
    return weekday;
}

void IndentFirstLine(int weekday)
{
    int i;
    for(i = 0; i < weekday; i++) 
    {
	printf("   ");
    }
}
char* MonthName(int month)
{
    switch(month) {
	case  1: return ("January");
	case  2: return ("February");
	case  3: return ("March");
	case  4: return ("April");
	case  5: return ("May");
	case  6: return ("June");
	case  7: return ("July");
	case  8: return ("August");
	case  9: return ("September");
	case 10: return ("October");
	case 11: return ("November");
	case 12: return ("December");
	default: return ("Illegal month.");
    }
}

int IsLeapYear(int year)
{
    return (((year%4==0) && (year%100!=0)) || (year%400==0));
}
