#include "Equation.h"





//Costruttore senza parametri

equation::equation() {}





//Distruttore

equation::~equation() {}


double equation::Eval(double x_In) const {

		return sin(x_In) - (x_In*cos(x_In));

}





/*****************************
******************************

Metodo che restituisce il valore massimo della funzione

******************************
*****************************/

double equation::Get_Extrema() const {

    return 1.;

}
