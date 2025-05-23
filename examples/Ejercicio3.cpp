#include "Asociar.hpp"
#include <string>
#include <vector>

int main() {
    Asociar<double> doubles;
    Asociar<string> palabras;
    Asociar<vector<int>> listas;

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
