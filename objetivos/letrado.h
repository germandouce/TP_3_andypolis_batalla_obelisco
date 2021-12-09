#ifndef LETRADO_H_INCLUDED
#define LETRADO_H_INCLUDED

#include "objetivo.h"

class Letrado: public Objetivo {
    public:
    Letrado();
    bool comprobar_requisito(int maximos_escuelas);
    bool comprobar_requisito();
};

#endif // LETRADO_H_INCLUDED