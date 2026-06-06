#pragma once
#include <string>
#include "IFuenteDatosReporte.h"
using namespace std;


class AdaptadorEnergia : public IFuenteDatosReporte {
public:

    ~AdaptadorEnergia() = default;
    string getNombreModulo() const override;
    map<string, string> DatosReporte() const override;
    string getEstado() const override;

};

