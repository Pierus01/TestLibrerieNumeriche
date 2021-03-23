#include "Zero_Search.h"
#include "../Function/Parabola.h"

#ifndef __Newton_Method_h__
#define __Newton_Method_h__





//Classe che realizza il metodo di newton

class newton_method : public zero_search {


    public:

            newton_method(); //Costruttore senza parametri

            ~newton_method(); //distruttore


            //metodi

            double Newton(double x_0, const parabola* f_In);

};

#endif    // __Newton_Method_h__
