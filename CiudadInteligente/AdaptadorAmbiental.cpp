#include "AdaptadorAmbiental.h"

string AdaptadorAmbiental::getNombreModulo() const {
    return "Ambiental";
}

map<string, string> AdaptadorAmbiental::DatosReporte() const {
    map<string, string> datos;
    datos["Calidad del Aire"] = "Buena";
    datos["Nivel de Ruido"] = "Moderado";
    datos["Temperatura"] = "22°C";
    return datos;
}

string AdaptadorAmbiental::getEstado() const {
    return "Alerta preventida: Se recomienda reducir actividades al aire libre durante las horas pico.";
}
