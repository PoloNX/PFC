#include "random.hpp"

randomRequests::randomRequests(void) {
}

std::string randomRequests::computerTurn(int choice) {
	srand(time(NULL));
	int alea = rand() % 3 + 1; //1 = Pierre 2 = Feuille 3 = Ciseaux
	if (choice == 1)	//Pierre
	{
		if (alea == 1)
			return "Egalité ! le choix adverse était Pierre";
		if (alea == 2)
			return "Perdu ! le choix adverse était Feuille";
		if (alea == 3)
			return "Gagné ! le choix adverse était Ciseaux";
	}
	
	if (choice == 2)	//Feuille
	{
		if (alea == 1)
			return "Gagné ! le choix adverse était Pierre";
		if (alea == 2)
			return "Egalité ! le choix adverse était Feuille";
		if (alea == 3)
			return "Perdu ! le choix adverse était Ciseaux";
	}
	
	if (choice == 3)	//Ciseaux
	{
		if (alea == 1)
			return "Perdu ! le choix adverse était Pierre";
		if (alea == 2)
			return "Gagné ! le choix adverse était Feuille";
		if (alea == 3)
			return "Egalité ! Le choix adverse était Ciseaux";
	}
}