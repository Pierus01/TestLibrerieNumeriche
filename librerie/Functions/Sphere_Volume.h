#include "Gamma_Function.h"

#ifndef __Sphere_Volume_h__
#define __Sphere_Volume_h__





class sphere_volume : public base_function {


    public:

        sphere_volume();
        ~sphere_volume();

        virtual double Eval(double x_In) const;
        virtual double Get_Extrema() const;

};

#endif    // __Sphere_Volume_h__
