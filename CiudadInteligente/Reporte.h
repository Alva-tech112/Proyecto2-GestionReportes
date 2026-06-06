#pragma once
#ifndef REPORTE_H
#define REPORTE_H

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;


/* Esta clase gestiona la memoria dinamica por medio del BIG 3 RULE
* esto garantiza que no haya fugas de memoria ni problemas de doble liberacion de memoria,
* ya que se implementa el constructor de copia,
* el operador de asignacion y el destructor.
*/

class Reporte {

private:
    static int contadorReportes;
    int idReporte;
    string modulo;
    char* contenidoFormnateado;

public:
    Reporte(const string& mod, const map<string, string>& datos);

    ///Big 3 RULE
    ~Reporte();
    Reporte(const Reporte& other);
    Reporte& operator=(const Reporte& other);

    int getIDReporte() const;
    string getModulo() const;
    const char* getContenido() const;
    friend ostream& operator<<(ostream& os, const Reporte& reporte);

};


#endif // !REPORTE_H