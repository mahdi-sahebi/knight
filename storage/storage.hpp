#ifndef __STORAGE_H__
#define __STORAGE_H__

/** \brief Storage interface for File, DataBase, etc. */

#include <string>
#include <cstdint>

class IStorage
{
public:
  enum Mode
  {
    READ = 0,
    WRITE
  };

  // TODO(MN): We could use std::string_view for performance if fstream::open() supported this.
  virtual bool     open   (const std::string _path, const Mode _mode) = 0;
  virtual void     close  () = 0;
  virtual uint32_t read   (void*const _dst,       uint32_t const _size) = 0;
  virtual uint32_t write  (void const*const _src, uint32_t const _size) = 0;
  virtual uint32_t getSize() = 0;
  virtual void     clear  () = 0;
};

#endif /* __STORAGE_H__ */
