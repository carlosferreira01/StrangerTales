#include "stdafx.h"
#include <iostream>
#include <string>
#include "Objeto.h"

#pragma once
class Sala {
private:
	bool aberta;
	Sala *salaEsq;
	Sala *salaDir;
	Sala *salaPai;
	Objeto *objetos;
	std::string mensagem;

public:
	Sala(std::string mensagem, Sala *salaEsq, Sala *salaDir, Sala *salaPai, Objeto *objetos);

	Sala(std::string mensagem, Sala *salaEsq, Sala *salaDir, Objeto *objetos);

	Sala(std::string mensagem, Objeto *objetos);

	void Mensagem();

	void Examinar(std::string nome);

	Sala *Esquerda();

	Sala *Direita();

	Sala *Voltar();

	bool estaAberta();
	~Sala();
};