#include "Vect.h"





/*****************************
******************************

Costruttore di default, che assegna valori nulli alla lunghezza del
vettore ed al puntatore

******************************
*****************************/

vect::vect() {

	DimVector = 0;

}





/*****************************
******************************

Costruttore che genera un vettore della dimensione inserita

******************************
*****************************/

vect::vect(unsigned int DimVector_In) {

	DimVector = DimVector_In;
    v = new double[DimVector];

}





/*****************************
******************************

Copy constructor

******************************
*****************************/

vect::vect(const vect& v_In) {

	DimVector = v_In.DimVector;
	v = new double[DimVector];

		for(unsigned int i=0; i<DimVector; i++)
			v[i] = v_In.v[i];

}





/*****************************
******************************

Un distruttore: deve chiaramente deallocare con delete[] la zona di memoria
allocata con new

******************************
*****************************/

vect::~vect() {

	delete v;

}





/*****************************
******************************

Overloading dell'operatore =

******************************
*****************************/

vect& vect::operator=(const vect& v_In) {

	DimVector = v_In.DimVector;
	v = new double[DimVector];

		for(unsigned int i=0; i<DimVector; i++)
			v[i] = v_In.DimVector;

	return *this;

}



unsigned int vect::Get_Dim() const {

    return DimVector;

}





/*****************************
******************************

Funzione per inserire gli elementi nel vettore

******************************
*****************************/

void vect::InsertElement(unsigned int Index_In, double Element_In) {

	if((Index_In <0)||(Index_In > DimVector))
		std::cout << "Index wrong" << std::endl;

	else
		v[Index_In] = Element_In;

}





/*****************************
******************************

Funzione per leggere gli elementi del vettore

******************************
*****************************/

double vect::ReadElement(unsigned int Index_In) {

	if((Index_In <0)||(Index_In > DimVector))
		return -1;

	else
		return v[Index_In];

}


/*****************************
******************************

Funzione per leggere gli elementi del vettore

******************************
*****************************/

double vect::Module() {

    double Sum = 0;

        //Sommo i quadrati degli elementi del vettore

        for(int i=0; i<DimVector; i++)
            Sum = pow(v[i], 2) + Sum;

                return sqrt(Sum);

}





/*****************************
******************************

Funzione che calcola la varianza

******************************
*****************************/

double vect::Average() {

    double Sum = 0;

        //Sommo tutti gli elementi del vettore

        for(int i=0; i<DimVector; i++)
            Sum = v[i] + Sum;

    Avg = Sum/DimVector;

                return Avg;

}





/*****************************
******************************

Funzione che calcola la varianza

******************************
*****************************/

double vect::Variance() {

    double Sum = 0;

        //Sommo tutti gli elementi di Vettore

        for(int i=0; i<DimVector; i++)
            Sum = (v[i] - Avg)*(v[i] - Avg);


    Var = Sum/(DimVector-1);


                return Var;

}
