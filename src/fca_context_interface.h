#pragma once

#include <cstddef>

#include "fca_bitset.h"

namespace FCA
{
    class ContextInterface
    {
    public:
        virtual void Set(const size_t& objInd, const size_t& attrInd, const bool val) = 0;
        virtual bool Get(const size_t& objInd, const size_t& attrInd) const = 0;

        virtual size_t ObjSize() const = 0;
        virtual size_t AttrSize() const = 0;

        virtual const BitSet& Intent(const size_t& objInd) const = 0;
        virtual const BitSet& Extent(const size_t& attrInd) const = 0;

        virtual BitSet DrvtAttr(const BitSet& current) const = 0;
        virtual BitSet ClosureAttr(const BitSet& current) const = 0;

        virtual BitSet DrvtObj(const BitSet& current) const = 0;
        virtual BitSet ClosureObj(const BitSet& current) const = 0;

        virtual ~ContextInterface() throw() { ;; }
    };
}
