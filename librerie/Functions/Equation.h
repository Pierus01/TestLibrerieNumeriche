#include "Base_Function.h"

#ifndef __Equation_h__
#define __Equation_h__





//Definisco l'equazione sinx-xcosx=0

class equation : public base_function {


		public:

            equation(); //Costruttore senza parametri
            ~equation(); //distruttore

            //metodi

            virtual double Eval(double x_In) const;
            virtual double Get_Extrema() const;

};

#endif    // __Equation_h__
