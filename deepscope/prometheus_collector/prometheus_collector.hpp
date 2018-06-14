#pragma once

#include <Prometheus/exposer.h>
#include <Mate/deepscope/collector/collector.hpp>
#include <string>

namespace mate {
    namespace deepscope {
        class PrometheusCollector : Public CollectorBase {
            public:
            constexpr static auto PROMETHEUS_EXPOSER_URI = "prometheus_exposer_uri";

            //typedef
            typedef std::map<std::string, std::reference_wrapper<
            prometheus::Family<prometheusCounter>>>

            CountersMap;

            typedef std::map<std::string, std::reference_wrapper<prometheus::Family<prometheus::Gauge>>>

            GaugeMap;

            typedef std::map<std::string, std::reference_wrapper<prometheus::Family<prometheus::Histogram>>>

            HistogramsMap;

            // methods
            bool parseConfiguration(const YAML::Node& conf) override;

            static HistogramsMap buildHistogramsMap(
                std::shared_ptr<prometheus::Registry> registry,
                const std::string& metricName,
                const std::map<std::string, std::string>& labels,
                const std::map<std::string, std::string>& nameToDesc);
        }
    }
}