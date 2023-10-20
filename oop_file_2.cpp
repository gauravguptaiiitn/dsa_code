#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToAndDisplayFile(const string &content) {
    ofstream file("example.txt", ios::app);
    if (!file) {
        cout << "Error opening the file!" << endl;
        return;
    }

    file << content << endl;
    file.close();

    ifstream readFile("example.txt");
    if (!readFile) {
        cout << "Error opening the file!" << endl;
        return;
    }

    string fileContent;
    while (getline(readFile, fileContent)) {
        cout << fileContent << endl;
    }

    readFile.close();
}

int countKeyword(const string &keyword) {
    ifstream readFile("example.txt");
    if (!readFile) {
        cout << "Error opening the file!" << endl;
        return -1;
    }

    string content;
    size_t count = 0;
    size_t pos = 0;
    while (getline(readFile, content)) {
        while ((pos = content.find(keyword, pos)) != string::npos) {
            count++;
            pos += keyword.length();
        }
    }

    readFile.close();

    return count;
}

void modifyKeyword(const string &oldKeyword, const string &newKeyword) {
    ifstream readFile("example.txt");
    if (!readFile) {
        cout << "Error opening the file!" << endl;
        return;
    }

    string content;
    string fileContent;
    while (getline(readFile, content)) {
        size_t pos = content.find(oldKeyword);
        if (pos != string::npos) {
            content.replace(pos, oldKeyword.length(), newKeyword);
        }
        fileContent += content + "\n";
    }

    readFile.close();

    ofstream writeFile("example.txt");
    if (!writeFile) {
        cout << "Error opening the file for writing!" << endl;
        return;
    }

    writeFile << fileContent;
    writeFile.close();
}

int countLine(const string &line) {
    ifstream readFile("example.txt");
    if (!readFile) {
        cout << "Error opening the file!" << endl;
        return -1;
    }

    string content;
    int count = 0;
    while (getline(readFile, content)) {
        if (content == line) {
            count++;
        }
    }

    readFile.close();

    return count;
}

int main() {
    writeToAndDisplayFile("This is the added content. This content is an example of the keyword example.");

    string keyword = "example";
    int keywordCount = countKeyword(keyword);
    cout << "The keyword \"" << keyword << "\" appears " << keywordCount << " times in the file." << endl;

    string oldKeyword = "example";
    string newKeyword = "sample";
    modifyKeyword(oldKeyword, newKeyword);

    string lineToCount = "This is the added content. This content is an example of the keyword example.";
    int lineCount = countLine(lineToCount);
    cout << "The line appears " << lineCount << " times in the file." << endl;

    return 0;
}

