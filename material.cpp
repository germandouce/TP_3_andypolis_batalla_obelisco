#include "material.h"

Material::Material() {
	this -> nombre_material = "";
	this->diminutivo = "-";
    this -> cantidad_material = 0;
}

Material::Material(int cantidad_material) {
	this -> nombre_material = "material";
	this->diminutivo = "-";
    this -> cantidad_material = cantidad_material;
}

Material::Material(string nombre_material, int cantidad_material) {
    this -> nombre_material = nombre_material;
	this->diminutivo = "-";
    this -> cantidad_material = cantidad_material;
}

string Material::obtener_nombre() {
    return nombre_material;
}

char* Material::obtener_diminutivo(){
    return diminutivo;
}

int Material::obtener_cantidad() {
    return cantidad_material;
}

void Material::sumar_cantidad(int cantidad) {
	cantidad_material += cantidad;
}

void Material::restar_cantidad(int cantidad) {
    cantidad_material -= cantidad;
}