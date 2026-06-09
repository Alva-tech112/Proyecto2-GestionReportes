#include "observadorConsola.h"



void observadorConsola::actualizar(const shared_ptr<Reporte>& reporte) {
    if (!reporte) {
        cout <<"Reporte no encontrado" << endl;
        return; 
        cout << "Nuevo reporte recibido:" << endl;
        cout <<&reporte << endl; // revisar este metodo al igual que tenemos que revisarlo en la clase de observador persistencia

   }





}