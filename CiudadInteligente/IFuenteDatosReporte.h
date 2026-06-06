#pragma once
#ifndef IFUENTEDATOSREPORTE_H
#define IFUENTEDATOSREPORTE_H
#include <string>
#include <map>
using namespace std;

/*
* Esta interfaz utiliza el patron adapter
ya que al implementar dicha interfaz, se adapta al los datos esperado que resive el
Sistema de Reportes, es decir, el Sistema de Reportes espera un formato de datos especifico,
y al implementar esta interfaz, se adapta a ese formato,
permitiendo que el Sistema de Reportes pueda utilizar los datos
proporcionados por la clase que implementa esta interfaz sin necesidad de
modificar el Sistema de Reportes.
*/

class IFuenteDatosReporte {
public:
    virtual ~IFuenteDatosReporte() = default;

    // Método para obtener el nombre del modulo (ejemplo: "Energia", "Transporte", etc.)
    virtual string getNombreModulo() const = 0;

    virtual map<string, string> DatosReporte() const = 0;

    virtual string getEstado() const = 0;

};

#endif // !IFUENTEDATOSREPORTE_H