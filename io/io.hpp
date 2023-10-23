#ifndef __IO_H__
#define __IO_H__

#include <cstdint>
#include <string>

class IIO
{
public:
  virtual bool     Open   (std::string const _path) = 0;
  virtual void     Close  () = 0;
  virtual bool     IsOpen () = 0;
  virtual uint32_t Read   (void*const _dst,       uint32_t const _size) = 0;
  virtual uint32_t Write  (void const*const _src, uint32_t const _size) = 0;
};

#endif /* __IO_H__ */
