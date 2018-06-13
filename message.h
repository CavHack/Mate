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

};

struct GetInclusionsStatesResponse {
    std::vector<bool> states; //decision tree
}



}