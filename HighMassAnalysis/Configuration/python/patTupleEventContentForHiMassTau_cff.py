import FWCore.ParameterSet.Config as cms

from PhysicsTools.PatAlgos.patEventContent_cff import *
from Configuration.EventContent.EventContent_cff import *

patTupleEventContent = [
    'keep source_*_*_*',
    'keep *_source_*_*',
    'keep edmHepMCProduct_generator_*_*',
    'keep edmHepMCProduct_generator_*_*',   
    'keep *_*_source_*',
    'keep *_*_*_source',
    'keep *_patElectrons_*_*',
    'drop *_heepPatElectrons_*_*',
    'keep *_patMuons_*_*',
    'keep patJet*_selectedPatJets_*_*',
    'keep *_patTaus_*_*',
    'keep *_pfType1CorrectedMet_*_*',
    'keep *_pfType1p2CorrectedMet_*_*',
    'keep recoGenParticles_genParticles*_*_*',
    'keep GenEventInfoProduct_*_*_*',
    'keep GenRunInfoProduct_*_*_*',
    'keep recoTracks_generalTracks*_*_*',
    'keep *_towerMaker_*_*',
    'keep *_offlineBeamSpot_*_*',
    'keep *_offlinePrimaryVertices*_*_*',
    'keep edmTriggerResults_TriggerResults*_*_*',
    'keep *_hltTriggerSummaryAOD_*_*',
    'keep L1GlobalTriggerReadoutRecord_gtDigis_*_*',
    'keep edmConditionsIn*Block_conditionsInEdm_*_*',
    'keep patTriggerAlgorithms_patTrigger_*_*',
    'keep patTriggerConditions_patTrigger_*_*',
    'keep patTriggerObjects_patTrigger_*_*',
    'keep patTriggerFilters_patTrigger_*_*',
    'keep patTriggerPaths_patTrigger_*_*',
    'keep *_patTriggerEvent_*_*',
    'keep *_TriggerResults_*_*',
    'keep *_hcalnoise_*_*',
    'keep recoPFCandidate*_particleFlow__*',
    'keep recoTracks_generalTracks_*_*',
    'keep recoTrackExtras_generalTracks_*_*',
    'keep recoMuons_muons_*_*',
    'keep booledmValueMap_muid*_*_*',
    'keep *_patMETs_*_*',
    'keep patMET*_*_*_*',
    'keep *_ak5GenJets_*_*',
    'keep *_genMetTrue_*_*',
    'keep *_generator_*_*',      
    'keep DcsStatuss_scalersRawToDigi_*_*',
    'keep *_hpsPFTau*_*_PATTuple',
    'keep *_ak5PFJetsLegacyHPSPiZeros_*_*',
    'keep recoPFCandidates_particleFlow_*_*',
    'keep *_ak5PFJets_*_*',
    'keep *_tauGenJets*_*_*',
    'keep *_hltL1GtObjectMap_*_*',
    'keep edmTriggerResults_*_*_*',
    'keep triggerTriggerEvent_*_*_*',
    'keep *_*IsoDeposit*_*_*',
    'keep *_*IsoValue*_*_*',
    'keep *_addPileupInfo_*_*',
    'keep *_ak5PFJets_rho_*',
    'keep *_iterativeCone5PFJets_rho_*',
    'keep *_kt6PFJets*_rho_*',
    'keep *Cores_gsf*_*_*',
    'keep recoGsfElectron*_gsfElectrons_*_*',
    'drop recoPFCandidate*_selectedPatJets_pfCandidates_*',
    'drop *_selectedPatJets_genJets_*',
    'drop *_*PF_caloTowers_*',
    'drop *_*JPT_pfCandidates_*',
    'drop *_*Calo_pfCandidates_*',
    'drop *_hlt*_*_*',
    'drop CaloTowers*_*_*_*',
    'drop patPhotons_*_*_*',
    'drop *_cleanPatJets_*_*',
    'drop *_ak5PFJetsRecoTauPiZeros_*_*',
    'drop recoSuperCluster*_*_*_*',
    'drop *_muIsoDeposit*_*_RECO',
]