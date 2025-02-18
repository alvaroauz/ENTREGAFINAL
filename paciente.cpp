#include "paciente.h"
#include<iostream>

Paciente::Paciente (int id, const std::string& nombre, const std::string& direccion, int anioNacimiento, int telefono, const std::string& notas,const Fecha& fecha)
    : Persona(id, nombre, direccion, anioNacimiento){
    this->telefono=telefono;
    this->notas=notas;
    this->fechaRegistro=fecha;
} 

Paciente::Paciente(): Persona(){
    this->telefono=666666666;
    this->notas="-";
    Fecha fecha=Fecha(1,1,2025);
    this->fechaRegistro=fecha;
}

void Paciente::generarReporte(const std::string &comentario)const{
    std::cout<<"Comentario del paciente "<<this->nombre<<" con id <<"
    <<this->id<<": "<<comentario;
}

void Paciente::mostrarInformacion()const{
    Persona::mostrarInformacion();
    std::cout << "Telefono: "<<this->telefono<<"\n";
    std::cout << "Notas: "<<this->notas<<"\n";
}

std::string Paciente::getNotas() const{
    return this->notas;
}

void Paciente::setNotas(const std::string &notas){
    this->notas=notas;
}



int Paciente::getTelefono() const{
    return this->telefono;
}

void Paciente::setTelefono(int telefono) {
    this->telefono = telefono;
}

Fecha Paciente::getFechaRegistro() const {
    return this->fechaRegistro;
}

void Paciente::setFechaRegistro(const Fecha& fechaRegistro) {
    this->fechaRegistro = fechaRegistro;
}

void Paciente::modificarDatosPersonales(const std::string &direccion,int edad,const std::string &notas,int telefono){
    this->direccion=direccion;
    this->edad=edad;
    this->notas=notas;
    this->telefono=telefono;
}

void Paciente::mostrarHistorial() const {
    std::cout << "Historial Clínico de " << nombre << ":\n";
    for (const auto& registro : this->historialClinico) {
        registro.mostrarRegistro();
        std::cout << "------------------------------------\n";
    }
}

void Paciente::agregarRegistro(const RegistroClinico& registro) {
    this->historialClinico.push_back(registro);  // Agrega un nuevo registro al historial
}

int Paciente::numRegistros()const{
    return this->historialClinico.size();
}

std::vector<RegistroClinico> Paciente::obtenerRegitrosClinicos() const {
        return this->historialClinico;  // Devolvemos el vector de registros clinicos
    }

//funciones
void altaPaciente(std::vector<Paciente *>& pacientes,int id, const std::string& nombre, const std::string& direccion, int anioNacimiento, int telefono, const std::string &notas,const Fecha& fecha) {
    bool encontrado=false;
    size_t i=0;
    while(!encontrado && i<pacientes.size()){
        if(pacientes[i]->getId()==id){
            encontrado=true;
            std::cout << "Ya exite un paciente con con id: " << id << ".\n";
        }
        i++;
    }

    if (!encontrado) {
        Paciente* paciente= new Paciente(id, nombre, direccion, anioNacimiento,telefono,notas,fecha);
        pacientes.push_back(paciente);
        std::cout << "Paciente " << nombre << " dado de alta.\n";
    }
}

void bajaPaciente(std::vector<Paciente *>& pacientes, int id) {
    bool encontrado = false;
    size_t i = 0;
    while(!encontrado && i < pacientes.size()) {
        if(pacientes[i]->getId() == id) {
            std::string nombre = pacientes[i]->getNombre();
            delete pacientes[i];
            pacientes.erase(pacientes.begin() + i);
            encontrado = true;
            std::cout << "Paciente " << nombre << " dado de baja.\n";
        }
        i++;
    }

    if (!encontrado) {
        std::cout << "No se encontró el paciente con id: " << id << ".\n";
    }
}

void listarPorFechaRegistro(const std::vector<Paciente *>& pacientes, const Fecha& fecha){
    std::cout << "Listado de pacientes con fecha de registro: "<< fecha<< "\n";
    for (const auto& paciente : pacientes) {
        if (paciente->getFechaRegistro() == fecha) {
            std::cout<<"Nombre: "<<paciente->getNombre()<<"\n";
        }
    }
}
void busquedaPorNombre(const std::vector<Paciente *>& pacientes, const std::string& nombre){
    bool encontrado=false;
    size_t i=0;
    while(!encontrado && i<pacientes.size()){
        if(pacientes[i]->getNombre()==nombre){
            encontrado=true;
            std::cout<<"Paciente con nombre "<<nombre<<" encontrado.\n";
            pacientes[i]->mostrarInformacion();
        }
        i++;
    }

    if (!encontrado) {
        std::cout << "No se encontró el paciente con nombre: " << nombre << ".\n";
    }
}

void busquedaPorId(const std::vector<Paciente *>& pacientes, int id){
    bool encontrado=false;
    size_t i=0;
    while(!encontrado && i<pacientes.size()){
        if(pacientes[i]->getId()==id){
            encontrado=true;
            std::cout<<"Paciente con ID "<<id<<" encontrado.\n";
            pacientes[i]->mostrarInformacion();
        }
        i++;
    }

    if (!encontrado) {
        std::cout << "No se encontró el paciente con ID: " << id << ".\n";
    }
}

bool existePacienteId(const std::vector<Paciente *>& pacientes, int id){
    bool existe=false;
    size_t i=0;
    while(!existe && i<pacientes.size()){
        if(pacientes[i]->getId()==id){
            existe=true;
        }
        i++;
    }

    if (!existe) {
        std::cout << "No se encontró el paciente con ID: " << id << ".\n";
    }

    return existe;
}

void mostrarListaPacientes(const std::vector<Paciente *>& pacientes){
    for (const auto& paciente : pacientes) {
        paciente->mostrarInformacion();
    }
}