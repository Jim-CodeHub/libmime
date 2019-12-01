# libMIME
MIME C++ library that reference RFC822, RFC2045, RFC2046, RFC2047, RFC2048 and RFC2049 as IETF definition

### Now VS Future
Currently only the parts that might be relevant to HTTP are implemented and int the future implement mail parts, such as 'Message', 'Data and time', 'Address' etc.

###Known-Bug
funciton "class field &operator=(const class &field);" will cause little heep leak, but almost negligible
