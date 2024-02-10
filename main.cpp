#include <iostream>
#include <limits>

using namespace std;

void error()
{
	cout << "ERROR: Nesprávné zadání!" << endl;
}

struct ZakladniTexty
{
	const string easyText = "EASY obtížnost\n- Začínáte s 3 mld. penězi\n- Začínáte s 2000 vojáky\n- Dokud neinvestujete, získáváte 2 mld. peněz za kolo\n- Chcete-li vyhrát, musíte získat 25 území\n- Investovat můžete do 10 peněz za kolo\n- Invaze do vaší země se konají každých 10 kol\n- Invaze jsou vždy po 1000 vojácích";
	const string normalText = "NORMAL obtížnost\n- Začínáte s 3 mld. penězi\n- Nezačínáte s žádnými vojáky\n- Dokud neinvestujete, získáváte 2 mld. peněz za kolo\n- Chcete-li vyhrát, musíte získat 55 území\n- Investovat můžete do 5 peněz za kolo\n- Invaze do vaší země se konají každých 5 kol\n- Invaze jsou vždy po 1000 vojácích";
	const string hardText = "HARD obtížnost\n- Nezačínáte s žádnými penězi\n- Nezačínáte s žádnými vojáky\n- Dokud neinvestujete, získáváte 2 mld. peněz za kolo\n- Chcete-li vyhrát, musíte získat 70 území\n- Investovat můžete do 5 peněz za kolo\n- Invaze do vaší země se konají každých 5 kol\n- Invaze jsou vždy po 2000 vojácích";
};

struct Hra
{
	int penize;
	int vojaci;
	int kola = 1;
	int obsadit;
	int banka = 0;
	int penize_za_kolo = 2;
};

bool obtiznost_switch(char obtiznost, ZakladniTexty zakladniTexty, int& penize, int& vojaci, int& obsadit, string& zakladniText)
{
	switch (obtiznost)
	{
	case 'E':
		penize = 3;
		vojaci = 2000;
		obsadit = 25;
		zakladniText = zakladniTexty.easyText;
		return 0;
	case 'N':
		penize = 3;
		vojaci = 0;
		obsadit = 55;
		zakladniText = zakladniTexty.normalText;
		return 0;
	case 'H':
		penize = 0;
		vojaci = 0;
		obsadit = 70;
		zakladniText = zakladniTexty.hardText;
		return 0;
	default:
		return 1;
	}
}

bool vyber_switch(char vyber, Hra hra)
{
	switch (vyber)
	{
		case 'K':
			return 0;
		case 'V':
			return 0;
		case 'I':
			return 0;
		case 'B':
			return 0;
		case 'D':
			return 0;
		case 'E':
			cout << "Odešel jsi ze hry.";
			exit(0);
		default:
			return 1;
	}
}

int main() {
	Hra hra;
	ZakladniTexty zakladniTexty;
	string zakladniText;

	bool quit = false;
	while (!quit) {
		string obtiznost_str;
		char& obtiznost = obtiznost_str[0];

		cout << "Na jakou chceš hrát obtížnost\nE = Easy\nN = Normal\nH = Hard: ";
		cin >> obtiznost_str;
		if (obtiznost_str.length() > 1) {
			error();
			continue;
		}

		obtiznost_str = toupper(obtiznost);
		obtiznost_switch(obtiznost, zakladniTexty, hra.penize, hra.vojaci, hra.obsadit, zakladniText) ? [] {error(); main();}() : [zakladniText] {cout << zakladniText << endl << "Stiskem ENTER pokračujte: ";}();
		quit = true;
	}
	
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();

	cout << "Toto je vylepšená verze hry textova_hra.py. Jestli chcete mít zážitek ze hry textova_hra, jako takový, stáhněte si KV OS BETA 0.6.\n" << endl;
	while (true) {
		string vyber_str;
		char& vyber = vyber_str[0];

		cout << hra.kola << ". KOLO! \nK = Koupit vojáky, V = Válka, I = Investovat, B = Banka, D = Další kolo, E = Exit: ";
		cin >> vyber_str;
		if (vyber_str.length() > 1) {
			error();
			continue;
		}

		vyber_str = toupper(vyber);
		if (vyber_switch(vyber, hra)) {
			error();
			continue;
		}

		cout << "Dobrý den!";
	}
}