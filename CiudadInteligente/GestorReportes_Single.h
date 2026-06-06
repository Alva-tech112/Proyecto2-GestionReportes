#pragma once
#include <iostream>
#include <string>


class Reporte;
using namespace std;



class GestorReportes_Single{

private:
    GestorReportes_Single() = default; //constructor privado para evitar instancias que nos sean directamente controladas por la clase


public:
    //aplicamos el patron singleton
    GestorReportes_Single(const GestorReportes_Single&) = delete; //eliminamos el constructor de copia

    GestorReportes_Single& operator=(const GestorReportes_Single&) = delete; //eliminamos el operador de asignación y movimiento

    static GestorReportes_Single& getInstancia() { //método estático para obtener la instancia única
        static GestorReportes_Single instancia; //la instancia se crea en la primera llamada y se mantiene durante toda la ejecución
        return instancia;
    }

};

