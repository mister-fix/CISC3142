#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int countNumRecords();
void loadNames(string *names, int size);

int main()
{
    try
    {
        ifstream inputFile("names.data");
        if (!inputFile.good())
        {
            throw string("*** Exception *** input file names.data not found");
        }

        ofstream outputFile("results.data");
        if (!outputFile.good())
        {
            throw string("*** Exception *** output file results.data not found");
        }

        int numberOfRecords = countNumRecords();
        if (numberOfRecords > 50)
        {
            throw string("*** Exception *** array capacity exceeded");
        }

        string *namesArray = new string[numberOfRecords];
        loadNames(namesArray, numberOfRecords);

        int *recordIDArray = new int[numberOfRecords];
        int recordIDTracker = 1001;

        for (int i = 0; i < numberOfRecords; i++)
        {
            recordIDArray[i] = recordIDTracker;
            recordIDTracker++;
        }

        string *allRecords = new string[numberOfRecords];

        for (int i = 0; i < numberOfRecords; i++)
        {
            allRecords[i] = namesArray[i] + " " + to_string(recordIDArray[i]);
        }

        sort(allRecords, allRecords + numberOfRecords);

        for (int i = 0; i < numberOfRecords; i++)
        {
            outputFile << allRecords[i] << endl;
        }

        cout << numberOfRecords << " records processed" << endl;

        delete[] namesArray;
        delete[] recordIDArray;
        delete[] allRecords;
    }
    catch (string message)
    {
        cout << message << endl;
        exit(1);
    }
}

int countNumRecords()
{
    try
    {
        int numRecords = 0;
        string fileLine;

        ifstream namesFile("names.data");
        if (!namesFile.good())
        {
            throw string("*** Exception *** input file names.data not found");
        }

        while (namesFile.peek() != EOF)
        {
            getline(namesFile, fileLine);
            numRecords++;
        }

        return numRecords;
    }
    catch (string message)
    {
        cout << message << endl;
        exit(1);
    }
}

void loadNames(string *names, int size)
{
    try
    {
        ifstream namesFile("names.data");
        if (!namesFile.good())
            throw string("*** Exception *** input file names.data not found");

        string name;
        int recordsTrack = 0;

        while (namesFile.peek() != EOF && recordsTrack < size)
        {
            namesFile >> names[recordsTrack];
            getline(namesFile, name);
            recordsTrack++;
        }
    }
    catch (string message)
    {
        cout << message << endl;
        exit(1);
    }
}
