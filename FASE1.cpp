#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Clase Producto con atributos privados
class Producto 
{
private:
    string nombre;
    string descripcion;
    float precio;
    int cantidad;

public:
    // Constructor
    Producto(string nom, string desc, float pre, int cant) 
    {
        nombre = nom;
        descripcion = desc;
        precio = pre;
        cantidad = cant;
    }

    // Métodos get
    string getNombre() { return nombre; }
    string getDescripcion() { return descripcion; }
    float getPrecio() { return precio; }
    int getCantidad() { return cantidad; }

    // Métodos set
    void setNombre(string nom) { nombre = nom; }
    void setDescripcion(string desc) { descripcion = desc; }
    void setPrecio(float pre) { precio = pre; }
    void setCantidad(int cant) { cantidad = cant; }
};

// Clase Tienda que contiene un vector dinámico de productos
class Tienda 
{
private:
    vector<Producto*> inventario;

public:
    // Agrega producto al inventario
    void agregarProducto(Producto* p) 
    {
        inventario.push_back(p);
    }

    // Muestra todos los productos
    void mostrarProductos() 
    {
        if (inventario.empty()) 
        {
            cout << "Inventario vacío.\n";
        } 
        else 
        {
            for (int i = 0; i < inventario.size(); i++) 
            {
                cout << "\nProducto " << i + 1 << ":\n";
                cout << "Nombre: " << inventario[i]->getNombre() << endl;
                cout << "Descripción: " << inventario[i]->getDescripcion() << endl;
                cout << "Precio: S/ " << inventario[i]->getPrecio() << endl;
                cout << "Cantidad: " << inventario[i]->getCantidad() << endl;
            }
        }
    }

    // Elimina producto por nombre
    void eliminarProducto(string nombreBuscado) 
    {
        for (int i = 0; i < inventario.size(); i++) 
        {
            if (inventario[i]->getNombre() == nombreBuscado) 
            {
                delete inventario[i]; // Liberar memoria
                inventario.erase(inventario.begin() + i); // Eliminar del vector
                cout << "Producto '" << nombreBuscado << "' eliminado.\n";
                return;
            }
        }
        cout << "Producto no encontrado.\n";
    }

    // Modifica la cantidad de un producto
    void modificarCantidad(string nombreBuscado, int nuevaCantidad) 
    {
        for (int i = 0; i < inventario.size(); i++) 
        {
            if (inventario[i]->getNombre() == nombreBuscado) 
            {
                inventario[i]->setCantidad(nuevaCantidad);
                cout << "Cantidad actualizada a " << nuevaCantidad << " para '" << nombreBuscado << "'.\n";
                return;
            }
        }
        cout << "Producto no encontrado.\n";
    }

};

// Función principal para probar la tienda
int main() 
{
    Tienda miTienda;

    // Crear productos usando memoria dinámica
    Producto* p1 = new Producto("Laptop", "Laptop de 15 pulgadas", 2500.0, 10);
    Producto* p2 = new Producto("Smartphone", "Celular 128GB", 1200.0, 20);
    Producto* p3 = new Producto("Libro", "Curso de C++", 80.0, 50);

    // Agregar al inventario
    miTienda.agregarProducto(p1);
    miTienda.agregarProducto(p2);
    miTienda.agregarProducto(p3);

    // Mostrar inventario inicial
    cout << "--- Inventario Inicial ---\n";
    miTienda.mostrarProductos();

    // Eliminar producto
    miTienda.eliminarProducto("Smartphone");

    // Mostrar inventario tras eliminar
    cout << "\n--- Inventario Después de Eliminar ---\n";
    miTienda.mostrarProductos();

    // Modificar cantidad
    miTienda.modificarCantidad("Laptop", 5);

    // Mostrar inventario final
    cout << "\n--- Inventario Final ---\n";
    miTienda.mostrarProductos();

    return 0;
}
