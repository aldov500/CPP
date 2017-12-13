//song.cpp
#include "song.h"

/*  Constructores  */

Song::Song() {
    title   = "Def Title";
    author  = "Def Author";
    recordL = "Def RecordL";
    genre   = "Def Genre";
    mp3     = "Def mp3";

    }

Song::Song(const string &t, const string &a, const string &rl, const string &g) {
    title   = t;
    author  = a;
    recordL = rl;
    genre   = g;
    setMP3(a,t);
    }

/*  Getters  */

string Song::getTitle() {
    return title;
    }

string Song::getAuthor() {
    return author;
    }

string Song::getRecordL() {
    return recordL;
    }

string Song::getGenre() {
    return genre;
    }

string Song::getMP3() {
    return mp3;
    }

string Song::getSongInfo () {
    return author + ": " + title + ", " + recordL + ", " + genre + " |" + mp3 + "\n";

    }

/*  Setters  */

void Song::setTitle(const string& t) {
    title = t;
    }

void Song::setAuthor(const string& a) {
    author = a;
    }

void Song::setRecordL(const string& rl) {
    recordL = rl;
    }

void Song::setGenre(const string& g) {
    genre = g;
    }

void Song::setMP3(const string& a, const string& t) {
    mp3 = t +" - "+ a + ".mp3";
    }

void Song::printSong() {
    cout<< getSongInfo();
    }

/*  Operadores  */

bool Song::operator == (Song &s) {
    if(getTitle() == s.getTitle() && getAuthor() == s.getAuthor() ) {
        return true;
        }
    return false;
    }

bool Song::operator != (Song &s) {
    if( (getTitle() != s.getTitle()) || (getAuthor() != s.getAuthor()) || (getMP3() != s.getMP3()) || (getGenre() != s.getGenre()) ) {
        return true;
        }
    else {
        return false;
        }
    }

bool Song::operator <  (Song &s) {

    if((getAuthor() == s.getAuthor() ) && (getTitle() < s.getTitle() ) ) {
        return true;
        }

    if (getAuthor() < s.getAuthor() ) {
        return true;
        }

    return false;
    }

bool Song::operator >  (Song &s) {

    if( (getAuthor() == s.getAuthor()) && (getTitle() > s.getTitle()) ) {
        return true;
        }

    if (getAuthor() > s.getAuthor() ) {
        return true;
        }
    return false;

    }

bool Song::operator =  (Song &s) {
    title   = s.getTitle();
    author  = s.getAuthor();
    recordL = s.getRecordL();
    genre   = s.getGenre();
    mp3     = s.getMP3();
    }
