#pragma once
#include <iostream>
#include "CiudadException.h"
using namespace std; 

class ArchivoNoEncontradoException : public CiudadException {
public:
    ArchivoNoEncontradoException(const std::string& mensaje) : CiudadException("Archivo no encontrado: " + mensaje) {}
};


