#include "random.hpp"

randomRequests::randomRequests(void) {
}

std::string randomRequests::computerTurn(int choice) {
	srand(time(NULL));
	int alea = rand() % 3 + 1; //1 = Pierre 2 = Feuille 3 = Ciseaux
	if (choice == 1)	//Pierre
	{
		if (alea == 1)
			return "Egalit� ! le choix adverse �tait Pierre";
		if (alea == 2)
			return "Perdu ! le choix adverse �tait Feuille";
		if (alea == 3)
			return "Gagn� ! le choix adverse �tait Ciseaux";
	}
	
	if (choice == 2)	//Feuille
	{
		if (alea == 1)
			return "Gagn� ! le choix adverse �tait Pierre";
		if (alea == 2)
			return "Egalit� ! le choix adverse �tait Feuille";
		if (alea == 3)
			return "Perdu ! le choix adverse �tait Ciseaux";
	}
	
	if (choice == 3)	//Ciseaux
	{
		if (alea == 1)
			return "Perdu ! le choix adverse �tait Pierre";
		if (alea == 2)
			return "Gagn� ! le choix adverse �tait Feuille";
		if (alea == 3)
			return "Egalit� ! Le choix adverse �tait Ciseaux";
	}
}