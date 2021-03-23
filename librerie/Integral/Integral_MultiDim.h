#include "Integral.h"

#ifndef __Integral_MultiDim_h__
#define __Integral_MultiDim_h__





class integral_multidim : public integral {

        public:

            integral_multidim(double a_In, double b_In, const base_function* f_In);    //Costruttore con parametri
            ~integral_multidim();    //Distruttore

            double midpoint_MC_MultiDim(int nstep_In, int dim_In);

        private:

            double a, b, sum, h, integral_value;
            
            int sign;

            const base_function *integrand;

};

#endif    // __Integral_MultiDim_h__ 
