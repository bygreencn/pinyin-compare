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

#ifndef macros_h
#define macros_h

#define isconsonant(ch) ((ch)!='a' && (ch)!='e' && (ch)!='i' && (ch)!='o' && (ch)!='u' && (ch)>='a' && (ch)<='z')
#define isvowel(ch) ((ch)=='a' || (ch)=='e' || (ch)=='i' || (ch)=='o' || (ch)=='u' || (ch)==L'ü')
#define isseparator(ch) (!isconsonant((ch)) && !isvowel((ch)))

#endif /* macros_h */
