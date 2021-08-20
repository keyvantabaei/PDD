#include "HistoManager.hh"
#include <TTree.h>
#include <TH1D.h>
#include <TFile.h>
//there is another way to include following header .
#include <CLHEP/Units/SystemOfUnits.h>
HistoManager::HistoManager():rootfile(0)
{
  _Ntuple1=0;
  _z=0;
  _edep=0;
  //5cm
  _histo_all_photons5cm=0;
  _histo_scattered_photons5cm=0;
  _histo_electrons5cm=0;

//10cm
    _histo_all_photons10cm=0;
  _histo_scattered_photons10cm=0;
  _histo_electrons10cm=0;

//15cm
    _histo_all_photons15cm=0;
  _histo_scattered_photons15cm=0;
  _histo_electrons15cm=0;
}

HistoManager::~HistoManager(){if(rootfile)delete rootfile;}

void HistoManager::Save()
{
    if(!rootfile)return;
    rootfile->Write();
    rootfile->Close();
}

void HistoManager::Book()
{
  //G4cout<<"File is opened"<<G4endl;
rootfile = new TFile("result.root","RECREATE");

//5cm
_histo_all_photons5cm = new TH1D("APH5cm", "All Photons (keV)", 50, 0., 1500);
_histo_scattered_photons5cm = new TH1D("SPH5cm", "Scattered Photons (keV)", 50, 0., 1500);
_histo_electrons5cm = new TH1D("E5cm", "Electrons (keV)", 50, 0., 1500);


//10cm
_histo_all_photons10cm = new TH1D("APH10cm", "All Photons (keV)", 50, 0., 1500);
_histo_scattered_photons10cm = new TH1D("SPH10cm", "Scattered Photons (keV)", 50, 0., 1500);
_histo_electrons10cm = new TH1D("E10cm", "Electrons (keV)", 50, 0., 1500);



//15cm
_histo_all_photons15cm = new TH1D("APH15cm", "All Photons (keV)", 50, 0., 1500);
_histo_scattered_photons15cm = new TH1D("SPH15cm", "Scattered Photons (keV)", 50, 0., 1500);
_histo_electrons15cm = new TH1D("E15cm", "Electrons (keV)", 50, 0., 1500);




_Ntuple1 = new TTree("Ntuple1", "Edep");
_Ntuple1->Branch("Z", &_z, "Z/D");
_Ntuple1->Branch("edep", &_edep, "edep/D");
}


void HistoManager::Fill_PDD(std::tuple<G4double,G4double>  pos_edep)
{
if(std::get<1>(pos_edep)!=0)
{
  _z=std::get<0>(pos_edep);
  _edep=std::get<1>(pos_edep);
  _Ntuple1->Fill();
}

}
//5cm
void HistoManager::Fill_Histogram_ALLPHOTONS5cm( G4double e){_histo_all_photons5cm->Fill(e);}
void HistoManager::Fill_Histogram_SCATTERED_PHOTONS5cm( G4double e){_histo_scattered_photons5cm->Fill(e);}
void HistoManager::Fill_Histogram_ELECTRONS5cm( G4double e){  _histo_electrons5cm->Fill(e);}



//10cm
void HistoManager::Fill_Histogram_ALLPHOTONS10cm( G4double e){_histo_all_photons10cm->Fill(e);}
void HistoManager::Fill_Histogram_SCATTERED_PHOTONS10cm( G4double e){_histo_scattered_photons10cm->Fill(e);}
void HistoManager::Fill_Histogram_ELECTRONS10cm( G4double e){  _histo_electrons10cm->Fill(e);}


//15cm
void HistoManager::Fill_Histogram_ALLPHOTONS15cm( G4double e){_histo_all_photons15cm->Fill(e);}
void HistoManager::Fill_Histogram_SCATTERED_PHOTONS15cm( G4double e){_histo_scattered_photons15cm->Fill(e);}
void HistoManager::Fill_Histogram_ELECTRONS15cm( G4double e){  _histo_electrons15cm->Fill(e);}