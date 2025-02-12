#include<iostream>
#include<vector>
#include<fstream>
#include <algorithm> 
#include <iomanip>

#include "medico.h"
#include "paciente.h"
#include "citaMedica.h"


int menuPrincipal(){
    int opcion;
    do{
        std::cout<<"---------Menu principal---------\n";
        std::cout<<"1. Gestion de pacientes\n";
        std::cout<<"2. Gestion de medicos\n";
        std::cout<<"3. Gestion de citas\n";
        std::cout<<"4. Guardar\n";
        std::cout<<"0. Salir\n";
        std::cout<<"Opcion: ";
        std::cin>>opcion;
    }while(opcion<0 || opcion>4);

    return opcion;
}

int menuPacientes(){
    int opcion;
    do{
        std::cout<<"---------Menu pacientes---------\n";
        std::cout<<"1. Alta de pacientes\n";
        std::cout<<"2. Baja de pacientes\n";
        std::cout<<"3. Modificación de datos personales.\n";
        std::cout<<"4. Búsqueda de pacientes por nombre.\n";
        std::cout<<"5. Búsqueda de pacientes por id.\n";
        std::cout<<"6. Búsqueda de pacientes por fecha de ingreso.\n";
        std::cout<<"7. Mostrar historial clinico.\n";
        std::cout<<"8. Aniadir registro al historial clinico.\n";
        std::cout<<"9. Lista de pacientes.\n";
        std::cout<<"0. Salir\n";
        std::cout<<"Opcion: ";
        std::cin>>opcion;
    }while(opcion<0 || opcion > 9);

    return opcion;
}

int menuMedicos(){
    int opcion;
    do{
        std::cout<<"---------Menu medicos---------\n";
        std::cout<<"1. Alta de medicos\n";
        std::cout<<"2. Baja de medicos\n";
        std::cout<<"3. Listado de médicos por especialidad\n";
        std::cout<<"4. Listado de médicos por disponibilidad.\n";
        std::cout<<"5. Mostrar informacion de un medico\n";
        std::cout<<"6. Lista de medicos\n";
        std::cout<<"0. Salir\n";
        std::cout<<"Opcion: ";
        std::cin>>opcion;
    }while(opcion<0 || opcion > 6);

    return opcion;
}

int menuCitas(){
    int opcion;
    do{
        std::cout<<"---------Menu citas---------\n";
        std::cout<<"1. Asignacion de citas\n";
        std::cout<<"2. Ordenar citas\n";
        std::cout<<"3. Cancelacion de citas\n";
        std::cout<<"4. Modificacion de citas.\n";
        std::cout<<"5. Mostrar citas.\n";
        std::cout<<"0. Salir\n";
        std::cout<<"Opcion: ";
        std::cin>>opcion;
    }while(opcion<0 || opcion > 5);

    return opcion;
}

int main(int argc, char** argv) {
    int idCita = 0;
    std::vector<Medico *> medicos;
    std::vector<Paciente *> pacientes;
    std::vector<CitaMedica *> citas;

    int opcionMenuPrincipal,opcionGestionPacientes,opcionGestionMedicos,opcionGestionCitas;
    int idPaciente,anioNacimiento,dia, mes, anio,telefonoPaciente,edadPaciente;
    int idMedico,anioNacimientoMedico;
    int idCita;
    bool urgente;
    std::string nombrePaciente,direccionPaciente,notas;
    std::string diagnostico, tratamiento, observacion;
    std::string nombreMedico,direccionMedico,especialidad,disponible;
    std::string aux;
    char respuestaUrgente;
    Fecha fecha;
    RegistroClinico registro;
    int numRegistros;
    if(argc > 1){
        std::cout<<"El fichero de carga es "<<argv[1]<<"\n";
        std::ifstream lectura;
        lectura.open("backup.txt");
        if(lectura.is_open()){
            lectura>>aux;//--medicos--
            lectura>>idMedico;
            while(idMedico!=-1){//mientras no llegues al centinela
                lectura>>nombreMedico;
                lectura>>direccionMedico;
                lectura>>anioNacimientoMedico;
                lectura>>especialidad;
                lectura>>disponible;
                if(disponible=="Si"){
                    altaMedico(medicos,idMedico,nombreMedico,direccionMedico,anioNacimientoMedico,especialidad,true);
                }
                else{
                    altaMedico(medicos,idMedico,nombreMedico,direccionMedico,anioNacimientoMedico,especialidad,false);
                }
                lectura>>idMedico;
            }
            lectura>>aux; //--pacientes--
            lectura>>idPaciente;
            while(idPaciente!=-1){
                lectura>>nombrePaciente;
                lectura>>direccionPaciente;
                lectura>>anioNacimiento;
                lectura>>telefonoPaciente;
                lectura>>notas;
                lectura>>dia;
                lectura>>mes;
                lectura>>anio;
                fecha=Fecha(dia,mes,anio);
                altaPaciente(pacientes,idPaciente,nombrePaciente,direccionPaciente,anioNacimiento, telefonoPaciente,notas,fecha);
                getline(lectura,aux); //historial clinico del paciente 0:
                lectura>>numRegistros;
                lectura>>aux; //registros
                for(int i=0;i<numRegistros;i++){
                    lectura>>dia;
                    lectura>>mes;
                    lectura>>anio;
                    lectura>>diagnostico;
                    lectura>>tratamiento;
                    lectura>>observacion;
                }
                lectura>>idPaciente;
            }
            lectura>>aux; //--citas--
            while(!lectura.eof()){
                lectura>>idPaciente;
                lectura>>idMedico;
                lectura>>dia;
                lectura>>mes;
                lectura>>anio;
                lectura>>respuestaUrgente;
                if(respuestaUrgente=='S'){
                    urgente=true;
                }
                else{
                    urgente=false;
                }
                fecha=Fecha(dia,mes,anio);
                if(existeMedicoId(medicos,idMedico) && existePacienteId(pacientes,idPaciente)){
                    asignarCita(citas,idCita,*pacientes[idPaciente],*medicos[idMedico], fecha,urgente);
                }
                else{
                    std::cout<<"No se ha agregado ninguna cita\n";
                }
                lectura>>idCita;
            }
            lectura.close();
            std::cout<<"Fichero cargado con exito\n";
        }
        else{
            std::cout<<"Error de apertura del fichero "<<argv[1]<<"\n";
        }
        
    }
    else{
        std::cout<<"No hay fichero de carga\n";
    }
    opcionMenuPrincipal=menuPrincipal();
    while(opcionMenuPrincipal!=0){
        switch(opcionMenuPrincipal){
            case 1:
                opcionGestionPacientes=menuPacientes();
                switch(opcionGestionPacientes){
                    case 1:
                        std::cout<<"Introduce el id del paciente: ";
                        std::cin>>idPaciente;
                        std::cout<<"Introduce el nombre del paciente: ";
                        std::cin>>nombrePaciente;
                        std::cout<<"Introduce la direccion del paciente: ";
                        std::cin>>direccionPaciente;
                        std::cout<<"Introduce el anio de nacimiento del paciente: ";
                        std::cin>>anioNacimiento;
                        std::cout<<"Introduce el telefono del paciente: ";
                        std::cin>>telefonoPaciente;
                        std::cout<<"Introduce la nota del paciente: ";
                        std::cin>>notas;
                        std::cout<<"Introduce el dia de ingreso: ";
                        std::cin>>dia;
                        std::cout<<"Introduce el mes de ingreso: ";
                        std::cin>>mes;
                        std::cout<<"Introduce el anio de ingreso: ";
                        std::cin>>anio;
                        fecha=Fecha(dia,mes,anio);
                        altaPaciente(pacientes,idPaciente,nombrePaciente,direccionPaciente,anioNacimiento, telefonoPaciente,notas,fecha);
                    break;
                    case 2:
                        std::cout<<"Id de paciente al que quieres dar baja: ";
                        std::cin>>idPaciente;
                        bajaPaciente(pacientes,idPaciente);
                    break;
                    case 3:
                        std::cout<<"Introduce el id del paciente del que quieres modificar informacion: ";
                        std::cin>>idPaciente;
                        std::cout<<"Introduce la nueva direccion: ";
                        std::cin>>direccionPaciente;
                        std::cout<<"Introduce la nueva edad del paciente: ";
                        std::cin>>edadPaciente;
                        std::cout<<"Introduce ela nueva nota del paciente: ";
                        std::cin>>notas;
                        std::cout<<"Introduce el nuevo telefono del paciente: ";
                        std::cin>>telefonoPaciente;
                        pacientes[idPaciente]->modificarDatosPersonales(direccionPaciente,edadPaciente,notas,telefonoPaciente);
                    break;
                    case 4:
                        std::cout<<"Introduce el nombre del paciente a buscar: ";
                        std::cin>>nombrePaciente;
                        busquedaPorNombre(pacientes,nombrePaciente);
                    break;
                    case 5:
                        std::cout<<"Introduce el id del paciente a buscar: ";
                        std::cin>>idPaciente;
                        busquedaPorId(pacientes,idPaciente);
                    break;
                    case 6:
                        std::cout<<"Introduce el anio de ingreso del paciente a buscar: ";
                        std::cin>>anio;
                        std::cout<<"Introduce el mes de ingreso del paciente a buscar: ";
                        std::cin>>mes;
                        std::cout<<"Introduce el dia de ingreso del paciente a buscar: ";
                        std::cin>>dia;
                        fecha=Fecha(dia,mes,anio);
                        listarPorFechaRegistro(pacientes,fecha);
                    break;
                    case 7:
                        std::cout<<"Introduce el id del paciente del que queires mostrar el historial clinico: ";
                        std::cin>>idPaciente;
                        pacientes[idPaciente]->mostrarHistorial();
                    break;
                    case 8:
                        std::cout<<"Introduce el id del paciente al que quieres agregar un nuevo registro: ";
                        std::cin>>idPaciente;
                        std::cout<<"Introduce el anio: ";
                        std::cin>>anio;
                        std::cout<<"Introduce el mes: ";
                        std::cin>>mes;
                        std::cout<<"Introduce el dia: ";
                        std::cin>>dia;
                        std::cout<<"Introduce el diagnostico del paciente: ";
                        std::cin>>diagnostico;
                        std::cout<<"Introduce el tratamiento del paciente: ";
                        std::cin>>tratamiento;
                        std::cout<<"Introduce la observacion del paciente: ";
                        std::cin>>observacion;
                        fecha=Fecha(dia,mes,anio);
                        registro=RegistroClinico(fecha,diagnostico,tratamiento,observacion);
                        pacientes[idPaciente]->agregarRegistro(registro);
                    break;
                    case 9:
                        mostrarListaPacientes(pacientes);
                    break;
                }
            break;
            case 2:
            opcionGestionMedicos=menuMedicos();
                switch(opcionGestionMedicos){
                    case 1:
                        std::cout<<"Introduce el id del medico: ";
                        std::cin>>idMedico;
                        std::cout<<"Introduce el nombre del medico: ";
                        std::cin>>nombreMedico;
                        std::cout<<"Introduce la direccion del medico: ";
                        std::cin>>direccionMedico;
                        std::cout<<"Introduce la especialidad del medico: ";
                        std::cin>>especialidad;
                        std::cout<<"Introduce el anio de nacimiento del medico: ";
                        std::cin>>anioNacimientoMedico;
                        altaMedico(medicos,idMedico,nombreMedico,direccionMedico,anioNacimientoMedico,especialidad,true);
                    break;
                    case 2:
                        std::cout<<"Id del medico al que quieres dar baja: ";
                        std::cin>>idMedico;
                        bajaMedico(medicos,idMedico);
                    break;
                    case 3:
                        std::cout<<"Introduce la especialidad a buscar: ";
                        std::cin>>especialidad;
                        listarPorEspecialidad(medicos,especialidad);
                    break;
                    case 4:
                        listarPorDisponibilidad(medicos);
                    break;
                    case 5:
                    std::cout<<"Introduce el id del medico del que queires mostrar su informacion: ";
                        std::cin>>idMedico;
                        medicos[idMedico]->mostrarInformacion();
                    break;
                    case 6:
                        mostrarListaMedicos(medicos);
                    break;
                }
            break;
            case 3:
            opcionGestionCitas=menuCitas();
                switch(opcionGestionCitas){
                    case 1:
                        std::cout<<"Introduce el id de la cita que quieres asignar: ";
                        std::cin>>idCita;
                        std::cout<<"Introduce el id de el paciente que quieres asignar: ";
                        std::cin>>idPaciente;
                        std::cout<<"Introduce el id de el medico que quieres asignar: ";
                        std::cin>>idMedico;
                        std::cout<<"Introduce el nuevo dia de la cita: ";
                        std::cin>>dia;
                        std::cout<<"Introduce el nuevo mes de la cita: ";
                        std::cin>>mes;
                        std::cout<<"Introduce el nuevo anio de la cita: ";
                        std::cin>>anio;
                        std::cout<<"Introduce si es urgente o no (S/N): ";
                        std::cin>>respuestaUrgente;
                        if(respuestaUrgente=='S'){
                            urgente=true;
                        }
                        else{
                            urgente=false;
                        }
                        fecha=Fecha(dia,mes,anio);
                        if(existeMedicoId(medicos,idMedico) && existePacienteId(pacientes,idPaciente)){
                            asignarCita(citas,idCita,*pacientes[idPaciente],*medicos[idMedico], fecha,urgente);
                        }
                        else{
                            std::cout<<"No se ha agregado ninguna cita\n";
                        }
                    break;
                    case 2:
                        ordenarCitasPorUrgenciaYFecha(citas);
                    break;
                    case 3:
                        std::cout<<"Introduce el id de la cita que quieres cancelar: ";
                        std::cin>>idCita;
                        cancelarCita(citas,idCita);
                    break;
                    case 4:
                        std::cout<<"Introduce el id de la cita que quieres modificar: ";
                        std::cin>>idCita;
                        std::cout<<"Introduce el nuevo dia de la cita: ";
                        std::cin>>dia;
                        std::cout<<"Introduce el nuevo mes de la cita: ";
                        std::cin>>mes;
                        std::cout<<"Introduce el nuevo anio de la cita: ";
                        std::cin>>anio;
                        std::cout<<"Introduce si es urgente o no (S/N): ";
                        std::cin>>respuestaUrgente;
                        if(respuestaUrgente=='S'){
                            urgente=true;
                        }
                        else{
                            urgente=false;
                        }
                        fecha=Fecha(dia,mes,anio);
                        modificarCita(citas,idCita,fecha,urgente);
                    break;
                    case 5:
                        mostrarCitas(citas);
                    break;
                }
            break;
            case 4:
                std::ofstream escritura;
                escritura.open("guardado.txt");
                escritura<<"--medicos--\n";
                for (const auto& medico : medicos) {
                    escritura<<medico->getId()<<"\n";
                    escritura<<medico->getNombre()<<"\n";
                    escritura<<medico->getAnioNacimiento()<<"\n";
                    escritura<<medico->getEspecialidad()<<"\n";
                    if(medico->getDisponible()){
                        escritura<<"Si\n";
                    }
                    else{
                        escritura<<"No\n";
                    }
                }
                escritura<<-1; //centinela de medicos
                escritura<<"\n--pacientes--\n";
                for (const auto& paciente : pacientes) {
                    escritura<<paciente->getId()<<"\n";
                    escritura<<paciente->getNombre()<<"\n";
                    escritura<<paciente->getDireccion()<<"\n";
                    escritura<<paciente->getAnioNacimiento()<<"\n";
                    escritura<<paciente->getTelefono()<<"\n";
                    escritura<<paciente->getNotas()<<"\n";
                    escritura<<paciente->getFechaRegistro().getDia()<<"\n";
                    escritura<<paciente->getFechaRegistro().getMes()<<"\n";
                    escritura<<paciente->getFechaRegistro().getAnio()<<"\n";
                    escritura<<"historial clinico del paciente "<<paciente->getId()<<":\n";
                    escritura<<paciente->numRegistros()<<" registros\n";
                    std::vector<RegistroClinico> historial=paciente->obtenerRegitrosClinicos();
                    for(int i=0;i<paciente->numRegistros(); i++){
                        escritura<<historial[i].getFecha().getDia()<<"\n";
                        escritura<<historial[i].getFecha().getMes()<<"\n";
                        escritura<<historial[i].getFecha().getAnio()<<"\n";
                        escritura<<historial[i].getDiagnostico()<<"\n";
                        escritura<<historial[i].getTratamiento()<<"\n";
                        escritura<<historial[i].getObservaciones()<<"\n";
                    }
                    
                }
                escritura<<-1; //centinela de pacientes
                escritura<<"\n--citas--\n";
                for (const auto& cita : citas) {
                    escritura<<cita->getId()<<"\n";
                    escritura<<cita->getPaciente().getId()<<"\n";
                    escritura<<cita->getMedico().getId()<<"\n";
                    escritura<<cita->getFecha().getDia()<<"\n";
                    escritura<<cita->getFecha().getMes()<<"\n";
                    escritura<<cita->getFecha().getAnio()<<"\n";
                    if(cita->getUrgente()){
                        escritura<<"Si\n";
                    }
                    else{
                        escritura<<"No\n";
                    }
                }

                escritura.close();
                std::cout<<"Fichero guardado con exito\n";

            break;
        }
        opcionMenuPrincipal=menuPrincipal();
    }

    return 0;
}