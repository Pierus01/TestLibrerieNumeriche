#include "Zero_Search.h"

#ifndef __Secant_Method_h__
#define __Secant_Method_h__





//Classe che realizza il metodo delle secanti

class secant_method : public zero_search {


    public:

            secant_method(); //Costruttore senza parametri

            ~secant_method(); //distruttore


            //metodi

            double Secant(double x_0, double x_1, const base_function* f_In);

};

#endif    // __Secant_Method_h__
