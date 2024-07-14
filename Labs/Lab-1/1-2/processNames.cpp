#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// This function will count the number of records within the names.data file
int countNumRecords() {
    try {
        // Records counter
        int numRecords = 0;
        string fileLine;

        // Opening the names.data file (input file)
        ifstream namesFile("names.data");
        // Making sure that the names file exists
        if(!namesFile.good()) {
            throw string("*** Exception *** input file names.data not found");
        }

        // Iterating through file and incrementing the records counter
        while(namesFile.peek() != EOF) {
            getline(namesFile, fileLine);
            // Incrementing the records counter
            numRecords++;
        }

        // Returning number of counted records
        return numRecords;
    }
    catch(string message) {
        // Printing exception message and exit
        cout << message << endl;
        exit(1);
    }
}

// This function will load the names array with all names from the input file
void loadNames(string names[5]) {
    try {
        // Opening the input file
        ifstream namesFile("names.data");
        // Making sure the input file exits
        if(!namesFile.good()) throw string("*** Exception *** input file names.data not found");

        // Keep account of names in file
        string name;

        // Counting number of records in input file
        int recordsTrack = 0;
        // Iterating through file to load names array with names
        while(namesFile.peek() != EOF) {
            // Adding name to array
            namesFile >> names[recordsTrack];
            // Reading file line
            getline(namesFile, name);
            // Incrementing tracker
            recordsTrack++;
        }
    }
    catch(string message) {
        // Printing exception message and exit
        cout << message << endl;
        exit(1);
    }
}

int main() {
    try {
        // Opening the names.data input file
        ifstream inputFile("names.data");
        // Checking that the input file exists
        if(!inputFile.good()) throw string("*** Exception *** input file names.data not found");
        // Opening results.data output file
        ofstream outputFile("results.data");
        // Checking that the output file exits
        if(!outputFile.good()) throw string("*** Exception *** output file results.data not found");

        // Counter for number of records to process in names.data file
        int numberOfRecords = countNumRecords();
        // Making sure we don't exceed our maximum allowed records of 50
        if(numberOfRecords > 50) throw string("*** Exception *** array capacity exceeded");

        // Names array
        string namesArray[numberOfRecords];
        // Loading the names array with data from input file
        loadNames(namesArray);

        // Array for record IDs
        int *recordIDArray = new int[numberOfRecords];
        // Tracker for record IDs
        int recordIDTracker = 1001;

        // Loop to load the record IDs array
        for(int i = 0; i < numberOfRecords; i++){
            recordIDArray[i] = recordIDTracker;
            // Incrementing record ID tracker
            recordIDTracker++;
        }
        
        // String array to hold processed record with name and ID
        string *allRecords = new string [numberOfRecords];

        // Loop to create fully processed record
        for(int i = 0; i < numberOfRecords; i++){
            allRecords[i] = namesArray[i] + " " + to_string(recordIDArray[i]);
        }
	
        // Calling sort method to organize our records alphabetically
	    sort(allRecords, allRecords + numberOfRecords);

        // Writing processed records to output file
        for(int i = 0; i < numberOfRecords; i++) {
            outputFile << allRecords[i] << endl;
        }

        // Printing number of records processed message 
        cout << numberOfRecords << " records processed" << endl;
    }
    catch(string message) {
        // Print exception message and exit
        cout << message << endl;
        exit(1);
    }
}