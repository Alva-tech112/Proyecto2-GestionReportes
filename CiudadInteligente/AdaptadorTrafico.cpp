#include "AdaptadorTrafico.h"
#include "AdaptadorSensorTrafico.h"
#include <sstream>

string AdaptadorTrafico::getNombreModulo() const {
    return "Trafico";
}

map<string, string> AdaptadorTrafico::DatosReporte() const {
    // Crear sensor externo con datos simulados de la ciudad
    SensorTraficoExterno sensor("SENSOR-AV-PRINCIPAL-01", 3500, 45.0, 62.0);
    AdaptadorSensorTrafico adaptadorSensor(sensor);

    // Obtener medicion del sensor
    MedicionTrafico medicion = adaptadorSensor.obtenerMedicion();

    map<string, string> datos;

    ostringstream ossVehiculos;
    ossVehiculos << medicion.getVehiculos() << " unidades";
    datos["Vehiculos en Circulacion"] = ossVehiculos.str();

    ostringstream ossVelocidad;
    ossVelocidad << medicion.getVelocidadPromedio() << " km/h";
    datos["Velocidad Promedio"] = ossVelocidad.str();

    ostringstream ossCongestion;
    ossCongestion << medicion.getNivelCongestion() << "%";
    datos["Nivel de Congestion"] = ossCongestion.str();

    datos["Sensor"] = adaptadorSensor.getNombreSensor();
    datos["Accidentes Reportados"] = "2 en las ultimas 24 horas";
    datos["Semaforos Activos"] = "120 de 125";

    return datos;
}

string AdaptadorTrafico::getEstado() const {
    SensorTraficoExterno sensor("SENSOR-AV-PRINCIPAL-01", 3500, 45.0, 62.0);
    AdaptadorSensorTrafico adaptadorSensor(sensor);
    MedicionTrafico medicion = adaptadorSensor.obtenerMedicion();

    if (medicion.getNivelCongestion() > 70.0) {
        return "Alerta: Congestion alta en las vias principales. Se recomienda usar transporte publico o rutas alternas.";
    }
    else if (medicion.getNivelCongestion() > 50.0) {
        return "Precaucion: Congestion moderada en las vias principales durante hora pico. Se recomienda usar rutas alternas.";
    }
    return "Normal: Flujo vehicular dentro de parametros normales.";
}