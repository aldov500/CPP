#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Song {
    private:
        string title;
        string author;
        string recordL;
        string genre;

    public:

        void setTitle(const string&);
        void setAuthor(const string&);
        void setRecordL(const string&);
        void setGenre(const string&);


        string getTitle();
        string getAuthor();
        string getRecordL();
        string getGenre();


    };

#endif // SONG_H_INCLUDED
