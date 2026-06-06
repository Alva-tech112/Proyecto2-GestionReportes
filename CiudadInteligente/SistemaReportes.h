#pragma once
#include "HistorialReportes.h"
#include "GestorObservadores.h"
#include "IFuenteDatosReporte.h"
#include <vector>
#include <string>

class SistemaReportes {
private:
    HistorialReportes historial;
    GestorObservadores gestorObs;
    std::vector<IFuenteDatosReporte*> fuentes;

public:
    void agregarFuente(IFuenteDatosReporte* fuente);
    void registrarObservador(IObservadorReporte* obs);

    void generarReportePorModulo(const std::string& nombreModulo);
    void generarReporteGeneral();

    void mostrarHistorial() const;
    void cargarHistorial(const std::string& ruta);
};
