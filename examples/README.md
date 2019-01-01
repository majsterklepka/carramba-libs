# Examples in C of uses carramba library

> *example01.c:* Short explaination how library works. For work this example requires library **readline*** and package **readline-devel**.To build type after build and install carramba library:  
```
gcc example01.c -o example01 -lreadline `pkg-config --libs carramba-0.1 --cflags carramba-0.1 --with-path=/usr/local/lib`
```

``path=/usr/local/lib ->`` is default for installing library, you can change it by run ``./configure --prefix=/path/to/somthings`` when you configure source of *carramba library*. Next build library by typing ``make`` and install it by typing ``sudo make install``, but the first..., you must clone repository:  
```
git clone http://github.com/majsterklepka/carramba-libs.git
```

_That's all! *mgr inż. Paweł Sobótka*, maintainer._  
_Thank you for use this software!_



