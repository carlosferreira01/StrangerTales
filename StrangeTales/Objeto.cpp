#include "stdafx.h"
#include <string>
#include <iostream>
#include "Objeto.h"

Objeto::Objeto(std::string nome, std::string mensagem) {
	this->nome = nome;
	this->mensagem = mensagem;
}

bool Objeto::Interagir() {
	std::cout << this->mensagem << std::endl;
	return temItem;
}

std::string Objeto::getNome() {
	return nome;
}
