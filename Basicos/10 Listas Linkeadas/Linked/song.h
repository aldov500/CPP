//song.h
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
        string mp3;

    public:

        Song();
        Song(const string&,const string&,const string&,const string&);

        string getMP3();
        string getTitle();
        string getAuthor();
        string getRecordL();
        string getGenre();
        string getSongInfo();

        void setTitle(const string&);
        void setAuthor(const string&);
        void setRecordL(const string&);
        void setGenre(const string&);
        void setMP3(const string&, const string&);
        void printSong();

        bool operator == (Song&);
        bool operator != (Song&);
        bool operator <  (Song&);
        bool operator >  (Song&);
        bool operator =  (Song&);


    };

#endif // SONG_H_INCLUDED
