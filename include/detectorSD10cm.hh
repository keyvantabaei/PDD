#ifndef detectorSD10cm_h
#define detectorSD10cm_h 1

#include "G4VSensitiveDetector.hh"
#include "detectorSD10cmHit.hh"
class G4Step;
class G4HCofThisEvent;
class detectorSD10cm : public G4VSensitiveDetector
{
public:
detectorSD10cm(const G4String& name,const G4String& HCname);
virtual ~detectorSD10cm();
virtual void Initialize(G4HCofThisEvent* hc);
virtual G4bool ProcessHits(G4Step* step,G4TouchableHistory*);
virtual void EndOfEvent(G4HCofThisEvent*);
private:
detectorSD10cmHC* _detectorSD10cmHC;
};
#endif