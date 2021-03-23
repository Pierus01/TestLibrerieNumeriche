#include "Gauss_Function.h"





/******************************
******************************

Costruttore con parametri

******************************
*****************************/

gauss_function::gauss_function(double Average_In, double Variance_In) {

    Average = Average_In;
    Variance = Variance_In;

}





/*****************************
******************************

Distruttore

******************************
*****************************/

gauss_function::~gauss_function() {}





double gauss_function::Eval(double x_In) const {

        return (1/(Variance*sqrt(2*M_PI)))*exp((-1)*pow(x_In-Average, 2)/(2*pow(Variance, 2)));

}





/*****************************
******************************

Metodo che restituisce il valore massimo della funzione

******************************
*****************************/

double gauss_function::Get_Extrema() const {

    return 1/(Variance*sqrt(2*M_PI));

}





/*****************************
******************************

Metodo che restituisce il valore di Average

******************************
*****************************/

double gauss_function::Get_Average() {

    return Average;

}





/*****************************
******************************

Metodo che restituisce il valore di Variance

******************************
*****************************/

double gauss_function::Get_Variance() {

    return Variance;

}





/*****************************
******************************

Metodo che restituisce il valore di Average

******************************
*****************************/

void gauss_function::Set_Average(double Average_In) {

    Average = Average_In;

}





/*****************************
******************************

Metodo che restituisce il valore di Variance

******************************
*****************************/

void gauss_function::Set_Variance(double Variance_In) {

    Variance = Variance_In;

}
