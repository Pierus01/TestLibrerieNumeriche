#include "../Function/Base_Function.h"

#ifndef __Zero_Search_h__
#define __Zero_Search_h__





//Classe astratta per una generica funzione

class zero_search {

        public:

            void SetPrecision(double epsilon) { prec = epsilon; }
            double GetPrecision() { return prec;}

        protected:

            double x_min, x_max;    //Estremi della regione di ricerca
            double prec;    //Precision of the solution

            const base_function *f;

};

#endif    // __Zero_Search_h__
