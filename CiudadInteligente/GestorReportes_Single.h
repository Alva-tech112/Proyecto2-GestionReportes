#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "SistemaReportes.h"


class Reporte;
using namespace std;



class GestorReportes_Single{

private:
    GestorReportes_Single() {

        cout << "\n====================================================\n";
        cout << "SISTEMA DE REPORTES DE CUIDAD INTELIGENTE\n";
        cout << "\n====================================================\n";
    }



        //constructor privado para evitar instancias que nos sean directamente controladas por la clase
    SistemaReportes sistemaRepo; 

public:
    //aplicamos el patron singleton
    GestorReportes_Single(const GestorReportes_Single&) = delete; //eliminamos el constructor de copia

    GestorReportes_Single& operator=(const GestorReportes_Single&) = delete; //eliminamos el operador de asignación y movimiento

    static GestorReportes_Single& getInstancia() { //método estático para obtener la instancia única
        static GestorReportes_Single instancia; //la instancia se crea en la primera llamada y se mantiene durante toda la ejecución
        return instancia;
    }

    SistemaReportes& getSistemaReportes() { //método para acceder al sistema de reportes
        return sistemaRepo;
    }

    // Ejecutar el menú principal interactivo
    void ejecutarMenu() {
        int opcion = 0;

        do {
            cout << "\n========================================\n";
            cout << "         MENU ADMINISTRADOR\n";
            cout << "========================================\n";
            cout << "1. Generar Reporte de Energia\n";
            cout << "2. Generar Reporte de Trafico\n";
            cout << "3. Generar Reporte Ambiental\n";
            cout << "4. Generar Reporte General\n";
            cout << "5. Ver Historial de Reportes\n";
            cout << "6. Cargar Historial desde Archivo\n";
            cout << "7. Ver Estadísticas del Sistema\n";
            cout << "0. Salir\n";
            cout << "========================================\n";
            cout << "Ingrese su opcion: ";

            // Leer entrada
            cin >> opcion;

            // Validar entrada
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\n[ERROR] Entrada invalida. Por favor ingrese un numero.\n";
                continue;
            }

            // Limpiar buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Procesar opción
            try {
                switch (opcion) {
                case 1: {
                    cout << "\n[PROCESANDO] Generando reporte de Energia...\n";
                    sistemaRepo.generarReportePorModulo("Energia");
                    break;
                }

                case 2: {
                    cout << "\n[PROCESANDO] Generando reporte de Trafico...\n";
                    sistemaRepo.generarReportePorModulo("Trafico");
                    break;
                }

                case 3: {
                    cout << "\n[PROCESANDO] Generando reporte Ambiental...\n";
                    sistemaRepo.generarReportePorModulo("Ambiental");
                    break;
                }

                case 4: {
                    cout << "\n[PROCESANDO] Generando reporte General...\n";
                    sistemaRepo.generarReporteGeneral();
                    break;
                }

                case 5: {
                    cout << "\n[PROCESANDO] Mostrando historial...\n";
                    sistemaRepo.mostrarHistorial();
                    break;
                }

                case 6: {
                    string ruta;
                    cout << "\nIngrese la ruta del archivo: ";
                    getline(cin, ruta);

                    if (ruta.empty()) {
                        cout << "[ERROR] Ruta no puede estar vacia.\n";
                        break;
                    }

                    cout << "\n[PROCESANDO] Cargando historial desde: " << ruta << "\n";
                    sistemaRepo.cargarHistorial(ruta);
                    break;
                }

                case 7: {
                    cout << "\n========== ESTADÍSTICAS DEL SISTEMA ==========\n";
                    cout << "Total de Reportes: " << sistemaRepo.getCantidadReportes() << "\n";
                    cout << "Fuentes de Datos: " << sistemaRepo.getCantidadFuentes() << "\n";
                    cout << "Observadores Activos: " << sistemaRepo.getCantidadObservadores() << "\n";
                    cout << "=============================================\n";
                    break;
                }

                case 0: {
                    cout << "\n========================================\n";
                    cout << "Saliendo del sistema...\n";
                    cout << "Gracias por usar el Sistema de Reportes.\n";
                    cout << "========================================\n\n";
                    break;
                }

                default: {
                    cout << "\n[ERROR] Opcion " << opcion << " no valida.\n";
                    cout << "Por favor seleccione una opcion entre 0 y 7.\n";
                }
                }
            }
            catch (const CiudadException& e) {
                cerr << "\n[ERROR EN MENU] " << e.what() << "\n";
            }
            catch (const exception& e) {
                cerr << "\n[ERROR CRITICO] " << e.what() << "\n";
            }

        } while (opcion != 0);
    }

    // Método para mostrar información del sistema
    void mostrarInfoSistema() const {
        cout << "\n========================================\n";
        cout << "   INFORMACION DEL SISTEMA\n";
        cout << "========================================\n";
        cout << "Total de Reportes Generados: " << sistemaRepo.getCantidadReportes() << "\n";
        cout << "Modulos Conectados: " << sistemaRepo.getCantidadFuentes() << "\n";
        cout << "Observadores Registrados: " << sistemaRepo.getCantidadObservadores() << "\n";
        cout << "========================================\n";
    }
};

