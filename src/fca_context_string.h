# pragma once

# include <vector>
# include <string>

# include "fca_context.h"
# include "fca_named_entity_interface.h"

namespace FCA {
    class ContextString : public Context, public NamedEntityInterface {
    public:
        ContextString();
        explicit ContextString(const Context& cxt);
        ContextString(const ContextString& cxt);
        ContextString(const size_t& objSize, const size_t& attrSize);
        ContextString(const std::vector<std::string>& objName,
                      const std::vector<std::string>& attrName);
        explicit ContextString(const std::vector<std::vector<bool> >& table);
        ContextString(const std::vector<std::vector<bool> >& table,
                      const std::vector<std::string>& objName,
                      const std::vector<std::string>& attrName);
        explicit ContextString(const BitSetVector& table);
        ContextString(const BitSetVector& table,
                      const std::vector<std::string>& objName,
                      const std::vector<std::string>& attrName);

        ContextString& operator =(const ContextString& cxt);

        void SetObjName(const size_t& objInd, const std::string& name);
        const std::string& GetObjName(const size_t& objInd) const;

        void SetObjNames(const std::vector<std::string>& names);
        const std::vector<std::string>& GetObjNames() const;

        void SetAttrName(const size_t& attrInd, const std::string& name);
        const std::string& GetAttrName(const size_t& attrInd) const;

        void SetAttrNames(const std::vector<std::string>& names);
        const std::vector<std::string>& GetAttrNames() const;

        virtual ~ContextString() throw() { ;; }

    protected:
        std::vector<std::string> objName;
        std::vector<std::string> attrName;
    };

    void Read(FILE* input, ContextString& cxt);
    void Write(FILE* output, const ContextString& cxt);
}; //namespace FCA
