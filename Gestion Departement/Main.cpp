#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
 
#include<string.h>
#include"Bib.h"
#include"Fonctions.h"


void main()
{
	//Etudiant etd;
	//Classe cls;
	TI1 ti;
	DSI2 ds;
	char choix;
	int choixActionPrincipale;
	ti=AllocationTI1();
	ds=AllocationDSI2();
	do{
		printf("\n+----------------------------------------------------+");
	printf("\n|Bienvenue au departement de l'informatique de l'ISET|");
	printf("\n+----------------------------------------------------+");
		choixActionPrincipale = menuPrincipale();
		switch(choixActionPrincipale)
		{
			
						case 1:
							  {
									AfficherClasseTI1(ti);
							  }break;
						case 2:
							  {
								  if(((ti.Tab)+(ti.NbCls-1))->NbEtd<3)
								  {AjouterEtudiant(&ti);}
								  else 
									  {ReallocationTI1(&ti);
								  AjouterEtudiant(&ti);}
									  
							  }break;
						case 3:
							  {
								  Equilibrage(&ti);
							  }break;
						case 4:
							  {
									Trialpha(&ti);
							  }break;
						case 5:
							  {
									AffecterNotes(&ti);
							  }break;
						case 6:
							  {
									AfficherRedoublants(&ti);
							  }break;
						case 7:
							  {
									AffectationDSI2(&ds,&ti);
							  }break;
						case 8:
							  {
								  AfficherClasseDSI2(ds);
							  }break;
						case 9:
							  {
									system("cls");
						
							  }break;
					
				 
				 
				
			default : printf("\n\n\tErreur: Choix non-valide!\n");
		}
		choix = SaisieReponse();
	}while(toupper(choix) != 'N');
	system("cls");
	printf("\n+---------------+");
	printf("\n|Fin du Programme|");
	printf("\n+---------------+");
	

	






getch();
}