//Etudiant:

Etudiant DonneeEtudiant();
void AfficherEtudiant(Etudiant);
void AjouterEtudiant(TI1*);

//Classe:
Classe AllocationClasse();
void ReallocationClasse(Classe**);
Classe AjouterClasse();


//TI1:
TI1 AllocationTI1();
void AfficherClasseTI1(TI1);
void ReallocationTI1(TI1*);
void Equilibrage(TI1*);
void Trialpha(TI1*);
void AffecterNotes(TI1*);
void AfficherRedoublants(TI1*);

//DSI2:
DSI2 AllocationDSI2();
void ReallocationDS2(DSI2*);
void AffectationDSI2(DSI2 *, TI1 *);
void AfficherClasseDSI2( DSI2 );
//Menu
int menuPrincipale();
char SaisieReponse();