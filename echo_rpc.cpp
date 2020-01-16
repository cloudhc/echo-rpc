/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * Copyright (c) 2014 Xabyss Inc. All rights reserved.
 */

#include <inttypes.h>
#include <list>
#include <vector>

#include "echo_rpc.hpp"

namespace pca {

#define NTHREADS 4

echo_rpc::echo_rpc(const std::string& address, unsigned short port)
    : rpc_base(address, port, NTHREADS)
{
}

bool echo_rpc::serve(const Json::Value& req, Json::Value* res)
{
    std::string method = req["method"].asString();

    if ("ping" == method) {
        return serve_ping(req["params"], res);
    } else {
        return serve_method_not_found(req["params"], res);
    }

    return true;
}

bool echo_rpc::serve_ping(const Json::Value& params, Json::Value* res)
{
    (*res)["message"] = "pong";
    (*res)["params"] = params;

    return true;
}

}  // namespace pca
