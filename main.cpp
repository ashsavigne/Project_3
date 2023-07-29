#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include "song.cpp"
using namespace std;

void ReadCSV(Playlist p, const string& adj, bool exp, int year, const string& artist){
    ifstream inFile("tracks_features.csv");

    string line;
    getline(inFile, line); // ignore header
    while (getline(inFile, line)){
        if (!line.empty()){
            istringstream stream(line);
            Song* newSong = new Song;
            newSong->Deserialize(stream);
            p.Insert(newSong, adj, exp, year, artist);
        }
    }
}

int main() {
    Playlist p;
    bool on = true;

    while(on){
        cout << "How would you like to design your playlist?" << endl;
        cout << "1. Decade" << endl;
        cout << "2. Mood" << endl;
        cout << "3. Event" << endl;
        cout << "4. Artist" << endl;

        int result;
        string artist = "any";
        cin >> result;
        char exp;
        bool exp_cont;
        int year;
        string num;

        if (result == 0)
            break;

        else if (result == 1){
            cout << "Enter Year: " << endl;
            cin >> result;

            cout << "Family Friendly? (Y/N)" << endl;
            cin >> exp;

            if (exp == 'Y')
                exp_cont = false;
            else
                exp_cont = true;

            cout << "How many songs? (insert \"all\" or a number)" << endl;
            cin >> num;

            ReadCSV(p, "any", exp_cont, result, "any");
            if (num != "all"){
                p.PrintN(stoi(num));
            }
            else
                p.PrintAll();
            p.songs.clear();
            result = 0;
        }

            // mood
        else if (result == 2){
            cout << "Select Mood: " << endl;
            cout << "1. Happy: " << endl; // high energy A major, Bb major c major
            cout << "2. Sad: " << endl; // low energy f minor G minor ab major/minor Bb minor b mino (50 - 80 ) C sharp minor
            cout << "3. Relaxed: " << endl; // mid energy ~ 60 bpm lots of intrumental low loud
            cout << "4. Victorious" << endl; // D major high energy high tempo
            cout << "5. Angry" << endl; // f major b major very loud high tempo
            cout << "0. to stop the progam" << endl;

            cin >> result;

            cout << "Family Friendly? (Y/N)" << endl;
            cin >> exp;
            if (exp == 'Y')
                exp_cont = false;
            else
                exp_cont = true;
            cout << "Insert year: (\"0\" if all)" << endl;
            cin >> year;


            cout << "How many songs? (insert \"all\" or a number)" << endl;
            cin >> num;


            if (result == 1)
                ReadCSV(p, "happy", exp_cont, year, artist);
            else if (result == 2)
                ReadCSV(p, "sad", exp_cont, year, artist);
            else if (result == 3)
                ReadCSV(p, "relaxed", exp_cont, year, artist);
            else if (result == 4)
                ReadCSV(p, "victory", exp_cont, year, artist);
            else if (result == 5)
                ReadCSV(p, "angry", exp_cont, year, artist);
            else
                break;

            if (num != "all")
                p.PrintN(stoi(num));
            else
                p.PrintAll();

            p.songs.clear();
            result = 0;
        }
        else if (result == 3){
            cout << "Enter Event: " << endl;
            cout << "1. Dinner Party" << endl;  // low dance + fam friendly
            cout << "2. Party" << endl; // high dance
            cout << "3. Workout" << endl; // high energy + high dance + high tempo
            cout << "4. After party" << endl; // mid energy + mid tempo
            cin >> result;


            cout << "Family Friendly? (Y/N)" << endl;
            cin >> exp;
            if (exp == 'Y')
                exp_cont = false;
            else
                exp_cont = true;
            cout << "Insert year: (\"0\" if all)" << endl;
            cin >> year;

            cout << "How many songs? (insert \"all\" or a number)" << endl;
            cin >> num;

            if (result == 1)
                ReadCSV(p, "dinner", exp_cont, year, artist);

            else if (result == 2)
                ReadCSV(p, "party", exp_cont, year, artist);
            else if (result == 3)
                ReadCSV(p, "workout", exp_cont, year, artist);
            else if (result == 4)
                ReadCSV(p, "after party", exp_cont, year, artist);
            else {
                break;
            }

            if (num != "all")
                p.PrintN(stoi(num));
            else
                p.PrintAll();

            p.songs.clear();
            result = 0;
        }

        else if (result == 4){
            cout << "Enter Artist: " << endl;
            cin >> artist;

            cout << "Family Friendly? (Y/N)" << endl;
            cin >> exp;
            if (exp == 'Y')
                exp_cont = false;
            else
                exp_cont = true;
            cout << "Insert year: (\"0\" if all)" << endl;
            cin >> year;

            cout << "How many songs? (insert \"all\" or a number)" << endl;
            cin >> num;

            ReadCSV(p, "after party", exp_cont, year, artist);

            if (num != "all")
                p.PrintN(stoi(num));
            else
                p.PrintAll();

            p.songs.clear();
            result = 0;

        }
    }
}
