#include <TTree.h>
#include <TFile.h>
#include <TH1D.h>

void plot() 
{ 
  // TFile* f = new TFile("result.root");          
  // TCanvas* c1 = new TCanvas("c1", "  ");
  // TCanvas* c2 = new TCanvas("c2", "  ");
  // TCanvas* c3 = new TCanvas("c3", "  ");
  // TH1D* hist1 = (TH1D*)f->Get("APH5cm");
  // TH1D* hist2 = (TH1D*)f->Get("SPH5cm");
  // TH1D* hist3 = (TH1D*)f->Get("E5cm");
  // hist1->Draw("HIST");
  // hist1->SetTitle("ALL Photons From Source Region ; Energy (keV) ; Photons Per 50 keV");
  // c1->cd();
  // c1->Update(); 
  // hist2->Draw("HIST");
  // hist2->SetTitle("Scattered Photons From Source Region ; Energy (keV) ; Photons Per 50 keV");
  // c2->cd();
  // c2->Update(); 
  // hist3->Draw("HIST");
  // hist3->SetTitle("Scattered Electrons From Source Region ; Energy (keV) ; Photons Per 50 keV");
  // c3->cd();
  // c3->Update();
 

  // TCanvas* c4 = new TCanvas("c4", "  ");
  // TCanvas* c5 = new TCanvas("c5", "  ");
  // TCanvas* c6 = new TCanvas("c6", "  ");
  // TH1D* hist4 = (TH1D*)f->Get("APH10cm");
  // TH1D* hist5 = (TH1D*)f->Get("SPH10cm");
  // TH1D* hist6 = (TH1D*)f->Get("E10cm");
  // hist4->Draw("HIST");
  // hist4->SetTitle("ALL Photons From Source Region ; Energy (keV) ; Photons Per 50 keV");
  // c4->cd();
  // c4->Update(); 
  // hist5->Draw("HIST");
  // hist5->SetTitle("Scattered Photons From Source Region ; Energy (keV) ; Photons Per 50 keV");
  // c5->cd();
  // c5->Update(); 
  // hist6->Draw("HIST");
  // hist6->SetTitle("Scattered Electrons From Source Region ; Energy (keV) ; Photons Per 50 keV");
  // c6->cd();
  // c6->Update();






  // TCanvas* c7 = new TCanvas("c7", "  ");
  // TCanvas* c8 = new TCanvas("c8", "  ");
  // TCanvas* c9 = new TCanvas("c9", "  ");
  // TH1D* hist7 = (TH1D*)f->Get("APH15cm");
  // TH1D* hist8 = (TH1D*)f->Get("SPH15cm");
  // TH1D* hist9 = (TH1D*)f->Get("E15cm");
  // hist7->Draw("HIST");
  // hist7->SetTitle("ALL Photons From Source Region ; Energy (keV) ; Photons Per 50 keV");
  // c7->cd();
  // c7->Update(); 
  // hist8->Draw("HIST");
  // hist8->SetTitle("Scattered Photons From Source Region ; Energy (keV) ; Photons Per 50 keV");
  // c8->cd();
  // c8->Update(); 
  // hist9->Draw("HIST");
  // hist9->SetTitle("Scattered Electrons From Source Region ; Energy (keV) ; Photons Per 50 keV");
  // c9->cd();
  // c9->Update();



TFile* f =new TFile("result.root");  
TCanvas* c1 = new TCanvas("c1", "  ");
TTree* tree = (TTree*)f->Get("Ntuple1");
tree->Draw("edep:Z");
c1->cd();
c1->Update(); 
// htemp->SetTitle("Energy Deposit Water Phantom ; Depth (mm) ; Energy (keV)");
// Double_t edep;
// tree->SetBranchAddress("edep",&edep);
// TH1D *hpx   = new TH1D("h1","edep distribution",500,0,0.5);
// //read all entries and fill the histograms
// Long64_t nentries = tree->GetEntries();
// for (Long64_t i=0;i<nentries;i++) 
// {
// tree->GetEntry(i);
// hpx->Fill(edep);
// }
// hpx->Draw();
}

