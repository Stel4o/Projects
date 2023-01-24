#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Flight {
    int day;
    int flight_number;
    string pilot1;
    string pilot2;
    string pilot3;
    int first_class_passengers;
    int second_class_passengers;
    double first_class_price;
    double second_class_price;
};

void addFlight(const Flight& flight) {
    ofstream file("flights.txt", ios::app);

    file << flight.day << " " << flight.flight_number << " " << flight.pilot1 << " "
        << flight.pilot2 << " " << flight.pilot3 << " " << flight.first_class_passengers << " "
        << flight.second_class_passengers << " " << flight.first_class_price << " "
        << flight.second_class_price << endl;

    file.close();
}

void correctPassengerCount(int flight_number, int first_class_passengers, int second_class_passengers) {
    vector<Flight> flights;
    ifstream file("flights.txt");
    while (file) {
        Flight flight;
        file >> flight.day >> flight.flight_number >> flight.pilot1 >> flight.pilot2 >> flight.pilot3
            >> flight.first_class_passengers >> flight.second_class_passengers
            >> flight.first_class_price >> flight.second_class_price;
        if (file) flights.push_back(flight);
    }
    file.close();

    for (Flight& flight : flights) {
        if (flight.flight_number == flight_number) {
            flight.first_class_passengers = first_class_passengers;
            flight.second_class_passengers = second_class_passengers;
            break;
        }
    }

    ofstream output_file("flights.txt");
    for (const Flight& flight : flights) {
        output_file << flight.day << " " << flight.flight_number << " " << flight.pilot1 << " "
            << flight.pilot2 << " " << flight.pilot3 << " " << flight.first_class_passengers << " "
            << flight.second_class_passengers << " " << flight.first_class_price << " "
            << flight.second_class_price << endl;
    }
    output_file.close();
}
void displayPilotFlights(const string& pilot) {
    ifstream file("flights.txt");
    while (file) {
        Flight flight;
        file >> flight.day >> flight.flight_number >> flight.pilot1 >> flight.pilot2 >> flight.pilot3
            >> flight.first_class_passengers >> flight.second_class_passengers
            >> flight.first_class_price >> flight.second_class_price;
        if (file) {
            if (flight.pilot1 == pilot || flight.pilot2 == pilot || flight.pilot3 == pilot) {
                cout << "Flight " << flight.flight_number << " on day " << flight.day << ": "
                    << flight.first_class_passengers << " first class passengers, "
                    << flight.second_class_passengers << " second class passengers" << endl;
            }
        }
    }
    file.close();
}
int main() {
    cout << "Varna Airport Flight Management System" << endl;
    cout << "1. Add new flight" << endl;
    cout << "2. Correct passenger count on a flight" << endl;
    cout << "3. Display flights of a pilot" << endl;
    cout << "4. Display all flights" << endl;
    cout << "Enter a number to select a function (0 to exit): ";

    int selection;
    cin >> selection;

    if (selection == 1) {
        Flight flight;
        cout << "Enter day of the month: ";
        cin >> flight.day;
        cout << "Enter flight number: ";
        cin >> flight.flight_number;
        cout << "Enter the three names of the pilot: ";
        cin >> flight.pilot1 >> flight.pilot2 >> flight.pilot3;
        cout << "Enter number of passengers (first and second class): ";
        cin >> flight.first_class_passengers >> flight.second_class_passengers;
        cout << "Enter ticket price (first and second class): ";
        cin >> flight.first_class_price >> flight.second_class_price;

        addFlight(flight);
    }
    else if (selection == 2) {
        int flight_number;
        cout << "Enter flight number: ";
        cin >> flight_number;
        int first_class_passengers;
        cout << "Enter number of first class passengers: ";
        cin >> first_class_passengers;
        int second_class_passengers;
        cout << "Enter number of second class passengers: ";
        cin >> second_class_passengers;

        correctPassengerCount(flight_number, first_class_passengers, second_class_passengers);
    }
    else if (selection == 3) {
        string pilot;
        cout << "Enter pilot name: ";
        cin >> pilot;

        displayPilotFlights(pilot);
    }
    else if (selection == 4) {
        ifstream file("flights.txt");
        while (file) {
            Flight flight;
            file >> flight.day >> flight.flight_number >> flight.pilot1 >> flight.pilot2 >> flight.pilot3
                >> flight.first_class_passengers >> flight.second_class_passengers
                >> flight.first_class_price >> flight.second_class_price;
            if (file) {
                cout << "Flight " << flight.flight_number << " on day " << flight.day << ": "
                    << flight.first_class_passengers << " first class passengers, "
                    << flight.second_class_passengers << " second class passengers" << endl;
            }
        }
        file.close();
    }

    return 0;
}