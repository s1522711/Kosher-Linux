#include <iostream>
#include <ctime>
#include <sstream>

int main() {
    // check the current time and see if the day is a Saturday
    const time_t now = time(nullptr);
    const tm *ltm = localtime(&now);
    if (ltm->tm_wday != 6 && ltm->tm_wday != 5) {
        std::cout << "normal weekday" << std::endl;
        return 0;
    }

    // if its a friday, check if the time is before 3:00 PM
    if (ltm->tm_wday == 5) {
        if (ltm->tm_hour < 15) {
            std::cout << "not the weekend" << std::endl;
            return 0;
        }
    }

    // if its a saturday, check if the time is after 11:00 AM
    if (ltm->tm_wday == 6) {
        if (ltm->tm_hour < 11) {
            std::cout << "not the weekend" << std::endl;
            return 0;
        }
    }

    // if its the weekend, shut down the computer
    std::cout << "shutting down" << std::endl;
    system("shutdown 5");
    return 0;
}
