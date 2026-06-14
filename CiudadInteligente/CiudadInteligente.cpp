#include <iostream>
#include <string>
#include <memory>
// Singleton y Sistema de Reportes
#include "GestorReportes_Single.h"

// Adaptadores (Patrón Adapter)
#include "AdaptadorEnergia.h"
#include "AdaptadorTrafico.h"
#include "AdaptadorAmbiental.h"

// Observadores (Patrón Observer)
#include "observadorConsola.h"
#include "observadorPersistencia.h"

using namespace std;

int main() {

    // =====================================================================
    // PATRÓN SINGLETON: Obtenemos la instancia única del gestor de reportes
    // =====================================================================
    GestorReportes_Single& gestor = GestorReportes_Single::getInstancia();

    // Obtenemos referencia al sistema de reportes interno
    SistemaReportes& sistema = gestor.getSistemaReportes();

    // =====================================================================
    // PATRÓN ADAPTER: Creamos los adaptadores que convierten datos de cada
    // módulo al formato esperado por el sistema de reportes
    // =====================================================================
    AdaptadorEnergia* adaptadorEnergia = new AdaptadorEnergia();
    AdaptadorTrafico* adaptadorTrafico = new AdaptadorTrafico();
    AdaptadorAmbiental* adaptadorAmbiental = new AdaptadorAmbiental();

    // Registramos las fuentes de datos (adaptadores) en el sistema
    sistema.agregarFuente(adaptadorEnergia);
    sistema.agregarFuente(adaptadorTrafico);
    sistema.agregarFuente(adaptadorAmbiental);

    // =====================================================================
    // PATRÓN OBSERVER: Creamos y registramos los observadores que serán
    // notificados cada vez que se genere un nuevo reporte
    // =====================================================================
    observadorConsola* obsConsola = new observadorConsola();
    observadorPersistencia* obsPersistencia = new observadorPersistencia("reportes_generados.txt");

    sistema.registrarObservador(obsConsola);
    sistema.registrarObservador(obsPersistencia);

    // =====================================================================
    // Ejecutamos el menú interactivo del sistema (dentro del Singleton)
    // =====================================================================
    gestor.ejecutarMenu();

    // =====================================================================
    // Liberación de memoria
    // =====================================================================
    delete obsConsola;
    delete obsPersistencia;
    delete adaptadorEnergia;
    delete adaptadorTrafico;
    delete adaptadorAmbiental;

    return 0;
}