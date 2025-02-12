#include "persona.h"

// Constructor
Persona::Persona(int id, const std::string& nombre, const std::string& direccion, int anioNacimiento) {
	this->id=id;
    this->nombre = nombre;
	this->direccion = direccion;
	this->anioNacimiento = anioNacimiento;

	this->calcularEdad();
}

Persona::Persona(){
    this->id=-1;
    this->nombre = "-";
	this->direccion = "-";
	this->anioNacimiento = 2025;
    this->edad=0;
}

void Persona::calcularEdad() {
	this->edad = ANIO_ACTUAL - this->anioNacimiento;
}

void Persona::mostrarInformacion()const {
    std::cout << "Id: "<<this->id<<"\n";
	std::cout << "Nombre: " << this->nombre << "\n";
	std::cout << "Edad: " << this->edad << "\n";
	std::cout << "Direccion: " << this->direccion<<"\n";
}

//getters y setters
void Persona::setId(int id){
    this->id=id;
}

int Persona::getId() const{
    return this->id;
}

void Persona::setNombre(const std::string &nombre){
    this->nombre=nombre;
}

std::string Persona::getNombre() const{
    return this->nombre;
}

void Persona::setEdad(int edad){
    this->edad=edad;
}

int Persona::getEdad() const{
    return this->edad;
}

void Persona::setDireccion(const std::string &direccion){
    this->direccion=direccion;
}

std::string Persona::getDireccion() const{
    return this->direccion;
}

void Persona::setAnioNacimiento(int anioNacimiento){
    this->anioNacimiento=anioNacimiento;
}

int Persona::getAnioNacimiento() const{
    return this->anioNacimiento;
}