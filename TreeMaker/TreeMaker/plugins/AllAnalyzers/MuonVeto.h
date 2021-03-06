
#ifndef __MUON_VETO_H_                                                                                                                                          
#define __MUON_VETO_H_ 


#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/CompositeCandidate.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Math/interface/LorentzVectorFwd.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/PatCandidates/interface/Isolation.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/normalizedPhi.h"
#include "DataFormats/TauReco/interface/PFTau.h"
#include "DataFormats/TauReco/interface/PFTauDiscriminator.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/Common/interface/RefVector.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "CLHEP/Random/RandGauss.h"
#include "CommonTools/CandUtils/interface/Booster.h"
#include "DataFormats/METReco/interface/GenMET.h"
#include "DataFormats/METReco/interface/GenMETCollection.h"
#include <Math/VectorUtil.h>
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/HitPattern.h"
#include "TrackingTools/TransientTrack/interface/TrackTransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "CLHEP/Units/GlobalPhysicalConstants.h"
#include "CommonTools/Statistics/interface/ChiSquaredProbability.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "JetMETCorrections/Objects/interface/JetCorrectionsRecord.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "CommonTools/ParticleFlow/test/PFIsoReaderDemo.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "JetMETCorrections/Objects/interface/JetCorrector.h"
#include "JetMETCorrections/Objects/interface/JetCorrectionsRecord.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "boost/regex.hpp"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "PhysicsTools/JetMCUtils/interface/JetMCTag.h"
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TProfile.h>
#include <TTree.h>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#include <TRandom3.h>
#include <TBranch.h>
// class declaration                                                                                                                           
//                                                                                                                                             
using namespace std;
using namespace edm;

//
// class declaration
//

class MuonVeto {
    public:
        MuonVeto(std::string prefix, edm::Service<TFileService> fs, const edm::ParameterSet& cfg);
      ~MuonVeto();
        void Fill(const edm::Event& iEvent);
        void Clear();
 //      FakeRate* fakerateObj;

    private:
     MuonVeto() {};


  //-----do matching to gen?
  bool _MatchTauToGen;
  bool _UseTauMotherId;
  bool _UseTauGrandMotherId;
  bool _MatchLeptonToGen;
  bool _UseLeptonMotherId;
  bool _UseLeptonGrandMotherId;
  int _TauMotherId;
  int _TauGrandMotherId;
  int _LeptonMotherId;
  int _LeptonGrandMotherId;
  double _TauToGenMatchingDeltaR;                                                                                                                            
  std::vector<bool> muVetoContainer,EVetoContainer,IsoVetoContainer;
  std::vector<reco::GenParticleRef> associatedGenParticles;
  
  Handle< reco::GenParticleCollection > _genParticles;
  Handle<reco::GenJetCollection> _genJets;
  Handle<reco::PFTauCollection> _hpsTaucoll;
//  Handle<reco::PFTauDiscriminator> _hpsTau,_hpsTau1,_hpsTau2,_hpsTau3,_chargedIsoPtSum,_neutralIsoPtSum,_pucorrPtSum,_rawCharged;
  
 Handle<reco::PFTauDiscriminator> _dmf,_mv1,_mv2,_mv3,_mv31,_mv32,_ev1,_ev2,_ev3,_iso1,_iso2,_iso3,_iso4,_iso5,_iso6, _hpsTau,_hpsTau1,_hpsTau2,_hpsTau3,_chargedIsoPtSum,_neutralIsoPtSum,_pucorrPtSum,_rawCharged; 
  bool OverlapWithGenTau(double, double, edm::Handle<std::vector<reco::GenJet> >, int&) ;
  void countHits(const reco::Muon& muon, std::vector<int>& numHitsDT, std::vector<int>& numHitsCSC, std::vector<int>& numHitsRPC);
  //  bool MatchingWithPFTau(const patTau& theObject);
  bool IsZTauTau(edm::Handle<reco::GenParticleCollection> genParticles);
  reco::Candidate::LorentzVector MChadtau;
  const reco::Candidate * daughterCand;  
  const reco::Candidate * motherCand;
  const reco::Candidate * grandMotherCand;

  void countMatches(const reco::Muon& muon, std::vector<int>& numMatchesDT, std::vector<int>& numMatchesCSC, std::vector<int>& numMatchesRPC);
  //  double hpsLooseCombined3HitsFromPtSums1;

  // vector<string> muVeto, EVeto, IsoVeto;

 int tauGenJetDecayModeInt;

 TH1F *h_Num_Muons;
 TH1F *h_Fill_Muon_pT;

 TH1F *h_Fill_Muon_Eta;
 
 TH1F *h_Fill_numMatches_eta1p2;    
 TH1F * h_DT_FirstStation_eta1p2 ;  
 TH1F *h_CSC_FirstStation_eta1p2 ;  
 TH1F *h_RPC_FirstStation_eta1p2  ; 
 TH1F *h_DT_SecondStation_eta1p2   ;
 TH1F *h_CSC_SecondStation_eta1p2  ;
 TH1F *h_RPC_SecondStation_eta1p2  ;
 TH1F *h_DT_ThirdStation_eta1p2    ;
 TH1F *h_CSC_ThirdStation_eta1p2   ;
 TH1F *h_RPC_ThirdStation_eta1p2   ;
 TH1F *h_DT_FourthStation_eta1p2   ;
 TH1F *h_CSC_FourthStation_eta1p2  ;
 TH1F *h_RPC_FourthStation_eta1p2 ;
 TH1F *h_Fill_numMatches_etag1p2   ;
 TH1F *h_DT_FirstStation_etag1p2   ;
 TH1F *h_CSC_FirstStation_etag1p2  ;
 TH1F *h_RPC_FirstStation_etag1p2  ;
 TH1F *h_DT_SecondStation_etag1p2  ;
 TH1F *h_CSC_SecondStation_etag1p2 ;
 TH1F *h_RPC_SecondStation_etag1p2 ;
 TH1F *h_DT_ThirdStation_etag1p2   ;
 TH1F *h_CSC_ThirdStation_etag1p2  ;
 TH1F *h_RPC_ThirdStation_etag1p2  ;
 TH1F *h_DT_FourthStation_etag1p2  ;
 TH1F *h_CSC_FourthStation_etag1p2 ;
 TH1F *h_RPC_FourthStation_etag1p2 ;


 TH1F * h_DT_FirstStation_eta1p2_Muons ;  
 TH1F *h_CSC_FirstStation_eta1p2_Muons ;  
 TH1F *h_RPC_FirstStation_eta1p2_Muons  ; 
 TH1F *h_DT_SecondStation_eta1p2_Muons   ;
 TH1F *h_CSC_SecondStation_eta1p2_Muons  ;
 TH1F *h_RPC_SecondStation_eta1p2_Muons  ;
 TH1F *h_DT_ThirdStation_eta1p2_Muons    ;
 TH1F *h_CSC_ThirdStation_eta1p2_Muons   ;
 TH1F *h_RPC_ThirdStation_eta1p2_Muons   ;
 TH1F *h_DT_FourthStation_eta1p2_Muons   ;
 TH1F *h_CSC_FourthStation_eta1p2_Muons  ;
 TH1F *h_RPC_FourthStation_eta1p2_Muons ;

 TH1F *h_DT_FirstStation_etag1p2_Muons   ;
 TH1F *h_CSC_FirstStation_etag1p2_Muons  ;
 TH1F *h_RPC_FirstStation_etag1p2_Muons  ;
 TH1F *h_DT_SecondStation_etag1p2_Muons  ;
 TH1F *h_CSC_SecondStation_etag1p2_Muons ;
 TH1F *h_RPC_SecondStation_etag1p2_Muons ;
 TH1F *h_DT_ThirdStation_etag1p2_Muons   ;
 TH1F *h_CSC_ThirdStation_etag1p2_Muons  ;
 TH1F *h_RPC_ThirdStation_etag1p2_Muons  ;
 TH1F *h_DT_FourthStation_etag1p2_Muons  ;
 TH1F *h_CSC_FourthStation_etag1p2_Muons ;
 TH1F *h_RPC_FourthStation_etag1p2_Muons ;

 TH1F * h_DT_FirstStation_Matches_eta1p2 ;  
 TH1F *h_CSC_FirstStation_Matches_eta1p2 ;  
 TH1F *h_RPC_FirstStation_Matches_eta1p2  ; 
 TH1F *h_DT_SecondStation_Matches_eta1p2   ;
 TH1F *h_CSC_SecondStation_Matches_eta1p2  ;
 TH1F *h_RPC_SecondStation_Matches_eta1p2  ;
 TH1F *h_DT_ThirdStation_Matches_eta1p2    ;
 TH1F *h_CSC_ThirdStation_Matches_eta1p2   ;
 TH1F *h_RPC_ThirdStation_Matches_eta1p2   ;
 TH1F *h_DT_FourthStation_Matches_eta1p2   ;
 TH1F *h_CSC_FourthStation_Matches_eta1p2  ;
 TH1F *h_RPC_FourthStation_Matches_eta1p2 ;
 TH1F *h_DT_FirstStation_Matches_etag1p2   ;
 TH1F *h_CSC_FirstStation_Matches_etag1p2  ;
 TH1F *h_RPC_FirstStation_Matches_etag1p2  ;
 TH1F *h_DT_SecondStation_Matches_etag1p2  ;
 TH1F *h_CSC_SecondStation_Matches_etag1p2 ;
 TH1F *h_RPC_SecondStation_Matches_etag1p2 ;
 TH1F *h_DT_ThirdStation_Matches_etag1p2   ;
 TH1F *h_CSC_ThirdStation_Matches_etag1p2  ;
 TH1F *h_RPC_ThirdStation_Matches_etag1p2  ;
 TH1F *h_DT_FourthStation_Matches_etag1p2  ;
 TH1F *h_CSC_FourthStation_Matches_etag1p2 ;
 TH1F *h_RPC_FourthStation_Matches_etag1p2 ;


 TH1F * h_DT_FirstStation_Matches_eta1p2_Muons ;  
 TH1F *h_CSC_FirstStation_Matches_eta1p2_Muons ;  
 TH1F *h_RPC_FirstStation_Matches_eta1p2_Muons  ; 
 TH1F *h_DT_SecondStation_Matches_eta1p2_Muons   ;
 TH1F *h_CSC_SecondStation_Matches_eta1p2_Muons  ;
 TH1F *h_RPC_SecondStation_Matches_eta1p2_Muons  ;
 TH1F *h_DT_ThirdStation_Matches_eta1p2_Muons    ;
 TH1F *h_CSC_ThirdStation_Matches_eta1p2_Muons   ;
 TH1F *h_RPC_ThirdStation_Matches_eta1p2_Muons   ;
 TH1F *h_DT_FourthStation_Matches_eta1p2_Muons   ;
 TH1F *h_CSC_FourthStation_Matches_eta1p2_Muons  ;
 TH1F *h_RPC_FourthStation_Matches_eta1p2_Muons ;
 TH1F *h_DT_FirstStation_Matches_etag1p2_Muons   ;
 TH1F *h_CSC_FirstStation_Matches_etag1p2_Muons  ;
 TH1F *h_RPC_FirstStation_Matches_etag1p2_Muons  ;
 TH1F *h_DT_SecondStation_Matches_etag1p2_Muons  ;
 TH1F *h_CSC_SecondStation_Matches_etag1p2_Muons ;
 TH1F *h_RPC_SecondStation_Matches_etag1p2_Muons ;
 TH1F *h_DT_ThirdStation_Matches_etag1p2_Muons   ;
 TH1F *h_CSC_ThirdStation_Matches_etag1p2_Muons  ;
 TH1F *h_RPC_ThirdStation_Matches_etag1p2_Muons  ;
 TH1F *h_DT_FourthStation_Matches_etag1p2_Muons  ;
 TH1F *h_CSC_FourthStation_Matches_etag1p2_Muons ;
 TH1F *h_RPC_FourthStation_Matches_etag1p2_Muons ;


 TH1F *h_Fill_numMatches_eta1p2_ML2;   
 TH1F *h_DT_FirstStation_eta1p2_ML2 ;  
 TH1F *h_CSC_FirstStation_eta1p2_ML2;  
 TH1F *h_RPC_FirstStation_eta1p2_ML2  ;
 TH1F *h_DT_SecondStation_eta1p2_ML2 ; 
 TH1F *h_CSC_SecondStation_eta1p2_ML2; 
 TH1F *h_RPC_SecondStation_eta1p2_ML2; 
 TH1F *h_DT_ThirdStation_eta1p2_ML2  ; 
 TH1F *h_CSC_ThirdStation_eta1p2_ML2 ; 
 TH1F *h_RPC_ThirdStation_eta1p2_ML2 ; 
 TH1F *h_DT_FourthStation_eta1p2_ML2 ; 
 TH1F *h_CSC_FourthStation_eta1p2_ML2 ;
 TH1F *h_RPC_FourthStation_eta1p2_ML2; 
 TH1F *h_Fill_numMatches_etag1p2_ML2;  
 TH1F *h_DT_FirstStation_etag1p2_ML2;  
 TH1F *h_CSC_FirstStation_etag1p2_ML2; 
 TH1F *h_RPC_FirstStation_etag1p2_ML2; 
 TH1F *h_DT_SecondStation_etag1p2_ML2; 
 TH1F *h_CSC_SecondStation_etag1p2_ML2;
 TH1F *h_RPC_SecondStation_etag1p2_ML2;
 TH1F *h_DT_ThirdStation_etag1p2_ML2  ;
 TH1F *h_CSC_ThirdStation_etag1p2_ML2 ;
 TH1F *h_RPC_ThirdStation_etag1p2_ML2 ;
 TH1F *h_DT_FourthStation_etag1p2_ML2 ;
 TH1F *h_CSC_FourthStation_etag1p2_ML2;
 TH1F *h_RPC_FourthStation_etag1p2_ML2;
                                 
                                 
 TH1F *h_Fill_numMatches_eta1p2_ML3   ;
 TH1F *h_DT_FirstStation_eta1p2_ML3   ;
 TH1F *h_CSC_FirstStation_eta1p2_ML3  ;
 TH1F *h_RPC_FirstStation_eta1p2_ML3  ;
 TH1F *h_DT_SecondStation_eta1p2_ML3  ;
 TH1F *h_CSC_SecondStation_eta1p2_ML3 ;
 TH1F *h_RPC_SecondStation_eta1p2_ML3 ;
 TH1F *h_DT_ThirdStation_eta1p2_ML3   ;
 TH1F *h_CSC_ThirdStation_eta1p2_ML3  ;
  TH1F *h_RPC_ThirdStation_eta1p2_ML3  ;
  TH1F *h_DT_FourthStation_eta1p2_ML3 ; 
  TH1F *h_CSC_FourthStation_eta1p2_ML3 ;
  TH1F *h_RPC_FourthStation_eta1p2_ML3 ;
  TH1F *h_Fill_numMatches_etag1p2_ML3  ;
  TH1F *h_DT_FirstStation_etag1p2_ML3  ;
  TH1F *h_CSC_FirstStation_etag1p2_ML3 ;
  TH1F *h_RPC_FirstStation_etag1p2_ML3 ;
  TH1F *h_DT_SecondStation_etag1p2_ML3 ;
  TH1F *h_CSC_SecondStation_etag1p2_ML3;
  TH1F *h_RPC_SecondStation_etag1p2_ML3;
  TH1F *h_DT_ThirdStation_etag1p2_ML3  ;
  TH1F *h_CSC_ThirdStation_etag1p2_ML3 ;
  TH1F *h_RPC_ThirdStation_etag1p2_ML3 ;
  TH1F *h_DT_FourthStation_etag1p2_ML3 ;
  TH1F *h_CSC_FourthStation_etag1p2_ML3;
  TH1F *h_RPC_FourthStation_etag1p2_ML3;
  

   int numMatches ,numMatches0, numMatches1, numMatches2;
//
// constructors and destructor
};
#endif
