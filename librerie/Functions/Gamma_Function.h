#include "Base_Function.h"

#ifndef __Gamma_Function_h__
#define __Gamma_Function_h__





/******************************
*******************************

Funzione f(x) = asin(bx + c) + d

*******************************
******************************/

class gamma_function : public base_function {


    public:

        gamma_function();
        ~gamma_function();

        virtual double Eval(double x_In) const;
        virtual double Get_Extrema() const;

};

#endif    // __Gamma_Function_h__
