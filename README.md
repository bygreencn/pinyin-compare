# Hanyu Pinyin Comparator
## Introduction
This library sorts UTF-8 encoded [Hanyu Pinyin](https://en.wikipedia.org/wiki/Pinyin). For SQLite, the term "collation" is used. This library provides the function prototype needed for using its custom collation feature. It is able to handle the diacritical tone marks used in pinyin. The convention is to use the MACRON, ACUTE, CARON and GRAVE versions of the vowels to represent the four tones used in Mandarin Chinese.

## Sorting Algorithm
It is important to note that most of the time you may _not_ want to use strict tone order. These exceptions are built into the algorithms. Here are some examples to illustrate.

### Normalized sorting
For the most part, sorting is based on the toneless versions of the word. That is, the tone marks are ignored.

Mà
Mán

Mà < Mán, because Ma < Man. Here, tone is ignored. This makes sense when looking for words in an index. One expects "ma" to come before "man". This is especially true for compound words or phrases.

    zhōnghuà
    Zhōnghuá mínzú

Normally, zhōnghuá < zhōnghuà. However, zhōnghuà < Zhōnghuá mínzú. Intuitively, this makes sense. Note also that case is ignored. That is, pinyin comparison (at least with this library) is case insensitive.

### Strict sorting
If the words being compared are identical in spelling, then the tones are taken into account.

    Má
    Mà

Here, Má < Mà because Má has the 2nd tone whereas Mà has the fourth.

NOTE: Even though a toneless word is sometimes classified as a 5th tone, its order is before the 1st tone. So,

    Ma (neutral tone)
    Mā (1st tone)
    Má (2nd tone)
    Mǎ (3rd tone)
    Mà (4th tone)
    Māma

Strictly speaking, in this example, "ma" as a standalone pinyin word without tone doesn't exist. You'll generally find it at the end of a compound word such as "Māma" in which case it'll be placed after "Mà" based on normalized alphabetic order.

## Building & Installing
Tarballs are not yet provided so you'll need to build it yourself. This project was developed under macOS so no guarantees on other platforms. However, it uses the GNU Build System for cross-platform building. It is also configured for CMake, if that works better for you.

### Building with GNU Build Tools
You will need to have autoconf, automake and libtool installed. From the project root directory:

```
$ autoreconf --install
$ mkdir build
$ cd build
$ ../configure
$ make
$ make install
```

## Building with CMake
You will need to have cmake installed. From the project root directory:

```
$ mkdir build
$ cd build
$ ../cmake
$ make
$ make test
$ make install
```

NOTE: Only the cmake configuration has tests.

## APIs

Public APIs are located in `pinyin_compare.h`. The main compare function is `pinyin_compare`.

    int pinyin_compare(void* data, int l1, const void* s1, int l2, const void* s2);

- **data** - Not used at this time but is required for interfacing with SQLite.
- **l1** - Length of the first string. Pass a negative number and it will be computed for you. Another AQLite requirement.
- **s1** - First string to compare in UTF-8 format.
- **l2** - Length of second string. Pass a negative number here too, if you want.
- **s2** - Second string to compare in UTF-8 format.

## Using in SQLite 3
This is an example of using from SQLite CLI

```
> .open /path/to/database.db
> .load libpinyincompare
> select pinyin from sometable order by pinyin collate pinyin;
```

For use in C code, reference the `sqlite3_create_collation` function at [Define New Collating Sequences](https://www.sqlite.org/c3ref/create_collation.html).
