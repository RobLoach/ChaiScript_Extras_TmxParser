#include <string>

#include <chaiscript/chaiscript.hpp>

#include <TmxMap.h>

using namespace Tmx;

namespace chaiscript {
  namespace extras {
    namespace tmxparser {
      ModulePtr bootstrap(ModulePtr m = std::make_shared<Module>())
      {
        // Map
        m->add(user_type<Map>(), "TmxMap");
        //m->add(chaiscript::bootstrap::basic_constructors<Map>("TmxMap"));
        m->add(constructor<Tmx::Map()>(), "TmxMap");
        m->add(fun(&Map::GetVersion), "GetVersion");
        m->add(fun(&Map::GetWidth), "GetWidth");
        m->add(fun(&Map::GetHeight), "GetHeight");
        return m;
      }
    }
  }
}
