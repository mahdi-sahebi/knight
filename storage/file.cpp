#include <filesystem>
#include "file.hpp"


File::File()
{

}

File::~File()
{
  close();
}

bool File::open(const std::string _path, const Mode _mode)
{
  m_path = _path;
  std::ios_base::openmode openMode = std::ios::binary;
  openMode |= (Mode::READ == _mode) ? std::ios::in : std::ios::out;
  m_file.open(m_path, openMode);
  return m_file.is_open();
}

uint32_t File::getSize()
{
  return std::filesystem::file_size(m_path);
}

void File::clear()
{
  if (std::filesystem::exists(m_path))
    std::filesystem::resize_file(m_path, 0);
}

uint32_t File::read(void*const _dst, uint32_t const _size)
{
  uint32_t readSize = 0;

  if (m_file.is_open())
  {
    m_file.read((char*)_dst, _size);
    readSize = getSize();
    m_file.close();
  }

  return readSize;
}

void File::read(std::string& _dstString)
{
  _dstString.clear();
  const uint32_t size = getSize();
  char buf[1024] = {0}; // TODO(MN): Remove it.
  read(buf, size);
  _dstString = std::string(buf);
  _dstString.resize(size);
}

uint32_t File::write(void const*const _src, uint32_t const _size)
{
  uint32_t writtenSize = 0;

  if (m_file.is_open())
  {
    m_file.write((char*)_src, _size);
    m_file.close();
    writtenSize = getSize();
  }

  return 0;
}

void File::close()
{
  if (m_file.is_open())
    m_file.close();
  m_path = "";
}
