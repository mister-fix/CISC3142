#include <iostream>
#include <fstream>

using namespace std;

int main() {
    try {
        ifstream namesFile("names.data");
        if(!namesFile.good()) throw string("*** Exception *** input file names.data not found");

        ofstream outputFile("results.data");
        if(!outputFile.good()) throw string("*** Exception *** output file results.data not found");

        int idArray[] = {1001, 1002, 1003, 1004, 1005};
        int numberOfRecords = 0;
        string namesArray[5];
        string name;

        while(namesFile.peek() != EOF) {
            namesFile >> namesArray[numberOfRecords];
            getline(namesFile, name);
            numberOfRecords++;
        }

        if(numberOfRecords > 50) {
            throw string("*** Exception *** array capacity exceeded");
        } else {
            for(int i = 0; i < numberOfRecords; ++i) {
                outputFile << namesArray[i] << " ";
                outputFile << idArray[i] << endl;
            }
        }

        cout << numberOfRecords << " records processed" << endl;
    } catch(string message) {
        cout << message << endl;
        exit(1);
    }
}