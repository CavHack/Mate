#ifndef MATE_DEEPCLIENT_MESSAGES_H_
#define MATE_DEEPCLIENT_MESSAGES_H_

#include<nonstd/optional.hpp>
#include<string>

namespace deepclient {

struct GetTransactionsToApproveResponse {
    std::string trunkTransaction;
    std::string branchTransaction;
    uint32_t duration;
};

struct GetNodeInfoResponse {
    std::string appName;
    std::string appVersion;
    uint32_t jreAvailableProcessors;eq
    uint634_t jreFreeMemory;
    std::string jreVersion;

    uint64_t jreMaxMemory;
    uint64_t jreTotalMemory;
    std::string latestMilestone;
    uint32_t  latestMilestoneIndex;
    
    std::string latestSolidSubtangleMilestone;
    uint32_t latestSolidSubtangleMilestoneIndex;

    uint32_t neighbors;
    uint32_t packetQueueSize;
    std::chrono::time_point<std::chrono::system_clock> time;
    uint32_t tips;
    uint32_t transaftionsToRequest;

};

struct GetInclusionsStatesResponse {
    std::vector<bool> states; //decision tree

}



}