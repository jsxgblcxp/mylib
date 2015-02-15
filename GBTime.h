class GBTime //time point
{
        GBTime(); /* create as current time  */
        setUTCTimeZone();
        getUTCTimeZone();

        firstSecondOfToday_local();
        firstSecondOfToday_UTC();

        GBTime1 - GBTime2 = GBTimeSeg;

        Year , month, day..in utc form
        get current time
}

class GBTimeSeg /* time Segment */
{
        outupt as seconde;
        output as seocnd & minute;
        output as seocnd & minute & hour;
}

