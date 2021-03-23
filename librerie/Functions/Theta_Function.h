#include "Base_Function.h"

#ifndef __Theta_Function_h__
#define __Theta_Function_h__

#include "../Vector/Vect.h"





/******************************
*******************************

Funzione caratteristica di un intervallo

*******************************
******************************/

class theta_function : public base_function {


    public:

        theta_function (double I0, double I1);    //Costruttore con parametri
        ~theta_function ();    //Distruttore

        virtual double Eval(double x_In) const;    //Caso mono-dimensionale
        double Eval_MultiDim(vect* &v_In, int dim_In) const;    //Caso multi-dimensionale
        virtual double Get_Extrema() const;

    private:

        double a, b;    /*Estremi rispettivamente inferiore e superiore dell'intervallo
                        entro cui la funzione caratteristica vale 1*/

};

#endif    // __Theta_Function_h__
