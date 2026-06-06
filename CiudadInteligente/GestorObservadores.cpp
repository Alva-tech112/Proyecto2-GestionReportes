
#include "GestorObservadores.h"

void GestorObservadores::registrar(IObservadorReporte* obs) {
    observadores.push_back(obs);
}

void GestorObservadores::notificar(const shared_ptr<Reporte>& r) {
    for (auto* obs : observadores) {
        obs->actualizar(r);
    }
}
