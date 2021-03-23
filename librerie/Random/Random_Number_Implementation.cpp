#include "Random_Number.h"





/*****************************
******************************

Costruttore senza parametri

******************************
*****************************/

random_number::random_number() {

    seed = 1;

}





/*****************************
******************************

Costruttore con parametri

******************************
*****************************/

random_number::random_number(unsigned int seed_In) {

    seed = seed_In;

}





/*****************************
******************************

Distruttore

******************************
*****************************/

random_number::~random_number() {}





/*****************************
******************************

Metodo per cambiare il valore di a

******************************
*****************************/

void random_number::Set_a(unsigned int a_In) {

	a = a_In;

}





/*****************************
******************************

Metodo per cambiare il valore di c

******************************
*****************************/

void random_number::Set_c(unsigned int c_In) {

	c = c_In;

}





/*****************************
******************************

Metodo per cambiare il valore di m

******************************
*****************************/

void random_number::Set_m(unsigned int m_In) {

	m = m_In;

}





/*****************************
******************************

Metodo per generare numeri pseudocasuali nell'intervallo [0, 1],
che implementa l'algoritmo di generazione lineare congruenziale,
utilizzando la sequente formula:

n_i = mod(a*n_(i-1) + c, m)

con n_0 il seme e mod è una funzione che ritorna
il resto della divisione (intera)
m = massimo numero casuale raggiungibile

******************************
*****************************/

double random_number::Linear_Congruent() {

	unsigned int n;

	double d;

	n = ((a*seed)+c) % m;			    /*Retituise il resto della
                                        divisione tra i due argomenti*/

	seed = n;				    /*Pongo il seme seed uguale a
                                n così posso passare al numero
                                successivo della sequenza*/

	d = ((double)n)/((double)(m-1));	/*In questo modo si ottiene
                                        un numero uniformemente
                                        distribuito tra 0 e 1*/


		return d;

}





/*****************************
******************************

Generatore lineare congruenziale di numeri pseudocasuali nell'intervallo
generico [a, b]

******************************
*****************************/

double random_number::Linear_Congruent(double I0, double I1) {

	unsigned int n;

	double d;

	n = ((a*seed)+c) % m;			    /*Retituise il resto della
                                        divisione tra i due argomenti*/

	seed = n;				    /*Pongo il seme seed uguale a
                                n così posso passare al numero
                                successivo della sequenza*/

	d = ((double)n)/((double)(m-1));	/*In questo modo si ottiene
                                        un numero uniformemente
                                        distribuito tra 0 e 1*/


		return I0+((I1-I0)*d);

}





/*****************************
******************************

Metodo per generare numeri casuali secondo una distribuzione gaussiana,
con il metodo dell'accept-reject, I0 e I1 rappresentano rispettivamente
estremi sinistro e destro dell'intervallo.

La formula della gaussiana è data da:

f(x) = (1/sigma*sqrt(2*pi))*e^-(((x-average)^2)/2*sigma^2)

dove u è il valore atteso e s la varianza. In x = ?, questa funzione
ha un massimo che vale:

f(u) = (1/?*sqrt(2*pi))

******************************
*****************************/

double random_number::Accept_Reject(double I0, double I1, base_function *f_In) {

	double max;    /*Valore massimo della funzione gaussiana
                   nell'intervallo considerato*/

    double y_0;    //Numero maggiore di max
	double x, y;    /*Coppia di numeri da generare su cui si basa
                    il metodo dell'accept-reject*/

    double temp;    /*Variabile utilizzata per scambiare gli estremi nel caso fossero
                    invertiti*/


        //Intervalli scambiati

        if(I0>I1) {

            temp = I0;
            I0 = I1;
            I1 = temp;

		}

		/*Controllo se gli intervalli includono il picco della gaussiana
		se lo includono il massimo è il valore del picco, altrimenti è
		l'estremo dell'intervallo più vicino al picco*/

		if(I0>=(f_In->Get_Extrema()))
            max = I0;

        if(I1<=(f_In->Get_Extrema()))
            max = I1;

        else
            max  = f_In->Get_Extrema();


    //Definisco y_0

    y_0 = max + 0.5;


    /*Genero i numeri casuali per inizializzare il ciclo while, questo ciclo
    prosegue fino a quando una y estratta casualmente si trova al di sotto
    della curva*/

    x = I0 + ((I1-I0)*Linear_Congruent());
    y = y_0*Linear_Congruent();

        while(y<=(f_In->Eval(x))) {

			x = I0 + ((I1-I0)*Linear_Congruent());
			y = y_0*Linear_Congruent();

		}

		return y;

}





/*****************************
******************************

Metodo per generare numeri casuali secondo una distribuzione gaussiana,
con il metodo del Box Muller

******************************
*****************************/

double random_number::Gauss_Box_Muller(double Average_In, double Variance_In) {

	double s = this->Linear_Congruent();
	double t = this->Linear_Congruent();

	double g = sqrt(-2*log(s))*cos(2*M_PI*t);

		return Average_In + (Variance_In*g);

}





/*****************************
******************************

Metodo per generare numeri casuali secondo una distribuzione esponenziale,
con il metodo del Box Muller.

La formula della distribuzione esponenziale è data da:

f(x) = (1/w)*e(-x/w)

dove w è la varianza e 1/w il rate della distribuzione

******************************
*****************************/

double random_number::Exp_Box_Muller(double rate_In) {

	return (-1)*rate_In*log(Linear_Congruent());

}
