#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


int main()
{   
    double deg2rad = M_PI / 180.0;
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();

    auto commaLon = LON.find(',');
    auto commaLat = LAT.find(',');

    LON.replace(commaLon, 1, 1, '.');
    LAT.replace(commaLat, 1, 1, '.');

    double lonA = stod(LON) * deg2rad;
    double latA = stod(LAT) * deg2rad;

    double minDist = numeric_limits<double>::max();
    string address;

    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);

        auto semicolon1 = DEFIB.find(';');
        auto semicolon2 = DEFIB.find(';', semicolon1 + 1);
        auto semicolon3 = DEFIB.find(';', semicolon2 + 1);
        auto semicolon4 = DEFIB.find(';', semicolon3 + 1);
        auto semicolon5 = DEFIB.find(';', semicolon4 + 1);
        
        commaLon = DEFIB.find(',', semicolon4 + 1);
        commaLat = DEFIB.find(',', semicolon5 + 1);

        DEFIB.replace(commaLon, 1, 1, '.');
        DEFIB.replace(commaLat, 1, 1, '.');

        double lonB = stod(DEFIB.substr(semicolon4+1, semicolon5 - semicolon4 - 1)) * deg2rad;
        double latB = stod(DEFIB.substr(semicolon5+1)) * deg2rad;

        double x = (lonB - lonA) * cos((latA+ latB) * 0.5);
        double y = (latB - latA);
        double d = sqrt(x*x + y*y) * 6371;

        if (d < minDist) {
            minDist = d;
            address = DEFIB.substr(semicolon1+1, semicolon2 - semicolon1 - 1);
        }

    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << address << endl;
}