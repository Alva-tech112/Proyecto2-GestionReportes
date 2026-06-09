#include "SistemaReportes.h"
#include "ModuloNoEncontradoException.h"
#include "FuenteInvalidaDatosException.h"
#include <iostream>


SistemaReportes::SistemaReportes() {
}


IFuenteDatosReporte* SistemaReportes::buscarFuente(const string& nombre) {

    for (auto* f : fuentes) {
        if (f && f->getNombreModulo() == nombre) {
            return f;
        }
    }
    throw ModuloNoEncontradoException(nombre);
}


void SistemaReportes::agregarFuente(IFuenteDatosReporte* fuente) {
    try {
        if (!fuente) throw FuenteInvalidaDatosException("No se puede agregar una fuente de datos nula");

        //validamos que no haya nombres repetidos

        string nombre = fuente->getNombreModulo();
        if (buscarFuente(nombre) != nullptr) {
            throw FuenteInvalidaDatosException("El modulo" + nombre + " ya existe");
        }
        fuentes.push_back(fuente);
        cout << "\nFuente de datos agregada:" << nombre << "\n";
    }
    catch (const exception& e) {
        cerr << "Error:" << e.what() << endl;
    }
}

void SistemaReportes::registrarObservador(IObservadorReporte* obs) {
    
    try {

        if (!obs) {
            throw FuenteInvalidaDatosException("No se puede registrar una fuente de datos nula");
        }

        gestorObs.registrar(obs);
        cout << "\n Obervadores registrados correctamente. Observadores Totales:" << getCantidadObservadores() << "\n"; 
    }
    catch (const exception& e) {
        cerr << "Error:" << e.what() << endl;
        throw; 
    }

}

void SistemaReportes::generarReportePorModulo(const string& nombremod) {
    try {

        if (nombremod.empty()) {
            throw ModuloNoEncontradoException("Nombre del módulo no puede estar vacío");
        }

        IFuenteDatosReporte* fuente = buscarFuente(nombremod);

        if (!fuente) {
            throw FuenteInvalidaDatosException("No se encontró la fuente de datos para el módulo: " + nombremod);
        }

        map<string, string> datos = fuente->DatosReporte();
        string estado = fuente->getEstado();

        //creamos el reporte

        Reporte* r = nullptr;


        try {
            r = new Reporte(fuente->getNombreModulo(), datos, estado);
        }
        catch (const exception& e) {
            cerr << "Error al crear el reporte: " << e.what() << endl;
            throw;
        }


        try {
            historial.agregarReporte(r);
        }
        catch (const exception& e) {
            cerr << "Error al agregar el reporte al historial: " << e.what() << endl;
            delete r;
            throw;
        }

        //notificamos a los observadores

        try {

            gestorObs.notificar(make_shared<Reporte>(*r));
        }
        catch (const exception& e) {
            cerr << "Error al notificar a los observadores: " << e.what() << endl;
            throw;
        }
        cout << "Reporte generado con exito, nombre del modulo: " << nombremod << "\n";

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}


void SistemaReportes::generarReporteGeneral() {

    if (fuentes.empty()) {
        cout << "\nNo hay fuente de datos\n";
        return;
    }
    map<string, map<string, string>> datosGenerales;
    for (auto* f : fuentes) {
        datosGenerales[f->getNombreModulo()] = f->DatosReporte();
    }
    Reporte* r = new Reporte("Reporte General", datosGenerales); //revisar porque da este error
    historial.agregarReporte(r);
    gestorObs.notificar(make_shared<Reporte>(*r));
    cout << "\nReporte general generado\n";


}

void SistemaReportes::mostrarHistorial() const {
    try {
        historial.mostrar();
    }
    catch (const exception& e) {
        cerr << "Error al mostrar el historial: " << e.what() << endl;
}
}

void SistemaReportes::cargarHistorial(const string& ruta) {

    try {
        if (ruta.empty()) {
            throw invalid_argument("La ruta del archivo no puede estar vacía");
        }
        historial.cargarDesdeArchivo(ruta);
        cout <<"\n Historial cargado desde el archivo: " << ruta << "\n";
    }
    catch (const exception& e) {
        cerr << "Error al cargar el historial: " << e.what() << endl;
    }
}


int SistemaReportes::getCantidadObservadores() const {
    return gestorObs.getObservadores();
}

int SistemaReportes::getCantidadFuentes() const {
    return fuentes.size();
}

int SistemaReportes::getCantidadReportes() const {
    return historial.getReportes();
}