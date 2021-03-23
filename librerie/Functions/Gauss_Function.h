#include "Base_Function.h"

#ifndef __Gauss_Function_h__
#define __Gauss_Function_h__





/******************************
*******************************

Funzione Gaussiana

*******************************
******************************/

class gauss_function : public base_function {


    public:

        gauss_function(double Average_In, double Variance_In);    //Costruttore con parametri
        ~gauss_function();    //Distruttore

        virtual double Eval(double x_In) const;
        virtual double Get_Extrema() const;

        double Get_Average();
        double Get_Variance();

        void Set_Average(double Average_In);
        void Set_Variance(double Variance_In);


    private:

        double Average, Variance;

};

#endif    // __Gauss_Function_h__
