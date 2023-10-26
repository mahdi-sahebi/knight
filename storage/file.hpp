#ifndef __FILE_H__
#define __FILE_H__

#include <fstream>
#include "storage.hpp"

class CFile : public IStorage
{
public: 
  CFile();
  bool     Open   (std::string const _path) override;
  bool     IsOpen () override;
  uint32_t GetSize() override;
  void     Clear  () override;
  void     Delete ();
  uint32_t Read   (void*const _dst,       uint32_t const _size) override;
  uint32_t Write  (void const*const _src, uint32_t const _size) override;
  void     Append (void const*const _src, uint32_t const _size) override;
  void     Close  () override;
  mutable std::string  m_path;

//  static void GetSize(std::string const _path);
//  static void Clear  (std::string const _path);
//  static void Delete (std::string const _path);
private:
  std::fstream m_file;
};

#endif /* __FILE_H__ */
