#include <stdio.h>
#include <stdbool.h>

#    define name "Aidan"
#    define day_in_years 365


int main() {
    double avg;
    int months = 12;
    
    int years_old;
    
    printf("Years old: ");
    scanf("%d",&years_old);
    int total_months = months*years_old;
    int lead_back = total_months/months;
    
    printf("You have lived %d months.\nEquation: %d*%d=%d\n%d/%d=%d\n\n",total_months,months,years_old,total_months,total_months,months,lead_back);
    
    // we don't want there to be any decimal places, so we are going to keep it as (int)
    avg = (int) day_in_years/months;
    int your_total_days = avg*total_months;
    int leading_back = your_total_days/total_months;
    
    printf("There are approx. %.0f days in a month.\nMeaning you have lived for %d days\nNevertheless, %d/%d=%d. 30 being the average amount of days in a month\n\nThis is being said by %s in the c language\n",avg,your_total_days,your_total_days,total_months,leading_back,name);
    
    return 0;
}
