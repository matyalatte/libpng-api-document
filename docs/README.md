# libpng-api-document
unofficial API reference for libpng

> [!warning]
> libpng-api-document is a work in progress. Many functions are not yet documented. Contributions via pull requests are welcome.

## About

This is an unofficial documentation resource for [libpng 1.6.54](https://github.com/pnggroup/libpng/tree/v1.6.54). The official documentation is provided in plain-text format, which is easy for core developers to maintain but difficult for newcomers to read.

This project aims to fill in the `@brief` and `@since` attributes for each API.
(I do not plan to document everything, but contributions are welcome.)

## Sitemap

### Manual
[libpng-manual.txt](https://github.com/pnggroup/libpng/blob/v1.6.54/libpng-manual.txt) in markdown format.

1. [Introduction](https://matyalatte.github.io/libpng-api-document/introduction.html)
2. [Structures](https://matyalatte.github.io/libpng-api-document/structures.html)
3. [Reading](https://matyalatte.github.io/libpng-api-document/reading.html)
4. [Writing](https://matyalatte.github.io/libpng-api-document/writing.html)
5. [Simplified API](https://matyalatte.github.io/libpng-api-document/simplified_api.html)
6. [Modifying/Customizing libpng](https://matyalatte.github.io/libpng-api-document/customizing.html)
7. [MNG support](https://matyalatte.github.io/libpng-api-document/mng.html)
8. [Changes](https://matyalatte.github.io/libpng-api-document/changes.html)
9. [Contributing](https://matyalatte.github.io/libpng-api-document/contributing.html)

### API Reference

- [Simplified API](https://matyalatte.github.io/libpng-api-document/group__simple__api.html)
- [Reading](https://matyalatte.github.io/libpng-api-document/group__reader.html)
- [Wrting](https://matyalatte.github.io/libpng-api-document/group__writer.html)
- [Setter](https://matyalatte.github.io/libpng-api-document/group__setter.html)
- [Getter](https://matyalatte.github.io/libpng-api-document/group__getter.html)
- [Progressive Read](https://matyalatte.github.io/libpng-api-document/group__progressive.html)
- [Error Handling](https://matyalatte.github.io/libpng-api-document/group__error.html)
- [Memory Management](https://matyalatte.github.io/libpng-api-document/group__memory.html)
- [Zlib Options](https://matyalatte.github.io/libpng-api-document/group__zlib.html)
- [Versioning](https://matyalatte.github.io/libpng-api-document/group__versioning.html)
- [Others](https://matyalatte.github.io/libpng-api-document/group__other.html)
- [Macros](https://matyalatte.github.io/libpng-api-document/group__macro.html)

## Doxygen

This website is generated with [Doxygen](https://www.doxygen.nl/) and [Doxygen Awesome](https://jothepro.github.io/doxygen-awesome-css/).  

You can build the HTML files by the following steps.  

- Edit `libpng-api-document.h` and the `docs` folder if you want to.
- Install [Doxygen 1.9.8](https://github.com/doxygen/doxygen/releases/tag/Release_1_9_8).
- Clone [Doxygen Awesome 2.4.1](https://github.com/jothepro/doxygen-awesome-css/tree/v2.4.1) with `git submodule update --init`.
- Run `doxygen ./Doxyfile` on the root directory of libpng-api-document.

Note that you should use the specified versions of tools. Or the HTML files might be broken.
