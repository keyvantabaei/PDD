#ifndef detectorSD5cmHit_h
#define detectorSD5cmHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh"

class detectorSD5cmHit : public G4VHit
{
public:
//Construct and De-Construct Methods
detectorSD5cmHit();
virtual ~detectorSD5cmHit();
detectorSD5cmHit(const detectorSD5cmHit&);

//Virtual Method
virtual void Print();
virtual void Draw();

//operators
const detectorSD5cmHit& operator=(const detectorSD5cmHit&);
G4bool operator==(const detectorSD5cmHit&) const;
inline void* operator new (size_t);
inline void operator delete(void*);

void Set_Histogram_ALLPHOTONS_Energy(G4double e){_all_energy=e;}
G4double Get_Histogram_ALLPHOTONS_Energy(){return _all_energy;}

void Set_Histogram_SCATTERED_Energy(G4double e){_sacattered_energy=e;}
G4double Get_Histogram_SCATTERED_Energy(){return _sacattered_energy;}

void Set_Histogram_ELECTRONS_Energy(G4double e){_electron_energy=e;}
G4double Get_Histogram_ELECTRONS_Energy(){return _electron_energy;}

std::tuple<G4double,G4double> Get_CopyNo_Dose_tuple(){return CopyNo_Dose;}


private:
std::tuple<G4double,G4double> CopyNo_Dose;
G4double _all_energy;
G4double _sacattered_energy;
G4double _electron_energy;

};

typedef G4THitsCollection<detectorSD5cmHit> detectorSD5cmHC;
extern G4ThreadLocal G4Allocator<detectorSD5cmHit>* phantomAllocator5cm;
inline void* detectorSD5cmHit::operator new (size_t)
{
if(!phantomAllocator5cm)
phantomAllocator5cm = new G4Allocator<detectorSD5cmHit>;
return (void*)phantomAllocator5cm->MallocSingle();
}

inline void detectorSD5cmHit::operator delete(void *hit)
{
    phantomAllocator5cm->FreeSingle((detectorSD5cmHit*) hit);
}
#endif