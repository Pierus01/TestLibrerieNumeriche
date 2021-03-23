#include "Zero_Search.h"

#ifndef __Bisection_Metod_h__
#define __Bisection_Metod_h__





//Classe che realizza il metodo di bisezione

class bisection_metod : public zero_search {


		public:

            bisection_metod(); //Costruttore senza parametri

            ~bisection_metod(); //distruttore

            //metodi

            double Bisection(double x_min_In, double x_max_In, const base_function* f_In);

};

#endif    // __Bisection_Metod_h__
