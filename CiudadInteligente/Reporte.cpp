#include "Reporte.h"

int Reporte::contadorReportes = 0;

Reporte::Reporte(const string& mod, const map <string, string>& dato) :
    idReporte(++contadorReportes), modulo(mod), contenidoFormnateado(nullptr) {

    ostringstream ss;

    ss << "\t ==============================================\n"
        << "\t Reporte ID: " << idReporte << " Modulo: " << modulo <<
        "\t ==============================================n";

    for (const auto& par : dato) {
        ss << "\t " << par.first << ": " << par.second << "\n";
    }
    ss << "\t ==============================================\n";
    string temp = ss.str();
    contenidoFormnateado = new char[temp.size() + 1];
    strcpy(contenidoFormnateado, temp.c_str());
}

///Regla de 3
Reporte :: ~Reporte() {
    delete[] contenidoFormnateado;
}

Reporte::Reporte(const Reporte& other) :
    idReporte(other.idReporte), modulo(other.modulo), contenidoFormnateado(nullptr) {
    if (other.contenidoFormnateado) {
        contenidoFormnateado = new char[strlen(other.contenidoFormnateado) + 1];
        strcpy(contenidoFormnateado, other.contenidoFormnateado);
    }
    else
    {
        contenidoFormnateado = nullptr;
    }
}

Reporte& Reporte::operator=(const Reporte& other) {
    if (this != &other) {
        idReporte = other.idReporte;
        modulo = other.modulo;
        delete[] contenidoFormnateado;
        if (other.contenidoFormnateado) {
            contenidoFormnateado = new char[strlen(other.contenidoFormnateado) + 1];
            strcpy(contenidoFormnateado, other.contenidoFormnateado);
        }
        else
        {
            contenidoFormnateado = nullptr;
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
    return contenidoFormnateado;
}

ostream& operator<<(ostream& os, const Reporte& reporte) {
    if (reporte.contenidoFormnateado) {
        os << reporte.contenidoFormnateado;
    }
    return os;
}