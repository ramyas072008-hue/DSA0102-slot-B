
#include <array>
#include <iostream>
#include <stdexcept>
using namespace std;

enum class Zone { Inner, Middle, Outer, Airport };

constexpr array<long long, 4> BASE_PAISE{
    1000, 2000, 3000, 6000
};

constexpr long long MIN_BALANCE = 5000;

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) ||
           (hour >= 17 && hour < 20);
}

class FarePolicy {
public:
    static long long calculate(Zone zone, int hour, bool weekend) {
        if (hour < 0 || hour > 23)
            throw invalid_argument("Invalid hour");

        int index = static_cast<int>(zone);

        if (index < 0 ||
            index >= static_cast<int>(BASE_PAISE.size()))
            throw invalid_argument("Invalid zone");

        long long fare = BASE_PAISE[index];

        // Weekend discount replaces peak surcharge.
        if (weekend)
            return fare * 90 / 100;

        if (isPeak(hour))
            fare += fare * 20 / 100;

        return fare;
    }
};

class MonthlyPass {
private:
    Zone zone1;
    Zone zone2;
    bool active;

public:
    MonthlyPass(Zone a, Zone b, bool valid)
        : zone1(a), zone2(b), active(valid) {}

    bool coversZone(Zone zone) const {
        return active && (zone == zone1 || zone == zone2);
    }
};

class SmartCard {
private:
    long long balancePaise;

public:
    explicit SmartCard(long long balance)
        : balancePaise(balance >= 0 ? balance : 0) {}

    bool deduct(long long fare) {
        if (fare < 0 || balancePaise < fare ||
            balancePaise - fare < MIN_BALANCE)
            return false;

        balancePaise -= fare;
        return true;
    }

    long long getBalance() const {
        return balancePaise;
    }
};

void printFare(const char* label, long long paise) {
    cout << label << " Rs "
         << paise / 100 << '.';

    if (paise % 100 < 10)
        cout << '0';

    cout << paise % 100 << '\n';
}

int main() {
    printFare("Inner weekday peak:",
        FarePolicy::calculate(Zone::Inner, 8, false));

    printFare("Airport weekday peak:",
        FarePolicy::calculate(Zone::Airport, 18, false));

    printFare("Airport weekend:",
        FarePolicy::calculate(Zone::Airport, 18, true));

    MonthlyPass pass(Zone::Inner, Zone::Middle, true);

    cout << "Pass covers Inner: "
         << (pass.coversZone(Zone::Inner) ? "Yes" : "No") << '\n';

    cout << "Pass covers Airport: "
         << (pass.coversZone(Zone::Airport) ? "Yes" : "No") << '\n';

    SmartCard card(10000);

    cout << "Deduct Rs 10: "
         << (card.deduct(1000) ? "Success" : "Denied") << '\n';

    cout << "Balance: " << card.getBalance() << " paise\n";
}
