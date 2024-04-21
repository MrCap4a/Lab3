#include <iostream>
#include <string>
#include <map>
using namespace std;


class date {
private:
    int day = 1;
    int month = 1;
    int year = 2000;

public:
    date() {};
    date(int day, int month, int year) : day(day), month(month), year(year) {};
    ~date() {
        cout << "Объект класса date уничтожен";
    }

    string get_info() {
        return to_string(day) + "-" + to_string(month) + "-" + to_string(year) + ";";
    }

    bool is_leap() {
        if (year % 4 == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void increase() {
        int max_days;
        if (is_leap()) {
            map<int, int> monthes = {
                {1, 31},
                {2, 28},
                {3, 31},
                {4, 30},
                {5, 31},
                {6, 30},
                {7, 31},
                {8, 31},
                {9, 30},
                {10, 31},
                {11, 30},
                {12, 31}
            };
            max_days = monthes[month];
        }
        else {
            map<int, int> monthes = {
                {1, 31},
                {2, 29},
                {3, 31},
                {4, 30},
                {5, 31},
                {6, 30},
                {7, 31},
                {8, 31},
                {9, 30},
                {10, 31},
                {11, 30},
                {12, 31}
            };
            max_days = monthes[month];
        }
        if (max_days < (day + 5)) {
            day = 5 - (max_days - day);
            month += 1;
        }
        else {
            day += 5;
        }
        if (month == 13) {
            month = 1;
            year += 1;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    date this_day(21, 4, 2024);
    cout << this_day.is_leap() << endl;
    cout << this_day.get_info() << endl;
    this_day.increase();
    cout << this_day.get_info() << endl;
}