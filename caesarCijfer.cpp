/* Opdracht voltooid 
 * Bij PPC werken we met C++17 zodat onder andere stoi kan werken.
 * Om de code zo te compileren moet men het volgende doen:
 *      g++ test.cpp -o test -std=c++17
 *
 * Gebruik als "caesarCijfer <woord>  <rotatie>" of caesarCijfer < <inputFile> <rotatie>
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
    if (argc < 2 || argc > 3) {
        cerr << "Gebruik: ./caesarCijfer.exe 'BESTAND of WOORD' 'ROTATIE'" << endl;
        return 1;
    }
    if(argc == 2 ) {  // Als de argument counter 2 is, moet er een bestand meegegeven zijn.
        while(!cin.eof()) {
            getline(cin, sentence);
            for (unsigned int i = 0; i < sentence.length(); i++) {
                if (sentence[i] != ' ' && sentence[i] != ',' && sentence[i] != '.') {
                    newSentence.push_back(char(int(sentence[i]) + stoi(string(argv[1]))));
                } else {
                    newSentence.push_back(sentence[i]);
                }
            }
        }
    } else if(argc == 3){ // Als de argument counter 3 is, moet er een woord meegegeven zijn
        for(unsigned int i = 0; i < string(argv[1]).length(); i++){
            if(string(argv[1])[i] != ' ' && string(argv[1])[i] != ',' && string(argv[1])[i] != '.') {
                newSentence.push_back(char(int(string(argv[1])[i]) + stoi(string(argv[2]))));
            } else {
                newSentence.push_back(string(argv[1])[i]);
            }
        }
    }
    cout << newSentence << endl;
    newSentence = "";
}
