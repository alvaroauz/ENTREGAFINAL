#include "medico.h"
#include<iostream>

Medico::Medico(int id, const std::string& nombre, const std::string& direccion, int anioNacimiento,const std::string &especialidad ,bool disponible)
    : Persona(id, nombre, direccion, anioNacimiento){
        this->especialidad=especialidad;
        this->disponible=disponible;
    }

Medico::Medico():Persona(){
    this->especialidad="-";
    this->disponible=false;
}

std::string Medico::getEspecialidad() const{
    return this->especialidad;
}

void Medico::setEspecialidad(const std::string &especialidad){
    this->especialidad=especialidad;
}

bool Medico::getDisponible() const{
    return this->disponible;
}

void Medico::setDisponibilidad(bool disponible){
    this->disponible=disponible;
}

void Medico::mostrarInformacion()const{
    Persona::mostrarInformacion();
    std::cout << "Especialidad: "<<this->especialidad<<"\n";
    if(this->disponible){
        std::cout << "Disponible: Si\n";
    }
    else{
       std::cout << "Disponible: No\n"; 
    }
}

void Medico::generarReporte(const std::string &comentario)const{
    std::cout<<"Comentario del medico "<<this->nombre<<" con la especialidad "
    <<this->especialidad<<": "<<comentario;
}

void altaMedico(std::vector<Medico *>& medicos,int id, const std::string& nombre, const std::string& direccion, int anioNacimiento,const std::string &especialidad,bool disponible) {
    bool encontrado=false;
    size_t i=0;
    while(!encontrado && i<medicos.size()){
        if(medicos[i]->getId()==id){
            encontrado=true;
            std::cout << "Ya exite un medico con con id: " << id << ".\n";
        }
        i++;
    }

    if (!encontrado) {
        Medico* medico= new Medico(id, nombre, direccion, anioNacimiento,especialidad ,disponible);
        medicos.push_back(medico);
        std::cout << "Médico " << nombre << " dado de alta con especialidad " << especialidad << ".\n";
    }

}

void bajaMedico(std::vector<Medico*>& medicos, int id) {
    bool encontrado = false;
    size_t i = 0;
    while (!encontrado && i < medicos.size()) {
        if (medicos[i]->getId() == id) {
            std::string nombre = medicos[i]->getNombre(); 
            delete medicos[i];
            medicos.erase(medicos.begin() + i);
            encontrado = true;
            std::cout << "Médico " << nombre << " dado de baja.\n";
        }
        i++;
    }

    if (!encontrado) {
        std::cout << "No se encontró el médico con id: " << id << ".\n";
    }
}

void listarPorEspecialidad(const std::vector<Medico *>& medicos, const std::string& especialidad) {
    std::cout << "Listado de médicos con especialidad " << especialidad << ":\n";
    for (const auto& medico : medicos) {
        if (medico->getEspecialidad() == especialidad) {
            std::cout<<"Nombre: "<<medico->getNombre()<<"\n";
        }
    }
}

void listarPorDisponibilidad(const std::vector<Medico *>& medicos) {
   std::cout << "Listado de médicos disponibles:\n";
    for (const auto& medico : medicos) {
        if (medico->getDisponible()) {
            std::cout<<"Nombre: "<<medico->getNombre()<<"\n";
        }
    }
}

bool existeMedicoId(const std::vector<Medico *>& medicos, int id){
    bool existe=false;
    size_t i=0;
    while(!existe && i<medicos.size()){
        if(medicos[i]->getId()==id){
            existe=true;
        }
        i++;
    }

    if (!existe) {
        std::cout << "No se encontró el medico con ID: " << id << ".\n";
    }

    return existe;
}

void mostrarListaMedicos(const std::vector<Medico *>& medicos){
    for (const auto& medico : medicos) {
        medico->mostrarInformacion();
    }
}