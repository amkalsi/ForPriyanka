#include "./MuTauFakeRate.h"                                                                                                                                        
#include "DataFormats/TrackReco/interface/HitPattern.h"

MuTauFakeRate::MuTauFakeRate(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
{
  
  //now do what ever initialization is needed
  _MatchLeptonToGen = iConfig.getParameter<bool>("MatchLeptonToGen");                                                                                        
  _UseLeptonMotherId = iConfig.getParameter<bool>("UseLeptonMotherId");
  _UseLeptonGrandMotherId = iConfig.getParameter<bool>("UseLeptonGrandMotherId");
  _LeptonMotherId = iConfig.getParameter<int>("LeptonMotherId");
  _LeptonGrandMotherId = iConfig.getParameter<int>("LeptonGrandMotherId");
  _MatchTauToGen = iConfig.getParameter<bool>("MatchTauToGen");
  _UseTauMotherId = iConfig.getParameter<bool>("UseTauMotherId");
  _UseTauGrandMotherId = iConfig.getParameter<bool>("UseTauGrandMotherId");
  _TauMotherId = iConfig.getParameter<int>("TauMotherId");
  _TauGrandMotherId = iConfig.getParameter<int>("TauGrandMotherId");
  _TauToGenMatchingDeltaR = iConfig.getParameter<double>("TauToGenMatchingDeltaR");
 etacut = iConfig.getParameter<double>("etacut");
etacutmin = iConfig.getParameter<double>("etacutmin");
  //h_RPC_FourthStation_etag1p2 = fs->make<TH1F>(("h_RPC_FourthStation_etag1p2"+prefix).c_str() ,"h_RPC_FourthStation_etag1p2",15,0,15);

  Nvtx_DMF = fs->make<TH1F>(("Nvtx_DMF"+prefix).c_str() ,"Nvtx_DMF",200,0,200);            
  NGood_DMF = fs->make<TH1F>(("NGood_DMF"+prefix).c_str() ,"NGood_DMF",200,0,200);
  
  
  Nvtx_num = fs->make<TH1F>(("Nvtx_num"+prefix).c_str() ,"Nvtx_num",200,0,200);            
  NGood_num = fs->make<TH1F>(("NGood_num"+prefix).c_str() ,"NGood_num",200,0,200);

  Nvtx_num_tight = fs->make<TH1F>(("Nvtx_num_tight"+prefix).c_str() ,"Nvtx_num_tight",200,0,200); 
  NGood_num_tight = fs->make<TH1F>(("NGood_num_tight"+prefix).c_str() ,"NGood_num_tight",200,0,200);
  
  Nvtx_num_E = fs->make<TH1F>(("Nvtx_num_E"+prefix).c_str() ,"Nvtx_num_E",200,0,200);
  NGood_num_E = fs->make<TH1F>(("NGood_num_E"+prefix).c_str() ,"NGood_num_E",200,0,200);

  Nvtx_num_tight_E = fs->make<TH1F>(("Nvtx_num_tight_E"+prefix).c_str() ,"Nvtx_num_tight_E",200,0,200);
  NGood_num_tight_E = fs->make<TH1F>(("NGood_num_tight_E"+prefix).c_str() ,"NGood_num_tight_E",200,0,200);

  //

  Nvtx_numT = fs->make<TH1F>(("Nvtx_numT"+prefix).c_str() ,"Nvtx_numT",200,0,200);            
  NGood_numT = fs->make<TH1F>(("NGood_numT"+prefix).c_str() ,"NGood_numT",200,0,200);

  Nvtx_numT_E = fs->make<TH1F>(("Nvtx_numT_E"+prefix).c_str() ,"Nvtx_numT_E",200,0,200);            
  NGood_numT_E = fs->make<TH1F>(("NGood_numT_E"+prefix).c_str() ,"NGood_numT_E",200,0,200);

  Nvtx_num_tightT = fs->make<TH1F>(("Nvtx_num_tightT"+prefix).c_str() ,"Nvtx_num_tightT",200,0,200);            
  NGood_num_tightT = fs->make<TH1F>(("NGood_num_tightT"+prefix).c_str() ,"NGood_num_tightT",200,0,200);

  Nvtx_num_tightT_E = fs->make<TH1F>(("Nvtx_num_tightT_E"+prefix).c_str() ,"Nvtx_num_tightT_E",200,0,200);            
  NGood_num_tightT_E = fs->make<TH1F>(("NGood_num_tightT_E"+prefix).c_str() ,"NGood_num_tightT_E",200,0,200);


  Nvtx_numM = fs->make<TH1F>(("Nvtx_numM"+prefix).c_str() ,"Nvtx_numM",200,0,200);            
  NGood_numM = fs->make<TH1F>(("NGood_numM"+prefix).c_str() ,"NGood_numM",200,0,200);

  Nvtx_numM_E = fs->make<TH1F>(("Nvtx_numM_E"+prefix).c_str() ,"Nvtx_numM_E",200,0,200);  
  NGood_numM_E = fs->make<TH1F>(("NGood_numM_E"+prefix).c_str() ,"NGood_numM_E",200,0,200);

  Nvtx_num_tightM = fs->make<TH1F>(("Nvtx_num_tightM"+prefix).c_str() ,"Nvtx_num_tightM",200,0,200);            
  NGood_num_tightM = fs->make<TH1F>(("NGood_num_tightM"+prefix).c_str() ,"NGood_num_tightM",200,0,200);

  
  Nvtx_num_tightM_E = fs->make<TH1F>(("Nvtx_num_tightM_E"+prefix).c_str() ,"Nvtx_num_tightM_E",200,0,200);            
  NGood_num_tightM_E = fs->make<TH1F>(("NGood_num_tightM_E"+prefix).c_str() ,"NGood_num_tightM_E",200,0,200);

  Nvtx_den = fs->make<TH1F>(("Nvtx_den"+prefix).c_str() ,"Nvtx_den",200,0,200);            
  NGood_den = fs->make<TH1F>(("NGood_den"+prefix).c_str() ,"NGood_den",200,0,200);
  
  
  h_PfTau_pT_DMF = fs->make<TH1F>(("h_PfTau_pT_DMF"+prefix).c_str() ,"h_PfTau_pT_DMF",100,0,700);
  h_PfTau_Eta_DMF = fs->make<TH1F>(("h_PfTau_Eta_DMF"+prefix).c_str() ,"h_PfTau_Eta_DMF",100,-5,5);
  h_PfTau_Phi_DMF = fs->make<TH1F>(("h_PfTau_Phi_DMF"+prefix).c_str() ,"h_PfTau_Phi_DMF",100,-5,5);
  h_genMuon_pT_DMF = fs->make<TH1F>(("h_genMuon_pT_DMF"+prefix).c_str() ,"h_genMuon_pT_DMF",100,0,700);
  h_genMuon_Eta_DMF = fs->make<TH1F>(("h_genMuon_Eta_DMF"+prefix).c_str() ,"h_genMuon_Eta_DMF",100,-5,5);
  h_genMuon_Phi_DMF = fs->make<TH1F>(("h_genMuon_Phi_DMF"+prefix).c_str() ,"h_genMuon_Phi_DMF",100,-5,5); 

  h_PfTau_pT_den = fs->make<TH1F>(("h_PfTau_pT_den"+prefix).c_str() ,"h_PfTau_pT_den",100,0,700);
  h_PfTau_Eta_den = fs->make<TH1F>(("h_PfTau_Eta_den"+prefix).c_str() ,"h_PfTau_Eta_den",100,-5,5);
  h_PfTau_Phi_den = fs->make<TH1F>(("h_PfTau_Phi_den"+prefix).c_str() ,"h_PfTau_Phi_den",100,-5,5);
  h_genMuon_pT_den = fs->make<TH1F>(("h_genMuon_pT_den"+prefix).c_str() ,"h_genMuon_pT_den",100,0,700);
  h_genMuon_Eta_den = fs->make<TH1F>(("h_genMuon_Eta_den"+prefix).c_str() ,"h_genMuon_Eta_den",100,-5,5);
  h_genMuon_Phi_den = fs->make<TH1F>(("h_genMuon_Phi_den"+prefix).c_str() ,"h_genMuon_Phi_den",100,-5,5); 

  h_PfTau_pT_num = fs->make<TH1F>(("h_PfTau_pT_num"+prefix).c_str() ,"h_PfTau_pT_num",100,0,700);
  h_PfTau_Eta_num = fs->make<TH1F>(("h_PfTau_Eta_num"+prefix).c_str() ,"h_PfTau_Eta_num",100,-5,5);
  h_PfTau_Phi_num = fs->make<TH1F>(("h_PfTau_Phi_num"+prefix).c_str() ,"h_PfTau_Phi_num",100,-5,5);
  h_genMuon_pT_num = fs->make<TH1F>(("h_genMuon_pT_num"+prefix).c_str() ,"h_genMuon_pT_num",100,0,700);
  h_genMuon_Eta_num = fs->make<TH1F>(("h_genMuon_Eta_num"+prefix).c_str() ,"h_genMuon_Eta_num",100,-5,5); 
  h_genMuon_Phi_num = fs->make<TH1F>(("h_genMuon_Phi_num"+prefix).c_str() ,"h_genMuon_Phi_num",100,-5,5); 
 

  //

  h_PfTau_pT_num_E = fs->make<TH1F>(("h_PfTau_pT_num_E"+prefix).c_str() ,"h_PfTau_pT_num_E",100,0,700);
  h_PfTau_Eta_num_E = fs->make<TH1F>(("h_PfTau_Eta_num_E"+prefix).c_str() ,"h_PfTau_Eta_num_E",100,-5,5);
  h_PfTau_Phi_num_E = fs->make<TH1F>(("h_PfTau_Phi_num_E"+prefix).c_str() ,"h_PfTau_Phi_num_E",100,-5,5);
  h_genMuon_pT_num_E = fs->make<TH1F>(("h_genMuon_pT_num_E"+prefix).c_str() ,"h_genMuon_pT_num_E",100,0,700);
  h_genMuon_Eta_num_E = fs->make<TH1F>(("h_genMuon_Eta_num_E"+prefix).c_str() ,"h_genMuon_Eta_num_E",100,-5,5); 
  h_genMuon_Phi_num_E = fs->make<TH1F>(("h_genMuon_Phi_num_E"+prefix).c_str() ,"h_genMuon_Phi_num_E",100,-5,5); 
 

  //
  h_PfTau_pT_num_tight = fs->make<TH1F>(("h_PfTau_pT_num_tight"+prefix).c_str() ,"h_PfTau_pT_num_tight",100,0,700);
  h_PfTau_Eta_num_tight = fs->make<TH1F>(("h_PfTau_Eta_num_tight"+prefix).c_str() ,"h_PfTau_Eta_num_tight",100,-5,5);
  h_PfTau_Phi_num_tight = fs->make<TH1F>(("h_PfTau_Phi_num_tight"+prefix).c_str() ,"h_PfTau_Phi_num_tight",100,-5,5);
  h_genMuon_pT_num_tight = fs->make<TH1F>(("h_genMuon_pT_num_tight"+prefix).c_str() ,"h_genMuon_pT_num_tight",100,0,700);
  h_genMuon_Eta_num_tight = fs->make<TH1F>(("h_genMuon_Eta_num_tight"+prefix).c_str() ,"h_genMuon_Eta_num_tight",100,-5,5); 
  h_genMuon_Phi_num_tight = fs->make<TH1F>(("h_genMuon_Phi_num_tight"+prefix).c_str() ,"h_genMuon_Phi_num_tight",100,-5,5); 

  ///

  h_PfTau_pT_num_tight_E = fs->make<TH1F>(("h_PfTau_pT_num_tight_E"+prefix).c_str() ,"h_PfTau_pT_num_tight_E",100,0,700);
  h_PfTau_Eta_num_tight_E = fs->make<TH1F>(("h_PfTau_Eta_num_tight_E"+prefix).c_str() ,"h_PfTau_Eta_num_tight_E",100,-5,5);
  h_PfTau_Phi_num_tight_E = fs->make<TH1F>(("h_PfTau_Phi_num_tight_E"+prefix).c_str() ,"h_PfTau_Phi_num_tight_E",100,-5,5);
  h_genMuon_pT_num_tight_E = fs->make<TH1F>(("h_genMuon_pT_num_tight_E"+prefix).c_str() ,"h_genMuon_pT_num_tight_E",100,0,700);
  h_genMuon_Eta_num_tight_E = fs->make<TH1F>(("h_genMuon_Eta_num_tight_E"+prefix).c_str() ,"h_genMuon_Eta_num_tight_E",100,-5,5); 
  h_genMuon_Phi_num_tight_E = fs->make<TH1F>(("h_genMuon_Phi_num_tight_E"+prefix).c_str() ,"h_genMuon_Phi_num_tight_E",100,-5,5); 

  //
  h_PfTau_pT_numM = fs->make<TH1F>(("h_PfTau_pT_numM"+prefix).c_str() ,"h_PfTau_pT_numM",100,0,700);
  h_PfTau_Eta_numM = fs->make<TH1F>(("h_PfTau_Eta_numM"+prefix).c_str() ,"h_PfTau_Eta_numM",100,-5,5);
  h_PfTau_Phi_numM = fs->make<TH1F>(("h_PfTau_Phi_numM"+prefix).c_str() ,"h_PfTau_Phi_numM",100,-5,5);
  h_genMuon_pT_numM = fs->make<TH1F>(("h_genMuon_pT_numM"+prefix).c_str() ,"h_genMuon_pT_numM",100,0,700);
  h_genMuon_Eta_numM = fs->make<TH1F>(("h_genMuon_Eta_numM"+prefix).c_str() ,"h_genMuon_Eta_numM",100,-5,5); 
  h_genMuon_Phi_numM = fs->make<TH1F>(("h_genMuon_Phi_numM"+prefix).c_str() ,"h_genMuon_Phi_numM",100,-5,5); 


  h_PfTau_pT_numM_E = fs->make<TH1F>(("h_PfTau_pT_numM_E"+prefix).c_str() ,"h_PfTau_pT_numM_E",100,0,700);
  h_PfTau_Eta_numM_E = fs->make<TH1F>(("h_PfTau_Eta_numM_E"+prefix).c_str() ,"h_PfTau_Eta_numM_E",100,-5,5);
  h_PfTau_Phi_numM_E = fs->make<TH1F>(("h_PfTau_Phi_numM_E"+prefix).c_str() ,"h_PfTau_Phi_numM_E",100,-5,5);
  h_genMuon_pT_numM_E = fs->make<TH1F>(("h_genMuon_pT_numM_E"+prefix).c_str() ,"h_genMuon_pT_numM_E",100,0,700);
  h_genMuon_Eta_numM_E = fs->make<TH1F>(("h_genMuon_Eta_numM_E"+prefix).c_str() ,"h_genMuon_Eta_numM_E",100,-5,5); 
  h_genMuon_Phi_numM_E = fs->make<TH1F>(("h_genMuon_Phi_numM_E"+prefix).c_str() ,"h_genMuon_Phi_numM_E",100,-5,5); 

  h_PfTau_pT_numT = fs->make<TH1F>(("h_PfTau_pT_numT"+prefix).c_str() ,"h_PfTau_pT_numT",100,0,700);
  h_PfTau_Eta_numT = fs->make<TH1F>(("h_PfTau_Eta_numT"+prefix).c_str() ,"h_PfTau_Eta_numT",100,-5,5);
  h_PfTau_Phi_numT = fs->make<TH1F>(("h_PfTau_Phi_numT"+prefix).c_str() ,"h_PfTau_Phi_numT",100,-5,5);
  h_genMuon_pT_numT = fs->make<TH1F>(("h_genMuon_pT_numT"+prefix).c_str() ,"h_genMuon_pT_numT",100,0,700);
  h_genMuon_Eta_numT = fs->make<TH1F>(("h_genMuon_Eta_numT"+prefix).c_str() ,"h_genMuon_Eta_numT",100,-5,5); 
  h_genMuon_Phi_numT = fs->make<TH1F>(("h_genMuon_Phi_numT"+prefix).c_str() ,"h_genMuon_Phi_numT",100,-5,5); 


  h_PfTau_pT_numT_E = fs->make<TH1F>(("h_PfTau_pT_numT_E"+prefix).c_str() ,"h_PfTau_pT_numT_E",100,0,700);
  h_PfTau_Eta_numT_E = fs->make<TH1F>(("h_PfTau_Eta_numT_E"+prefix).c_str() ,"h_PfTau_Eta_numT_E",100,-5,5);
  h_PfTau_Phi_numT_E = fs->make<TH1F>(("h_PfTau_Phi_numT_E"+prefix).c_str() ,"h_PfTau_Phi_numT_E",100,-5,5);
  h_genMuon_pT_numT_E = fs->make<TH1F>(("h_genMuon_pT_numT_E"+prefix).c_str() ,"h_genMuon_pT_numT_E",100,0,700);
  h_genMuon_Eta_numT_E = fs->make<TH1F>(("h_genMuon_Eta_numT_E"+prefix).c_str() ,"h_genMuon_Eta_numT_E",100,-5,5); 
  h_genMuon_Phi_numT_E = fs->make<TH1F>(("h_genMuon_Phi_numT_E"+prefix).c_str() ,"h_genMuon_Phi_numT_E",100,-5,5); 
 


  h_PfTau_pT_num_tightT = fs->make<TH1F>(("h_PfTau_pT_num_tightT"+prefix).c_str() ,"h_PfTau_pT_num_tightT",100,0,700);
  h_PfTau_Eta_num_tightT = fs->make<TH1F>(("h_PfTau_Eta_num_tightT"+prefix).c_str() ,"h_PfTau_Eta_num_tightT",100,-5,5);
  h_PfTau_Phi_num_tightT = fs->make<TH1F>(("h_PfTau_Phi_num_tightT"+prefix).c_str() ,"h_PfTau_Phi_num_tightT",100,-5,5);
  h_genMuon_pT_num_tightT = fs->make<TH1F>(("h_genMuon_pT_num_tightT"+prefix).c_str() ,"h_genMuon_pT_num_tightT",100,0,700);
  h_genMuon_Eta_num_tightT = fs->make<TH1F>(("h_genMuon_Eta_num_tightT"+prefix).c_str() ,"h_genMuon_Eta_num_tightT",100,-5,5); 
  h_genMuon_Phi_num_tightT = fs->make<TH1F>(("h_genMuon_Phi_num_tightT"+prefix).c_str() ,"h_genMuon_Phi_num_tightT",100,-5,5); 


  h_PfTau_pT_num_tightT_E = fs->make<TH1F>(("h_PfTau_pT_num_tightT_E"+prefix).c_str() ,"h_PfTau_pT_num_tightT_E",100,0,700);
  h_PfTau_Eta_num_tightT_E = fs->make<TH1F>(("h_PfTau_Eta_num_tightT_E"+prefix).c_str() ,"h_PfTau_Eta_num_tightT_E",100,-5,5);
  h_PfTau_Phi_num_tightT_E = fs->make<TH1F>(("h_PfTau_Phi_num_tightT_E"+prefix).c_str() ,"h_PfTau_Phi_num_tightT_E",100,-5,5);
  h_genMuon_pT_num_tightT_E = fs->make<TH1F>(("h_genMuon_pT_num_tightT_E"+prefix).c_str() ,"h_genMuon_pT_num_tightT_E",100,0,700);
  h_genMuon_Eta_num_tightT_E = fs->make<TH1F>(("h_genMuon_Eta_num_tightT_E"+prefix).c_str() ,"h_genMuon_Eta_num_tightT_E",100,-5,5); 
  h_genMuon_Phi_num_tightT_E = fs->make<TH1F>(("h_genMuon_Phi_num_tightT_E"+prefix).c_str() ,"h_genMuon_Phi_num_tightT_E",100,-5,5); 

  h_PfTau_pT_num_tightM = fs->make<TH1F>(("h_PfTau_pT_num_tightM"+prefix).c_str() ,"h_PfTau_pT_num_tightM",100,0,700);
  h_PfTau_Eta_num_tightM = fs->make<TH1F>(("h_PfTau_Eta_num_tightM"+prefix).c_str() ,"h_PfTau_Eta_num_tightM",100,-5,5);
  h_PfTau_Phi_num_tightM = fs->make<TH1F>(("h_PfTau_Phi_num_tightM"+prefix).c_str() ,"h_PfTau_Phi_num_tightM",100,-5,5);
  h_genMuon_pT_num_tightM = fs->make<TH1F>(("h_genMuon_pT_num_tightM"+prefix).c_str() ,"h_genMuon_pT_num_tightM",100,0,700);
  h_genMuon_Eta_num_tightM = fs->make<TH1F>(("h_genMuon_Eta_num_tightM"+prefix).c_str() ,"h_genMuon_Eta_num_tightM",100,-5,5); 
  h_genMuon_Phi_num_tightM = fs->make<TH1F>(("h_genMuon_Phi_num_tightM"+prefix).c_str() ,"h_genMuon_Phi_num_tightM",100,-5,5); 


  h_PfTau_pT_num_tightM_E = fs->make<TH1F>(("h_PfTau_pT_num_tightM_E"+prefix).c_str() ,"h_PfTau_pT_num_tightM_E",100,0,700);
  h_PfTau_Eta_num_tightM_E = fs->make<TH1F>(("h_PfTau_Eta_num_tightM_E"+prefix).c_str() ,"h_PfTau_Eta_num_tightM_E",100,-5,5);
  h_PfTau_Phi_num_tightM_E = fs->make<TH1F>(("h_PfTau_Phi_num_tightM_E"+prefix).c_str() ,"h_PfTau_Phi_num_tightM_E",100,-5,5);
  h_genMuon_pT_num_tightM_E = fs->make<TH1F>(("h_genMuon_pT_num_tightM_E"+prefix).c_str() ,"h_genMuon_pT_num_tightM_E",100,0,700);
  h_genMuon_Eta_num_tightM_E = fs->make<TH1F>(("h_genMuon_Eta_num_tightM_E"+prefix).c_str() ,"h_genMuon_Eta_num_tightM_E",100,-5,5); 
  h_genMuon_Phi_num_tightM_E = fs->make<TH1F>(("h_genMuon_Phi_num_tightM_E"+prefix).c_str() ,"h_genMuon_Phi_num_tightM_E",100,-5,5); 
  

}


MuTauFakeRate::~MuTauFakeRate()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}


//
// member functions
//

// ------------ method called for each event  ------------
void MuTauFakeRate::Fill(const edm::Event& iEvent) {
  using namespace edm;
  using namespace std;
  using namespace reco;
  using namespace pat;

  edm::Handle<reco::VertexCollection> vtx;
  iEvent.getByLabel("offlinePrimaryVertices",vtx);
  
  iEvent.getByLabel("genParticles", _genParticles); 
  
  Handle< reco::TrackCollection > track;
  iEvent.getByLabel("generalTracks", track);
  
  Handle< reco::GenJetCollection > genTauJets;
  iEvent.getByLabel("tauGenJets",genTauJets);
  
  edm::Handle<pat::JetCollection> pfjet;
  iEvent.getByLabel("selectedPatJets", pfjet);
  
  edm::Handle<std::vector< PileupSummaryInfo > >  PupInfo;
  iEvent.getByLabel(std::string("addPileupInfo"), PupInfo);
  
  edm::Handle<reco::MuonCollection> rmuons;
  iEvent.getByLabel("muons",rmuons);
  

  //  vector<pat::Muon>                    "patMuons"                  ""           "PATTuple"  
 
  
  iEvent.getByLabel("ak5GenJets", _genJets);
  
  
  iEvent.getByLabel("hpsPFTauProducer",_hpsTaucoll);
  //decay Mode
   iEvent.getByLabel("hpsPFTauDiscriminationByDecayModeFindingOldDMs",_dmf);
  //Muon Veto

   //Muon 2 working pint
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection2",_mv1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumMuonRejection2",_mv2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection2",_mv3);
   
   // Muon 3 working points

   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection3",_mv31);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection3",_mv32);

   //Electron Veto
     iEvent.getByLabel("hpsPFTauDiscriminationByMediumElectronRejection2",_enew);  
   iEvent.getByLabel("hpsPFTauDiscriminationByMVA5LooseElectronRejection",_ev1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMVA5MediumElectronRejection",_ev2);
   iEvent.getByLabel("hpsPFTauDiscriminationByMVA5TightElectronRejection",_ev3);
   
   // Isolation Working points
   
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseCombinedIsolationDBSumPtCorr",_iso1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumCombinedIsolationDBSumPtCorr",_iso2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightCombinedIsolationDBSumPtCorr",_iso3);
   
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseCombinedIsolationDBSumPtCorr3Hits",_iso4);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumCombinedIsolationDBSumPtCorr3Hits",_iso5);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightCombinedIsolationDBSumPtCorr3Hits",_iso6);
  
  
   iEvent.getByLabel("hpsPFTauDiscriminationByVLooseChargedIsolation",_hpsTau);
   
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseChargedIsolation",_hpsTau1);
   
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumChargedIsolation",_hpsTau2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightChargedIsolation",_hpsTau3);
   
   
  iEvent.getByLabel("hpsPFTauDiscriminationByRawChargedIsolationDBSumPtCorr",_rawCharged);

  iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralIsoPtSumWeight1",_nw1);
  iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralIsoPtSumWeight2",_nw2);
  iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralIsoPtSumWeight1NQ",_nw1nq);

   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralIsoPtSumWeight2NQ",_nw2nq);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralHadronIsoPtSum",_h1);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralHadronIsoPtSumWeight1",_hw1);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralHadronIsoPtSumWeight2",_hw2);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralHadronIsoPtSumWeight1NQ",_hw1nq);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralHadronIsoPtSumWeight2NQ",_hw2nq);
   iEvent.getByLabel("hpsPFTauMVA3IsolationChargedIsoPtSum",_rawc);                                                         
    iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralIsoPtSum",_rawn);
    iEvent.getByLabel("hpsPFTauMVA3IsolationPUcorrPtSum",_rawpu);
    iEvent.getByLabel("hpsPFTauDiscriminationByLooseCombinedIsolationRhoSumPtCorr3Hits",rho1);
    iEvent.getByLabel("hpsPFTauDiscriminationByMediumCombinedIsolationRhoSumPtCorr3Hits",rho2);
    iEvent.getByLabel("hpsPFTauDiscriminationByTightCombinedIsolationRhoSumPtCorr3Hits",rho3);
 
 

  
  
  bool isZMuMu=false;
  isZMuMu = IsZMuMu (_genParticles) ;
 
 int  nGoodVtx = 0;
   for( reco::VertexCollection::const_iterator vtxIt = vtx->begin(); vtxIt != vtx->end(); ++vtxIt){
     
     if((vtxIt->isValid()) && !(vtxIt->isFake())) {
       
       nGoodVtx++;
     }
   }
 
  //isZtautau=true;

   std::vector<PileupSummaryInfo>::const_iterator PVI;
   for (PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
     PUInfo += PVI->getPU_NumInteractions();
     if(PVI->getBunchCrossing()== 0){
       PUInfo_Bunch0 += PVI->getPU_NumInteractions();
       PUInfo_true = PVI->getTrueNumInteractions();
     }
   }
  
  if(isZMuMu) {
    
      
    for(reco::GenParticleCollection::const_iterator genparticles = _genParticles->begin(); genparticles !=  _genParticles->end(); ++genparticles) {
      
      if(genparticles->pt() <= 20) continue;
      if(abs(genparticles->eta()) <= etacutmin) continue;
      if(abs(genparticles->eta()) >= etacut) continue;
      
      if(((abs(genparticles->pdgId()) == 13) && (genparticles->status() ==3))) {
	if(abs(genparticles->mother(0)->pdgId()) == _TauMotherId) {
 
      
          h_genMuon_pT_den->Fill(genparticles->pt());
          h_genMuon_Eta_den->Fill(genparticles->eta());
          h_genMuon_Phi_den->Fill(genparticles->phi());
          Nvtx_den->Fill(PUInfo_true);                                                                                         
          NGood_den->Fill(nGoodVtx);

	  
	   int index1= -1;
    if(OverlapWithGenTauForOther(genparticles->eta() , genparticles->phi() , _hpsTaucoll, _dmf ,index1 )) {   
       if(index1 != -1){
       reco::PFTauRef tauCandidate(_hpsTaucoll, index1);
      h_PfTau_pT_DMF->Fill(tauCandidate->pt());
      h_PfTau_Eta_DMF->Fill(tauCandidate->eta());
      h_PfTau_Phi_DMF->Fill(tauCandidate->phi());
  
      h_genMuon_pT_DMF->Fill(genparticles->pt());
      h_genMuon_Eta_DMF->Fill(genparticles->eta());
      h_genMuon_Phi_DMF->Fill(genparticles->phi());  
      Nvtx_DMF->Fill(PUInfo_true); 
      NGood_DMF->Fill(nGoodVtx);


    if((*_rawc)[tauCandidate] < 4){
      if ((*_mv31)[tauCandidate] > 0.5) { 
	h_PfTau_pT_num->Fill(tauCandidate->pt());
	h_PfTau_Eta_num->Fill(tauCandidate->eta());
	h_PfTau_Phi_num->Fill(tauCandidate->phi());
	h_genMuon_pT_num->Fill(genparticles->pt());
	h_genMuon_Eta_num->Fill(genparticles->eta());
	h_genMuon_Phi_num->Fill(genparticles->phi());    
	Nvtx_num->Fill(PUInfo_true);
	NGood_num->Fill(nGoodVtx);
	//Fill Reco 
	//electronid

      if ((*_enew)[tauCandidate] > 0.5) { 
	h_PfTau_pT_num_E->Fill(tauCandidate->pt());
	h_PfTau_Eta_num_E->Fill(tauCandidate->eta());
	h_PfTau_Phi_num_E->Fill(tauCandidate->phi());
	h_genMuon_pT_num_E->Fill(genparticles->pt());
	h_genMuon_Eta_num_E->Fill(genparticles->eta());
	h_genMuon_Phi_num_E->Fill(genparticles->phi());    
	Nvtx_num_E->Fill(PUInfo_true);
	NGood_num_E->Fill(nGoodVtx);

      }
      }
      // tight wp
      
      if ((*_mv32)[tauCandidate] > 0.5) {
	h_PfTau_pT_num_tight->Fill(tauCandidate->pt());
	h_PfTau_Eta_num_tight->Fill(tauCandidate->eta());
	h_PfTau_Phi_num_tight->Fill(tauCandidate->phi());
	h_genMuon_pT_num_tight->Fill(genparticles->pt());
	h_genMuon_Eta_num_tight->Fill(genparticles->eta());
	h_genMuon_Phi_num_tight->Fill(genparticles->phi()); 
	Nvtx_num_tight->Fill(PUInfo_true); 
	NGood_num_tight->Fill(nGoodVtx);


        if ((*_enew)[tauCandidate] > 0.5) { 
	h_PfTau_pT_num_tight_E->Fill(tauCandidate->pt());
	h_PfTau_Eta_num_tight_E->Fill(tauCandidate->eta());
	h_PfTau_Phi_num_tight_E->Fill(tauCandidate->phi());
	h_genMuon_pT_num_tight_E->Fill(genparticles->pt());
	h_genMuon_Eta_num_tight_E->Fill(genparticles->eta());
	h_genMuon_Phi_num_tight_E->Fill(genparticles->phi());    
	Nvtx_num_tight_E->Fill(PUInfo_true);
	NGood_num_tight_E->Fill(nGoodVtx);

      }
	
      }
      // Tight Veto
    }

    // medium isolation
    if((*_rawc)[tauCandidate] < 2){
    
      if ((*_mv31)[tauCandidate] > 0.5) { 
	h_PfTau_pT_numM->Fill(tauCandidate->pt());
	h_PfTau_Eta_numM->Fill(tauCandidate->eta());
	h_PfTau_Phi_numM->Fill(tauCandidate->phi());
	h_genMuon_pT_numM->Fill(genparticles->pt());
	h_genMuon_Eta_numM->Fill(genparticles->eta());
	h_genMuon_Phi_numM->Fill(genparticles->phi());    
	Nvtx_numM->Fill(PUInfo_true);
	NGood_numM->Fill(nGoodVtx);
	//Fill Reco 

	//elec now
	if ((*_enew)[tauCandidate] > 0.5) { 
	h_PfTau_pT_numM_E->Fill(tauCandidate->pt());
	h_PfTau_Eta_numM_E->Fill(tauCandidate->eta());
	h_PfTau_Phi_numM_E->Fill(tauCandidate->phi());
	h_genMuon_pT_numM_E->Fill(genparticles->pt());
	h_genMuon_Eta_numM_E->Fill(genparticles->eta());
	h_genMuon_Phi_numM_E->Fill(genparticles->phi());    
	Nvtx_numM_E->Fill(PUInfo_true);
	NGood_numM_E->Fill(nGoodVtx);

      }
	
      }
      
      if ((*_mv32)[tauCandidate] > 0.5) {
	h_PfTau_pT_num_tightM->Fill(tauCandidate->pt());
	h_PfTau_Eta_num_tightM->Fill(tauCandidate->eta());
	h_PfTau_Phi_num_tightM->Fill(tauCandidate->phi());
	h_genMuon_pT_num_tightM->Fill(genparticles->pt());
	h_genMuon_Eta_num_tightM->Fill(genparticles->eta());
	h_genMuon_Phi_num_tightM->Fill(genparticles->phi()); 
	Nvtx_num_tightM->Fill(PUInfo_true); 
	NGood_num_tightM->Fill(nGoodVtx);


	if ((*_enew)[tauCandidate] > 0.5) { 
	h_PfTau_pT_num_tightM_E->Fill(tauCandidate->pt());
	h_PfTau_Eta_num_tightM_E->Fill(tauCandidate->eta());
	h_PfTau_Phi_num_tightM_E->Fill(tauCandidate->phi());
	h_genMuon_pT_num_tightM_E->Fill(genparticles->pt());
	h_genMuon_Eta_num_tightM_E->Fill(genparticles->eta());
	h_genMuon_Phi_num_tightM_E->Fill(genparticles->phi());    
	Nvtx_num_tightM_E->Fill(PUInfo_true);
	NGood_num_tightM_E->Fill(nGoodVtx);

      }
	
      }
     
    }
    // tight
   if((*_rawc)[tauCandidate] < 1){
      if ((*_mv31)[tauCandidate] > 0.5) { 
	h_PfTau_pT_numT->Fill(tauCandidate->pt());
	h_PfTau_Eta_numT->Fill(tauCandidate->eta());
	h_PfTau_Phi_numT->Fill(tauCandidate->phi());
	h_genMuon_pT_numT->Fill(genparticles->pt());
	h_genMuon_Eta_numT->Fill(genparticles->eta());
	h_genMuon_Phi_numT->Fill(genparticles->phi());    
	Nvtx_numT->Fill(PUInfo_true);
	NGood_numT->Fill(nGoodVtx);
	//Fill Reco 
	if ((*_enew)[tauCandidate] > 0.5) { 
 	h_PfTau_pT_numT_E->Fill(tauCandidate->pt());
	h_PfTau_Eta_numT_E->Fill(tauCandidate->eta());
	h_PfTau_Phi_numT_E->Fill(tauCandidate->phi());
	h_genMuon_pT_numT_E->Fill(genparticles->pt());
	h_genMuon_Eta_numT_E->Fill(genparticles->eta());
	h_genMuon_Phi_numT_E->Fill(genparticles->phi());    
	Nvtx_numT_E->Fill(PUInfo_true);
	NGood_numT_E->Fill(nGoodVtx);

      }

      }
      
      if ((*_mv32)[tauCandidate] > 0.5) {
	h_PfTau_pT_num_tightT->Fill(tauCandidate->pt());
	h_PfTau_Eta_num_tightT->Fill(tauCandidate->eta());
	h_PfTau_Phi_num_tightT->Fill(tauCandidate->phi());
	h_genMuon_pT_num_tightT->Fill(genparticles->pt());
	h_genMuon_Eta_num_tightT->Fill(genparticles->eta());
	h_genMuon_Phi_num_tightT->Fill(genparticles->phi()); 
	Nvtx_num_tightT->Fill(PUInfo_true); 
	NGood_num_tightT->Fill(nGoodVtx);
	
	if ((*_enew)[tauCandidate] > 0.5) { 
	h_PfTau_pT_num_tightT_E->Fill(tauCandidate->pt());
	h_PfTau_Eta_num_tightT_E->Fill(tauCandidate->eta());
	h_PfTau_Phi_num_tightT_E->Fill(tauCandidate->phi());
	h_genMuon_pT_num_tightT_E->Fill(genparticles->pt());
	h_genMuon_Eta_num_tightT_E->Fill(genparticles->eta());
	h_genMuon_Phi_num_tightT_E->Fill(genparticles->phi());    
	Nvtx_num_tightT_E->Fill(PUInfo_true);
	NGood_num_tightT_E->Fill(nGoodVtx);

      }

      }
     
    }
 
 
       }
    }	  
	}
      }
    }
  }
}
// ------------ method called once each job just before starting event loop  ------------

bool MuTauFakeRate::OverlapWithGenTauForOther(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc ,int &index ) {
   double drtmp = _TauToGenMatchingDeltaR;
   bool genTaufound = false;
   index = -1;
   for ( unsigned iTau = 0; iTau < taujetcol->size(); ++iTau ) {
     reco::PFTauRef tauCandidate(taujetcol,iTau);
     if(tauCandidate->pt() <= 20) continue;
     if(fabs(tauCandidate->eta()) <= etacutmin) continue;
     if(fabs(tauCandidate->eta()) >= etacut) continue;
     if((*disc)[tauCandidate] > 0.5) {

       double dr =reco::deltaR(Taueta, Tauphi,tauCandidate->eta(),tauCandidate->phi());
       if(dr < drtmp){
 drtmp = dr;
 index = iTau;
 genTaufound= true;
     }
     }
   }
   return genTaufound;
 }

bool MuTauFakeRate::IsZMuMu(edm::Handle<reco::GenParticleCollection> genParticles){
   bool isZMuMu = false;
  reco::GenParticleCollection::const_iterator particle;
  for (particle = genParticles->begin(); particle != genParticles->end();  particle++) {
    if ((abs(particle->pdgId()) == _TauMotherId)) {
//      std::cout<<" Z found with pdgid = "<<particle->numberOfDaughters()<<std::endl;
      int daughters  = particle->numberOfDaughters();
       for (int j = 0; j<daughters; ++j) {
        const reco::Candidate *daughter = particle->daughter(j);
         int pidg = std::abs(daughter->pdgId());
	 int status = daughter->status();
         if (pidg == 13 && status ==3) {
           isZMuMu = true;
//           std::cout<<"working inside function"<<std::endl;
           break;
        }
      }
    }
  }
  return isZMuMu;  
}

bool MuTauFakeRate::OverlapWithGenMu(double Taueta , double Tauphi ,edm::Handle<reco::GenParticleCollection> genParticles ,int  &index ) {
  double drtmp = _TauToGenMatchingDeltaR;
  int tmpindex =0 ;
  bool genTaufound = false;
  for(reco::GenParticleCollection::const_iterator genmuons=genParticles->begin(); genmuons!=genParticles->end(); ++genmuons) {
    if(((abs(genmuons->pdgId()) == 13) && (genmuons->status() ==3))) {
	 if(abs(genmuons->mother(0)->pdgId()) == _TauMotherId) {
    double dr =reco::deltaR(Taueta, Tauphi,genmuons->eta(),genmuons->phi());
    if(dr < drtmp){
      drtmp = dr;
      index = tmpindex;
      genTaufound= true;
    } 
    tmpindex++;
	 }
       }
       }
    return genTaufound;
  }
  

