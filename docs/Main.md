# libpng-api-document
unofficial API reference for libpng

\warning
libpng-api-document is a work in progress. Many functions are not yet documented. Contributions via pull requests are welcome.

[![donate](https://img.shields.io/static/v1?label=donate&message=%E2%9D%A4&logo=GitHub&color=%23fe8e86)](https://github.com/sponsors/matyalatte)  

## About

This is an unofficial documentation resource for [libpng 1.6.54](https://github.com/pnggroup/libpng/tree/v1.6.54). The official documentation is provided in plain-text format, which is easy for core developers to maintain but difficult for newcomers to read.

This project aims to fill in the `@brief` and `@since` attributes for each API.
(I do not plan to document everything, but contributions are welcome.)

## Sitemap

### Manual
[libpng-manual.txt](https://github.com/pnggroup/libpng/blob/v1.6.54/libpng-manual.txt) in markdown format.

1. \ref introduction "Introduction"
2. \ref structures "Structures"
3. \ref reading "Reading"
4. \ref writing "Writing"
5. \ref simplified_api "Simplified API"
6. \ref customizing "Modifying/Customizing libpng"
7. \ref mng "MNG support"
8. \ref changes "Changes"
9. \ref contributing "Contributing"

### API Reference

- \ref simple_api
- \ref reader
- \ref writer
- \ref setter
- \ref getter
- \ref progressive
- \ref error
- \ref memory
- \ref zlib
- \ref versioning
- \ref other
- \ref macro

### External Links

- [pnggroup/libpng](https://github.com/pnggroup/libpng): Official libpng repository
- [PNG Home Site](https://www.libpng.org/pub/png/): Official web site for PNG
- [matyalatte/libpng-loader](https://github.com/matyalatte/libpng-loader): Meta loader for libpng16

## Doxygen

This website is generated with [Doxygen](https://www.doxygen.nl/) and [Doxygen Awesome](https://jothepro.github.io/doxygen-awesome-css/).  

You can build the HTML files by the following steps.  

- Edit `libpng-api-document.h` and the `docs` folder if you want to.
- Install [Doxygen 1.9.8](https://github.com/doxygen/doxygen/releases/tag/Release_1_9_8).
- Clone [Doxygen Awesome 2.4.1](https://github.com/jothepro/doxygen-awesome-css/tree/v2.4.1) with `git submodule update --init`.
- Run `doxygen ./Doxyfile` on the root directory of libpng-api-document.

Note that you should use the specified versions of tools. Or the HTML files might be broken.
