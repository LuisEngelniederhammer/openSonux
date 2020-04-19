#include "MiddlewareStack.hpp"

#include "../lib/easyloggingcpp/easylogging++.h"

void MiddlewareStack::push(MiddlewareInvocation *middleware)
{
    middlewares.push(middleware);
    LOG(TRACE) << "Added " << typeid(*middleware).name();
}

void MiddlewareStack::execute()
{
    while (!middlewares.empty())
    {
        MiddlewareInvocation *invocation = middlewares.top();
        LOG(TRACE) << "Execute " << typeid(*invocation).name();
        invocation->invoke(nullptr, nullptr);
        middlewares.pop();
    }
}