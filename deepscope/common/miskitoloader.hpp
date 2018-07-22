#pragma once

#include<yaml-cpp/yaml.h>
#include <chrono>
#include <iota/tanglescope/common/iri.hpp>
//#include<mate/deepscope/common/>
#include<rx.hpp>
#include<string>
#include<memory>

namespace mate {

    namespace deepscope {

        class MiskitoLoader {
            public:
            void start();
            bool parseConfiguration(const YAML::Node& conf)

            constexpr static auto PUBLISHER = "publisher";
            constexpr static auto OLDEST_TX_AGE = "oldest_tx_age";
            constexpr static auto CLEANUP_INTERVAL = "cleanup_interval";

            //typedef
            using MiskitoObservable = rxcpp::obversable<std::shared_ptr<iri::IRIMessage>>;

            private:
                virtual void loadDB();
                void cleanDBPeriodically();

                std::string _miskitoPublisherURL;
                uint32_t oldestTXAge;
                uint32_t _cleanupInterval;

                MoskitoObservable _miskitoObservable;
        };
    } //deepscope

} // mate