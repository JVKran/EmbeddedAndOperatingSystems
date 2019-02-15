/*
 * Bij PPC werken we met C++17 zodat onder andere stoi kan werken.
 * Om de code zo te compileren moet men het volgende doen:
 *      g++ test.cpp -o test -std=c++17
 *
 */
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::stoi;

int main(int argc, char* argv[]) {
    string newSentence;
    string sentence;
    if (argc < 2) {
        cerr << "Gebruik: ./test.exe 'BESTAND of WOORD' 'ROTATIE'" << endl;
        return 1;
    }
    if(argc == 2) {
        getline(cin, sentence);
        for (unsigned int i = 0; i < sentence.length(); i++) {
            newSentence.push_back(char(int(sentence[i]) + stoi(string(argv[1]))));
        }
    } else if(argc == 3){
        for(unsigned int i = 0; i < string(argv[1]).length(); i++){
            newSentence.push_back(char(int(string(argv[1])[i])+stoi(string(argv[2]))));
        }
    }
    cout << newSentence;
}