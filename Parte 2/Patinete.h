#ifndef PATINETE_H
#define PATINETE_H

#include <string>

class Patinete {
public:
    int id; // id del patinete
    std::string estado; // guarda el estado del patinete
    Patinete(int id, std::string estado) : id(id), estado(estado) {} // meto id y estado
};

#endif
