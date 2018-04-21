#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include <sstream>
#include "catch.hpp"

#include <chaiscript/chaiscript.hpp>
#include <TmxMap.h>
using namespace Tmx;

/**
 * Load the TmxParser library.
 */
#include "../include/chaiscript/extras/tmxparser.hpp"

TEST_CASE( "TmxParser functions work", "[tmxparser]" ) {

  auto tmxparserlib = chaiscript::extras::tmxparser::bootstrap();
  
  // Create the ChaiScript environment.
  chaiscript::ChaiScript chai;

  // Add the library to the ChaiScript instance.
  chai.add(tmxparserlib);

  // Map tests.
  chai.eval(R""(
    global map = TmxMap();
  )"");

  chai.eval(R""(
    map.ParseFile("../tests/Resources/map.tmx");
  )"");

  CHECK(chai.eval<int>("map.GetWidth()") == 10);

  // Color
  chai.eval(R""(
    global col = map.GetBackgroundColor();
  )"");

  CHECK(chai.eval<std::string>("col.ToString()") == "#00000000");

  // Enums
  CHECK(chai.eval<MapError>("TMX_COULDNT_OPEN") == TMX_COULDNT_OPEN);
  CHECK(chai.eval<MapOrientation>("map.GetOrientation()") == TMX_MO_ORTHOGONAL);
}
