#include "Bisection_Metod.h"





//Costruttore senza parametri

bisection_metod::bisection_metod() {}





//Distruttore

bisection_metod::~bisection_metod(){}





double bisection_metod::Bisection(double x_min_In, double x_max_In, const base_function* f_In) {

    int n=0;
    double x;


		while (n <= prec) {    //Controllo sulla precisione richiesta

            x = x_min_In + ((x_max_In - x_min_In)/2);    //Calcolo del valore medio dell'intervallo,
                                                        //tale valore rappresenta la successione
                                                       //da iterare

            n++;    //Contatore del numero di passi

                if (f_In->Eval(x)*f_In->Eval(x_min_In) == 0.)    //Trovato lo zero
                    break;

                /*Verifico se la funzione cambia segno agli estremi in tal caso c'è uno zero,
                il prodotto viene valutato mediante il segno per via della limitata precisione
                del tipo double*/

                if (f_In->Eval(x)*f_In->Eval(x_min_In) < 0.)
                    x_max_In=x;

                else
                    x_min_In = x;

        }

            return x;

}
 
