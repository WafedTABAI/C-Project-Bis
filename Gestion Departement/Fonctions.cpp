#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include"Bib.h"
#pragma once


Etudiant DonneeEtudiant(){
	Etudiant etd;

	printf("Donnez le nom de l'eleve :\n");
	scanf("%s",etd.Nom);
	printf("Donnez le prenom de l'eleve :\n");
	scanf("%s",etd.Prenom);
	printf("Donnez l'adresse de l'eleve :\n");
	scanf("%s",etd.Adresse);
	printf("Donnez la CIN de l'eleve :\n");
	scanf("%d",&etd.CIN);
	printf("Donnez la numero de telephone de l'eleve :\n");
	scanf("%d",&etd.NumTel);
	//etd.Redoublant=false;
	
	return etd;


}

void AfficherEtudiant(Etudiant etd){

	
	printf("|Nom: %s\t",etd.Nom);
	printf("|Prenom: %s\t",etd.Prenom);
	printf("|Adresse: %s\t",etd.Adresse);
	printf("|CIN: %d\t",etd.CIN);
	printf("|Numero Telephone: %d\t",etd.NumTel);
	/*
	if(etd.Redoublant) 
	printf("|Redoublant : oui!");
	else
		printf("|Redoublant : non!");*/
	

}






/*Classe AjouterClasse()
{  Classe cls;
	int nb;
	do{
	printf("Donnez le nombre d'etudiant a ajouter a cette classe:\n");
	scanf("%d",&nb);
	} while (nb<1);

	cls=AllocationClasse();
	printf("\nAjout Des etudiants: \n");
	for(int i=0;i<nb;i++)
	{    printf("\nEtudiant: %d\n",i+1);
		
		*(cls.Tab+i)=DonneeEtudiant();

	}
	cls.NbEtd=nb;
	printf("\nFin de l'ajout!\n");
	return cls;
}*/




void AjouterEtudiant(TI1* ti)
{  

	
	((ti->Tab)+(ti->NbCls-1))->NbEtd++;
	printf("\nAjout De l'etudiant: %d a la classe :%d\n",((*ti).Tab+((*ti).NbCls-1))->NbEtd, (*ti).NbCls );
	
	*(((ti->Tab)+(ti->NbCls-1))->Tab+(((ti->Tab)+(ti->NbCls-1))->NbEtd-1))=DonneeEtudiant();
	

	
}


/*Classe AllocationClasse(){
	Classe cls;
	cls.Tab = (Etudiant*) malloc(2*sizeof(Etudiant));
	if(!cls.Tab) exit(-1);
	cls.NbEtd=0;
	return cls;
}*/

/*void ReallocationClasse(Classe**cls){

	(*(*(cls))).NbEtd++;
	(*(*(cls))).Tab= (Etudiant*) realloc((*(*(cls))).Tab,(*(*(cls))).NbEtd* sizeof(Etudiant));
	if(!(*(*(cls))).Tab) exit(-2);
}*/





void AfficherClasseTI1( TI1 ti ) {
	if(ti.Tab->NbEtd>0){
	printf("\nAffichage Des Classes: \n");
	
	for(int j=0;j<ti.NbCls;j++)
	{
    printf("\nAffichage Des etudiants de la classe: %d\n",j+1);
	for(int i=0;i<(ti.Tab+j)->NbEtd;i++)
	{
		printf("\n\nEtudiant: %d\n",i+1);
		AfficherEtudiant(*((ti.Tab+j)->Tab+i));
	}
	}
	printf("\n\nFin de l'affichage!\n");
	}
	else  printf("\n\nPas d'etudiants a afficher!\n");
}


TI1 AllocationTI1(){
	TI1 ti;
	ti.Tab = (Classe*) malloc(sizeof(Classe));
	if(!ti.Tab) exit(-3);
	ti.NbCls=1;
	(ti.Tab+ti.NbCls-1)->Tab=(Etudiant*) malloc(3*sizeof(Etudiant));// hnai 30 fi 3oudh 3
	if(!(ti.Tab+ti.NbCls-1)->Tab) exit(-4);
	(ti.Tab+ti.NbCls-1)->NbEtd=0;
	ti.notesaffectes=false;
	return ti;
}

void ReallocationTI1(TI1* ti){
	ti->NbCls++;
	ti->Tab = (Classe*) realloc(ti->Tab,ti->NbCls * sizeof(Classe));
	if(!ti->Tab) exit(-5);
	((ti->Tab)+(ti->NbCls-1))->Tab=(Etudiant*) malloc(3*sizeof(Etudiant));// hnai 30 fi 3oudh 2
	if(!((ti->Tab)+(ti->NbCls-1))->Tab) exit(-6);
	((ti->Tab)+(ti->NbCls-1))->NbEtd=0;
	ti->notesaffectes=false;
}


void Equilibrage(TI1* ti) //Sur le nombre seulement, Même principe pour les redoublants
{   //Impossible d'avoir le même nombre d'étudiant tout le temps, on le fera quand c'est possible, dans le cas écheant, on prendra
	//Le minium d'étudiants des classes récemment remplies
	//On répartira le nombre de redoublants sur toutes les classes quand c'est possible


	//Ici equilibre en effectif etudiant : on a pris 3 eleves par classes max au lieu de 30 pour des fins de test:
	if(ti->NbCls>1)
	{
			if(((ti->Tab)+(ti->NbCls-1))->NbEtd<2)//25
			{  int nb=((ti->Tab)+(ti->NbCls-1))->NbEtd;
			   double somme=(((3*(ti->NbCls-1)+nb))/(ti->NbCls));//double pour la fonction floor;
				if (somme== floor(somme) ) //test d'équirépartition d'etudiants
				{
										int nbetd=somme-nb;
			
										int k=(nbetd)/(ti->NbCls-1);
										int l=0;
										for(int i=2;i<ti->NbCls+1;i++)
										{
											int h=((ti->Tab)+(ti->NbCls-i))->NbEtd;
											for(int j=1;j<k+1;j++)
											{
						
												*(((ti->Tab)+(ti->NbCls-1))->Tab+nb+l)=*(((ti->Tab)+(ti->NbCls-i))->Tab+h-j);
												l++;
												((ti->Tab)+(ti->NbCls-1))->NbEtd++;
											}
											((ti->Tab)+(ti->NbCls-i))->Tab=(Etudiant*)realloc(((ti->Tab)+(ti->NbCls-i))->Tab,(h-k)*sizeof(Etudiant));
											((ti->Tab)+(ti->NbCls-i))->NbEtd=h-k;
										}
								
					printf("\nEquilibrage de nombre d'etudiants effectue!\n");
				}
				else printf("\nPas de possibilite d'equirepartition avec l'effectif d'etudiant acutel!\n");
			}
		
		else printf("\nNombre d'etudiant assez suffisant (>=25) pour aborder un equilibrage!\n");
			
				
			
	}
	else printf("\nUne seule classe presente: Equlibrage impossible!\n");

	////Ici equilibre en effectif redoublant : Marche pas, faute de temps je l'enleve pour le moment

	/*if(ti->NbCls>1 && ti->Tab->NbEtd>1)
	{  if ( ti->notesaffectes==true)
			{ 
				int nbred=0;
				for(int i=0;i<ti->NbCls;i++)
					{
							for(int j=0;j<((ti->Tab)+(i))->NbEtd;j++)
							{
								if((((ti->Tab)+(i))->Tab+j)->Moyenne<10)
									nbred++;


							}
					

					}

				  if (nbred>0)
				  {
					  double somme=nbred/ti->NbCls;
					  if (somme== floor(somme) ) //test d'équirépartition de redoublants:
					  {    Classe cls;
										cls.Tab=(Etudiant*) malloc(nbred*sizeof(Etudiant));
										if(!cls.Tab) exit(-7);
										cls.NbEtd=0;
								for(int i=0;i<ti->NbCls;i++)
								{
										for(int j=0;j<((ti->Tab)+(i))->NbEtd;j++)
										{
												if((((ti->Tab)+(i))->Tab+j)->Moyenne<10)
												{
													*((cls.Tab)+(cls.NbEtd))=*(((ti->Tab)+(i))->Tab+j);
													cls.NbEtd++;

													for(int k=j;k<((ti->Tab)+(i))->NbEtd-1;k++)//ecrasement
													{
														*(((ti->Tab)+(i))->Tab+k)=*(((ti->Tab)+(i))->Tab+k+1);
														((ti->Tab)+(i))->NbEtd--;

														((ti->Tab)+(ti->NbCls-i))->Tab=(Etudiant*)realloc(((ti->Tab)+(ti->NbCls-i))->Tab,((ti->Tab)+(i))->NbEtd*sizeof(Etudiant));

													}
												}


										}
					

						  
								}

								int k=(nbred)/(ti->NbCls);//nb de red a repartir par classe
								for(int i=0;i<ti->NbCls;i++)
								{           
											((ti->Tab)+(i))->NbEtd+=k;	
											((ti->Tab)+(ti->NbCls-i))->Tab=(Etudiant*)realloc(((ti->Tab)+(ti->NbCls-i))->Tab,((ti->Tab)+(i))->NbEtd*sizeof(Etudiant));
											for(int i=1;i<k+1;i++)
											{*(((ti->Tab)+(ti->NbCls-1))->Tab+((ti->Tab)+(i))->NbEtd-i)=*((cls.Tab)+(cls.NbEtd-i));

											}
											cls.NbEtd-=k;
											cls.Tab=(Etudiant*) realloc(cls.Tab,cls.NbEtd*sizeof(Etudiant));
								}
								free(cls.Tab); //liberation memoire;
				  printf("\nEquilibrage de nombre de redboulants effectue!\n");
				}
				else printf("\nPas de possibilite d'equirepartition avec le nombre de redoublants acutel!\n");

				
			}
				  else printf("\nAucun redoublant dans toutes les classes!\n");
		
			}
	else printf("\nMoyennes pas encore attribuées aux etudiants pour equirepartir les redoublants\n");
	}
	else printf("\nNombre d'etudiants insuffisant!\n");*/

}



void Trialpha(TI1* ti)
{  if(ti->Tab->NbEtd>1)
	{
			for(int i=0;i<ti->NbCls;i++)
			{
					for(int j=0;j<((ti->Tab)+(i))->NbEtd-1;j++)
					{ 
						for(int k=1;k<((ti->Tab)+(i))->NbEtd;k++)
						{
							if (strcmp(strcpy(((((ti->Tab)+(i))->Tab+(k))->Nom),((((ti->Tab)+(i))->Tab+(k))->Prenom)),strcpy(((((ti->Tab)+(i))->Tab+(k-1))->Nom),((((ti->Tab)+(i))->Tab+(k-1))->Prenom)))<0)
								{Etudiant etd=*(((ti->Tab)+(i))->Tab+k);
						
								*(((ti->Tab)+(i))->Tab+k)=*(((ti->Tab)+(i))->Tab+k-1);
								*(((ti->Tab)+(i))->Tab+k-1)=etd;
								}
						}
			
					}


			}
	 printf("\nTri effectue!\n");
	}
	else printf("\nPas assez d'etudiants!\n");

}

void AffecterNotes(TI1* ti)
{
	if(ti->Tab->NbEtd>0)
	{
		printf("\nAffectation des notes a tous les etudiants!\n");
		for(int i=0;i<ti->NbCls;i++)
		{    printf("\nNotes de la classe numero: %d:\n",i+1);
             for(int j=0;j<((ti->Tab)+(i))->NbEtd;j++)
			 {   printf("\nNotes de l'etudiant numero: %d:\n",j+1);
				(((ti->Tab)+(i))->Tab+j)->Moyenne=0;
				 for(int k=0;k<2;k++){//Nombre de matieres = 2 dans notre exemple, on peut changer biensur
				     printf("\nDonnez la Note de la matiere numero %d sur une echelle de 0 a 20: \n",k+1);
					 scanf("%d",&(((ti->Tab)+(i))->Tab+j)->Notes[k]);
					 (((ti->Tab)+(i))->Tab+j)->Moyenne+=(((ti->Tab)+(i))->Tab+j)->Notes[k]/2;//2 nombre de matieres, on peut le changer
				 }
				
			 }
		
		}

		ti->notesaffectes=true;

	}

	else printf("\nPas d'etudiants a noter!\n");

}

void AfficherRedoublants(TI1* ti)
{
	if(ti->Tab->NbEtd>0)
	{  if ( ti->notesaffectes==true) 
		{
				printf("\nAffichage des redoublants:\n");
				for(int i=0;i<ti->NbCls;i++)
				{    printf("\nRedoublants de la classe numero: %d:\n",i+1);
					 int nb=0;
					 for(int j=0;j<((ti->Tab)+(i))->NbEtd;j++)
					 {  
						 if((((ti->Tab)+(i))->Tab+j)->Moyenne<10)
						 {
							 printf("\nEtudiant numero %d redouble avec une moyenne de: %f\n",j+1,(((ti->Tab)+(i))->Tab+j)->Moyenne);
							 nb++;
						 }
					  

			
				
					 }
					 if(nb==0) printf("\nPas de redoublants pour cette classe!\n");
		
				}

			}
		else printf("\nLes notes n'ont pas encore ete donnee!\n");

	}

	else printf("\nPas d'etudiants à evaluer!\n");

}


DSI2 AllocationDSI2(  )

{   DSI2 ds;
	
	ds.Tab = (Classe*) malloc(sizeof(Classe));
	if(!ds.Tab) exit(-8);
	ds.NbCls=1;
	(ds.Tab+ds.NbCls-1)->Tab=(Etudiant*) malloc(3*sizeof(Etudiant));// hnai 30 fi 3oudh 3
	if(!(ds.Tab+ds.NbCls-1)->Tab) exit(-4);
	(ds.Tab+ds.NbCls-1)->NbEtd=0;

	return ds;
}

void ReallocationDSI2(DSI2* ds){
	ds->NbCls++;
	ds->Tab = (Classe*) realloc(ds->Tab,ds->NbCls * sizeof(Classe));
	if(!ds->Tab) exit(-5);
	((ds->Tab)+(ds->NbCls-1))->Tab=(Etudiant*) malloc(3*sizeof(Etudiant));// hnai 30 fi 3oudh 2
	if(!((ds->Tab)+(ds->NbCls-1))->Tab) exit(-9);
	((ds->Tab)+(ds->NbCls-1))->NbEtd=0;
	
}


void AffectationDSI2(DSI2 *ds, TI1 * ti){

	
	if(ti->Tab->NbEtd>0)
	{  if ( ti->notesaffectes==true) 
	
		{
				printf("\nAffectation aux classes DSI2:\n");
				for(int i=0;i<ti->NbCls;i++)
				{    
					 int nb=0;
					 for(int j=0;j<((ti->Tab)+(i))->NbEtd;j++)
					 {  
						 if((((ti->Tab)+(i))->Tab+j)->Moyenne<10)
						 {

							 nb++;
						 }
					  if((((ti->Tab)+(i))->Tab+j)->Moyenne>10)
						 {
							 if((ds->Tab+ds->NbCls-1)->NbEtd>2)// a la place de 30
							 {   
								 ReallocationDSI2(ds);
							 }
							 * ((ds->Tab+ds->NbCls-1)->Tab+(ds->Tab+ds->NbCls-1)->NbEtd)=*(((ti->Tab)+(i))->Tab+j);
								(ds->Tab+ds->NbCls-1)->NbEtd++;

						 }

			
				
					 }
					 if(nb==0) {
						 printf("\nPas de redoublants pour la classe TI1 numero : %d!\n",i);
						 for(int k=i;k<ti->NbCls-1;k++)
						 {
							 *((ti->Tab)+(k))=*((ti->Tab)+(k+1));
							 ti->NbCls--;
							 ti->Tab = (Classe*) realloc(ti->Tab,ti->NbCls * sizeof(Classe));
						 }
						 printf("\nCette classe a ete supprimee!\n");

					 }
		
				}

			}
		else printf("\nLes notes n'ont pas encore ete donnee!\n");

	}

	else printf("\nPas d'etudiants a evaluer!\n");


}


void AfficherClasseDSI2( DSI2 ds ) {
	if(ds.Tab->NbEtd>0){
	printf("\nAffichage Des Classes: \n");
	
	for(int j=0;j<ds.NbCls;j++)
	{
    printf("\nAffichage Des etudiants de la classe: %d\n",j+1);
	for(int i=0;i<(ds.Tab+j)->NbEtd;i++)
	{
		printf("\n\nEtudiant: %d\n",i+1);
		AfficherEtudiant(*((ds.Tab+j)->Tab+i));
	}
	}
	printf("\n\nFin de l'affichage!\n");
	}
	else  printf("\n\nPas d'etudiants a afficher!\n");
}

int menuPrincipale()
{
    int choix;
    printf("\n 1. Afficher les Classes TI1");
    printf("\n 2. Ajouter Etudiant");
	printf("\n 3. Equilibrer les Classes");
	printf("\n 4. Trier les classes");
	printf("\n 5. Donner Notes d'etudiants");
	printf("\n 6. Afficher Redoublants");
	printf("\n 7. Affecter a DSI2");
	printf("\n 8. Afficher les Classes DSI2");
	printf("\n 9. vider l'ecran");
	printf("\n");
	
	do{
		scanf("%d",&choix);
	}while((choix>9)||(choix<1));

	return choix;
}

char SaisieReponse()
{
	char rep;
	do{
		printf("Voulez vous continuer ?(Y/N)\n");
		rep = getch();
	}while(toupper(rep) != 'Y' && toupper(rep) != 'N');
	
	return rep;
}



