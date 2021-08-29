# git reset --hard HEAD
# https://www.rapidtables.com/code/text/ascii-table.html
# { = \x7B
# } = \x7D
# \ = \x5C
# / = \x2F
# [\t\v\r\n ]* any space character

find ./src -type f -exec echo {} \;

: '
Remove
```
namespace YY
{
	namespace Thunks
	{
```
'
find ./src -type f -exec sed -i -n '1h;1!H;${;g;s/[\t\v\r\n ]*namespace YY[\t\v\r\n ]*\x7B[\t\v\r\n ]*\tnamespace Thunks[\t\v\r\n ]*\x7B[\n]*/\n\n/g;p;}' {} \;

: '
Remove
```
	}//namespace Thunks

} //namespace YY
```
'
find ./src -type f -exec sed -i -n '1h;1!H;${;g;s/[\t\v\r\n ]*\x7D[\t\v\r\n ]*\x2F\x2Fnamespace Thunks[\t\v\r\n ]*\x7D[\t\v\r\n ]*\x2F\x2Fnamespace YY[\t\v\r\n ]*/\n/g;p;}' {} \;

find ./src -type f -exec sed -i -n '1h;1!H;${;g;s/鸭船/win-polyfill/g;p;}' {} \;

find ./src -type f -exec sed -i -n '1h;1!H;${;g;s/YY_Thunks_Support_Version/WP_SUPPORT_VERSION/g;p;}' {} \;

find ./src -type f -exec sed -i -n '1h;1!H;${;g;s/__YY_Thunks_Expand_Function/__wp_expand_function/g;p;}' {} \;

find ./src -type f -exec sed -i -n '1h;1!H;${;g;s/YY_Thunks_Defined/WP_HEADER_DEFINED/g;p;}' {} \;

find ./src -type f -exec sed -i -n '1h;1!H;${;g;s/::YY_/::wp_/g;p;}' {} \;

find ./src -type f -exec sed -i 's/try_get/wp_get/g' {} \;

find ./src -type f -exec sed -i -n '1h;1!H;${;g;s/[\t\v\r\n ]*namespace YY[\t\v\r\n ]*\x7B[\t\v\r\n ]*\tnamespace Thunks[\t\v\r\n ]*\x7B[\n]*/\n\n/g;p;}' {} \;

find ./src -type f -exec sed -i -n '1h;1!H;${;g;s/[\t\v\r\n ]*\x7D[\t\v\r\n ]*\x2F\x2Fnamespace Thunks[\t\v\r\n ]*\x7D[\t\v\r\n ]*\x2F\x2Fnamespace YY[\t\v\r\n ]*/\n/g;p;}' {} \;

find ./src -type f -exec sed -i -n '1h;1!H;${;g;s/YY_/WP_/g;p;}' {} \;

find ./src -type f -exec sed -i -n '1h;1!H;${;g;s/YY-Thunks/win-polyfill/g;p;}' {} \;
