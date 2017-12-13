#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED

#include <fstream>

class FileManager {
    private:
        ofstream fileOut("canciones.txt");
        ifstream fileIn("canciones.txt");

        char cadena[1000000];


    public:
       void createFiles();


};

#endif // FILEMANAGER_H_INCLUDED
