#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

#include <iomanip>
#include <iostream>
#include "string.h"

#include "song.h"
#include "rankingException.h"


class rankingList {
    private:
        Song newSong[300];
        int last;

    public:
        Song createSong(const string&, const string&, const string&, const string&, const int&);

        void initialize();
        bool isEmpty();
        bool isFull();
        void deleteAll();

        void insertSong(const int&, const Song&);
        void deleteSong(const int&);

        int getFirstPos();
        int getLastPos();
        int prevPos(const int&);
        int nextPos(const int&);
        Song getSong(const int&);

        void printSong(const int&);



        string linealSearch(const string&);




    };



#endif // RANKING_H_INCLUDED
