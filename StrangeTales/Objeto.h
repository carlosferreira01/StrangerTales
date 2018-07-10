#include "stdafx.h"
#include <string>

#pragma once
class Objeto {
private:
	std::string nome;
	std::string mensagem;
	bool temItem;

public:
	Objeto(std::string nome, std::string mensagem);
	bool Interagir();
	std::string getNome();
};