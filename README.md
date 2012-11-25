sqlcipher-cmake
===============

This script allows to build SQLCipher library, SQLite shell program and
Qt4 sql module using Microsoft compiler as well as mingw compiler.

To build you will need:
  * SQLCipher sources (http://sqlcipher.net)
  * SQLite amalgamation sources (http://sqlite.org)
  * OpenSSL http://slproweb.com/products/Win32OpenSSL.html
  * Qt4 distribution (if you want to build sql plugin).


Building
========

Before building you have to configure CMake script.
Open CMakeLists.txt and modify the following variables:
  * ```SQLITE_SRC_DIR```  - SQLite source path
  * ```CIPHER_ROOT```     - SQLite Cipher path
  * ```OPENSSL_ROOT```    - Win32 OpenSSL instalation path

Also CMake script provides a couple of options:
  * ```OPENSSL_MT```      - Use OpenSSL MT libs instead of MD (only for msvc, disabled by default)
  * ```OPENSSL_STATIC```  - Use OpenSSL static libs instead of dynamic (only for msvc, disabled by default)
  * ```BUILD_QT_PLUGIN``` - Build Qt sql plugin (enabled by default)
  * ```BUILD_SHELL```     - Build sqlite shell (enabled by default)


Examples
--------

After configuration you may run cmake & your make, below are examples for cmake.

To build release version of sqlcipher lib, shell, qsqlcipher4 plugin with MS nmake:

    cmake -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=Release
    
To build debug version of sqlcipher lib (static lib, dynamic runtime), shell, qsqlcipher4 plugin with MS nmake:

    cmake -G"NMake Makefiles" -DCMAKE_BUILD_TYPE=Debug -DOPENSSL_MT=OFF -DOPENSSL_STATIC=ON
    
To build just sqlcipher lib with MSYS make:
    
    cmake -G"MSYS Makefiles" -DBUILD_QT_PLUGIN=OFF -DBUILD_SHELL=OFF
    
    
Notes
=====

Inspired by
  * [domehead100](https://groups.google.com/d/msg/sqlcipher/ISwSo2Vq-B8/x205cECTiI0J)
  * [crossplatform.ru](http://www.wiki.crossplatform.ru/index.php/%D0%9F%D1%80%D0%B8%D0%B2%D1%8F%D0%B7%D0%BA%D0%B0_SQLCipher_%D0%BA_Qt)

Tested with SQLCipher-2.0.6, sqlite-3.7.14.1, Qt-4.8.3, OpenSSL-1.0.1b.
For more info see CMakeLists.txt comments.