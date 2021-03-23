#include "Sin_Function.h"





/******************************
******************************

Costruttore senza parametri

******************************
*****************************/

sin_function::sin_function() {

	a = 1.;
	b = 1.;
    c = 0.;
    d = 0.;

}





/*****************************
******************************

Costruttore con parametri

******************************
*****************************/

sin_function::sin_function(double a_In, double b_In, double c_In, double d_In) {

	a = a_In;
	b = b_In;
    c = c_In;
    d = d_In;

}





/*****************************
******************************

Distruttore

******************************
*****************************/

sin_function::~sin_function(){}





/*****************************
******************************

Overloading dell'operatore =

******************************
*****************************/

sin_function& sin_function::operator=(const sin_function& sin_In) {

	a = sin_In.a;
    b = sin_In.b;
    c = sin_In.c;
    d = sin_In.d;

	return *this;

}





double sin_function::Eval(double x_In) const {

		return a*sin((b*x_In) + c) + d;

}





/*****************************
******************************

Metodo che restituisce il valore massimo della funzione

******************************
*****************************/

double sin_function::Get_Extrema() const {

    return 1.;

}





double sin_function::Get_a() const {

		return a;

}





double sin_function::Get_b() const {

		return b;

}





double sin_function::Get_c() const {

		return c;

}





double sin_function::Get_d() const {

		return d;

}





void sin_function::Print() {

    if((Get_a() != 0.)and(Get_a() != 1.)) {

        if((Get_c() > 0.)and(Get_d() > 0.))
            std::cout << "L'equazione di questa sinusoide è: " << Get_a() << "sin(" << Get_b() << "x + " << Get_c() << ") + " << Get_d() << std::endl;

        if((Get_c() > 0.)and(Get_d() < 0.))
            std::cout << "L'equazione di questa sinusoide è: " << Get_a() << "sin(" << Get_b() << "x + " << Get_c() << ") - " << fabs(Get_d()) << std::endl;

        if((Get_c() < 0.)and(Get_d() > 0.))
            std::cout << "L'equazione di questa sinusoide è: " << Get_a() << "sin(" << Get_b() << "x - " << fabs(Get_c()) << ") + " << Get_d() << std::endl;

        if((Get_c() < 0.)and(Get_d() < 0.))
            std::cout << "L'equazione di questa sinusoide è: " << Get_a() << "sin(" << Get_b() << "x - " << fabs(Get_c()) << ") - " << fabs(Get_d()) << std::endl;

    }

    if((Get_a() != 0.)and(Get_a() == 1.)) {

        if((Get_c() > 0.)and(Get_d() > 0.))
            std::cout << "L'equazione di questa sinusoide è: " << "sin(" << Get_b() << "x + " << Get_c() << ") + " << Get_d() << std::endl;

        if((Get_c() > 0.)and(Get_d() < 0.))
            std::cout << "L'equazione di questa sinusoide è: " << "sin(" << Get_b() << "x + " << Get_c() << ") - " << fabs(Get_d()) << std::endl;

        if((Get_c() < 0.)and(Get_d() > 0.))
            std::cout << "L'equazione di questa sinusoide è: " << "sin(" << Get_b() << "x - " << fabs(Get_c()) << ") + " << Get_d() << std::endl;

        if((Get_c() < 0.)and(Get_d() < 0.))
        std::cout << "L'equazione di questa sinusoide è: " << "sin(" << Get_b() << "x - " << fabs(Get_c()) << ") - " << fabs(Get_d()) << std::endl;

    }

    if(Get_a() == 0.)

        std::cout << "La sinusoide è ridotta a una costane di equazione" << Get_d() << std::endl;

}
