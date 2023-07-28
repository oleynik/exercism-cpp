// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include <cmath>

const int HOURS_PER_DAY = 8;
const int DAYS_PER_MONTH = 22;
const double HUNDRED = 100.0;

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return HOURS_PER_DAY * hourly_rate;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    return before_discount * (HUNDRED - discount) / HUNDRED;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    double afterDiscount = apply_discount(daily_rate(hourly_rate) * DAYS_PER_MONTH, discount);
    return (int) ceil(afterDiscount);
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double daily = apply_discount(daily_rate(hourly_rate), discount);
    return floor(budget / daily);
}