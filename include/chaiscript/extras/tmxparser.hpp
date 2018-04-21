#include <vector>
#include <string>

#include <chaiscript/chaiscript.hpp>

#include <TmxMap.h>
#include <TmxColor.h>
#include <TmxLayer.h>

namespace chaiscript {
  namespace extras {
    namespace tmxparser {

      ModulePtr addLayer(ModulePtr m = std::make_shared<Module>()) {
        // LayerType
        m->add_global_const(const_var(Tmx::TMX_LAYERTYPE_TILE), "TMX_LAYERTYPE_TILE");
        m->add_global_const(const_var(Tmx::TMX_LAYERTYPE_OBJECTGROUP), "TMX_LAYERTYPE_OBJECTGROUP");
        m->add_global_const(const_var(Tmx::TMX_LAYERTYPE_IMAGE_LAYER), "TMX_LAYERTYPE_IMAGE_LAYER");
        m->add_global_const(const_var(Tmx::TMX_LAYERTYPE_GROUP_LAYER), "TMX_LAYERTYPE_GROUP_LAYER");

        // Layer
        m->add(user_type<Tmx::Layer>(), "TmxLayer");
        m->add(fun(&Tmx::Layer::mapGetMap), "mapGetMap");
        m->add(fun(&Tmx::Layer::GetName), "GetName");
        m->add(fun(&Tmx::Layer::GetX), "GetX");
        m->add(fun(&Tmx::Layer::GetY), "GetY");
        m->add(fun(&Tmx::Layer::GetWidth), "GetWidth");
        m->add(fun(&Tmx::Layer::GetHeight), "GetHeight");
        m->add(fun(&Tmx::Layer::GetOpacity), "GetOpacity");
        m->add(fun(&Tmx::Layer::IsVisible), "IsVisible");
        m->add(fun(&Tmx::Layer::GetProperties), "GetProperties");
        m->add(fun(&Tmx::Layer::GetZOrder), "GetZOrder");
        m->add(fun(&Tmx::Layer::SetZOrder), "SetZOrder");
        m->add(fun(&Tmx::Layer::GetParseOrder), "GetParseOrder");
        m->add(fun(&Tmx::Layer::GetLayerType), "GetLayerType");

        return m;
      }

      ModulePtr addMapEnums(ModulePtr m = std::make_shared<Module>()) {
        // MapError
        m->add_global_const(const_var(Tmx::TMX_COULDNT_OPEN), "TMX_COULDNT_OPEN");
        m->add_global_const(const_var(Tmx::TMX_PARSING_ERROR), "TMX_PARSING_ERROR");
        m->add_global_const(const_var(Tmx::TMX_INVALID_FILE_SIZE), "TMX_INVALID_FILE_SIZE");

        // MapOrientation
        m->add_global_const(const_var(Tmx::TMX_MO_ORTHOGONAL), "TMX_MO_ORTHOGONAL");
        m->add_global_const(const_var(Tmx::TMX_MO_ISOMETRIC), "TMX_MO_ISOMETRIC");
        m->add_global_const(const_var(Tmx::TMX_MO_STAGGERED), "TMX_MO_STAGGERED");
        m->add_global_const(const_var(Tmx::TMX_MO_HEXAGONAL), "TMX_MO_HEXAGONAL");

        // MapRenderOrder
        m->add_global_const(const_var(Tmx::TMX_RIGHT_DOWN), "TMX_RIGHT_DOWN");
        m->add_global_const(const_var(Tmx::TMX_RIGHT_UP), "TMX_RIGHT_UP");
        m->add_global_const(const_var(Tmx::TMX_LEFT_DOWN), "TMX_LEFT_DOWN");
        m->add_global_const(const_var(Tmx::TMX_LEFT_UP), "TMX_LEFT_UP");

        // MapStaggerAxis
        m->add_global_const(const_var(Tmx::TMX_SA_NONE), "TMX_SA_NONE");
        m->add_global_const(const_var(Tmx::TMX_SA_X), "TMX_SA_X");
        m->add_global_const(const_var(Tmx::TMX_SA_Y), "TMX_SA_Y");

        // MapStaggerIndex
        m->add_global_const(const_var(Tmx::TMX_SI_NONE), "TMX_SI_NONE");
        m->add_global_const(const_var(Tmx::TMX_SI_EVEN), "TMX_SI_EVEN");
        m->add_global_const(const_var(Tmx::TMX_SI_ODD), "TMX_SI_ODD");

        return m;
      }

      ModulePtr addColor(ModulePtr m = std::make_shared<Module>()) {
        m->add(user_type<Tmx::Color>(), "TmxColor");
        m->add(constructor<Tmx::Color()>(), "TmxColor");
        m->add(constructor<Tmx::Color(uint32_t)>(), "TmxColor");
        m->add(constructor<Tmx::Color(uint8_t, uint8_t, uint8_t, uint8_t)>(), "TmxColor");
        m->add(constructor<Tmx::Color(const std::string&)>(), "TmxColor");
        m->add(fun(&Tmx::Color::GetAlpha), "GetAlpha");
        m->add(fun(&Tmx::Color::GetRed), "GetRed");
        m->add(fun(&Tmx::Color::GetGreen), "GetGreen");
        m->add(fun(&Tmx::Color::GetBlue), "GetBlue");
        m->add(fun(&Tmx::Color::IsTransparent), "IsTransparent");
        m->add(fun(&Tmx::Color::ToInt), "ToInt");
        m->add(fun(&Tmx::Color::ToString), "ToString");

        return m;
      }

      /**
       * Adds the Map to the ChaiScript module.
       */
      ModulePtr addMap(ModulePtr m = std::make_shared<Module>()) {
        addMapEnums(m);
        m->add(user_type<Tmx::Map>(), "TmxMap");
        m->add(constructor<Tmx::Map()>(), "TmxMap");
        m->add(fun(&Tmx::Map::ParseFile), "ParseFile");
        m->add(fun(&Tmx::Map::ParseText), "ParseText");
        m->add(fun(&Tmx::Map::GetFilename), "GetFilename");
        m->add(fun(&Tmx::Map::GetFilepath), "GetFilepath");
        m->add(fun(&Tmx::Map::GetVersion), "GetVersion");
        m->add(fun(&Tmx::Map::GetWidth), "GetWidth");
        m->add(fun(&Tmx::Map::GetHeight), "GetHeight");
        m->add(fun(&Tmx::Map::GetTileWidth), "GetTileWidth");
        m->add(fun(&Tmx::Map::GetTileHeight), "GetTileHeight");
        m->add(fun(&Tmx::Map::GetNextObjectId), "GetNextObjectId");
        m->add(fun(&Tmx::Map::GetHexsideLength), "GetHexsideLength");
        m->add(fun(&Tmx::Map::GetNumLayers), "GetNumLayers");
        m->add(fun(&Tmx::Map::GetNumTileLayers), "GetNumTileLayers");
        m->add(fun(&Tmx::Map::GetNumObjectGroups), "GetNumObjectGroups");
        m->add(fun(&Tmx::Map::GetNumImageLayers), "GetNumImageLayers");
        m->add(fun(&Tmx::Map::GetNumGroupLayers), "GetNumGroupLayers");
        m->add(fun(&Tmx::Map::FindTilesetIndex), "FindTilesetIndex");
        m->add(fun(&Tmx::Map::GetNumTilesets), "GetNumTilesets");
        m->add(fun(&Tmx::Map::HasError), "HasError");
        m->add(fun(&Tmx::Map::GetErrorCode), "GetErrorCode");
        m->add(fun(&Tmx::Map::GetBackgroundColor), "GetBackgroundColor");
        m->add(fun(&Tmx::Map::GetOrientation), "GetOrientation");
        m->add(fun(&Tmx::Map::GetRenderOrder), "GetRenderOrder");
        m->add(fun(&Tmx::Map::GetStaggerAxis), "GetStaggerAxis");
        m->add(fun(&Tmx::Map::GetStaggerIndex), "GetStaggerIndex");
        m->add(fun(&Tmx::Map::GetLayer), "GetLayer");
        //m->add(chaiscript::bootstrap::standard_library::vector_type<std::vector<Tmx::Layer*>>("VectorTmxLayer"));
        m->add(fun(&Tmx::Map::GetLayers), "GetLayers");

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
