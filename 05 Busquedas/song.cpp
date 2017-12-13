#include "song.h"


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

void Song::setMP3(const string& a, const string& t){
    mp3 = t +" - "+ a + ".mp3";
}

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

string Song::getMP3(){
    return mp3;
}


