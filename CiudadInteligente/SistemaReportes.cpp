#include "SistemaReportes.h"


void SistemaReportes::agregarFuente(IFuenteDatosReporte* fuente) {
    fuentes.push_back(fuente);
}

void SistemaReportes::registrarObservador(IObservadorReporte* obs) {
    gestorObs.registrar(obs);
}

void SistemaReportes::generarReportePorModulo(const string& nombremod) {
    for (auto* f : fuentes) {
        if (f->getNombreModulo() == nombremod) {
            Reporte* r = new Reporte(f->getNombreModulo(), f->DatosReporte(), f->getEstado());
            historial.agregarReporte(r);
            gestorObs.notificar(make_shared<Reporte>(*r));
            //notificacion de que todo haya funcionado perfectamente
            cout <<"Reporte generado para el módulo: " << nombremod << endl;
            return;
        }
    }
    cout <<"Módulo no encontrado: " << nombremod << endl;   

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
    Reporte* r = new Reporte("General", datosGenerales, "N/A");
    historial.agregarReporte(r);
    gestorObs.notificar(make_shared<Reporte>(*r));
    cout << "\nReporte general generado\n";


}

void SistemaReportes::mostrarHistorial() const {
    historial.mostrar();
}

void SistemaReportes::cargarHistorial(const string& ruta) {
    historial.cargarDesdeArchivo(ruta);
}
