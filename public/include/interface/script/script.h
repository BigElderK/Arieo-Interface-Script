#pragma once

#include "base/interop/interface.h"
#include <filesystem>
#include <string>
#include <vector>
#include <functional>
#include <memory>
#include <variant>

namespace Arieo::Interface::Script
{
    // Forward declarations
    class IContext;
    class IModule;
    class IInstance;
    class IInterface;
    
    class IContext
    {
    public:
        virtual void addHostFunction(
            const std::string& module_name,
            const std::string& function_name,
            const std::function<void()>& function
        ) = 0;
    };

    class IModule
    {
    public:
    };

    class IInstance
    {
    public:
        virtual void* queryInterface(const std::string& interface_name) = 0;
        virtual void* queryFunction(void* interface, const std::string& function_name) = 0;
        virtual void callFunction(
            void*) = 0;
    };

    class IScriptEngine
    {
    public:
        virtual Base::InteropOld<IContext> createContext() = 0;
        virtual void destroyContext(Base::InteropOld<IContext> context) = 0;

        virtual void initInterfaceLinkers(const std::filesystem::path& lib_file_path) = 0;
        
        virtual Base::InteropOld<IModule> loadModuleFromWatString(const std::string& wat_string) = 0;
        virtual Base::InteropOld<IModule> loadModuleFromCompiledBinary(void* binary_data, size_t data_size) = 0;
        virtual void unloadModule(Base::InteropOld<IModule> module) = 0;

        virtual Base::InteropOld<IInstance> createInstance(Base::InteropOld<IContext> context, Base::InteropOld<IModule> module) = 0;
        virtual void destroyInstance(Base::InteropOld<IInstance> instance) = 0;
    };
}