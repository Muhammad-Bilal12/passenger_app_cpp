#include <iostream>
#include <ctime>

using namespace std;

int main()
{

    const char *time_details = "16:35:12";
    struct tm tm;
    strptime(time_details, "%H:%M:%S", &tm);
    time_t t = mktime(&tm); // t is now your desired time_t

    // current date/time based on current system
    time_t now = time(0);
    //////////////////////////////////
    // time_t t;
    // char *time_string = "Thu Oct 20 01:47:13 2022";

    // t = (time_t)atoll(time_string);
    // difftime(now, now);
    /////////////////////////////////////////
    // convert now to string form
    char *dt = ctime(&now);

    // cout << start << endl;

    cout << "The local date and time is: " << dt << endl;

    // convert now to tm struct for UTC
    // tm *gmtm = gmtime(&now);
    // dt = asctime(gmtm);
    // cout << "The UTC date and time is:" << dt << endl;
}
