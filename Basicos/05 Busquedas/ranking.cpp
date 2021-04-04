#include "ranking.h"

Song rankingList::createSong(const string& t, const string& a, const string& rl, const string& g, const int& p ) {
    Song temp;

    temp.setTitle(t);
    temp.setAuthor(a);
    temp.setRecordL(rl);
    temp.setGenre(g);
    temp.setMP3(a,t);

    return temp;

    }


void rankingList::initialize() {
    last = -1;

    }

bool rankingList::isEmpty() {
    return last == -1;
    }

bool rankingList::isFull() {
    return last == 49;
    }

void rankingList::deleteAll() {
    last = -1;
    }

void rankingList::insertSong(const int& pos, const Song& s) {
    if(isFull()) {
        throw ListException("Desbordamiento de datos.");
        }
    else if(pos< -1 || (pos>last)) {
        throw ListException("Posicion invalida");
        }

    int i = last;

    while(i>pos) {
        newSong[i+1] = newSong[i];
        i++;
        }

    newSong[pos+1] = s;
    last++;

    }

void rankingList::deleteSong(const int& pos) {
    if(isFull()) {
        throw ListException("Insuficiencia de datos.");
        }
    else if(pos< -1 || (pos>last)) {
        throw ListException("Posicion invalida");
        }

    int i = pos;

    while(i<last) {
        newSong[i] = newSong[i+1];
        i++;
        }
    last--;

    }

int rankingList::getFirstPos() {
    if(isEmpty()) {
        return -1;
        }
    return 0;
    }

int rankingList::getLastPos() {
    return last;
    }

int rankingList::prevPos(const int& pos) {
    if(isEmpty() || pos<1 || pos>last) {
        return -1;
        }
    return pos-1;
    }


int rankingList::nextPos(const int& pos) {
    if(isEmpty() || pos<1 || pos>last) {
        return -1;
        }
    return pos-1;
    }

Song rankingList::getSong(const int& pos) {
    if(isFull()) {
        throw ListException("Insuficiencia de datos.");
        }
    else if(pos< -1 || (pos>last)) {
        throw ListException("Posicion invalida");
        }
    return newSong[pos];

    }

void rankingList::printSong(const int& pos) {
    cout <<setw(3)<<"["<<pos+1<<"]" << setw(25)<<newSong[pos].getTitle()
        << setw(25) <<newSong[pos].getAuthor()
        << setw(25) <<newSong[pos].getRecordL()
        << setw(25) <<newSong[pos].getGenre()
        << setw(25) <<newSong[pos].getMP3()
        <<endl;

    }


string rankingList::linealSearch(const string& s){
    int i = 0;

    while(i<=last){

        while( (s == newSong[i].getAuthor()) || (s == newSong[i].getTitle()) ){

            return newSong[i].getMP3();
        }

        i++;
    }
    return "No Encontrado Lineal";
}


