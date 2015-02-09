#ifndef __13NEW_DECAYMODE_NEWD_H_                                                                                                                                          
#define __13NEW_DECAYMODE_NEWD_H_ 


#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "Geometry/Records/interface/GlobalTrackingGeometryRecord.h"                                                             

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

class TauIDUpto2to3New {
    public:
        TauIDUpto2to3New(std::string prefix,edm::Service<TFileService> fs, const edm::ParameterSet& cfg);
      ~TauIDUpto2to3New();
        void Fill(const edm::Event& iEvent);
        void Clear();
 //      FakeRate* fakerateObj;

    private:
     TauIDUpto2to3New() {};


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
  Handle<reco::PFTauDiscriminator> _dmf,_mv1,_mv2,_mv3,_mv31,_mv32,_ev1,_ev2,_ev3,_iso1,_iso2,_iso3,_iso4,_iso5,_iso6, _hpsTau,_hpsTau1,_hpsTau2,_hpsTau3,_chargedIsoPtSum,_neutralIsoPtSum,_pucorrPtSum,_rawCharged, _rawpu, _rawn , _rawc,_nw1,_nw2,_nw1nq,_nw2nq,_hw1,_hw2,_hw1nq,_hw2nq, _h1 ,rho1,rho2,rho3 , _enew , _Newdmf, _isowLTraw,_isowoLTraw, _isowLTvloose,_isowLTloose, _isowLTmedium, _isowLTtight, _isowLTvtight, _isowLTvvtight, _isowoLTvloose,_isowoLTloose, _isowoLTmedium, _isowoLTtight, _isowoLTvtight, _isowoLTvvtight;

bool OverlapWithGenTau(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc, int &index );


bool OverlapWithGenTauForOther(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc, edm::Handle<reco::PFTauDiscriminator>  disc1 ,int &index );
//  bool MatchingWithPFTau(const patTau& theObject);
  bool IsZTauTau(edm::Handle<reco::GenParticleCollection> genParticles);
  reco::Candidate::LorentzVector MChadtau;
  const reco::Candidate * daughterCand;  
  const reco::Candidate * motherCand;
  const reco::Candidate * grandMotherCand;

  //  double hpsLooseCombined3HitsFromPtSums1;
  double hpsLooseCombined3HitsFromPtSums;  
  // vector<string> muVeto, EVeto, IsoVeto;

 int tauGenJetDecayModeInt;
 TH1F  *TrackPt;
 TH1F  *TrackEta;
 TH1F  *TrackPhi;
 TH1F  *JetPt;
  TH1F  *TauPtResponse_DM;

  TH1F  *TauPtResponse_ML2;
  TH1F  *TauPtResponse_MM2;
  TH1F  *TauPtResponse_MT2;

  TH1F  *TauPtResponse_ML3;
  TH1F  *TauPtResponse_MT3;

  TH1F  *TauPtResponse_EL3;
  TH1F  *TauPtResponse_ET3;
  TH1F  *TauPtResponse_EM3;

  TH1F  *TauPtResponse_LIso3Hits;
  TH1F  *TauPtResponse_MIso3Hits;
  TH1F  *TauPtResponse_TIso3Hits;

  TH1F *TauPtResponse_DenDMF;
  TH1F  *RecoTauDecayMode_DenDMF;
  TH1F  *GenTauDecayMode_DenDMF;
  TH2F  *reco_dm_vs_gen_DenDMF;

  TH1F  *TauPtResponse_LIso;
  TH1F  *TauPtResponse_MIso;
  TH1F  *TauPtResponse_TIso;

  TH1F  *TauPtResponse_VLChar;
  TH1F  *TauPtResponse_LChar;
  TH1F  *TauPtResponse_MChar;
  TH1F  *TauPtResponse_TChar;

  TH1I*  npuVertices_;
  TH1I*  ootnpuVertices_;

  TH1F  *RecoTauDecayMode_DM;
  TH1F  *GenTauDecayMode_DM;
  TH2F  *reco_dm_vs_gen_dm;

  TH1F  *RecoTauDecayMode_ML2;
  TH1F  *GenTauDecayMode_ML2;
  TH2F  *reco_dm_vs_gen_ML2;

  TH1F  *RecoTauDecayMode_MM2;
  TH1F  *GenTauDecayMode_MM2;
  TH2F  *reco_dm_vs_gen_MM2;

  TH1F  *RecoTauDecayMode_MT2;
  TH1F  *GenTauDecayMode_MT2;
  TH2F  *reco_dm_vs_gen_MT2;

  TH1F  *RecoTauDecayMode_ML3;
  TH1F  *GenTauDecayMode_ML3;
  TH2F  *reco_dm_vs_gen_ML3;

  TH1F  *RecoTauDecayMode_MT3;
  TH1F  *GenTauDecayMode_MT3;
  TH2F  *reco_dm_vs_gen_MT3;

  TH1F  *RecoTauDecayMode_EL3;
  TH1F  *GenTauDecayMode_EL3;
  TH2F  *reco_dm_vs_gen_EL3;


  TH1F  *RecoTauDecayMode_EM3;
  TH1F  *GenTauDecayMode_EM3;
  TH2F  *reco_dm_vs_gen_EM3;


  TH1F  *RecoTauDecayMode_ET3;
  TH1F  *GenTauDecayMode_ET3;
  TH2F  *reco_dm_vs_gen_ET3;


  TH1F  *RecoTauDecayMode_LIso3Hits;
  TH1F  *GenTauDecayMode_LIso3Hits;
  TH2F  *reco_dm_vs_gen_LIso3Hits;

  TH1F  *RecoTauDecayMode_MIso3Hits;
  TH1F  *GenTauDecayMode_MIso3Hits;
  TH2F  *reco_dm_vs_gen_MIso3Hits;

  TH1F  *RecoTauDecayMode_TIso3Hits;
  TH1F  *GenTauDecayMode_TIso3Hits;
  TH2F  *reco_dm_vs_gen_TIso3Hits;


  TH1F  *RecoTauDecayMode_LIso;
  TH1F  *GenTauDecayMode_LIso;
  TH2F  *reco_dm_vs_gen_LIso;

  TH1F  *RecoTauDecayMode_MIso;
  TH1F  *GenTauDecayMode_MIso;
  TH2F  *reco_dm_vs_gen_MIso;

  TH1F  *RecoTauDecayMode_TIso;
  TH1F  *GenTauDecayMode_TIso;
  TH2F  *reco_dm_vs_gen_TIso;


  TH1F  *RecoTauDecayMode_VLChar;
  TH1F  *GenTauDecayMode_VLChar;
  TH2F  *reco_dm_vs_gen_VLChar;

  TH1F  *RecoTauDecayMode_LChar;
  TH1F  *GenTauDecayMode_LChar;
  TH2F  *reco_dm_vs_gen_LChar;

  TH1F  *RecoTauDecayMode_MChar;
  TH1F  *GenTauDecayMode_MChar;
  TH2F  *reco_dm_vs_gen_MChar;

  TH1F  *RecoTauDecayMode_TChar;
  TH1F  *GenTauDecayMode_TChar;
  TH2F  *reco_dm_vs_gen_TChar;


 TH1F  *GenTauPtWithoutDMF;
 TH1F  *GenTauEtaWithoutDMF;
 TH1F  *GenTauPhiWithoutDMF;

 TH1F  *GenTauPtWithoutDMF_eta1p47;
 TH1F  *GenTauEtaWithoutDMF_eta1p47;
 TH1F  *GenTauPhiWithoutDMF_eta1p47;

 TH1F  *GenTauPtWithoutDMF_etag1p47;
 TH1F  *GenTauEtaWithoutDMF_etag1p47;
 TH1F  *GenTauPhiWithoutDMF_etag1p47;


 TH1F  *GenTauPt_Den;                                                                                        
 TH1F  *GenTauEta_Den;
 TH1F  *GenTauPhi_Den;

 TH1F  *GenTauPtWithDMF;
 TH1F  *GenTauEtaWithDMF;
 TH1F  *GenTauPhiWithDMF;

 TH1F *GenTauHadronCandidatesNewDMF;
 TH1F *GenTauPiZeroCandidatesNewDMF;

 TH1F *GenTauHadronCandidatesDMF;
 TH1F *GenTauPiZeroCandidatesDMF;



 TH1F  *GenTauPtWithNewDMF;
 TH1F  *GenTauEtaWithNewDMF;
 TH1F  *GenTauPhiWithNewDMF;

 

 TH1F  *GenTauPtWithDMF_ML2;
 TH1F  *GenTauEtaWithDMF_ML2;
 TH1F  *GenTauPhiWithDMF_ML2;

 TH1F  *GenTauPtWithDMF_MM2;
 TH1F  *GenTauEtaWithDMF_MM2;
 TH1F  *GenTauPhiWithDMF_MM2;

 TH1F  *GenTauPtWithDMF_MT2;
 TH1F  *GenTauEtaWithDMF_MT2;
 TH1F  *GenTauPhiWithDMF_MT2;

  TH1F  *GenTauPtWithDMF_ML3;
  TH1F  *GenTauEtaWithDMF_ML3;
  TH1F  *GenTauPhiWithDMF_ML3;

  TH1F  *GenTauPtWithDMF_MT3;
  TH1F  *GenTauEtaWithDMF_MT3;
  TH1F  *GenTauPhiWithDMF_MT3;

  TH1F  *GenTauPtWithDMF_EL3;
  TH1F  *GenTauEtaWithDMF_EL3;
  TH1F  *GenTauPhiWithDMF_EL3;
                     
  TH1F  *GenTauPtWithDMF_EM3;
  TH1F  *GenTauEtaWithDMF_EM3; 
  TH1F  *GenTauPhiWithDMF_EM3; 
                     
  TH1F  *GenTauPtWithDMF_ET3;
  TH1F  *GenTauEtaWithDMF_ET3;
  TH1F  *GenTauPhiWithDMF_ET3; // constants, enums and typedefs

  TH1F  *GenTauPtWithDMF_LIso3Hits; 
  TH1F  *GenTauEtaWithDMF_LIso3Hits;
  TH1F  *GenTauPhiWithDMF_LIso3Hits;
                           
  TH1F  *GenTauPtWithDMF_MIso3Hits; 
  TH1F  *GenTauEtaWithDMF_MIso3Hits;
  TH1F  *GenTauPhiWithDMF_MIso3Hits;
                           
  TH1F  *GenTauPtWithDMF_TIso3Hits; 
  TH1F  *GenTauEtaWithDMF_TIso3Hits;
  TH1F  *GenTauPhiWithDMF_TIso3Hits;

  TH1F  *GenTauPtWithDMF_LIso; 
  TH1F  *GenTauEtaWithDMF_LIso;
  TH1F  *GenTauPhiWithDMF_LIso;
                           
  TH1F  *GenTauPtWithDMF_MIso; 
  TH1F  *GenTauEtaWithDMF_MIso;
  TH1F  *GenTauPhiWithDMF_MIso;
                           
  TH1F  *GenTauPtWithDMF_TIso; 
  TH1F  *GenTauEtaWithDMF_TIso;
  TH1F  *GenTauPhiWithDMF_TIso;

  TH1F  *GenTauPtWithDMF_VLChar; 
  TH1F  *GenTauEtaWithDMF_VLChar;
  TH1F  *GenTauPhiWithDMF_VLChar;
 
  TH1F  *GenTauPtWithDMF_LChar; 
  TH1F  *GenTauEtaWithDMF_LChar;
  TH1F  *GenTauPhiWithDMF_LChar;
                           
  TH1F  *GenTauPtWithDMF_MChar;
  TH1F  *GenTauEtaWithDMF_MChar;
  TH1F  *GenTauPhiWithDMF_MChar;
                           
  TH1F  *GenTauPtWithDMF_TChar; 
  TH1F  *GenTauEtaWithDMF_TChar;
  TH1F  *GenTauPhiWithDMF_TChar;


  TH1F  *GenTauPtWithDMF_eta1p47_0;
  TH1F  *GenTauEtaWithDMF_eta1p47_0;
  TH1F  *GenTauPhiWithDMF_eta1p47_0;
  TH1F  *GenTauPtWithDMF_eta1p47_1;
  TH1F  *GenTauEtaWithDMF_eta1p47_1;
  TH1F  *GenTauPhiWithDMF_eta1p47_1;
 
  TH1F  *GenTauPtWithDMF_eta1p47_2;
  TH1F  *GenTauEtaWithDMF_eta1p47_2;
  TH1F  *GenTauPhiWithDMF_eta1p47_2;
      
  TH1F  *GenTauPtWithDMF_eta1p47_10;
  TH1F  *GenTauEtaWithDMF_eta1p47_10;
  TH1F  *GenTauPhiWithDMF_eta1p47_10;
 
  TH1F  *GenTauPtWithDMF_eta1p47_11;
  TH1F  *GenTauEtaWithDMF_eta1p47_11;
  TH1F  *GenTauPhiWithDMF_eta1p47_11;



  TH1F  *GenTauPtWithDMF_etag1p47_0;
  TH1F  *GenTauEtaWithDMF_etag1p47_0;
  TH1F  *GenTauPhiWithDMF_etag1p47_0;
  TH1F  *GenTauPtWithDMF_etag1p47_1;
  TH1F  *GenTauEtaWithDMF_etag1p47_1;
  TH1F  *GenTauPhiWithDMF_etag1p47_1;
 
  TH1F  *GenTauPtWithDMF_etag1p47_2;
  TH1F  *GenTauEtaWithDMF_etag1p47_2;
  TH1F  *GenTauPhiWithDMF_etag1p47_2;
      
  TH1F  *GenTauPtWithDMF_etag1p47_10;
  TH1F  *GenTauEtaWithDMF_etag1p47_10;
  TH1F  *GenTauPhiWithDMF_etag1p47_10;
 
  TH1F  *GenTauPtWithDMF_etag1p47_11;
  TH1F  *GenTauEtaWithDMF_etag1p47_11;
  TH1F  *GenTauPhiWithDMF_etag1p47_11;

  TH1F  *GenTauPtWithDMF_0;
  TH1F  *GenTauEtaWithDMF_0;
  TH1F  *GenTauPhiWithDMF_0;
  TH1F  *GenTauPtWithDMF_1;
  TH1F  *GenTauEtaWithDMF_1;
  TH1F  *GenTauPhiWithDMF_1;
 
  TH1F  *GenTauPtWithDMF_2;
  TH1F  *GenTauEtaWithDMF_2;
  TH1F  *GenTauPhiWithDMF_2;



  TH1F  *GenTauPtWithDMF_DenDMF;
  TH1F  *GenTauEtaWithDMF_DenDMF;
  TH1F  *GenTauPhiWithDMF_DenDMF;

      
  TH1F  *GenTauPtWithDMF_10;
  TH1F  *GenTauEtaWithDMF_10;
  TH1F  *GenTauPhiWithDMF_10;
 
  TH1F  *GenTauPtWithDMF_11;
  TH1F  *GenTauEtaWithDMF_11;
  TH1F  *GenTauPhiWithDMF_11;

  TH1F *hNeutralIsoPtSumWeight1;
  TH1F *hNeutralIsoPtSumWeight2;
  TH1F *hNeutralIsoPtSumWeight1NQ;
  TH1F *hNeutralIsoPtSumWeight2NQ;
  TH1F *hNeutralHadronIsoPtSum;
  TH1F *hNeutralHadronIsoPtSumWeight1;
  TH1F *hNeutralHadronIsoPtSumWeight2;
 TH1F *hNeutralHadronIsoPtSumWeight1NQ;
 TH1F *hNeutralHadronIsoPtSumWeight2NQ;
 TH1F *hChargedIsoPtSum;
 TH1F *hNeutralIsoPtSum;
 TH1F *hPUcorrPtSum;


 TProfile *hNeutralIsoPtSumWeight1_pt;
 TProfile *hNeutralIsoPtSumWeight2_pt;
 TProfile *hNeutralIsoPtSumWeight1NQ_pt;
 TProfile *hNeutralIsoPtSumWeight2NQ_pt;
 TProfile *hNeutralHadronIsoPtSum_pt;
 TProfile *hNeutralHadronIsoPtSumWeight1_pt;
 TProfile *hNeutralHadronIsoPtSumWeight2_pt;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_pt;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_pt;
 TProfile *hChargedIsoPtSum_pt;
 TProfile *hNeutralIsoPtSum_pt;
 TProfile *hPUcorrPtSum_pt;

 TProfile *hNeutralIsoPtSumWeight1_eta;
 TProfile *hNeutralIsoPtSumWeight2_eta;
 TProfile *hNeutralIsoPtSumWeight1NQ_eta;
 TProfile *hNeutralIsoPtSumWeight2NQ_eta;
 TProfile *hNeutralHadronIsoPtSum_eta;
 TProfile *hNeutralHadronIsoPtSumWeight1_eta;
 TProfile *hNeutralHadronIsoPtSumWeight2_eta;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_eta;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_eta;
 TProfile *hChargedIsoPtSum_eta;
 TProfile *hNeutralIsoPtSum_eta;
 TProfile *hPUcorrPtSum_eta;

 TProfile *hNeutralIsoPtSumWeight1_phi;
 TProfile *hNeutralIsoPtSumWeight2_phi;
 TProfile *hNeutralIsoPtSumWeight1NQ_phi;
 TProfile *hNeutralIsoPtSumWeight2NQ_phi;
 TProfile *hNeutralHadronIsoPtSum_phi;
 TProfile *hNeutralHadronIsoPtSumWeight1_phi;
 TProfile *hNeutralHadronIsoPtSumWeight2_phi;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_phi;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_phi;
 TProfile *hChargedIsoPtSum_phi;
 TProfile *hNeutralIsoPtSum_phi;
 TProfile *hPUcorrPtSum_phi;

 TProfile *hNeutralIsoPtSumWeight1_vtx;
 TProfile *hNeutralIsoPtSumWeight2_vtx;
 TProfile *hNeutralIsoPtSumWeight1NQ_vtx;
 TProfile *hNeutralIsoPtSumWeight2NQ_vtx;
 TProfile *hNeutralHadronIsoPtSum_vtx;
 TProfile *hNeutralHadronIsoPtSumWeight1_vtx;
 TProfile *hNeutralHadronIsoPtSumWeight2_vtx;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_vtx;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_vtx;
 TProfile *hChargedIsoPtSum_vtx;
 TProfile *hNeutralIsoPtSum_vtx;
 TProfile *hPUcorrPtSum_vtx;

 TProfile *hNeutralIsoPtSumWeight1_nGoodVtx;
 TProfile *hNeutralIsoPtSumWeight2_nGoodVtx;
 TProfile *hNeutralIsoPtSumWeight1NQ_nGoodVtx;
 TProfile *hNeutralIsoPtSumWeight2NQ_nGoodVtx;
 TProfile *hNeutralHadronIsoPtSum_nGoodVtx;
 TProfile *hNeutralHadronIsoPtSumWeight1_nGoodVtx;
 TProfile *hNeutralHadronIsoPtSumWeight2_nGoodVtx;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx;
 TProfile *hChargedIsoPtSum_nGoodVtx;
 TProfile *hNeutralIsoPtSum_nGoodVtx;
 TProfile *hPUcorrPtSum_nGoodVtx;



  TH1F *hNeutralIsoPtSumWeight1_dmf;
  TH1F *hNeutralIsoPtSumWeight2_dmf;
  TH1F *hNeutralIsoPtSumWeight1NQ_dmf;
  TH1F *hNeutralIsoPtSumWeight2NQ_dmf;
  TH1F *hNeutralHadronIsoPtSum_dmf;
  TH1F *hNeutralHadronIsoPtSumWeight1_dmf;
  TH1F *hNeutralHadronIsoPtSumWeight2_dmf;
 TH1F *hNeutralHadronIsoPtSumWeight1NQ_dmf;
 TH1F *hNeutralHadronIsoPtSumWeight2NQ_dmf;
 TH1F *hChargedIsoPtSum_dmf;
 TH1F *hNeutralIsoPtSum_dmf;
 TH1F *hPUcorrPtSum_dmf;

 TProfile *hNeutralIsoPtSumWeight1_pt_dmf;
 TProfile *hNeutralIsoPtSumWeight2_pt_dmf;
 TProfile *hNeutralIsoPtSumWeight1NQ_pt_dmf;
 TProfile *hNeutralIsoPtSumWeight2NQ_pt_dmf;
 TProfile *hNeutralHadronIsoPtSum_pt_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight1_pt_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight2_pt_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_pt_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_pt_dmf;
 TProfile *hChargedIsoPtSum_pt_dmf;
 TProfile *hNeutralIsoPtSum_pt_dmf;
 TProfile *hPUcorrPtSum_pt_dmf;

 TProfile *hNeutralIsoPtSumWeight1_eta_dmf;
 TProfile *hNeutralIsoPtSumWeight2_eta_dmf;
 TProfile *hNeutralIsoPtSumWeight1NQ_eta_dmf;
 TProfile *hNeutralIsoPtSumWeight2NQ_eta_dmf;
 TProfile *hNeutralHadronIsoPtSum_eta_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight1_eta_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight2_eta_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_eta_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_eta_dmf;
 TProfile *hChargedIsoPtSum_eta_dmf;
 TProfile *hNeutralIsoPtSum_eta_dmf;
 TProfile *hPUcorrPtSum_eta_dmf;

 TProfile *hNeutralIsoPtSumWeight1_phi_dmf;
 TProfile *hNeutralIsoPtSumWeight2_phi_dmf;
 TProfile *hNeutralIsoPtSumWeight1NQ_phi_dmf;
 TProfile *hNeutralIsoPtSumWeight2NQ_phi_dmf;
 TProfile *hNeutralHadronIsoPtSum_phi_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight1_phi_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight2_phi_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_phi_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_phi_dmf;
 TProfile *hChargedIsoPtSum_phi_dmf;
 TProfile *hNeutralIsoPtSum_phi_dmf;
 TProfile *hPUcorrPtSum_phi_dmf;

 TProfile *hNeutralIsoPtSumWeight1_vtx_dmf;
 TProfile *hNeutralIsoPtSumWeight2_vtx_dmf;
 TProfile *hNeutralIsoPtSumWeight1NQ_vtx_dmf;
 TProfile *hNeutralIsoPtSumWeight2NQ_vtx_dmf;
 TProfile *hNeutralHadronIsoPtSum_vtx_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight1_vtx_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight2_vtx_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf;
 TProfile *hChargedIsoPtSum_vtx_dmf;
 TProfile *hNeutralIsoPtSum_vtx_dmf;
 TProfile *hPUcorrPtSum_vtx_dmf;

 TProfile *hNeutralIsoPtSumWeight1_nGoodVtx_dmf;
 TProfile *hNeutralIsoPtSumWeight2_nGoodVtx_dmf;
 TProfile *hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf;
 TProfile *hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf;
 TProfile *hNeutralHadronIsoPtSum_nGoodVtx_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf;
 TProfile *hChargedIsoPtSum_nGoodVtx_dmf;
 TProfile *hNeutralIsoPtSum_nGoodVtx_dmf;
 TProfile *hPUcorrPtSum_nGoodVtx_dmf;







 //////////////////////////////////////////////////////


  TH1F *hNeutralIsoPtSumWeight1_Newdmf;
  TH1F *hNeutralIsoPtSumWeight2_Newdmf;
  TH1F *hNeutralIsoPtSumWeight1NQ_Newdmf;
  TH1F *hNeutralIsoPtSumWeight2NQ_Newdmf;
  TH1F *hNeutralHadronIsoPtSum_Newdmf;
  TH1F *hNeutralHadronIsoPtSumWeight1_Newdmf;
  TH1F *hNeutralHadronIsoPtSumWeight2_Newdmf;
 TH1F *hNeutralHadronIsoPtSumWeight1NQ_Newdmf;
 TH1F *hNeutralHadronIsoPtSumWeight2NQ_Newdmf;
 TH1F *hChargedIsoPtSum_Newdmf;
 TH1F *hNeutralIsoPtSum_Newdmf;
 TH1F *hPUcorrPtSum_Newdmf;

 TH1F *hFillDecayModeNewDM;
  TH1F *hFillDecayMode; 
 TProfile *hNeutralIsoPtSumWeight1_pt_Newdmf;
 TProfile *hNeutralIsoPtSumWeight2_pt_Newdmf;
 TProfile *hNeutralIsoPtSumWeight1NQ_pt_Newdmf;
 TProfile *hNeutralIsoPtSumWeight2NQ_pt_Newdmf;
 TProfile *hNeutralHadronIsoPtSum_pt_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight1_pt_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight2_pt_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_pt_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_pt_Newdmf;
 TProfile *hChargedIsoPtSum_pt_Newdmf;
 TProfile *hNeutralIsoPtSum_pt_Newdmf;
 TProfile *hPUcorrPtSum_pt_Newdmf;

 TProfile *hNeutralIsoPtSumWeight1_eta_Newdmf;
 TProfile *hNeutralIsoPtSumWeight2_eta_Newdmf;
 TProfile *hNeutralIsoPtSumWeight1NQ_eta_Newdmf;
 TProfile *hNeutralIsoPtSumWeight2NQ_eta_Newdmf;
 TProfile *hNeutralHadronIsoPtSum_eta_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight1_eta_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight2_eta_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_eta_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_eta_Newdmf;
 TProfile *hChargedIsoPtSum_eta_Newdmf;
 TProfile *hNeutralIsoPtSum_eta_Newdmf;
 TProfile *hPUcorrPtSum_eta_Newdmf;

 TProfile *hNeutralIsoPtSumWeight1_phi_Newdmf;
 TProfile *hNeutralIsoPtSumWeight2_phi_Newdmf;
 TProfile *hNeutralIsoPtSumWeight1NQ_phi_Newdmf;
 TProfile *hNeutralIsoPtSumWeight2NQ_phi_Newdmf;
 TProfile *hNeutralHadronIsoPtSum_phi_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight1_phi_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight2_phi_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_phi_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_phi_Newdmf;
 TProfile *hChargedIsoPtSum_phi_Newdmf;
 TProfile *hNeutralIsoPtSum_phi_Newdmf;
 TProfile *hPUcorrPtSum_phi_Newdmf;

 TProfile *hNeutralIsoPtSumWeight1_vtx_Newdmf;
 TProfile *hNeutralIsoPtSumWeight2_vtx_Newdmf;
 TProfile *hNeutralIsoPtSumWeight1NQ_vtx_Newdmf;
 TProfile *hNeutralIsoPtSumWeight2NQ_vtx_Newdmf;
 TProfile *hNeutralHadronIsoPtSum_vtx_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight1_vtx_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight2_vtx_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_vtx_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_vtx_Newdmf;
 TProfile *hChargedIsoPtSum_vtx_Newdmf;
 TProfile *hNeutralIsoPtSum_vtx_Newdmf;
 TProfile *hPUcorrPtSum_vtx_Newdmf;

 TProfile *hNeutralIsoPtSumWeight1_nGoodVtx_Newdmf;
 TProfile *hNeutralIsoPtSumWeight2_nGoodVtx_Newdmf;
 TProfile *hNeutralIsoPtSumWeight1NQ_nGoodVtx_Newdmf;
 TProfile *hNeutralIsoPtSumWeight2NQ_nGoodVtx_Newdmf;
 TProfile *hNeutralHadronIsoPtSum_nGoodVtx_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight1_nGoodVtx_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight2_nGoodVtx_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_Newdmf;
 TProfile *hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_Newdmf;
 TProfile *hChargedIsoPtSum_nGoodVtx_Newdmf;
 TProfile *hNeutralIsoPtSum_nGoodVtx_Newdmf;
 TProfile *hPUcorrPtSum_nGoodVtx_Newdmf ;

 ////////////////////////////////////////////////////
  TH1F  *TauPtResponse_LooseRho;


  TH1F  *RecoTauDecayMode_LooseRho;
  TH1F  *GenTauDecayMode_LooseRho;
  TH2F  *reco_dm_vs_gen_LooseRho;


 TH1F  *GenTauPtWithDMF_LooseRho;
 TH1F  *GenTauEtaWithDMF_LooseRho;
 TH1F  *GenTauPhiWithDMF_LooseRho;
//

  TH1F  *TauPtResponse_Iso1;
  TH1F  *RecoTauDecayMode_Iso1;
  TH1F  *GenTauDecayMode_Iso1;
  TH2F  *reco_dm_vs_gen_Iso1;
 TH1F  *GenTauPtWithDMF_Iso1;
 TH1F  *GenTauEtaWithDMF_Iso1;
 TH1F  *GenTauPhiWithDMF_Iso1;

         
  TH1F  *TauPtResponse_Iso2;
  TH1F  *RecoTauDecayMode_Iso2;
  TH1F  *GenTauDecayMode_Iso2;
  TH2F  *reco_dm_vs_gen_Iso2;
 TH1F  *GenTauPtWithDMF_Iso2;
 TH1F  *GenTauEtaWithDMF_Iso2;
 TH1F  *GenTauPhiWithDMF_Iso2;

  TH1F  *TauPtResponse_Iso4;
  TH1F  *RecoTauDecayMode_Iso4;
  TH1F  *GenTauDecayMode_Iso4;
  TH2F  *reco_dm_vs_gen_Iso4;
 TH1F  *GenTauPtWithDMF_Iso4;
 TH1F  *GenTauEtaWithDMF_Iso4;
 TH1F  *GenTauPhiWithDMF_Iso4;

 TH1F  *TauPtResponse_MediumRho;
TH1F  *RecoTauDecayMode_MediumRho;
TH1F  *GenTauDecayMode_MediumRho;
TH2F  *reco_dm_vs_gen_MediumRho;
 TH1F  *GenTauPtWithDMF_MediumRho;
 TH1F  *GenTauEtaWithDMF_MediumRho;
 TH1F  *GenTauPhiWithDMF_MediumRho;



TH1F  *TauPtResponse_TightRho;
TH1F  *RecoTauDecayMode_TightRho;
TH1F  *GenTauDecayMode_TightRho;
TH2F  *reco_dm_vs_gen_TightRho;
 TH1F  *GenTauPtWithDMF_TightRho;
 TH1F  *GenTauEtaWithDMF_TightRho;
 TH1F  *GenTauPhiWithDMF_TightRho;

  TH1F  *TauPtResponse_Cut;
 TH1F  *RecoTauDecayMode_Cut;
   TH1F  *GenTauDecayMode_Cut;
  TH2F  *reco_dm_vs_gen_Cut;

TH1F  *GenTauPtWithDMF_Cut;
  TH1F  *GenTauEtaWithDMF_Cut;
  TH1F  *GenTauPhiWithDMF_Cut;

 TH1F *hFillTauHcal3x3OverPLead_NewDMF;                   
 TH1F *FillHOverP_NewDMF ; 
 TH1F *FillEOverP_NewDMF;
 TH1F *FillGammaFraction_NewDMF;

TH1F *hFillTauHcal3x3OverPLead_DMF;                   
 TH1F *FillHOverP_DMF ; 
 TH1F *FillEOverP_DMF;
 TH1F *FillGammaFraction_DMF;

 TH1F *hFillTauHcal3x3OverPLead_before;                   
 TH1F *FillHOverP_before ; 
 TH1F *FillEOverP_before;
 TH1F *FillGammaFraction_before;

 TH1F *hFillTauHcal3x3OverPLead;                   
 TH1F *FillHOverP ; 
 TH1F *FillEOverP;
 TH1F *FillGammaFraction;


 TH1F *h_RunNumber ;
 TH1F *h_EventNumber;
 TH1F *h_LumiNumber;
 TH1F *h_BXNumber;

 TH1F *Nvtx_Den;
 TH1F *NGood_Den;
  
 TProfile *TES_DM ;
 TH1F *Nvtx_DM;
 TH1F *NGood_DM;

 TProfile *TES_ML2;
 TH1F *Nvtx_ML2;
 TH1F *NGood_ML2; 

 TProfile *TES_MM2;
 TH1F *Nvtx_MM2;
 TH1F *NGood_MM2;

 TProfile *TES_MT2;
 TH1F *Nvtx_MT2;
 TH1F *NGood_MT2;

 TProfile *TES_ML3;
 TH1F *Nvtx_ML3;
 TH1F *NGood_ML3;

 TProfile *TES_MT3 ;
 TH1F *Nvtx_MT3;
 TH1F *NGood_MT3;

 TProfile *TES_Iso1;
 TH1F *Nvtx_Iso1;
 TH1F *NGood_Iso1;

 TProfile *TES_Iso2;
 TH1F *Nvtx_Iso2; 
 TH1F *NGood_Iso2;

  TProfile *TES_Iso4 ;
  TH1F *Nvtx_Iso4 ;
  TH1F *NGood_Iso4;

  TProfile *TES_Cut;
  TH1F *Nvtx_Cut;
  TH1F *NGood_Cut;
  //seee
  TProfile *TES_EL3;
  TH1F *Nvtx_EL3;
  TH1F *NGood_EL3;

  TProfile *TES_EM3 ;
  TH1F *Nvtx_EM3;
  TH1F *NGood_EM3 ;

  TProfile *TES_ET3 ;
  TH1F *Nvtx_ET3 ;
  TH1F *NGood_ET3 ;
  

  TProfile *TES_VLChar;
  TH1F *Nvtx_VLChar;
  TH1F *NGood_VLChar;

  TProfile *TES_LChar ;
  TH1F *Nvtx_LChar ;
  TH1F *NGood_LChar ;

  TProfile *TES_MChar ;
  TH1F *Nvtx_MChar ;
  TH1F *NGood_MChar ;

  TProfile *TES_TChar ;
  TH1F *Nvtx_TChar ;
  TH1F *NGood_TChar ;

  TProfile *TES_LIso ;
  TH1F *Nvtx_LIso ; 
  TH1F *NGood_LIso ;


  TProfile *TES_MIso ;
  TH1F *Nvtx_MIso ; 
  TH1F *NGood_MIso ;

  TProfile *TES_TIso ;
  TH1F *Nvtx_TIso ;
  TH1F *NGood_TIso ;


  TProfile *TES_LIso3Hits;
  TH1F *Nvtx_LIso3Hits;
  TH1F *NGood_LIso3Hits;


  TProfile *TES_MIso3Hits;
  TH1F *Nvtx_MIso3Hits;
  TH1F *NGood_MIso3Hits;

  TProfile *TES_TIso3Hits;
  TH1F *Nvtx_TIso3Hits;
  TH1F *NGood_TIso3Hits;


  TProfile *TES_LooseRho;
  TH1F *Nvtx_LooseRho;
  TH1F *NGood_LooseRho;

  TProfile *TES_MediumRho ;
  TH1F *Nvtx_MediumRho;
  TH1F *NGood_MediumRho;

  
  TProfile *TES_TightRho;
  TH1F *Nvtx_TightRho;
  TH1F *NGood_TightRho;


  TH1F *TauPtResponse_Combined;
  TProfile *TES_Combined;
  TH1F *RecoTauDecayMode_Combined;
  TH1F *GenTauDecayMode_Combined;
  TH2F *reco_dm_vs_gen_Combined;
  TH1F *GenTauPtWithDMF_Combined;
  TH1F *GenTauEtaWithDMF_Combined;
  TH1F *GenTauPhiWithDMF_Combined;
  TH1F *Nvtx_Combined;
  TH1F *NGood_Combined;

  //
  TH1F *TauPtResponse_MIsoPtSum;
  TProfile *TES_MIsoPtSum;
  TH1F *RecoTauDecayMode_MIsoPtSum;
  TH1F *GenTauDecayMode_MIsoPtSum;
  TH2F *reco_dm_vs_gen_MIsoPtSum;
  TH1F *GenTauPtWithDMF_MIsoPtSum;
  TH1F *GenTauEtaWithDMF_MIsoPtSum;
  TH1F *GenTauPhiWithDMF_MIsoPtSum;
  TH1F *Nvtx_MIsoPtSum;
  TH1F *NGood_MIsoPtSum;

  TH1F *TauPtResponse_LIsoPtSum;
  TProfile *TES_LIsoPtSum;
  TH1F *RecoTauDecayMode_LIsoPtSum;
  TH1F *GenTauDecayMode_LIsoPtSum;
  TH2F *reco_dm_vs_gen_LIsoPtSum;
  TH1F *GenTauPtWithDMF_LIsoPtSum;
  TH1F *GenTauEtaWithDMF_LIsoPtSum;
  TH1F *GenTauPhiWithDMF_LIsoPtSum;
  TH1F *Nvtx_LIsoPtSum;
  TH1F *NGood_LIsoPtSum;

  TH1F *TauPtResponse_TIsoPtSum;
  TProfile *TES_TIsoPtSum;
  TH1F *RecoTauDecayMode_TIsoPtSum;
  TH1F *GenTauDecayMode_TIsoPtSum;
  TH2F *reco_dm_vs_gen_TIsoPtSum;
  TH1F *GenTauPtWithDMF_TIsoPtSum;
  TH1F *GenTauEtaWithDMF_TIsoPtSum;
  TH1F *GenTauPhiWithDMF_TIsoPtSum;
  TH1F *Nvtx_TIsoPtSum;
  TH1F *NGood_TIsoPtSum;



  TH1F *TauPtResponse_wLTloose;
  TProfile *TES_wLTloose;
  TH1F *RecoTauDecayMode_wLTloose;
  TH1F *GenTauDecayMode_wLTloose;
  TH2F *reco_dm_vs_gen_wLTloose;
  TH1F *GenTauPtWithDMF_wLTloose;
  TH1F *GenTauEtaWithDMF_wLTloose;
  TH1F *GenTauPhiWithDMF_wLTloose;
  TH1F *Nvtx_wLTloose;
  TH1F *NGood_wLTloose;


  TH1F *TauPtResponse_wLTvloose;
  TProfile *TES_wLTvloose;
  TH1F *RecoTauDecayMode_wLTvloose;
  TH1F *GenTauDecayMode_wLTvloose;
  TH2F *reco_dm_vs_gen_wLTvloose;
  TH1F *GenTauPtWithDMF_wLTvloose;
  TH1F *GenTauEtaWithDMF_wLTvloose;
  TH1F *GenTauPhiWithDMF_wLTvloose;
  TH1F *Nvtx_wLTvloose;
  TH1F *NGood_wLTvloose;



  TH1F *TauPtResponse_wLTmedium;
  TProfile *TES_wLTmedium;
  TH1F *RecoTauDecayMode_wLTmedium;
  TH1F *GenTauDecayMode_wLTmedium;
  TH2F *reco_dm_vs_gen_wLTmedium;
  TH1F *GenTauPtWithDMF_wLTmedium;
  TH1F *GenTauEtaWithDMF_wLTmedium;
  TH1F *GenTauPhiWithDMF_wLTmedium;
  TH1F *Nvtx_wLTmedium;
  TH1F *NGood_wLTmedium;



  TH1F *TauPtResponse_wLTtight;
  TProfile *TES_wLTtight;
  TH1F *RecoTauDecayMode_wLTtight;
  TH1F *GenTauDecayMode_wLTtight;
  TH2F *reco_dm_vs_gen_wLTtight;
  TH1F *GenTauPtWithDMF_wLTtight;
  TH1F *GenTauEtaWithDMF_wLTtight;
  TH1F *GenTauPhiWithDMF_wLTtight;
  TH1F *Nvtx_wLTtight;
  TH1F *NGood_wLTtight;



  TH1F *TauPtResponse_wLTvtight;
  TProfile *TES_wLTvtight;
  TH1F *RecoTauDecayMode_wLTvtight;
  TH1F *GenTauDecayMode_wLTvtight;
  TH2F *reco_dm_vs_gen_wLTvtight;
  TH1F *GenTauPtWithDMF_wLTvtight;
  TH1F *GenTauEtaWithDMF_wLTvtight;
  TH1F *GenTauPhiWithDMF_wLTvtight;
  TH1F *Nvtx_wLTvtight;
  TH1F *NGood_wLTvtight;


  TH1F *TauPtResponse_wLTvvtight;
  TProfile *TES_wLTvvtight;
  TH1F *RecoTauDecayMode_wLTvvtight;
  TH1F *GenTauDecayMode_wLTvvtight;
  TH2F *reco_dm_vs_gen_wLTvvtight;
  TH1F *GenTauPtWithDMF_wLTvvtight;
  TH1F *GenTauEtaWithDMF_wLTvvtight;
  TH1F *GenTauPhiWithDMF_wLTvvtight;
  TH1F *Nvtx_wLTvvtight;
  TH1F *NGood_wLTvvtight;


  //


  TH1F *TauPtResponse_woLTloose;
  TProfile *TES_woLTloose;
  TH1F *RecoTauDecayMode_woLTloose;
  TH1F *GenTauDecayMode_woLTloose;
  TH2F *reco_dm_vs_gen_woLTloose;
  TH1F *GenTauPtWithDMF_woLTloose;
  TH1F *GenTauEtaWithDMF_woLTloose;
  TH1F *GenTauPhiWithDMF_woLTloose;
  TH1F *Nvtx_woLTloose;
  TH1F *NGood_woLTloose;


  TH1F *TauPtResponse_woLTvloose;
  TProfile *TES_woLTvloose;
  TH1F *RecoTauDecayMode_woLTvloose;
  TH1F *GenTauDecayMode_woLTvloose;
  TH2F *reco_dm_vs_gen_woLTvloose;
  TH1F *GenTauPtWithDMF_woLTvloose;
  TH1F *GenTauEtaWithDMF_woLTvloose;
  TH1F *GenTauPhiWithDMF_woLTvloose;
  TH1F *Nvtx_woLTvloose;
  TH1F *NGood_woLTvloose;



  TH1F *TauPtResponse_woLTmedium;
  TProfile *TES_woLTmedium;
  TH1F *RecoTauDecayMode_woLTmedium;
  TH1F *GenTauDecayMode_woLTmedium;
  TH2F *reco_dm_vs_gen_woLTmedium;
  TH1F *GenTauPtWithDMF_woLTmedium;
  TH1F *GenTauEtaWithDMF_woLTmedium;
  TH1F *GenTauPhiWithDMF_woLTmedium;
  TH1F *Nvtx_woLTmedium;
  TH1F *NGood_woLTmedium;



  TH1F *TauPtResponse_woLTtight;
  TProfile *TES_woLTtight;
  TH1F *RecoTauDecayMode_woLTtight;
  TH1F *GenTauDecayMode_woLTtight;
  TH2F *reco_dm_vs_gen_woLTtight;
  TH1F *GenTauPtWithDMF_woLTtight;
  TH1F *GenTauEtaWithDMF_woLTtight;
  TH1F *GenTauPhiWithDMF_woLTtight;
  TH1F *Nvtx_woLTtight;
  TH1F *NGood_woLTtight;



  TH1F *TauPtResponse_woLTvtight;
  TProfile *TES_woLTvtight;
  TH1F *RecoTauDecayMode_woLTvtight;
  TH1F *GenTauDecayMode_woLTvtight;
  TH2F *reco_dm_vs_gen_woLTvtight;
  TH1F *GenTauPtWithDMF_woLTvtight;
  TH1F *GenTauEtaWithDMF_woLTvtight;
  TH1F *GenTauPhiWithDMF_woLTvtight;
  TH1F *Nvtx_woLTvtight;
  TH1F *NGood_woLTvtight;


  TH1F *TauPtResponse_woLTvvtight;
  TProfile *TES_woLTvvtight;
  TH1F *RecoTauDecayMode_woLTvvtight;
  TH1F *GenTauDecayMode_woLTvvtight;
  TH2F *reco_dm_vs_gen_woLTvvtight;
  TH1F *GenTauPtWithDMF_woLTvvtight;
  TH1F *GenTauEtaWithDMF_woLTvvtight;
  TH1F *GenTauPhiWithDMF_woLTvvtight;
  TH1F *Nvtx_woLTvvtight;
  TH1F *NGood_woLTvvtight;

//


//
// static data member definitions
//

//
// constructors and destructor
};
#endif
