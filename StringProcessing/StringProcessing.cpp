#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> splitWords(const string& text);
string insertCommaBeforeNo(const vector<string>& words);
int countSubstringsBetweenCommas(const string& text);
bool firstLetterRepeats(const string& word);
int countWordsWithRepeatedFirstLetter(const vector<string>& words);
void printWords(const vector<string>& words);

vector<string> splitWords(const string& text) {
    vector<string> words;
    stringstream stream(text);
    string word;

    while (stream >> word) {
        words.push_back(word);
    }

    return words;
}

string insertCommaBeforeNo(const vector<string>& words) {
    string result;

    for (int i = 0; i < words.size(); i++) {
        if (words[i] == "no") {
            if (!result.empty() && result[result.length() - 1] == ' ') {
                result.pop_back();
            }
            result += ",";
        }

        result += words[i];

        if (i != words.size() - 1) {
            result += " ";
        }
    }

    return result;
}

int countSubstringsBetweenCommas(const string& text) {
    int count = 0;
    bool hasCharacters = false;

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ',') {
            if (hasCharacters) {
                count++;
            }
            hasCharacters = false;
        }
        else if (text[i] != ' ') {
            hasCharacters = true;
        }
    }

    if (hasCharacters) {
        count++;
    }

    return count;
}

bool firstLetterRepeats(const string& word) {
    if (word.empty()) {
        return false;
    }

    char firstLetter = word[0];
    int count = 0;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] == firstLetter) {
            count++;
        }
    }

    return count > 1;
}

int countWordsWithRepeatedFirstLetter(const vector<string>& words) {
    int count = 0;

    for (int i = 0; i < words.size(); i++) {
        if (firstLetterRepeats(words[i])) {
            count++;
        }
    }

    return count;
}

void printWords(const vector<string>& words) {
    cout << "Слова строки:" << endl;

    for (int i = 0; i < words.size(); i++) {
        cout << i + 1 << ". " << words[i] << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    string text;

    cout << "Введите строку слов, разделенных пробелами:" << endl;
    getline(cin, text);

    vector<string> words = splitWords(text);

    cout << endl << "Исходная строка:" << endl;
    cout << text << endl;

    cout << endl;
    printWords(words);

    string newText = insertCommaBeforeNo(words);

    cout << endl << "Новая строка:" << endl;
    cout << newText << endl;

    int substringCount = countSubstringsBetweenCommas(newText);
    int repeatedFirstLetterCount = countWordsWithRepeatedFirstLetter(words);

    cout << endl << "Количество подстрок между запятыми: " << substringCount << endl;
    cout << "Количество слов, у которых первая буква встречается более одного раза: "
        << repeatedFirstLetterCount << endl;

    cin.get();

    return 0;
}