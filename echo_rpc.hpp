/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * Copyright (c) 2014 Xabyss Inc. All rights reserved.
 */

#pragma once

#include <memory>
#include <string>
#include <mutex>
#include <condition_variable>

#include "rpc_base.hpp"

namespace pca {

class echo_rpc : public xa::rpc_base {
public:
    echo_rpc(const std::string& address, unsigned short port);
    virtual bool serve(const Json::Value &req, Json::Value* res);

private:
    bool serve_ping(const Json::Value& params, Json::Value* res);
};

}  // namespace pca
