#pragma once
#include <string>
#include "IFuenteDatosReporte.h"
using namespace std;


class AdaptadorAmbiental : public IFuenteDatosReporte {

public:

    ~AdaptadorAmbiental() = default;
    string getNombreModulo() const override;
    map<string, string> DatosReporte() const override;
    string getEstado() const override;

};

