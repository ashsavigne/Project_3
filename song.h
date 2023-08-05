#include <iostream>
#include <vector>
using namespace std;
struct Song {
    // class variables
    string name;
    string album;
    string artist;
    int mode;
    bool exp;
    int dance;
    int key;
    int energy;
    int loud;
    int year;
    int tempo;
    int valence;
    int rating;
public:
    void Deserialize(istringstream& stream);
};

class Playlist{
public:
    vector<Song*> songs;
    Playlist() : songs({}){}
    void Insert(Song* song, const string& option, const string& adj, bool exp, int year, const string& artist);
    void PrintAll();
    void PrintN(int n);
    void Clear();
    ~Playlist();
};
