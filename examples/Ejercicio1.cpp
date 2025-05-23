#include "SaveFlightData.hpp"
#include <fstream>

int main(){
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f); //se guardan los datos requeridos en consigna como objetos
    Presion presion(101.3f, 5.8f, 6.1f);

    SaveFlightData flight(posicion, presion);
    flight.imprimir(); //Se instancia un objeto SaveFlightData y se imprimen los datos

    //Se abre el archivo binario.
    ofstream out("flight.bin", ios::binary); //el ios::binary dice que el archivo se escribe en binario sin importar la extensión
    //creo archivo, uso el metodo serializar para guardar
    // el contenido de flight en ese archivo
    flight.serializar(out);
    out.close();

    SaveFlightData flight_temp;
    // creo otro archivo con valores del constructor por default 
    // que van a ser sobreescritos por los datos leidos desde el archivo con deserealizar()
    ifstream in("flight.bin", ios::binary); //cargo los datos del archivo binario en el nuevo objeto flight_temp
    flight_temp.deserializar(in);
    in.close();

    flight_temp.imprimir(); //muestro los datos recuperados del nuevo archivo
    return 0;
}