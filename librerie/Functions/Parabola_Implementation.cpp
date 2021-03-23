#include "Parabola.h"


/******************************
******************************

Costruttore senza parametri

******************************
*****************************/

parabola::parabola() {

	a = 0.0;
	b = 0.0;
    c = 0.0;

		}

/******************************
******************************

Costruttore con parametri

******************************
*****************************/

parabola::parabola(double a_In, double b_In, double c_In) {

	a = a_In;
	b = b_In;
    c = c_In;

		}

/*****************************
******************************

Distruttore

******************************
*****************************/

parabola::~parabola(){}


double parabola::Eval(double x_In) const {

		return (a*x_In*x_In) + (b*x_In) + c;

}


/*****************************
******************************

Metodo che restituisce il valore massimo della funzione

******************************
*****************************/

double parabola::Get_Extrema() const {

    return (-1)*Get_b()/(2*Get_a());

}


int parabola::sign(double x) {

        /*if(x>0)
            return 1;

        if(x==0)
            return 0;

        if(x>0)
            return 1;*/
    return (a == 0) ? 0 : (a<0 ? -1 : 1);

}


double parabola::Get_a() const {

		return a;

}



double parabola::Get_b() const {

		return b;

}



double parabola::Get_c() const {

		return c;

}




void parabola::Print() {

    if(Get_a() != 0.) {

    if((Get_b() > 0.)and(Get_c() > 0.))
    std::cout << "L'equazione di questa parabola è: " << Get_a() << "x^2 + " << Get_b() << "x + " << Get_c() << std::endl;

    if((Get_b() > 0.)and(Get_c() < 0.))
    std::cout << "L'equazione di questa parabola è: " << Get_a() << "x^2 + " << Get_b() << "x - " << fabs(Get_c()) << std::endl;

    if((Get_b() < 0.)and(Get_c() > 0.))
    std::cout << "L'equazione di questa parabola è: " << Get_a() << "x^2 - " << fabs(Get_b()) << "x - " << Get_c() << std::endl;

    if((Get_b() < 0.)and(Get_c() < 0.))
    std::cout << "L'equazione di questa parabola è: " << Get_a() << "x^2 - " << fabs(Get_b()) << "x - " << fabs(Get_c()) << std::endl;

    if((Get_b() > 0.)and(Get_c() == 0.))
    std::cout << "L'equazione di questa parabola è: " << Get_a() << "x^2 + " << Get_b() << "x" << std::endl;

    if((Get_b() < 0.)and(Get_c() == 0.))
    std::cout << "L'equazione di questa parabola è: " << Get_a() << "x^2 - " << fabs(Get_b()) << "x" << std::endl;

    if((Get_b() == 0.)and(Get_c() == 0.))
    std::cout << "L'equazione di questa parabola è: " << Get_a() << std::endl;

    }

    if(Get_a() == 0.) {

    if((Get_b() > 0.)and(Get_c() > 0.))
    std::cout << "L'equazione di questa parabola è: " << Get_b() << "x + " << Get_c() << std::endl;

    if((Get_b() > 0.)and(Get_c() < 0.))
    std::cout << "L'equazione di questa parabola è: " << Get_b() << "x - " << fabs(Get_c()) << std::endl;

    if((Get_b() < 0.)and(Get_c() > 0.))
    std::cout << "L'equazione di questa parabola è: " << Get_b() << "x - " << Get_c() << std::endl;

    if((Get_b() < 0.)and(Get_c() < 0.))
    std::cout << "L'equazione di questa parabola è: " << Get_b() << "x - " << fabs(Get_c()) << std::endl;

    if((Get_b() > 0.)and(Get_c() == 0.))
    std::cout << "L'equazione di questa parabola è: " <<  Get_b() << "x" << std::endl;

    if((Get_b() < 0.)and(Get_c() == 0.))
    std::cout << "L'equazione di questa parabola è: " <<  Get_b() << "x" << std::endl;

    if((Get_b() == 0.)and(Get_c() == 0.))
    std::cout << "La parabola è ridotta a un punto" << std::endl;

    }

}
