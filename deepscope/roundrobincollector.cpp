#include <glog/logging.h>
#include <set>

#include <mate/deepscope/roundrobincollector.hpp>
#include <mate/deepscope/common/zmqpub.hpp>

using namespace mate::deepscope;

std::map<std::string, std::string> RoundRobinCollector:nametoDescHistogram = {

{RoundRobinCollector::TX_NUM_APPROVERS,
"Number of transactions directly approving a single transaction"}};

bool RoundrobinCollector::parseConfiguration(const YAML::Node& conf) {

  if (!PrometheusCollector::parseConfiguration(conf)) {
    return false;
  }

  if (!conf[SNAPSHOT_INTERVAL] || !conf[PUBLISHER] || !conf[HISTOGRAM_RANGE] ||
      !conf[BUCKET_SIZE]) {
    return false;

  }

  _zmqPublisher = conf[PUBLISHER].as<std::string>();
  _snapshotInterval = conf[SNAPSHOT_INTERVAL].as<uint32_t>();
 _histogramRange = conf[HISTOGRAM_RANGE]

}
