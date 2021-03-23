#include "Secant_Method.h"





//Costruttore senza parametri

secant_method::secant_method() {}





//Distruttore

secant_method::~secant_method(){}





double secant_method::Secant(double x_0, double x_1, const base_function* f_In) {

    int n = 0;
    double x;

        while (n <= prec) {

            //Incremento il contatore del numero di cicli

            n++;

            /*Definisco la successione in cui x corrisponde a x_k+1, mentre
            x_0 corrisponde a x_k, il valore di x_0 passato come argomento
            è il valore iniziale della successione*/

            x = x_1 - ((x_1 - x_0)*f_In->Eval(x_1)/(f_In->Eval(x_1) - f_In->Eval(x_0)));

            //Scambio i due termini

            x_0 = x_1;
            x_0 = x;

            //Riparte il ciclo

        }

            return x;

}
