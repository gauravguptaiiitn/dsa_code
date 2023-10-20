#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("example.txt", ios::app);
    if (!file) {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    file << "This is the added content.\n";
    file.close();

    ifstream readFile("example.txt");
    if (!readFile) {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    string content;
    while (getline(readFile, content)) {
        cout << content << endl;
    }

    readFile.close();

    return 0;
}

