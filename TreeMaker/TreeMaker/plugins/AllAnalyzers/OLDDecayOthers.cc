#include "./OLDDecayOthers.h"                                                                                                                                        


OLDDecayOthers::OLDDecayOthers(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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
  
  
  hFillTauHcal3x3OverPLead  = fs->make<TH1F>(("hFillTauHcal3x3OverPLead"+prefix).c_str() ,"hFillTauHcal3x3OverPLead",1000,0,50);
  FillHOverP  = fs->make<TH1F>(("FillHOverP"+prefix).c_str() ,"FillHOverP",1000,0,50);
  FillEOverP  = fs->make<TH1F>(("FillEOverP"+prefix).c_str() ,"FillEOverP",1000,0,30); 
  FillGammaFraction = fs->make<TH1F>(("FillGammaFraction"+prefix).c_str() ,"FillGammaFraction",1000,0,5);
  
  hFillTauHcal3x3OverPLead_before  = fs->make<TH1F>(("hFillTauHcal3x3OverPLead_before"+prefix).c_str() ,"hFillTauHcal3x3OverPLead_befor",1000,0,50);
  FillHOverP_before  = fs->make<TH1F>(("FillHOverP_before"+prefix).c_str() ,"FillHOverP_before",1000,0,50);
  FillEOverP_before  = fs->make<TH1F>(("FillEOverP_before"+prefix).c_str() ,"FillEOverP_brfore",1000,0,30); 
  FillGammaFraction_before = fs->make<TH1F>(("FillGammaFraction_before"+prefix).c_str() ,"FillGammaFraction_before",1000,0,5);
  
  hFillTauHcal3x3OverPLead_DMF  = fs->make<TH1F>(("hFillTauHcal3x3OverPLead_DMF"+prefix).c_str() ,"hFillTauHcal3x3OverPLead_DMF",1000,0,50);
  FillHOverP_DMF  = fs->make<TH1F>(("FillHOverP_DMF"+prefix).c_str() ,"FillHOverP_DMF",1000,0,50);
  FillEOverP_DMF  = fs->make<TH1F>(("FillEOverP_DMF"+prefix).c_str() ,"FillEOverP_DMF",1000,0,30); 
  FillGammaFraction_DMF = fs->make<TH1F>(("FillGammaFraction_DMF"+prefix).c_str() ,"FillGammaFraction_DMF",1000,0,5);
  

  GenTauPt_NDM1Prong = fs->make<TH1F>(("GenTauPt_NDM1Prong"+prefix).c_str() ,"GenTauPt_NDM1Prong" ,100,0,700);                                               
  GenTauEta_NDM1Prong = fs->make<TH1F>(("GenTauEta_NDM1Prong"+prefix).c_str() ,"GenTauEta_NDM1Prong" ,100,-5,5);
  GenTauPhi_NDM1Prong = fs->make<TH1F>(("GenTauPhi_NDM1Prong"+prefix).c_str() ,"GenTauPhi_NDM1Prong" ,100,-5,5);

  GenTauPt_NDM1Prong1pi0 = fs->make<TH1F>(("GenTauPt_NDM1Prong1pi0"+prefix).c_str() ,"GenTauPt_NDM1Prong1pi0" ,100,0,700);
  GenTauEta_NDM1Prong1pi0 = fs->make<TH1F>(("GenTauEta_NDM1Prong1pi0"+prefix).c_str() ,"GenTauEta_NDM1Prong1pi0" ,100,-5,5);
  GenTauPhi_NDM1Prong1pi0 = fs->make<TH1F>(("GenTauPhi_NDM1Prong1pi0"+prefix).c_str() ,"GenTauPhi_NDM1Prong1pi0" ,100,-5,5);

  GenTauPt_NDM1Prong2pi0 = fs->make<TH1F>(("GenTauPt_NDM1Prong2pi0"+prefix).c_str() ,"GenTauPt_NDM1Prong2pi0" ,100,0,700);
  GenTauEta_NDM1Prong2pi0 = fs->make<TH1F>(("GenTauEta_NDM1Prong2pi0"+prefix).c_str() ,"GenTauEta_NDM1Prong2pi0" ,100,-5,5);
  GenTauPhi_NDM1Prong2pi0 = fs->make<TH1F>(("GenTauPhi_NDM1Prong2pi0"+prefix).c_str() ,"GenTauPhi_NDM1Prong2pi0" ,100,-5,5);

  GenTauPt_NDM3Prong = fs->make<TH1F>(("GenTauPt_NDM3Prong"+prefix).c_str() ,"GenTauPt_NDM3Prong" ,100,0,700);
  GenTauEta_NDM3Prong = fs->make<TH1F>(("GenTauEta_NDM3Prong"+prefix).c_str() ,"GenTauEta_NDM3Prong" ,100,-5,5);
  GenTauPhi_NDM3Prong = fs->make<TH1F>(("GenTauPhi_NDM3Prong"+prefix).c_str() ,"GenTauPhi_NDM3Prong" ,100,-5,5);

  GenTauPt_NDM3Prong1pi0 = fs->make<TH1F>(("GenTauPt_NDM3Prong1pi0"+prefix).c_str() ,"GenTauPt_NDM3Prong1pi0" ,100,0,700);
  GenTauEta_NDM3Prong1pi0 = fs->make<TH1F>(("GenTauEta_NDM3Prong1pi0"+prefix).c_str() ,"GenTauEta_NDM3Prong1pi0" ,100,-5,5);
  GenTauPhi_NDM3Prong1pi0 = fs->make<TH1F>(("GenTauPhi_NDM3Prong1pi0"+prefix).c_str() ,"GenTauPhi_NDM3Prong1pi0" ,100,-5,5);
 
   GenTauPt_Den1Prong = fs->make<TH1F>(("GenTauPt_Den1Prong"+prefix).c_str() ,"GenTauPt_Den1Prong" ,100,0,700);                                               
  GenTauEta_Den1Prong = fs->make<TH1F>(("GenTauEta_Den1Prong"+prefix).c_str() ,"GenTauEta_Den1Prong" ,100,-5,5);
  GenTauPhi_Den1Prong = fs->make<TH1F>(("GenTauPhi_Den1Prong"+prefix).c_str() ,"GenTauPhi_Den1Prong" ,100,-5,5);

  GenTauPt_Den1Prong1pi0 = fs->make<TH1F>(("GenTauPt_Den1Prong1pi0"+prefix).c_str() ,"GenTauPt_Den1Prong1pi0" ,100,0,700);
  GenTauEta_Den1Prong1pi0 = fs->make<TH1F>(("GenTauEta_Den1Prong1pi0"+prefix).c_str() ,"GenTauEta_Den1Prong1pi0" ,100,-5,5);
  GenTauPhi_Den1Prong1pi0 = fs->make<TH1F>(("GenTauPhi_Den1Prong1pi0"+prefix).c_str() ,"GenTauPhi_Den1Prong1pi0" ,100,-5,5);

  GenTauPt_Den1Prong2pi0 = fs->make<TH1F>(("GenTauPt_Den1Prong2pi0"+prefix).c_str() ,"GenTauPt_Den1Prong2pi0" ,100,0,700);
  GenTauEta_Den1Prong2pi0 = fs->make<TH1F>(("GenTauEta_Den1Prong2pi0"+prefix).c_str() ,"GenTauEta_Den1Prong2pi0" ,100,-5,5);
  GenTauPhi_Den1Prong2pi0 = fs->make<TH1F>(("GenTauPhi_Den1Prong2pi0"+prefix).c_str() ,"GenTauPhi_Den1Prong2pi0" ,100,-5,5);

  GenTauPt_Den3Prong = fs->make<TH1F>(("GenTauPt_Den3Prong"+prefix).c_str() ,"GenTauPt_Den3Prong" ,100,0,700);
  GenTauEta_Den3Prong = fs->make<TH1F>(("GenTauEta_Den3Prong"+prefix).c_str() ,"GenTauEta_Den3Prong" ,100,-5,5);
  GenTauPhi_Den3Prong = fs->make<TH1F>(("GenTauPhi_Den3Prong"+prefix).c_str() ,"GenTauPhi_Den3Prong" ,100,-5,5);

  GenTauPt_Den3Prong1pi0 = fs->make<TH1F>(("GenTauPt_Den3Prong1pi0"+prefix).c_str() ,"GenTauPt_Den3Prong1pi0" ,100,0,700);
  GenTauEta_Den3Prong1pi0 = fs->make<TH1F>(("GenTauEta_Den3Prong1pi0"+prefix).c_str() ,"GenTauEta_Den3Prong1pi0" ,100,-5,5);
  GenTauPhi_Den3Prong1pi0 = fs->make<TH1F>(("GenTauPhi_Den3Prong1pi0"+prefix).c_str() ,"GenTauPhi_Den3Prong1pi0" ,100,-5,5);

  TauPtResponse_NDM3Prong1pi0LChar  = fs->make<TH1F>(("TauPtResponse_NDM3Prong1pi0LChar"+prefix).c_str() ,"TauPtResponse_NDM3Prong1pi0LChar",100,0.1,2.0);
  TauPtResponse_NDM3Prong1pi0  = fs->make<TH1F>(("TauPtResponse_NDM3Prong1pi0"+prefix).c_str() ,"TauPtResponse_NDM3Prong1pi0",100,0.1,2.0);
  TauPtResponse_NDM1Prong1pi0LChar  = fs->make<TH1F>(("TauPtResponse_NDM1Prong1pi0LChar"+prefix).c_str() ,"TauPtResponse_NDM1Prong1pi0LChar",100,0.1,2.0);
  TauPtResponse_NDM1Prong1pi0  = fs->make<TH1F>(("TauPtResponse_NDM1Prong1pi0"+prefix).c_str() ,"TauPtResponse_NDM1Prong1pi0",100,0.1,2.0);
  TauPtResponse_NDM1Prong2pi0LChar  = fs->make<TH1F>(("TauPtResponse_NDM1Prong2pi0LChar"+prefix).c_str() ,"TauPtResponse_NDM1Prong2pi0LChar",100,0.1,2.0);
  TauPtResponse_NDM1Prong2pi0  = fs->make<TH1F>(("TauPtResponse_NDM1Prong2pi0"+prefix).c_str() ,"TauPtResponse_NDM1Prong2pi0",100,0.1,2.0);
  TauPtResponse_NDM1ProngLChar  = fs->make<TH1F>(("TauPtResponse_NDM1ProngLChar"+prefix).c_str() ,"TauPtResponse_NDM1ProngLChar",100,0.1,2.0);
  TauPtResponse_NDM1Prong  = fs->make<TH1F>(("TauPtResponse_NDM1Prong"+prefix).c_str() ,"TauPtResponse_NDM1Prong",100,0.1,2.0);
  TauPtResponse_NDM3ProngLChar  = fs->make<TH1F>(("TauPtResponse_NDM3ProngLChar"+prefix).c_str() ,"TauPtResponse_NDM3ProngLChar",100,0.1,2.0);
  TauPtResponse_NDM3Prong  = fs->make<TH1F>(("TauPtResponse_NDM1Prong"+prefix).c_str() ,"TauPtResponse_NDM1Prong",100,0.1,2.0);


  h_RunNumber_NDM1Prong = fs->make<TH1F>(("h_RunNumber_NDM1Prong"+prefix).c_str() ,"h_RunNumber_NDM1Prong",100000,0,100000);
  h_EventNumber_NDM1Prong = fs->make<TH1F>(("h_EventNumber_NDM1Prong"+prefix).c_str() ,"h_EventNumber_NDM1Prong",100000,0,100000);
  h_LumiNumber_NDM1Prong = fs->make<TH1F>(("h_LumiNumber_NDM1Prong"+prefix).c_str() ,"h_LumiNumber_NDM1Prong",100000,0,100000);
  h_BXNumber_NDM1Prong = fs->make<TH1F>(("h_BXNumber_NDM1Prong"+prefix).c_str() ,"h_BXNumber_NDM1Prong",100,0,100);
 

  h_RunNumber_NDM1Prong1pi0 = fs->make<TH1F>(("h_RunNumber_NDM1Prong1pi0"+prefix).c_str() ,"h_RunNumber_NDM1Prong1pi0",100000,0,100000);
  h_EventNumber_NDM1Prong1pi0 = fs->make<TH1F>(("h_EventNumber_NDM1Prong1pi0"+prefix).c_str() ,"h_EventNumber_NDM1Prong1pi0",100000,0,100000);
  h_LumiNumber_NDM1Prong1pi0 = fs->make<TH1F>(("h_LumiNumber_NDM1Prong1pi0"+prefix).c_str() ,"h_LumiNumber_NDM1Prong1pi0",100000,0,100000);
  h_BXNumber_NDM1Prong1pi0 = fs->make<TH1F>(("h_BXNumber_NDM1Prong1pi0"+prefix).c_str() ,"h_BXNumber_NDM1Prong1pi0",100,0,100);


  h_RunNumber_NDM1Prong2pi0 = fs->make<TH1F>(("h_RunNumber_NDM1Prong2pi0"+prefix).c_str() ,"h_RunNumber_NDM1Prong2pi0",100000,0,100000);
  h_EventNumber_NDM1Prong2pi0 = fs->make<TH1F>(("h_EventNumber_NDM1Prong2pi0"+prefix).c_str() ,"h_EventNumber_NDM1Prong2pi0",100000,0,100000);
  h_LumiNumber_NDM1Prong2pi0 = fs->make<TH1F>(("h_LumiNumber_NDM1Prong2pi0"+prefix).c_str() ,"h_LumiNumber_NDM1Prong2pi0",100000,0,100000);
  h_BXNumber_NDM1Prong2pi0 = fs->make<TH1F>(("h_BXNumber_NDM1Prong2pi0"+prefix).c_str() ,"h_BXNumber_NDM1Prong2pi0",100,0,100);

  h_RunNumber_NDM3Prong = fs->make<TH1F>(("h_RunNumber_NDM3Prong"+prefix).c_str() ,"h_RunNumber_NDM3Prong",100000,0,100000);
  h_EventNumber_NDM3Prong = fs->make<TH1F>(("h_EventNumber_NDM3Prong"+prefix).c_str() ,"h_EventNumber_NDM3Prong",100000,0,100000);
  h_LumiNumber_NDM3Prong = fs->make<TH1F>(("h_LumiNumber_NDM3Prong"+prefix).c_str() ,"h_LumiNumber_NDM3Prong",100000,0,100000);
  h_BXNumber_NDM3Prong = fs->make<TH1F>(("h_BXNumber_NDM3Prong"+prefix).c_str() ,"h_BXNumber_NDM3Prong",100,0,100);
 
  h_RunNumber_NDM3Prong1pi0 = fs->make<TH1F>(("h_RunNumber_NDM3Prong1pi0"+prefix).c_str() ,"h_RunNumber_NDM3Prong1pi0",100000,0,100000);
  h_EventNumber_NDM3Prong1pi0 = fs->make<TH1F>(("h_EventNumber_NDM3Prong1pi0"+prefix).c_str() ,"h_EventNumber_NDM3Prong1pi0",100000,0,100000);
  h_LumiNumber_NDM3Prong1pi0 = fs->make<TH1F>(("h_LumiNumber_NDM3Prong1pi0"+prefix).c_str() ,"h_LumiNumber_NDM3Prong1pi0",100000,0,100000);
  h_BXNumber_NDM3Prong1pi0 = fs->make<TH1F>(("h_BXNumber_NDM3Prong1pi0"+prefix).c_str() ,"h_BXNumber_NDM3Prong1pi0",100,0,100);

 TES_NDM3Prong1pi0  = fs->make<TProfile>(("TES_NDM3Prong1pi0"+prefix).c_str() ,"TES_NDM3Prong1pi0",100,0,700,0,50);
  TES_NDM3Prong  = fs->make<TProfile>(("TES_NDM3Prong"+prefix).c_str() ,"TES_NDM3Prong",100,0,700,0,50);
  TES_NDM1Prong1pi0  = fs->make<TProfile>(("TES_NDM1Prong1pi0"+prefix).c_str() ,"TES_NDM1Prong1pi0",100,0,700,0,50);
  TES_NDM1Prong  = fs->make<TProfile>(("TES_NDM1Prong"+prefix).c_str() ,"TES_NDM1Prong",100,0,700,0,50);
  TES_NDM1Prong2pi0  = fs->make<TProfile>(("TES_NDM1Prong2pi0"+prefix).c_str() ,"TES_NDM2Prong1pi0",100,0,700,0,50);                    


		  
}


OLDDecayOthers::~OLDDecayOthers()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void OLDDecayOthers::Fill(const edm::Event& iEvent) {
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
 

  iEvent.getByLabel("ak5GenJets", _genJets);
  
  
  iEvent.getByLabel("hpsPFTauProducer",_hpsTaucoll);
  //decay Mode
  
  //Muon Veto
 
   iEvent.getByLabel("hpsPFTauDiscriminationByDecayModeFindingOldDMs",_Newdmf);  

   //Muon 2 working pint
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection2",_mv1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumMuonRejection2",_mv2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection2",_mv3);
   
   // Muon 3 working points

   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection3",_mv31);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection3",_mv32);

   //Electron Veto
// new cut based

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


    // input variables to Electron Discriminator
   for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
       reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);
      
       if((tauCandidate->leadPFChargedHadrCand().isNonnull()) && (tauCandidate->leadPFChargedHadrCand()->p() > 0)) { 
          FillHOverP->Fill(tauCandidate->leadPFChargedHadrCand()->hcalEnergy()/tauCandidate->leadPFChargedHadrCand()->p());
          FillEOverP->Fill(tauCandidate->leadPFChargedHadrCand()->ecalEnergy()/tauCandidate->leadPFChargedHadrCand()->p());

         }

         hFillTauHcal3x3OverPLead->Fill(tauCandidate->hcal3x3OverPLead());

          // photon fraction
           
           int sumPt = 0;
           for ( std::vector<PFCandidatePtr>::const_iterator signalTrack =  tauCandidate->signalPFGammaCands().begin() ;signalTrack != tauCandidate->signalPFGammaCands().end(); ++signalTrack ) {
                   sumPt += (*signalTrack)->pt();

             }
        
             if(tauCandidate->pt() > 0 ){ FillGammaFraction->Fill(sumPt/tauCandidate->pt()); }

     }   // tau collection ends here 
//////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// individual decay modes


   for(reco::GenJetCollection::const_iterator gentaujet = genTauJets->begin(); gentaujet !=  genTauJets->end(); ++gentaujet) { 
     
     if(gentaujet->pt() < 20 ) continue;
     if(fabs(gentaujet->eta()) >= 2.3) continue;
     tauGenJetDecayModeInt = -999;
     std::string tauGenJetDecayMode = JetMCTagUtils::genTauDecayMode(*gentaujet);
     
     
     if(tauGenJetDecayMode=="oneProng0Pi0") {
      
       GenTauPt_Den1Prong->Fill(gentaujet->pt());
       GenTauEta_Den1Prong->Fill(gentaujet->eta());
       GenTauPhi_Den1Prong->Fill(gentaujet->phi());
       
       int index1= -1;
       if(OverlapWithGenTau(gentaujet->eta() ,gentaujet->phi() , _hpsTaucoll , _Newdmf, index1 )){
	 if(index1 != -1) {
	 reco::PFTauRef tauCandidate(_hpsTaucoll, index1);
	
	 GenTauPt_NDM1Prong->Fill(gentaujet->pt());
	 GenTauEta_NDM1Prong->Fill(gentaujet->eta());
	 GenTauPhi_NDM1Prong->Fill(gentaujet->phi());
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_NDM1Prong->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_NDM1Prong->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	 }
	 
	 if((*_hpsTau1)[tauCandidate] > 0.5) {
	   if(gentaujet->pt() != 0) {
	     TauPtResponse_NDM1ProngLChar->Fill(tauCandidate->pt()/gentaujet->pt());
	   }
	 } 
       }
     }
     }     
     // 1 prong 1 pi0
     if(tauGenJetDecayMode=="oneProng1Pi0") {

       GenTauPt_Den1Prong1pi0->Fill(gentaujet->pt());
       GenTauEta_Den1Prong1pi0->Fill(gentaujet->eta());
       GenTauPhi_Den1Prong1pi0->Fill(gentaujet->phi());
       
       int index1= -1;
       if(OverlapWithGenTau(gentaujet->eta() ,gentaujet->phi() , _hpsTaucoll , _Newdmf, index1 )){
	 if(index1 != -1) {
	 reco::PFTauRef tauCandidate(_hpsTaucoll, index1);
	 GenTauPt_NDM1Prong1pi0->Fill(gentaujet->pt());
	 GenTauEta_NDM1Prong1pi0->Fill(gentaujet->eta());
	 GenTauPhi_NDM1Prong1pi0->Fill(gentaujet->phi());
	
	 if(gentaujet->pt() != 0) {
	   TES_NDM1Prong1pi0->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   TauPtResponse_NDM1Prong1pi0->Fill(tauCandidate->pt()/gentaujet->pt());
	 }
	       
	 if((*_hpsTau1)[tauCandidate] > 0.5) {
	   if(gentaujet->pt() != 0) {
	     TauPtResponse_NDM1Prong1pi0LChar->Fill(tauCandidate->pt()/gentaujet->pt());
	   }
	 } 
       }
     } 
     }      


     /// I prong 2 po0
     if(tauGenJetDecayMode=="oneProng2Pi0") {
	 GenTauPt_Den1Prong2pi0->Fill(gentaujet->pt());
	 GenTauEta_Den1Prong2pi0->Fill(gentaujet->eta());
	 GenTauPhi_Den1Prong2pi0->Fill(gentaujet->phi());

       int index1= -1;
       if(OverlapWithGenTau(gentaujet->eta() ,gentaujet->phi() , _hpsTaucoll , _Newdmf, index1 )){
	 if(index1 != -1) {

	 reco::PFTauRef tauCandidate(_hpsTaucoll, index1);
	       
	 GenTauPt_NDM1Prong2pi0->Fill(gentaujet->pt());
	 GenTauEta_NDM1Prong2pi0->Fill(gentaujet->eta());
	 GenTauPhi_NDM1Prong2pi0->Fill(gentaujet->phi());
	 
	       
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_NDM1Prong2pi0->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_NDM1Prong2pi0->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	 }
	 
	 
	 if((*_hpsTau1)[tauCandidate] > 0.5) {
	   if(gentaujet->pt() != 0) {
	     TauPtResponse_NDM1Prong2pi0LChar->Fill(tauCandidate->pt()/gentaujet->pt());
	   }
	 } 
       }
     }
     }  

     // 3 prong

       if(tauGenJetDecayMode=="threeProng0Pi0") {

	 GenTauPt_Den3Prong->Fill(gentaujet->pt());
	 GenTauEta_Den3Prong->Fill(gentaujet->eta());
	 GenTauPhi_Den3Prong->Fill(gentaujet->phi());

       int index1= -1;
       if(OverlapWithGenTau(gentaujet->eta() ,gentaujet->phi() , _hpsTaucoll , _Newdmf, index1 )){
	 if(index1 != -1) {
	 reco::PFTauRef tauCandidate(_hpsTaucoll, index1);
	 
	 GenTauPt_NDM3Prong->Fill(gentaujet->pt());
	 GenTauEta_NDM3Prong->Fill(gentaujet->eta());
	 GenTauPhi_NDM3Prong->Fill(gentaujet->phi());
	 
	       
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_NDM3Prong->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_NDM3Prong->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	 }
	 
	 
	 if((*_hpsTau1)[tauCandidate] > 0.5) {
	   if(gentaujet->pt() != 0) {
	     TauPtResponse_NDM3Prong->Fill(tauCandidate->pt()/gentaujet->pt());
	   }
	 } 
       }
     }
       }

       if(tauGenJetDecayMode=="threeProng1Pi0") {


          GenTauPt_Den3Prong1pi0->Fill(gentaujet->pt());
          GenTauEta_Den3Prong1pi0->Fill(gentaujet->eta());
          GenTauPhi_Den3Prong1pi0->Fill(gentaujet->phi());

       int index1= -1;
       if(OverlapWithGenTau(gentaujet->eta() ,gentaujet->phi() , _hpsTaucoll , _Newdmf, index1 )){
	 if(index1 != -1) {

	 reco::PFTauRef tauCandidate(_hpsTaucoll, index1);
	 
	 GenTauPt_NDM3Prong1pi0->Fill(gentaujet->pt());
	 GenTauEta_NDM3Prong1pi0->Fill(gentaujet->eta());
	 GenTauPhi_NDM3Prong1pi0->Fill(gentaujet->phi());
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_NDM3Prong1pi0->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_NDM3Prong1pi0->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }
	 
	 
	 if((*_hpsTau1)[tauCandidate] > 0.5) {
	   if(gentaujet->pt() != 0) {
	     TauPtResponse_NDM3Prong1pi0LChar->Fill(tauCandidate->pt()/gentaujet->pt());
	   }
	 } 
       }
       }
       }
   }
   }
}


  



// ------------ method called once each job just before starting event loop  ------------


bool OLDDecayOthers::OverlapWithGenTau(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc, int &index ) {
   double drtmp = _TauToGenMatchingDeltaR;
   bool genTaufound = false;
   index = -1;

   for ( unsigned iTau = 0; iTau < taujetcol->size(); ++iTau ) {
     reco::PFTauRef tauCandidate(taujetcol,iTau);
     if(tauCandidate->pt() <= 20) continue;
     if(fabs(tauCandidate->eta()) >= 2.3) continue;
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


bool OLDDecayOthers::IsZTauTau(edm::Handle<reco::GenParticleCollection> genParticles){
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

