#include <stdexcept>
#include "song.h"
#include <iostream>
#include <string>

void Playlist::Insert(Song* song, const string& adj, bool exp, int year, const string& artist){
    if ((exp && exp != song->explicit_cont) || (year != 0 && year != song->year) || (artist != "any" && artist != song->artist)){
        delete song;
        return;
    }
    else if ((artist == song->artist && adj == "any" ) || (year == song->year && adj == "any")){
        song->rating = song->tempo + song->dance * 100 + song->energy * 100;
        songs.push_back(song);
    }
    else if (adj == "happy" && song->tempo >= 120 && song->tempo <= 140 && song->dance >= 70 && song->energy >= 50 && song->energy <= 90 && song->valence >= 70 && song->valence <= 90 && song->loud >= -20 && song->mode == 1) {
        song->rating = song->tempo + song->dance * 100 + song->energy * 100;
        songs.push_back(song);
    }
    else if (adj == "sad" && song->tempo >= 50 && song->tempo <= 80 && song->energy <= 40 && song->dance <= 40 && song->loud >= -60 && song->loud <= -30 && song->valence < 40 && song->mode == 0){
        song->rating = 180 - song->tempo + (100 - song->dance) + (100 - song->energy);
        songs.push_back(song);
    }
    else if (adj == "relax" && song->tempo >= 60 && song->tempo <= 90 && song->energy >= 10 && song->energy <= 50 && song->dance <= 40 && song->loud >= -40 && song->loud <= -20 && song->valence >= 30 && song->valence <= 70 && song->mode == 0){
        song->rating = 180 - song->tempo + (100 - song->dance) + (100 - song->energy);
        songs.push_back(song);
    }
    else if (adj == "vinctory" && song->tempo >= 120 && song->tempo <= 140 && song->loud >= -20 && song->valence >=70 && song->energy >= 50 && song->energy <= 90 && song->dance >= 70 && song->mode == 1){
        song->rating = song->tempo + song->dance * 100 + song->energy * 100;
        songs.push_back(song);
    }
    else if (adj == "angry" && song->tempo >= 130 && song->valence <= 60 && song->valence >= 30 && song->energy >= 50 && song->energy >= 70 && song->dance >= 70 && song->loud >= -10){
        song->rating = song->tempo + song->dance * 100 + song->energy * 100 + song->loud;
        songs.push_back(song);
    }
    else if (adj == "Din" && song->tempo >= 50 && song->tempo <= 80 && song->dance <= 50 && song->dance >= 10 && song->energy >= 70 && song->loud >= -40 && song->loud <= -20){
        song->rating = 180 - song->tempo + (100 - song->dance) + (100 - song->energy);
        songs.push_back(song);
    }
    else if (adj == "party" && song->tempo >= 120&& song->energy >= 80 && song->dance >= 80 && song->valence >= 80 && song->loud >= -20 && song->mode == 1){
        song->rating = song->tempo + song->dance * 100 + song->energy * 100;
        songs.push_back(song);
    }
    else if (adj == "workout" && song->tempo >= 100 && song->tempo <= 150 && song->valence >= 50 && song->valence <= 90 && song->energy >= 70 && song->dance >= 50 && song->dance <= 90 && song->loud >= -10 && song->mode == 1){
        song->rating = song->tempo + song->dance * 100 + song->energy * 100 + song->loud * 100;
        songs.push_back(song);
    }
    else if (adj == "Afterparty" && song->tempo >= 90 && song->tempo <= 120 && song->dance >= 50 && song->dance <= 80 && song->energy <= 80 && song->energy >= 40 && song->valence >= 30 && song->valence <= 80 && song->loud >= -20){
        song->rating = song->tempo + song->dance * 100 + song->energy * 100;
        songs.push_back(song);
    }
    else if (adj == "Focus" && song->tempo <= 100 && song->tempo >= 60 && song->dance <= 40 && song->dance >= 10 && song->energy >= 10 && song->energy <= 50 && song->loud >= -40 && song->loud <= -20){
        song->rating = (180 - song->tempo) + (100 - song->dance) + (100 - song->energy);
        songs.push_back(song);
    }
    else if (adj == "Sleepy" && song->tempo >= 40 && song->tempo <= 60 && song->dance <= 30 && song->valence <= 40 && song->energy <= 30 && song->loud <= -30 && song->loud >= -60){
        song->rating = (180 - song->tempo) + (100 - song->dance) + (100 - song->energy);
        songs.push_back(song);

    }
    else
        delete song;
}
void Playlist::PrintAll(){
    if (songs.empty()){
        cout << "Sorry! No applicable songs :(" << endl;
        return;
    }
    cout << "Your playlist has " << songs.size() << " songs!" << endl;
    for (const auto& i : songs){
        cout << "Title: " << i->name << endl;
        cout << "Artist: " << i->artist << endl;
        cout << "Album: " << i->album << endl << endl;
    }

}

void Playlist::PrintN(int n){
    if (songs.empty()){
        cout << "Sorry! No applicable songs :(" << endl;
        return;
    }
    if (n > songs.size()){
        cout << "Your playlist has " << songs.size() << " songs!" << endl;

        for (const auto& i : songs){
            cout << "Title: " << i->name << endl;
            cout << "Artist: " << i->artist << endl;
            cout << "Album: " << i->album << endl << endl;
        }
    }
    else{
        cout << "Your playlist has " << n << " songs!" << endl;
        for (int i = 0; i < n; i++){
            cout << "Title: " << songs[i]->name << endl;
            cout << "Artist: " << songs[i]->artist << endl;
            cout << "Album: " << songs[i]->album << endl << endl;

        }
    }



}

void Song::Deserialize(istringstream& stream) {
    string token;
    if (!getline(stream, token, ',')) // ignore id
        throw runtime_error("Error: missing id");

    if (!getline(stream, this->name, ','))
        throw runtime_error("Error: missing name");

    if (!getline(stream, this->album, ','))
        throw runtime_error("Error: missing album");

    if (!getline(stream, token, ',')) // ignore album id
        throw runtime_error("Error: missing album id");

    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing artist");
    try{
        token.erase(0, 2);
        token.erase(token.size() - 2, 2);
        this->artist = token;
    }
    catch (out_of_range&){
        this->artist = "null";
    }

    if (!getline(stream, token, ',')) // ignore artist id
        throw runtime_error("Error: missing artist id");

    if (!getline(stream, token, ',')) // ignore track num
        throw runtime_error("Error: missing track num");

    if (!getline(stream, token, ',')) // ignore disk num
        throw runtime_error("Error: missing disk num");

    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing explicit"); // explicit

    if (token == "TRUE")
        this->exp = true;
    else
        this->exp = false;

    cout << 'a';

    if (!getline(stream, token, ',')){
        throw runtime_error("Error: missing decidability");
    }
    try{
        this->dance = int(stod(token) * 100);
    }
    catch (invalid_argument&){
        this->dance = 0;
    }

    cout << 'b';
    if (!getline(stream, token, ',')) // ignore artist id
        throw runtime_error("Error: missing energy");
    try{
        this->energy = int(stod(token) * 100);
    }
    catch (invalid_argument&){
        this->energy = 0;
    }

    cout << 'c';
    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing artist id");
    try{
        this->key = stoi(token);
    }
    catch (invalid_argument&){
        this->key = 0;
    }

    if (!getline(stream, token, ','))
        throw runtime_error("no loud");
    try{
        this->loud = int(stod(token) * 100);
    }
    catch (invalid_argument&){
        this->loud = 0;
    }

    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing mode"); // ignore mode

   if (!getline(stream, token, ','))
        throw runtime_error("Error: missing speech"); // ignore speece

    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing acoustics");


    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing instrumental");

    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing liveliness");

    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing valence");
    try{
        this->valence = int(stod(token) * 100);
    }
    catch (invalid_argument&){
        this->valence = 0;
    }

    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing tempo");
    try{
        this->tempo = stoi(token);
    }
    catch (invalid_argument&){
        this->tempo = 0;
    }


    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing duration"); // ignore duration

    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing time signature");

    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing year");
    try{
        this->year = stoi(token);
    }
    catch (invalid_argument&){
        this->year = 0;
    }

    if (!getline(stream, token, ','))
        throw runtime_error("Error: missing release date");
}

Playlist::~Playlist(){
    for (const auto& i : songs){
        delete i;
    }

}
