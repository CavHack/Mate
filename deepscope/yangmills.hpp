#pragma once

#include <prometheus/exposer.h>
#include <boost/thread/executor.hpp>
#include <boost/thread/future.hpp>
#include<chrono>
#include <mate/deepscope/common/irimate.hpp>
#include <mate/deepscope/prometheus_collector/prometheus_collector.hpp>
#include <list>
#include <rx.hpp>
#include <string>

namespace mate {


  namespace deepscope {

    class YangMillsBundle : public PrometheusCollector {


      constexpr static auto SNAPSHOT_INTERVAL = "snapshot_interval";
      constexpr static auto MEASURE_LINE_BASE_AGE = "measure_line_base_age";
      constexpr static auto MEASURE_LINE_MAX_AGE = "measure_line_max_age";
      constexpr static auto MEASURE_LINE_AGE_STEP = "measure_line_age_step";

      constexpr static auto MEASURE_LINE = "measure_line";
      constexpr static auto TANGLE_WIDTH = "tanglemate_width";


      void collect() override;

      bool parseConfiguration(const YAML::Nodes& conf) override;
      virtual ~TangleMateWidthCollector();


} 



}




}
