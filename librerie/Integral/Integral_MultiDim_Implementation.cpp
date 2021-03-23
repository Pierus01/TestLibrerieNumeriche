#include "Integral_MultiDim.h"





/*****************************
******************************

Costruttore con parametri

******************************
*****************************/

integral_multidim::integral_multidim(double a_In, double b_In, const base_function *f_In) {

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

integral_multidim::~integral_multidim() {} 





/*****************************
******************************

Integrazione con il metodo della media usando monte carlo
in più dimensioni
dim_In = numero delle dimensioni

******************************
*****************************/

double integral_multidim::midpoint_MC_MultiDim(int nstep_In, int dim_In) {

    double sum = 0., integralM, sum1 = 0.;

    vect *x = new vect(dim_In);    /*Definisco x come un vettore di dim_In elementi pseudo casuali generati dagli
                                   elementi di r*/

    random_number *Random_Container[dim_In];    //Definisco r come un vettore di dim_In elementi di tipo random_number

        //Memorizzo in r dim_In elementi di tipo random_number

        for (int i=0; i<dim_In; i++){

            Random_Container[i] = new random_number(i);

            Random_Container[i]->Set_a(1664525);
            Random_Container[i]->Set_c(1013904223);
            Random_Container[i]->Set_m(pow(2, 31));

        }


        for (int j=0; j<nstep_In; j++){

                for (int k=0; k<dim_In; k++){

                    x->InsertElement(k, Random_Container[k]->Linear_Congruent(a, b));

                }

            sum = integrand->Eval_MultiDim(x, dim_In) + sum;

        }


    integralM = pow(b-a, dim_In)*(sum/nstep_In);


    //Svuoto la memoria allocata

        for (int k0=0; k0<dim_In; k0++)
            delete Random_Container[k0];

    delete x;

        //Restituisco il valore dell'integrale

		return integralM;

}
