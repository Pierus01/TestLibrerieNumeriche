#include "Sphere_Volume.h"





/******************************
******************************

Costruttore senza parametri

******************************
*****************************/

sphere_volume::sphere_volume() {}





/*****************************
******************************

Distruttore

******************************
*****************************/

sphere_volume::~sphere_volume() {}





double sphere_volume::Eval(double x_In) const {

    base_function *g = new gamma_function();

	double a = pow(M_PI, 0.5*x_In);
	double b = g-> Eval(x_In*0.5+1.);
	double vol = a/b;

        return vol;

}





/*****************************
******************************

Metodo che restituisce il valore massimo della funzione

******************************
*****************************/

double sphere_volume::Get_Extrema() const {

    return 1.;

}
