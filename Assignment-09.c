#include<stdio.h>
int main()
{
    int hr,min,sec,totalsec;
    printf("Enter time in hr,min and sec: ");
    scanf("%d%d%d",&hr,&min,&sec);
    printf("The given time is %d hour, %d minute and %d second\n",hr,min,sec);
    totalsec=hr*3600+min*60+sec;
    printf("Total number of seconds=%d",totalsec);
}

