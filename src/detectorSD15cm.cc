#include "detectorSD15cm.hh"


#include "G4VSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "k1DC.hh"
#include "G4RunManager.hh"
#include "G4ThreeVector.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "Run.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"

detectorSD15cm::detectorSD15cm(const G4String& name,const G4String& HCname):
G4VSensitiveDetector(name),
_detectorSD15cmHC(NULL)
{
collectionName.insert(HCname);

}

detectorSD15cm::~detectorSD15cm(){}

void detectorSD15cm::Initialize(G4HCofThisEvent* hc)
{
_detectorSD15cmHC = new detectorSD15cmHC(SensitiveDetectorName,collectionName[0]);
G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
hc->AddHitsCollection(hcID,_detectorSD15cmHC);
}
G4bool detectorSD15cm::ProcessHits(G4Step* step,G4TouchableHistory*)
{
  //scattered and all photons

    if(step->GetTrack()->GetDefinition() == G4Gamma::Gamma())
    {
     auto hc = new detectorSD15cmHit();
    G4double energy=step->GetPreStepPoint()->GetKineticEnergy()/keV;
    hc->Set_Histogram_ALLPHOTONS_Energy(energy);
    if(energy!=1330 && energy!=1170){hc->Set_Histogram_SCATTERED_Energy(energy);}
        _detectorSD15cmHC->insert(hc);

    //count 
//     Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
//     if(energy!=1330 && energy!=1170){    run->CountPhoton((G4double)0,(G4double)1);
// }
// else{ run->CountPhoton((G4double)1,(G4double)0);}
    }
    else if(step->GetTrack()->GetDefinition() == G4Electron::Electron())
    {
            auto hc = new detectorSD15cmHit();
    G4double energy=step->GetPreStepPoint()->GetKineticEnergy()/keV;
            hc->Set_Histogram_ELECTRONS_Energy(energy);
            _detectorSD15cmHC->insert(hc);


    }

    // Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    // run->AddData(step->GetPreStepPoint()->GetKineticEnergy());
    
// else if()
// {
//     auto hc = new phantomHit();
//     G4double energy=step->GetPreStepPoint()->GetKineticEnergy()/keV;
//     _phantomHC->insert(hc);
// }
 // auto charge = step->GetTrack()->GetDefinition()->GetPDGCharge();
    // auto edep = step->GetTotalEnergyDeposit()/MeV;
    // const G4VTouchable* touchable = step->GetPreStepPoint()->GetTouchable();

    // auto e = step->Get
    // G4int iz =touchable->GetReplicaNumber(0);
    // if (edep==0.) return false;
    // if(iz!=9)return false;
    // if(iz!=8)return false;
    // G4ThreeVector pos = step->GetPreStepPoint()->GetPosition();

    // G4int iy =touchable->GetReplicaNumber(2);

    // auto massy =touchable->GetVolume(2)->GetLogicalVolume()->GetMass()/kg;
    // auto massx =touchable->GetVolume(1)->GetLogicalVolume()->GetMass()/kg;
    // auto mass =touchable->GetVolume(0)->GetLogicalVolume()->GetMass()/kg;

    // G4cout<<"------------------------------------------------>> Mass X :"<<massx <<"----------->> Dose :"<<edep/massx<<G4endl;
    // G4cout<<"------------------------------------------------>> Mass Y :"<<massy <<"----------->> Dose :"<<edep/massy<<G4endl;
    // G4cout<<"------------------------------------------------>> Mass Z :"<<massz <<"----------->> Dose :"<<edep/massz<<G4endl;


    // G4double dose=/edep/mass;

    // RUN

    // Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    // run->AddData(dose,(G4double)iy);

    //end RUN
    
    //HIT

    // auto hc = new phantomHit();
    // hc->Set_CopyNo_Dose_tuple(std::make_tuple(iz,dose));
    // _phantomHC->insert(hc);

    //end HIT
return true;

}
void detectorSD15cm::EndOfEvent(G4HCofThisEvent*)
{
}