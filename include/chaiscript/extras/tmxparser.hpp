#include <string>

#include <chaiscript/chaiscript.hpp>

#include <TmxMap.h>
#include <TmxColor.h>

using namespace Tmx;

namespace chaiscript {
  namespace extras {
    namespace tmxparser {

      ModulePtr addLayer(ModulePtr m = std::make_shared<Module>()) {
        // LayerType
        m->add_global_const(const_var(TMX_LAYERTYPE_TILE), "TMX_LAYERTYPE_TILE");
        m->add_global_const(const_var(TMX_LAYERTYPE_OBJECTGROUP), "TMX_LAYERTYPE_OBJECTGROUP");
        m->add_global_const(const_var(TMX_LAYERTYPE_IMAGE_LAYER), "TMX_LAYERTYPE_IMAGE_LAYER");
        m->add_global_const(const_var(TMX_LAYERTYPE_GROUP_LAYER), "TMX_LAYERTYPE_GROUP_LAYER");

        // Layer
        m->add(user_type<Layer>(), "TmxLayer");
        m->add(fun(&Layer::mapGetMap), "mapGetMap");
        m->add(fun(&Layer::GetName), "GetName");
        m->add(fun(&Layer::GetX), "GetX");
        m->add(fun(&Layer::GetY), "GetY");
        m->add(fun(&Layer::GetWidth), "GetWidth");
        m->add(fun(&Layer::GetHeight), "GetHeight");
        m->add(fun(&Layer::GetOpacity), "GetOpacity");
        m->add(fun(&Layer::IsVisible), "IsVisible");
        m->add(fun(&Layer::GetProperties), "GetProperties");
        m->add(fun(&Layer::GetZOrder), "GetZOrder");
        m->add(fun(&Layer::SetZOrder), "SetZOrder");
        m->add(fun(&Layer::GetParseOrder), "GetParseOrder");
        m->add(fun(&Layer::GetLayerType), "GetLayerType");
      }

      ModulePtr addMapEnums(ModulePtr m = std::make_shared<Module>()) {
        // MapError
        m->add_global_const(const_var(TMX_COULDNT_OPEN), "TMX_COULDNT_OPEN");
        m->add_global_const(const_var(TMX_PARSING_ERROR), "TMX_PARSING_ERROR");
        m->add_global_const(const_var(TMX_INVALID_FILE_SIZE), "TMX_INVALID_FILE_SIZE");

        // MapOrientation
        m->add_global_const(const_var(TMX_MO_ORTHOGONAL), "TMX_MO_ORTHOGONAL");
        m->add_global_const(const_var(TMX_MO_ISOMETRIC), "TMX_MO_ISOMETRIC");
        m->add_global_const(const_var(TMX_MO_STAGGERED), "TMX_MO_STAGGERED");
        m->add_global_const(const_var(TMX_MO_HEXAGONAL), "TMX_MO_HEXAGONAL");

        // MapRenderOrder
        m->add_global_const(const_var(TMX_RIGHT_DOWN), "TMX_RIGHT_DOWN");
        m->add_global_const(const_var(TMX_RIGHT_UP), "TMX_RIGHT_UP");
        m->add_global_const(const_var(TMX_LEFT_DOWN), "TMX_LEFT_DOWN");
        m->add_global_const(const_var(TMX_LEFT_UP), "TMX_LEFT_UP");

        // MapStaggerAxis
        m->add_global_const(const_var(TMX_SA_NONE), "TMX_SA_NONE");
        m->add_global_const(const_var(TMX_SA_X), "TMX_SA_X");
        m->add_global_const(const_var(TMX_SA_Y), "TMX_SA_Y");

        // MapStaggerIndex
        m->add_global_const(const_var(TMX_SI_NONE), "TMX_SI_NONE");
        m->add_global_const(const_var(TMX_SI_EVEN), "TMX_SI_EVEN");
        m->add_global_const(const_var(TMX_SI_ODD), "TMX_SI_ODD");

        return m;
      }

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
        addMapEnums(m);
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
        m->add(fun(&Map::GetOrientation), "GetOrientation");
        m->add(fun(&Map::GetRenderOrder), "GetRenderOrder");
        m->add(fun(&Map::GetStaggerAxis), "GetStaggerAxis");
        m->add(fun(&Map::GetStaggerIndex), "GetStaggerIndex");
        m->add(fun(&Map::GetLayer), "GetLayer");
        m->add(bootstrap::standard_library::vector_type<std::vector<Layer*>>("VectorTmxLayer"));
        m->add(fun(&Map::GetLayers), "GetLayers");

        // TODO: Add the remaining functions.
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
        addLayer(m);
        addColor(m);
        addMap(m);

        return m;
      }
    }
  }
}
