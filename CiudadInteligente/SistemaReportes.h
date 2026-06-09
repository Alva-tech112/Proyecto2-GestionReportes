#pragma once
#include "HistorialReportes.h"
#include "GestorObservadores.h"
#include "IFuenteDatosReporte.h"
#include <vector>
#include <string>
#include "CiudadException.h"

class CuidadException; //forward declaration because of errors, needs to be review for the adjustment and repair of the error 


class SistemaReportes {
private:
    HistorialReportes historial;
    GestorObservadores gestorObs;
    std::vector<IFuenteDatosReporte*> fuentes;


    //metodo auxiliar
    IFuenteDatosReporte* buscarFuente(const string& nombre); 

public:
    SistemaReportes();
    ~SistemaReportes() = default;
    void agregarFuente(IFuenteDatosReporte* fuente);
    void registrarObservador(IObservadorReporte* obs);

    void generarReportePorModulo(const std::string& nombreModulo);
    void generarReporteGeneral();

    void mostrarHistorial() const;
    void cargarHistorial(const std::string& ruta);


    //metodos de consulta

    int getCantidadReportes() const;
    int getCantidadFuentes() const;
    int getCantidadObservadores() const;


};
