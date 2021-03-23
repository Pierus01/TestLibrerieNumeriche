#include "Theta_Function.h"





/******************************
******************************

Costruttore con parametri che prende come argomenti gli estremi
di un intevallo

******************************
*****************************/

theta_function::theta_function(double I0, double I1) {

    /*Assegno ad a e b i due argomenti, controllando quale dei
    due è l'estremo inferiore e superiore dell'intervallo*/

    a = std::min(I0, I1);
    b = std::max(I0, I1);

}





/*****************************
******************************

Distruttore

******************************
*****************************/

theta_function::~theta_function () {}





/*****************************
******************************

Caso mono-dimensionale

******************************
*****************************/

double theta_function::Eval(double x_In) const {

	if ((x_In >= a) and (x_In <= b))
        return 1.;

    else
        return 0.;

}





/*****************************
******************************

Caso multi-dimensionale

******************************
*****************************/

double theta_function::Eval_MultiDim(vect* &v_In, int dim_In) const {

	if ((v_In->Module() >= pow(a, dim_In)) and (v_In->Module() <= pow(b, dim_In)))
        return 1.;

    else
        return 0.;

}




/*****************************
******************************

Metodo che restituisce il valore massimo della funzione

******************************
*****************************/

double theta_function::Get_Extrema() const {

    return 1.;

}
