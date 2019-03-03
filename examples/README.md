# Examples in C of uses Carramba Libs

> **example01.c:** Short explanation how library works. For work this example requires library **readline** and package **readline-devel**. To build type:  
```
gcc example01.c -o example01 -lreadline `pkg-config --libs carramba-libs --cflags carramba-libs --with-path=/usr/local/share/pkgconfig`
```
**Explanation:**  
``prefix=/usr/local`` is default for installing package, you can change it by run ``./configure --prefix=/path/to/somethings`` when you configure source of **Carramba Libs**. In ``pkg-config`` you can configure some parametr, like ``--with-path=``, which need be full path to folder with ``*.pc`` files. In default configuration this is: ``--with-path=${datadir}/pkgconfig``, where ``datadir`` is like: ``${prefix}/share`` and ``prefix`` for default is: ``/usr/local``. Name ``carramba-libs`` is ``pkg-config`` config file provided by package **Carramba Libs**. Next build library by typing ``make`` and install it by typing ``sudo make install``, but the first..., you must clone repository:  
```
git clone http://github.com/majsterklepka/carramba-libs.git
```

_That's all! **mgr inż. Paweł Sobótka**, maintainer._  
_Thank you for use this software!_



