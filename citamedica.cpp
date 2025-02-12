#include "citaMedica.h"
#include<iostream>
#include <algorithm> 

CitaMedica::CitaMedica(int id,const Paciente &paciente,const Medico &medico, const Fecha &fecha,bool urgente){
    this->id=id;
    this->paciente=paciente;
    this->medico=medico;
    this->fecha=fecha;
    this->urgente=urgente;
}

void CitaMedica::mostrarCita() const{
    std::cout<<"\nId: "<<this->paciente.getId();
    std::cout<<"\nPaciente: "<<this->paciente.getNombre();
    std::cout<<"\nMedico: "<<this->medico.getNombre();
    std::cout<<"\nFecha: "<<this->fecha;
    if(this->urgente){
        std::cout<<"\nUrgente: Si\n";
    }
    else{
        std::cout<<"\nUrgente: No\n";
    }
}

int CitaMedica::getId(){
    return this->id;
}

void CitaMedica::setId(int id){
    this->id=id;
}

Paciente CitaMedica::getPaciente() const{
    return this->paciente;
}
void CitaMedica::setPaciente(const Paciente &paciente){
    this->paciente=paciente;
}
Medico CitaMedica::getMedico() const{
    return this->medico;
}
void CitaMedica::setMedico(const Medico &medico){
    this->medico=medico;
}
Fecha CitaMedica::getFecha() const{
    return this->fecha;
}
void CitaMedica::setFecha(const Fecha &fecha){
    this->fecha=fecha;
}
bool CitaMedica::getUrgente() const{
    return this->urgente;
}
void CitaMedica::setUrgente(bool urgente){
    this->urgente=urgente;
}

//funciones

void asignarCita(std::vector<CitaMedica *>& citas,int id,const Paciente &paciente,const Medico &medico, const Fecha &fecha,bool urgente){
    bool encontrado=false;
    size_t i=0;
    while(!encontrado && i<citas.size()){
        if(citas[i]->getId()==id){
            encontrado=true;
            std::cout << "Ya exite una cita con con id: " << id << ".\n";
        }
        i++;
    }

    if (!encontrado) {
        CitaMedica* cita= new CitaMedica(id,paciente,medico, fecha,urgente);
        citas.push_back(cita);
        std::cout << "Cita con id " << id << " agregada.\n";
    }
}

// Comparador para ordenar las citas
bool compararCitas(const CitaMedica *cita1, const CitaMedica *cita2) {
    bool cita1delante=false;
    if (cita1->getUrgente()) {
        cita1delante=true;
    }
    else if(!cita1->getUrgente() && !cita2->getUrgente()){
        if(cita1->getFecha()<cita2->getFecha()){
            cita1delante=true;
        }
    }

    return cita1delante;
}

// Función para ordenar las citas médicas
void ordenarCitasPorUrgenciaYFecha(std::vector<CitaMedica *>& citas) {
    std::sort(citas.begin(), citas.end(), compararCitas);
}

void cancelarCita(std::vector<CitaMedica *>& citas, int id) {
    bool encontrado = false;
    size_t i = 0;
    while(!encontrado && i < citas.size()) {
        if(citas[i]->getId() == id) {
            int citaId = citas[i]->getId(); // Guardamos el ID antes de borrar
            delete citas[i];
            citas.erase(citas.begin() + i);
            encontrado = true;
            std::cout << "Cita con Id " << citaId << " cancelada.\n";
        }
        i++;
    }

    if (!encontrado) {
        std::cout << "No se encontró la cita con id: " << id << ".\n";
    }
}

void modificarCita(std::vector<CitaMedica *>& citas, int id,const Fecha &fecha,bool urgente) {
    bool encontrado=false;
    size_t i=0;
    while(!encontrado && i<citas.size()){
        if(citas[i]->getId()==id){
            citas[i]->setFecha(fecha);
            citas[i]->setUrgente(urgente);
            encontrado=true;
            std::cout << "Cita con Id " << citas[i]->getId() << " modificada.\n";
        }
        i++;
    }

    if (!encontrado) {
        std::cout << "No se encontró la cita con id: " << id << ".\n";
    }
}

void mostrarCitas(const std::vector<CitaMedica*>& citas) {
    for (const auto& cita : citas) {
        cita->mostrarCita();
        std::cout << "-----------------------------------------------\n";
    }
}