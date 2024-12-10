#include <stdbool.h>
#include <stdio.h>
void build_array(int n, int v[], int *p_min) // in sirul puncte retinem cate puncte mai poate
							 // obtine la fiecare materie
{
	int x[101], c[101];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &c[i]);
	}
	scanf("%d", p_min);
	for (int i = 0; i < n; i++)
	{
		*p_min -= x[i] * c[i]; // scadem din punctajul minim cate puncte a obtinut deja
						 // ca sa determinam de cate mariri mai avem nevoie
		v[i] = c[i] * (10 - x[i]);
	}
}
void sorteaza(int n, int v[]) // problema s-a redus la metoda greedy deci
							  // sortam, am ales descrescator pentru a porni de
							  // pe prima pozitie in parcurgerea finala
{
	bool sortat = false; // il presupunem nesortat
	while (sortat == 0)	 // metoda bulelor
	{
		bool amschimbat = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (v[i] < v[i + 1])
			{
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				amschimbat = true;
			}
		}
		if (amschimbat == false) // cand l-am parcurs si nu am mai facut nicio
								 // schimbare e clar sortat
			sortat = true;
	}
}
int main()
{
	int n, puncte[101] = {0}, p_min, i = 0, m = 0;
	scanf("%d", &n);
	build_array(n, puncte, &p_min);
	sorteaza(n, puncte);
	while (p_min > 0 && i < n) // parcurgem de la cea mai mare marire posibila de obtinut pana
				  // la cea mai mica si scadem din cate puncte mai avem nevoie
	{
		if (puncte[i] != 0)
		{
			m++;
			p_min -= puncte[i];
		}
		i++;
	}
	if (p_min <= 0)
		printf("%d\n", m); // afisam cate mariri avem nevoie sau -1 daca punctajul
						   // e irealizabil
	else
		printf("-1\n");
}