#include "./TauIDChecksG2p3.h"                                                                                                                                        
  

TauIDChecksG2p3::TauIDChecksG2p3(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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


  TauPtResponse_DM = fs->make<TH1F>(("TauPtResponse_DM"+prefix).c_str() ,"TauPtResponse_DM",100,0.1,2.0);

 TauPtResponse_ML2 = fs->make<TH1F>(("TauPtResponse_ML2"+prefix).c_str() ,"TauPtResponse_ML2",100,0.1,2.0);

 TauPtResponse_MM2 = fs->make<TH1F>(("TauPtResponse_MM2"+prefix).c_str() ,"TauPtResponse_MM2",100,0.1,2.0);


 TauPtResponse_MT2= fs->make<TH1F>(("TauPtResponse_MT2"+prefix).c_str() ,"TauPtResponse_MT2",100,0.1,2.0);

 TauPtResponse_ML3 = fs->make<TH1F>(("TauPtResponse_ML3"+prefix).c_str() ,"TauPtResponse_ML3",100,0.1,2.0);

 TauPtResponse_MT3= fs->make<TH1F>(("TauPtResponse_MT3"+prefix).c_str() ,"TauPtResponse_MT3",100,0.1,2.0);

 TauPtResponse_EL3 = fs->make<TH1F>(("TauPtResponse_EL3"+prefix).c_str() ,"TauPtResponse_EL3",100,0.1,2.0);

 TauPtResponse_EM3 = fs->make<TH1F>(("TauPtResponse_EM3"+prefix).c_str() ,"TauPtResponse_EM3",100,0.1,2.0);

 TauPtResponse_ET3 = fs->make<TH1F>(("TauPtResponse_ET3"+prefix).c_str() ,"TauPtResponse_ET3",100,0.1,2.0);

TauPtResponse_Cut  = fs->make<TH1F>(("TauPtResponse_Cut"+prefix).c_str() ,"TauPtResponse_Cut",100,0.1,2.0);

 RecoTauDecayMode_Cut  = fs->make<TH1F>(("RecoTauDecayMode_Cut"+prefix).c_str() ,"RecoTauDecayMode_Cut",15,0,15);
  GenTauDecayMode_Cut   = fs->make<TH1F>(("GenTauDecayMode_Cut"+prefix).c_str() ,"GenTauDecayMode_Cut",15,0,15);
  reco_dm_vs_gen_Cut = fs->make<TH2F>(("reco_dm_vs_gen_Cut"+prefix).c_str() ,"reco_dm_vs_gen_Cut",15,0,15,15,0,15);
  GenTauPtWithDMF_Cut = fs->make<TH1F>(("GenTauPtWithDMF_Cut"+prefix).c_str() ,"GenTauPtWithDMF_Cut" ,100,0,700);
  GenTauEtaWithDMF_Cut = fs->make<TH1F>(("GenTauEtaWithDMF_Cut"+prefix).c_str() ,"GenTauEtaWithDMF_Cut"  ,100,-5,5);
  GenTauPhiWithDMF_Cut = fs->make<TH1F>(("GenTauPhiWithDMF_Cut"+prefix).c_str() ,"GenTauPhiWithDMF_Cut"  ,100,-5,5);

 TauPtResponse_DM_LooseIso_1Prong1Pi0 = fs->make<TH1F>(("TauPtResponse_DM_LooseIso_1Prong1Pi0"+prefix).c_str() ,"TauPtResponse_DM_LooseIso_1Prong1Pi0",100,0.1,2.0);

 TauPtResponse_DM_LooseIso_1Prong= fs->make<TH1F>(("TauPtResponse_DM_LooseIso_1Prong"+prefix).c_str() ,"TauPtResponse_DM_LooseIso_1Prong",100,0.1,2.0);

TauPtResponse_DM_LooseIso_1Prong2Pi0 = fs->make<TH1F>(("TauPtResponse_DM_LooseIso_1Prong2Pi0"+prefix).c_str() ,"TauPtResponse_DM_LooseIso_1Prong2Pi0",100,0.1,2.0    );

TauPtResponse_DM_LooseIso_3Prong = fs->make<TH1F>(("TauPtResponse_DM_LooseIso_3Prong"+prefix).c_str() ,"TauPtResponse_DM_LooseIso_3Prong",100,0.1,2.0);

 TauPtResponse_DM_LooseIso_3Prong1Pi0 = fs->make<TH1F>(("TauPtResponse_DM_LooseIso_3Prong1Pi0"+prefix).c_str() ,"TauPtResponse_DM_LooseIso_3Prong1Pi0",100,0.1,2.0);


 TauPtResponse_LIso3Hits = fs->make<TH1F>(("TauPtResponse_LIso3Hits"+prefix).c_str() ,"TauPtResponse_LIso3Hits",100,0.1,2.0);

 TauPtResponse_MIso3Hits = fs->make<TH1F>(("TauPtResponse_MIso3Hits"+prefix).c_str() ,"TauPtResponse_MIso3Hits",100,0.1,2.0);

 TauPtResponse_TIso3Hits = fs->make<TH1F>(("TauPtResponse_TIso3Hits"+prefix).c_str() ,"TauPtResponse_TIso3Hits",100,0.1,2.0);


 TauPtResponse_LIso = fs->make<TH1F>(("TauPtResponse_LIso"+prefix).c_str() ,"TauPtResponse_LIso",100,0.1,2.0);

 TauPtResponse_MIso = fs->make<TH1F>(("TauPtResponse_MIso"+prefix).c_str() ,"TauPtResponse_MIso",100,0.1,2.0);

 TauPtResponse_TIso = fs->make<TH1F>(("TauPtResponse_TIso"+prefix).c_str() ,"TauPtResponse_TIso",100,0.1,2.0);

 TauPtResponse_VLChar = fs->make<TH1F>(("TauPtResponse_VLChar"+prefix).c_str() ,"TauPtResponse_VLChar",100,0.1,2.0);

 TauPtResponse_LChar = fs->make<TH1F>(("TauPtResponse_LChar"+prefix).c_str() ,"TauPtResponse_LChar",100,0.1,2.0);

 TauPtResponse_MChar = fs->make<TH1F>(("TauPtResponse_MChar"+prefix).c_str() ,"TauPtResponse_MChar",100,0.1,2.0);

 TauPtResponse_TChar = fs->make<TH1F>(("TauPtResponse_TChar"+prefix).c_str() ,"TauPtResponse_TChar",100,0.1,2.0);



 npuVertices_ =fs->make<TH1I>(("npuVertices"+prefix).c_str() , "npuVertices" , 500,   0.0, 500.0);
 ootnpuVertices_ =fs->make<TH1I>(("ootnpuVertices"+prefix).c_str() , "ootnpuVertices" , 500,   0.0, 500.0);

  RecoTauDecayMode_DM = fs->make<TH1F>(("RecoTauDecayMode_DM"+prefix).c_str() ,"RecoTauDecayMode_DM",15,0,15);
  GenTauDecayMode_DM = fs->make<TH1F>(("GenTauDecayMode_DM"+prefix).c_str() ,"GenTauDecayMode_DM",15,0,15);
  reco_dm_vs_gen_dm = fs->make<TH2F>(("reco_dm_vs_gen_dm"+prefix).c_str() ,"reco_dm_vs_gen_dm",15,0,15,15,0,15);



  RecoTauDecayMode_ML2 = fs->make<TH1F>(("RecoTauDecayMode_ML2"+prefix).c_str() ,"RecoTauDecayMode_ML2",15,0,15);
  GenTauDecayMode_ML2 = fs->make<TH1F>(("GenTauDecayMode_ML2"+prefix).c_str() ,"GenTauDecayMode_ML2",15,0,15);
  reco_dm_vs_gen_ML2 = fs->make<TH2F>(("reco_dm_vs_gen_ML2"+prefix).c_str() ,"reco_dm_vs_gen_ML2",15,0,15,15,0,15);

  RecoTauDecayMode_MM2 = fs->make<TH1F>(("RecoTauDecayMode_MM2"+prefix).c_str() ,"RecoTauDecayMode_MM2",15,0,15);
  GenTauDecayMode_MM2 = fs->make<TH1F>(("GenTauDecayMode_MM2"+prefix).c_str() ,"GenTauDecayMode_MM2",15,0,15);
  reco_dm_vs_gen_MM2 = fs->make<TH2F>(("reco_dm_vs_gen_MM2"+prefix).c_str() ,"reco_dm_vs_gen_MM2",15,0,15,15,0,15);

  RecoTauDecayMode_MT2 = fs->make<TH1F>(("RecoTauDecayMode_MT2"+prefix).c_str() ,"RecoTauDecayMode_MT2",15,0,15);
  GenTauDecayMode_MT2 = fs->make<TH1F>(("GenTauDecayMode_MT2"+prefix).c_str() ,"GenTauDecayMode_MT2",15,0,15);
  reco_dm_vs_gen_MT2 = fs->make<TH2F>(("reco_dm_vs_gen_MT2"+prefix).c_str() ,"reco_dm_vs_gen_MT2",15,0,15,15,0,15);

  RecoTauDecayMode_ML3 = fs->make<TH1F>(("RecoTauDecayMode_ML3"+prefix).c_str() ,"RecoTauDecayMode_ML3",15,0,15);
  GenTauDecayMode_ML3 = fs->make<TH1F>(("GenTauDecayMode_ML3"+prefix).c_str() ,"GenTauDecayMode_ML3",15,0,15);
  reco_dm_vs_gen_ML3 = fs->make<TH2F>(("reco_dm_vs_gen_ML3"+prefix).c_str() ,"reco_dm_vs_gen_ML3",15,0,15,15,0,15);


  RecoTauDecayMode_MT3 = fs->make<TH1F>(("RecoTauDecayMode_MT3"+prefix).c_str() ,"RecoTauDecayMode_MT3",15,0,15);
  GenTauDecayMode_MT3 = fs->make<TH1F>(("GenTauDecayMode_MT3"+prefix).c_str() ,"GenTauDecayMode_MT3",15,0,15);
  reco_dm_vs_gen_MT3 = fs->make<TH2F>(("reco_dm_vs_gen_MT3"+prefix).c_str() ,"reco_dm_vs_gen_MT3",15,0,15,15,0,15);

  RecoTauDecayMode_EL3 = fs->make<TH1F>(("RecoTauDecayMode_EL3"+prefix).c_str() ,"RecoTauDecayMode_EL3",15,0,15);
  GenTauDecayMode_EL3 = fs->make<TH1F>(("GenTauDecayMode_EL3"+prefix).c_str() ,"GenTauDecayMode_EL3",15,0,15);
  reco_dm_vs_gen_EL3 = fs->make<TH2F>(("reco_dm_vs_gen_EL3"+prefix).c_str() ,"reco_dm_vs_gen_EL3",15,0,15,15,0,15);


  RecoTauDecayMode_EM3 = fs->make<TH1F>(("RecoTauDecayMode_EM3"+prefix).c_str() ,"RecoTauDecayMode_EM3",15,0,15);
  GenTauDecayMode_EM3 = fs->make<TH1F>(("GenTauDecayMode_EM3"+prefix).c_str() ,"GenTauDecayMode_EM3",15,0,15);
  reco_dm_vs_gen_EM3 = fs->make<TH2F>(("reco_dm_vs_gen_EM3"+prefix).c_str() ,"reco_dm_vs_gen_EM3",15,0,15,15,0,15);

  RecoTauDecayMode_ET3 = fs->make<TH1F>(("RecoTauDecayMode_ET3"+prefix).c_str() ,"RecoTauDecayMode_ET3",15,0,15);
  GenTauDecayMode_ET3 = fs->make<TH1F>(("GenTauDecayMode_ET3"+prefix).c_str() ,"GenTauDecayMode_ET3",15,0,15);
  reco_dm_vs_gen_ET3 = fs->make<TH2F>(("reco_dm_vs_gen_ET3"+prefix).c_str() ,"reco_dm_vs_gen_ET3",15,0,15,15,0,15);

  RecoTauDecayMode_LIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_LIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_LIso3Hits",15,0,15);
  GenTauDecayMode_LIso3Hits = fs->make<TH1F>(("GenTauDecayMode_LIso3Hits"+prefix).c_str() ,"GenTauDecayMode_LIso3Hits",15,0,15);
  reco_dm_vs_gen_LIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_LIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_LIso3Hits",15,0,15,15,0,15);

  RecoTauDecayMode_MIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_MIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_MIso3Hits",15,0,15);
  GenTauDecayMode_MIso3Hits = fs->make<TH1F>(("GenTauDecayMode_MIso3Hits"+prefix).c_str() ,"GenTauDecayMode_MIso3Hits",15,0,15);
  reco_dm_vs_gen_MIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_MIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_MIso3Hits",15,0,15,15,0,15);

  RecoTauDecayMode_TIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_TIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_TIso3Hits",15,0,15);
  GenTauDecayMode_TIso3Hits = fs->make<TH1F>(("GenTauDecayMode_TIso3Hits"+prefix).c_str() ,"GenTauDecayMode_TIso3Hits",15,0,15);
  reco_dm_vs_gen_TIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_TIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_TIso3Hits",15,0,15,15,0,15);

  RecoTauDecayMode_LIso = fs->make<TH1F>(("RecoTauDecayMode_LIso"+prefix).c_str() ,"RecoTauDecayMode_LIso",15,0,15);
  GenTauDecayMode_LIso = fs->make<TH1F>(("GenTauDecayMode_LIso"+prefix).c_str() ,"GenTauDecayMode_LIso",15,0,15);
  reco_dm_vs_gen_LIso = fs->make<TH2F>(("reco_dm_vs_gen_LIso"+prefix).c_str() ,"reco_dm_vs_gen_LIso",15,0,15,15,0,15);

  RecoTauDecayMode_MIso = fs->make<TH1F>(("RecoTauDecayMode_MIso"+prefix).c_str() ,"RecoTauDecayMode_MIso",15,0,15);
  GenTauDecayMode_MIso = fs->make<TH1F>(("GenTauDecayMode_MIso"+prefix).c_str() ,"GenTauDecayMode_MIso",15,0,15);
  reco_dm_vs_gen_MIso = fs->make<TH2F>(("reco_dm_vs_gen_MIso"+prefix).c_str() ,"reco_dm_vs_gen_MIso",15,0,15,15,0,15);

  RecoTauDecayMode_TIso = fs->make<TH1F>(("RecoTauDecayMode_TIso"+prefix).c_str() ,"RecoTauDecayMode_TIso",15,0,15);
  GenTauDecayMode_TIso = fs->make<TH1F>(("GenTauDecayMode_TIso"+prefix).c_str() ,"GenTauDecayMode_TIso",15,0,15);
  reco_dm_vs_gen_TIso = fs->make<TH2F>(("reco_dm_vs_gen_TIso"+prefix).c_str() ,"reco_dm_vs_gen_TIso",15,0,15,15,0,15);


  RecoTauDecayMode_VLChar = fs->make<TH1F>(("RecoTauDecayMode_VLChar"+prefix).c_str() ,"RecoTauDecayMode_VLChar",15,0,15);
  GenTauDecayMode_VLChar = fs->make<TH1F>(("GenTauDecayMode_VLChar"+prefix).c_str() ,"GenTauDecayMode_VLChar",15,0,15);
  reco_dm_vs_gen_VLChar = fs->make<TH2F>(("reco_dm_vs_gen_VLChar"+prefix).c_str() ,"reco_dm_vs_gen_VLChar",15,0,15,15,0,15);

  RecoTauDecayMode_LChar = fs->make<TH1F>(("RecoTauDecayMode_LChar"+prefix).c_str() ,"RecoTauDecayMode_LChar",15,0,15);
  GenTauDecayMode_LChar = fs->make<TH1F>(("GenTauDecayMode_LChar"+prefix).c_str() ,"GenTauDecayMode_LChar",15,0,15);
  reco_dm_vs_gen_LChar = fs->make<TH2F>(("reco_dm_vs_gen_LChar"+prefix).c_str() ,"reco_dm_vs_gen_LChar",15,0,15,15,0,15);

  RecoTauDecayMode_MChar = fs->make<TH1F>(("RecoTauDecayMode_MChar"+prefix).c_str() ,"RecoTauDecayMode_MChar",15,0,15);
  GenTauDecayMode_MChar = fs->make<TH1F>(("GenTauDecayMode_MChar"+prefix).c_str() ,"GenTauDecayMode_MChar",15,0,15);
  reco_dm_vs_gen_MChar = fs->make<TH2F>(("reco_dm_vs_gen_MChar"+prefix).c_str() ,"reco_dm_vs_gen_MChar",15,0,15,15,0,15);

  RecoTauDecayMode_TChar = fs->make<TH1F>(("RecoTauDecayMode_TChar"+prefix).c_str() ,"RecoTauDecayMode_TChar",15,0,15);
  GenTauDecayMode_TChar = fs->make<TH1F>(("GenTauDecayMode_TChar"+prefix).c_str() ,"GenTauDecayMode_TChar",15,0,15);
  reco_dm_vs_gen_TChar = fs->make<TH2F>(("reco_dm_vs_gen_TChar"+prefix).c_str() ,"reco_dm_vs_gen_TChar",15,0,15,15,0,15);

//  GenTauPtWithoutDMF = fs->make<TH1F>(("GenTauPtWithoutDMF", "GenTauPtWithoutDMF",100,0,700);
//  GenTauEtaWithoutDMF = fs->make<TH1F>(("GenTauEtaWithoutDMF", "GenTauEtaWithoutDMF",100,-5,5);
//  GenTauPhiWithoutDMF = fs->make<TH1F>(("GenTauPhiWithoutDMF", "GenTauPhiWithoutDMF",100,-5,5);

  GenTauPtWithoutDMF = fs->make<TH1F>(("GenTauPtWithoutDMF"+prefix).c_str(), "GenTauPtWithoutDMF",100,0,700); 
 GenTauEtaWithoutDMF = fs->make<TH1F>(("GenTauEtaWithoutDMF"+prefix).c_str() ,"GenTauEtaWithoutDMF",100,-5,5);
 GenTauPhiWithoutDMF = fs->make<TH1F>(("GenTauPhiWithoutDMF"+prefix).c_str() ,"GenTauPhiWithoutDMF",100,-5,5);


 GenTauPtWithoutDMF_eta1p47 = fs->make<TH1F>(("GenTauPtWithoutDMF_eta1p47"+prefix).c_str(), "GenTauPtWithoutDMF_eta1p47",100,0,700); 
 GenTauEtaWithoutDMF_eta1p47 = fs->make<TH1F>(("GenTauEtaWithoutDMF_eta1p47"+prefix).c_str() ,"GenTauEtaWithoutDMF_eta1p47",100,-5,5);
 GenTauPhiWithoutDMF_eta1p47 = fs->make<TH1F>(("GenTauPhiWithoutDMF_eta1p47"+prefix).c_str() ,"GenTauPhiWithoutDMF_eta1p47",100,-5,5);
 
 
 
 GenTauPtWithoutDMF_etag1p47 = fs->make<TH1F>(("GenTauPtWithoutDMF_etag1p47"+prefix).c_str(), "GenTauPtWithoutDMF_etag1p47",100,0,700); 
 GenTauEtaWithoutDMF_etag1p47 = fs->make<TH1F>(("GenTauEtaWithoutDMF_etag1p47"+prefix).c_str() ,"GenTauEtaWithoutDMF_etag1p47",100,-5,5);
 GenTauPhiWithoutDMF_etag1p47 = fs->make<TH1F>(("GenTauPhiWithoutDMF_etag1p47"+prefix).c_str() ,"GenTauPhiWithoutDMF_etag1p47",100,-5,5);
 

  GenTauPtWithDMF = fs->make<TH1F>(("GenTauPtWithDMF"+prefix).c_str() ,"GenTauPtWithDMF",100,0,700);
  GenTauEtaWithDMF = fs->make<TH1F>(("GenTauEtaWithDMF"+prefix).c_str() ,"GenTauEtaWithDMF",100,-5,5);
  GenTauPhiWithDMF = fs->make<TH1F>(("GenTauPhiWithDMF"+prefix).c_str() ,"GenTauPhiWithDMF",100,-5,5);


  GenTauPtWithDMF_ML2 = fs->make<TH1F>(("GenTauPtWithDMF_ML2"+prefix).c_str() ,"GenTauPtWithDMF_ML2" ,100,0,700);
  GenTauEtaWithDMF_ML2 = fs->make<TH1F>(("GenTauEtaWithDMF_ML2"+prefix).c_str() ,"GenTauEtaWithDMF_ML2" ,100,-5,5);
  GenTauPhiWithDMF_ML2 = fs->make<TH1F>(("GenTauPhiWithDMF_ML2"+prefix).c_str() ,"GenTauPhiWithDMF_ML2" ,100,-5,5);

  GenTauPtWithDMF_MM2 = fs->make<TH1F>(("GenTauPtWithDMF_MM2"+prefix).c_str() ,"GenTauPtWithDMF_MM2" ,100,0,700);
  GenTauEtaWithDMF_MM2 = fs->make<TH1F>(("GenTauEtaWithDMF_MM2"+prefix).c_str() ,"GenTauEtaWithDMF_MM2" ,100,-5,5);
  GenTauPhiWithDMF_MM2 = fs->make<TH1F>(("GenTauPhiWithDMF_MM2"+prefix).c_str() ,"GenTauPhiWithDMF_MM2" ,100,-5,5);

  GenTauPtWithDMF_MT2 = fs->make<TH1F>(("GenTauPtWithDMF_MT2"+prefix).c_str() ,"GenTauPtWithDMF_MT2" ,100,0,700);
  GenTauEtaWithDMF_MT2 = fs->make<TH1F>(("GenTauEtaWithDMF_MT2"+prefix).c_str() ,"GenTauEtaWithDMF_MT2" ,100,-5,5);
  GenTauPhiWithDMF_MT2 = fs->make<TH1F>(("GenTauPhiWithDMF_MT2"+prefix).c_str() ,"GenTauPhiWithDMF_MT2" ,100,-5,5);

  GenTauPtWithDMF_ML3 = fs->make<TH1F>(("GenTauPtWithDMF_ML3"+prefix).c_str() ,"GenTauPtWithDMF_ML3" ,100,0,700);
  GenTauEtaWithDMF_ML3 = fs->make<TH1F>(("GenTauEtaWithDMF_ML3"+prefix).c_str() ,"GenTauEtaWithDMF_ML3" ,100,-5,5);
  GenTauPhiWithDMF_ML3 = fs->make<TH1F>(("GenTauPhiWithDMF_ML3"+prefix).c_str() ,"GenTauPhiWithDMF_ML3" ,100,-5,5);
	  
  GenTauPtWithDMF_MT3 = fs->make<TH1F>(("GenTauPtWithDMF_MT3"+prefix).c_str() ,"GenTauPtWithDMF_MT3" ,100,0,700);
  GenTauEtaWithDMF_MT3 = fs->make<TH1F>(("GenTauEtaWithDMF_MT3"+prefix).c_str() ,"GenTauEtaWithDMF_MT3" ,100,-5,5);
  GenTauPhiWithDMF_MT3 = fs->make<TH1F>(("GenTauPhiWithDMF_MT3"+prefix).c_str() ,"GenTauPhiWithDMF_MT3" ,100,-5,5);
    	  
  GenTauPtWithDMF_EL3 = fs->make<TH1F>(("GenTauPtWithDMF_EL3"+prefix).c_str() ,"GenTauPtWithDMF_EL3" ,100,0,700);
  GenTauEtaWithDMF_EL3 = fs->make<TH1F>(("GenTauEtaWithDMF_EL3"+prefix).c_str() ,"GenTauEtaWithDMF_EL3" ,100,-5,5);
  GenTauPhiWithDMF_EL3 = fs->make<TH1F>(("GenTauPhiWithDMF_EL3"+prefix).c_str() ,"GenTauPhiWithDMF_EL3" ,100,-5,5);

  GenTauPtWithDMF_EM3 = fs->make<TH1F>(("GenTauPtWithDMF_EM3"+prefix).c_str() ,"GenTauPtWithDMF_EM3" ,100,0,700);
  GenTauEtaWithDMF_EM3 = fs->make<TH1F>(("GenTauEtaWithDMF_EM3"+prefix).c_str() ,"GenTauEtaWithDMF_EM3" ,100,-5,5);
  GenTauPhiWithDMF_EM3 = fs->make<TH1F>(("GenTauPhiWithDMF_EM3"+prefix).c_str() ,"GenTauPhiWithDMF_EM3" ,100,-5,5);

  GenTauPtWithDMF_ET3 = fs->make<TH1F>(("GenTauPtWithDMF_ET3"+prefix).c_str() ,"GenTauPtWithDMF_ET3" ,100,0,700);
  GenTauEtaWithDMF_ET3 = fs->make<TH1F>(("GenTauEtaWithDMF_ET3"+prefix).c_str() ,"GenTauEtaWithDMF_ET3" ,100,-5,5);
  GenTauPhiWithDMF_ET3 = fs->make<TH1F>(("GenTauPhiWithDMF_ET3"+prefix).c_str() ,"GenTauPhiWithDMF_ET3" ,100,-5,5);


  GenTauPtWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_LIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_LIso3Hits" ,100,-5,5);
  GenTauPhiWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_LIso3Hits" ,100,-5,5);

  GenTauPtWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_MIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_MIso3Hits" ,100,-5,5);
  GenTauPhiWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_MIso3Hits" ,100,-5,5);

  GenTauPtWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_TIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_TIso3Hits" ,100,-5,5);
  GenTauPhiWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_TIso3Hits" ,100,-5,5);



  GenTauPtWithDMF_LIso = fs->make<TH1F>(("GenTauPtWithDMF_LIso"+prefix).c_str() ,"GenTauPtWithDMF_LIso" ,100,0,700);
  GenTauEtaWithDMF_LIso = fs->make<TH1F>(("GenTauEtaWithDMF_LIso"+prefix).c_str() ,"GenTauEtaWithDMF_LIso" ,100,-5,5);
  GenTauPhiWithDMF_LIso = fs->make<TH1F>(("GenTauPhiWithDMF_LIso"+prefix).c_str() ,"GenTauPhiWithDMF_LIso" ,100,-5,5);

  GenTauPtWithDMF_MIso = fs->make<TH1F>(("GenTauPtWithDMF_MIso"+prefix).c_str() ,"GenTauPtWithDMF_MIso" ,100,0,700);
  GenTauEtaWithDMF_MIso = fs->make<TH1F>(("GenTauEtaWithDMF_MIso"+prefix).c_str() ,"GenTauEtaWithDMF_MIso" ,100,-5,5);
  GenTauPhiWithDMF_MIso = fs->make<TH1F>(("GenTauPhiWithDMF_MIso"+prefix).c_str() ,"GenTauPhiWithDMF_MIso" ,100,-5,5);

  GenTauPtWithDMF_TIso = fs->make<TH1F>(("GenTauPtWithDMF_TIso"+prefix).c_str() ,"GenTauPtWithDMF_TIso" ,100,0,700);
  GenTauEtaWithDMF_TIso = fs->make<TH1F>(("GenTauEtaWithDMF_TIso"+prefix).c_str() ,"GenTauEtaWithDMF_TIso" ,100,-5,5);
  GenTauPhiWithDMF_TIso = fs->make<TH1F>(("GenTauPhiWithDMF_TIso"+prefix).c_str() ,"GenTauPhiWithDMF_TIso" ,100,-5,5);

  GenTauPtWithDMF_VLChar = fs->make<TH1F>(("GenTauPtWithDMF_VLChar"+prefix).c_str() ,"GenTauPtWithDMF_VLChar" ,100,0,700);
  GenTauEtaWithDMF_VLChar = fs->make<TH1F>(("GenTauEtaWithDMF_VLChar"+prefix).c_str() ,"GenTauEtaWithDMF_VLChar" ,100,-5,5);
  GenTauPhiWithDMF_VLChar = fs->make<TH1F>(("GenTauPhiWithDMF_VLChar"+prefix).c_str() ,"GenTauPhiWithDMF_VLChar" ,100,-5,5);

  GenTauPtWithDMF_LChar = fs->make<TH1F>(("GenTauPtWithDMF_LChar"+prefix).c_str() ,"GenTauPtWithDMF_LChar" ,100,0,700);
  GenTauEtaWithDMF_LChar = fs->make<TH1F>(("GenTauEtaWithDMF_LChar"+prefix).c_str() ,"GenTauEtaWithDMF_LChar" ,100,-5,5);
  GenTauPhiWithDMF_LChar = fs->make<TH1F>(("GenTauPhiWithDMF_LChar"+prefix).c_str() ,"GenTauPhiWithDMF_LChar" ,100,-5,5);

  GenTauPtWithDMF_MChar = fs->make<TH1F>(("GenTauPtWithDMF_MChar"+prefix).c_str() ,"GenTauPtWithDMF_MChar" ,100,0,700);
  GenTauEtaWithDMF_MChar = fs->make<TH1F>(("GenTauEtaWithDMF_MChar"+prefix).c_str() ,"GenTauEtaWithDMF_MChar" ,100,-5,5);
  GenTauPhiWithDMF_MChar = fs->make<TH1F>(("GenTauPhiWithDMF_MChar"+prefix).c_str() ,"GenTauPhiWithDMF_MChar" ,100,-5,5);

  GenTauPtWithDMF_TChar = fs->make<TH1F>(("GenTauPtWithDMF_TChar"+prefix).c_str() ,"GenTauPtWithDMF_TChar" ,100,0,700);
  GenTauEtaWithDMF_TChar = fs->make<TH1F>(("GenTauEtaWithDMF_TChar"+prefix).c_str() ,"GenTauEtaWithDMF_TChar" ,100,-5,5);
  GenTauPhiWithDMF_TChar = fs->make<TH1F>(("GenTauPhiWithDMF_TChar"+prefix).c_str() ,"GenTauPhiWithDMF_TChar" ,100,-5,5);

  
  GenTauPtWithDMF_eta1p47_0 = fs->make<TH1F>(("GenTauPtWithDMF_eta1p47_0"+prefix).c_str() ,"GenTauPtWithDMF_eta1p47_0",100,0,700);
  GenTauEtaWithDMF_eta1p47_0 = fs->make<TH1F>(("GenTauEtaWithDMF_eta1p47_0"+prefix).c_str() ,"GenTauEtaWithDMF_eta1p47_0",100,-5,5);
  GenTauPhiWithDMF_eta1p47_0 = fs->make<TH1F>(("GenTauPhiWithDMF_eta1p47_0"+prefix).c_str() ,"GenTauPhiWithDMF_eta1p47_0",100,-5,5);
  GenTauPtWithDMF_eta1p47_1 = fs->make<TH1F>(("GenTauPtWithDMF_eta1p47_1"+prefix).c_str() ,"GenTauPtWithDMF_eta1p47_1",100,0,700);
  GenTauEtaWithDMF_eta1p47_1 = fs->make<TH1F>(("GenTauEtaWithDMF_eta1p47_1"+prefix).c_str() ,"GenTauEtaWithDMF_eta1p47_1",100,-5,5);
  GenTauPhiWithDMF_eta1p47_1 = fs->make<TH1F>(("GenTauPhiWithDMF_eta1p47_1"+prefix).c_str() ,"GenTauPhiWithDMF_eta1p47_1",100,-5,5);
 
  GenTauPtWithDMF_eta1p47_2 = fs->make<TH1F>(("GenTauPtWithDMF_eta1p47_2"+prefix).c_str() ,"GenTauPtWithDMF_eta1p47_2",100,0,700);
  GenTauEtaWithDMF_eta1p47_2 = fs->make<TH1F>(("GenTauEtaWithDMF_eta1p47_2"+prefix).c_str() ,"GenTauEtaWithDMF_eta1p47_2",100,-5,5);
  GenTauPhiWithDMF_eta1p47_2 = fs->make<TH1F>(("GenTauPhiWithDMF_eta1p47_2"+prefix).c_str() ,"GenTauPhiWithDMF_eta1p47_2",100,-5,5);
      
  GenTauPtWithDMF_eta1p47_10 = fs->make<TH1F>(("GenTauPtWithDMF_eta1p47_10"+prefix).c_str() ,"GenTauPtWithDMF_eta1p47_10",100,0,700);
  GenTauEtaWithDMF_eta1p47_10 = fs->make<TH1F>(("GenTauEtaWithDMF_eta1p47_10"+prefix).c_str() ,"GenTauEtaWithDMF_eta1p47_10",100,-5,5);
  GenTauPhiWithDMF_eta1p47_10 = fs->make<TH1F>(("GenTauPhiWithDMF_eta1p47_10"+prefix).c_str() ,"GenTauPhiWithDMF_eta1p47_10",100,-5,5);
 
  GenTauPtWithDMF_eta1p47_11 = fs->make<TH1F>(("GenTauPtWithDMF_eta1p47_11"+prefix).c_str() ,"GenTauPtWithDMF_eta1p47_11",100,0,700);
  GenTauEtaWithDMF_eta1p47_11 = fs->make<TH1F>(("GenTauEtaWithDMF_eta1p47_11"+prefix).c_str() ,"GenTauEtaWithDMF_eta1p47_11",100,-5,5);
  GenTauPhiWithDMF_eta1p47_11 = fs->make<TH1F>(("GenTauPhiWithDMF_eta1p47_11"+prefix).c_str() ,"GenTauPhiWithDMF_eta1p47_11",100,-5,5);
 

  GenTauPtWithDMF_etag1p47_0 = fs->make<TH1F>(("GenTauPtWithDMF_etag1p47_0"+prefix).c_str() ,"GenTauPtWithDMF_etag1p47_0",100,0,700);
  GenTauEtaWithDMF_etag1p47_0 = fs->make<TH1F>(("GenTauEtaWithDMF_etag1p47_0"+prefix).c_str() ,"GenTauEtaWithDMF_etag1p47_0",100,-5,5);
  GenTauPhiWithDMF_etag1p47_0 = fs->make<TH1F>(("GenTauPhiWithDMF_etag1p47_0"+prefix).c_str() ,"GenTauPhiWithDMF_etag1p47_0",100,-5,5);
  GenTauPtWithDMF_etag1p47_1 = fs->make<TH1F>(("GenTauPtWithDMF_etag1p47_1"+prefix).c_str() ,"GenTauPtWithDMF_etag1p47_1",100,0,700);
  GenTauEtaWithDMF_etag1p47_1 = fs->make<TH1F>(("GenTauEtaWithDMF_etag1p47_1"+prefix).c_str() ,"GenTauEtaWithDMF_etag1p47_1",100,-5,5);
  GenTauPhiWithDMF_etag1p47_1 = fs->make<TH1F>(("GenTauPhiWithDMF_etag1p47_1"+prefix).c_str() ,"GenTauPhiWithDMF_etag1p47_1",100,-5,5);
 
  GenTauPtWithDMF_etag1p47_2 = fs->make<TH1F>(("GenTauPtWithDMF_etag1p47_2"+prefix).c_str() ,"GenTauPtWithDMF_etag1p47_2",100,0,700);
  GenTauEtaWithDMF_etag1p47_2 = fs->make<TH1F>(("GenTauEtaWithDMF_etag1p47_2"+prefix).c_str() ,"GenTauEtaWithDMF_etag1p47_2",100,-5,5);
  GenTauPhiWithDMF_etag1p47_2 = fs->make<TH1F>(("GenTauPhiWithDMF_etag1p47_2"+prefix).c_str() ,"GenTauPhiWithDMF_etag1p47_2",100,-5,5);
      
  GenTauPtWithDMF_etag1p47_10 = fs->make<TH1F>(("GenTauPtWithDMF_etag1p47_10"+prefix).c_str() ,"GenTauPtWithDMF_etag1p47_10",100,0,700);
  GenTauEtaWithDMF_etag1p47_10 = fs->make<TH1F>(("GenTauEtaWithDMF_etag1p47_10"+prefix).c_str() ,"GenTauEtaWithDMF_etag1p47_10",100,-5,5);
  GenTauPhiWithDMF_etag1p47_10 = fs->make<TH1F>(("GenTauPhiWithDMF_etag1p47_10"+prefix).c_str() ,"GenTauPhiWithDMF_etag1p47_10",100,-5,5);
 
  GenTauPtWithDMF_etag1p47_11 = fs->make<TH1F>(("GenTauPtWithDMF_etag1p47_11"+prefix).c_str() ,"GenTauPtWithDMF_etag1p47_11",100,0,700);
  GenTauEtaWithDMF_etag1p47_11 = fs->make<TH1F>(("GenTauEtaWithDMF_etag1p47_11"+prefix).c_str() ,"GenTauEtaWithDMF_etag1p47_11",100,-5,5);
  GenTauPhiWithDMF_etag1p47_11 = fs->make<TH1F>(("GenTauPhiWithDMF_etag1p47_11"+prefix).c_str() ,"GenTauPhiWithDMF_etag1p47_11",100,-5,5);
 
 GenTauPtWithDMF_0 = fs->make<TH1F>(("GenTauPtWithDMF_0"+prefix).c_str() ,"GenTauPtWithDMF_0",100,0,700);
  GenTauEtaWithDMF_0 = fs->make<TH1F>(("GenTauEtaWithDMF_0"+prefix).c_str() ,"GenTauEtaWithDMF_0",100,-5,5);
  GenTauPhiWithDMF_0 = fs->make<TH1F>(("GenTauPhiWithDMF_0"+prefix).c_str() ,"GenTauPhiWithDMF_0",100,-5,5);
  GenTauPtWithDMF_1 = fs->make<TH1F>(("GenTauPtWithDMF_1"+prefix).c_str() ,"GenTauPtWithDMF_1",100,0,700);
  GenTauEtaWithDMF_1 = fs->make<TH1F>(("GenTauEtaWithDMF_1"+prefix).c_str() ,"GenTauEtaWithDMF_1",100,-5,5);
  GenTauPhiWithDMF_1 = fs->make<TH1F>(("GenTauPhiWithDMF_1"+prefix).c_str() ,"GenTauPhiWithDMF_1",100,-5,5);
 
  GenTauPtWithDMF_2 = fs->make<TH1F>(("GenTauPtWithDMF_2"+prefix).c_str() ,"GenTauPtWithDMF_2",100,0,700);
  GenTauEtaWithDMF_2 = fs->make<TH1F>(("GenTauEtaWithDMF_2"+prefix).c_str() ,"GenTauEtaWithDMF_2",100,-5,5);
  GenTauPhiWithDMF_2 = fs->make<TH1F>(("GenTauPhiWithDMF_2"+prefix).c_str() ,"GenTauPhiWithDMF_2",100,-5,5);
      
  GenTauPtWithDMF_10 = fs->make<TH1F>(("GenTauPtWithDMF_10"+prefix).c_str() ,"GenTauPtWithDMF_10",100,0,700);
  GenTauEtaWithDMF_10 = fs->make<TH1F>(("GenTauEtaWithDMF_10"+prefix).c_str() ,"GenTauEtaWithDMF_10",100,-5,5);
  GenTauPhiWithDMF_10 = fs->make<TH1F>(("GenTauPhiWithDMF_10"+prefix).c_str() ,"GenTauPhiWithDMF_10",100,-5,5);
 
  GenTauPtWithDMF_11 = fs->make<TH1F>(("GenTauPtWithDMF_11"+prefix).c_str() ,"GenTauPtWithDMF_11",100,0,700);
  GenTauEtaWithDMF_11 = fs->make<TH1F>(("GenTauEtaWithDMF_11"+prefix).c_str() ,"GenTauEtaWithDMF_11",100,-5,5);
  GenTauPhiWithDMF_11 = fs->make<TH1F>(("GenTauPhiWithDMF_11"+prefix).c_str() ,"GenTauPhiWithDMF_11",100,-5,5);

  hNeutralIsoPtSumWeight1 = fs->make<TH1F>(("hNeutralIsoPtSumWeight1"+prefix).c_str() ,"hNeutralIsoPtSumWeight1",400,0,200); 
  hNeutralIsoPtSumWeight2 = fs->make<TH1F>(("hNeutralIsoPtSumWeight2"+prefix).c_str() ,"hNeutralIsoPtSumWeight2",400,0,200); 
  hNeutralIsoPtSumWeight1NQ = fs->make<TH1F>(("hNeutralIsoPtSumWeight1NQ"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ",400,0,200); 
  hNeutralIsoPtSumWeight2NQ = fs->make<TH1F>(("hNeutralIsoPtSumWeight2NQ"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ",400,0,200); 
 
  hNeutralHadronIsoPtSum  = fs->make<TH1F>(("hNeutralHadronIsoPtSum"+prefix).c_str() ,"hNeutralHadronIsoPtSum",400,0,200);
  hNeutralHadronIsoPtSumWeight1 = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight1"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1",400,0,200);
  hNeutralHadronIsoPtSumWeight2 = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight2"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2",400,0,200);
  hNeutralHadronIsoPtSumWeight1NQ = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight1NQ"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ",400,0,200);
  hNeutralHadronIsoPtSumWeight2NQ = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight2NQ"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ",400,0,200);
  hChargedIsoPtSum  = fs->make<TH1F>(("hChargedIsoPtSum"+prefix).c_str(),"hChargedIsoPtSum",400,0,200); 
  hNeutralIsoPtSum = fs->make<TH1F>(("hNeutralIsoPtSum"+prefix).c_str(),"hNeutralIsoPtSum",400,0,200);
  hPUcorrPtSum = fs->make<TH1F>(("hPUcorrPtSum"+prefix).c_str(),"hPUcorrPtSum",400,0,200);


  hNeutralIsoPtSumWeight1_dmf = fs->make<TH1F>(("hNeutralIsoPtSumWeight1_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_dmf",400,0,200);
 hNeutralIsoPtSumWeight2_dmf = fs->make<TH1F>(("hNeutralIsoPtSumWeight2_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_dmf",400,0,200);
 hNeutralIsoPtSumWeight1NQ_dmf = fs->make<TH1F>(("hNeutralIsoPtSumWeight1NQ_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_dmf",400,0,200);
 hNeutralIsoPtSumWeight2NQ_dmf = fs->make<TH1F>(("hNeutralIsoPtSumWeight2NQ_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_dmf",400,0,200);


  hNeutralHadronIsoPtSum_dmf  = fs->make<TH1F>(("hNeutralHadronIsoPtSum_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_dmf",400,0,200);
  hNeutralHadronIsoPtSumWeight1_dmf = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight1_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_dmf",400,0,200);
  hNeutralHadronIsoPtSumWeight2_dmf = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight2_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_dmf",400,0,200);
  hNeutralHadronIsoPtSumWeight1NQ_dmf = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight1NQ_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_dmf",400,0,200);
  hNeutralHadronIsoPtSumWeight2NQ_dmf = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight2NQ_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_dmf",400,0,200);
  hChargedIsoPtSum_dmf  = fs->make<TH1F>(("hChargedIsoPtSum_dmf"+prefix).c_str(),"hChargedIsoPtSum_dmf",400,0,200); 
  hNeutralIsoPtSum_dmf = fs->make<TH1F>(("hNeutralIsoPtSum_dmf"+prefix).c_str(),"hNeutralIsoPtSum_dmf",400,0,200);
  hPUcorrPtSum_dmf = fs->make<TH1F>(("hPUcorrPtSum_dmf"+prefix).c_str(),"hPUcorrPtSum_dmf",400,0,200);

  hNeutralIsoPtSumWeight1_pt = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_pt"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_pt",400,0,700,0,200); 
  hNeutralIsoPtSumWeight2_pt = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_pt"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_pt",400,0,700,0,200); 
  hNeutralIsoPtSumWeight1NQ_pt = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_pt"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_pt",400,0,700,0,200); 
  hNeutralIsoPtSumWeight2NQ_pt = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_pt"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_pt",400,0,700,0,200); 
  hNeutralHadronIsoPtSum_pt  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_pt"+prefix).c_str() ,"hNeutralHadronIsoPtSum_pt",400,0,700,0,200);
  hNeutralHadronIsoPtSumWeight1_pt = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_pt"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_pt",400,0,700,0,200);
  hNeutralHadronIsoPtSumWeight2_pt = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_pt"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_pt",400,0,700,0,200);
  hNeutralHadronIsoPtSumWeight1NQ_pt = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_pt"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_pt",400,0,700,0,200);
  hNeutralHadronIsoPtSumWeight2NQ_pt = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_pt"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_pt",400,0,700,0,200);
  hChargedIsoPtSum_pt  = fs->make<TProfile>(("hChargedIsoPtSum_pt"+prefix).c_str(),"hChargedIsoPtSum_pt",400,0,700,0,200); 
  hNeutralIsoPtSum_pt = fs->make<TProfile>(("hNeutralIsoPtSum_pt"+prefix).c_str(),"hNeutralIsoPtSum_pt",400,0,700,0,200);
  hPUcorrPtSum_pt = fs->make<TProfile>(("hPUcorrPtSum_pt"+prefix).c_str(),"hPUcorrPtSum_pt",400,0,700,0,200);

  hNeutralIsoPtSumWeight1_eta = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_eta"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_eta",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight2_eta = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_eta"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_eta",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight1NQ_eta = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_eta"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_eta",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight2NQ_eta = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_eta"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_eta",200,-5,5,0,200); 
  hNeutralHadronIsoPtSum_eta  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_eta"+prefix).c_str() ,"hNeutralHadronIsoPtSum_eta",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight1_eta = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_eta"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_eta",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight2_eta = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_eta"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_eta",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight1NQ_eta = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_eta"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_eta",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight2NQ_eta = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_eta"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_eta",200,-5,5,0,200);
  hChargedIsoPtSum_eta  = fs->make<TProfile>(("hChargedIsoPtSum_eta"+prefix).c_str(),"hChargedIsoPtSum_eta",200,-5,5,0,200); 
  hNeutralIsoPtSum_eta = fs->make<TProfile>(("hNeutralIsoPtSum_eta"+prefix).c_str(),"hNeutralIsoPtSum_eta",200,-5,5,0,200);
  hPUcorrPtSum_eta = fs->make<TProfile>(("hPUcorrPtSum_eta"+prefix).c_str(),"hPUcorrPtSum_eta",200,-5,5,0,200);


  hNeutralIsoPtSumWeight1_phi = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_phi"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_phi",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight2_phi = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_phi"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_phi",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight1NQ_phi = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_phi"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_phi",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight2NQ_phi = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_phi"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_phi",200,-5,5,0,200); 
  hNeutralHadronIsoPtSum_phi  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_phi"+prefix).c_str() ,"hNeutralHadronIsoPtSum_phi",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight1_phi = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_phi"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_phi",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight2_phi = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_phi"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_phi",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight1NQ_phi = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_phi"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_phi",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight2NQ_phi = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_phi"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_phi",200,-5,5,0,200);
  hChargedIsoPtSum_phi  = fs->make<TProfile>(("hChargedIsoPtSum_phi"+prefix).c_str(),"hChargedIsoPtSum_phi",200,-5,5,0,200); 
  hNeutralIsoPtSum_phi = fs->make<TProfile>(("hNeutralIsoPtSum_phi"+prefix).c_str(),"hNeutralIsoPtSum_phi",200,-5,5,0,200);
  hPUcorrPtSum_phi = fs->make<TProfile>(("hPUcorrPtSum_phi"+prefix).c_str(),"hPUcorrPtSum_phi",200,-5,5,0,200);


  hNeutralIsoPtSumWeight1_vtx = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_vtx"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_vtx",200,0,200,0,200); 
  hNeutralIsoPtSumWeight2_vtx = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_vtx"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_vtx",200,0,200,0,200); 
  hNeutralIsoPtSumWeight1NQ_vtx = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_vtx"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_vtx",200,0,200,0,200); 
  hNeutralIsoPtSumWeight2NQ_vtx = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_vtx"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_vtx",200,0,200,0,200); 
  hNeutralHadronIsoPtSum_vtx  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_vtx"+prefix).c_str() ,"hNeutralHadronIsoPtSum_vtx",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight1_vtx = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_vtx"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_vtx",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight2_vtx = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_vtx"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_vtx",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight1NQ_vtx = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_vtx"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_vtx",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight2NQ_vtx = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_vtx"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_vtx",200,0,200,0,200);
  hChargedIsoPtSum_vtx  = fs->make<TProfile>(("hChargedIsoPtSum_vtx"+prefix).c_str(),"hChargedIsoPtSum_vtx",200,0,200,0,200); 
  hNeutralIsoPtSum_vtx = fs->make<TProfile>(("hNeutralIsoPtSum_vtx"+prefix).c_str(),"hNeutralIsoPtSum_vtx",200,0,200,0,200);
  hPUcorrPtSum_vtx = fs->make<TProfile>(("hPUcorrPtSum_vtx"+prefix).c_str(),"hPUcorrPtSum_vtx",200,0,200,0,200);

  hNeutralIsoPtSumWeight1_nGoodVtx = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_nGoodVtx"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_nGoodVtx",200,0,200,0,200); 
  hNeutralIsoPtSumWeight2_nGoodVtx = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_nGoodVtx"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_nGoodVtx",200,0,200,0,200); 
  hNeutralIsoPtSumWeight1NQ_nGoodVtx = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_nGoodVtx"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_nGoodVtx",200,0,200,0,200); 
  hNeutralIsoPtSumWeight2NQ_nGoodVtx = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_nGoodVtx"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_nGoodVtx",200,0,200,0,200); 
  hNeutralHadronIsoPtSum_nGoodVtx  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_nGoodVtx"+prefix).c_str() ,"hNeutralHadronIsoPtSum_nGoodVtx",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight1_nGoodVtx = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_nGoodVtx"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_nGoodVtx",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight2_nGoodVtx = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_nGoodVtx"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_nGoodVtx",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx",200,0,200,0,200);
  hChargedIsoPtSum_nGoodVtx  = fs->make<TProfile>(("hChargedIsoPtSum_nGoodVtx"+prefix).c_str(),"hChargedIsoPtSum_nGoodVtx",200,0,200,0,200); 
  hNeutralIsoPtSum_nGoodVtx = fs->make<TProfile>(("hNeutralIsoPtSum_nGoodVtx"+prefix).c_str(),"hNeutralIsoPtSum_nGoodVtx",200,0,200,0,200);
  hPUcorrPtSum_nGoodVtx = fs->make<TProfile>(("hPUcorrPtSum_nGoodVtx"+prefix).c_str(),"hPUcorrPtSum_nGoodVtx",200,0,200,0,200);

  /// After Decay Mode Finding

  hNeutralIsoPtSumWeight1_pt_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_pt_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_pt_dmf",400,0,700,0,200); 
  hNeutralIsoPtSumWeight2_pt_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_pt_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_pt_dmf",400,0,700,0,200); 
  hNeutralIsoPtSumWeight1NQ_pt_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_pt_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_pt_dmf",400,0,700,0,200); 
  hNeutralIsoPtSumWeight2NQ_pt_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_pt_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_pt_dmf",400,0,700,0,200); 
  hNeutralHadronIsoPtSum_pt_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_pt_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_pt_dmf",400,0,700,0,200);
  hNeutralHadronIsoPtSumWeight1_pt_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_pt_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_pt_dmf",400,0,700,0,200);
  hNeutralHadronIsoPtSumWeight2_pt_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_pt_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_pt_dmf",400,0,700,0,200);
  hNeutralHadronIsoPtSumWeight1NQ_pt_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_pt_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_pt_dmf",400,0,700,0,200);
  hNeutralHadronIsoPtSumWeight2NQ_pt_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_pt_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_pt_dmf",400,0,700,0,200);
  hChargedIsoPtSum_pt_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_pt_dmf"+prefix).c_str(),"hChargedIsoPtSum_pt_dmf",400,0,700,0,200); 
  hNeutralIsoPtSum_pt_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_pt_dmf"+prefix).c_str(),"hNeutralIsoPtSum_pt_dmf",400,0,700,0,200);
  hPUcorrPtSum_pt_dmf = fs->make<TProfile>(("hPUcorrPtSum_pt_dmf"+prefix).c_str(),"hPUcorrPtSum_pt_dmf",400,0,700,0,200);

  hNeutralIsoPtSumWeight1_eta_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_eta_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_eta_dmf",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight2_eta_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_eta_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_eta_dmf",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight1NQ_eta_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_eta_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_eta_dmf",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight2NQ_eta_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_eta_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_eta_dmf",200,-5,5,0,200); 
  hNeutralHadronIsoPtSum_eta_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_eta_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_eta_dmf",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight1_eta_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_eta_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_eta_dmf",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight2_eta_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_eta_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_eta_dmf",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight1NQ_eta_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_eta_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_eta_dmf",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight2NQ_eta_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_eta_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_eta_dmf",200,-5,5,0,200);
  hChargedIsoPtSum_eta_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_eta_dmf"+prefix).c_str(),"hChargedIsoPtSum_eta_dmf",200,-5,5,0,200); 
  hNeutralIsoPtSum_eta_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_eta_dmf"+prefix).c_str(),"hNeutralIsoPtSum_eta_dmf",200,-5,5,0,200);
  hPUcorrPtSum_eta_dmf = fs->make<TProfile>(("hPUcorrPtSum_eta_dmf"+prefix).c_str(),"hPUcorrPtSum_eta_dmf",200,-5,5,0,200);


  hNeutralIsoPtSumWeight1_phi_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_phi_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_phi_dmf",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight2_phi_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_phi_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_phi_dmf",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight1NQ_phi_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_phi_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_phi_dmf",200,-5,5,0,200); 
  hNeutralIsoPtSumWeight2NQ_phi_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_phi_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_phi_dmf",200,-5,5,0,200); 
  hNeutralHadronIsoPtSum_phi_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_phi_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_phi_dmf",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight1_phi_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_phi_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_phi_dmf",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight2_phi_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_phi_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_phi_dmf",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight1NQ_phi_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_phi_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_phi_dmf",200,-5,5,0,200);
  hNeutralHadronIsoPtSumWeight2NQ_phi_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_phi_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_phi_dmf",200,-5,5,0,200);
  hChargedIsoPtSum_phi_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_phi_dmf"+prefix).c_str(),"hChargedIsoPtSum_phi_dmf",200,-5,5,0,200); 
  hNeutralIsoPtSum_phi_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_phi_dmf"+prefix).c_str(),"hNeutralIsoPtSum_phi_dmf",200,-5,5,0,200);
  hPUcorrPtSum_phi_dmf = fs->make<TProfile>(("hPUcorrPtSum_phi_dmf"+prefix).c_str(),"hPUcorrPtSum_phi_dmf",200,-5,5,0,200);


  hNeutralIsoPtSumWeight1_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_vtx_dmf",200,0,200,0,200); 
  hNeutralIsoPtSumWeight2_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_vtx_dmf",200,0,200,0,200); 
  hNeutralIsoPtSumWeight1NQ_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_vtx_dmf",200,0,200,0,200); 
  hNeutralIsoPtSumWeight2NQ_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_vtx_dmf",200,0,200,0,200); 
  hNeutralHadronIsoPtSum_vtx_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_vtx_dmf",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight1_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_vtx_dmf",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight2_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_vtx_dmf",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf",200,0,200,0,200);
  hChargedIsoPtSum_vtx_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_vtx_dmf"+prefix).c_str(),"hChargedIsoPtSum_vtx_dmf",200,0,200,0,200); 
  hNeutralIsoPtSum_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_vtx_dmf"+prefix).c_str(),"hNeutralIsoPtSum_vtx_dmf",200,0,200,0,200);
  hPUcorrPtSum_vtx_dmf = fs->make<TProfile>(("hPUcorrPtSum_vtx_dmf"+prefix).c_str(),"hPUcorrPtSum_vtx_dmf",200,0,200,0,200);

  hNeutralIsoPtSumWeight1_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_nGoodVtx_dmf",200,0,200,0,200); 
  hNeutralIsoPtSumWeight2_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_nGoodVtx_dmf",200,0,200,0,200); 
  hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf",200,0,200,0,200); 
  hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf",200,0,200,0,200); 
  hNeutralHadronIsoPtSum_nGoodVtx_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_nGoodVtx_dmf",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf",200,0,200,0,200);
  hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf",200,0,200,0,200);
  hChargedIsoPtSum_nGoodVtx_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_nGoodVtx_dmf"+prefix).c_str(),"hChargedIsoPtSum_nGoodVtx_dmf",200,0,200,0,200); 
  hNeutralIsoPtSum_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_nGoodVtx_dmf"+prefix).c_str(),"hNeutralIsoPtSum_nGoodVtx_dmf",200,0,200,0,200);
  hPUcorrPtSum_nGoodVtx_dmf = fs->make<TProfile>(("hPUcorrPtSum_nGoodVtx_dmf"+prefix).c_str(),"hPUcorrPtSum_nGoodVtx_dmf",200,0,200,0,200);

  TauPtResponse_LooseRho = fs->make<TH1F>(("TauPtResponse_LooseRho"+prefix).c_str() ,"TauPtResponse_LooseRho",100,0.1,2.0);
 RecoTauDecayMode_LooseRho = fs->make<TH1F>(("RecoTauDecayMode_LooseRho"+prefix).c_str() ,"RecoTauDecayMode_LooseRho",15,0,15);
 GenTauDecayMode_LooseRho = fs->make<TH1F>(("GenTauDecayMode_LooseRho"+prefix).c_str() ,"GenTauDecayMode_LooseRho",15,0,15);
 reco_dm_vs_gen_LooseRho = fs->make<TH2F>(("reco_dm_vs_gen_LooseRho"+prefix).c_str() ,"reco_dm_vs_gen_LooseRho",15,0,15,15,0,15);

GenTauPtWithDMF_LooseRho = fs->make<TH1F>(("GenTauPtWithDMF_LooseRho"+prefix).c_str(), "GenTauPtWithDMF_LooseRho",100,0,700);
GenTauEtaWithDMF_LooseRho = fs->make<TH1F>(("GenTauEtaWithDMF_LooseRho"+prefix).c_str() ,"GenTauEtaWithDMF_LooseRho",100,-5,5);
GenTauPhiWithDMF_LooseRho = fs->make<TH1F>(("GenTauPhiWithDMF_LooseRho"+prefix).c_str() ,"GenTauPhiWithDMF_LooseRho",100,-5,5);
 
  TauPtResponse_MediumRho = fs->make<TH1F>(("TauPtResponse_MediumRho"+prefix).c_str() ,"TauPtResponse_MediumRho",100,0.1,2.0);
 RecoTauDecayMode_MediumRho = fs->make<TH1F>(("RecoTauDecayMode_MediumRho"+prefix).c_str() ,"RecoTauDecayMode_MediumRho",15,0,15);
 GenTauDecayMode_MediumRho = fs->make<TH1F>(("GenTauDecayMode_MediumRho"+prefix).c_str() ,"GenTauDecayMode_MediumRho",15,0,15);
reco_dm_vs_gen_MediumRho = fs->make<TH2F>(("reco_dm_vs_gen_MediumRho"+prefix).c_str() ,"reco_dm_vs_gen_MediumRho",15,0,15,15,0,15);
 GenTauPtWithDMF_MediumRho = fs->make<TH1F>(("GenTauPtWithDMF_MediumRho"+prefix).c_str(), "GenTauPtWithDMF_MediumRho",100,0,700);
 GenTauEtaWithDMF_MediumRho = fs->make<TH1F>(("GenTauEtaWithDMF_MediumRho"+prefix).c_str() ,"GenTauEtaWithDMF_MediumRho",100,-5,5);
 GenTauPhiWithDMF_MediumRho = fs->make<TH1F>(("GenTauPhiWithDMF_MediumRho"+prefix).c_str() ,"GenTauPhiWithDMF_MediumRho",100,-5,5);
  
  TauPtResponse_TightRho = fs->make<TH1F>(("TauPtResponse_TightRho"+prefix).c_str() ,"TauPtResponse_TightRho",100,0.1,2.0);
RecoTauDecayMode_TightRho = fs->make<TH1F>(("RecoTauDecayMode_TightRho"+prefix).c_str() ,"RecoTauDecayMode_TightRho",15,0,15);
 GenTauDecayMode_TightRho = fs->make<TH1F>(("GenTauDecayMode_TightRho"+prefix).c_str() ,"GenTauDecayMode_TightRho",15,0,15);
 reco_dm_vs_gen_TightRho = fs->make<TH2F>(("reco_dm_vs_gen_TightRho"+prefix).c_str() ,"reco_dm_vs_gen_TightRho",15,0,15,15,0,15);
 
GenTauPtWithDMF_TightRho = fs->make<TH1F>(("GenTauPtWithDMF_TightRho"+prefix).c_str(), "GenTauPtWithDMF_TightRho",100,0,700);
GenTauEtaWithDMF_TightRho = fs->make<TH1F>(("GenTauEtaWithDMF_TightRho"+prefix).c_str() ,"GenTauEtaWithDMF_TightRho",100,-5,5);
GenTauPhiWithDMF_TightRho = fs->make<TH1F>(("GenTauPhiWithDMF_TightRho"+prefix).c_str() ,"GenTauPhiWithDMF_TightRho",100,-5,5);
  





		  
}


TauIDChecksG2p3::~TauIDChecksG2p3()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void TauIDChecksG2p3::Fill(const edm::Event& iEvent) {
   using namespace edm;
   using namespace std;
   using namespace reco;
   using namespace pat;

  iEvent.getByLabel("genParticles", _genParticles); 
   
  
  Handle< reco::TrackCollection > track;
  iEvent.getByLabel("generalTracks", track);

  Handle< reco::GenJetCollection > genTauJets;
  iEvent.getByLabel("tauGenJets",genTauJets);


  edm::Handle<std::vector< PileupSummaryInfo > >  PupInfo;
  iEvent.getByLabel(std::string("addPileupInfo"), PupInfo);

    edm::Handle<reco::MuonCollection> rmuons;
    iEvent.getByLabel("muons",rmuons);

    edm::Handle<reco::VertexCollection> vtx;
   iEvent.getByLabel("offlinePrimaryVertices",vtx);
  
 
//  vector<pat::Muon>                    "patMuons"                  ""           "PATTuple"  
 std::vector<PileupSummaryInfo>::const_iterator PVI;
     int ootnpuVertices =0;
     int npuVertices    =0;
     for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
      if(PVI->getBunchCrossing()== 0)  {
       npuVertices += PVI->getPU_NumInteractions();
     }
     else{   ootnpuVertices += PVI->getPU_NumInteractions();
    }
  }//loop over pileup infor
  npuVertices_->Fill(npuVertices);
  ootnpuVertices_->Fill(ootnpuVertices);

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
  iEvent.getByLabel("hpsPFTauDiscriminationByMediumElectronRejection2",_enew);

   bool isZtautau=false;
   isZtautau = IsZTauTau (_genParticles) ;
   
   int  nGoodVtx = 0;
   for( reco::VertexCollection::const_iterator vtxIt = vtx->begin(); vtxIt != vtx->end(); ++vtxIt){
     
     if((vtxIt->isValid()) && !(vtxIt->isFake())) {
       
       nGoodVtx++;
     }
   }
   

   //isZtautau=true;
   
   if(isZtautau) {
     
     for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
       reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);
      
       
       bool TauEtaCuts1 = false;
       bool TauEtaCuts2 = false; 
       bool RecoptCut = false;
       bool DecayModeFinding = false;
       
       
       if(abs(tauCandidate->eta()) > 2.3) TauEtaCuts1 = true;
       if(abs(tauCandidate->eta()) < 3.0)  TauEtaCuts2 = true;
       
       if((tauCandidate->pt()) > 20) RecoptCut = true;
       
       if((*_dmf)[tauCandidate] > 0.5) DecayModeFinding = true; 
       
       if( (RecoptCut && TauEtaCuts1 && TauEtaCuts2 ) ) { 

	 int igentau = 0;
	 int index  = -1;
	 if(OverlapWithGenTau( tauCandidate->eta() , tauCandidate->phi() , genTauJets , index ) && index != -1 ){
	   for(reco::GenJetCollection::const_iterator gentaujet = genTauJets->begin(); gentaujet !=  genTauJets->end(); ++gentaujet) {
	     if(igentau == index) {
	       tauGenJetDecayModeInt = -999;
	       
	       //just to cross confirm	       
	       if(reco::deltaR(gentaujet->eta(), gentaujet->phi(), tauCandidate->eta(), tauCandidate->phi()) < _TauToGenMatchingDeltaR) {
		 //cout<<"enter deltaR matching"<<endl; 
		 GenTauPtWithoutDMF->Fill(gentaujet->pt());
		 GenTauEtaWithoutDMF->Fill(gentaujet->eta());
		 GenTauPhiWithoutDMF->Fill(gentaujet->phi());
		
      //////////////////////////////////////// isolation discriminators
   
   hNeutralIsoPtSumWeight1->Fill((*_nw1)[tauCandidate] );
   hNeutralIsoPtSumWeight2->Fill((*_nw2)[tauCandidate] );
   hNeutralIsoPtSumWeight1NQ->Fill((*_nw1nq)[tauCandidate] ); 
   hNeutralIsoPtSumWeight2NQ->Fill((*_nw2nq)[tauCandidate] );
   hNeutralHadronIsoPtSum->Fill((*_h1)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1->Fill((*_hw1)[tauCandidate] ); 
   hNeutralHadronIsoPtSumWeight2->Fill((*_hw2)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1NQ->Fill((*_hw1nq)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight2NQ->Fill((*_hw2nq)[tauCandidate] );
   hChargedIsoPtSum->Fill((*_rawc)[tauCandidate] );
   hNeutralIsoPtSum->Fill((*_rawn)[tauCandidate] );
   hPUcorrPtSum->Fill((*_rawpu)[tauCandidate] );

   hNeutralIsoPtSumWeight1_pt->Fill(gentaujet->pt(),(*_nw1)[tauCandidate] );
   hNeutralIsoPtSumWeight2_pt->Fill(gentaujet->pt(),(*_nw2)[tauCandidate] );
   hNeutralIsoPtSumWeight1NQ_pt->Fill(gentaujet->pt(),(*_nw1nq)[tauCandidate] );
   hNeutralIsoPtSumWeight2NQ_pt->Fill(gentaujet->pt(),(*_nw2nq)[tauCandidate] );
   hNeutralHadronIsoPtSum_pt->Fill(gentaujet->pt(),(*_h1)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1_pt->Fill(gentaujet->pt(),(*_hw1)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight2_pt->Fill(gentaujet->pt(),(*_hw2)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1NQ_pt->Fill(gentaujet->pt(),(*_hw1nq)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight2NQ_pt->Fill(gentaujet->pt(),(*_hw2nq)[tauCandidate] );
   hChargedIsoPtSum_pt->Fill(gentaujet->pt(),(*_rawc)[tauCandidate] );
   hNeutralIsoPtSum_pt->Fill(gentaujet->pt(),(*_rawn)[tauCandidate] );
   hPUcorrPtSum_pt->Fill(gentaujet->pt(),(*_rawpu)[tauCandidate] );


   hNeutralIsoPtSumWeight1_eta->Fill(gentaujet->eta(),(*_nw1)[tauCandidate] );
   hNeutralIsoPtSumWeight2_eta->Fill(gentaujet->eta(),(*_nw2)[tauCandidate] );
   hNeutralIsoPtSumWeight1NQ_eta->Fill(gentaujet->eta(),(*_nw1nq)[tauCandidate] );
   hNeutralIsoPtSumWeight2NQ_eta->Fill(gentaujet->eta(),(*_nw2nq)[tauCandidate] );
   hNeutralHadronIsoPtSum_eta->Fill(gentaujet->eta(),(*_h1)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1_eta->Fill(gentaujet->eta(),(*_hw1)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight2_eta->Fill(gentaujet->eta(),(*_hw2)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1NQ_eta->Fill(gentaujet->eta(),(*_hw1nq)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight2NQ_eta->Fill(gentaujet->eta(),(*_hw2nq)[tauCandidate] );
   hChargedIsoPtSum_eta->Fill(gentaujet->eta(),(*_rawc)[tauCandidate] );
   hNeutralIsoPtSum_eta->Fill(gentaujet->eta(),(*_rawn)[tauCandidate] );
   hPUcorrPtSum_eta->Fill(gentaujet->eta(),(*_rawpu)[tauCandidate] );



   hNeutralIsoPtSumWeight1_phi->Fill(gentaujet->phi(),(*_nw1)[tauCandidate] );
   hNeutralIsoPtSumWeight2_phi->Fill(gentaujet->phi(),(*_nw2)[tauCandidate] );
   hNeutralIsoPtSumWeight1NQ_phi->Fill(gentaujet->phi(),(*_nw1nq)[tauCandidate] );
   hNeutralIsoPtSumWeight2NQ_phi->Fill(gentaujet->phi(),(*_nw2nq)[tauCandidate] );
   hNeutralHadronIsoPtSum_phi->Fill(gentaujet->phi(),(*_h1)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1_phi->Fill(gentaujet->phi(),(*_hw1)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight2_phi->Fill(gentaujet->phi(),(*_hw2)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1NQ_phi->Fill(gentaujet->phi(),(*_hw1nq)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight2NQ_phi->Fill(gentaujet->phi(),(*_hw2nq)[tauCandidate] );
   hChargedIsoPtSum_phi->Fill(gentaujet->phi(),(*_rawc)[tauCandidate] );
   hNeutralIsoPtSum_phi->Fill(gentaujet->phi(),(*_rawn)[tauCandidate] );
   hPUcorrPtSum_phi->Fill(gentaujet->phi(),(*_rawpu)[tauCandidate] );



   hNeutralIsoPtSumWeight1_vtx->Fill(vtx->size(),(*_nw1)[tauCandidate] );
   hNeutralIsoPtSumWeight2_vtx->Fill(vtx->size(),(*_nw2)[tauCandidate] );
   hNeutralIsoPtSumWeight1NQ_vtx->Fill(vtx->size(),(*_nw1nq)[tauCandidate] );
   hNeutralIsoPtSumWeight2NQ_vtx->Fill(vtx->size(),(*_nw2nq)[tauCandidate] );
   hNeutralHadronIsoPtSum_vtx->Fill(vtx->size(),(*_h1)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1_vtx->Fill(vtx->size(),(*_hw1)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight2_vtx->Fill(vtx->size(),(*_hw2)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1NQ_vtx->Fill(vtx->size(),(*_hw1nq)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight2NQ_vtx->Fill(vtx->size(),(*_hw2nq)[tauCandidate] );
   hChargedIsoPtSum_vtx->Fill(vtx->size(),(*_rawc)[tauCandidate] );
   hNeutralIsoPtSum_vtx->Fill(vtx->size(),(*_rawn)[tauCandidate] );
   hPUcorrPtSum_vtx->Fill(vtx->size(),(*_rawpu)[tauCandidate] );

   hNeutralIsoPtSumWeight1_nGoodVtx->Fill(nGoodVtx,(*_nw1)[tauCandidate] );
   hNeutralIsoPtSumWeight2_nGoodVtx->Fill(nGoodVtx,(*_nw2)[tauCandidate] );
   hNeutralIsoPtSumWeight1NQ_nGoodVtx->Fill(nGoodVtx,(*_nw1nq)[tauCandidate] );
   hNeutralIsoPtSumWeight2NQ_nGoodVtx->Fill(nGoodVtx,(*_nw2nq)[tauCandidate] );
   hNeutralHadronIsoPtSum_nGoodVtx->Fill(nGoodVtx,(*_h1)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1_nGoodVtx->Fill(nGoodVtx,(*_hw1)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight2_nGoodVtx->Fill(nGoodVtx,(*_hw2)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx->Fill(nGoodVtx,(*_hw1nq)[tauCandidate] );
   hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx->Fill(nGoodVtx,(*_hw2nq)[tauCandidate] );
   hChargedIsoPtSum_nGoodVtx->Fill(nGoodVtx,(*_rawc)[tauCandidate] );
   hNeutralIsoPtSum_nGoodVtx->Fill(nGoodVtx,(*_rawn)[tauCandidate] );
   hPUcorrPtSum_nGoodVtx->Fill(nGoodVtx,(*_rawpu)[tauCandidate] );


  
      if(DecayModeFinding) {
	
	std::string tauGenJetDecayMode = JetMCTagUtils::genTauDecayMode(*gentaujet);
	
	
	if(tauGenJetDecayMode=="muon") continue;
	if(tauGenJetDecayMode=="electron") continue;
	
	if(gentaujet->pt() != 0) {
	  TauPtResponse_DM->Fill(tauCandidate->pt()/gentaujet->pt());
	}
	
	

	
	hNeutralIsoPtSumWeight1_dmf->Fill((*_nw1)[tauCandidate] );

	hNeutralIsoPtSumWeight2_dmf->Fill((*_nw2)[tauCandidate] );


	hNeutralIsoPtSumWeight1NQ_dmf->Fill((*_nw1nq)[tauCandidate] ); 



	hNeutralIsoPtSumWeight2NQ_dmf->Fill((*_nw2nq)[tauCandidate] );


	hNeutralHadronIsoPtSum_dmf->Fill((*_h1)[tauCandidate] );
 

	hNeutralHadronIsoPtSumWeight1_dmf->Fill((*_hw1)[tauCandidate] ); 


	hNeutralHadronIsoPtSumWeight2_dmf->Fill((*_hw2)[tauCandidate] );


	hNeutralHadronIsoPtSumWeight1NQ_dmf->Fill((*_hw1nq)[tauCandidate] );


	hNeutralHadronIsoPtSumWeight2NQ_dmf->Fill((*_hw2nq)[tauCandidate] );


	hChargedIsoPtSum_dmf->Fill((*_rawc)[tauCandidate] );


	hNeutralIsoPtSum_dmf->Fill((*_rawn)[tauCandidate] );


	hPUcorrPtSum_dmf->Fill((*_rawpu)[tauCandidate] );


	
	hNeutralIsoPtSumWeight1_pt_dmf->Fill(gentaujet->pt(),(*_nw1)[tauCandidate] );
	hNeutralIsoPtSumWeight2_pt_dmf->Fill(gentaujet->pt(),(*_nw2)[tauCandidate] );
	hNeutralIsoPtSumWeight1NQ_pt_dmf->Fill(gentaujet->pt(),(*_nw1nq)[tauCandidate] );
	hNeutralIsoPtSumWeight2NQ_pt_dmf->Fill(gentaujet->pt(),(*_nw2nq)[tauCandidate] );
	hNeutralHadronIsoPtSum_pt_dmf->Fill(gentaujet->pt(),(*_h1)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight1_pt_dmf->Fill(gentaujet->pt(),(*_hw1)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight2_pt_dmf->Fill(gentaujet->pt(),(*_hw2)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight1NQ_pt_dmf->Fill(gentaujet->pt(),(*_hw1nq)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight2NQ_pt_dmf->Fill(gentaujet->pt(),(*_hw2nq)[tauCandidate] );
	hChargedIsoPtSum_pt_dmf->Fill(gentaujet->pt(),(*_rawc)[tauCandidate] );
	hNeutralIsoPtSum_pt_dmf->Fill(gentaujet->pt(),(*_rawn)[tauCandidate] );
	hPUcorrPtSum_pt_dmf->Fill(gentaujet->pt(),(*_rawpu)[tauCandidate] );
	


	hNeutralIsoPtSumWeight1_eta_dmf->Fill(gentaujet->eta(),(*_nw1)[tauCandidate] );
	hNeutralIsoPtSumWeight2_eta_dmf->Fill(gentaujet->eta(),(*_nw2)[tauCandidate] );
	hNeutralIsoPtSumWeight1NQ_eta_dmf->Fill(gentaujet->eta(),(*_nw1nq)[tauCandidate] );
	hNeutralIsoPtSumWeight2NQ_eta_dmf->Fill(gentaujet->eta(),(*_nw2nq)[tauCandidate] );
	hNeutralHadronIsoPtSum_eta_dmf->Fill(gentaujet->eta(),(*_h1)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight1_eta_dmf->Fill(gentaujet->eta(),(*_hw1)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight2_eta_dmf->Fill(gentaujet->eta(),(*_hw2)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight1NQ_eta_dmf->Fill(gentaujet->eta(),(*_hw1nq)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight2NQ_eta_dmf->Fill(gentaujet->eta(),(*_hw2nq)[tauCandidate] );
	hChargedIsoPtSum_eta_dmf->Fill(gentaujet->eta(),(*_rawc)[tauCandidate] );
	hNeutralIsoPtSum_eta_dmf->Fill(gentaujet->eta(),(*_rawn)[tauCandidate] );
	hPUcorrPtSum_eta_dmf->Fill(gentaujet->eta(),(*_rawpu)[tauCandidate] );
	



	hNeutralIsoPtSumWeight1_phi_dmf->Fill(gentaujet->phi(),(*_nw1)[tauCandidate] );
	hNeutralIsoPtSumWeight2_phi_dmf->Fill(gentaujet->phi(),(*_nw2)[tauCandidate] );
	hNeutralIsoPtSumWeight1NQ_phi_dmf->Fill(gentaujet->phi(),(*_nw1nq)[tauCandidate] );
	hNeutralIsoPtSumWeight2NQ_phi_dmf->Fill(gentaujet->phi(),(*_nw2nq)[tauCandidate] );
	hNeutralHadronIsoPtSum_phi_dmf->Fill(gentaujet->phi(),(*_h1)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight1_phi_dmf->Fill(gentaujet->phi(),(*_hw1)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight2_phi_dmf->Fill(gentaujet->phi(),(*_hw2)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight1NQ_phi_dmf->Fill(gentaujet->phi(),(*_hw1nq)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight2NQ_phi_dmf->Fill(gentaujet->phi(),(*_hw2nq)[tauCandidate] );
	hChargedIsoPtSum_phi_dmf->Fill(gentaujet->phi(),(*_rawc)[tauCandidate] );
	hNeutralIsoPtSum_phi_dmf->Fill(gentaujet->phi(),(*_rawn)[tauCandidate] );
	hPUcorrPtSum_phi_dmf->Fill(gentaujet->phi(),(*_rawpu)[tauCandidate] );
	
	



	hNeutralIsoPtSumWeight1_vtx_dmf->Fill(vtx->size(),(*_nw1)[tauCandidate] );
	hNeutralIsoPtSumWeight2_vtx_dmf->Fill(vtx->size(),(*_nw2)[tauCandidate] );
	hNeutralIsoPtSumWeight1NQ_vtx_dmf->Fill(vtx->size(),(*_nw1nq)[tauCandidate] );
	hNeutralIsoPtSumWeight2NQ_vtx_dmf->Fill(vtx->size(),(*_nw2nq)[tauCandidate] );
	hNeutralHadronIsoPtSum_vtx_dmf->Fill(vtx->size(),(*_h1)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight1_vtx_dmf->Fill(vtx->size(),(*_hw1)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight2_vtx_dmf->Fill(vtx->size(),(*_hw2)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf->Fill(vtx->size(),(*_hw1nq)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf->Fill(vtx->size(),(*_hw2nq)[tauCandidate] );
	hChargedIsoPtSum_vtx_dmf->Fill(vtx->size(),(*_rawc)[tauCandidate] );
	hNeutralIsoPtSum_vtx_dmf->Fill(vtx->size(),(*_rawn)[tauCandidate] );
	hPUcorrPtSum_vtx_dmf->Fill(vtx->size(),(*_rawpu)[tauCandidate] );



	hNeutralIsoPtSumWeight1_nGoodVtx_dmf->Fill(nGoodVtx,(*_nw1)[tauCandidate] );
	hNeutralIsoPtSumWeight2_nGoodVtx_dmf->Fill(nGoodVtx,(*_nw2)[tauCandidate] );
	hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf->Fill(nGoodVtx,(*_nw1nq)[tauCandidate] );
	hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf->Fill(nGoodVtx,(*_nw2nq)[tauCandidate] );
	hNeutralHadronIsoPtSum_nGoodVtx_dmf->Fill(nGoodVtx,(*_h1)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf->Fill(nGoodVtx,(*_hw1)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf->Fill(nGoodVtx,(*_hw2)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf->Fill(nGoodVtx,(*_hw1nq)[tauCandidate] );
	hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf->Fill(nGoodVtx,(*_hw2nq)[tauCandidate] );
	hChargedIsoPtSum_nGoodVtx_dmf->Fill(nGoodVtx,(*_rawc)[tauCandidate] );
	hNeutralIsoPtSum_nGoodVtx_dmf->Fill(nGoodVtx,(*_rawn)[tauCandidate] );
	hPUcorrPtSum_nGoodVtx_dmf->Fill(nGoodVtx,(*_rawpu)[tauCandidate] );
	

	
	//   cout<<" pat Decay Mode ::  "<<tauCandidate->decayMode()<<endl;
	
	//    cout<<"tauGenJetDecayMode::"<<tauGenJetDecayMode<<endl;
	

                   if(tauGenJetDecayMode=="oneProng0Pi0") {
                     tauGenJetDecayModeInt=0;
                     GenTauPtWithDMF_0->Fill(gentaujet->pt());
                     GenTauEtaWithDMF_0->Fill(gentaujet->eta());
                     GenTauPhiWithDMF_0->Fill(gentaujet->phi());

                     if( (*_hpsTau1)[tauCandidate] > 0.5 ) {
                       if(gentaujet->pt() != 0) {
                         TauPtResponse_DM_LooseIso_1Prong->Fill(tauCandidate->pt()/gentaujet->pt());
                       }

                     }
                   }

                   if(tauGenJetDecayMode=="oneProng1Pi0") {
                     tauGenJetDecayModeInt=1;
                     GenTauPtWithDMF_1->Fill(gentaujet->pt());
                     GenTauEtaWithDMF_1->Fill(gentaujet->eta());
                     GenTauPhiWithDMF_1->Fill(gentaujet->phi());

                     if( (*_hpsTau1)[tauCandidate] > 0.5 ) {
                       if(gentaujet->pt() != 0) {
                         TauPtResponse_DM_LooseIso_1Prong1Pi0->Fill(tauCandidate->pt()/gentaujet->pt());
                       }
                     }
                   }
                 if(tauGenJetDecayMode=="oneProng2Pi0") {
                     tauGenJetDecayModeInt=2;
                     GenTauPtWithDMF_2->Fill(gentaujet->pt());
                     GenTauEtaWithDMF_2->Fill(gentaujet->eta());
                     GenTauPhiWithDMF_2->Fill(gentaujet->phi());

                     if( (*_hpsTau1)[tauCandidate] > 0.5 ) {
                       if(gentaujet->pt() != 0) {

                         TauPtResponse_DM_LooseIso_1Prong2Pi0->Fill(tauCandidate->pt()/gentaujet->pt());
                       }
                     }
                   }



                 if(tauGenJetDecayMode=="threeProng0Pi0") {
                     tauGenJetDecayModeInt=10;
                     GenTauPtWithDMF_10->Fill(gentaujet->pt());
                     GenTauEtaWithDMF_10->Fill(gentaujet->eta());
                     GenTauPhiWithDMF_10->Fill(gentaujet->phi());

                     if( (*_hpsTau1)[tauCandidate] > 0.5 ) {
                       if(gentaujet->pt() != 0) {
                         TauPtResponse_DM_LooseIso_3Prong->Fill(tauCandidate->pt()/gentaujet->pt());
                       }
                     }

                   }
         if(tauGenJetDecayMode=="threeProng1Pi0") {
                     tauGenJetDecayModeInt=11;
                     GenTauPtWithDMF_11->Fill(gentaujet->pt());
                     GenTauEtaWithDMF_11->Fill(gentaujet->eta());
                     GenTauPhiWithDMF_11->Fill(gentaujet->phi());

                     if( (*_hpsTau1)[tauCandidate] > 0.5 ) {

                       if(gentaujet->pt() != 0) {
                         TauPtResponse_DM_LooseIso_3Prong1Pi0->Fill(tauCandidate->pt()/gentaujet->pt());
                       }
                     }
                   }



	
	RecoTauDecayMode_DM->Fill(tauCandidate->decayMode());
	GenTauDecayMode_DM->Fill(tauGenJetDecayModeInt);
	
	reco_dm_vs_gen_dm->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	
	GenTauPtWithDMF->Fill(gentaujet->pt());	  
	GenTauEtaWithDMF->Fill(gentaujet->eta());
	GenTauPhiWithDMF->Fill(gentaujet->phi());
	
	
	/////////////////////////////////////////////////////////////////////////////////
	
	
	////////// DMF v/s Eta Phi /////////////////////////
	
	
        
	if((*_mv1)[tauCandidate] > 0.5) {
	  
	  if(gentaujet->pt() != 0) {
	    TauPtResponse_ML2->Fill(tauCandidate->pt()/gentaujet->pt());
	  }
	  
	  RecoTauDecayMode_ML2->Fill(tauCandidate->decayMode());
	  GenTauDecayMode_ML2->Fill(tauGenJetDecayModeInt);
	  reco_dm_vs_gen_ML2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	  
	  GenTauPtWithDMF_ML2->Fill(gentaujet->pt());	  
	  GenTauEtaWithDMF_ML2->Fill(gentaujet->eta());
	  GenTauPhiWithDMF_ML2->Fill(gentaujet->phi());
	}
	
	
	
	if((*_mv2)[tauCandidate] > 0.5) {
	  
	  if(gentaujet->pt() != 0) {
	    TauPtResponse_MM2->Fill(tauCandidate->pt()/gentaujet->pt());
	  }
	  
	  RecoTauDecayMode_MM2->Fill(tauCandidate->decayMode());
	  GenTauDecayMode_MM2->Fill(tauGenJetDecayModeInt);
	  
	  reco_dm_vs_gen_MM2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	  
	  GenTauPtWithDMF_MM2->Fill(gentaujet->pt());	  
	  GenTauEtaWithDMF_MM2->Fill(gentaujet->eta());
	  GenTauPhiWithDMF_MM2->Fill(gentaujet->phi());
	}
	
	
	if((*_mv3)[tauCandidate] > 0.5) {
	  if(gentaujet->pt() != 0) {
	    TauPtResponse_MT2->Fill(tauCandidate->pt()/gentaujet->pt());
	  }
	  
	  RecoTauDecayMode_MT2->Fill(tauCandidate->decayMode());
	  GenTauDecayMode_MT2->Fill(tauGenJetDecayModeInt);
	  reco_dm_vs_gen_MT2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	  GenTauPtWithDMF_MT2->Fill(gentaujet->pt());	  
	  GenTauEtaWithDMF_MT2->Fill(gentaujet->eta());
	  GenTauPhiWithDMF_MT2->Fill(gentaujet->phi());
	}
	
	
	if((*_mv31)[tauCandidate] > 0.5) {
	  
	  if(gentaujet->pt() != 0) {
	    TauPtResponse_ML3->Fill(tauCandidate->pt()/gentaujet->pt());
	  }
	  
	  RecoTauDecayMode_ML3->Fill(tauCandidate->decayMode());
	  GenTauDecayMode_ML3->Fill(tauGenJetDecayModeInt);
	  reco_dm_vs_gen_ML3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	  
	  GenTauPtWithDMF_ML3->Fill(gentaujet->pt());	  
	  GenTauEtaWithDMF_ML3->Fill(gentaujet->eta());
	  GenTauPhiWithDMF_ML3->Fill(gentaujet->phi());
	}
	
	
	if((*_mv32)[tauCandidate] > 0.5) {
	  
	  if(gentaujet->pt() != 0) {
	    TauPtResponse_MT3->Fill(tauCandidate->pt()/gentaujet->pt());
	  }
	  
	  RecoTauDecayMode_MT3->Fill(tauCandidate->decayMode());
	  GenTauDecayMode_MT3->Fill(tauGenJetDecayModeInt);
	  reco_dm_vs_gen_MT3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	  
	  GenTauPtWithDMF_MT3->Fill(gentaujet->pt());	  
	  GenTauEtaWithDMF_MT3->Fill(gentaujet->eta());
	  GenTauPhiWithDMF_MT3->Fill(gentaujet->phi());
	}
	
	

          if((*_enew)[tauCandidate] > 0.5) {

          if(gentaujet->pt() != 0) {
       TauPtResponse_Cut->Fill(tauCandidate->pt()/gentaujet->pt());
     }

     RecoTauDecayMode_Cut->Fill(tauCandidate->decayMode());
     GenTauDecayMode_Cut->Fill(tauGenJetDecayModeInt);
     reco_dm_vs_gen_Cut->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

     GenTauPtWithDMF_Cut->Fill(gentaujet->pt());
     GenTauEtaWithDMF_Cut->Fill(gentaujet->eta());
     GenTauPhiWithDMF_Cut->Fill(gentaujet->phi());
   }



	if((*_ev1)[tauCandidate] > 0.5) {
	  
	  if(gentaujet->pt() != 0) {
	    TauPtResponse_EL3->Fill(tauCandidate->pt()/gentaujet->pt());
	  }
	  
	  RecoTauDecayMode_EL3->Fill(tauCandidate->decayMode());
	  GenTauDecayMode_EL3->Fill(tauGenJetDecayModeInt);
	  reco_dm_vs_gen_EL3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	  
	  GenTauPtWithDMF_EL3->Fill(gentaujet->pt());	  
	  GenTauEtaWithDMF_EL3->Fill(gentaujet->eta());
	  GenTauPhiWithDMF_EL3->Fill(gentaujet->phi());
	}
	
	
	
	if((*_ev2)[tauCandidate] > 0.5) {
	  
	  if(gentaujet->pt() != 0) {
	    TauPtResponse_EM3->Fill(tauCandidate->pt()/gentaujet->pt());
	  }
	  
		     RecoTauDecayMode_EM3->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_EM3->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_EM3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_EM3->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_EM3->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_EM3->Fill(gentaujet->phi());
		   }

		   if((*_ev3)[tauCandidate] > 0.5) {
		     
		     //    cout<<"1"<<endl;  
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_ET3->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_ET3->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_ET3->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_ET3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_ET3->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_ET3->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_ET3->Fill(gentaujet->phi());
		   }
		   
		   
		   if((*_iso4)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_LIso3Hits->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_LIso3Hits->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_LIso3Hits->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_LIso3Hits->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_LIso3Hits->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_LIso3Hits->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_LIso3Hits->Fill(gentaujet->phi());
		   }
		   
		   if((*_iso5)[tauCandidate] > 0.5) {
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_MIso3Hits->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_MIso3Hits->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_MIso3Hits->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_MIso3Hits->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_MIso3Hits->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_MIso3Hits->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_MIso3Hits->Fill(gentaujet->phi());
		   }
		   
		   if((*_iso6)[tauCandidate] > 0.5) {
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_TIso3Hits->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_TIso3Hits->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_TIso3Hits->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_TIso3Hits->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_TIso3Hits->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_TIso3Hits->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_TIso3Hits->Fill(gentaujet->phi());
		   }
		   
		   
		   if((*_iso1)[tauCandidate] > 0.5) {
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_LIso->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_LIso->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_LIso->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_LIso->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_LIso->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_LIso->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_LIso->Fill(gentaujet->phi());
		     
		   }
		   
		   if((*_iso2)[tauCandidate] > 0.5) {

		     if(gentaujet->pt() != 0) {
		       TauPtResponse_MIso->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_MIso->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_MIso->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_MIso->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_MIso->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_MIso->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_MIso->Fill(gentaujet->phi());
		     
		   }
		   
		   
		   if((*_iso3)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_TIso->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_TIso->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_TIso->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_TIso->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_TIso->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_TIso->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_TIso->Fill(gentaujet->phi());
		     
		   }
		   
		   if((*_hpsTau)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_VLChar->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_VLChar->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_VLChar->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_VLChar->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_VLChar->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_VLChar->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_VLChar->Fill(gentaujet->phi());
		     
		   }
		   
		   
		   if((*_hpsTau1)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_LChar->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_LChar->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_LChar->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_LChar->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     
		     GenTauPtWithDMF_LChar->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_LChar->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_LChar->Fill(gentaujet->phi());
		   }
		   
		   if((*_hpsTau2)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_MChar->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_MChar->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_MChar->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_MChar->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     
		     GenTauPtWithDMF_MChar->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_MChar->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_MChar->Fill(gentaujet->phi());
		     
		   }
		   
		   ///
                  		   if((*rho1)[tauCandidate] > 0.5) {
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_LooseRho->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_LooseRho->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_LooseRho->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_LooseRho->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_LooseRho->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_LooseRho->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_LooseRho->Fill(gentaujet->phi());
		   }
		  

 
		   if((*rho2)[tauCandidate] > 0.5) {
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_MediumRho->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_MediumRho->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_MediumRho->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_MediumRho->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_MediumRho->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_MediumRho->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_MediumRho->Fill(gentaujet->phi());
		   }


		   if((*rho3)[tauCandidate] > 0.5) {
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_TightRho->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_TightRho->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_TightRho->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_TightRho->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_TightRho->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_TightRho->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_TightRho->Fill(gentaujet->phi());
		   }
		   

		   if((*_hpsTau3)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_TChar->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_TChar->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_TChar->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_TChar->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_TChar->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_TChar->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_TChar->Fill(gentaujet->phi());
		     
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
bool TauIDChecksG2p3::OverlapWithGenTau(double Taueta , double Tauphi ,edm::Handle<std::vector< reco::GenJet > > genTauJets ,int  &index     ) {
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

bool TauIDChecksG2p3::IsZTauTau(edm::Handle<reco::GenParticleCollection> genParticles){
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

