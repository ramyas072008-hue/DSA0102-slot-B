
#include <array>
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr array<long long, 3> BASE{
    1000, 2000, 3000
};

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

bool calculateFare(Zone zone, int hour, long long& result) {
    if (hour < 0 || hour > 23)
        return false;

    int index;

    switch (zone) {
        case Zone::Inner:  index = 0; break;
        case Zone::Middle: index = 1; break;
        case Zone::Outer:  index = 2; break;
        default: return false;
    }

    result = BASE[index];

    if (isPeak(hour))
        result += result * 20 / 100;

    return true;
}

int main() {
    struct Test {
        Zone zone;
        int hour;
        long long expected;
    };

    const array<Test, 6> tests{{
        {Zone::Inner, 7, 1000},
        {Zone::Inner, 8, 1200},
        {Zone::Inner, 10, 1000},
        {Zone::Outer, 17, 3600},
        {Zone::Outer, 20, 3000},
        {Zone::Middle, 12, 2000}
    }};

    int passed = 0;

    for (const Test& t : tests) {
        long long actual = 0;
        bool valid = calculateFare(t.zone, t.hour, actual);
        bool success = valid && actual == t.expected;

        cout << (success ? "PASS" : "FAIL")
             << " Expected: " << t.expected
             << " Actual: ";

        if (valid)
            cout << actual;
        else
            cout << "INVALID";

        cout << '\n';
        if (success) ++passed;
    }

    cout << "Passed: " << passed << "/" << tests.size() << '\n';
}
