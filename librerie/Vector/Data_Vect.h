#include <fstream>

#include "Vect.h"





class data_vect : public vect {


    public:

        data_vect();    //Costruttore con parametri

        ~data_vect();   //Distruttore
        
        void LoadFile(std::string Input_file_name);
        void insertionSort();
        void Print() const;
        void Print(std::string Output_file_name) const;

};
