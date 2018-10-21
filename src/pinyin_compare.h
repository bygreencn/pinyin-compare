/*
Copyright 2009 Ryan Homer

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef pinyin_compare_h
#define pinyin_compare_h

#include "u8_util.h"

#ifdef __cplusplus
extern "C" {
#endif

int pinyin_compare(void* data, int l1, const void* s1, int l2, const void* s2);

#ifdef __cplusplus
}
#endif
#endif /* pinyin_compare_h */
