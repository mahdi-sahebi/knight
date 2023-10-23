#include "file.hpp"

constexpr std::ios_base::openmode OPEN_MODE = std::ios::in | std::ios::out | std::ios::binary;

bool CFile::Open(std::string const _path)
{
  bool isOpened = false;

  if (true == m_file.is_open())
  {
    // TODO(MN): Error
  }
  else
  {
    m_file.open(_path, OPEN_MODE);
    isOpened = true;
  }
  
  return isOpened;
}

bool CFile::IsOpen()
{
  return m_file.is_open();
}

uint32_t CFile::GetSize()
{
  uint32_t fileSize = 0;

  if (true == m_file.is_open())
  {
    uint32_t const lastPos = m_file.tellg();
    m_file.seekg(0, std::ios::end);
    fileSize = m_file.tellg(); 
    m_file.seekg(lastPos, std::ios::beg);
  }
  else
  {
    // TODO(MN): Error 
  }
  
  return fileSize;
}

void CFile::Clear()
{
  if (m_file.is_open())
  {
    m_file.close();
    m_file.open(m_path, std::ios::trunc);
    m_file.close();
    m_file.open(m_path, OPEN_MODE);
  }
  else
  {
    // TODO(MN): Error
  }
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
