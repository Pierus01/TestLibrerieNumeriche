#include "Newton_Method.h"





//Costruttore senza parametri

newton_method::newton_method() {}





//Distruttore

newton_method::~newton_method(){}





double newton_method::Newton(double x_0, const parabola* f_In) {

    int n = 0;
    double x;

        while (n <= prec) {

            //Incremento il contatore del numero di cicli

            n++;

            /*Definisco la successione in cui x corrisponde a x_k+1, mentre
            x_0 corrisponde a x_k, il valore di x_0 passato come argomento
            è il valore iniziale della successione*/

            x = x_0 - ((f_In->Eval(x_0))/((2*f_In->Get_a()*x_0) + f_In->Get_b()));

            //Scambio i due termini

            x_0 = x;

            //Riparte il ciclo

        }

            return x;

}
