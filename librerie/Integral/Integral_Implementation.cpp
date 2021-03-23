#include "Integral.h"





/*****************************
******************************

Costruttore con parametri

******************************
*****************************/

integral::integral(double a_In, double b_In, const base_function *f_In) {

    integrand = f_In;

    a = std::min(a_In, b_In);
    b = std::max(a_In, b_In);

        if(a>b)
            sign = -1;

        else
            sign = 1;

}





/*****************************
******************************

Distruttore

******************************
*****************************/

integral::~integral() {}





/*****************************
******************************

Integrazione con la formula del mid-point

******************************
*****************************/

double integral::midpoint(int nstep_In) {

    double x;
    sum = 0.;
    h = (b-a)/nstep_In;

        for(int i=0; i<nstep_In; i++) {

            x = a + (i+0.5)*h;
            sum += integrand->Eval(x);

        }

    integral_value = sign*sum*h;

        return integral_value;

}





/*****************************
******************************

Integrazione con il metodo di Simpson

******************************
*****************************/

double integral::simpson(int nstep_In) {

    double x;
    double sum_1 = 0.;
    double sum_2 = 0.;

    h = (b-a)/(2*nstep_In);

        for(int i=1; i<nstep_In; i++) {

            x = 2*i*h;
            sum_1 += integrand->Eval(x);

        }

        for(int j=0; j<nstep_In; j++) {

            x = ((2*j)+1)*h;
            sum_2 += integrand->Eval(x);

        }

    integral_value = (sign*(h/3))*((integrand->Eval(0.))+(2*sum_1)+(4*sum_2)+(integrand->Eval(b-a)));

        return integral_value;

}





/*****************************
******************************

Integrazione con la formula dei trapezi

******************************
*****************************/

double integral::trapezium(int nstep_In) {

    double x;
    sum = 0.;

    h = (b-a)/nstep_In;

        for(int i=1; i<nstep_In; i++) {

            x = a + (i*h);
            sum += integrand->Eval(x);

        }

    integral_value = h*((((integrand->Eval(a))+(integrand->Eval(a)))/2)+sum);

        return integral_value;

}





/*****************************
******************************

Integrazione con il metodo hit-or-miss

La funzione prende in ingresso il numero di numeri casuali da
generare, nstep_In, e il massimo valore che la funzione assume
nell'intervallo in cui viene calcolato l'integrale, max_function_In

******************************
*****************************/

double integral::Hit_or_Miss(int nstep_In, double max_function_In) {

    unsigned int n_i = 0;    /*Conta quanti numeri casuali vengono generati
                             al di sotto del grafico della funzione*/

    double x_i;    //Numero casuale nell'intervallo di integrazione
    double y_i;    /*Numero casuale da confrontare con l'immagine di
                   x_i attraverso la funzione integranda*/

    double A = (b-a)*max_function_In;    /*Area del rettangolo di base (b-a) e
                                         altezza max_function_In, cioè il massimo
                                         valore assunto dalla funzione nell'intevallo
                                         considerato*/

    r = new random_number(100);

    r->Set_a(1664525);
    r->Set_c(1013904223);
    r->Set_m(pow(2, 31));

        /*Conto quanti y_i si trovano al di sotto del grafico della funzione mediante
        la disuguaglianza y_i<=f(x_i)*/

        for(int i=0; i<nstep_In; i++) {

            x_i = r->Linear_Congruent(a, b);
            y_i = max_function_In*(r->Linear_Congruent());

                if(y_i <= integrand->Eval(x_i))
                    n_i++;

        }

    delete r;

    //Calcolo l'errore standard sulla media della funzione con il metodo hit or miss

    Variance_HM = sqrt(fabs(n_i - (pow(n_i, 2)/nstep_In)))/nstep_In;


        //Restituisco il valore dell'integrale

        return (A*n_i)/nstep_In;

}





/*****************************
******************************

Errore standard sulla media della funzione con il metodo
hit or miss

******************************
*****************************/

double integral::Variance_Hit_or_Miss() {

    return Variance_HM;

}





/*****************************
******************************

Errore standard sulla media della funzione con il metodo
hit or miss

******************************
*****************************/

double integral::Error_Average_Hit_or_Miss() {

    return sqrt(Variance_HM);

}





/*****************************
******************************

Integrazione con il metodo della media usando monte carlo

******************************
*****************************/

double integral::midpoint_MC(int nstep_In) {

    double x, sum = 0., integralM, sum2 = 0., f_Average, f_square_Average;

	r = new random_number(1);
	r->Set_a(1664525);
	r->Set_c(1013904223);
	r->Set_m(pow(2, 31));

        for (int i=0; i<nstep_In; i++){

            x = r->Linear_Congruent(a, b);
            sum = integrand->Eval(x) + sum;
            sum2 = pow(integrand->Eval(x), 2) + sum2;

        }


    integralM = (b-a)*(sum/nstep_In);

    //Calcolo la varianza dello stimatore

    f_Average = sum/nstep_In;
    f_square_Average = sum2/nstep_In;
    Variance_midp_MC = fabs(pow(f_Average, 2) - f_square_Average)/nstep_In;


    //Svuoto la memoria allocata

    delete r;


        //Restituisco il valore dell'integrale

		return integralM;

}





/*****************************
******************************

Varianza dello stimatore della media

******************************
*****************************/

double integral::Variance_midpoint_MC(int nstep_In) {

    double x, sum = 0., integralM, sum2 = 0., f_Average, f_square_Average;

	r = new random_number(1);
	r->Set_a(1664525);
	r->Set_c(1013904223);
	r->Set_m(pow(2, 31));

        for (int i=0; i<nstep_In; i++){

            x = r->Linear_Congruent(a, b);
            sum = integrand->Eval(x) + sum;
            sum2 = pow(integrand->Eval(x), 2) + sum2;

        }


    integralM = (b-a)*(sum/nstep_In);

    //Calcolo la varianza dello stimatore

    f_Average = sum/nstep_In;
    f_square_Average = sum2/nstep_In;
    Variance_midp_MC = fabs(pow(f_Average, 2) - f_square_Average)/nstep_In;


    //Svuoto la memoria allocata

    delete r;


        //Restituisco il valore dell'integrale

		return Variance_midp_MC;

}





/*****************************
******************************

Errore standard della media

******************************
*****************************/

double integral::Error_Average_midpoint_MC(int nstep_In) {

    double x, sum = 0., integralM, sum2 = 0., f_Average, f_square_Average;

	r = new random_number(1);
	r->Set_a(1664525);
	r->Set_c(1013904223);
	r->Set_m(pow(2, 31));

        for (int i=0; i<nstep_In; i++){

            x = r->Linear_Congruent(a, b);
            sum = integrand->Eval(x) + sum;
            sum2 = pow(integrand->Eval(x), 2) + sum2;

        }


    integralM = (b-a)*(sum/nstep_In);

    //Calcolo la varianza dello stimatore

    f_Average = sum/nstep_In;
    f_square_Average = sum2/nstep_In;
    Variance_midp_MC = fabs(pow(f_Average, 2) - f_square_Average)/nstep_In;


    //Svuoto la memoria allocata

    delete r;


        //Restituisco il valore dell'integrale

		return sqrt(Variance_midp_MC);

}
