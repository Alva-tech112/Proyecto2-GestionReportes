
#include "GestorObservadores.h"

void GestorObservadores::registrar(IObservadorReporte* obs) {
    observadores.push_back(obs);
}

void GestorObservadores::notificar(const shared_ptr<Reporte>& r) {
    for (auto* obs : observadores) {
        obs->actualizar(r);
    }
}


void GestorObservadores::eliminar(IObservadorReporte* obs) {

    //la variable buscar es un iterador que apunta al elemento que se quiere eliminar, busca el elemento en el vector de observadores, si lo encuentra, en el if
    //si buscar es diferente al final del vector de observadores, no encontro el elemento, entonces se elimina el elemento del vector de observadores
    auto buscar = find(observadores.begin(), observadores.end(), obs);
    if (buscar != observadores.end()) { //si se encuentra el elemento, se elimina del vector de observadores
        observadores.erase(buscar);
    }
}

int GestorObservadores::getObservadores() const {
    return observadores.size(); //cantidad de observadores registrados
}