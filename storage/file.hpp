#ifndef __FILE_H__
#define __FILE_H__

#include <fstream>
#include "storage.hpp"

class CFile : public IStorage
{
public: 
  CFile();
  bool     Open   (std::string const _path);
  bool     IsOpen ();
  uint32_t GetSize();
  void     Clear  ();
  void     Delete ();
  uint32_t Read   (void*const _dst,       uint32_t const _size);
  uint32_t Write  (void const*const _src, uint32_t const _size);
  void     Append (void const*const _src, uint32_t const _size);
  void     Close  ();

  static void GetSize(std::string const _path);
  static void Clear  (std::string const _path);
  static void Delete (std::string const _path);
private:
  std::string  m_path;
  std::fstream m_file;
};

#endif /* __FILE_H__ */
