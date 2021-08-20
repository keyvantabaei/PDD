#ifndef HistoManager_h
#define HistoManager_h 1

#include "globals.hh"

class TFile;
class TTree;
class TH1D;

class HistoManager
{
public:
 HistoManager();
~HistoManager();

void Book();
void Save();
void Draw();
void Fill_PDD(std::tuple<G4double,G4double>);

//5cm
void Fill_Histogram_ALLPHOTONS5cm(G4double energy);
void Fill_Histogram_SCATTERED_PHOTONS5cm(G4double energy);
void Fill_Histogram_ELECTRONS5cm(G4double energy);

//10cm
void Fill_Histogram_ALLPHOTONS10cm(G4double energy);
void Fill_Histogram_SCATTERED_PHOTONS10cm(G4double energy);
void Fill_Histogram_ELECTRONS10cm(G4double energy);

//15cm
void Fill_Histogram_ALLPHOTONS15cm(G4double energy);
void Fill_Histogram_SCATTERED_PHOTONS15cm(G4double energy);
void Fill_Histogram_ELECTRONS15cm(G4double energy);

private:
G4double _z;
G4double _edep;
G4double _histo_energy;
TTree*   _Ntuple1;
//5cm  
TH1D* _histo_all_photons5cm;  
TH1D* _histo_scattered_photons5cm;  
TH1D* _histo_electrons5cm;

//10cm  
TH1D* _histo_all_photons10cm;  
TH1D* _histo_scattered_photons10cm;  
TH1D* _histo_electrons10cm; 

//15cm  
TH1D* _histo_all_photons15cm;  
TH1D* _histo_scattered_photons15cm;  
TH1D* _histo_electrons15cm; 


TFile* rootfile;

};
#endif