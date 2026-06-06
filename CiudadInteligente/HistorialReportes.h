#pragma once
#include "Reporte.h"
#include <iostream>
#include <vector>

// Esta clase se encarga de almacenar y gestionar los reportes generados por el sistema de reportes.
//ademas de que implementa el BIG 3 RULE para garantizar una correcta gestion de la memoria dinamica.



class HistorialReportes{
private:
    vector<Reporte*> historial;


public:
    HistorialReportes() = default;

    //big 5
    ~HistorialReportes();
    //constructor de copia
    HistorialReportes(const HistorialReportes& otro;
    //constructor de movimiento
    HistorialReportes& operator=(const HistorialReportes& otro); 
    //operador de asignacion por movimiento
    HistorialReportes(HistorialReportes&& otro) noexcept;
    HistorialReportes& operator=(HistorialReportes&& otro) noexcept;


    void agregarReporte(Reporte* r);
    void mostrar() const;
    void cargarDesdeArchivo(const string& ruta);




};

