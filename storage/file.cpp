#include <filesystem>
#include "file.hpp"

constexpr std::ios_base::openmode OPEN_MODE = std::ios::in | std::ios::out | std::ios::binary;

bool File::open(std::string const _path)
{
  const bool result = std::filesystem::exists(_path);

  if (result)
  {
    if (m_file.is_open())
      m_file.close();

    m_file.open(_path, OPEN_MODE);
    m_path = _path;
  }

  return result;
}

bool File::isOpen()
{
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
  uint32_t readSize =  _size;

  if (m_file.is_open())
    m_file.read((char*)_dst, _size);
  else
    readSize = 0;

  return 0;
}

uint32_t File::write(void const*const _src, uint32_t const _size)
{
  uint32_t writtenSize = _size;

  if (m_file.is_open())
     m_file.write((char*)_src, _size);
  else
    writtenSize = 0;

  return 0;
}

void File::close()
{
  if (m_file.is_open())
    m_file.close();
  m_path = "";
}
