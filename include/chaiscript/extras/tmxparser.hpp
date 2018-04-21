#include <string>

#include <chaiscript/chaiscript.hpp>

#include <TmxMap.h>

namespace chaiscript {
  namespace extras {
    namespace tmxparser {
      ModulePtr bootstrap(ModulePtr m = std::make_shared<Module>())
      {
        // Map
        m->add(user_type<Tmx::Map>(), "TmxMap");
        m->add(fun(&Tmx::Map::GetVersion), "GetVersion");
        m->add(fun(&Tmx::Map::GetWidth), "GetWidth");
        m->add(fun(&Tmx::Map::GetHeight), "GetHeight");
        return m;
      }
    }
  }
}
