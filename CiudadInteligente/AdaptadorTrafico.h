#pragma once
#include <string>
#include "IFuenteDatosReporte.h"
using namespace std;

class AdaptadorTrafico : public IFuenteDatosReporte {

public:
    ~AdaptadorTrafico() = default;
    string getNombreModulo() const override;
    map<string, string> DatosReporte() const override;
    string getEstado() const override;

};

