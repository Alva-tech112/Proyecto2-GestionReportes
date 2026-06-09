#pragma once
#include <iostream>
#include "CiudadException.h"
using namespace std; 


class ModuloNoEncontradoException : public CiudadException {
public:

    ModuloNoEncontradoException(const string& mensaje) : CiudadException("Modulo no encontrado" + mensaje) {}
};
