#ifndef detectorSD15cm_h
#define detectorSD15cm_h 1

#include "G4VSensitiveDetector.hh"
#include "detectorSD15cmHit.hh"
class G4Step;
class G4HCofThisEvent;
class detectorSD15cm : public G4VSensitiveDetector
{
public:
detectorSD15cm(const G4String& name,const G4String& HCname);
virtual ~detectorSD15cm();
virtual void Initialize(G4HCofThisEvent* hc);
virtual G4bool ProcessHits(G4Step* step,G4TouchableHistory*);
virtual void EndOfEvent(G4HCofThisEvent*);
private:
detectorSD15cmHC* _detectorSD15cmHC;
};
#endif