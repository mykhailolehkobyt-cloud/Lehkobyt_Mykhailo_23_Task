#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int CountWords(const string& sentence) {
    stringstream stream(sentence);
    string word;
    int count = 0;

    while (stream >> word) {
        count++;
    }

    return count;
}

int main() {
    system("chcp 65001 > nul");


    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cout << "Не те ім'я файлу" << endl;
        return 1;
    }
    string currentSentance = "";
    string longestSentence = "";
    int maxWordCount = 0;
  
    while (getline(inputFile,currentSentance))
    {
        int currentWordCount = CountWords(currentSentance);
        cout << "Речення: " << currentSentance << "' | Слів: " << currentWordCount << endl;

        if (currentWordCount > maxWordCount) {
            maxWordCount = currentWordCount;
            longestSentence = currentSentance;
        }
    }
    inputFile.close();