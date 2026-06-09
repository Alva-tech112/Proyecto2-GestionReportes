#pragma once
#include "IObservadorReporte.h"
#include <vector>
using namespace std;


class GestorObservadores {
private:
    std::vector<IObservadorReporte*> observadores;

public:
    void registrar(IObservadorReporte* obs);
    void notificar(const shared_ptr<Reporte>& r);
    void eliminar(IObservadorReporte* obs);
    int getObservadores() const;
};



