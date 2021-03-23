#include <algorithm> // std::max

#include "../Functions/Base_Function.h"
#include "Random_Number.h"

#ifndef __Integral_h__
#define __Integral_h__

class integral
{

public:
    integral(double a_In, double b_In, const base_function *f_In); //Costruttore con parametri
    ~integral();                                                   //Distruttore

    double midpoint(int nstep_In);
    double simpson(int nstep_In);
    double trapezium(int nstep_In);

    double Hit_or_Miss(int nstep_In, double max_function_In);
    double Variance_Hit_or_Miss();
    double Error_Average_Hit_or_Miss();

    double midpoint_MC(int nstep_In);
    double Variance_midpoint_MC(int nstep_In);
    double Error_Average_midpoint_MC(int nstep_In);

private:
    double a, b, sum, h, integral_value, Variance_HM, Variance_midp_MC;

    int sign;

    const base_function *integrand;

    random_number *r, *s;
};

#endif // __Integral_h__