//Made By iH8s4N
//*Hubo unos errores en el sistema encargado de la revision de ciertos DNI
//*Por lo cual, se cito a las personas afectadas para que puedan acercarse 
//*a la SUNAT con el motivo de poder arreglar el problema de su Doc. Identidad.
//*Debido a este problema, La SUNAT tiene una extensa cola de casi 3 cuadras
//*Y la gente aun no sabe como poder organizarse. Se pide al ingeniero encargado
//*Crear un programa que cumpla las siguientes especificaciones para poder 
//*Resolver este asunto.

//!Cada persona sera simbolicamente representada como un Nodo
//*La estructura de persona (Nodo) a crear debe tener lo siguientes campos:
//? NOMBRE - APELLIDO  - DNI - EDAD - NIVELD DE PRIORIDAD
//?Cada dato sera ingresado por el usuario en consola mas no la edad ni
//?la prioridad ya que estas se generaran a nivel ramdom (Limitar Rango).

//*Se pide que se cree una cola de prioridad, donde :
//* la prioridad '1' seran los mayores de 55 anios
//* la prioridad '2' seran los discapacitados y/o embarazadas de cualquier edad
//* la prioridad '3' seran los personas de 18 a 54 anios

//!Puede escoger cualquier tipo de variable para poder ingresar la data
//!Ejemplo: string nombre; char nombre ...etc..etc;

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Nodo{
    string nombre;
    string appelido;
    int edad;
    string DNI;
    int nivelPrioridad;
    Nodo *sgte;

};

struct queue{

    Nodo *frente;
    Nodo *final;
};

void menu(){
    system("cls");
    cout<<"\n\n\tMENU DE COLA DE BANCO\n\n";
    cout<<"[1]. Ingresar Data de Persona\n";
    cout<<"[2]. Mostrar la cola \n";
    cout<<"[3]. Dar un orden de Prioridad\n";
    cout<<"[4]. Salir del menu\n\n";
    cout<<"Ingresar una opcion : ";
}
void pushData(Nodo *&, queue &);
bool is_null(queue &);
void read(queue &);
void priority(queue &);

int main(){

    srand (time(NULL));
    bool band = false;
    int opc = 0;
    Nodo *persona = NULL;
    struct queue cola;
    cola.frente = NULL;
    cola.final = NULL;

    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:cout<<"\n\n\tINGRESO DE USUARIO A LA COLA\n\n";
            pushData(persona,cola);
            system("pause");
            break;
        
        case 2:
            cout<<"\n\n\tMOSTRANDO COLA\n\n";
            read(cola);
            system("pause");
            break;
        
        case 3:cout<<"\n\n\tDANDO ORDEN DE PRIORIDAD\n\n";
            priority(cola);
            system("pause");
            break;

        case 4:cout<<"\n\nGRACIAS POR USAR EL PROGRAMA\n\n";
        band = true;
        }
        
    }while(band != true);

    return 0;
}


void pushData(Nodo *&nodoP, queue &cola){

    Nodo *persona = new Nodo();
    string name,apellido,dni;
    fflush(stdin);
    cout<<"Ingrese Nombre de usuario : ";
    fflush(stdin);
    getline(cin,name);
    cout<<"Ingrese Apellido de usuario : ";
    fflush(stdin);
    getline(cin,apellido);
    cout<<"Ingrese DNI de usuario : ";
    fflush(stdin);
    getline(cin,dni); 


    
    //*esta entre M y N =/   variable = (N-M+1) + M
    int priori = rand() % (3-1+1) + 1; 
    persona->nombre = name;
    persona->appelido = apellido;
    persona->DNI = dni;
    persona->nivelPrioridad = priori;

    if(persona->nivelPrioridad == 1){
        int edad = rand() % (80-55+1) + 55;
        persona->edad = edad;
    }
    else if(persona->nivelPrioridad == 2){
        int edad = rand() % (80-18+1) + 18;
        persona->edad = edad;
    }
    else{
        int edad = rand() % (54-18+1) + 18;
        persona->edad = edad;
    }

    persona->sgte = NULL;

    if(is_null(cola)){
        cola.frente = persona;
        cout<<"\n\nSe acaba de Crear una nueva cola\n\n";
    }else{
        cola.final->sgte =persona;
        cout<<"\n\nSe Agrego una nueva persona a la cola\n\n";
    }
    
    cola.final = persona;
    
}

bool is_null(queue &cola){
    if(cola.frente == NULL){
        return true;
    }else{
        return false;
    }
}

void read(queue &cola){
    Nodo *actual = new Nodo();

    actual = cola.frente;

    while(actual != NULL){

        cout<<"Nombre       :  "<<actual->nombre<<endl;
        cout<<"Apellido     :  "<<actual->appelido<<endl;
        cout<<"D.N.I        :  "<<actual->DNI<<endl;
        cout<<"Edad         :  "<<actual->edad<<endl;
        if(actual->nivelPrioridad == 1){
        cout<<"Prioridad [1]: Persona Mayor "<<endl<<endl; 
        }
        else if(actual->nivelPrioridad == 2){
            cout<<"Prioridad [2]: Persona Discapacitada "<<endl<<endl; 
        }
        else{
            cout<<"Prioridad [3]: Persona comun"<<endl<<endl; 
        }

        actual = actual->sgte;
    }
}

void priority(queue &cola){


    Nodo *aux = new Nodo();
    Nodo *aux2 = new Nodo();
    string aux_name;
    string aux_ape;
    int aux_age;
    string aux_dni;
    int aux_prio;

    aux = cola.frente;

    while(aux != NULL){

        aux2 = aux->sgte;
        while(aux2 != NULL){
            
            if(aux->nivelPrioridad > aux2->nivelPrioridad){
                aux_name = aux->nombre;
                aux_ape = aux->appelido;
                aux_dni = aux->DNI;
                aux_age = aux->edad;
                aux_prio = aux->nivelPrioridad;

                aux->nombre = aux2->nombre;
                aux->appelido = aux2->appelido;
                aux->DNI = aux2->DNI;
                aux->edad = aux2->edad;
                aux->nivelPrioridad = aux2->nivelPrioridad;
                
                aux2->nombre = aux_name;
                aux2->appelido = aux_ape;
                aux2->DNI = aux_dni;
                aux2->edad = aux_age;
                aux2->nivelPrioridad = aux_prio;
            }

            aux2 = aux2->sgte;
        }

    aux = aux->sgte;

    }
    cout<<"\n\nSE APLICO UNA PRIORIDAD A LA COLA\n\n";
}

