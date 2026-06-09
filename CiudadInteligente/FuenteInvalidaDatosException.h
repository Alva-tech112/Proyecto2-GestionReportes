#pragma once
#include <iostream>
#include "CiudadException.h"
using namespace std;

class FuenteInvalidaDatosException : public CiudadException {

public:
    FuenteInvalidaDatosException(const string& mensaje) : CiudadException("Fuente de datos Invalida: " + mensaje) {}
};


