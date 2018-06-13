#ifndef MATE_DEEPCLIENT_API_H
#define MATE_DEEPCLIENT_API_H

#include<chrono>
#include<cstdint>
//#include<nonstd/optional.hpp>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
#include "message.h"

namespace deepclient {

    struct Transaction {

        public:
        std::string hash;
        std::string address;
        int64_t value;
        std::chrono::system_clock::time_point timestamp;
        int64_t currentIndex;
        int64_t lastIndex;
        std::string bundleHash;
        std::string trunk;

};

struct NodeInfo {

public:
std::string latestMilestone;
uint64_t latestMilestoneIndex;
uint64_t latestSolidMilestoneIndex;


};

using Bundle = std::vector<Transaction>;

/// IotaAPI class.
/// Provides an API to the tangle. The following API are available:
/// - isNodeSolid
/// - getBalances
/// - getConfirmedBundlesForAddress
/// - filterConfirmedTails
/// - filterConsistentTails
/// - findTransactions
/// - getNodeInfo
/// - getTransactions
/// - attachToTangle
/// - getTransactionsToApprove
/// - storeTransactions
/// - broadcastTransactions

class MateAPI {

    public:
    virtual bool isNodeSolid() = 0;

    virtual std::unordered_map<std::string, uint64_t> getBalances(
        const std::vector<std::string>& addresses
    ) = 0;

    virtual std::unordered_multimap<std::string, Bundle>
    getConfirmedBundlesdForAddresses(
        const std::vector<std::string>& tails, 
        const nonstd::optional<std::string>& reference) =0;
    

    }


}