#include "../Functions/Base_Function.h"

#ifndef __Random_Number_h__
#define __Random_Number_h__





class random_number {


	public:

        random_number();    //Costruttore senza parametri
		random_number(unsigned int seed_In);	//Costruttore con parametri

		~random_number();    //Distruttore

		void Set_a(unsigned int a_In);    //Metodo per cambiare il valore di a
		void Set_c(unsigned int c_In);    //Metodo per cambiare il valore di b
		void Set_m(unsigned int m_In);    //Metodo per cambiare il valore di c

		double Linear_Congruent();    /*Metodo per generare numeri casuali compresi
                                      nell'intervallo [0, 1] che implementa l'algoritmo
                                      di generazione lineare congruenziale*/

        double Linear_Congruent(double I0, double I1);    /*Metodo per generare numeri casuali compresi
                                                          nell'intervallo generico [a, b] che implementa
                                                          l'algoritmo di generazione lineare congruenziale*/

        double Accept_Reject(double I0, double I1, base_function *f_In);    /*Metodo per generare numeri casuali
                                                                            secondo una distribuzione gaussiana,
                                                                            con il metodo dell'accept-reject,
                                                                            I0 e I1 rappresentano rispettivamente
                                                                            estremi sinistro e destro dell'intervallo*/

        double Gauss_Box_Muller(double Average_In, double Variance_In);    /*Metodo per generare numeri casuali
                                                                           secondo una distribuzione gaussiana,
                                                                           con il metodo del  Box Muller*/

        double Exp_Box_Muller(double rate_In);    /*Metodo per generare numeri casuali
								    secondo una distribuzione esponenziale,
								    con il metodo del  Box Muller*/


	private:

		unsigned int a, c, m, seed;    //Coefficienti per generare numeri pseudocasuali


/*La keyword unsigned indica che il tipo seguente deve essere considerato senza segno, lasciando
cos� un bit in pi� alla rappresentazione del numero. L'utilizzo di unsigned � necessario con i parametri
dai noi scelti per evitare problemi di overflow degli interi nelle operazioni*/

};

#endif    // __Random_Number__
