struct etudiant {

char Nom[20];
char Prenom[20];
char Adresse[30];
int CIN;
int NumTel;
bool Redoublant;
int Notes[2];
float Moyenne;

};
typedef struct etudiant Etudiant;

struct  classe{
Etudiant* Tab;
int NbEtd;


};
typedef struct classe Classe;
struct ti1
{   Classe * Tab;

    int NbCls;
	bool notesaffectes;
};
typedef struct ti1 TI1;


struct dsi2
{   Classe * Tab;

    int NbCls;
	//bool notesaffectes;
};
typedef struct dsi2 DSI2;