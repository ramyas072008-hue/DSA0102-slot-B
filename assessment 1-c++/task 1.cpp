
#include <iostream>
#include <string>
using namespace std;

enum class Zone { Inner, Middle, Outer };

class Passenger {
public:
    string name;
    string category;

    Passenger(string n, string c)
        : name(n), category(c) {}
};

class FareTable {
public:
    static int getFare(Zone z) {
        switch (z) {
            case Zone::Inner: return 1000;
            case Zone::Middle: return 2000;
            case Zone::Outer: return 3000;
        }
        return 0;
    }
};

class Journey {
public:
    Zone zone;
    int hour;

    Journey(Zone z, int h) : zone(z), hour(h) {}

    bool isPeak() const {
        return (hour >= 8 && hour < 10) ||
               (hour >= 17 && hour < 20);
    }

    long long calculateFare() const {
        long long f = FareTable::getFare(zone);
        return isPeak() ? f + f * 20 / 100 : f;
    }
};

class SmartCard {
private:
    long long balancePaise;

public:
    explicit SmartCard(long long b) : balancePaise(b) {}

    bool pay(long long fare) {
        if (fare < 0 || balancePaise - fare < 5000)
            return false;
        balancePaise -= fare;
        return true;
    }

    long long balance() const { return balancePaise; }
};

int main() {
    Passenger p("Ramya", "Regular");
    Journey j(Zone::Inner, 9);
    SmartCard card(10000);

    long long f = j.calculateFare();

    cout << "Passenger: " << p.name << '\n';
    cout << "Fare (paise): " << f << '\n';
    cout << (card.pay(f) ? "Journey allowed" : "Journey denied")
         << '\n';
    cout << "Balance (paise): " << card.balance() << '\n';
}
