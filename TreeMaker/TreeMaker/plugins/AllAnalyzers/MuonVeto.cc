#include "./MuonVeto.h"                                                                                                                                        
#include "DataFormats/TrackReco/interface/HitPattern.h"

MuonVeto::MuonVeto(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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

  h_Num_Muons = fs->make<TH1F>(("h_Num_Muons"+prefix).c_str() ,"h_Num_Muons",100,0,100);
  h_Fill_numMatches_eta1p2    = fs->make<TH1F>(("h_Fill_numMatches_eta1p2"+prefix).c_str() ,"h_Fill_numMatches_eta1p2",15,0,15);
  h_DT_FirstStation_eta1p2    = fs->make<TH1F>(("h_DT_FirstStation_eta1p2"+prefix).c_str() ,"h_DT_FirstStation_eta1p2",15,0,15);
  h_CSC_FirstStation_eta1p2   = fs->make<TH1F>(("h_CSC_FirstStation_eta1p2"+prefix).c_str() ,"h_CSC_FirstStation_eta1p2",15,0,15);
  h_RPC_FirstStation_eta1p2   = fs->make<TH1F>(("h_RPC_FirstStation_eta1p2"+prefix).c_str() ,"h_RPC_FirstStation_eta1p2",15,0,15);
  h_DT_SecondStation_eta1p2   = fs->make<TH1F>(("h_DT_SecondStation_eta1p2"+prefix).c_str() ,"h_DT_SecondStation_eta1p2",15,0,15);
  h_CSC_SecondStation_eta1p2  = fs->make<TH1F>(("h_CSC_SecondStation_eta1p2"+prefix).c_str() ,"h_CSC_SecondStation_eta1p2",15,0,15);
  h_RPC_SecondStation_eta1p2  = fs->make<TH1F>(("h_RPC_SecondStation_eta1p2"+prefix).c_str() ,"h_RPC_SecondStation_eta1p2",15,0,15);
  h_DT_ThirdStation_eta1p2    = fs->make<TH1F>(("h_DT_ThirdStation_eta1p2"+prefix).c_str() ,"h_DT_ThirdStation_eta1p2",15,0,15);
  h_CSC_ThirdStation_eta1p2   = fs->make<TH1F>(("h_CSC_ThirdStation_eta1p2"+prefix).c_str() ,"h_CSC_ThirdStation_eta1p2",15,0,15);
  h_RPC_ThirdStation_eta1p2   = fs->make<TH1F>(("h_RPC_ThirdStation_eta1p2"+prefix).c_str() ,"h_RPC_ThirdStation_eta1p2",15,0,15);
  h_DT_FourthStation_eta1p2   = fs->make<TH1F>(("h_DT_FourthStation_eta1p2"+prefix).c_str() ,"h_DT_FourthStation_eta1p2",15,0,15);
  h_CSC_FourthStation_eta1p2  = fs->make<TH1F>(("h_CSC_FourthStation_eta1p2"+prefix).c_str() ,"h_CSC_FourthStation_eta1p2",15,0,15);
  h_RPC_FourthStation_eta1p2  = fs->make<TH1F>(("h_RPC_FourthStation_eta1p2"+prefix).c_str() ,"h_RPC_FourthStation_eta1p2",15,0,15);
  h_Fill_numMatches_etag1p2   = fs->make<TH1F>(("h_Fill_numMatches_etag1p2"+prefix).c_str() ,"h_Fill_numMatches_etag1p2",15,0,15);
  h_DT_FirstStation_etag1p2   = fs->make<TH1F>(("h_DT_FirstStation_etag1p2"+prefix).c_str() ,"h_DT_FirstStation_etag1p2",15,0,15);
  h_CSC_FirstStation_etag1p2  = fs->make<TH1F>(("h_CSC_FirstStation_etag1p2"+prefix).c_str() ,"h_CSC_FirstStation_etag1p2",15,0,15);
  h_RPC_FirstStation_etag1p2  = fs->make<TH1F>(("h_RPC_FirstStation_etag1p2"+prefix).c_str() ,"h_RPC_FirstStation_etag1p2",15,0,15);
  h_DT_SecondStation_etag1p2  = fs->make<TH1F>(("h_DT_SecondStation_etag1p2"+prefix).c_str() ,"h_DT_SecondStation_etag1p2",15,0,15);
  h_CSC_SecondStation_etag1p2 = fs->make<TH1F>(("h_CSC_SecondStation_etag1p2"+prefix).c_str() ,"h_CSC_SecondStation_etag1p2",15,0,15);
  h_RPC_SecondStation_etag1p2 = fs->make<TH1F>(("h_RPC_SecondStation_etag1p2"+prefix).c_str() ,"h_RPC_SecondStation_etag1p2",15,0,15);
  h_DT_ThirdStation_etag1p2   = fs->make<TH1F>(("h_DT_ThirdStation_etag1p2"+prefix).c_str() ,"h_DT_ThirdStation_etag1p2",15,0,15);
  h_CSC_ThirdStation_etag1p2  = fs->make<TH1F>(("h_CSC_ThirdStation_etag1p2"+prefix).c_str() ,"h_CSC_ThirdStation_etag1p2",15,0,15);
  h_RPC_ThirdStation_etag1p2  = fs->make<TH1F>(("h_RPC_ThirdStation_etag1p2"+prefix).c_str() ,"h_RPC_ThirdStation_etag1p2",15,0,15);
  h_DT_FourthStation_etag1p2  = fs->make<TH1F>(("h_DT_FourthStation_etag1p2"+prefix).c_str() ,"h_DT_FourthStation_etag1p2",15,0,15);
  h_CSC_FourthStation_etag1p2 = fs->make<TH1F>(("h_CSC_FourthStation_etag1p2"+prefix).c_str() ,"h_CSC_FourthStation_etag1p2",15,0,15);
  h_RPC_FourthStation_etag1p2 = fs->make<TH1F>(("h_RPC_FourthStation_etag1p2"+prefix).c_str() ,"h_RPC_FourthStation_etag1p2",15,0,15);


  h_DT_FirstStation_Matches_eta1p2    = fs->make<TH1F>(("h_DT_FirstStation_Matches_eta1p2"+prefix).c_str() ,"h_DT_FirstStation_Matches_eta1p2",15,0,15);
  h_CSC_FirstStation_Matches_eta1p2   = fs->make<TH1F>(("h_CSC_FirstStation_Matches_eta1p2"+prefix).c_str() ,"h_CSC_FirstStation_Matches_eta1p2",15,0,15);
  h_RPC_FirstStation_Matches_eta1p2   = fs->make<TH1F>(("h_RPC_FirstStation_Matches_eta1p2"+prefix).c_str() ,"h_RPC_FirstStation_Matches_eta1p2",15,0,15);
  h_DT_SecondStation_Matches_eta1p2   = fs->make<TH1F>(("h_DT_SecondStation_Matches_eta1p2"+prefix).c_str() ,"h_DT_SecondStation_Matches_eta1p2",15,0,15);
  h_CSC_SecondStation_Matches_eta1p2  = fs->make<TH1F>(("h_CSC_SecondStation_Matches_eta1p2"+prefix).c_str() ,"h_CSC_SecondStation_Matches_eta1p2",15,0,15);
  h_RPC_SecondStation_Matches_eta1p2  = fs->make<TH1F>(("h_RPC_SecondStation_Matches_eta1p2"+prefix).c_str() ,"h_RPC_SecondStation_Matches_eta1p2",15,0,15);
  h_DT_ThirdStation_Matches_eta1p2    = fs->make<TH1F>(("h_DT_ThirdStation_Matches_eta1p2"+prefix).c_str() ,"h_DT_ThirdStation_Matches_eta1p2",15,0,15);
  h_CSC_ThirdStation_Matches_eta1p2   = fs->make<TH1F>(("h_CSC_ThirdStation_Matches_eta1p2"+prefix).c_str() ,"h_CSC_ThirdStation_Matches_eta1p2",15,0,15);
  h_RPC_ThirdStation_Matches_eta1p2   = fs->make<TH1F>(("h_RPC_ThirdStation_Matches_eta1p2"+prefix).c_str() ,"h_RPC_ThirdStation_Matches_eta1p2",15,0,15);
  h_DT_FourthStation_Matches_eta1p2   = fs->make<TH1F>(("h_DT_FourthStation_Matches_eta1p2"+prefix).c_str() ,"h_DT_FourthStation_Matches_eta1p2",15,0,15);
  h_CSC_FourthStation_Matches_eta1p2  = fs->make<TH1F>(("h_CSC_FourthStation_Matches_eta1p2"+prefix).c_str() ,"h_CSC_FourthStation_Matches_eta1p2",15,0,15);
  h_RPC_FourthStation_Matches_eta1p2  = fs->make<TH1F>(("h_RPC_FourthStation_Matches_eta1p2"+prefix).c_str() ,"h_RPC_FourthStation_Matches_eta1p2",15,0,15);
  h_DT_FirstStation_Matches_etag1p2   = fs->make<TH1F>(("h_DT_FirstStation_Matches_etag1p2"+prefix).c_str() ,"h_DT_FirstStation_Matches_etag1p2",15,0,15);
  h_CSC_FirstStation_Matches_etag1p2  = fs->make<TH1F>(("h_CSC_FirstStation_Matches_etag1p2"+prefix).c_str() ,"h_CSC_FirstStation_Matches_etag1p2",15,0,15);
  h_RPC_FirstStation_Matches_etag1p2  = fs->make<TH1F>(("h_RPC_FirstStation_Matches_etag1p2"+prefix).c_str() ,"h_RPC_FirstStation_Matches_etag1p2",15,0,15);
  h_DT_SecondStation_Matches_etag1p2  = fs->make<TH1F>(("h_DT_SecondStation_Matches_etag1p2"+prefix).c_str() ,"h_DT_SecondStation_Matches_etag1p2",15,0,15);
  h_CSC_SecondStation_Matches_etag1p2 = fs->make<TH1F>(("h_CSC_SecondStation_Matches_etag1p2"+prefix).c_str() ,"h_CSC_SecondStation_Matches_etag1p2",15,0,15);
  h_RPC_SecondStation_Matches_etag1p2 = fs->make<TH1F>(("h_RPC_SecondStation_Matches_etag1p2"+prefix).c_str() ,"h_RPC_SecondStation_Matches_etag1p2",15,0,15);
  h_DT_ThirdStation_Matches_etag1p2   = fs->make<TH1F>(("h_DT_ThirdStation_Matches_etag1p2"+prefix).c_str() ,"h_DT_ThirdStation_Matches_etag1p2",15,0,15);
  h_CSC_ThirdStation_Matches_etag1p2  = fs->make<TH1F>(("h_CSC_ThirdStation_Matches_etag1p2"+prefix).c_str() ,"h_CSC_ThirdStation_Matches_etag1p2",15,0,15);
  h_RPC_ThirdStation_Matches_etag1p2  = fs->make<TH1F>(("h_RPC_ThirdStation_Matches_etag1p2"+prefix).c_str() ,"h_RPC_ThirdStation_Matches_etag1p2",15,0,15);
  h_DT_FourthStation_Matches_etag1p2  = fs->make<TH1F>(("h_DT_FourthStation_Matches_etag1p2"+prefix).c_str() ,"h_DT_FourthStation_Matches_etag1p2",15,0,15);
  h_CSC_FourthStation_Matches_etag1p2 = fs->make<TH1F>(("h_CSC_FourthStation_Matches_etag1p2"+prefix).c_str() ,"h_CSC_FourthStation_Matches_etag1p2",15,0,15);
  h_RPC_FourthStation_Matches_etag1p2 = fs->make<TH1F>(("h_RPC_FourthStation_Matches_etag1p2"+prefix).c_str() ,"h_RPC_FourthStation_Matches_etag1p2",15,0,15);


  h_Fill_Muon_pT = fs->make<TH1F>(("h_Fill_Muon_pT"+prefix).c_str() ,"h_Fill_Muon_pT",100,0,700);

  h_Fill_Muon_Eta = fs->make<TH1F>(("h_Fill_Muon_Eta"+prefix).c_str() ,"h_Fill_Muon_Eta",100,-5,5);
  h_DT_FirstStation_Matches_eta1p2_Muons    = fs->make<TH1F>(("h_DT_FirstStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_DT_FirstStation_Matches_eta1p2_Muons",15,0,15);
  h_CSC_FirstStation_Matches_eta1p2_Muons   = fs->make<TH1F>(("h_CSC_FirstStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_CSC_FirstStation_Matches_eta1p2_Muons",15,0,15);
  h_RPC_FirstStation_Matches_eta1p2_Muons   = fs->make<TH1F>(("h_RPC_FirstStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_RPC_FirstStation_Matches_eta1p2_Muons",15,0,15);
  h_DT_SecondStation_Matches_eta1p2_Muons   = fs->make<TH1F>(("h_DT_SecondStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_DT_SecondStation_Matches_eta1p2_Muons",15,0,15);
  h_CSC_SecondStation_Matches_eta1p2_Muons  = fs->make<TH1F>(("h_CSC_SecondStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_CSC_SecondStation_Matches_eta1p2_Muons",15,0,15);
  h_RPC_SecondStation_Matches_eta1p2_Muons  = fs->make<TH1F>(("h_RPC_SecondStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_RPC_SecondStation_Matches_eta1p2_Muons",15,0,15);
  h_DT_ThirdStation_Matches_eta1p2_Muons    = fs->make<TH1F>(("h_DT_ThirdStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_DT_ThirdStation_Matches_eta1p2_Muons",15,0,15);
  h_CSC_ThirdStation_Matches_eta1p2_Muons   = fs->make<TH1F>(("h_CSC_ThirdStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_CSC_ThirdStation_Matches_eta1p2_Muons",15,0,15);
  h_RPC_ThirdStation_Matches_eta1p2_Muons   = fs->make<TH1F>(("h_RPC_ThirdStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_RPC_ThirdStation_Matches_eta1p2_Muons",15,0,15);
  h_DT_FourthStation_Matches_eta1p2_Muons   = fs->make<TH1F>(("h_DT_FourthStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_DT_FourthStation_Matches_eta1p2_Muons",15,0,15);
  h_CSC_FourthStation_Matches_eta1p2_Muons  = fs->make<TH1F>(("h_CSC_FourthStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_CSC_FourthStation_Matches_eta1p2_Muons",15,0,15);
  h_RPC_FourthStation_Matches_eta1p2_Muons  = fs->make<TH1F>(("h_RPC_FourthStation_Matches_eta1p2_Muons"+prefix).c_str() ,"h_RPC_FourthStation_Matches_eta1p2_Muons",15,0,15);
  h_DT_FirstStation_Matches_etag1p2_Muons   = fs->make<TH1F>(("h_DT_FirstStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_DT_FirstStation_Matches_etag1p2_Muons",15,0,15);
  h_CSC_FirstStation_Matches_etag1p2_Muons  = fs->make<TH1F>(("h_CSC_FirstStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_CSC_FirstStation_Matches_etag1p2_Muons",15,0,15);
  h_RPC_FirstStation_Matches_etag1p2_Muons  = fs->make<TH1F>(("h_RPC_FirstStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_RPC_FirstStation_Matches_etag1p2_Muons",15,0,15);
  h_DT_SecondStation_Matches_etag1p2_Muons  = fs->make<TH1F>(("h_DT_SecondStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_DT_SecondStation_Matches_etag1p2_Muons",15,0,15);
  h_CSC_SecondStation_Matches_etag1p2_Muons = fs->make<TH1F>(("h_CSC_SecondStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_CSC_SecondStation_Matches_etag1p2_Muons",15,0,15);
  h_RPC_SecondStation_Matches_etag1p2_Muons = fs->make<TH1F>(("h_RPC_SecondStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_RPC_SecondStation_Matches_etag1p2_Muons",15,0,15);
  h_DT_ThirdStation_Matches_etag1p2_Muons   = fs->make<TH1F>(("h_DT_ThirdStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_DT_ThirdStation_Matches_etag1p2_Muons",15,0,15);
  h_CSC_ThirdStation_Matches_etag1p2_Muons  = fs->make<TH1F>(("h_CSC_ThirdStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_CSC_ThirdStation_Matches_etag1p2_Muons",15,0,15);
  h_RPC_ThirdStation_Matches_etag1p2_Muons  = fs->make<TH1F>(("h_RPC_ThirdStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_RPC_ThirdStation_Matches_etag1p2_Muons",15,0,15);
  h_DT_FourthStation_Matches_etag1p2_Muons  = fs->make<TH1F>(("h_DT_FourthStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_DT_FourthStation_Matches_etag1p2_Muons",15,0,15);
  h_CSC_FourthStation_Matches_etag1p2_Muons = fs->make<TH1F>(("h_CSC_FourthStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_CSC_FourthStation_Matches_etag1p2_Muons",15,0,15);
  h_RPC_FourthStation_Matches_etag1p2_Muons = fs->make<TH1F>(("h_RPC_FourthStation_Matches_etag1p2_Muons"+prefix).c_str() ,"h_RPC_FourthStation_Matches_etag1p2_Muons",15,0,15);

  h_DT_FirstStation_eta1p2_Muons    = fs->make<TH1F>(("h_DT_FirstStation_eta1p2_Muons"+prefix).c_str() ,"h_DT_FirstStation_eta1p2_Muons",15,0,15);
  h_CSC_FirstStation_eta1p2_Muons   = fs->make<TH1F>(("h_CSC_FirstStation_eta1p2_Muons"+prefix).c_str() ,"h_CSC_FirstStation_eta1p2_Muons",15,0,15);
  h_RPC_FirstStation_eta1p2_Muons   = fs->make<TH1F>(("h_RPC_FirstStation_eta1p2_Muons"+prefix).c_str() ,"h_RPC_FirstStation_eta1p2_Muons",15,0,15);
  h_DT_SecondStation_eta1p2_Muons   = fs->make<TH1F>(("h_DT_SecondStation_eta1p2_Muons"+prefix).c_str() ,"h_DT_SecondStation_eta1p2_Muons",15,0,15);
  h_CSC_SecondStation_eta1p2_Muons  = fs->make<TH1F>(("h_CSC_SecondStation_eta1p2_Muons"+prefix).c_str() ,"h_CSC_SecondStation_eta1p2_Muons",15,0,15);
  h_RPC_SecondStation_eta1p2_Muons  = fs->make<TH1F>(("h_RPC_SecondStation_eta1p2_Muons"+prefix).c_str() ,"h_RPC_SecondStation_eta1p2_Muons",15,0,15);
  h_DT_ThirdStation_eta1p2_Muons    = fs->make<TH1F>(("h_DT_ThirdStation_eta1p2_Muons"+prefix).c_str() ,"h_DT_ThirdStation_eta1p2_Muons",15,0,15);
  h_CSC_ThirdStation_eta1p2_Muons   = fs->make<TH1F>(("h_CSC_ThirdStation_eta1p2_Muons"+prefix).c_str() ,"h_CSC_ThirdStation_eta1p2_Muons",15,0,15);
  h_RPC_ThirdStation_eta1p2_Muons   = fs->make<TH1F>(("h_RPC_ThirdStation_eta1p2_Muons"+prefix).c_str() ,"h_RPC_ThirdStation_eta1p2_Muons",15,0,15);
  h_DT_FourthStation_eta1p2_Muons   = fs->make<TH1F>(("h_DT_FourthStation_eta1p2_Muons"+prefix).c_str() ,"h_DT_FourthStation_eta1p2_Muons",15,0,15);
  h_CSC_FourthStation_eta1p2_Muons  = fs->make<TH1F>(("h_CSC_FourthStation_eta1p2_Muons"+prefix).c_str() ,"h_CSC_FourthStation_eta1p2_Muons",15,0,15);
  h_RPC_FourthStation_eta1p2_Muons  = fs->make<TH1F>(("h_RPC_FourthStation_eta1p2_Muons"+prefix).c_str() ,"h_RPC_FourthStation_eta1p2_Muons",15,0,15);
  h_DT_FirstStation_etag1p2_Muons   = fs->make<TH1F>(("h_DT_FirstStation_etag1p2_Muons"+prefix).c_str() ,"h_DT_FirstStation_etag1p2_Muons",15,0,15);
  h_CSC_FirstStation_etag1p2_Muons  = fs->make<TH1F>(("h_CSC_FirstStation_etag1p2_Muons"+prefix).c_str() ,"h_CSC_FirstStation_etag1p2_Muons",15,0,15);
  h_RPC_FirstStation_etag1p2_Muons  = fs->make<TH1F>(("h_RPC_FirstStation_etag1p2_Muons"+prefix).c_str() ,"h_RPC_FirstStation_etag1p2_Muons",15,0,15);
  h_DT_SecondStation_etag1p2_Muons  = fs->make<TH1F>(("h_DT_SecondStation_etag1p2_Muons"+prefix).c_str() ,"h_DT_SecondStation_etag1p2_Muons",15,0,15);
  h_CSC_SecondStation_etag1p2_Muons = fs->make<TH1F>(("h_CSC_SecondStation_etag1p2_Muons"+prefix).c_str() ,"h_CSC_SecondStation_etag1p2_Muons",15,0,15);
  h_RPC_SecondStation_etag1p2_Muons = fs->make<TH1F>(("h_RPC_SecondStation_etag1p2_Muons"+prefix).c_str() ,"h_RPC_SecondStation_etag1p2_Muons",15,0,15);
  h_DT_ThirdStation_etag1p2_Muons   = fs->make<TH1F>(("h_DT_ThirdStation_etag1p2_Muons"+prefix).c_str() ,"h_DT_ThirdStation_etag1p2_Muons",15,0,15);
  h_CSC_ThirdStation_etag1p2_Muons  = fs->make<TH1F>(("h_CSC_ThirdStation_etag1p2_Muons"+prefix).c_str() ,"h_CSC_ThirdStation_etag1p2_Muons",15,0,15);
  h_RPC_ThirdStation_etag1p2_Muons  = fs->make<TH1F>(("h_RPC_ThirdStation_etag1p2_Muons"+prefix).c_str() ,"h_RPC_ThirdStation_etag1p2_Muons",15,0,15);
  h_DT_FourthStation_etag1p2_Muons  = fs->make<TH1F>(("h_DT_FourthStation_etag1p2_Muons"+prefix).c_str() ,"h_DT_FourthStation_etag1p2_Muons",15,0,15);
  h_CSC_FourthStation_etag1p2_Muons = fs->make<TH1F>(("h_CSC_FourthStation_etag1p2_Muons"+prefix).c_str() ,"h_CSC_FourthStation_etag1p2_Muons",15,0,15);
  h_RPC_FourthStation_etag1p2_Muons = fs->make<TH1F>(("h_RPC_FourthStation_etag1p2_Muons"+prefix).c_str() ,"h_RPC_FourthStation_etag1p2_Muons",15,0,15);

  h_Fill_numMatches_eta1p2_ML2    = fs->make<TH1F>(("h_Fill_numMatches_eta1p2_ML2"+prefix).c_str() ,"h_Fill_numMatches_eta1p2_ML2",15,0,15);
  h_DT_FirstStation_eta1p2_ML2    = fs->make<TH1F>(("h_DT_FirstStation_eta1p2_ML2"+prefix).c_str() ,"h_DT_FirstStation_eta1p2_ML2",15,0,15);
  h_CSC_FirstStation_eta1p2_ML2   = fs->make<TH1F>(("h_CSC_FirstStation_eta1p2_ML2"+prefix).c_str() ,"h_CSC_FirstStation_eta1p2_ML2",15,0,15);
  h_RPC_FirstStation_eta1p2_ML2   = fs->make<TH1F>(("h_RPC_FirstStation_eta1p2_ML2"+prefix).c_str() ,"h_RPC_FirstStation_eta1p2_ML2",15,0,15);
  h_DT_SecondStation_eta1p2_ML2   = fs->make<TH1F>(("h_DT_SecondStation_eta1p2_ML2"+prefix).c_str() ,"h_DT_SecondStation_eta1p2_ML2",15,0,15);
  h_CSC_SecondStation_eta1p2_ML2  = fs->make<TH1F>(("h_CSC_SecondStation_eta1p2_ML2"+prefix).c_str() ,"h_CSC_SecondStation_eta1p2_ML2",15,0,15);
  h_RPC_SecondStation_eta1p2_ML2  = fs->make<TH1F>(("h_RPC_SecondStation_eta1p2_ML2"+prefix).c_str() ,"h_RPC_SecondStation_eta1p2_ML2",15,0,15);
  h_DT_ThirdStation_eta1p2_ML2    = fs->make<TH1F>(("h_DT_ThirdStation_eta1p2_ML2"+prefix).c_str() ,"h_DT_ThirdStation_eta1p2_ML2",15,0,15);
  h_CSC_ThirdStation_eta1p2_ML2   = fs->make<TH1F>(("h_CSC_ThirdStation_eta1p2_ML2"+prefix).c_str() ,"h_CSC_ThirdStation_eta1p2_ML2",15,0,15);
  h_RPC_ThirdStation_eta1p2_ML2   = fs->make<TH1F>(("h_RPC_ThirdStation_eta1p2_ML2"+prefix).c_str() ,"h_RPC_ThirdStation_eta1p2_ML2",15,0,15);
  h_DT_FourthStation_eta1p2_ML2   = fs->make<TH1F>(("h_DT_FourthStation_eta1p2_ML2"+prefix).c_str() ,"h_DT_FourthStation_eta1p2_ML2",15,0,15);
  h_CSC_FourthStation_eta1p2_ML2  = fs->make<TH1F>(("h_CSC_FourthStation_eta1p2_ML2"+prefix).c_str() ,"h_CSC_FourthStation_eta1p2_ML2",15,0,15);
  h_RPC_FourthStation_eta1p2_ML2  = fs->make<TH1F>(("h_RPC_FourthStation_eta1p2_ML2"+prefix).c_str() ,"h_RPC_FourthStation_eta1p2_ML2",15,0,15);
  h_Fill_numMatches_etag1p2_ML2   = fs->make<TH1F>(("h_Fill_numMatches_etag1p2_ML2"+prefix).c_str() ,"h_Fill_numMatches_etag1p2_ML2",15,0,15);
  h_DT_FirstStation_etag1p2_ML2   = fs->make<TH1F>(("h_DT_FirstStation_etag1p2_ML2"+prefix).c_str() ,"h_DT_FirstStation_etag1p2_ML2",15,0,15);
  h_CSC_FirstStation_etag1p2_ML2  = fs->make<TH1F>(("h_CSC_FirstStation_etag1p2_ML2"+prefix).c_str() ,"h_CSC_FirstStation_etag1p2_ML2",15,0,15);
  h_RPC_FirstStation_etag1p2_ML2  = fs->make<TH1F>(("h_RPC_FirstStation_etag1p2_ML2"+prefix).c_str() ,"h_RPC_FirstStation_etag1p2_ML2",15,0,15);
  h_DT_SecondStation_etag1p2_ML2  = fs->make<TH1F>(("h_DT_SecondStation_etag1p2_ML2"+prefix).c_str() ,"h_DT_SecondStation_etag1p2_ML2",15,0,15);
  h_CSC_SecondStation_etag1p2_ML2 = fs->make<TH1F>(("h_CSC_SecondStation_etag1p2_ML2"+prefix).c_str() ,"h_CSC_SecondStation_etag1p2_ML2",15,0,15);
  h_RPC_SecondStation_etag1p2_ML2 = fs->make<TH1F>(("h_RPC_SecondStation_etag1p2_ML2"+prefix).c_str() ,"h_RPC_SecondStation_etag1p2_ML2",15,0,15);
  h_DT_ThirdStation_etag1p2_ML2   = fs->make<TH1F>(("h_DT_ThirdStation_etag1p2_ML2"+prefix).c_str() ,"h_DT_ThirdStation_etag1p2_ML2",15,0,15);
  h_CSC_ThirdStation_etag1p2_ML2  = fs->make<TH1F>(("h_CSC_ThirdStation_etag1p2_ML2"+prefix).c_str() ,"h_CSC_ThirdStation_etag1p2_ML2",15,0,15);
  h_RPC_ThirdStation_etag1p2_ML2  = fs->make<TH1F>(("h_RPC_ThirdStation_etag1p2_ML2"+prefix).c_str() ,"h_RPC_ThirdStation_etag1p2_ML2",15,0,15);
  h_DT_FourthStation_etag1p2_ML2  = fs->make<TH1F>(("h_DT_FourthStation_etag1p2_ML2"+prefix).c_str() ,"h_DT_FourthStation_etag1p2_ML2",15,0,15);
  h_CSC_FourthStation_etag1p2_ML2 = fs->make<TH1F>(("h_CSC_FourthStation_etag1p2_ML2"+prefix).c_str() ,"h_CSC_FourthStation_etag1p2_ML2",15,0,15);
  h_RPC_FourthStation_etag1p2_ML2 = fs->make<TH1F>(("h_RPC_FourthStation_etag1p2_ML2"+prefix).c_str() ,"h_RPC_FourthStation_etag1p2_ML2",15,0,15);


  h_Fill_numMatches_eta1p2_ML3    = fs->make<TH1F>(("h_Fill_numMatches_eta1p2_ML3"+prefix).c_str() ,"h_Fill_numMatches_eta1p2_ML3",15,0,15);
  h_DT_FirstStation_eta1p2_ML3    = fs->make<TH1F>(("h_DT_FirstStation_eta1p2_ML3"+prefix).c_str() ,"h_DT_FirstStation_eta1p2_ML3",15,0,15);
  h_CSC_FirstStation_eta1p2_ML3   = fs->make<TH1F>(("h_CSC_FirstStation_eta1p2_ML3"+prefix).c_str() ,"h_CSC_FirstStation_eta1p2_ML3",15,0,15);
  h_RPC_FirstStation_eta1p2_ML3   = fs->make<TH1F>(("h_RPC_FirstStation_eta1p2_ML3"+prefix).c_str() ,"h_RPC_FirstStation_eta1p2_ML3",15,0,15);
  h_DT_SecondStation_eta1p2_ML3   = fs->make<TH1F>(("h_DT_SecondStation_eta1p2_ML3"+prefix).c_str() ,"h_DT_SecondStation_eta1p2_ML3",15,0,15);
  h_CSC_SecondStation_eta1p2_ML3  = fs->make<TH1F>(("h_CSC_SecondStation_eta1p2_ML3"+prefix).c_str() ,"h_CSC_SecondStation_eta1p2_ML3",15,0,15);
  h_RPC_SecondStation_eta1p2_ML3  = fs->make<TH1F>(("h_RPC_SecondStation_eta1p2_ML3"+prefix).c_str() ,"h_RPC_SecondStation_eta1p2_ML3",15,0,15);
  h_DT_ThirdStation_eta1p2_ML3    = fs->make<TH1F>(("h_DT_ThirdStation_eta1p2_ML3"+prefix).c_str() ,"h_DT_ThirdStation_eta1p2_ML3",15,0,15);
  h_CSC_ThirdStation_eta1p2_ML3   = fs->make<TH1F>(("h_CSC_ThirdStation_eta1p2_ML3"+prefix).c_str() ,"h_CSC_ThirdStation_eta1p2_ML3",15,0,15);
  h_RPC_ThirdStation_eta1p2_ML3   = fs->make<TH1F>(("h_RPC_ThirdStation_eta1p2_ML3"+prefix).c_str() ,"h_RPC_ThirdStation_eta1p2_ML3",15,0,15);
  h_DT_FourthStation_eta1p2_ML3   = fs->make<TH1F>(("h_DT_FourthStation_eta1p2_ML3"+prefix).c_str() ,"h_DT_FourthStation_eta1p2_ML3",15,0,15);
  h_CSC_FourthStation_eta1p2_ML3  = fs->make<TH1F>(("h_CSC_FourthStation_eta1p2_ML3"+prefix).c_str() ,"h_CSC_FourthStation_eta1p2_ML3",15,0,15);
  h_RPC_FourthStation_eta1p2_ML3  = fs->make<TH1F>(("h_RPC_FourthStation_eta1p2_ML3"+prefix).c_str() ,"h_RPC_FourthStation_eta1p2_ML3",15,0,15);
  h_Fill_numMatches_etag1p2_ML3   = fs->make<TH1F>(("h_Fill_numMatches_etag1p2_ML3"+prefix).c_str() ,"h_Fill_numMatches_etag1p2_ML3",15,0,15);
  h_DT_FirstStation_etag1p2_ML3   = fs->make<TH1F>(("h_DT_FirstStation_etag1p2_ML3"+prefix).c_str() ,"h_DT_FirstStation_etag1p2_ML3",15,0,15);
  h_CSC_FirstStation_etag1p2_ML3  = fs->make<TH1F>(("h_CSC_FirstStation_etag1p2_ML3"+prefix).c_str() ,"h_CSC_FirstStation_etag1p2_ML3",15,0,15);
  h_RPC_FirstStation_etag1p2_ML3  = fs->make<TH1F>(("h_RPC_FirstStation_etag1p2_ML3"+prefix).c_str() ,"h_RPC_FirstStation_etag1p2_ML3",15,0,15);
  h_DT_SecondStation_etag1p2_ML3  = fs->make<TH1F>(("h_DT_SecondStation_etag1p2_ML3"+prefix).c_str() ,"h_DT_SecondStation_etag1p2_ML3",15,0,15);
  h_CSC_SecondStation_etag1p2_ML3 = fs->make<TH1F>(("h_CSC_SecondStation_etag1p2_ML3"+prefix).c_str() ,"h_CSC_SecondStation_etag1p2_ML3",15,0,15);
  h_RPC_SecondStation_etag1p2_ML3 = fs->make<TH1F>(("h_RPC_SecondStation_etag1p2_ML3"+prefix).c_str() ,"h_RPC_SecondStation_etag1p2_ML3",15,0,15);
  h_DT_ThirdStation_etag1p2_ML3   = fs->make<TH1F>(("h_DT_ThirdStation_etag1p2_ML3"+prefix).c_str() ,"h_DT_ThirdStation_etag1p2_ML3",15,0,15);
  h_CSC_ThirdStation_etag1p2_ML3  = fs->make<TH1F>(("h_CSC_ThirdStation_etag1p2_ML3"+prefix).c_str() ,"h_CSC_ThirdStation_etag1p2_ML3",15,0,15);
  h_RPC_ThirdStation_etag1p2_ML3  = fs->make<TH1F>(("h_RPC_ThirdStation_etag1p2_ML3"+prefix).c_str() ,"h_RPC_ThirdStation_etag1p2_ML3",15,0,15);
  h_DT_FourthStation_etag1p2_ML3  = fs->make<TH1F>(("h_DT_FourthStation_etag1p2_ML3"+prefix).c_str() ,"h_DT_FourthStation_etag1p2_ML3",15,0,15);
  h_CSC_FourthStation_etag1p2_ML3 = fs->make<TH1F>(("h_CSC_FourthStation_etag1p2_ML3"+prefix).c_str() ,"h_CSC_FourthStation_etag1p2_ML3",15,0,15);
  h_RPC_FourthStation_etag1p2_ML3 = fs->make<TH1F>(("h_RPC_FourthStation_etag1p2_ML3"+prefix).c_str() ,"h_RPC_FourthStation_etag1p2_ML3",15,0,15);



  
  
}


MuonVeto::~MuonVeto()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}


//
// member functions
//

// ------------ method called for each event  ------------
void MuonVeto::Fill(const edm::Event& iEvent) {
  using namespace edm;
  using namespace std;
  using namespace reco;
  using namespace pat;
  
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
   iEvent.getByLabel("hpsPFTauDiscriminationByDecayModeFinding",_dmf);
  //Muon Veto

   //Muon 2 working pint
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection2",_mv1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumMuonRejection2",_mv2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection2",_mv3);
   
   // Muon 3 working points

   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection3",_mv31);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection3",_mv32);

   //Electron Veto

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
  
  
  
  bool isZtautau=false;
  isZtautau = IsZTauTau (_genParticles) ;
  
  //isZtautau=true;
  
  if(isZtautau) {
   
    h_Num_Muons->Fill(rmuons->size());
 
    //Muon Loop here
   // for(reco::MuonCollection::const_iterator muons = rmuons->begin(); muons !=  rmuons->end(); ++muons) {

    for ( size_t idxMuon = 0; idxMuon < rmuons->size(); ++idxMuon ) {

    reco::MuonRef muons(rmuons, idxMuon);
    std::vector<int> numMatchesDTM(4), numMatchesCSCM(4) , numMatchesRPCM(4);
    std::vector<int>  numHitsDTM(4), numHitsCSCM(4) , numHitsRPCM(4);
   
    std::vector<int> numMatchesDTM0(4), numMatchesCSCM0(4) , numMatchesRPCM0(4);
    std::vector<int>  numHitsDTM0(4), numHitsCSCM0(4) , numHitsRPCM0(4);
    
   for ( int iStation = 0; iStation < 4; ++iStation ) {
    numMatchesDTM[iStation]  = 0;
    numMatchesCSCM[iStation]  = 0;
    numMatchesRPCM[iStation]  = 0;
    numHitsDTM[iStation]  = 0;
    numHitsCSCM[iStation]  = 0;
    numHitsRPCM[iStation]  = 0;


    numMatchesDTM0[iStation]  = 0;
    numMatchesCSCM0[iStation]  = 0;
    numMatchesRPCM0[iStation]  = 0;
    numHitsDTM0[iStation]  = 0;
    numHitsCSCM0[iStation]  = 0;
    numHitsRPCM0[iStation]  = 0;

    }

    h_Fill_Muon_pT->Fill(muons->pt());
    h_Fill_Muon_Eta->Fill(muons->eta());  
   
    for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
     reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);
 //  const reco::PFCandidateRef& pfLeadChargedHadron = tauCandidate->leadPFChargedHadrCand();
    const PFCandidatePtr& pfLeadChargedHadron = tauCandidate->leadPFChargedHadrCand();
    if((tauCandidate->pt() > 20) && (fabs(tauCandidate->eta()) < 2.3)) { 
    if((*_dmf)[tauCandidate] > 0.5) { 
    if ( pfLeadChargedHadron.isNonnull() && pfLeadChargedHadron->muonRef().isNonnull()) continue;
      if((muons) == pfLeadChargedHadron->muonRef() ) continue;
    if(fabs(muons->eta()) < 1.2) {
       double dR = deltaR(muons->p4(), tauCandidate->p4());
       if(dR < 0.3) {
        countMatches(*muons, numMatchesDTM, numMatchesCSCM, numMatchesRPCM);
        countHits(*muons, numHitsDTM, numHitsCSCM, numHitsRPCM);
       }
      //Fill Histos here
       h_DT_FirstStation_eta1p2_Muons->Fill(numHitsDTM.at(0));
       h_CSC_FirstStation_eta1p2_Muons->Fill(numHitsCSCM.at(0));
       h_RPC_FirstStation_eta1p2_Muons->Fill(numHitsRPCM.at(0));
       
       h_DT_FirstStation_Matches_eta1p2_Muons->Fill(numMatchesDTM.at(0));
       h_CSC_FirstStation_Matches_eta1p2_Muons->Fill(numMatchesCSCM.at(0));
       h_RPC_FirstStation_Matches_eta1p2_Muons->Fill(numMatchesRPCM.at(0));


       h_DT_SecondStation_eta1p2_Muons->Fill(numHitsDTM.at(1));
       h_CSC_SecondStation_eta1p2_Muons->Fill(numHitsCSCM.at(1));
       h_RPC_SecondStation_eta1p2_Muons->Fill(numHitsRPCM.at(1));
       
       h_DT_SecondStation_Matches_eta1p2_Muons->Fill(numMatchesDTM.at(1));
       h_CSC_SecondStation_Matches_eta1p2_Muons->Fill(numMatchesCSCM.at(1));
       h_RPC_SecondStation_Matches_eta1p2_Muons->Fill(numMatchesRPCM.at(1));


       h_DT_ThirdStation_eta1p2_Muons->Fill(numHitsDTM.at(2));
       h_CSC_ThirdStation_eta1p2_Muons->Fill(numHitsCSCM.at(2));
       h_RPC_ThirdStation_eta1p2_Muons->Fill(numHitsRPCM.at(2));
       
       h_DT_ThirdStation_Matches_eta1p2_Muons->Fill(numMatchesDTM.at(2));
       h_CSC_ThirdStation_Matches_eta1p2_Muons->Fill(numMatchesCSCM.at(2));
       h_RPC_ThirdStation_Matches_eta1p2_Muons->Fill(numMatchesRPCM.at(2));


       h_DT_FourthStation_eta1p2_Muons->Fill(numHitsDTM.at(3));
       h_CSC_FourthStation_eta1p2_Muons->Fill(numHitsCSCM.at(3));
       h_RPC_FourthStation_eta1p2_Muons->Fill(numHitsRPCM.at(3));
       
       h_DT_FourthStation_Matches_eta1p2_Muons->Fill(numMatchesDTM.at(3));
       h_CSC_FourthStation_Matches_eta1p2_Muons->Fill(numMatchesCSCM.at(3));
       h_RPC_FourthStation_Matches_eta1p2_Muons->Fill(numMatchesRPCM.at(3));

    }

    if((fabs(muons->eta()) > 1.2 ) && (fabs(muons->eta()) < 2.3)) {
      double dR = deltaR(muons->p4(), tauCandidate->p4());
      if(dR < 0.3) {
        countMatches(*muons, numMatchesDTM0, numMatchesCSCM0, numMatchesRPCM0);
        countHits(*muons, numHitsDTM0, numHitsCSCM0, numHitsRPCM0);
      }
      //Fill Histos here                                                                                                                                              
      h_DT_FirstStation_etag1p2_Muons->Fill(numHitsDTM0.at(0));
      h_CSC_FirstStation_etag1p2_Muons->Fill(numHitsCSCM0.at(0));
      h_RPC_FirstStation_etag1p2_Muons->Fill(numHitsRPCM0.at(0));

      h_DT_FirstStation_Matches_etag1p2_Muons->Fill(numMatchesDTM0.at(0));
      h_CSC_FirstStation_Matches_etag1p2_Muons->Fill(numMatchesCSCM0.at(0));
      h_RPC_FirstStation_Matches_etag1p2_Muons->Fill(numMatchesRPCM0.at(0));

      h_DT_SecondStation_etag1p2_Muons->Fill(numHitsDTM0.at(1));
      h_CSC_SecondStation_etag1p2_Muons->Fill(numHitsCSCM0.at(1));
      h_RPC_SecondStation_etag1p2_Muons->Fill(numHitsRPCM0.at(1));

      h_DT_SecondStation_Matches_etag1p2_Muons->Fill(numMatchesDTM0.at(1));
      h_CSC_SecondStation_Matches_etag1p2_Muons->Fill(numMatchesCSCM0.at(1));
      h_RPC_SecondStation_Matches_etag1p2_Muons->Fill(numMatchesRPCM0.at(1));
  
      h_DT_ThirdStation_etag1p2_Muons->Fill(numHitsDTM0.at(2));
      h_CSC_ThirdStation_etag1p2_Muons->Fill(numHitsCSCM0.at(2));
      h_RPC_ThirdStation_etag1p2_Muons->Fill(numHitsRPCM0.at(2));

      h_DT_ThirdStation_Matches_etag1p2_Muons->Fill(numMatchesDTM0.at(2));
      h_CSC_ThirdStation_Matches_etag1p2_Muons->Fill(numMatchesCSCM0.at(2));
      h_RPC_ThirdStation_Matches_etag1p2_Muons->Fill(numMatchesRPCM0.at(2));


      h_DT_FourthStation_etag1p2_Muons->Fill(numHitsDTM0.at(3));
      h_CSC_FourthStation_etag1p2_Muons->Fill(numHitsCSCM0.at(3));
      h_RPC_FourthStation_etag1p2_Muons->Fill(numHitsRPCM0.at(3));

      h_DT_FourthStation_Matches_etag1p2_Muons->Fill(numMatchesDTM0.at(3));
      h_CSC_FourthStation_Matches_etag1p2_Muons->Fill(numMatchesCSCM0.at(3));
      h_RPC_FourthStation_Matches_etag1p2_Muons->Fill(numMatchesRPCM0.at(3));




    }


    
    }

      }
     }
    }
   
   // Muon Loop ends here 

     for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
       reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);

       std::vector<int> numMatchesDT(4), numMatchesDT0(4);
       std::vector<int> numMatchesCSC(4), numMatchesCSC0(4);
       std::vector<int> numMatchesRPC(4), numMatchesRPC0(4); 
      
       std::vector<int> numHitsDT(4), numHitsDT0(4), numHitsDT1(4),numHitsDT2(4);

       std::vector<int> numHitsCSC(4),numHitsCSC0(4), numHitsCSC1(4),numHitsCSC2(4);
       std::vector<int> numHitsRPC(4),numHitsRPC0(4), numHitsRPC1(4),numHitsRPC2(4);

       for ( int iStation = 0; iStation < 4; ++iStation ) {
	 numMatchesDT[iStation]  = 0;
	 numMatchesDT0[iStation]  = 0;
	 numMatchesCSC[iStation]  = 0;
	 numMatchesCSC0[iStation]  = 0;
	 numMatchesRPC[iStation]  = 0;
	 numMatchesRPC0[iStation]  = 0; 
	 numHitsDT[iStation]  = 0;
	 numHitsDT0[iStation]  = 0;
	 numHitsDT1[iStation]  = 0;
	 numHitsDT2[iStation]  = 0;
	 numHitsCSC[iStation] = 0;
	 numHitsCSC0[iStation] = 0;
	 numHitsCSC1[iStation] = 0;
	 numHitsCSC2[iStation] = 0;
	 numHitsRPC[iStation] = 0;
	 numHitsRPC0[iStation] = 0;
	 numHitsRPC1[iStation] = 0;
	 numHitsRPC2[iStation] = 0;
       } 
       
      bool TauEtaCuts = false;
      bool RecoptCut = false;
      bool DecayModeFinding = false;
      
      
      if(abs(tauCandidate->eta()) < 2.3) TauEtaCuts = true;
      
      if((tauCandidate->pt()) > 20) RecoptCut = true;
      
      if((*_dmf)[tauCandidate] > 0.5) DecayModeFinding = true; 
      
      
      if( (TauEtaCuts) && (RecoptCut) ) { 
	
        int igentau = 0;
	int index  = -1;
        if(OverlapWithGenTau( tauCandidate->eta() , tauCandidate->phi() , genTauJets , index ) && index != -1 ){
	  for(reco::GenJetCollection::const_iterator gentaujet = genTauJets->begin(); gentaujet !=  genTauJets->end(); ++gentaujet) {
	    
	    if(igentau == index) {
	      tauGenJetDecayModeInt = -999;
	      //double DR = reco::deltaR(gentaujet->eta(), gentaujet->phi(), tauCandidate->eta(), tauCandidate->phi());
	      
	      
	      //just to crosse-check otherwise does not make sense as OverlapWithGenTau function is used earlier 
	      
	      if(reco::deltaR(gentaujet->eta(), gentaujet->phi(), tauCandidate->eta(), tauCandidate->phi()) < _TauToGenMatchingDeltaR) {
		//Pat Tau which is matched to Gen Tau
		
		if(DecayModeFinding) {
		  
		  //Pat Tau which is matched to Gen Tau
		  
		  std::string tauGenJetDecayMode = JetMCTagUtils::genTauDecayMode(*gentaujet);
		  
		  
		  if(tauGenJetDecayMode=="muon") continue;
		  if(tauGenJetDecayMode=="electron") continue;
		  
		  
		  // After having hadronic gen decay mode of matched gen tau, we are filling this information
		  if(fabs(tauCandidate->eta()) < 1.2) {
		    
		    if (tauCandidate->leadPFChargedHadrCand().isNonnull() ) {
		      reco::MuonRef muonRef = tauCandidate->leadPFChargedHadrCand()->muonRef();      
		      if ( muonRef.isNonnull() ) {
			// std::cout << " has muonRef." << std::endl;
			numMatches = muonRef->numberOfMatches(reco::Muon::NoArbitration);
			countHits(*muonRef, numHitsDT, numHitsCSC, numHitsRPC);
			countMatches(*muonRef, numMatchesDT, numMatchesCSC, numMatchesRPC);
		      }
		    } 
		    
		    h_Fill_numMatches_eta1p2->Fill(numMatches);
		    
		    //For 1st station
		    h_DT_FirstStation_eta1p2->Fill(numHitsDT.at(0));
		    h_CSC_FirstStation_eta1p2->Fill(numHitsCSC.at(0));
		    h_RPC_FirstStation_eta1p2->Fill(numHitsRPC.at(0));
		    
		    h_DT_FirstStation_Matches_eta1p2->Fill(numMatchesDT.at(0));
                    h_CSC_FirstStation_Matches_eta1p2->Fill(numMatchesCSC.at(0));
                    h_RPC_FirstStation_Matches_eta1p2->Fill(numMatchesRPC.at(0));

		    //Second Station
		    
		    h_DT_SecondStation_eta1p2->Fill(numHitsDT.at(1));
		    h_CSC_SecondStation_eta1p2->Fill(numHitsCSC.at(1));
		    h_RPC_SecondStation_eta1p2->Fill(numHitsRPC.at(1));

		    h_DT_SecondStation_Matches_eta1p2->Fill(numMatchesDT.at(1));
                    h_CSC_SecondStation_Matches_eta1p2->Fill(numMatchesCSC.at(1));
                    h_RPC_SecondStation_Matches_eta1p2->Fill(numMatchesRPC.at(1));
		    
		    //Third Station
		    h_DT_ThirdStation_eta1p2->Fill(numHitsDT.at(2));
		    h_CSC_ThirdStation_eta1p2->Fill(numHitsCSC.at(2));
		    h_RPC_ThirdStation_eta1p2->Fill(numHitsRPC.at(2));

		    h_DT_ThirdStation_Matches_eta1p2->Fill(numMatchesDT.at(2));
                    h_CSC_ThirdStation_Matches_eta1p2->Fill(numMatchesCSC.at(2));
                    h_RPC_ThirdStation_Matches_eta1p2->Fill(numMatchesRPC.at(2));

		    
		    //Fourth Station
		    
		    h_DT_FourthStation_eta1p2->Fill(numHitsDT.at(3));
		    h_CSC_FourthStation_eta1p2->Fill(numHitsCSC.at(3));
		    h_RPC_FourthStation_eta1p2->Fill(numHitsRPC.at(3));
		    
		    h_DT_FourthStation_Matches_eta1p2->Fill(numMatchesDT.at(3));
                    h_CSC_FourthStation_Matches_eta1p2->Fill(numMatchesCSC.at(3));
                    h_RPC_FourthStation_Matches_eta1p2->Fill(numMatchesRPC.at(3));

		    
		  }
	      
		  if(fabs(tauCandidate->eta()) > 1.2) {
		    
		    if (tauCandidate->leadPFChargedHadrCand().isNonnull() ) {
		      reco::MuonRef muonRef0 = tauCandidate->leadPFChargedHadrCand()->muonRef();      
		      if ( muonRef0.isNonnull() ) {
			// std::cout << " has muonRef." << std::endl;
			numMatches0 = muonRef0->numberOfMatches(reco::Muon::NoArbitration);
			countHits(*muonRef0, numHitsDT0, numHitsCSC0, numHitsRPC0);
			countMatches(*muonRef0, numMatchesDT0, numMatchesCSC0, numMatchesRPC0);
			// cout<<"numMatches"<<numMatches<<endl;
		      }
		    } 
		    
		    h_Fill_numMatches_etag1p2->Fill(numMatches0);
		    
		    
		    //For 1st station
		    h_DT_FirstStation_etag1p2->Fill(numHitsDT0.at(0));
		    h_CSC_FirstStation_etag1p2->Fill(numHitsCSC0.at(0));
		    h_RPC_FirstStation_etag1p2->Fill(numHitsRPC0.at(0));

		    h_DT_FirstStation_Matches_etag1p2->Fill(numMatchesDT0.at(0));
		    h_CSC_FirstStation_Matches_etag1p2->Fill(numMatchesCSC0.at(0));
		    h_RPC_FirstStation_Matches_etag1p2->Fill(numMatchesRPC0.at(0));
		    
		    
		    
		    //Second Station
		    
		    h_DT_SecondStation_etag1p2->Fill(numHitsDT0.at(1));
		    h_CSC_SecondStation_etag1p2->Fill(numHitsCSC0.at(1));
		    h_RPC_SecondStation_etag1p2->Fill(numHitsRPC0.at(1));
		
		    h_DT_SecondStation_Matches_etag1p2->Fill(numMatchesDT0.at(1));
                    h_CSC_SecondStation_Matches_etag1p2->Fill(numMatchesCSC0.at(1));
                    h_RPC_SecondStation_Matches_etag1p2->Fill(numMatchesRPC0.at(1));

		    //Third Station
		    h_DT_ThirdStation_etag1p2->Fill(numHitsDT0.at(2));
		    h_CSC_ThirdStation_etag1p2->Fill(numHitsCSC0.at(2));
		    h_RPC_ThirdStation_etag1p2->Fill(numHitsRPC0.at(2));
		    
		    h_DT_ThirdStation_Matches_etag1p2->Fill(numMatchesDT0.at(2));
                    h_CSC_ThirdStation_Matches_etag1p2->Fill(numMatchesCSC0.at(2));
                    h_RPC_ThirdStation_Matches_etag1p2->Fill(numMatchesRPC0.at(2));

		    //Fourth Station
		    
		    h_DT_FourthStation_etag1p2->Fill(numHitsDT0.at(3));
		    h_CSC_FourthStation_etag1p2->Fill(numHitsCSC0.at(3));
		    h_RPC_FourthStation_etag1p2->Fill(numHitsRPC0.at(3));
		    
		    h_DT_FourthStation_Matches_etag1p2->Fill(numMatchesDT0.at(3));
                    h_CSC_FourthStation_Matches_etag1p2->Fill(numMatchesCSC0.at(3));
                    h_RPC_FourthStation_Matches_etag1p2->Fill(numMatchesRPC0.at(3));

		
	      }
	      
	      
		  if((*_mv1)[tauCandidate] > 0.5) {
		    
		    
		    //lets see what happens in these variables when they pass through Muon Veto
		    if (tauCandidate->leadPFChargedHadrCand().isNonnull() ) {
		      reco::MuonRef muonRef1 = tauCandidate->leadPFChargedHadrCand()->muonRef();      
		      if ( muonRef1.isNonnull() ) {
			//  std::cout << " has muonRef1." << std::endl;
			numMatches1 = muonRef1->numberOfMatches(pat::Muon::NoArbitration);
			countHits(*muonRef1, numHitsDT1, numHitsCSC1, numHitsRPC1);
			//  cout<<"numMatches1"<<numMatches1<<endl;
		      }
		    } 
		    
		    if(fabs(tauCandidate->eta()) < 1.2) {
		      h_Fill_numMatches_eta1p2_ML2->Fill(numMatches1);
		      
		      //For 1st station
		      h_DT_FirstStation_eta1p2_ML2->Fill(numHitsDT1.at(0));
		      h_CSC_FirstStation_eta1p2_ML2->Fill(numHitsCSC1.at(0));
		      h_RPC_FirstStation_eta1p2_ML2->Fill(numHitsRPC1.at(0));
		      
		      //Second Station
		      
		      h_DT_SecondStation_eta1p2_ML2->Fill(numHitsDT1.at(1));
		      h_CSC_SecondStation_eta1p2_ML2->Fill(numHitsCSC1.at(1));
		      h_RPC_SecondStation_eta1p2_ML2->Fill(numHitsRPC1.at(1));
		      
		      //Third Station
		      h_DT_ThirdStation_eta1p2_ML2->Fill(numHitsDT1.at(2));
		      h_CSC_ThirdStation_eta1p2_ML2->Fill(numHitsCSC1.at(2));
		      h_RPC_ThirdStation_eta1p2_ML2->Fill(numHitsRPC1.at(2));
		      
		      //Fourth Station
		      
		      h_DT_FourthStation_eta1p2_ML2->Fill(numHitsDT1.at(3));
		      h_CSC_FourthStation_eta1p2_ML2->Fill(numHitsCSC1.at(3));
		      h_RPC_FourthStation_eta1p2_ML2->Fill(numHitsRPC1.at(3));
		      
		      
		    }
		    
		    if(fabs(tauCandidate->eta()) > 1.2) {
		      h_Fill_numMatches_etag1p2_ML2->Fill(numMatches1);
		      
		      //For 1st station
		      h_DT_FirstStation_etag1p2_ML2->Fill(numHitsDT1.at(0));
		      h_CSC_FirstStation_etag1p2_ML2->Fill(numHitsCSC1.at(0));
		      h_RPC_FirstStation_etag1p2_ML2->Fill(numHitsRPC1.at(0));
		      
		      //Second Station
		      
		      h_DT_SecondStation_etag1p2_ML2->Fill(numHitsDT1.at(1));
		      h_CSC_SecondStation_etag1p2_ML2->Fill(numHitsCSC1.at(1));
		      h_RPC_SecondStation_etag1p2_ML2->Fill(numHitsRPC1.at(1));
		      
		      //Third Station
		      h_DT_ThirdStation_etag1p2_ML2->Fill(numHitsDT1.at(2));
		      h_CSC_ThirdStation_etag1p2_ML2->Fill(numHitsCSC1.at(2));
		      h_RPC_ThirdStation_etag1p2_ML2->Fill(numHitsRPC1.at(2));
		      
		      //Fourth Station
		      
		      h_DT_FourthStation_etag1p2_ML2->Fill(numHitsDT1.at(3));
		      h_CSC_FourthStation_etag1p2_ML2->Fill(numHitsCSC1.at(3));
		      h_RPC_FourthStation_etag1p2_ML2->Fill(numHitsRPC1.at(3));
		      
		      
		    }
		    
		    
		  }
		  
		  
		  if((*_mv31)[tauCandidate] > 0.5) {
	   	    
		    //lets see what happens in these variables when they pass through Muon Veto
		    if (tauCandidate->leadPFChargedHadrCand().isNonnull() ) {
		      reco::MuonRef muonRef2 = tauCandidate->leadPFChargedHadrCand()->muonRef();      
		      if ( muonRef2.isNonnull() ) {
			//  std::cout << " has muonRef2." << std::endl;
			numMatches2 = muonRef2->numberOfMatches(pat::Muon::NoArbitration);
			countHits(*muonRef2, numHitsDT2, numHitsCSC2, numHitsRPC2);
			//  cout<<"numMatches2"<<numMatches2<<endl;
		      }
		    } 
		    
		    if(fabs(tauCandidate->eta()) < 1.2) {
		      h_Fill_numMatches_eta1p2_ML3->Fill(numMatches2);
		      
		      //For 1st station
		      h_DT_FirstStation_eta1p2_ML3->Fill(numHitsDT2.at(0));
		      h_CSC_FirstStation_eta1p2_ML3->Fill(numHitsCSC2.at(0));
		      h_RPC_FirstStation_eta1p2_ML3->Fill(numHitsRPC2.at(0));
		      
		      //Second Station
		      
		      h_DT_SecondStation_eta1p2_ML3->Fill(numHitsDT2.at(1));
		      h_CSC_SecondStation_eta1p2_ML3->Fill(numHitsCSC2.at(1));
		      h_RPC_SecondStation_eta1p2_ML3->Fill(numHitsRPC2.at(1));
		      
		      //Third Station
		      h_DT_ThirdStation_eta1p2_ML3->Fill(numHitsDT2.at(2));
		      h_CSC_ThirdStation_eta1p2_ML3->Fill(numHitsCSC2.at(2));
		      h_RPC_ThirdStation_eta1p2_ML3->Fill(numHitsRPC2.at(2));
		      
		      //Fourth Station
		      
		      h_DT_FourthStation_eta1p2_ML3->Fill(numHitsDT2.at(3));
		      h_CSC_FourthStation_eta1p2_ML3->Fill(numHitsCSC2.at(3));
		      h_RPC_FourthStation_eta1p2_ML3->Fill(numHitsRPC2.at(3));
		      
		      
		    }
		    
		    if(fabs(tauCandidate->eta()) > 1.2) {
		      h_Fill_numMatches_etag1p2_ML3->Fill(numMatches2);
		      
		      //For 1st station
		      h_DT_FirstStation_etag1p2_ML3->Fill(numHitsDT2.at(0));
		      h_CSC_FirstStation_etag1p2_ML3->Fill(numHitsCSC2.at(0));
		      h_RPC_FirstStation_etag1p2_ML3->Fill(numHitsRPC2.at(0));
		      
		      //Second Station
		      
		      h_DT_SecondStation_etag1p2_ML3->Fill(numHitsDT2.at(1));
		      h_CSC_SecondStation_etag1p2_ML3->Fill(numHitsCSC2.at(1));
		      h_RPC_SecondStation_etag1p2_ML3->Fill(numHitsRPC2.at(1));
		      
		      //Third Station
		      h_DT_ThirdStation_etag1p2_ML3->Fill(numHitsDT2.at(2));
		      h_CSC_ThirdStation_etag1p2_ML3->Fill(numHitsCSC2.at(2));
		      h_RPC_ThirdStation_etag1p2_ML3->Fill(numHitsRPC2.at(2));
		      
		      //Fourth Station

		      h_DT_FourthStation_etag1p2_ML3->Fill(numHitsDT2.at(3));
		      h_CSC_FourthStation_etag1p2_ML3->Fill(numHitsCSC2.at(3));
		      h_RPC_FourthStation_etag1p2_ML3->Fill(numHitsRPC2.at(3));
		      
		      
		    }
		  }
		}  
	      }
	    }
	    
	    igentau++;
	  }
	}
      }
     }
  }
}
// ------------ method called once each job just before starting event loop  ------------


bool MuonVeto::IsZTauTau(edm::Handle<reco::GenParticleCollection> genParticles){
   bool isZTauTau = false;
  reco::GenParticleCollection::const_iterator particle;
  for (particle = genParticles->begin(); particle != genParticles->end();  particle++) {
    if ((abs(particle->pdgId()) == _TauMotherId)) {
//      std::cout<<" Z found with pdgid = "<<particle->numberOfDaughters()<<std::endl;
      int daughters  = particle->numberOfDaughters();
       for (int j = 0; j<daughters; ++j) {
        const reco::Candidate *daughter = particle->daughter(j);
         int pidg = std::abs(daughter->pdgId());
         if (pidg == 15) {
           isZTauTau = true;
//           std::cout<<"working inside function"<<std::endl;
           break;
        }
      }
    }
  }
  return isZTauTau;  
}

bool MuonVeto::OverlapWithGenTau(double Taueta , double Tauphi ,edm::Handle<std::vector< reco::GenJet > > genTauJets ,int  &index ) {
  double drtmp = _TauToGenMatchingDeltaR;
  int tmpindex =0 ;
  bool genTaufound = false;
  for(std::vector<reco::GenJet>::const_iterator genJetItr=genTauJets->begin(); genJetItr!=genTauJets->end(); ++genJetItr) {
 
    double dr =reco::deltaR(Taueta, Tauphi,genJetItr->eta(),genJetItr->phi());
    if(dr < drtmp){
      drtmp = dr;
      index = tmpindex;
      genTaufound= true;
    }
    tmpindex++;
  }
  return genTaufound;
}


void MuonVeto::countHits(const reco::Muon& muon, std::vector<int>& numHitsDT, std::vector<int>& numHitsCSC, std::vector<int>& numHitsRPC)
  {
//        cout<<"Muon Outer Track not applied"<<endl;
    if ( muon.outerTrack().isNonnull() ) {
  
//      cout<<"Muon Outer Track"<<endl;
//         if(muon.outerTrack()->hitPattern().found()){
     
         const reco::HitPattern& muonHitPattern = muon.outerTrack()->hitPattern();
  //       cout<<"muonHitPattern.numberOfHits();"<<muonHitPattern.numberOfHits()<<endl;
       for ( int iHit = 0; iHit < muonHitPattern.numberOfHits(); ++iHit ) {
          int hit = muonHitPattern.getHitPattern(iHit);
//          cout<<"hit in function"<<hit<<endl;
       if ( hit == 0 ) break;      
      if ( muonHitPattern.muonHitFilter(hit) && (muonHitPattern.getHitType(hit) == TrackingRecHit::valid || muonHitPattern.getHitType(hit) == TrackingRecHit::bad) ) {
           int muonStation = muonHitPattern.getMuonStation(hit) - 1; // CV: map into range 0..3
           if ( muonStation >= 0 && muonStation < 4 ) {
            if      ( muonHitPattern.muonDTHitFilter(hit)  ) ++numHitsDT[muonStation];
             else if ( muonHitPattern.muonCSCHitFilter(hit) ) ++numHitsCSC[muonStation];
             else if ( muonHitPattern.muonRPCHitFilter(hit) ) ++numHitsRPC[muonStation];
           }
         }
       }
     }
  }
//   }


void MuonVeto::countMatches(const reco::Muon& muon, std::vector<int>& numMatchesDT, std::vector<int>& numMatchesCSC, std::vector<int>& numMatchesRPC)                     
   {
     const std::vector<reco::MuonChamberMatch>& muonSegments = muon.matches();
     for ( std::vector<reco::MuonChamberMatch>::const_iterator muonSegment = muonSegments.begin(); muonSegment != muonSegments.end(); ++muonSegment ) {
       if ( muonSegment->segmentMatches.empty() ) continue;
       int muonDetector = muonSegment->detector();
       int muonStation = muonSegment->station() - 1;
//       if(muonStation >= 0 && muonStation <= 3) {
       assert(muonStation >= 0 && muonStation <= 3);
       if      ( muonDetector == MuonSubdetId::DT  ) ++numMatchesDT[muonStation];
       else if ( muonDetector == MuonSubdetId::CSC ) ++numMatchesCSC[muonStation];
       else if ( muonDetector == MuonSubdetId::RPC ) ++numMatchesRPC[muonStation];
//     }
  }
}


