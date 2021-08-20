#ifndef detectorSD10cmHit_h
#define detectorSD10cmHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "tls.hh"

class detectorSD10cmHit : public G4VHit
{
public:
//Construct and De-Construct Methods
detectorSD10cmHit();
virtual ~detectorSD10cmHit();
detectorSD10cmHit(const detectorSD10cmHit&);

//Virtual Method
virtual void Print();
virtual void Draw();

//operators
const detectorSD10cmHit& operator=(const detectorSD10cmHit&);
G4bool operator==(const detectorSD10cmHit&) const;
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

typedef G4THitsCollection<detectorSD10cmHit> detectorSD10cmHC;
extern G4ThreadLocal G4Allocator<detectorSD10cmHit>* phantomAllocator10cm;
inline void* detectorSD10cmHit::operator new (size_t)
{
if(!phantomAllocator10cm)
phantomAllocator10cm = new G4Allocator<detectorSD10cmHit>;
return (void*)phantomAllocator10cm->MallocSingle();
}

inline void detectorSD10cmHit::operator delete(void *hit)
{
    phantomAllocator10cm->FreeSingle((detectorSD10cmHit*) hit);
}
#endif