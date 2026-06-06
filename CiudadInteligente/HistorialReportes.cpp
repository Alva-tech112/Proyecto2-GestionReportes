#include "HistorialReportes.h"
#include <iostream>
#include <fstream>
#include <sstream>





HistorialReportes::~HistorialReportes() {
    for (Reporte* r : historial) delete r;
}



HistorialReportes::HistorialReportes(const HistorialReportes& otro) {
    for (const Reporte* r : otro.historial) {
        historial.push_back(new Reporte(*r));
    }
}

HistorialReportes::HistorialReportes(HistorialReportes&& otro) noexcept : historial(move(otro.historial)) {}


HistorialReportes& HistorialReportes::operator=(const HistorialReportes& otro) noexcept {

    if (this == &otro) return *this;
    for (Reporte* r : historial) delete r; 
    historial = move(otro.historial);
    return *this;
}


void HistorialReportes::agregarReporte(Reporte* r) {
    historial.push_back(r);
}

void HistorialReportes::mostrar() const {
    if (historial.empty()) {
        cout << "No hay reportes en el historial." << endl;
        return; 
    }
    cout << "\n------HISTORIAL DE REPORTES--------\n"; 
    for (const auto* r : historial) {
        cout << *r; 
    }
}


void HistorialReportes::cargarDesdeArchivo(const string& ruta) {

    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << ruta << endl;
        return;
    }

    //agregar la programacion para el formato del archivo
}

