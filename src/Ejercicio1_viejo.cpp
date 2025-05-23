// #include <iostream>
// #include <memory> 
// #include <fstream>

// using namespace std;

// class IMediciones {
//     public:
//         virtual ~IMediciones() = default;
//         virtual void serializar(ofstream& out) const = 0; //no modifica al objeto
//         virtual void deserializar(ifstream& in) = 0 ; //modifica al objeto
// };

// class MedicionBase : public IMediciones {
//     protected:
//         unique_ptr<float> tiempoMedicion;
//     public:
//         MedicionBase(float tiempo=0.0f) : tiempoMedicion(make_unique<float>(tiempo)) {} 
//         //constructor con deep copy
//         MedicionBase(const MedicionBase& other) : tiempoMedicion(make_unique<float>(*other.tiempoMedicion)) {}
//         // "other" es un objeto MedicionBase pasado por referencia.
//         // Accedo a su atributo "tiempoMedicion" (un unique_ptr),
//         // desreferencio el puntero con "*"" para obtener el float,
//         // y creo una nueva copia de ese valor con "make_unique".

//         virtual ~MedicionBase() = default;
//         float getTiempo() const{
//             return *tiempoMedicion;
//         };
//         virtual void imprimir() const = 0;
// };

// class Presion : public MedicionBase {
//     public:
//         float presionEstatica;
//         float presionDinamica;
//         Presion(float p =0.0f, float q =0.0f, float t=0.0f) : presionEstatica(p), presionDinamica(q), MedicionBase(t) {}
//         //constructor con deep copy
//         //llamo explicitamente al constructor de copia de la clase base MedicionBase, 
//         //se crea una copia (deep copy) del atributo tiempoMedicion
//         Presion(const Presion& other) : presionEstatica(other.presionEstatica), presionDinamica(other.presionDinamica), MedicionBase(other) {}

//         void serializar(ofstream& out) const override{
//             out.write(reinterpret_cast<const char*>(&presionEstatica),sizeof(presionEstatica));
//             out.write(reinterpret_cast<const char*>(&presionDinamica),sizeof(presionDinamica));
//             out.write(reinterpret_cast<const char*>(tiempoMedicion.get()),sizeof(float));
//         }

//         void deserializar(ifstream& in) override{ 
//             in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
//             in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
//             in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
//         }

//         void imprimir() const override{
//             cout<<"TIEMPO MEDICIÓN: "<<getTiempo()<<endl;
//             cout<<"PRESIÓN ESTÁTICA: "<<presionEstatica<<endl;
//             cout<<"PRESIÓN DINÁMICA: "<<presionDinamica<<endl;
//         }
// };

// class Posicion : public MedicionBase{
//     public:
//         float latitud;
//         float longitud;
//         float altitud;
//         Posicion (float lat = 0.0f, float lon = 0.0f, float alt = 0.0f, float t = 0.0f): latitud(lat), longitud(lon), altitud(alt), MedicionBase(t) {}
//         //constructor con deep copy
//         Posicion(const Posicion& other) : latitud(other.latitud), longitud(other.longitud), altitud(other.altitud), MedicionBase(other) {}

//         void imprimir() const override{
//             cout<<"TIEMPO MEDICIÓN: "<<getTiempo()<<endl;
//             cout<<"LATITUD: "<<latitud<<endl;
//             cout<<"LONGITUD: "<<longitud<<endl;
//             cout<<"ALTITUD: "<<altitud<<endl;
//         }

//         void serializar(ofstream& out) const override{
//             out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
//             out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
//             out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
//             out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
//         }

//         void deserializar(ifstream& in) override{
//             in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
//             in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
//             in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
//             in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
//         }
// };

// class SaveFlightData{
//     public:
//         Posicion posicion;
//         Presion presion;

//         SaveFlightData(const Posicion& p = Posicion(), const Presion& q = Presion()): posicion(p), presion(q) {}

//         void imprimir(){
//             cout<<"FLIGHT DATA - SPANISH: "<<endl;
//             posicion.imprimir();
//             presion.imprimir();
//         }

//         void serializar(ofstream& out) const{
//             posicion.serializar(out);
//             presion.serializar(out);
//         }

//         void deserializar(ifstream& in) {
//             posicion.deserializar(in);
//             presion.deserializar(in);
//         }
// };

// int main(){
//     Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f); //se guardan los datos requeridos en consigna como objetos
//     Presion presion(101.3f, 5.8f, 6.1f);

//     SaveFlightData flight(posicion, presion);
//     flight.imprimir(); //Se instancia un objeto SaveFlightData y se imprimen los datos

//     //Se abre el archivo binario.
//     ofstream out("flight.bin", ios::binary); //el ios::binary dice que el archivo se escribe en binario sin importar la extensión
//     //creo archivo, uso el metodo serializar para guardar
//     // el contenido de flight en ese archivo
//     flight.serializar(out);
//     out.close();

//     SaveFlightData flight_temp;
//     // creo otro archivo con valores del constructor por default 
//     // que van a ser sobreescritos por los datos leidos desde el archivo con deserealizar()
//     ifstream in("flight.bin", ios::binary); //cargo los datos del archivo binario en el nuevo objeto flight_temp
//     flight_temp.deserializar(in);
//     in.close();

//     flight_temp.imprimir(); //muestro los datos recuperados del nuevo archivo
//     return 0;
// }