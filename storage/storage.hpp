#ifndef __STORAGE_H__
#define __STORAGE_H__

/** \brief Storage interface for File, DataBase, etc. */

#include <string>
#include <cstdint>
#include <io/io.hpp>

class IStorage : public IIO
{
public: 
  virtual bool     open      (std::string const _path) = 0;
  virtual void     close     () = 0;
  virtual bool     isOpen    () = 0;
  virtual uint32_t read      (void*const _dst,       uint32_t const _size) = 0;
  virtual uint32_t write     (void const*const _src, uint32_t const _size) = 0;
  virtual uint32_t getSize   () = 0;
  virtual void     clear     () = 0;
};

#endif /* __STORAGE_H__ */
