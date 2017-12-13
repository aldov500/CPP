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


