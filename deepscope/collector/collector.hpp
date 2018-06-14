#pragma once

#include <string>
#include <yaml-cpp/yaml.h>

namespace mate {
    namespace deepscope {

        class CollectorBase {
            public:
            virtual ~CollectorBase();
            virtual void collect() = 0;
            virtual bool parseConfiguration(const YAML::Node& conf);
        };

    }
}