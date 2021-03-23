#include "Base_Function.h"

#ifndef __Parabola_h__
#define __Parabola_h__





/******************************
*******************************

Funzione f(x) = ax^2 + bx + c

*******************************
******************************/

class parabola : public base_function {


		public:

            parabola(); //Costruttore senza parametri
			parabola(double a_In, double b_In, double c_In); //Costruttore con parametri

            ~parabola(); //distruttore

            //metodi

            virtual double Eval(double x_In) const;
            virtual double Get_Extrema() const;

            int sign(double x);    //Funzione segno

			double Get_a() const;
			double Get_b() const;
            double Get_c() const;

            void Print();

		private:

			double a, b, c;

};

#endif    //__Parabola_h__
