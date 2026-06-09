#pragma once
#include <iostream>
#include "IObservadorReporte.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class observadorPersistencia : public IObservadorReporte {
private:
    string ruta;


public:
    observadorPersistencia(const string& ruta);
    void actualizar(const shared_ptr<Reporte>& reporte) override;
    ~observadorPersistencia() = default;

}; 


