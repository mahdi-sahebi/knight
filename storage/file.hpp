#ifndef __FILE_H__
#define __FILE_H__

#include <fstream>
#include <cstring>
#include "storage.hpp"

class File : public IStorage
{
public: 
  File();
  ~File();
  bool     open   (const std::string _path) override;
  bool     isOpen () override;
  uint32_t getSize() override;
  void     clear  () override;
  uint32_t read   (void*const _dst,       uint32_t const _size) override;
  uint32_t write  (void const*const _src, uint32_t const _size) override;
  void     read(std::string& _dstString);
  void     close  () override;
  mutable std::string  m_path;

private:
  std::fstream m_file;
};

#endif /* __FILE_H__ */
