//*¿En una cola del banco se desea saber el nombre de todas las personas
//*que son mayores a 18 años. 
//*Desarrolle un programa en c que soluciones el problema utilizando 
//*la estrutura Cola
//*y sus propiedades en c++?. Gracias por su tiempo

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


struct Nodo{

    string usuario;
    int edad;
    Nodo *sgte;

};

struct queue{

    Nodo *frente;
    Nodo *final;
};

void push(Nodo *&, queue &);
bool vacio(queue &);
void read(queue &);
void popOverAge(queue &);
void popTenAger(queue &);
void pop(queue &);

void menu(){
    system("cls");
    cout<<"\n\n\t MENU DE BANCO \n\n";
    cout<<"[1]. Ingresar un Usuario "<<endl;
    cout<<"[2]. Mostrar todos los datos"<<endl;
    cout<<"[3]. Mostrar Mayores de 18 anios"<<endl;
    cout<<"[4]. Mostrar Menores de Edad"<<endl;
    cout<<"[5]. Borrar un Usuario"<<endl;
    cout<<"[6]. Salir "<<endl;
    cout<<"\nIngresa una opcion : ";

}

int main(){

    Nodo *persona = NULL;
    struct queue cola;
    cola.frente = NULL;
    cola.final = NULL;
    bool band = false;
    int opc;

    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:cout<<"\n\n\t[1]. INGRESANDO UN USUARIO \n\n";
            push(persona,cola); system("pause");
            break;

        case 2:cout<<"\n\n\t[2]. MOSTRANDO DATOS DE USUARIOS\n\n";
            read(cola); system("pause");
            break;

        case 3:cout<<"\n\n\t[3]. MOSTRANDO DATOS DE USUARIOS MAYORES DE EDAD\n\n";
            popOverAge(cola);
            system("pause");
            break;

        case 4:cout<<"\n\n\t[4]. MOSTRANDO DATOS DE USUARIOS MENORES DE EDAD\n\n";
            popTenAger(cola);
            system("pause");
            break;

        case 5:
            if(cola.frente != NULL){
            pop(cola);
            }else{
                cout<<"\n\nNo hay ningun user en la Cola\n\n";
            }
            system("pause");
            break;

        case 6:cout<<"\n\n\t[6]. GRACIAS POR USAR EL PROGRAMA\n\n";
            system("pause");
            band = true;
            break;
        }
    }while(band != true);

    return 0;
}


void push(Nodo *&nodo, queue &cola){

    string nombre;
    int edad;
    Nodo *nuevo = new Nodo();
    cout<<"Ingresa Nombre de La Persona : ";
    fflush(stdin);
    getline(cin,nuevo->usuario);
    cout<<"Ingresa Edad de La persona   : ";
    cin>>nuevo->edad;
    nuevo->sgte = NULL;

    if(vacio(cola)){
        cola.frente = nuevo;
        cout<<"\n\nSe creo una Nueva Cola\n\n";
    }else{
        cola.final->sgte = nuevo;
        cout<<"\n\nSe agrego un nuevo user a la Cola\n\n";
    }

    cola.final = nuevo;

}

bool vacio(queue &cola){
    
    if(cola.frente == NULL){
        return true;
    }else{
        return false;
    }
}

void read(queue &cola){

    Nodo *actual = cola.frente;

    while(actual != NULL){

        cout<<"Usuario  :   "<<actual->usuario<<endl;
        cout<<"Edad     :   "<<actual->edad<<endl<<endl;

        actual = actual->sgte;
    }

}

void popOverAge(queue &cola){

    Nodo *actual = cola.frente;

    while(actual != NULL){
        if(actual->edad >= 18){
            
            cout<<"Usuario  :   "<<actual->usuario<<endl;
            cout<<"Edad     :   "<<actual->edad<<endl<<endl;
        }
        actual = actual->sgte;
    }
}

void popTenAger(queue &cola){

    Nodo *actual = cola.frente;

    while(actual != NULL){
        if(actual->edad < 18){
            
            cout<<"Usuario  :   "<<actual->usuario<<endl;
            cout<<"Edad     :   "<<actual->edad<<endl<<endl;
        }
        actual = actual->sgte;
    }
}

void pop(queue &cola){
    cout<<"\n\n\t[5]. BORRANDO ULTIMO USUARIO DE LA COLA \n\n";
    Nodo *aux;
    int edad;
    string nombre;

    aux = cola.frente;

    edad= aux->edad;
    nombre = aux->usuario;

    cola.frente = cola.frente->sgte;
    delete aux;
    cout<<"\nUser Borrado con Exito\n\n";
}