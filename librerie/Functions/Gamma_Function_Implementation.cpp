#include "Gamma_Function.h"





/******************************
******************************

Costruttore senza parametri

******************************
*****************************/

gamma_function::gamma_function() {}





/*****************************
******************************

Distruttore

******************************
*****************************/

gamma_function::~gamma_function() {}





double gamma_function::Eval(double x_In) const {

    unsigned int step = pow(10,7);
	double a_b = pow(10,5);
	double h = a_b/step;
	double somma = 0.;


        for (unsigned int i =0; i<step; i++)
            somma = somma + h*(pow(i*h,x_In-1)*exp(0.-i*h)+pow((i+1)*h,x_In-1)*exp(0.-(i+1)*h))/2.;

        return somma;

}





/*****************************
******************************

Metodo che restituisce il valore massimo della funzione

******************************
*****************************/

double gamma_function::Get_Extrema() const {

    return 1.;

}
