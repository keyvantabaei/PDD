#ifndef detectorSD5cm_h
#define detectorSD5cm_h 1

#include "G4VSensitiveDetector.hh"
#include "detectorSD5cmHit.hh"
class G4Step;
class G4HCofThisEvent;
class detectorSD5cm : public G4VSensitiveDetector
{
public:
detectorSD5cm(const G4String& name,const G4String& HCname);
virtual ~detectorSD5cm();
virtual void Initialize(G4HCofThisEvent* hc);
virtual G4bool ProcessHits(G4Step* step,G4TouchableHistory*);
virtual void EndOfEvent(G4HCofThisEvent*);
private:
detectorSD5cmHC* _detectorSD5cmHC;
};
#endif