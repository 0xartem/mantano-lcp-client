#ifndef __BASE_LCP_NODE_H__
#define __BASE_LCP_NODE_H__

#include <vector>
#include <memory>
#include "ILcpNode.h"
#include "LcpUtils.h"

namespace lcp
{
    class ICryptoProvider;

    class BaseLcpNode : public ILcpNode
    {
    public:
        virtual void AddChildNode(std::unique_ptr<ILcpNode> child)
        {
            m_childs.push_back(std::move(child));
        }

        virtual bool IsLeaf() const
        {
            return m_childs.size() == 0;
        }

        virtual void ParseNode(const rapidjson::Value & parentObject, JsonValueReader * reader)
        {
            if (!IsLeaf())
            {
                for (auto it = m_childs.begin(); it != m_childs.end(); ++it)
                {
                    (*it)->ParseNode(parentObject, reader);
                }
            }
        }

        virtual Status DecryptNode(ILicense * license, IKeyProvider * keyProvider, ICryptoProvider * cryptoProvider)
        {
            if (!IsLeaf())
            {
                for (auto it = m_childs.begin(); it != m_childs.end(); ++it)
                {
                    Status res = (*it)->DecryptNode(license, keyProvider, cryptoProvider);
                    if (!Status::IsSuccess(res))
                        return res;
                }
            }
            return Status(StCodeCover::ErrorCommonSuccess);
        }

        virtual Status VerifyNode(ILicense * license, IClientProvider * clientProvider, ICryptoProvider * cryptoProvider)
        {
            if (!IsLeaf())
            {
                for (auto it = m_childs.begin(); it != m_childs.end(); ++it)
                {
                    Status res = (*it)->VerifyNode(license, clientProvider, cryptoProvider);
                    if (!Status::IsSuccess(res))
                        return res;
                }
            }
            return Status(StCodeCover::ErrorCommonSuccess);
        }

    protected:
        std::vector<std::unique_ptr<ILcpNode> > m_childs;
    };
}

#endif //__BASE_LCP_NODE_H__
