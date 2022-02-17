# Arm FastModels Translation Modules

This repository contains a few example translation modules defined using the
translation unit framework.

## Authors

See AUTHORS file.

## License

See LICENSE file.

## Dependencies

To use this component, you will need to have the Arm FastModels including the relevant licenses.

## Preparations

Make sure to initialize the submodule using

```
$ git submodule init
$ git submodule update
```

## Building

**Environment Setup:** Before you can build you will need to source the configuration files as
described by the Arm FastModels tools. For example:

```
$ source FastModelsTools_11.15/source_all.sh
```
This should set the following environment variables:

 * `PVLIB_HOME`: FastModels Portfolio directory
 * `MAXCORE_HOME`: FastModels Tools directory
 * `SYSTEMC_HOME`: SystemC library folder installed with the FastModels
 * `ARMLMD_LICENSE_FILE`: License server for ARM, of the form `<port>@<hostname>`

Building: To build the framework support library, simply type:

```
$ make
```

This will build the translation unit definitions in this repository including
test platforms outlining their use.