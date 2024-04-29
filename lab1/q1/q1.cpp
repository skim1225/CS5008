#include <iostream>

using namespace std;

int main() {
    int hours;
    int minutes;
    int seconds;
    int elapsed_time;
    int seconds_remaining;

    cout << "Enter the elapsed time in seconds: " << endl;
    cin >> elapsed_time;

    hours = elapsed_time / 3600;
    seconds_remaining = elapsed_time % 3600;
    minutes = seconds_remaining / 60;
    seconds = seconds_remaining % 60;

    cout << "The time is " << hours << " hours, " << minutes
        << " minutes, and " << seconds << " seconds." << endl;
    return 0;
}