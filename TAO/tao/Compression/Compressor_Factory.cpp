// $Id: Compressor_Factory.cpp 91628 2010-09-07 11:11:12Z johnnyw $

#include "tao/Compression/Compressor_Factory.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  CompressorFactory::CompressorFactory (::Compression::CompressorId
                                        compressor_id)
    : compressor_id_ (compressor_id)
  {
  }

  ::Compression::CompressorId
  CompressorFactory::compressor_id (void)
  {
    return compressor_id_;
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL
