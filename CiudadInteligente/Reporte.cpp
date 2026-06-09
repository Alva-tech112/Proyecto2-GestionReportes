#include "Reporte.h"

int Reporte::contadorReportes = 0;


// Constructor con 2 parámetros (sin estado)
Reporte::Reporte(const string& mod, const map<string, string>& datos)
    : idReporte(++contadorReportes), modulo(mod) {

    contenido = "\n=== REPORTE ID: " + to_string(idReporte) + " | MODULO: " + modulo + " ===\n";

    for (const auto& par : datos) {
        contenido += par.first + ": " + par.second + "\n";
    }

    contenido += "=========================================\n";
}

// Constructor con 3 parámetros (con estado)
Reporte::Reporte(const string& mod, const map<string, string>& datos, const string& estado)
    : idReporte(++contadorReportes), modulo(mod) {

    contenido = "\n=== REPORTE ID: " + to_string(idReporte) + " | MODULO: " + modulo + " ===\n";

    for (const auto& par : datos) {
        contenido += par.first + ": " + par.second + "\n";
    }

    if (!estado.empty()) {
        contenido += "\nESTADO: " + estado + "\n";
    }

    contenido += "=========================================\n";
}

///Regla de 3
Reporte :: ~Reporte() {
    delete[] contenidoForma;
}

Reporte::Reporte(const Reporte& other) :
    idReporte(other.idReporte), modulo(other.modulo), contenidoForma(nullptr) {
    if (other.contenidoForma) {
        contenidoForma = new char[strlen(other.contenidoForma) + 1];
        strcpy(contenidoForma, other.contenidoForma);
    }
    else
    {
        contenidoForma = nullptr;
    }
}

Reporte& Reporte::operator=(const Reporte& other) {
    if (this != &other) {
        idReporte = other.idReporte;
        modulo = other.modulo;
        delete[] contenidoForma;
        if (other.contenidoForma) {
            contenidoForma = new char[strlen(other.contenidoForma) + 1];
            strcpy(contenidoForma, other.contenidoForma);
        }
        else
        {
            contenidoForma = nullptr;
        }
    }
    return *this;
}

int Reporte::getIDReporte() const {
    return idReporte;
}

string Reporte::getModulo() const {
    return modulo;
}

const char* Reporte::getContenido() const {
    return contenidoForma;
}

ostream& operator<<(ostream& os, const Reporte& reporte) {
    if (reporte.contenidoForma) {
        os << reporte.contenidoForma;
    }
    return os;
}