Pod::Spec.new do |spec|
  spec.name                = 'PinyinCompare'
  spec.version             = '1.0.0'
  spec.license             = { :type => 'Apache' }
  spec.homepage            = 'https://github.com/ryanhomer/pinyin-compare'
  spec.authors             = { 'Ryan Homer' => 'ryanhomer@gmail.com' }
  spec.summary             = 'Pinyin collation in C, compatible with SQLite3 API'
  spec.source              = { :git => 'https://github.com/ryanhomer/pinyin-compare.git', :tag => '1.0.0' }
  spec.source_files        = 'src/*.{h,c}', 'utf8proc/*.h', 'utf8proc/utf8proc.c'
  spec.resources           = 'utf8proc/utf8proc_data.c'
  spec.public_header_files = 'src/pinyin_compare.h', 'src/pinyin_util.h', 'src/u8_util.h', 'utf8proc/utf8proc.h'
  spec.requires_arc        = false
end
