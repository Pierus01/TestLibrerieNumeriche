#include "Data_Vect.h"





/*****************************
******************************

Costruttore con parametri

*****************************
******************************/

data_vect::data_vect() {
    
    DimVector = 0;
    
}





/*****************************
******************************

Distruttore

******************************
******************************/

data_vect::~data_vect() {

    delete v;

}





/*****************************
******************************

Funzione che carica i dati da un file da un file specificato dall'utente

******************************
******************************/

void data_vect::LoadFile(std::string Input_file_name) {
    
    //dichiarazioni di variabili di flusso di tipo file

    std::ifstream ingresso;

    int appo;

    ingresso.open(Input_file_name);

        if(ingresso.good() == 0)
            std::cout << "Problema apertura file" << std::endl;
	

    ingresso >> appo;

    //Conto utilizzando un ciclo while quanti dati ci sono memorizzati incrementando la variabile DimVector
    //Quando viene raggiunta la fine del file il ciclo si interrompe

        while(!(ingresso.eof())) {

            DimVector++;
            ingresso >> appo;

        }


    //Chiudo il file

    ingresso.close();

    v = new double[DimVector];
    
    //Apro il file

    ingresso.open(Input_file_name);

    //Memorizzo negli array i dati contenuti nel file

        for(int i=0;i<DimVector;i++)
            ingresso >> v[i];

    //Chiudo il file
	
    ingresso.close();
    
    
}





/*****************************
******************************

Algoritmo di ordinamento

*****************************
******************************/

void data_vect::insertionSort() {
    
    int location;
    int temp;


        for(int firstOutOfOredr = 1; firstOutOfOredr<DimVector; firstOutOfOredr++) {

            if(v[firstOutOfOredr]<v[firstOutOfOredr - 1]) {

                temp = v[firstOutOfOredr];
                location = firstOutOfOredr;

                    do {

                        v[location] = v[location - 1];
                        location--;

                    }

                    while(location>0 && v[location - 1] > temp);
                        v[location] = temp;
                    
            }
        }
    
    
}





/*****************************
******************************

//Stampa gli elementi del vettore preso come argomento sul terminale

*****************************
******************************/

void data_vect::Print() const {

    std::cout << "Elementi del vettore:" << std::endl;

        for(int i=0; i<DimVector; i++)
            std::cout << i << ") " << v[i] << std::endl;


}





/*****************************
******************************

Sovraccarico della funzione Print precedente:
stampa gli elementi del vettore preso come argomento in un file specificato
dall'utente

*****************************
******************************/

void data_vect::Print(std::string Output_file_name) const {

    //dichiarazioni di variabili di flusso di tipo file

    std::ofstream uscita;

    //Apro il file

    uscita.open(Output_file_name);

        if(uscita.good() == 0)
            std::cout << "Problema apertura file" << std::endl;

    uscita.close();

    //Scrivo sul file gli elementi del vettore

        for(int i=0; i<DimVector; i++)
            uscita << v[i];

    //Chiudo il file

    uscita.close();


}
