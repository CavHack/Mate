#pragma once

#include <prometheus/exposer.h>
#include <boost/thread/executor.hpp>
#include <boost/thread/future.hpp>
#include <chrono>
#include <mate/deepscope/common/irimate.hpp>
#include <mate/deepscope/prometheus_collector/prometheus_collector.hpp>
#include <libcuckoo/cuckoohash_map.hh>
#include <list>
#include <memory>
#include <rx.hpp>
#include <shared_mutex>
#include <string>

#include "cppClient/beast.h"

namespace mate {
  namespace deepscope {

    class ShellSelectionCollector : public PrometheusCollector {

    public:
      constexpr static auto IRI_HOST = "iri_host";
      constexpr static auto IRI_PORT = "iri_port";
      constexpr static auto SAMPLE_INTERVAL = "sample_interval";
      constexpr static auto SAMPLE_SIZE = "sample_size";
      constexpr static auto DEPTH = "depth";
      constexpr static auto DURATION_BUCKET_SIZE = "duration_bucket_size";
      constexpr static auto DURATION_HISTOGRAM_RANGE = "duration_histogram_range";

      //name the metrics
      constexpr static auto NUM_TX_WAS_SELECTED = "num_tx_was_selected";
      constexpr static auto NUM_TRUNK_EQ_BRANCH = "num_trunk_eq_branch";
      constexpr static auto NUM_TX_WAS_NOT_A_TIP = "num_tx_was_not_a_tip";

      
    }


  }


}
