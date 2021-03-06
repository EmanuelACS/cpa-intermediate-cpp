#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Emanuel Dobra

const int SIZE = 25;

int loadArrays(string[], double[][3]);
void printReport(string[], double[][3], int);

int main()
{
    string birdTypes[SIZE];
    double birdSightings[SIZE][3]; // int x[3][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}}; SO 3/3
    int birdCount = loadArrays(birdTypes, birdSightings);
    printReport(birdTypes, birdSightings, birdCount);
}

void printReport(string birdTypes[], double birdSightings[][3], int birdCount) {
    ofstream outFile("birds.rpt");
    if (!outFile.is_open()) {
        cout << "error opening file";
        system("pause");
        exit(-1);
    }

    for (int pos = 0; pos < birdCount; pos++) {
        outFile << birdTypes[pos] << "\t";

        for (int innerPos = 0; innerPos < 3; innerPos++) {
            outFile << birdSightings[pos][innerPos] << "\t";
        }
        outFile << endl;
    }
    outFile << "\n# of birds=" << birdCount << endl;
    outFile.close();

    system("type birds.rpt");
}

int loadArrays(string birdTypes[], double birdSightings[][3]) {
    ifstream myFile("birds.dat");
    if (!myFile.is_open()) {
        cout << "error opening file";
        system("pause");
        exit(-1);
    }

    int pos;
    for (pos = 0; pos < SIZE; pos++) {
        getline(myFile, birdTypes[pos]);
        if (myFile.eof())
            break;
        for (int innerPos = 0; innerPos < 3; innerPos++) {
            myFile >> birdSightings[pos][innerPos];
        }
        myFile.ignore(80, '\n');
    }
    myFile.close();
    
    return pos;
}

/* Output
Blue Heron      25      50      4
Cardinal        25      0       25
King Fisher     3       44      0
Pink Flamingo   0       40      2
Baltimore Oriole        53      8       7

# of birds=5
*/
