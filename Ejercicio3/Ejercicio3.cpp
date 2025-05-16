#include <iostream>
#include <concepts>
#include <type_traits>
#include <vector>
#include <string>
#include <map>
#include <memory>

using namespace std;

template <typename T>

class generar_vectores{
    private:
        vector<T> data;
    public:
        void agregar_valor(const T& value){
            data.push_back(value);
        }
        void procesar(const string& etiqueta) const{
            if constexpr (is_same_v<T, vector<int>>){
                cout << "  \""<<etiqueta<<"\":[" << endl;
                for (size_t i = 0; i < data.size(); ++i) {
                    cout << "  [";
                    for (size_t j = 0; j < data[i].size(); ++j) {
                        cout << data[i][j];
                        if (j < data[i].size() - 1) cout << ", ";
                    }
                    cout << "]";
                    if (i < data.size() - 1) cout << ",";
                    cout << endl;
                }
                cout << "  ]" << endl;
            }
            else if constexpr(is_same_v<T, double>){
                cout << "\""<<etiqueta<<"\":[";
                for (size_t i=0; i<data.size(); ++i){
                    cout<<data[i];
                    if (i<data.size()-1) cout<<", ";
                }
                cout << "]," << endl;
            }
            else if constexpr(is_same_v<T, string>){
                cout<< "  \""<<etiqueta<<"\":[";
                for (size_t i=0; i<data.size(); ++i){
                    cout<<"\""<<data[i]<<"\"";
                    if (i<data.size()-1) cout<<", ";
                }
                cout << "]," << endl;
            }
            else {
                cerr <<"No se pudo procesar este tipo de dato."<<endl;
            }
        }

};

template <typename T>
class asociar{
    private:
        map<string, unique_ptr<generar_vectores<T>>> elements;
    public:
        void add(const string&etiqueta, const T&value){
            if (!elements.count(etiqueta)) { //es true si no existe esa etiqueta en el map 
                elements[etiqueta] = make_unique<generar_vectores<T>>(); 
            }
            elements[etiqueta]->agregar_valor(value);
        }
        void procesar_json()const{
            for (const auto&[etiqueta, puntero] : elements){
                puntero->procesar(etiqueta);
            }
        }
};

int main() {
    asociar<double> doubles;
    asociar<string> palabras;
    asociar<vector<int>> listas;

    doubles.add("vec_doubles", 1.3);
    doubles.add("vec_doubles", 2.1);
    doubles.add("vec_doubles", 3.2);

    palabras.add("palabras", "Hola");
    palabras.add("palabras", "Mundo");

    listas.add("listas", {1, 2});
    listas.add("listas", {3, 4});

    cout << "{ ";
    doubles.procesar_json();
    palabras.procesar_json();
    listas.procesar_json();
    cout << "}" << endl;

    return 0;
}
