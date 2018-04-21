#include <string>

#include <chaiscript/chaiscript.hpp>

#include <TmxMap.h>
#include <TmxColor.h>

using Tmx::Color;
using Tmx::Map;

namespace chaiscript {
  namespace extras {
    namespace tmxparser {

      ModulePtr addColor(ModulePtr m = std::make_shared<Module>()) {
        m->add(user_type<Color>(), "TmxColor");
        m->add(constructor<Color()>(), "TmxColor");
        m->add(constructor<Color(uint32_t)>(), "TmxColor");
        m->add(constructor<Color(uint8_t, uint8_t, uint8_t, uint8_t)>(), "TmxColor");
        m->add(constructor<Color(const std::string&)>(), "TmxColor");
        m->add(fun(&Color::GetAlpha), "GetAlpha");
        m->add(fun(&Color::GetRed), "GetRed");
        m->add(fun(&Color::GetGreen), "GetGreen");
        m->add(fun(&Color::GetBlue), "GetBlue");
        m->add(fun(&Color::IsTransparent), "IsTransparent");
        m->add(fun(&Color::ToInt), "ToInt");
        m->add(fun(&Color::ToString), "ToString");

        return m;
      }

      /**
       * Adds the Map to the ChaiScript module.
       */
      ModulePtr addMap(ModulePtr m = std::make_shared<Module>()) {
        m->add(user_type<Map>(), "TmxMap");
        m->add(constructor<Map()>(), "TmxMap");
        m->add(fun(&Map::ParseFile), "ParseFile");
        m->add(fun(&Map::ParseText), "ParseText");
        m->add(fun(&Map::GetFilename), "GetFilename");
        m->add(fun(&Map::GetFilepath), "GetFilepath");
        m->add(fun(&Map::GetVersion), "GetVersion");
        m->add(fun(&Map::GetWidth), "GetWidth");
        m->add(fun(&Map::GetHeight), "GetHeight");
        m->add(fun(&Map::GetTileWidth), "GetTileWidth");
        m->add(fun(&Map::GetTileHeight), "GetTileHeight");
        m->add(fun(&Map::GetNextObjectId), "GetNextObjectId");
        m->add(fun(&Map::GetHexsideLength), "GetHexsideLength");
        m->add(fun(&Map::GetNumLayers), "GetNumLayers");
        m->add(fun(&Map::GetNumTileLayers), "GetNumTileLayers");
        m->add(fun(&Map::GetNumObjectGroups), "GetNumObjectGroups");
        m->add(fun(&Map::GetNumImageLayers), "GetNumImageLayers");
        m->add(fun(&Map::GetNumGroupLayers), "GetNumGroupLayers");
        m->add(fun(&Map::FindTilesetIndex), "FindTilesetIndex");
        m->add(fun(&Map::GetNumTilesets), "GetNumTilesets");
        m->add(fun(&Map::HasError), "HasError");
        m->add(fun(&Map::GetErrorCode), "GetErrorCode");
        m->add(fun(&Map::GetBackgroundColor), "GetBackgroundColor");

        // TODO: Add the remaining functions.
        //Tmx::MapOrientation GetOrientation()
        //Tmx::MapRenderOrder GetRenderOrder() const { return render_order; }
        //Tmx::MapStaggerAxis GetStaggerAxis() const { return stagger_axis; }
        //Tmx::MapStaggerIndex GetStaggerIndex() const { return stagger_index; }
        //const Tmx::Layer *GetLayer(int index) const { return layers.at(index); }
        //const std::vector< Tmx::Layer* > &GetLayers() const { return layers; }
        //const Tmx::TileLayer *GetTileLayer(int index) const { return tile_layers.at(index); }
        //const std::vector< Tmx::TileLayer* > &GetTileLayers() const { return tile_layers; }
        //const Tmx::ObjectGroup *GetObjectGroup(int index) const { return object_groups.at(index); }
        //const std::vector< Tmx::ObjectGroup* > &GetObjectGroups() const { return object_groups; }
        //const Tmx::ImageLayer *GetImageLayer(int index) const { return image_layers.at(index); }
        //const std::vector< Tmx::ImageLayer* > &GetImageLayers() const { return image_layers; }
        //const Tmx::GroupLayer *GetGroupLayer(int index) const { return group_layers.at(index); }
        //const std::vector< Tmx::GroupLayer* > &GetGroupLayers() const { return group_layers; }
        //const Tmx::Tileset *FindTileset(int gid) const;
        //const Tmx::Tileset *GetTileset(int index) const { return tilesets.at(index); }
        //const std::vector< Tmx::Tileset* > &GetTilesets() const { return tilesets; }
        //const std::string &GetErrorText() const { return error_text; }
        //const Tmx::PropertySet &GetProperties() const { return properties; }

        return m;
      }

      /**
       * Bootstrap a module with TmxParser support.
       */
      ModulePtr bootstrap(ModulePtr m = std::make_shared<Module>())
      {
        addColor(m);
        addMap(m);

        return m;
      }
    }
  }
}
