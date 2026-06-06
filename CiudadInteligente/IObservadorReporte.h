#pragma once
#include <iostream>
using namespace std;

class Reporte;

//CLASE INTERFAZ, define el metodo actualizar que deben implemntar los observadores concretos, 
// en el caso actual sera sistemaReporte quien recibe las notificaciones del observador

class IObservadorReporte {

public:
    //destructor virtual

    virtual ~IObservadorReporte() = default;

    //metodo actualizar, recibe un reporte
    //este metodo esta pensado para que el observador concreto pueda recibir un reporte y procesarlo de la manera que considere adecuada
    //,por ejemplo, mostrarlo en pantalla, guardarlo en un archivo, etc.
    virtual void actualizar(const std::shared_ptr<Reporte>& reporte) = 0;

};