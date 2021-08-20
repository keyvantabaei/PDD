#include "detectorSD15cmHit.hh"
#include "G4VHit.hh"
#include "G4ThreeVector.hh"
#include "G4Allocator.hh"
#include <iomanip>
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
G4ThreadLocal G4Allocator<detectorSD15cmHit>* phantomAllocator15cm=0;

detectorSD15cmHit::detectorSD15cmHit():G4VHit()
{
CopyNo_Dose=std::make_tuple(0,0);
_all_energy=-1;
_sacattered_energy=-1;
_electron_energy=-1;

}

detectorSD15cmHit::~detectorSD15cmHit(){}

detectorSD15cmHit::detectorSD15cmHit(const detectorSD15cmHit& K1BH):G4VHit()
{
    CopyNo_Dose=K1BH.CopyNo_Dose;
    _all_energy=K1BH._all_energy;
    _sacattered_energy=K1BH._sacattered_energy;
    _electron_energy=K1BH._electron_energy;

}
const detectorSD15cmHit& detectorSD15cmHit::operator=(const detectorSD15cmHit& K1BH)
{
    CopyNo_Dose=K1BH.CopyNo_Dose;
    _all_energy=K1BH._all_energy;
    _sacattered_energy=K1BH._sacattered_energy;
    _electron_energy=K1BH._electron_energy;    return *this;
}

G4bool detectorSD15cmHit::operator==(const detectorSD15cmHit& K1BH) const
{
    return (this == &K1BH) ? true : false;
}

void detectorSD15cmHit::Print()
{
}

void detectorSD15cmHit::Draw()
{
}