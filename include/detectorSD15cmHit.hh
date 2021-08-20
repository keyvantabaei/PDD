#ifndef detectorSD15cmHit_h
#define detectorSD15cmHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh"

class detectorSD15cmHit : public G4VHit
{
public:
//Construct and De-Construct Methods
detectorSD15cmHit();
virtual ~detectorSD15cmHit();
detectorSD15cmHit(const detectorSD15cmHit&);

//Virtual Method
virtual void Print();
virtual void Draw();

//operators
const detectorSD15cmHit& operator=(const detectorSD15cmHit&);
G4bool operator==(const detectorSD15cmHit&) const;
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

typedef G4THitsCollection<detectorSD15cmHit> detectorSD15cmHC;
extern G4ThreadLocal G4Allocator<detectorSD15cmHit>* phantomAllocator15cm;
inline void* detectorSD15cmHit::operator new (size_t)
{
if(!phantomAllocator15cm)
phantomAllocator15cm = new G4Allocator<detectorSD15cmHit>;
return (void*)phantomAllocator15cm->MallocSingle();
}

inline void detectorSD15cmHit::operator delete(void *hit)
{
    phantomAllocator15cm->FreeSingle((detectorSD15cmHit*) hit);
}
#endif