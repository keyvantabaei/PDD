
#include "k1DC.hh"
#include "G4SDManager.hh"
#include "k1Geometery.cc"
// #include "chamberSD.hh"
#include "phantomSD.hh"
#include "detectorSD5cm.hh"
#include "detectorSD10cm.hh"
#include "detectorSD15cm.hh"
#include <math.h>

k1DC::k1DC():G4VUserDetectorConstruction(),_phantom_size(G4ThreeVector(0,0,0))
{
}
k1DC::~k1DC()
{
}

G4VPhysicalVolume* k1DC::Construct()
{
          G4double a=10*cm;
          G4double b=10*cm;
          G4double SSD=100*cm;
    SetPhantomSize(G4ThreeVector(20*cm,20*cm,20*cm));
    SetCellCount(G4ThreeVector(100,100,100));
    // G4ThreeVector detector_size=G4ThreeVector(1*mm,1*mm,_phantom_size.z());
    Geometery geo;
    Struct _world =geo.Box("world","air",G4ThreeVector(2.5*m,2.5*m,2.5*m),G4ThreeVector(),0);
    Struct _phantom= geo.Box("waterphantom","water",_phantom_size,G4ThreeVector(0,0,_phantom_size.z()/2+SSD),_world._logic);
    _phantom_detector=_phantom._logic;
    _phantom_detector=geo.NestedParameterization(_phantom_detector,_phantom_size,_cell_count,"water");
//      Struct _detector= geo.Box("detectorphantom","water",detector_size,G4ThreeVector(0,0,0),_phantom._logic);
//     _phantom_detector=_detector._logic;
//     _phantom_detector=geo.NestedParameterization(_phantom_detector,detector_size,_cell_count,"water");

// geo.Box("waterphantom","water",G4ThreeVector(1*m,1*m,1*cm),G4ThreeVector(0,0,-80*cm),_world._logic);





// //source capsol

// //sizes

//           G4double cap_lenght=3.67*cm;
//           G4double cap_steel_lenght=2.44*cm;
//           G4double cap_radius=1.83*cm;
//           G4double cap_steel_radius=1.5*cm;
//           G4double cap_thickness=cap_radius-cap_steel_radius;
//           G4double cap_tungsten_radius=1.5*cm;
//           G4double cap_tungsten_lenght=0.12*cm;
//           G4double steel_front_plate_thichness=0.11*cm;
//           G4double source_lenght=1*cm;

//     Struct _tube= geo.HollowCylander("capsul","steel",std::make_tuple(0,cap_radius,cap_lenght,0,360*deg),std::make_tuple(0,cap_steel_radius,cap_steel_lenght+cap_tungsten_lenght+source_lenght,0,360*deg),G4ThreeVector(0,0,steel_front_plate_thichness/2),G4ThreeVector(0,0,cap_lenght/2),G4ThreeVector(0,0,0),_world._logic);
//     geo.Tube("steel1","steel",0,cap_steel_radius,cap_steel_lenght,0,360*deg,G4ThreeVector(0,0,cap_steel_lenght+steel_front_plate_thichness+source_lenght  - cap_steel_lenght/2),G4ThreeVector(),_world._logic);
//     geo.Tube("tungsten","tungsten",0,cap_tungsten_radius,cap_tungsten_lenght,0,360*deg,G4ThreeVector(0,0,cap_lenght-cap_tungsten_lenght/2 ),G4ThreeVector(),_world._logic);






    // colimators
    //sizes


          G4double primary_trapzoid_y=25*cm;
          G4double primary_trapzoid_z=b;
          G4double primary_trapzoid_x0=9.5*cm;
          G4double primary_trapzoid_x1=10*cm;
          G4double PoriginX=primary_trapzoid_x1/4-primary_trapzoid_x0/4+primary_trapzoid_x1/2;
          G4double dx=primary_trapzoid_x1-primary_trapzoid_x0;
          G4double m=-primary_trapzoid_y/dx;
          G4double opening=a/2-(-SSD)/m;

// opening=0;
    // geo.GenericTrapezoid("T1","pb",primary_trapzoid_z,primary_trapzoid_y,primary_trapzoid_x0,primary_trapzoid_x1,G4ThreeVector(-PoriginX-opening,0,-primary_trapzoid_y/2),G4ThreeVector(-90*deg,0,0),_world._logic)._logic;
    // geo.GenericTrapezoid("T2","pb",primary_trapzoid_z,primary_trapzoid_y,primary_trapzoid_x0,primary_trapzoid_x1,G4ThreeVector(PoriginX+opening,0,-primary_trapzoid_y/2),G4ThreeVector(-90*deg,180*deg,0),_world._logic)._logic;


//Wedge
double _90deg=1.5707963268;
G4double wedge_z=b;
G4double wedge_x1=a;
G4double wedge_x0=0.01*cm;
G4double wedge_y=tan((1*_90deg)/6)*wedge_x1;
G4double originX=wedge_y/4-wedge_x0/4+wedge_y/2;
// G4cout<<"---------------------------------->>"<< tan((1*_90deg)/2)<<G4endl;
    // geo.GenericTrapezoid("T2","pb",wedge_z,wedge_x1,wedge_x0,wedge_y,G4ThreeVector(0,0,wedge_x1/2-SSD),G4ThreeVector(90*deg,0,90*deg),_world._logic)._logic;
    // _detector5cm= geo.Box("waterphantom","vaccum",G4ThreeVector(a,b,1*cm),G4ThreeVector(0,0,-SSD),_world._logic)._logic;

// geo.Trapezoid("T2","pb",10*cm,10*cm,10*cm,5*cm,10*cm,G4ThreeVector(0,0,0),_world._logic);


    // _phantom_detector=geo.Tube("phantom","vaccum",0,10*cm,1*cm,0,360*deg,G4ThreeVector(0,0,-primary_trapzoid_y-primary_trapzoid_y-(SSD-primary_trapzoid_y-primary_trapzoid_y)),G4ThreeVector(),_world._logic)._logic;
    //  _detector5cm=geo.Tube("detector5cm","vaccum",0,5*cm,1*cm,0,360*deg,G4ThreeVector(0,0,-primary_trapzoid_y-primary_trapzoid_y-(SSD-primary_trapzoid_y-primary_trapzoid_y)),G4ThreeVector(),_world._logic)._logic;
    //  _detector10cm=geo.Tube("detector10cm","vaccum",0,10*cm,1*cm,0,360*deg,G4ThreeVector(0,0,-primary_trapzoid_y-primary_trapzoid_y-(SSD-primary_trapzoid_y-primary_trapzoid_y)),G4ThreeVector(),_world._logic)._logic;
    //  _detector15cm=geo.Tube("detector15cm","vaccum",0,15*cm,1*cm,0,360*deg,G4ThreeVector(0,0,-primary_trapzoid_y-primary_trapzoid_y-(SSD-primary_trapzoid_y-primary_trapzoid_y)),G4ThreeVector(),_world._logic)._logic;


return _world._physical;
}
void k1DC::ConstructSDandField()
{
  // chamberSD* _ion_chamber_SD = new phantomSD("k1/chamberSD","charge");
  // detectorSD5cm* _detectorSD5cm = new detectorSD5cm("k1/detectorSD5cm","flux5cm");
  // detectorSD10cm* _detectorSD10cm = new detectorSD10cm("k1/detectorSD10cm","flux10cm");
  //   detectorSD15cm* _detectorSD15cm = new detectorSD15cm("k1/detectorSD15cm","flux15cm");

  // G4SDManager::GetSDMpointer()->AddNewDetector(_ion_chamber_SD);
  // G4SDManager::GetSDMpointer()->AddNewDetector(_detectorSD5cm);
  // G4SDManager::GetSDMpointer()->AddNewDetector(_detectorSD10cm);
  // G4SDManager::GetSDMpointer()->AddNewDetector(_detectorSD15cm);

  // SetSensitiveDetector(_ion_chamber,_ion_chamber_SD);
  // SetSensitiveDetector(_detector5cm,_detectorSD5cm);
  // SetSensitiveDetector(_detector10cm,_detectorSD10cm);
  // SetSensitiveDetector(_detector15cm,_detectorSD15cm);


  phantomSD* _water_phantom_SD = new phantomSD("k1/phantomSD","edep");
  G4SDManager::GetSDMpointer()->AddNewDetector(_water_phantom_SD);
  SetSensitiveDetector(_phantom_detector,_water_phantom_SD);


}