#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// Function to read a text file and store its content in a string 
string readTextFile(const string& fileName)
{
    ifstream inFile(fileName);
    stringstream buffer;
    buffer << inFile.rdbuf();
    return buffer.str();
}

// Function to tokenize the text content into individual words 
vector<string>tokenizeText(const string& text) {
    vector<string> tokens;
    string word;
    istringstream iss(text);

    while (iss >> word) {
        // Remove punctuation and convert to lowercase
        for (auto& c : word) {
            if (ispunct(c))
                c = ' ';
            else
                c = tolower(c);
        }
        tokens.push_back(word);
    }
    return tokens;
}
// Function to count word occurences 
map <string, int> countWordOccurences(const vector<string>& tokens) {
    map<string, int> wordCount;

    for (const auto& token : tokens) {
        wordCount[token]++;
    }
    return wordCount;
}
// Function to display unique words along with their occurence count 
void displayUniqueWords(const map<string, int>& wordCount) {
    for (const auto& pair : wordCount) {
        cout << pair.first << ":" << pair.second << endl;
    }
}
// Function to find the longest word 
string findLongestWord(const vector<string>& tokens) {
    string longestWord;

    for (const auto& token : tokens) {
        if (token.length() > longestWord.length()) {
            longestWord = token;
        }
    }
    return longestWord;
}
int main() {
    string fileName = "input.txt";
    string text = readTextFile(fileName);
    vector<string> tokens = tokenizeText(text);

    cout << "Word occurrences:" << endl;
    map<string, int> wordCount = countWordOccurences(tokens);
    displayUniqueWords(wordCount);

    string longestWord = findLongestWord(tokens);
    cout << "Longest word: " << longestWord << endl;

    return 0;
}
