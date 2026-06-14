#include "AdaptadorEnergia.h"

string AdaptadorEnergia::getNombreModulo() const {
    return "Energia";
}

map <string, string> AdaptadorEnergia::DatosReporte() const {
    map<string, string> datos;
    datos["Consumo Total"] = "1500 kWh";
    datos["Consumo Promedio"] = "50 kWh/día";
    datos["Pico de Consumo"] = "200 kWh el 15 de junio";
    return datos;
}

string AdaptadorEnergia::getEstado() const {
    return "Alerta: Se ha detectado un aumento inusual en el consumo de energía. Se recomienda revisar los dispositivos conectados y considerar medidas de eficiencia energética.";
}
