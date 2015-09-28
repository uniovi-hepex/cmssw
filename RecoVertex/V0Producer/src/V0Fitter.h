// -*- C++ -*-
//
// Package:    V0Producer
// Class:      V0Fitter
// 
/**\class V0Fitter V0Fitter.h RecoVertex/V0Producer/interface/V0Fitter.h

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Brian Drell
//         Created:  Fri May 18 22:57:40 CEST 2007
//
//

#ifndef RECOVERTEX__V0_FITTER_H
#define RECOVERTEX__V0_FITTER_H

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "RecoVertex/KalmanVertexFit/interface/KalmanVertexFitter.h"
#include "RecoVertex/AdaptiveVertexFit/interface/AdaptiveVertexFitter.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "MagneticField/VolumeBasedEngine/interface/VolumeBasedMagneticField.h"
#include "DataFormats/Candidate/interface/VertexCompositeCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidate.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "Geometry/CommonDetUnit/interface/TrackingGeometry.h"
#include "Geometry/CommonDetUnit/interface/GeomDetUnit.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/TrackerGeometryBuilder/interface/GluedGeomDet.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
#include "DataFormats/TrackingRecHit/interface/TrackingRecHit.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "CommonTools/CandUtils/interface/AddFourMomenta.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/PatternTools/interface/ClosestApproachInRPhi.h"
#include "Geometry/CommonDetUnit/interface/GlobalTrackingGeometry.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "TrackingTools/TrajectoryState/interface/TrajectoryStateTransform.h"
#include "TrackingTools/PatternTools/interface/TSCBLBuilderNoMaterial.h"
#include <Math/Functions.h>
#include <Math/SVector.h>
#include <Math/SMatrix.h>
#include <typeinfo>
#include <memory>
#include <TVector3.h>
#include "DataFormats/VertexReco/interface/Vertex.h"

class dso_hidden V0Fitter {

   public:
      V0Fitter(const edm::ParameterSet& theParams, edm::ConsumesCollector && iC);
      void fitAll(const edm::Event& iEvent, const edm::EventSetup& iSetup,
         reco::VertexCompositeCandidateCollection & k, reco::VertexCompositeCandidateCollection & l);

   private:

      bool vertexFitter_;
      bool useRefTracks_;
      bool doKShorts_;
      bool doLambdas_;

      // cuts on initial track selection
      double tkChi2Cut_;
      int tkNHitsCut_;
      double tkPtCut_;
      double tkIPSigXYCut_;
      double tkIPSigZCut_;
      // cuts on the vertex
      double vtxChi2Cut_;
      double vtxDecaySigXYCut_;
      double vtxDecaySigXYZCut_;
      // miscellaneous cuts
      double tkDCACut_;
      double mPiPiCut_;
      double innerHitPosCut_;
      double cosThetaXYCut_;
      double cosThetaXYZCut_;
      // cuts on the V0 candidate mass
      double kShortMassCut_;
      double lambdaMassCut_;

      edm::EDGetTokenT<reco::TrackCollection> token_tracks;
      edm::EDGetTokenT<reco::BeamSpot> token_beamSpot;
      bool useVertex_;
      edm::EDGetTokenT<std::vector<reco::Vertex>> token_vertices;
};

#endif

