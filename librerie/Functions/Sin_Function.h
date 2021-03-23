#include "Base_Function.h"

#ifndef __Sin_Function_h__
#define __Sin_Function_h__





/******************************
*******************************

Funzione f(x) = asin(bx + c) + d

*******************************
******************************/

class sin_function : public base_function {


		public:

            sin_function();   //Costruttore senza parametri
            sin_function(double a_In, double b_In, double c_In, double d_In);   //Costruttore con parametri

            ~sin_function();    //Distruttore

            sin_function& operator = (const sin_function&);


            //metodi
            
            virtual double Eval(double x_In) const;
            virtual double Get_Extrema() const;

            double Get_a() const;
			double Get_b() const;
            double Get_c() const;
            double Get_d() const;

            void Print();


		private:

			double a, b, c, d;

};

#endif    // __Sin_Function_h__
