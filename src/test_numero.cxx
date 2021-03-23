#include "numero.h" //Per il test di pybind11
#include <iostream>
#include <pybind11/pybind11.h>

namespace py = pybind11;

/*
Costruzione del modulo di test, verifa che sia trovato pybind11 
e che la classe "numero" sia definita a dovere. La verifica include
l'import in python, potrebbero infatti essere presenti referenze non
risolte che non si vedono nella compilazione.
*/
PYBIND11_MODULE(test_numero, m)
{
    py::class_<numero>(m, "numero")
        .def(py::init<const double &>())
        .def("getValore", &numero::getValore)
        .def("setValore", &numero::setValore);
}