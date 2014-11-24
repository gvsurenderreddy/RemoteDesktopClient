#include <math.h>
#include <stdio.h>
#include <string>

#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/var.h"
#include "ppapi/cpp/var_dictionary.h"

#ifdef WIN32
#undef PostMessage
// Allow 'this' in initializer list
#pragma warning(disable : 4355)
#endif

namespace {
const char* kHelloMessage = "Hello from NaCl module";
}  // namespace


class RDPModuleInstance : public pp::Instance 
{
public:
    explicit RDPModuleInstance(PP_Instance instance)
        : pp::Instance(instance) {}

    virtual bool Init(uint32_t argc, const char* argn[], const char* argv[])
    {
        PostMessage(kHelloMessage);
        return true;
    }

private:
    virtual void HandleMessage(const pp::Var& inMessage)
    {
		if (!inMessage.is_dictionary()) 
		{
			return;
		}

		pp::VarDictionary dictMessage(inMessage);
		pp::Var loginInMessage = dictMessage.Get("login");
		if (!loginInMessage.is_string()) 
		{
			return;
		}

		std::string replyMessage("Message received: ");
		replyMessage.append(loginInMessage.AsString());
        PostMessage(replyMessage);
    }
};


class RDPModule : public pp::Module 
{
public:
    RDPModule() : pp::Module() {}
    virtual ~RDPModule() {}

    virtual pp::Instance* CreateInstance(PP_Instance instance)
    {
        return new RDPModuleInstance(instance);
    }
};


namespace pp 
{
Module* CreateModule() 
{ 
    return new RDPModule();
}
}  // namespace pp
