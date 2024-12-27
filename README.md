# Examples for the c-ares library

Build with

```sh
cmake --workflow --preset default
```

The example sources are under `examples`.

To build these examples with the newest version of c-ares, grab its repo and build it with

```sh
cmake -S . -B build
cmake --build build
mkdir -p $local_install_dir
cmake --install build --prefix $local_install_dir
```

Then create a `CMakeUserPresets.json` defining in its `configurePresets` the following:

```json
"CARES_LIBRARY": "REPLACE_ME/lib/libcares.so",
"CARES_INCLUDE_DIR": "REPLACE_ME/install/include/"
```

where you have *replaced* `REPLACE_ME` with your choice of `$local_install_dir`.
