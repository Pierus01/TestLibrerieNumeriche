#include <iostream>
#include "math.h"

#ifndef __Vect_h__
#define __Vect_h__





class vect {


	public:

		vect();    //Costruttore senza parametri
        vect(unsigned int DimVector_In);    //Costruttore con parametri
		vect(const vect&);    //Copy constructor

		~vect();

		vect& operator = (const vect&);

        unsigned int Get_Dim() const;
		void InsertElement(unsigned int Index_In, double Element_In);

		double ReadElement(unsigned int Index_In);
        double Module();    //Funzione che calcola la media aritmetica
        double Average();    //Funzione che calcola la media aritmetica
        double Variance();    //Funzione che calcola la varianza 


	protected:

		unsigned int DimVector;

        double Avg;    //Media aritmetica degli elementi del vettore
        double Var;    //Varianza degli elementi del vettore
		double *v=NULL;

};

#endif    // __Vect_h__
