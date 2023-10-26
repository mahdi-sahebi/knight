#include <filesystem>
#include "file.hpp"

constexpr std::ios_base::openmode OPEN_MODE = std::ios::in | std::ios::out | std::ios::binary;

bool CFile::Open(std::string const _path)
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

bool CFile::IsOpen()
{
  return m_file.is_open();
}

uint32_t CFile::GetSize()
{
  return std::filesystem::file_size(m_path);
}

void CFile::Clear()
{
  if (std::filesystem::exists(m_path))
    std::filesystem::resize_file(m_path, 0);
}

uint32_t CFile::Read(void*const _dst, uint32_t const _size)
{
  if (m_file.is_open())
  {
    m_file.read((char*)_dst, _size);
  }
  else
  {
    // TODO(MN): Error
  }

  return 0;
}

uint32_t CFile::Write(void const*const _src, uint32_t const _size)
{
  if (m_file.is_open())
  {
    m_file.write((char*)_src, _size);
  }
  else
  {
    // TODO(MN): Error
  }

  return 0;
}

void CFile::Append(void const*const _src, uint32_t const _size)
{
  if (m_file.is_open())
  {
    // TODO(MN): Implement
  }
  else
  {
    // TODO(MN): Error
  }
}

void CFile::Close()
{
  if (m_file.is_open())
  {
    m_file.close();
  }
}

void CFile::GetSize(std::string const _path)
{
    
}

void CFile::Clear(std::string const _path)
{
    
}

void CFile::Delete(std::string const _path)
{
    
}
