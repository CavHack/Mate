#pragma once

#include <prometheus/exposer.h>
#include <boost/thread/executor.hpp>
#include <chrono>
#include <mate/deepscope/common/irimate.hpp>
#include <mate/deepscope/prometheus_collector/promehteus_collector.hpp>
#include <rx.hpp>
#include <string>
#include <list>



namespace mate {

  namespace deepscope {
    class RoundRobinCollector: public PrometheusCollector {


    public:
      constexpr static auto PUBLISHER = "publisher";
      constexpr static auto SNAPSHOT_INTERVAL= "snapshot_interval";
      constexpr static auto HISTOGRAM_RANGE = "histogram_range";
      constexpr static auto BUCKET_SIZE = "bucket_size";

      constexpr static auto TX_NUM_APPROVERS = "tx_num_approvers";
      constexpr static uint8_t EXPIARY_PERIOD = 240; /*seconds*/
      constexpr static uint8_t MAX_NUM_MILESTONES = 30;

      using ZmqObservable = rxcpp::observable<std::shared_ptr<irimate::IRIMateMessage>>;
      void collect() override;
      bool parseConfiguration(const YAML::Nodes& conf) override;

      void refCountPublishedTransactions();
      void analyzeRoundRobinCollectorPeriodically();

    private:
      // methods
      void analyzeRoundRobingCollector (const std::vector<double>& buckets);





      //config
      std::string _zmqPublisher;
      uint32_t _snapshotInterval;

      ZmqObservable _zmqObservable;
      PrometheusCollector::HistogramsMap histograms;

      //state
      cuckoohash_map<std::string, uint8_t> _txToRefCount;
      cuckoohash_map<std::string, std::chrono::system_clock::time_point> _txToLastUpdateTime;
      std::list<std::string> _milestones;

      uint32_t _histogranRange;
      uint32_t _bucketSize;

      static std::map<std::string, std::string> nameToDescHistogram;
    };


}


}
