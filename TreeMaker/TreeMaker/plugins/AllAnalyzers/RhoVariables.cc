#include "./RhoVariables.h"                                                                                                                                        
  

RhoVariables::RhoVariables(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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

  GenTauPtWithDMF = fs->make<TH1F>(("GenTauPtWithDMF"+prefix).c_str() ,"GenTauPtWithDMF",100,0,700);                                                              
  GenTauEtaWithDMF = fs->make<TH1F>(("GenTauEtaWithDMF"+prefix).c_str() ,"GenTauEtaWithDMF",100,-5,5);
 GenTauPhiWithDMF = fs->make<TH1F>(("GenTauPhiWithDMF"+prefix).c_str() ,"GenTauPhiWithDMF",100,-5,5);

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


RhoVariables::~RhoVariables()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void RhoVariables::Fill(const edm::Event& iEvent) {
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
   
//   Rho Isolation Variables

   iEvent.getByLabel("hpsPFTauDiscriminationByLooseCombinedIsolationRhoSumPtCorr3Hits",rho1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumCombinedIsolationRhoSumPtCorr3Hits",rho2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightCombinedIsolationRhoSumPtCorr3Hits",rho3);   
   
   bool isZtautau=false;
   isZtautau = IsZTauTau (_genParticles) ;
   
   //isZtautau=true;
   
   if(isZtautau) {
     
     for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
       reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);
       
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
	       
	       //just to cross confirm	       
	       if(reco::deltaR(gentaujet->eta(), gentaujet->phi(), tauCandidate->eta(), tauCandidate->phi()) < _TauToGenMatchingDeltaR) {
		 
  
		 if(DecayModeFinding) {
		   
		   std::string tauGenJetDecayMode = JetMCTagUtils::genTauDecayMode(*gentaujet);
		   
		   
		   if(tauGenJetDecayMode=="muon") continue;
		   if(tauGenJetDecayMode=="electron") continue;
		   
		   
		   
		   if(tauGenJetDecayMode=="oneProng0Pi0") {
		     tauGenJetDecayModeInt=0;
		      
		   }
		   
		   if(tauGenJetDecayMode=="oneProng1Pi0") {
		     tauGenJetDecayModeInt=1;
		   }
		   
		   if(tauGenJetDecayMode=="oneProng2Pi0") {
		     tauGenJetDecayModeInt=2;
		  
		   }
		   
		   if(tauGenJetDecayMode=="threeProng0Pi0") {
		     tauGenJetDecayModeInt=10;
		  
		   }
		   
		   if(tauGenJetDecayMode=="threeProng1Pi0") {
		     tauGenJetDecayModeInt=11;
		  
		   }

       GenTauPtWithDMF->Fill(gentaujet->pt());  
       GenTauEtaWithDMF->Fill(gentaujet->eta());
       GenTauPhiWithDMF->Fill(gentaujet->phi());

		   
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
bool RhoVariables::OverlapWithGenTau(double Taueta , double Tauphi ,edm::Handle<std::vector< reco::GenJet > > genTauJets ,int  &index     ) {
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

bool RhoVariables::IsZTauTau(edm::Handle<reco::GenParticleCollection> genParticles){
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

