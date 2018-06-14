#include <deepscope/collector/collector.hpp>

namespace mate {

    namespace deepscope {
        CollectorBase::~CollectorBase() {

        }

        bool CollectorBase::parseConfiguration(const YAML::Node &conf) {
            if (!conf) {
                return false;
            }

            return true;
        }
    }

}