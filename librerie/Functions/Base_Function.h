#ifndef __Base_Function_h__
#define __Base_Function_h__

#include <iostream>
#include "math.h"

/*****************************
******************************

Classe astratta per una generica funzione

******************************
*****************************/

class base_function
{

public:
    virtual double Eval(double x_In) const = 0; //Caso mono-dimensionale
    virtual double Get_Extrema() const = 0;
};

#endif //
