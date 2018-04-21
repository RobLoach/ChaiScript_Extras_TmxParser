# ChaiScript Extras TmxParser

Provides [ChaiScript](https://github.com/ChaiScript/ChaiScript) bindings to [TmxParser](https://github.com/sainteos/tmxparser), allowing [Tiled](http://www.mapeditor.org/) usage.

## Usage

1. Include [`include/chaiscript/extras/tmxparser.hpp`](include/chaiscript/extras/TmxParser.hpp)

2. Include the module source...
  ```
  #include "../include/chaiscript/extras/tmxparser.hpp"
  ```

3. Add the module to the ChaiScript instance...
  ```
  auto tmxparserlib = chaiscript::extras::tmxparser::bootstrap();
  chai.add(tmxparserlib);
  ```

## Development

```
git submodule update --init
mkdir build
cd build
cmake ..
make
make test
```

## License

[MIT](LICENSE)
