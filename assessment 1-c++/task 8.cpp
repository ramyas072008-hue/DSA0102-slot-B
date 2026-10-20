
#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int hour;

    while (true) {
        cout << "Enter hour (0-23): ";

        if (cin >> hour) {
            if (hour >= 0 && hour <= 23)
                break;

            cout << "Invalid hour.\n";
        } else {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    long long farePaise =
        ((hour >= 8 && hour < 10) ||
         (hour >= 17 && hour < 20)) ? 1200 : 1000;

    cout << "Fare: Rs " << farePaise / 100 << '.'
         << setw(2) << setfill('0') << farePaise % 100
         << '\n';
}
