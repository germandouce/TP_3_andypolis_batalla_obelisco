#ifndef BOMBARDERO_H_INCLUDED
#define BOMBARDERO_H_INCLUDED

#include "objetivo.h"

class Bombardero: public Objetivo {
    public:
    Bombardero();
    bool comprobar_requisito();
};

#endif // BOMBARDERO_H_INCLUDED