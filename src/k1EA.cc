#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"

#include "k1EA.hh"
#include "k1RA.hh"
#include "HistoManager.hh"


k1EA::k1EA(k1RA* ra,HistoManager* histo)
 : G4UserEventAction(),_edep_HCID(-1),_det5cm_HCID(-1),_det10cm_HCID(-1),_det15cm_HCID(-1),_histo(histo),_charge_HCID(-1),_runAction(ra)
{}


k1EA::~k1EA()
{}

phantomHC*  k1EA::GetphantomHitsCollection(G4int hcID,const G4Event* event) const
{
  auto hitsCollection = static_cast<phantomHC*>(event->GetHCofThisEvent()->GetHC(hcID));
  
  if ( ! hitsCollection ) 
  {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("B4cEventAction::GetHitsCollection()","MyCode0003", FatalException, msg);
  }         

  return hitsCollection;
}  
chamberHC*  k1EA::GetchamberHitsCollection(G4int hcID,const G4Event* event) const
{
  auto hitsCollection = static_cast<chamberHC*>(event->GetHCofThisEvent()->GetHC(hcID));
  
  if ( ! hitsCollection ) 
  {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("B4cEventAction::GetHitsCollection()","MyCode0003", FatalException, msg);
  }         

  return hitsCollection;
} 
detectorSD5cmHC*  k1EA::GetDet5cmHitsCollection(G4int hcID,const G4Event* event) const
{
  auto hitsCollection = static_cast<detectorSD5cmHC*>(event->GetHCofThisEvent()->GetHC(hcID));
  
  if ( ! hitsCollection ) 
  {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("B4cEventAction::GetHitsCollection()","MyCode0003", FatalException, msg);
  }         

  return hitsCollection;
} 
detectorSD10cmHC*  k1EA::GetDet10cmHitsCollection(G4int hcID,const G4Event* event) const
{
  auto hitsCollection = static_cast<detectorSD10cmHC*>(event->GetHCofThisEvent()->GetHC(hcID));
  
  if ( ! hitsCollection ) 
  {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("B4cEventAction::GetHitsCollection()","MyCode0003", FatalException, msg);
  }         

  return hitsCollection;
} 
detectorSD15cmHC*  k1EA::GetDet15cmHitsCollection(G4int hcID,const G4Event* event) const
{
  auto hitsCollection = static_cast<detectorSD15cmHC*>(event->GetHCofThisEvent()->GetHC(hcID));
  
  if ( ! hitsCollection ) 
  {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("B4cEventAction::GetHitsCollection()","MyCode0003", FatalException, msg);
  }         

  return hitsCollection;
} 

void k1EA::BeginOfEventAction(const G4Event* event)
{
  G4int evtNb = event->GetEventID();
  if (evtNb%100000 == 0) 
    G4cout << "\n---> Begin of event: " << evtNb/100000 <<" "<< G4endl;
 
}

void k1EA::EndOfEventAction(const G4Event* event)
{  
  //       // Get hits collections IDs (only once)
  if ( _edep_HCID == -1 ) 
  {
    // _edep_HCID 
    //   = G4SDManager::GetSDMpointer()->GetCollectionID("edep");
    // _charge_HCID
      // = G4SDManager::GetSDMpointer()->GetCollectionID("charge");


      //     _det5cm_HCID 
      // = G4SDManager::GetSDMpointer()->GetCollectionID("flux5cm");
      //     _det10cm_HCID 
      // = G4SDManager::GetSDMpointer()->GetCollectionID("flux10cm");
      //     _det15cm_HCID 
      // = G4SDManager::GetSDMpointer()->GetCollectionID("flux15cm");
  }
  
// // Get HCs object
// auto _phantomHC = GetphantomHitsCollection(_edep_HCID, event);
// auto _det5cmHC = GetphantomHitsCollection(_det5cm_HCID, event);
// auto _det10cmHC = GetphantomHitsCollection(_det10cm_HCID, event);
// auto _det15cmHC = GetphantomHitsCollection(_det15cm_HCID, event);

// // auto _chamberHC = GetchamberHitsCollection(_charge_HCID,event);

// // HCs object lenght
// auto phantomHC_lenght = _phantomHC->entries();
// // auto chamberHC_lenght = _chamberHC->entries();
// auto _det5cmHC_lenght = _det5cmHC->entries();
// auto _det10cmHC_lenght = _det10cmHC->entries();
// auto _det15cmHC_lenght = _det15cmHC->entries();


//fill flux histogram //5cm
// for(size_t i=0;i<_det5cmHC_lenght;i++)
// {
//   auto _hit = (*_det5cmHC)[i];
//   _histo->Fill_Histogram_ALLPHOTONS5cm(_hit->Get_Histogram_ALLPHOTONS_Energy());
//   _histo->Fill_Histogram_SCATTERED_PHOTONS5cm(_hit->Get_Histogram_SCATTERED_Energy());
//   _histo->Fill_Histogram_ELECTRONS5cm(_hit->Get_Histogram_ELECTRONS_Energy());

// }

// for(size_t i=0;i<_det10cmHC_lenght;i++)
// {
//   auto _hit = (*_det10cmHC)[i];
//   _histo->Fill_Histogram_ALLPHOTONS10cm(_hit->Get_Histogram_ALLPHOTONS_Energy());
//   _histo->Fill_Histogram_SCATTERED_PHOTONS10cm(_hit->Get_Histogram_SCATTERED_Energy());
//   _histo->Fill_Histogram_ELECTRONS10cm(_hit->Get_Histogram_ELECTRONS_Energy());

// }

// for(size_t i=0;i<_det15cmHC_lenght;i++)
// {
//   auto _hit = (*_det15cmHC)[i];
//   _histo->Fill_Histogram_ALLPHOTONS15cm(_hit->Get_Histogram_ALLPHOTONS_Energy());
//   _histo->Fill_Histogram_SCATTERED_PHOTONS15cm(_hit->Get_Histogram_SCATTERED_Energy());
//   _histo->Fill_Histogram_ELECTRONS15cm(_hit->Get_Histogram_ELECTRONS_Energy());

// }



//charge
// G4double sum=0;
// for(size_t i=0;i<chamberHC_lenght;i++)
// {
//   auto _hit = (*_chamberHC)[i];
//   sum+=_hit->GetCharge();
// }
// _runAction->SumCharge(sum);
}  
