// StrangeTales.cpp : define o ponto de entrada para o aplicativo do console.


#include "stdafx.h"
#include "Sala.h"
#include "Objeto.h"
#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

void visita(Sala* A) {
	A->Mensagem();
}

void emOrdem(Sala* A) {
	if (A != NULL) {
		emOrdem(A->Esquerda());
		visita(A);
		emOrdem(A->Direita());
	}
}


int main() {

	setlocale(LC_ALL, "Portuguese");//Definido localidade

	Objeto objetoSalaRaiz[4]{{"Lampião", "Que suas noites sejam tão brilhantes quanto suas futuras ideias"},
						  {"Barril", "Possui um vinho dentro que está estragado"}, 
						  {"Boina", "Dentro da boina tem uma chave grudada a um bilhete escrito ''Bonjour, mon ami''"},//Objeto chave para ir para o próximo nivel
						  { "Envelope", "Tem R$3,50 e um bilhete escrito ''Dinheiro pra volta, aproveita'' " }
	};//Colocando os objetos da sala raiz

	Objeto objetoSalaDir[4]{ { "Bilhete", "Às vezes, a vida prega as mesmas peças em lugares diferentes" },
							 { "Abajur", "Ainda com medo de escuro, huh? Acho que seu maior problema não é esse" },
							 { "Relógio de pulso", "O relógio está parado, mas parece fácil de abrir. Ao jogá-lo no chão de raiva, ele se desmancha e aparece uma pequena chave com um bilhete ''As vezes as coisas precisam ser resolvidas na base do ódio mesmo'' " },//Objeto chave para ir para o próximo nivel
							 { "Fantasia de piloto de F1", "Pra você se sentir um campeão! Parabéns, eu acho." }
	};//Colocando os objetos da sala a direita da raiz

	Objeto objetoSalaEsq[4]{ { "Pergaminho", "Ao ser aberto, o pergaminho diz ''Haec mea et in aeternum erit mansio?'' Significa ''Esta será a minha morada pra sempre?'' em latim no contexto desta sala, signica ''se fo***'' hahaha" },
							 { "Megafone", "Quando ligado, apenas emite um som ''LOSER LOSER LOSE''" },
							 { "Diário", "Achou que eu fosse o Tom Riddle pra dar dica em diário? ACHOU ERRADO OTÁRIO!" },
							 { "Champagne", "Está cheio de água e diz ''Não achou que eu fosse te dar o melhor, não é ? '' " }
	};//Colocando os objetos da sala a esquerda da raiz

	Objeto objetoSalaDirDir[4]{ { "Sacola", "Contém um bilhete dentro dizendo ''Um SACO essa situação, ne''" },
								{ "Binóculo", "Pra que esses óculos, vovozinha?" },
								{ "Porta retrato", "Ao abrir o porta retrato, atrás da foto de um idoso, possui a mensagem ''Uma foto sua caso você, esteja se perguntando quanto tempo está nesse labirinto haha'' " },
								{ "Terno", "Contém um bilhete dizendo ''SUIT UP!!!'' " }
	};//Colocando os objetos da sala que esta a direita do filho da direita que é descentende da raiz - Dir->Dir

	Objeto objetoSalaDirEsq[4]{ { "Cartão de memória", "Põe no celular e aparece a senha pra proxima sala com os dizeres ''Unag''" },//Objeto chave para ir para o próximo nivel
								{ "Cômoda", "Cômoda // Apenas roupas mofadas, uma barata e um bilhete dizendo ''Definitivamente uma situação inCÔMODA''" },
								{ "Gaiola", "Felizes são os pássaros que chegam mais cedo que eu à suprema fraqueza e que, voando, caem, pequenos e abençoados, nos parques onde a primavera é eterna." },
								{ "Notebook", "Quando ligado, apenas aparece na tela ''VEM NIMIN PA''" }
	};//Colocando os objetos da sala que esta a esquerda do filho da direita que é descentende da raiz - Dir->Esq


	Objeto objetoSalaDirEsqDir[4]{ { "Quimono", "Ao abrir o quimono, ele está sujo e fedorento, e cai um bilhete com os dizeres ''Eca, se eu fosse você não usaria isso, meu avô tava bem suado quando morreu nele'' " },
								   { "Baú", "Aguarde.........." },//Chegando aqui você GANHA o jogo
								   { "Sanduicheira ", "Dentro tem um bilhete escrito ''TO COM FOMEEE, QUERO LEITÊEE. EU ASSUMO UMA PIPOCAAA ME SACODÊ''" },
								   { "Açucareiro", "Doce como uma chave de metal" }
	};//Colocando os objetos da sala que esta a direira do filho da esquerda do filho da direita que é descentende da raiz - Dir->Esq->Dir

	Objeto objetoSalaDirEsqEsq[4]{ { "Mala", "Os semelhantes se atraem?" },
								   { "Televisão", "Ao ligar a TV, está tocando Call Me Maybe. Ao se aproximar pra tentar desligar, você percebe um bilhete ao lado, escrito ''Agora um pouco mais de tortura: essa TV não desliga. Boa sorte encontrando a chave heh'' *easter egg* fica aparecendo call me maybe na tela" },
								   { "Uniforme militar", "Contém um bilhete escrito ''Você vai passar com 10 em todos os DM e o Bolsonitro2049 vai ser eleito''" },
								   { "Tambor", "Ao bater no tambor, você tosse e, de tanta poeira que tinha nele, se levanta correndo e o derruba. Em baixo dele tem um bilhete dizendo ''Preferiria o Timbalada lá na Bahia...''	" }
	};//Colocando os objetos da sala que esta a esquerda do filho da esquerda do filho da direita que é descentende da raiz - Dir->Esq->Esq

	Sala *salaFilhoDirEsqEsq = new Sala("Você está na sala incial", objetoSalaDirEsqEsq);
	Sala *salaFilhoDirEsqDir = new Sala("Você está na sala incial", objetoSalaDirEsqDir);
	Sala *salaFilhoDirEsq = new Sala("Você está na sala incial", salaFilhoDirEsqEsq , salaFilhoDirEsqDir ,objetoSalaDirEsq);
	Sala *salaFilhoDirDir = new Sala("Você está na sala incial", objetoSalaDirDir);
	Sala *salaFilhoDir = new Sala("Você está na sala incial", salaFilhoDirEsq, salaFilhoDirDir, objetoSalaDir);
	Sala *salaFilhoEsq = new Sala("Você está na sala incial", objetoSalaEsq);
	Sala *salaRaiz = new Sala("Você está na sala incial", salaFilhoEsq,salaFilhoDir, objetoSalaRaiz);	
	
	//Começa a interação com o jogador

	//Declaração de variaveis
	char exa1[30];

	cout << "------------------StrangeTales-------------------------" << endl;

	salaRaiz->Mensagem();
	std::cout << "Digite item vc quer examinar: ";
	std::cin >> exa1;

	


	 


	getchar();
}
