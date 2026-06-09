#include "observadorPersistencia.h"
#include "ArchivoNoEncontradoException.h"


observadorPersistencia::observadorPersistencia(const string& ruta) : ruta(ruta) {}

void observadorPersistencia::actualizar(const shared_ptr<Reporte>& reporte) {

    if (!reporte) {
        throw invalid_argument("El reporte no puede ser nulo.");
    }

    ofstream archivo(ruta, ios::app); // Abrir el archivo en modo de adición
    if (!archivo.is_open()) {
        throw ArchivoNoEncontradoException(ruta);

    }
    // Escribir el reporte en el archivo
    archivo << *reporte; //revisar error mas adelante
    archivo.close();
    cout <<"\nReporte guardado en " << ruta << endl;
}

