#ifndef __STORAGE_H__
#define __STORAGE_H__

/** \brief Storage interface for File, DataBase, etc. */

#include <string>
#include <cstdint>
#include <io/io.hpp>

class IStorage : public IIO
{
public: 
  virtual bool     Open      (std::string const _path) = 0;
  virtual void     Close     () = 0;
  virtual uint32_t GetAddress() = 0;
  virtual bool     IsOpen    () = 0;
  virtual uint32_t Read      (void*const _dst,       uint32_t const _size) = 0;
  virtual uint32_t Write     (void const*const _src, uint32_t const _size) = 0;
  virtual void     Append    (void const*const _src, uint32_t const _size) = 0;
  virtual uint32_t GetSize   () = 0;
  virtual void     Clear     () = 0;
};

#endif /* __STORAGE_H__ */
