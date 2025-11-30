#include <iostream>
using namespace std;

// https://codeforces.com/problemset/problem/466/A

int main()
{

    int trips, tripsCoveredByTicket;
    float singleTripPrice, ticketPrice;

    cin >> trips >> tripsCoveredByTicket >> singleTripPrice >> ticketPrice;

    if ((ticketPrice / tripsCoveredByTicket) < singleTripPrice) {

        int remainingTrips = trips % tripsCoveredByTicket;
        int noTickets = (trips - remainingTrips) / tripsCoveredByTicket;
        long sum = noTickets * ticketPrice;

        if (remainingTrips > 0 ){
            if (remainingTrips * singleTripPrice > ticketPrice) {
                sum += ticketPrice;
            } else {
                sum += remainingTrips * singleTripPrice;
            }
        }

        cout << sum;

    } else {
        long sum = trips * singleTripPrice;
        cout << sum;
    }

    return 0;
}