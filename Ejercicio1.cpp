#include <iostream>
#include <string>
using namespace std;

// Estructura Producto
struct Producto
{
    int Codigo;
    string Nombre;
    float Precio;
    int CantidadStock;
};

// Función para mostrar todos los productos
void MostrarProductos(const Producto productos[], int cantidad)
{
    cout << "\n======= LISTA DE PRODUCTOS =======\n";
    if (cantidad == 0)
    {
        cout << "No hay productos registrados.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++)
    {
        cout << "Codigo: " << productos[i].Codigo
            << "\nNombre: " << productos[i].Nombre
            << "\nPrecio: $" << productos[i].Precio
            << "\nCantidad en stock: " << productos[i].CantidadStock
            << "\n----------------------------------\n";
    }
}

// Función para buscar producto por código
void BuscarProductoPorCodigo(const Producto productos[], int cantidad, int codigo)
{
    bool encontrado = false;
    for (int i = 0; i < cantidad; i++)
    {
        if (productos[i].Codigo == codigo)
        {
            cout << "\n=== PRODUCTO ENCONTRADO ===\n";
            cout << "Codigo: " << productos[i].Codigo
                << "\nNombre: " << productos[i].Nombre
                << "\nPrecio: $" << productos[i].Precio
                << "\nCantidad en stock: " << productos[i].CantidadStock
                << "\n----------------------------------\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado)
    {
        cout << "\nProducto con codigo " << codigo << " no encontrado.\n";
    }
}

// Función para calcular valor total del inventario
float CalcularValorInventario(const Producto productos[], int cantidad)
{
    float total = 0;
    for (int i = 0; i < cantidad; i++)
    {
        total += productos[i].Precio * productos[i].CantidadStock;
    }
    return total;
}

// Función para registrar un producto
Producto RegistrarProducto()
{
    Producto p;
    cout << "\n=== REGISTRAR PRODUCTO ===\n";
    cout << "Codigo: ";
    cin >> p.Codigo;
    cin.ignore();

    cout << "Nombre: ";
    getline(cin, p.Nombre);

    cout << "Precio: ";
    cin >> p.Precio;

    cout << "Cantidad en stock: ";
    cin >> p.CantidadStock;

    return p;
}

int main()
{
    Producto productos[10];
    int cantidad = 0;
    int opcion;

    do
    {
        cout << "\n--- MENU INVENTARIO ---\n";
        cout << "1. Registrar producto\n";
        cout << "2. Mostrar todos los productos\n";
        cout << "3. Buscar producto por codigo\n";
        cout << "4. Calcular valor total del inventario\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            if (cantidad < 10)
            {
                productos[cantidad] = RegistrarProducto();
                cantidad++;
            }
            else
            {
                cout << "Inventario lleno (maximo 10 productos).\n";
            }
            break;
        case 2:
            MostrarProductos(productos, cantidad);
            break;
        case 3:
        {
            int codigo;
            cout << "\n--- BUSQUEDA PRODUCTO ---\n";
            cout << "Ingrese el codigo del producto: ";
            cin >> codigo;
            BuscarProductoPorCodigo(productos, cantidad, codigo);
            break;
        }
        case 4:
        {
            float total = CalcularValorInventario(productos, cantidad);
            cout << "\n--- VALOR TOTAL DE INVENTARIO ---\n";
            cout << "Valor total del inventario: $" << total << "\n";
            break;
        }
        case 5:
            cout << "Nos vemos.\n";
            break;
        default:
            cout << "Opcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
