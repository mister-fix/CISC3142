#include <iostream>
#include <fstream>

using namespace std;

int main() {
    try {
        // Input file
        ifstream namesFile("names.data");
        if(!namesFile.good()) throw string("*** Exception *** input file names.data not found");
        
        // Output file
        ofstream outputFile("results.data");
        if(!outputFile.good()) throw string("*** Exception *** output file results.data not found");

        const int ARR_CAPACITY = 50;

        int idArray[ARR_CAPACITY];
        string namesArray[ARR_CAPACITY];

        while(!namesFile.eof()) {
            namesFile >> namesArray[];
        }

    } catch( string message) {
        cout << message << endl;
        exit(1);
    }
}