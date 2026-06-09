#pragma once
#include <iostream>
using namespace std;
#include "ArchivoNoEncontradoException.h"
#include "IObservadorReporte.h"

class observadorConsola : public IObservadorReporte {

public:
    void actualizar(const shared_ptr<Reporte>& reporte) override;  
    ~observadorConsola() = default;
};

