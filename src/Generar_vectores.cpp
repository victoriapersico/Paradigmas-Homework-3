#ifndef GENERAR_VECTORES_CPP
#define GENERAR_VECTORES_CPP

#include "../headers/Generar_vectores.hpp"

//agrega un valor al vector de cada instancia de Generar_vectores<T>
template <typename T>
void Generar_vectores<T>::agregar_valor(const T& value){
    data.push_back(value);
}
//procesa los datos según su tipo y los imprime siguiendo el formato JSON
//usando if constexpr determina en tiempo de compilación el tipo de T
template <typename T>
void Generar_vectores<T>::procesar(const string& etiqueta) const{
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

#endif